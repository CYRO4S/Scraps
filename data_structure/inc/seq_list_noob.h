//
// Created by CYRO4S <me@ralf.ren> on 2018/10/1.
//

#ifndef DATA_STRUCTURE_SEQ_LIST_NOOB_H
#define DATA_STRUCTURE_SEQ_LIST_NOOB_H

#define MAX_SIZE 20
typedef int DataType;

typedef struct
{
    DataType data[MAX_SIZE];
    int length;
}NoobSeqList;

NoobSeqList* init();
void insert(NoobSeqList *list, int index, DataType data);
void delete(NoobSeqList *list, int index);
int locateReverseNoob(NoobSeqList *list, DataType data);
const int locateReverse(NoobSeqList list, DataType data);
const int locate(NoobSeqList* list, DataType data);
void reverse(NoobSeqList* list);
void mergeSortedLists(NoobSeqList* list_a, NoobSeqList* list_b, NoobSeqList** result);


#endif //DATA_STRUCTURE_SEQ_LIST_NOOB_H
