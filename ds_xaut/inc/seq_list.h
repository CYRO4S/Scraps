//
// Created by Ralf Ren on 2018/12/4.
//

#include "pre_defined.h"

#ifndef DS_XAUT_SEQ_LIST_H
#define DS_XAUT_SEQ_LIST_H

#define CAPACITY_INIT 100
#define CAPACITY_INCREMENT 10

typedef int ElemType;

typedef struct {
    ElemType *element;
    int length;
    int capacity;
} SeqList;

Status init(SeqList &l);
Status insert(SeqList &l, int i, ElemType e);



#endif //DS_XAUT_SEQ_LIST_H
