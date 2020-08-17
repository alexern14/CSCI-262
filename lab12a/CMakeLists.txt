cmake_minimum_required(VERSION 3.13)
project(lab12a)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(lab12a
        int_counter.h
        main.cpp
        mod_counter.h)
