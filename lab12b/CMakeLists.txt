cmake_minimum_required(VERSION 3.13)
project(lab12b)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(lab12b
        bit_counter.h
        counter.h
        int_counter.h
        main.cpp
        mod_counter.h bounded_counter.h)
