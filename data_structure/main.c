#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include "inc/queue_linked_list.h"

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