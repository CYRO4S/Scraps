//
// Created by CYRO4S <me@ralf.ren> on 2018/10/4.
//

#ifndef DATA_STRUCTURE_QUEUE_LINKED_LIST_H
#define DATA_STRUCTURE_QUEUE_LINKED_LIST_H

struct QueueNode
{
    int key;
    struct QueueNode* next;
};

typedef struct
{
    struct QueueNode *front, *rear;
} LinkedQueue;

struct QueueNode* createNode(int key);
LinkedQueue* createQueue();
void enqueue(LinkedQueue* queue, int key);
struct QueueNode* dequeue(LinkedQueue* queue);


#endif //DATA_STRUCTURE_QUEUE_LINKED_LIST_H
