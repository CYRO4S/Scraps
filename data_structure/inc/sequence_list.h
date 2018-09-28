//
// Created by me on 2018/9/28.
//
#include <stdbool.h>
#ifndef DATA_STRUCTURE_SEQUENCE_LIST_H
#define DATA_STRUCTURE_SEQUENCE_LIST_H

#define LIST_INIT_SIZE 10
#define LIST_INCREMENT 2

typedef int ElementType;

typedef struct
{
    ElementType* element;
    int length;
    int size;
} SeqList;

enum Status
{
    OK = 0,
    NullList = 1,
    Overflow = 2,
    InvalidArgument = 3,
    FirstOrNotExist = 4,
    LastOrNotExist = 5
};

enum Status init(SeqList* list);
enum Status destruct(SeqList* list);
enum Status clear(SeqList* list);
enum Status insert(SeqList* list, int index, ElementType element);
enum Status delete(SeqList* list, ElementType element);
enum Status deleteAt(SeqList* list, int index);
const enum Status isEmpty(SeqList* list, bool* result);
const enum Status getLength(SeqList* list, int* result);
const enum Status getElement(SeqList* list, int index, ElementType* result);
const enum Status getElementIndex(SeqList* list, ElementType element, int* result);
const enum Status getPreviousElement(SeqList* list, ElementType element, ElementType* result);
const enum Status getNextElement(SeqList* list, ElementType element, ElementType* result);

#endif //DATA_STRUCTURE_SEQUENCE_LIST_H
