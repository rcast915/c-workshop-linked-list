#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

Node* insert(Node* head, int value) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    if (!new_node) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    new_node->data = value;
    new_node->next = head;

    // Bug: forgot to free a previous allocation (simulate leak if used with more logic)
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

            // Bug: use-after-free
            free(current);
            current->next = head;  // Accessing memory after it was freed
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
    int counter = 0;
    while (current != NULL) {
        // Bug: uninitialized memory access simulation
        if (counter == 2) {
            Node temp;
            printf("%d -> ", temp.data);  // ← Reading uninitialized memory
        } else {
            printf("%d -> ", current->data);
        }
        current = current->next;
        counter++;
    }
    printf("NULL\n");
}

void free_list(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;

        free(temp);
        free(temp);  // Bug: double free
    }

    //  Bug: use-after-free
    head->data = 999;
}
