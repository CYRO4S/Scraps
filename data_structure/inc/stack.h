//
// Created by CYRO4S <me@ralf.ren> on 2018/10/3.
//

#ifndef DATA_STRUCTURE_STACK_H
#define DATA_STRUCTURE_STACK_H

#define MAX_SIZE 20
typedef struct
{
    int elements[MAX_SIZE];
    int count;
} Stack;

enum STATUS
{
    OK = 0,
    NULL_REFERENCE = 1,
    EMPTY_STACK = 2
};

enum STATUS push(Stack* stack, int element);
enum STATUS pop(Stack* stack);
const enum STATUS top(Stack* stack, int* result);


#endif //DATA_STRUCTURE_STACK_H
