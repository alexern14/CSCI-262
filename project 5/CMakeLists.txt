cmake_minimum_required(VERSION 3.13)
project(project_5)

set(CMAKE_CXX_STANDARD 14)

add_executable(project_5
        animal.cpp read.h read.cpp node.h play_game.cpp play_game.h expand.cpp expand.h)
