//
// Created by Ralf Ren on 2018/12/5.
//

#include "pre_defined.h"

#ifndef DS_XAUT_SEQUENCE_H
#define DS_XAUT_SEQUENCE_H

const int CAPACITY_INIT_SIZE = 10;
const int CAPACITY_INCREMENT = 10;

typedef struct {
    elem*  element;
    int    length;
    int    capacity;
} Sequence;

Status init(Sequence& seq);
Status enlarge(Sequence& seq);
Status insert(Sequence& seq, int index, elem element);
Status remove(Sequence& seq, int index, elem& element);
Status locate(Sequence& seq, elem element, int& index);



#endif //DS_XAUT_SEQUENCE_H
