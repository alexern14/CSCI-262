cmake_minimum_required(VERSION 3.13)
project(lab11)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(lab11
        main.cpp
        Queue.h)
