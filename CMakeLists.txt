cmake_minimum_required(VERSION 3.29)
project(ieor_4732)

set(CMAKE_CXX_STANDARD 11)

add_executable(ieor_4732 main.cpp
        option.h
        option.cpp
        european.h
        european.cpp)
