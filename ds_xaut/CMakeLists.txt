cmake_minimum_required(VERSION 3.12)
project(ds_xaut)

set(CMAKE_CXX_STANDARD 11)

add_executable(ds_xaut main.cpp inc/pre_defined.h inc/sequence.cpp inc/sequence.h inc/linked_list.cpp inc/linked_list.h inc/double_linked_list.cpp inc/double_linked_list.h inc/stack.cpp inc/stack.h stack_application.cpp)