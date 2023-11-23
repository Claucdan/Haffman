cmake_minimum_required(VERSION 3.26)
project(Haffman)

set(CMAKE_CXX_STANDARD 17)

add_executable(Haffman main.cpp
        cmake-build-debug/priority_queue.cpp
        cmake-build-debug/priority_queue.h
        cmake-build-debug/sort.h)
