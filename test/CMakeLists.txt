add_executable(poll-server-onethread epoll-server-onethread.c)
target_link_libraries(poll-server-onethread HttpServer)