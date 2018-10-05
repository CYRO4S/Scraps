//
// Created by CYRO4S on 2018/10/5.
//

#include "priority_queue_ll.h"
#include <malloc.h>

// create a new node
struct Node* createNode(int data, int priority)
{
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->priority = priority;
    temp->next = NULL;
    return temp;
}

// return the value at head
int peek(struct Node** head)
{
    return (*head)->data;
}

// remove highest priority item
void pop(struct Node** head)
{
    struct Node *temp = *head;
    (*head) = (*head)->next;
    free(temp);
}

void push(struct Node** head, int data, int priority)
{
    struct Node *start = (*head);

    // create new node
    struct Node *temp = createNode(data, priority);

    // Special Case: The head of list has lesser
    // priority than new node. So insert new
    // node before head node and change head node.
    if ((*head)->priority > priority)
    {
        // insert new node before head
        temp->next = *head;
        (*head) = temp;
    }
    else
    {
        // Traverse the list and find a
        // position to insert new node
        while (start->next != NULL && start->next->priority < p)
            start = start->next;
    }

    // Either at the ends of the list
    // or at required position
    temp->next = start->next;
    start->next = temp;
}

bool isEmpty(struct Node** head)
{
    return (*head) == NULL;
}