//
// Created by CYRO4S <me@ralf.ren> on 2018/10/3.
//

#include "stack.h"

enum STATUS push(Stack* stack, int element)
{
    if (!stack)
        return NULL_REFERENCE;
    stack->elements[stack->count] = element;
    stack->count++;
    return OK;
}

enum STATUS pop(Stack* stack)
{
    if (!stack)
        return NULL_REFERENCE;
    stack->count--;
    return OK;
}

const enum STATUS top(Stack* stack, int* result)
{
    if (!stack)
        return NULL_REFERENCE;
    if (stack->count == 0)
        return EMPTY_STACK;
    *result = stack->elements[stack->count-1];
    return OK;
}

// main function for testing
/*
void showStackInfo(Stack* stack)
{
    printf("Elements count: %d\n", stack->count);
    printf("Size of stack:  %d bytes\n\n", sizeof(stack));
}

int main(int argc, char* argv[])
{
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->count = 0;
    showStackInfo(stack);

    push(stack, 7);
    showStackInfo(stack);

    push(stack, 3);
    showStackInfo(stack);

    push(stack, 5);
    showStackInfo(stack);

    pop(stack);
    showStackInfo(stack);

    int top_element;
    top(stack, &top_element);
    printf("Top element:    %d\n", top_element);

    return 0;
}
 */
