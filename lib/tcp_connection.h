//
// Created by fisher on 2022/12/24.
//

#ifndef HTTPSERVER_TCP_CONNECTION_H
#define HTTPSERVER_TCP_CONNECTION_H
#include "event_loop.h"
#include "channel.h"
#include "buffer.h"
#include "tcp_server.h"
#include "log.h"


struct tcp_connection {
    struct event_loop *eventLoop;
    struct channel *channel;
    char *name;
    struct buffer *input_buffer;
    struct buffer *output_buffer;

    connection_completed_call_back connectionCompletedCallBack;
    message_call_back messageCallBack;
    write_completed_call_back writeCompletedCallBack;
    connection_closed_call_back connectionClosedCallBack;

    void *data;
    void *request;
    void *response;

};

struct tcp_connection *
tcp_connection_new(int fd,struct event_loop *eventLoop,connection_completed_call_back connectionCompletedCallBack,
                   connection_closed_call_back connectionClosedCallBack,
                   message_call_back messageCallBack,
                   write_completed_call_back writeCompletedCallBack);
int tcp_connection_send_data(struct tcp_connection *tcpConnection,void *data,int size);

int tcp_connection_send_buffer(struct tcp_connection *tcpConnection,struct buffer * buffer);

void tcp_connection_shutdown(struct tcp_connection *tcpConnection);


#endif //HTTPSERVER_TCP_CONNECTION_H
