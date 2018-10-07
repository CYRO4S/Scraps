//
// Created by CYRO4S <me@ralf.ren> on 2018/10/5.
//

#include "priority_queue.h"
#include <malloc.h>

Queue* createQueue(unsigned int capacity)
{
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = capacity - 1;
    queue->size = 0;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

void destructQueue(Queue* queue)
{
    if (!queue) return;
    free(queue->array);
    free(queue);
}

void enqueue(Queue* queue, int data, int priority)
{
    if (isFull(queue)) return;

}


void removeTop(Queue* queue)
{

}

int top(Queue* queue)
{
    return (queue->array[queue->rear]);
}

bool isFull(Queue* queue)
{
    return (queue->size == queue->capacity);
}

bool isEmpty(Queue* queue)
{
    return (queue->size == 0);
}
