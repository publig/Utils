cmake_minimum_required(VERSION 3.19)
project(Utils)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-O3 -Wall")
include_directories(./)

add_executable(base64
        Base64/Base64.cpp
        Base64/Base64.h
        examples/base64_demo.cpp)
