cmake_minimum_required(VERSION 3.10)
project(data_structure C)

set(CMAKE_C_STANDARD 99)

add_executable(data_structure main.c inc/queue_array.c inc/queue_array.h)