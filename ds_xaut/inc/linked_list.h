//
// Created by Ralf Ren on 2018/12/5.
//

#include "pre_defined.h"

#ifndef DS_XAUT_LINKED_LIST_H
#define DS_XAUT_LINKED_LIST_H

struct Node {
    elem element;
    struct Node* next;
};

Status getElement(const Node* list, int index, elem& element);
Status insert(Node* list, int index, elem element);
Status remove(Node* list, int index, elem& element);
Status create(Node* list, int quantity);

#endif //DS_XAUT_LINKED_LIST_H
