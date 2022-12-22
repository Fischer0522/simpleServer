add_executable(thread-helloworld thread-helloworld.c )
target_link_libraries(thread-helloworld HttpServer)


add_executable(thread01 thread01.c echo.c)
target_link_libraries(thread01 HttpServer)


add_executable(thread02 thread02.c echo.c)
target_link_libraries(thread02 HttpServer)
