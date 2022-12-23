//
// Created by fisher on 2022/12/23.
//

#include <assert.h>
#include "event_loop_thread.h"
#include "event_loop.h"
#include "log.h"

/*对子线程初始化一个event-loop
 * 通过信号量的方式通知主线程继续执行
 * 调用event_loop_run进入事件分发和处理的循环
 * */
void *event_loop_thread_run(void *arg){
    struct event_loop_thread *eventLoopThread = (struct event_loop_thread*) arg;
    pthread_mutex_lock(&eventLoopThread->mutex);
    eventLoopThread->eventLoop = event_loop_init_with_name(eventLoopThread->thread_name);
    fischer_msgx("event loop thread init and signal,%s",eventLoopThread->thread_name);
    pthread_cond_signal(&eventLoopThread->cond);
    pthread_mutex_lock(&eventLoopThread->mutex);
    event_loop_run(eventLoopThread->eventLoop);


}
/*对传入的eventLoopThread进行初始化*/
int event_loop_thread_init(struct event_loop_thread *eventLoopThread,int i) {
    eventLoopThread->eventLoop = nullptr;
    eventLoopThread->thread_count = 0;
    eventLoopThread->thread_tid = 0;
    pthread_mutex_init(&eventLoopThread->mutex,NULL);
    pthread_cond_init(&eventLoopThread->cond,NULL);

    char *buf = (char*)malloc(16);
    sprintf(buf,"Thread-%d\0",i+1);
    eventLoopThread->thread_name = buf;

    return 0;

}
/*首先调用pthread_create来创建一个子形成，令其执行event_loop_thread_run
 * 主线程等待子线程初始化完成*/
struct event_loop *event_loop_thread_start(struct event_loop_thread *eventLoopThread) {
    pthread_create(&eventLoopThread->thread_tid,NULL,&event_loop_thread_run,eventLoopThread);

    assert(pthread_mutex_lock(&eventLoopThread->mutex) == 0);

    while(eventLoopThread->eventLoop == NULL) {
        assert( pthread_cond_wait(&eventLoopThread->cond,&eventLoopThread->mutex) == 0);
    }
    assert(pthread_mutex_unlock(&eventLoopThread->mutex) == 0);

    fischer_msgx("event loop thread started, %s",eventLoopThread->thread_name);

    return eventLoopThread->eventLoop;

}

