//
// Created by CYRO4S <me@ralf.ren> on 2018/10/3.
//

#ifndef DATA_STRUCTURE_QUEUE_ARRAY_H
#define DATA_STRUCTURE_QUEUE_ARRAY_H
#include <stdbool.h>

typedef struct
{
    int front, rear, size;
    unsigned int capacity;
    int *array;
} Queue;

enum STATUS
{
    OK = 0,
    NULL_REFERENCE = 1,
    EMPTY_QUEUE = 2,
    FULL_QUEUE = 3
};

Queue* createQueue(unsigned int capacity);
enum STATUS destructQueue(Queue* queue);
enum STATUS enqueue(Queue* queue, int element);
enum STATUS dequeue(Queue* queue);
const bool isFull(Queue* queue);
const bool isEmpty(Queue* queue);
const enum STATUS front(Queue* queue, int* result);
const enum STATUS rear(Queue* queue, int* result);

#endif //DATA_STRUCTURE_QUEUE_ARRAY_H
