//
// Created by fisher on 2022/12/22.
//

#ifndef HTTPSERVER_EVENT_DISPATCHER_H
#define HTTPSERVER_EVENT_DISPATCHER_H

#include "channel.h"
struct event_dispatcher {
    const char *name;
    void *(*init)(struct event_loop *eventLoop);

    int (*add)(struct event_loop * eventLoop,struct channel * channel);

    int (*del)(struct event_loop * eventLoop,struct channel * channel);

    int (*update)(struct event_loop * eventLoop,struct channel * channel);

    int (*dispatch)(struct event_loop * eventLoop,struct timeval *);

    void (*clear)(struct event_loop * eventLoop);
};

#endif //HTTPSERVER_EVENT_DISPATCHER_H
