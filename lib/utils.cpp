//
// Created by fisher on 2022/12/22.
//
#include "utils.h"
void assertInSameThread(struct event_loop *eventLoop) {
    if (eventLoop->owner_thread_id != pthread.self()) {
        exit(-1);
    }
}

int isInSameThread(struct event_loop *eventLoop) {
    return eventLoop->owner_thread_id == pthread_self();
}