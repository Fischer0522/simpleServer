//
// Created by fisher on 2022/12/22.
//

#ifndef HTTPSERVER_THREAD_POOL_H
#define HTTPSERVER_THREAD_POOL_H
#include "event_loop.h"
#include "event_loop_thread.h"

struct thread_pool {
    struct event_loop *mainLoop;

    int started;

    int thread_number;

    struct event_loop_thread *eventLoopThreads;

    int position;
};

struct thread_pool *thread_pool_new(struct event_loop *mainLoop,int threadNumber);

void thread_pool_start(struct thread_pool *);

struct event_loop *thead_pool_get_loop(struct thread_pool *);

#endif //HTTPSERVER_THREAD_POOL_H
