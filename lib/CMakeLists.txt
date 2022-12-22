if (EPOLL_EXISTS)
    set(yolanda_lib
            tcp_server.cpp
            )
else ()
    set(yolanda_lib

            tcp_server.cpp channel.h)
endif ()


add_library(HttpServer ${yolanda_lib})
target_link_libraries(HttpServer pthread)

install(TARGETS HttpServer DESTINATION lib)

#file(GLOB HEADERS "*.h")
#install(FILES ${HEADERS} DESTINATION include/)

