//
// Created by CYRO4S <me@ralf.ren> on 2018/10/4.
// from: https://www.geeksforgeeks.org/generic-linked-list-in-c-2/
//

#ifndef DATA_STRUCTURE_LINKED_LIST_H
#define DATA_STRUCTURE_LINKED_LIST_H
#include <stdbool.h>

struct GenericNode
{
    // any data type can be stored
    void *data;
    struct GenericNode *next;
};

struct Node
{
    int data;
    struct Node *next;
};

// Generic linked list
void pushGeneric(struct GenericNode** head_ref, void *new_data, size_t data_size);

// Integer linked list
void push(struct Node** head, int data);
void insert(struct Node* prev, int data);
void append(struct Node** head, int data);
bool contains(struct Node* head, int data);
void show(struct Node* head);
void delete(struct Node** head, int data);
#endif //DATA_STRUCTURE_LINKED_LIST_H
