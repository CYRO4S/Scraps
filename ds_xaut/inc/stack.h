//
// Created by Ralf Ren on 2018-12-06.
//

#include "pre_defined.h"

#ifndef DS_XAUT_STACK_H
#define DS_XAUT_STACK_H

const int CAPACITY_INIT_SIZE = 10;
const int CAPACITY_INCREMENT = 1;

typedef struct {
    elem*  base;
    elem*  top;
    int    capacity;
} SeqStack;

Status init(SeqStack& stack);
Status top(SeqStack& stack, elem& element);
Status push(SeqStack& stack, elem element);
Status pop(SeqStack& stack, elem& element);
Status pop(SeqStack& stack);
Status isEmpty(SeqStack& stack);
Status isFull(SeqStack& stack);
Status enlarge(SeqStack& stack);

#endif //DS_XAUT_STACK_H
