//
// Created by CYRO4S <me@ralf.ren> on 2018/10/5.
// from: https://www.geeksforgeeks.org/priority-queue-using-linked-list/
//

#ifndef DATA_STRUCTURE_PRIORITY_QUEUE_LL_H
#define DATA_STRUCTURE_PRIORITY_QUEUE_LL_H

struct Node {
    int data;
    int priority;
    struct Node *next;
};

struct Node* createNode(int data, int priority);
int peek(struct Node** head);
int pop(struct Node** head);
void push(struct Node** head);

#endif //DATA_STRUCTURE_PRIORITY_QUEUE_LL_H
