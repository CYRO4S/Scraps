//
// Created by Ralf Ren on 2018/12/5.
//

#include <mm_malloc.h>
#include <stdio.h>
#include "linked_list.h"

Status getElement(const Node* list, int index, elem& element)
{
    if (!list) return NULL_POINTER;
    if (index < 1) return INVALID_INDEX;

    Node* ptr = list->next;
    int i = 1;

    while (ptr && i < index)
    {
        ptr = ptr->next;
        i++;
    }

    if (!ptr || i > index) return NOT_FOUND;
    element = ptr->element;
    return OK;
}

Status insert(Node* list, int index, elem element)
{
    if (!list) return NULL_POINTER;
    if (index < 1) return INVALID_INDEX;

    Node* ptr = list;
    int i = 0;
    while (ptr && i < index - 1)
    {
        ptr = ptr->next;
        i++;
    }
    if (!ptr || i > index - 1) return NOT_FOUND;

    Node* new_node = (Node*)malloc(sizeof(Node));

    new_node->element = element;
    new_node->next = ptr->next;
    ptr->next = new_node;

    return OK;
}

Status remove(Node* list, int index, elem& element)
{
    if (!list) return NULL_POINTER;
    if (index < 1) return INVALID_INDEX;

    Node* ptr = list;
    int i = 0;
    while (ptr->next && i < index - 1)
    {
        ptr = ptr->next;
        i++;
    }
    if (!(ptr->next) || i > index - 1) return INVALID_INDEX;

    Node* rm_node = ptr->next;
    ptr->next = rm_node->next;
    element = rm_node->element;
    free(rm_node);

    return OK;
}

Status create(Node* list, int quantity)
{
    list = (Node*)malloc(sizeof(Node));
    list->next = nullptr;

    for (int i = quantity; i > 0; i--)
    {
        Node* new_node = (Node*)malloc(sizeof(Node));
        scanf("%d", &new_node->element);
        new_node->next = list->next;
        list->next = new_node;
    }
    return OK;
}
