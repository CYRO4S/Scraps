//
// Created by CYRO4S <me@ralf.ren> on 2018/10/4.
//

#include "linked_list.h"
#include <malloc.h>
#include <stdio.h>


// add a node at the beginning of the list.
// new_node -> head -> ...
void pushGeneric(struct GenericNode** head_ref, void *new_data, size_t data_size)
{
    struct GenericNode *new_node = (struct GenericNode*)malloc(sizeof(struct GenericNode));
    new_node->next = (*head_ref);

    // allocate memory for new data
    new_node->data = malloc(data_size);
    // copy data to new node, byte by byte.
    // assume char is 1 byte
    for (int i = 0; i < data_size; ++i)
        *(char *)(new_node->data + i) = *(char *)(new_data + i);
    (*head_ref) = new_node;
}

// add a node at the beginning of the list.
// new_node -> head -> ...
void push(struct Node** head, int data)
{
    // allocate node
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    // put in data
    new_node->data = data;
    // make next of new node as current head
    new_node->next = (*head);
    // change head to the new node now
    (*head) = new_node;
}

// check the list if contains specified data
bool contains(struct Node* head, int data)
{
    struct Node *current = head;
    while (current != NULL)
    {
        if (current->data == data)
            return true;
        current = current->next;
    }
    return false;
}

// insert a node after specified previous node
void insert(struct Node* prev, int data)
{
    // check if given previous node is NULL
    if (!prev) return;

    // allocate new node
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));

    // put in the data
    new_node->data = data;

    // make next of new node as next of previous node
    new_node->next = prev->next;

    // move the next of previous node as new node
    prev->next = new_node;
}

// append a node to end of the list
void append(struct Node** head, int data)
{
    // allocate new node
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node *last = *head;

    // put in the data
    new_node->data = data;

    // new node is going to be the last node.
    new_node->next = NULL;

    // if list is empty, make the new node as head
    if (!*head)
    {
        *head = new_node;
        return;
    }

    // else traverse till the last node
    while (last->next != NULL)
        last = last->next;

    // change the next of last node
    last->next = new_node;
}

// show all members in a list
void show(struct Node* node)
{
    while (node != NULL)
    {
        printf(" %d ", node->data);
        node = node->next;
    }
}

void delete(struct Node** head, int data)
{
    struct Node* temp = *head;
    struct Node *prev = temp;

    // if head node itself holds the data to be deleted
    if (temp != NULL && temp->data == data)
    {
        *head = temp->next;
        free(temp);
        return;
    }

    // search for the data
    while (temp != NULL && temp->data != data)
    {
        prev = temp;
        temp = temp->next;
    }

    // if data was not present in the list
    if (temp == NULL) return;

    // data is in the last node
    // unlink last node from the linked list
    prev->next = temp->next;

    // release memory
    free(temp);
}