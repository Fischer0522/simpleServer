//
// Created by fisher on 2022/12/23.
//

#include <assert.h>
#include "utils.h"
#include "thread_pool.h"
struct thread_pool *thread_pool_new(struct event_loop *mainLoop,int threadNumber) {
    struct thread_pool *threadPool = (struct thread_pool*) malloc(sizeof(struct thread_pool));
    threadPool->mainLoop = mainLoop;
    threadPool->position = 0;
    threadPool->thread_number = 0;
    threadPool->started = 0;
    threadPool->eventLoopThreads = nullptr;
    return threadPool;

}
/*
 * 通过主线程发起，将线程池中的所有的线程全部初始化和启动
 * */
void thread_pool_start(struct thread_pool *threadPool) {
    assert(!threadPool->started);
    assertInSameThread(threadPool->mainLoop);
    threadPool->started = 1;
    for (int i = 0;i < threadPool->thread_number;i++) {
        event_loop_thread_init(&threadPool->eventLoopThreads[i],i);
        event_loop_thread_start(&threadPool->eventLoopThreads[i]);
    }

}
/*
 * 通过主线程调用
 * 先选择一个主线程，如果后续没有合适的子线程则使用主线程*/
struct event_loop *thread_pool_get_loop(struct thread_pool *threadPool) {
    assert(threadPool->started);
    assertInSameThread(threadPool->mainLoop);
    struct event_loop *selected = threadPool->mainLoop;
    if (threadPool->thread_number > 0) {
        // 存在子线程可选，则按顺序选择
        selected = threadPool->eventLoopThreads[threadPool->position].eventLoop;
        if (++threadPool->position >= threadPool->thread_number) {
            threadPool->position = 0;
        }

    }
    return selected;
}
