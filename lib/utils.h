//
// Created by fisher on 2022/12/22.
//

#ifndef HTTPSERVER_UTILS_H
#include "event_loop.h"

void assertInSameThread(struct event_loop *eventLoop);

int isInSameThread(struct event_loop *eventLoop);

#define HTTPSERVER_UTILS_H

#endif //HTTPSERVER_UTILS_H
