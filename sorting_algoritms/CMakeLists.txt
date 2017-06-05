cmake_minimum_required(VERSION 3.5.2)
project(sorting_algoritms)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp ListSorter.cpp)
add_executable(sorting_algoritms ${SOURCE_FILES})
