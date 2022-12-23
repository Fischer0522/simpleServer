if (EPOLL_EXISTS)
    set(yolanda_lib
            tcp_server.cpp channel.h channel.cpp event_loop.h event_loop.cpp event_dispatcher.h channel_map.h acceptor.h buffer.h event_loop_thread.h thread_pool.h utils.h utils.cpp log.h log.cpp
            buffer.cpp
            acceptor.cpp
            channel_map.cpp
            epoll_dispatcher.cpp poll_dispatcher.cpp)
else ()
    set(yolanda_lib

            tcp_server.cpp channel.h channel.cpp event_loop.h event_loop.cpp event_dispatcher.h channel_map.h acceptor.h buffer.h event_loop_thread.h thread_pool.h utils.h utils.cpp log.h log.cpp acceptor.cpp buffer.cpp channel_map.cpp epoll_dispatcher.cpp poll_dispatcher.cpp)
endif ()


add_library(HttpServer ${yolanda_lib})
target_link_libraries(HttpServer pthread)

install(TARGETS HttpServer DESTINATION lib)

#file(GLOB HEADERS "*.h")
#install(FILES ${HEADERS} DESTINATION include/)

