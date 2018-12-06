//
// Created by Ralf Ren on 2018-12-06.
//

#include "pre_defined.h"

#ifndef DS_XAUT_DOUBLE_LINKED_LIST_H
#define DS_XAUT_DOUBLE_LINKED_LIST_H

struct DNode {
    elem    element;
    DNode*  prior;
    DNode*  next;
};


Status insert(DNode* list, int index, elem element);
Status remove(DNode* list, int index, elem& element);
DNode* getPointerAt(DNode* list, int index);



#endif //DS_XAUT_DOUBLE_LINKED_LIST_H
