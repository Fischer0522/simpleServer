//
// Created by fisher on 2022/12/22.
//

#ifndef HTTPSERVER_EVENT_LOOP_THREAD_H
#define HTTPSERVER_EVENT_LOOP_THREAD_H
#include <pthread.h>

struct event_loop_thread {
    pthread_t thread_tid;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    char * thread_name;
    long thrread_count;
};

int event_loop_thread_init(struct event_loop_thread *);

struct event_loop *event_loop_thread_start(struct event_loop_thread *);

#endif //HTTPSERVER_EVENT_LOOP_THREAD_H
