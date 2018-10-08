cmake_minimum_required(VERSION 3.10)
project(data_structure C)

set(CMAKE_C_STANDARD 99)

add_executable(data_structure main.c inc/queue_linked_list.c inc/queue_linked_list.h inc/linked_list.c inc/linked_list.h inc/priority_queue_ll.c inc/priority_queue_ll.h)