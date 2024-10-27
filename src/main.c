#include <stdio.h>
#include "linked_list/linked_list.h"

void linked_list_demo(void) {
    printf("\n");
    printf("--------------------\n");
    printf("| Linked list demo |\n");
    printf("--------------------\n");

    Node *head  = create_node(NULL);
    push_back(head, (void*) 12);
    push_back(head, (void*) 23);
    push_back(head, (void*) 4);

    insert_at(head, 1, (void*) 6);

    printf("Pop front: %d\n", (int) pop_front(head));

    for (const Node *tmp = head->next; tmp != NULL; tmp = tmp->next) {
        printf("%d\n", (int) tmp->data);
    }

    free_node_recursive(head);
    head = NULL;
}

int main(void) {
    printf("Hello, World!\n");

    linked_list_demo();

    return 0;
}
