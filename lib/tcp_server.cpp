//
// Created by fisher on 2022/12/21.
//
#include "common.h"
#include "tcp_server.h"
int tcp_server(int port) {
    int listenfd;
    listenfd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_addr;
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(port);

    int on = 1;
    setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));

    int rt1 = bind(listenfd, (struct sockaddr *) &server_addr, sizeof(server_addr));
    if (rt1 < 0) {
        error(1, errno, "bind failed ");
    }

    int rt2 = listen(listenfd, LISTENQ);
    if (rt2 < 0) {
        error(1, errno, "listen failed ");
    }

    signal(SIGPIPE, SIG_IGN);

    int connfd;
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);

    if ((connfd = accept(listenfd, (struct sockaddr *) &client_addr, &client_len)) < 0) {
        error(1, errno, "bind failed ");
    }

    return connfd;
}


int tcp_server_listen(int port) {
    int listenfd;
    listenfd = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in server_addr;
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(port);

    int on = 1;
    setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));

    int rt1 = bind(listenfd, (struct sockaddr *) &server_addr, sizeof(server_addr));
    if (rt1 < 0) {
        error(1, errno, "bind failed ");
    }

    int rt2 = listen(listenfd, LISTENQ);
    if (rt2 < 0) {
        error(1, errno, "listen failed ");
    }

    signal(SIGPIPE, SIG_IGN);

    return listenfd;
}


int tcp_nonblocking_server_listen(int port) {
    int listenfd;
    listenfd = socket(AF_INET, SOCK_STREAM, 0);

    make_nonblocking(listenfd);

    struct sockaddr_in server_addr;
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(port);

    int on = 1;
    setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));

    int rt1 = bind(listenfd, (struct sockaddr *) &server_addr, sizeof(server_addr));
    if (rt1 < 0) {
        error(1, errno, "bind failed ");
    }

    int rt2 = listen(listenfd, LISTENQ);
    if (rt2 < 0) {
        error(1, errno, "listen failed ");
    }

    signal(SIGPIPE, SIG_IGN);

    return listenfd;
}

void make_nonblocking(int fd) {
    fcntl(fd, F_SETFL, O_NONBLOCK);
}
struct TCPserver *
        tcp_server_init(struct event_loop *eventLoop,struct acceptor *acceptor,
                connection_completed_call_back connectionCompletedCallBack,
                connection_closed_call_back connectionClosedCallBack,
                message_call_back messageCallBack,
                write_completed_call_back writeCompletedCallBack,
                int threadNum) {
    struct TCPserver *tcpServer = (struct TCPserver*) malloc(sizeof(struct TCPserver));
    tcpServer->event_loop = eventLoop;
    tcpServer->acceptor = acceptor;
    tcpServer->connectionClosedCallBack = connectionClosedCallBack;
    tcpServer->messageCallBack = messageCallBack;
    tcpServer->writeCompletedCallBack = writeCompletedCallBack;
    tcpServer->connectionCompletedCallBack = connectionCompletedCallBack;
    tcpServer->threadNum = threadNum;
    tcpServer->threadPool = thread_pool_new(eventLoop,threadNum);
    tcpServer->data = NULL;

    return tcpServer;
}
/*1. accpet后使其非阻塞，*/
int handle_connection_established(void *data) {
    struct TCPserver *tcpServer = (struct TCPserver*) data;
    struct acceptor *acceptor = tcpServer->acceptor;
    int listen_fd = acceptor->listen_fd;
    struct sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);
    int connected_fd = accept(listen_fd,(struct sockaddr*) &client_addr,&client_len);
    make_nonblocking(connected_fd);

    fischer_msgx("new connection established, socket == %d",connected_fd);

    struct event_loop *eventLoop = tcpServer->event_loop;
    struct tcp_connection *tcpConnection = tcp_connection_new(connected_fd,eventLoop,
            tcpServer->connectionCompletedCallBack,
            tcpServer->connectionClosedCallBack,
            tcpServer->messageCallBack,
            tcpServer->writeCompletedCallBack);

    if (tcpServer->data != NULL) {
        tcpConnection->data = tcpServer->data;
    }
    return 0;

}
void tcp_server_start(struct TCPserver *tcpServer) {
    struct acceptor *acceptor = tcpServer->acceptor;
    struct event_loop *eventLoop = tcpServer->event_loop;

    thread_pool_start(tcpServer->threadPool);

    struct channel *channel = channel_new(acceptor->listen_fd,EVENT_READ,handle_connection_established,
            NULL,tcpServer);
    event_loop_add_channel_event(eventLoop,acceptor->listen_fd,channel);
    return;

}

void tcp_server_set_data(struct TCPserver *tcpServer, void *data) {
    if (data != NULL) {
        tcpServer->data = data;
    }
}
