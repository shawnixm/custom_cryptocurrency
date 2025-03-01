cmake_minimum_required(VERSION 3.30)
project(custom_cryptocurrency)

set(CMAKE_CXX_STANDARD 20)

add_executable(custom_cryptocurrency main.cpp
        blockchain.cpp
        blockchain.h
        block.h
        block.cpp
        transaction.cpp
        transaction.h)
