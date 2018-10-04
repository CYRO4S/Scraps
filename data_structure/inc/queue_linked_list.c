//
// Created by CYRO4S <me@ralf.ren> on 2018/10/4.
// from: https://www.geeksforgeeks.org/queue-set-2-linked-list-implementation/
//

#include "queue_linked_list.h"
#include <malloc.h>

struct QueueNode* createNode(int key)
{
    struct QueueNode *temp = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    temp->key = key;
    temp->next = NULL;
    return temp;
}

LinkedQueue* createQueue()
{
    LinkedQueue* queue = (LinkedQueue*)malloc(sizeof(LinkedQueue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

void enqueue(LinkedQueue* queue, int key)
{
    struct QueueNode *temp = createNode(key);

    // if queue is empty,
    // then new node is front and rear both
    if (queue->rear == NULL)
    {
        queue->front = queue->rear = temp;
        return;
    }

    // add the new node at the end of queue and change rear
    queue->rear->next = temp;
    queue->rear = temp;
}

struct QueueNode* dequeue(LinkedQueue* queue)
{
    // queue is empty
    if (queue->front == NULL)
        return NULL;

    // store previous front and move front one node ahead
    struct QueueNode *temp = queue->front;
    queue->front = queue->front->next;

    // if front becomes NULL, then change rear also as NULL
    if (queue->front == NULL)
        queue->rear = NULL;
    return temp;
}

// main function for testing
/*
int main(int argc, char* argv[])
{
    LinkedQueue *queue = createQueue();
    enqueue(queue, 10);
    enqueue(queue, 20);
    dequeue(queue);
    dequeue(queue);
    enqueue(queue, 30);
    enqueue(queue, 40);
    enqueue(queue, 50);

    struct QueueNode *node = dequeue(queue);
    if (node != NULL)
        printf("De-queued: %d", node->key);

    return 0;
}
 */
