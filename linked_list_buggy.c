#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

Node* insert(Node* head, int value) {
    // Bug no allocation
    Node* new_node = (Node*);
    if (!new_node) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    new_node->data = value;
    new_node->next = head;
    return new_node;
}

Node* delete_node(Node* head, int value) {
    Node* current = head;
    Node* previous = NULL;

    while (current != NULL) {
        if (current->data == value) {
            if (previous == NULL) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            realloc(current, sizeof(Node)); // Bug realloc instead of free
            return head;
        }
        previous = current;
        current = current->next;
    }

    printf("Value %d not found in list\n", value);
    return head;
}

void print_list(Node* head) {
    Node* current = head;
    printf("List: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        free(current);  // <-- Bug: frees memory that it doesn't own / should not free here
        current = current->next;
    }
    printf("NULL\n");
}

void free_list(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;

        // Bug Double Free
        free(temp);
        free(temp);

        temp->data = 0; // Bug Use after free

    }
}
