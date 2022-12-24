//
// Created by fisher on 2022/12/22.
//

#ifndef HTTPSERVER_CHANNEL_H
#define HTTPSERVER_CHANNEL_H
#include "common.h"
#include "event_loop.h"
#include "buffer.h"

#define EVENT_READ 0x02
#define EVENT_WRITE 0x04

typedef int (*event_read_callback)(void *data);
typedef int (*event_write_callback)(void *data);

struct channel {
    int fd;
    int events; // event类型 EVENT_READ 和 EVENT_WRITE
    event_read_callback eventReadCallback;
    event_write_callback eventWriteCallback;
    void* data;
};
struct channel *channel_new(int fd,int events,event_read_callback eventReadCallback,event_write_callback eventWriteCallback,
                            void *data);

int channel_write_event_is_enabled(struct channel *channel);

int channel_write_event_enable(struct channel * channel);

int channel_write_event_disable(struct channel * channel);

#endif //HTTPSERVER_CHANNEL_H
