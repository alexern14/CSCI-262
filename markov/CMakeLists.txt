cmake_minimum_required(VERSION 3.13)
project(markov)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(cmake-build-debug)

add_executable(markov
        cmake-build-debug/alice.txt
        cmake-build-debug/cicero.txt
        cmake-build-debug/gibbon.txt
        cmake-build-debug/hamlet.txt
        cmake-build-debug/mobydick.txt
        cmake-build-debug/obama.txt
        cmake-build-debug/ulysses.txt
    cmake-build-debug/cmake_install.cmake
    cmake-build-debug/CMakeCache.txt
    cmake-build-debug/Makefile
    cmake-build-debug/markov
    cmake-build-debug/markov.cbp
    brute_model.cpp
    brute_model.h
    CMakeLists.txt
    main.cpp
    map_model.cpp
    map_model.h
    markov.cpp
    markov.h
    model.h
    "READ ME"
    word_model.cpp
    word_model.h)
