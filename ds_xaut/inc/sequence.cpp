//
// Created by Ralf Ren on 2018/12/5.
//

#include "sequence.h"
#include <mm_malloc.h>

Status init(Sequence& seq)
{
    seq.element = (elem*)malloc(CAPACITY_INIT_SIZE * sizeof(elem));
    if (!seq.element) return OVERFLOW;

    seq.length = 0;
    seq.capacity = CAPACITY_INIT_SIZE;
    return OK;
}

Status enlarge(Sequence& seq)
{
    auto new_element = (elem*)realloc(seq.element, (seq.capacity + CAPACITY_INCREMENT) * sizeof(elem));
    if (!new_element) return OVERFLOW;

    seq.element = new_element;
    seq.capacity += CAPACITY_INCREMENT;
    return OK;
}

Status insert(Sequence& seq, int index, elem element)
{
    if (!seq.element) return NULL_POINTER;
    if (index < 0 || index > seq.length) return INVALID_INDEX;
    if (seq.length >= seq.capacity) enlarge(seq);

    auto insert_pos = &(seq.element[index]);
    for (auto i = &(seq.element[seq.length - 1]); i >= insert_pos; --i)
        *(i + 1) = *i;

    *insert_pos = element;
    seq.length ++;
    return OK;
}

Status remove(Sequence& seq, int index, elem& element)
{
    if (!seq.element) return NULL_POINTER;
    if (seq.length == 0) return EMPTY;
    if (index < 0 || index > seq.length - 1) return INVALID_INDEX;

    element = seq.element[index];
    for (auto i = &(seq.element[index]); i < &(seq.element[seq.length -1]); i++)
        *i = *(i + 1);

    seq.length --;
    return OK;
}

Status locate(Sequence& seq, elem element, int& index)
{
    for (int i = 0; i <= seq.length - 1; i++)
    {
        if (seq.element[i] == element)
        {
            index = i;
            return OK;
        }
    }
    return NOT_FOUND;
}
