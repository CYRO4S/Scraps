//
// Created by Ralf Ren on 2018/12/4.
//

#include "seq_list.h"
#include <mm_malloc.h>

Status init(SeqList &l)
{
    // build a new list
    l.element = (ElemType *)malloc(CAPACITY_INIT * sizeof(ElemType));

    // cannot allocate memory for elements
    if (! l.element) return OVERFLOW;

    // initial length & list size
    l.length = 0;
    l.capacity = CAPACITY_INIT;

    return OK;
}

Status insert(SeqList &l, int i, ElemType e)
{
    // insert before 'i'
    // invalid 'i'
    if (i < 1 || i > l.length + 1) return ERROR;

    // list is full
    if (l.length >= l.capacity) {
        auto new_base = (ElemType *)realloc(l.element,
                (l.capacity + CAPACITY_INCREMENT) * sizeof(ElemType));
        if (!new_base) return OVERFLOW;
        l.element = new_base;
        l.capacity += CAPACITY_INCREMENT;
    }

    auto insert_pos = &(l.element[i - 1]);
    for (auto p = &(l.element[l.length - 1]); p >= insert_pos; --p)
    {
        *(p + 1) = * p;
    }

    *insert_pos = e;
    ++l.length;
    return OK;

}

