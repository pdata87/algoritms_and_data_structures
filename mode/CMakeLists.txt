cmake_minimum_required(VERSION 3.7)
project(mode)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Mode.cpp Mode.h)
add_executable(mode ${SOURCE_FILES})