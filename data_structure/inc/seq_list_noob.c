//
// Created by CYRO4S <me@ralf.ren> on 2018/10/1.
//

#include "seq_list_noob.h"
#include <malloc.h>

NoobSeqList* init()
{
    NoobSeqList *list;
    list = (NoobSeqList*)malloc(sizeof(NoobSeqList));
    list->length = 0;
    return list;
}

void insert(NoobSeqList *list, int index, DataType data)
{
    // list is full.
    if (list->length == MAX_SIZE - 1)
        return;

    // invalid insert location
    if (index < 1 || index > list->length + 1)
        return;

    for (int j = list->length; j >= index; --j)
        list->data[j+1] = list->data[j];
    list->data[index] = data;
    list->length++;
}

void delete(NoobSeqList *list, int index)
{
    // list is empty
    if (list->length == 0)
        return;

    // invalid remove location
    if (index < 1 || index > list->length)
        return;

    for (int j = index + 1; j <= list->length; ++j)
        list->data[j-1] = list->data[j];
    list->length--;
}

int locateReverseNoob(NoobSeqList *list, DataType data)
{
    int i = list->length;
    // the following operation is destructive.
    // should not change value of the original list in locating element.
    list->data[0] = data;
    while (list->data[i] != data)
        i--;
    return i;
}

const int locateReverse(NoobSeqList list, DataType data)
{
    int i = list.length;
    list.data[0] = data;
    while (list.data[i] != data)
        i--;
    return i;
}

const int locate(NoobSeqList* list, DataType data)
{
    int i = 1;
    while (i < list->length && list->data[i] != data)
        i++;
    if (list->data[i] == data)
        return i;
    else
        return 0;
}

void reverse(NoobSeqList* list)
{
    int data;
    int len = list->length;
    for (int i = 1; i < len/2; ++i) {
        data = list->data[i];
        list->data[i] = list->data[len-i+1];
        list->data[len-i+1] = data;
    }
}

// merge sorted list A & B to list 'result'.
// noob
void mergeSortedLists(NoobSeqList* list_a, NoobSeqList* list_b, NoobSeqList** result)
{
    int i = 1, j = 1, k = 1;

    // new list is out of size
    if (list_a->length + list_b->length >= MAX_SIZE)
        return;

    // the following operation is noob action.
    *result = (NoobSeqList*)malloc(sizeof(NoobSeqList));
    while (i <= list_a->length && j <= list_b->length)
        if (list_a->data[i] < list_b->data[j])
            (*result)->data[k++] = list_a->data[i++];
        else
            (*result)->data[k++] = list_b->data[j++];
    while (i <= list_a->length)
        (*result)->data[k++] = list_a->data[i++];
    while (j <= list_b->length)
        (*result)->data[k++] = list_b->data[j++];
    (*result)->length = k - 1;
}