cmake_minimum_required(VERSION 3.5.2)
project(huffman_coding)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp HuffmanNode.cpp HuffmanNode.h Huffman.cpp Huffman.h)
add_executable(huffman_coding ${SOURCE_FILES})