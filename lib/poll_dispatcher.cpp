//
// Created by fisher on 2022/12/23.
//
#include "event_dispatcher.h"
#include "event_loop.h"
#include "log.h"
#include <sys/poll.h>

#define INIT_POLL_SIZE 1024

struct pollidx {
    int idxplus1;
};
struct poll_dispatcher_data {
    int event_count;
    int nfds;
    int realloc_copy;
    struct pollfd *event_set;
    struct pollfd *event_set_copy;
};

static void *poll_init(struct event_loop *);

static int poll_add(struct event_loop *, struct channel *channel1);

static int poll_del(struct event_loop *, struct channel *channel1);

static int poll_update(struct event_loop *, struct channel *channel1);

static int poll_dispatch(struct event_loop *, struct timeval *);

static void poll_clear(struct event_loop *);

const struct event_dispatcher poll_dispatcher = {
        "poll",
        poll_init,
        poll_add,
        poll_del,
        poll_update,
        poll_dispatch,
        poll_clear,
};
void *poll_init(struct event_loop *eventLoop) {
    struct poll_dispatcher_data *pollDispatcherData = (poll_dispatcher_data *) eventLoop->event_dispatcher_data;
    int i;
    for(i = 0;i < INIT_POLL_SIZE;i++) {
        pollDispatcherData->event_set[i].fd = -1;
    }
    pollDispatcherData->realloc_copy = 0;
    pollDispatcherData->nfds = 0;
    pollDispatcherData->event_count = 0;
    return pollDispatcherData;
}
int poll_add(struct event_loop *eventLoop,struct channel *channel1) {
    struct poll_dispatcher_data *pollDispatcherData = (struct poll_dispatcher_data*)eventLoop->event_dispatcher_data;
     int fd = channel1->fd;
     int events = 0;
     if (channel1->events & EVENT_WRITE) {
         events = events | POLLRDNORM;
     } else if (channel1->events & EVENT_WRITE) {
         events = events | POLLWRNORM;
     }

     int i;
     for (i = 0; i < INIT_POLL_SIZE;i++) {
         if (pollDispatcherData->event_set[i].fd < 0) {
             pollDispatcherData->event_set[i].fd = fd;
             pollDispatcherData->event_set[i].events = events;
             break;
         }
     }
    fischer_msgx("poll added channel fd ==%d,%s",fd,eventLoop->thread_name);
     if (i >= INIT_POLL_SIZE) {
         LOG_ERR("too many clients,just abort it");
     }
     return 0;
}

int poll_del(struct event_loop *eventLoop,struct channel *channel1) {
    struct poll_dispatcher_data *pollDispatcherData = (struct poll_dispatcher_data*)eventLoop->event_dispatcher_data;
    int fd = channel1->fd;
    int i;
    for(i = 0;i < INIT_POLL_SIZE;i++) {
        if (pollDispatcherData->event_set[i].fd == fd) {
            pollDispatcherData->event_set[i].fd = -1;
            break;
        }
    }
    fischer_msgx("poll delete channel fd ==%d,%s",fd,eventLoop->thread_name);
    if (i >= INIT_POLL_SIZE) {
        LOG_ERR("can not find fd,poll delete error");
    }
    return 0;
}

int poll_update(struct event_loop *eventLoop,struct channel *channel1) {
    struct poll_dispatcher_data *pollDispatcherData = (struct poll_dispatcher_data*)eventLoop->event_dispatcher_data;
    int fd = channel1->fd;
    int events = 0;
    if (channel1->events & EVENT_READ) {
        events = events | POLLRDNORM;
    } else if (channel1->events & EVENT_WRITE) {
        events = events | POLLWRNORM;
    }
    int i = 0;
    for(i = 0;i < INIT_POLL_SIZE;i++) {
        if (fd == pollDispatcherData->event_set[i].fd) {
            pollDispatcherData->event_set[i].events = events;
            break;
        }
    }
    fischer_msgx("poll updated channel fd== %d,%s",fd,eventLoop->thread_name);
    if (i >= INIT_POLL_SIZE) {
        LOG_ERR("can not find fd,poll updated error");
    }

    return 0;
}
int poll_dispatch(struct event_loop *eventLoop,struct timeval *timeval) {
    struct poll_dispatcher_data *pollDispatcherData = (struct poll_dispatcher_data*) eventLoop->event_dispatcher_data;

    int ready_number = 0;
    int timewait = timeval->tv_sec * 1000;
    if ((ready_number = poll(pollDispatcherData->event_set,INIT_POLL_SIZE,timewait)) < 0) {
        error(1,errno,"poll failed");
    }
    if (ready_number <= 0) {
        return 0;
    }
    int i;
    for( i = 0;i<= INIT_POLL_SIZE;i++) {
        int socket_fd;
        struct pollfd pollfd = pollDispatcherData->event_set[i];
        if ((socket_fd = pollfd.fd) < 0) {
            continue;
        }
        if (pollfd.revents > 0) {
            fischer_msgx("get message channel i==%d,fd==%d,%s",i,socket_fd,eventLoop->thread_name);
            if (pollfd.revents & POLLRDNORM) {
                channel_event_activate(eventLoop,socket_fd,EVENT_READ);
            } else if (pollfd.revents & POLLWRNORM) {
                channel_event_activate(eventLoop,socket_fd,EVENT_WRITE);
            }
            if (--ready_number <= 0) {
                break;
            }
        }

    }
    return 0;

}

void poll_clear(struct event_loop *eventLoop) {
    struct poll_dispatcher_data *pollDispatcherData =
            (struct poll_dispatcher_data*) eventLoop->event_dispatcher_data;
    free(pollDispatcherData->event_set);
    pollDispatcherData->event_set = nullptr;
    free(pollDispatcherData);
    eventLoop->event_dispatcher_data = nullptr;
    return;
}


