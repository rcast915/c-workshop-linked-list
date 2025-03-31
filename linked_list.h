#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* insert(Node* head, int value);
Node* delete_node(Node* head, int value);
void print_list(Node* head);
void free_list(Node* head);

#endif
