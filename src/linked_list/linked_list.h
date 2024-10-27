#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>

typedef struct node {
    void *data;
    struct node *next;
} Node;

Node* create_node(void *data);
bool free_node_recursive(Node *node);
bool free_list(Node *head);
int size(const Node *head);
bool empty(const Node *head);
void* value_at(const Node *head, int index);
bool push_front(Node *head, void *value);
void* pop_front(Node *head);
bool push_back(Node *head, void *value);
void* pop_back(Node *head);
void* front(const Node *head);
void* back(const Node *head);
bool insert_at(Node *head, int index, void *value);
bool erase(Node *head, int index);
void* value_n_from_end(const Node *head, int n);
bool reverse(Node *head);
bool remove_value(Node *head, const void *value);

#endif //LINKED_LIST_H
