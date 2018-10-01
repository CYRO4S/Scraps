//
// Created by CYRO4S <me@ralf.ren> on 2018/9/28.
//
#include <malloc.h>
#include "sequence_list.h"

enum Status init(SeqList* list)
{
    list->element = malloc(LIST_INIT_SIZE * sizeof(ElementType));
    if (!list->element)
        return Overflow;
    list->length = 0;
    list->size = LIST_INIT_SIZE;
    return OK;
}

enum Status destruct(SeqList* list)
{
    if (!list->element)
        return NullList;
    free(list->element);
    list->element = NULL;
    list->length = 0;
    list->size = 0;
    return OK;
}

enum Status clear(SeqList* list)
{
    if (!list->element)
        return NullList;
    list->length = 0;
    return OK;
}

enum Status insert(SeqList* list, int index, ElementType element)
{
    if (!list->element)
        return NullList;
    if (index < 1 || index > list->length + 1)
        return InvalidArgument;
    if (list->length == list->size)
    {
        ElementType* new;
        new = realloc(list->element, (list->size + LIST_INCREMENT) * sizeof(ElementType));
        if (!new)
            return Overflow;
        list->element = new;
        list->size += LIST_INCREMENT;
    }
    ElementType* insert;
    insert = list->element + index - 1;
    for (ElementType* i = list->element + list->length - 1; i >= insert; --i)
        *(i + 1) = *i;
    *insert = element;
    ++list->length;
    return OK;
}

enum Status deleteAt(SeqList* list, int index)
{
    if (!list->element)
        return NullList;
    if (index < 1 || index > list->length + 1)
        return InvalidArgument;
    ElementType *remove, *last;
    remove = list->element + index - 1;
    last = list->element + list->length - 1;
    for (++remove; remove<=last; ++remove)
        *(remove - 1) = *remove;
    list->length--;
    return OK;
}

const enum Status isEmpty(SeqList* list, bool* result)
{
    if (!list->element)
        return NullList;
    if (list->length == 0)
        *result = true;
    else
        *result = false;
    return OK;
}

const enum Status getLength(SeqList* list, int* result)
{
    if (!list->element)
        return NullList;
    *result = list->length;
    return OK;
}

const enum Status getElement(SeqList* list, int index, ElementType* result)
{
    if (!list->element)
        return NullList;
    if (index < 1 || index > list->length)
        return InvalidArgument;
    *result = *(list->element + index - 1);
    return OK;
}

const enum Status getElementIndex(SeqList* list, ElementType element, int* result)
{
    if (!list->element)
        return NullList;
    ElementType* first = list->element;
    int i = 1;
    while (i <= list->length && (*first++ != element))
        ++i;
    if (i < list->length)
        *result = i;
    else
        *result = 0;
    return OK;
}

const enum Status getPreviousElement(SeqList* list, ElementType element, ElementType* result)
{
    if (!list->element)
        return NullList;
    int i = 2;
    ElementType* p = list->element + 1;
    while (i <= list->length && *p != element)
    {
        p++;
        i++;
    }
    if (i > list->length)
        return FirstOrNotExist;
    else
    {
        *result = *--p;
        return OK;
    }
}

const enum Status getNextElement(SeqList* list, ElementType element, ElementType* result)
{
    if (!list->element)
        return NullList;
    ElementType* p = list->element;
    int i = 0;
    while (i < list->length && *p != element)
    {
        i++;
        p++;
    }
    if (i == list->length)
        return LastOrNotExist;
    else
    {
        *result = *++p;
        return OK;
    }
}
