cmake_minimum_required(VERSION 3.3)
project(mystack)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp mystack.h)
add_executable(mystack ${SOURCE_FILES})