cmake_minimum_required(VERSION 3.13)
project(project1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(project1
        personality_test.cpp
        personality_test.h
        proj1.cpp)
