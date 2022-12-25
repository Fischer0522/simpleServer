//
// Created by fisher on 2022/12/24.
//
#include "tcp_connection.h"
#include "utils.h"
#include "channel.h"
#include "log.h"

int handle_connection_closed(struct tcp_connection *tcpConnection) {
    struct event_loop *eventLoop = tcpConnection->eventLoop;
    struct channel *channel = tcpConnection->channel;
    event_loop_remove_channel_event(eventLoop,channel->fd,channel);
    if (tcpConnection->connectionClosedCallBack != NULL) {
        tcpConnection->connectionClosedCallBack(tcpConnection);
    }
}
// 读到input_buffer当中
int handle_read(void *data) {
    struct tcp_connection *tcpConnection = (struct tcp_connection *)data;
    struct buffer *inputBuffer = tcpConnection->input_buffer;
    struct channel *channel = tcpConnection->channel;
    if (buffer_socket_read(inputBuffer,channel->fd) > 0) {
        if (tcpConnection->messageCallBack != NULL) {
            tcpConnection->messageCallBack(inputBuffer,tcpConnection);
        }
    } else {
        handle_connection_closed(tcpConnection);
    }
}
int handle_write(void *data) {
    struct tcp_connection *tcpConnection = (struct tcp_connection*) data;
    struct event_loop *eventLoop = tcpConnection->eventLoop;
    struct buffer *outputBuffer = tcpConnection->output_buffer;
    struct channel *channel = tcpConnection->channel;
    ssize_t nwrited = write(channel->fd,outputBuffer->data+outputBuffer->readIndex,
                            buffer_readable_size(outputBuffer));
    if (nwrited > 0) {
        // 向套接字中写入了部分的数据，
        outputBuffer->readIndex += nwrited;
        if (buffer_readable_size(outputBuffer) == 0) {
            channel_write_event_disable(channel);
        }
        if (tcpConnection->writeCompletedCallBack != NULL) {
            tcpConnection->writeCompletedCallBack(tcpConnection);
        }
    } else {
        yolanda_msgx("handle_write for tcp connection %s",tcpConnection->name);
    }


}

struct tcp_connection *
tcp_connection_new(int fd,struct event_loop *eventLoop,connection_completed_call_back connectionCompletedCallBack,
                   connection_closed_call_back connectionClosedCallBack,
                   message_call_back messageCallBack,
                   write_completed_call_back writeCompletedCallBack) {
    struct tcp_connection *tcpConnection = (struct tcp_connection*) malloc(sizeof(struct tcp_connection));
    tcpConnection->writeCompletedCallBack = writeCompletedCallBack;
    tcpConnection->connectionClosedCallBack = connectionClosedCallBack;
    tcpConnection->messageCallBack = messageCallBack;
    tcpConnection->connectionCompletedCallBack = connectionCompletedCallBack;
    tcpConnection->eventLoop = eventLoop;
    tcpConnection->input_buffer = buffer_new();
    tcpConnection->output_buffer = buffer_new();
    char *buf = (char *) malloc(16);
    sprintf(buf,"connection-%d\0",fd);
    tcpConnection->name = buf;
    struct channel *channel1 = channel_new(fd,EVENT_READ, handle_read, handle_write,tcpConnection);
    tcpConnection->channel =channel1;
    if (tcpConnection->connectionCompletedCallBack != NULL) {
        tcpConnection->connectionCompletedCallBack(tcpConnection);
    }
    event_loop_add_channel_event(tcpConnection->eventLoop,fd,channel1);
    return tcpConnection;

}


int tcp_connection_send_data(struct tcp_connection *tcpConnection,void *data,int size) {
    ssize_t nwrited = 0;
    size_t nleft = size;
    int fault = 0;
    struct channel *channel = tcpConnection->channel;
    struct buffer *outputBuffer = tcpConnection->output_buffer;

    if (!channel_write_event_is_enabled(channel) && buffer_readable_size(outputBuffer) == 0) {
        nwrited = write(channel->fd,data,size);
        if (nwrited >= 0) {
            nleft = nleft - nwrited;
        } else {
            nwrited = 0;
            if (errno != EWOULDBLOCK) {
                if (errno == EPIPE ||errno == ECONNRESET) {
                    fault = 1;
                }
            }
        }
    }
    // 如果一次性没有全部发送给套接字，则将数据写入到buffer当中，
    // 注册成一个事件存入到event_loop当中，后续进行处理
    if (!fault && nleft > 0) {
        buffer_append(outputBuffer,data,nleft);
        if (!channel_write_event_is_enabled(channel)) {
            channel_write_event_enable(channel);
        }
    }
    return nwrited;
}

int tcp_connection_send_buffer(struct tcp_connection *tcpConnection,struct buffer * buffer){
    int size = buffer_readable_size(buffer);
    int result = tcp_connection_send_data(tcpConnection,buffer->data + buffer->readIndex,size);
    buffer->readIndex +=  size;
    return result;

}

void tcp_connection_shutdown(struct tcp_connection *tcpConnection){
    if (shutdown(tcpConnection->channel->fd,SHUT_WR) < 0) {
        yolanda_msgx("tcp_connection_shutdown failed,sokcet = %d",tcpConnection->channel->fd);
    }
}
