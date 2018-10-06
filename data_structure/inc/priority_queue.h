//
// Created by CYRO4S <me@ralf.ren> on 2018/10/6.
// from: https://www.geeksforgeeks.org/priority-queue-set-1-introduction/
//

#ifndef DATA_STRUCTURE_PRIORITY_QUEUE_H
#define DATA_STRUCTURE_PRIORITY_QUEUE_H

#include <stdbool.h>

typedef struct {
    int front, rear, size;
    unsigned int capacity;
    int priority;
    int *array;
} Queue;

Queue* createQueue(unsigned int capacity);
void destructQueue(Queue* queue);

void enqueue(Queue* queue, int data, int priority);
void removeTop(Queue* queue);
int top(Queue* queue);

bool isFull(Queue* queue);
bool isEmpty(Queue* queue);

#endif //DATA_STRUCTURE_PRIORITY_QUEUE_H
