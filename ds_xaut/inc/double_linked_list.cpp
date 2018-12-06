//
// Created by Ralf Ren on 2018-12-06.
//

#include "double_linked_list.h"
#include <mm_malloc.h>

Status insert(DNode* list, int index, elem element)
{
    DNode* ptr = getPointerAt(list, index);
    if (! ptr) return INVALID_INDEX;

    auto new_node = (DNode*)malloc(sizeof(DNode));
    if (! new_node) return OVERFLOW;

    new_node->element = element;

    // connect the left
    new_node->prior = ptr->prior;
    ptr->next = new_node;

    // connect the right
    new_node->next = new_node->prior->next;
    new_node->prior->next = new_node;

    return OK;
}

Status remove(DNode* list, int index, elem& element)
{
    DNode* ptr = getPointerAt(list, index);
    if (! ptr) return INVALID_INDEX;

    element = ptr->element;
    ptr->prior->next = ptr->next;
    ptr->next->prior = ptr->prior;

    free(ptr);
    return OK;
}

DNode* getPointerAt(DNode* list, int index)
{
    DNode* ptr = list->next;
    int i = 1;

    while (ptr != list && i < index) {
        ptr = ptr->next;
        i++;
    }

    if (ptr == list || i > index) return nullptr;
    return ptr;
}
