#include <stdio.h>
#include <stdlib.h>

// #include "linked_list/linked_list.h"
#include "dynamic_array/dynamic_array.h"

// void linked_list_demo(void) {
//     printf("\n");
//     printf("--------------------\n");
//     printf("| Linked list demo |\n");
//     printf("--------------------\n");
//
//     Node *head  = create_node(NULL);
//     push_back(head, (void*) 12);
//     push_back(head, (void*) 23);
//     push_back(head, (void*) 4);
//
//     insert_at(head, 1, (void*) 6);
//
//     printf("Pop front: %d\n", (int) pop_front(head));
//
//     for (const Node *tmp = head->next; tmp != NULL; tmp = tmp->next) {
//         printf("%d\n", (int) tmp->data);
//     }
//
//     free_node_recursive(head);
//     head = NULL;
// }

void dynamic_array_demo(void) {
    printf("\n");
    printf("--------------------\n");
    printf("| Dynamic array demo |\n");
    printf("--------------------\n");

    DynamicArray *array = DynamicArray_new();

    for (int i = 0; i < 16; i++) {
        push(array, (void*)i);
    }

    for (int i = 0; i < 8; i++) {
        pop(array);
    }

    printf("%d\n", array->size);
    printf("%d\n\n", array->capacity);

    for (int i = 0; i < array->size; i++) {
      printf("%d\n", (int)at(array, i));
    }

    DynamicArray_destroy(array);
}

int main(void) {
    printf("Hello, World!\n");

    // linked_list_demo();
    dynamic_array_demo();

    return 0;
}
