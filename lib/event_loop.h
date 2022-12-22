//
// Created by fisher on 2022/12/22.
//

#ifndef HTTPSERVER_EVENT_LOOP_H
#define HTTPSERVER_EVENT_LOOP_H

#include "common.h"
#include "event_dispatcher.h"
#include "common.h"
struct channel_element {
    int type;
    struct channel *channel;
    struct channel_element *next;
};
struct event_loop {
    int quit; // 表示是否结束循环的标志位
    const struct event_dispatcher *eventDispatcher;
    void *event_dispatcher_data;
    int is_handle_pending;

    struct channel_element *pending_head;
    struct channel_element *pending_tail;

    pthread_t owner_thread_id;
    pthread_mutex_t mutex;
    pthread_cond_t cond;
    int socketPair[2];
    char *thread_name;
};


struct event_loop *event_loop_init();
struct event_loop * event_loop_init_with_name(char * thread_name);

int event_loop_run(struct event_loop *eventLoop);

void event_loop_wakeup(struct event_loop *eventLoop);

int event_loop_add_channel_event(struct event_loop *eventLoop,int fd,struct channel *channel1);

int event_loop_remove_channel_event(struct event_loop *eventLoop,int fd,struct channel *channel1);

int event_loop_update_channel_event(struct event_loop *eventLoop,int fd,struct channel *channel1);

int event_loop_handle_pending_add(struct event_loop *eventLoop,int fd,struct channel * channel1);

int event_loop_handle_pending_remove(struct event_loop *eventLoop,int fd,struct channel *channel1);

int event_loop_handle_pending_update(struct event_loop *eventLoop,int fd,struct channel channel1);
// res : EVENT_READ | EVENT_WRITE
int channel_event_activate(struct event_loop *eventLoop,int fd,int res);





#endif //HTTPSERVER_EVENT_LOOP_H
