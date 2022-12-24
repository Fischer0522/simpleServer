//
// Created by fisher on 2022/12/21.
//

#ifndef HTTPSERVER_TCP_SERVER_H
#define HTTPSERVER_TCP_SERVER_H
typedef int (*connection_completed_call_back)(struct tcp_connection* tcpConnection);

typedef int (*message_call_back)(struct buffer *buffer,struct tcp_connection *tcpConnection);

typedef int (*write_completed_call_back)(struct tcp_connection *tcpConnection);

typedef int (*connection_closed_call_back)(struct tcp_connection *tcpConnection);

#include "acceptor.h"
#include "event_loop.h"
#include "buffer.h"
#include "tcp_connection.h"
#include "thread_pool.h"
struct TCPserver {
    int port;
    struct event_loop *event_loop;
    struct acceptor *acceptor;
    connection_completed_call_back  connectionCompletedCallBack;
    message_call_back messageCallBack;
    write_completed_call_back writeCompletedCallBack;
    connection_closed_call_back connectionClosedCallBack;
    int threadNum;
    struct thread_pool *threadPool;
    void *data;
};

struct TCPserver *
        tcp_server_init(struct event_loop *eventLoop,struct acceptor *acceptor,
                connection_completed_call_back connectionCompletedCallBack,
                message_call_back messageCallBack,
                write_completed_call_back writeCompletedCallBack,
                connection_closed_call_back connectionClosedCallBack,
                int threadNum);

int handle_connection_established(void *data);

void tcp_server_start(struct TCPserver *tcpServer);

void tcp_server_set_data(struct TCPserver *tcpServer,void *drand48_data);


#endif //HTTPSERVER_TCP_SERVER_H
