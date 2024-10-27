cmake_minimum_required(VERSION 3.29)
project(datastructures C)

set(CMAKE_C_STANDARD 99)

add_executable(datastructures src/main.c
        src/linked_list/linked_list.c
        src/linked_list/linked_list.h
)
