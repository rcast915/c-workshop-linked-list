#include <stdio.h>
#include "linked_list.h"

int main() {
    
    Node* head = NULL;

    head = insert(head, 10);
    head = insert(head, 20);
    head = insert(head, 30);

    print_list(head); // Expected output: 30 -> 20 -> 10 -> NULL

    head = delete_node(head, 20);
    print_list(head); // Expected output: 30 -> 10 -> NULL

    free_list(head);
    
    
    
    

    return 0;
}
