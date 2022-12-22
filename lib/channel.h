//
// Created by fisher on 2022/12/22.
//

#ifndef HTTPSERVER_CHANNEL_H
#define HTTPSERVER_CHANNEL_H
#include "common.h"

#define EVENT_READ 0x02
#define EVENT_WRITE 0x04

typedef int (*event_read_callback)(void *data);
typedef int (*event_write_callback)(void *data);

struct channel {
    int fd;
    int events; // event类型 EVENT_READ 和 EVENT_WRITE
    event_read_callback eventReadCallback;
    event_write_callback eventWriteCallback;
};
#endif //HTTPSERVER_CHANNEL_H
