//
// Created by CYRO4S <me@ralf.ren> on 2018/10/3.
//

#include "queue_array.h"
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

enum STATUS destructQueue(Queue* queue)
{
    if (!queue)
        return NULL_REFERENCE;
    free(queue->array);
    free(queue);
    return OK;
}

enum STATUS enqueue(Queue* queue, int element)
{
    if (isFull(queue))
        return FULL_QUEUE;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = element;
    queue->size++;
    return OK;
}

enum STATUS dequeue(Queue* queue)
{
    if (isEmpty(queue))
        return EMPTY_QUEUE;
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size --;
    return OK;
}

const bool isFull(Queue* queue)
{
    return (queue->size == queue->capacity);
}

const bool isEmpty(Queue* queue)
{
    return (queue->size == 0);
}

const enum STATUS front(Queue* queue, int* result)
{
    if (isEmpty(queue))
        return EMPTY_QUEUE;
    *result = queue->array[queue->front];
    return OK;
}

const enum STATUS rear(Queue* queue, int* result)
{
    if (isEmpty(queue))
        return EMPTY_QUEUE;
    *result = queue->array[queue->rear];
    return OK;
}

// main function for testing
/*
void showFrontAndRear(Queue* queue)
{
    int front_item, rear_item;
    front(queue, &front_item);
    rear(queue, &rear_item);
    printf("Front: %d\n", front_item);
    printf("Rear:  %d\n\n", rear_item);
}

int main(int argc, char* argv[])
{
    Queue* queue = createQueue(20);

    enqueue(queue, 10);
    showFrontAndRear(queue);
    enqueue(queue, 20);
    showFrontAndRear(queue);
    enqueue(queue, 30);
    showFrontAndRear(queue);
    enqueue(queue, 40);
    showFrontAndRear(queue);

    dequeue(queue);
    showFrontAndRear(queue);
    dequeue(queue);
    showFrontAndRear(queue);
    dequeue(queue);
    showFrontAndRear(queue);
    return 0;
}
 */