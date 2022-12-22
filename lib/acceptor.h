//
// Created by fisher on 2022/12/22.
//

#ifndef HTTPSERVER_ACCEPTOR_H
#define HTTPSERVER_ACCEPTOR_H
#include "common.h"

struct acceptor {
    int listen_port;
    int listen_fd;
};

struct acceptor *acceptor_init(int port);
#endif //HTTPSERVER_ACCEPTOR_H
