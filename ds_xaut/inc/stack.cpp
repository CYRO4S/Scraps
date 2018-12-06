//
// Created by Ralf Ren on 2018-12-06.
//

#include "stack.h"
#include <mm_malloc.h>

Status init(SeqStack& stack)
{
    stack.base = (elem*)malloc(CAPACITY_INIT_SIZE * sizeof(elem));
    if (! stack.base) return OVERFLOW;

    stack.top = stack.base;
    stack.capacity = CAPACITY_INIT_SIZE;

    return OK;
}

Status top(SeqStack& stack, elem& element)
{
    if (isEmpty(stack)) return EMPTY;
    element = *(stack.top - 1);
    return OK;
}

Status push(SeqStack& stack, elem element)
{
    if (isFull(stack)) if (enlarge(stack) == OVERFLOW) return OVERFLOW;

    *(stack.top ++) = element;
    return OK;
}

Status pop(SeqStack& stack, elem& element)
{
    if (isEmpty(stack)) return EMPTY;
    element = *(stack.top);
    stack.top --;

    return OK;
}

Status isEmpty(SeqStack& stack)
{
    if (stack.top == stack.base) return TRUE;
    return FALSE;
}

Status isFull(SeqStack& stack)
{
    if (stack.top - stack.base >= stack.capacity) return TRUE;
    return FALSE;
}

Status enlarge(SeqStack& stack)
{
    stack.base = (elem*)realloc(stack.base, (stack.capacity + CAPACITY_INCREMENT) * sizeof(elem));
    if (! stack.base) return OVERFLOW;
    stack.top = stack.base + stack.capacity;
    stack.capacity += CAPACITY_INCREMENT;
    return OK;
}