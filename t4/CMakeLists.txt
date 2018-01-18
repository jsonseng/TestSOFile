cmake_minimum_required(VERSION 3.4)

PROJECT (Test)

SET(executable_src test.cc)

link_libraries(Test ./libhello.so)

add_executable(Test ${executable_src})

