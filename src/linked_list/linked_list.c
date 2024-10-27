#include "linked_list.h"
#include <stdlib.h>

Node *create_node(void *data) {
    Node *node = malloc(sizeof(Node));
    if (node == NULL) return NULL;

    node->data = data;
    node->next = NULL;

    return node;
}

bool free_node_recursive(Node *node) {
    if (node == NULL) return false;

    if (node->next != NULL) free_node_recursive(node->next);
    free(node);
    node = NULL;

    return true;
}

bool free_list(Node *head) {
    if (empty(head)) return false;

    for (int i = size(head) - 1; i >= 0; i--) erase(head, i);
    free(head);
    head = NULL;

    return true;
}

int size(const Node *head) {
    if (head == NULL) return 0;

    int count = 0;
    for (const Node *tmp = head->next; tmp != NULL; tmp = tmp->next) count++;
    return count;
}

bool empty(const Node *head) {
    if (head == NULL) return true;

    return head->next == NULL;
}

void* value_at(const Node *head, const int index) {
    if (empty(head)) return NULL;
    if (index < 0 || index >= size(head)) return NULL;

    const Node *tmp = head->next;
    for (int i = 0; i < index; i++) {
        if (tmp->next == NULL) return NULL;
        tmp = tmp->next;
    }

    return tmp->data;
}

bool push_front(Node *head, void *value) {
    if (head == NULL) return false;

    Node *node = create_node(value);
    if (node == NULL) return false;

    node->next = head->next;
    head->next = node;

    return true;
}

void* pop_front(Node *head) {
    if (empty(head)) return NULL;

    Node *node = head->next;
    head->next = node->next;

    void *data = node->data;

    free(node);
    node = NULL;

    return data;
}

bool push_back(Node *head, void *value) {
    if (head == NULL) return false;

    Node *last_node = head;
    while (last_node->next) last_node = last_node->next;

    Node *node = create_node(value);
    if (node == NULL) return false;

    last_node->next = node;

    return true;
}

void* pop_back(Node *head) {
    if (empty(head)) return NULL;

    Node *new_last_node = head;
    while (new_last_node->next->next) new_last_node = new_last_node->next;

    Node *last_node = new_last_node->next;
    new_last_node->next = NULL;

    void *data = last_node->data;

    free(last_node);
    last_node = NULL;

    return data;
}

void* front(const Node *head) {
    if (empty(head)) return NULL;

    return head->next->data;
}

void* back(const Node *head) {
    if (empty(head)) return NULL;

    const Node *last_node = head->next;
    while (last_node->next) last_node = last_node->next;

    return last_node->data;
}

bool insert_at(Node *head, const int index, void *value) {
    if (head == NULL) return false;
    if (index < 0 || index >= size(head)) return false;

    Node *prev = head;
    for (int i = 0; i < index; i++) {
        prev = prev->next;
        if (prev == NULL) return false;
    }

    Node *node = create_node(value);
    if (node == NULL) return false;

    node->next = prev->next;
    prev->next = node;

    return true;
}

bool erase(Node *head, const int index) {
    if (empty(head)) return false;
    if (index < 0 || index >= size(head)) return false;

    Node *prev = head;
    for (int i = 0; i < index; i++) {
        prev = prev->next;
        if (prev == NULL) return false;
    }

    Node *node = prev->next;
    prev->next = node->next;

    free(node);
    node = NULL;

    return true;
}

void* value_n_from_end(const Node *head, const int n) {
    if (empty(head)) return NULL;

    const int length = size(head);
    const int index = length - 1 - n;

    return value_at(head, index);
}

bool reverse(Node *head) {
    if (empty(head)) return false;

    Node *new_head = create_node(NULL);
    if (new_head == NULL) return false;

    for (const Node *tmp = head->next; tmp != NULL; tmp = tmp->next) push_front(new_head, tmp->data);

    free_node_recursive(head->next);
    head->next = new_head->next;

    free(new_head);
    new_head = NULL;

    return true;
}

bool remove_value(Node *head, const void *value) {
    if (empty(head)) return false;

    Node *prev = head;
    Node *node = prev->next;

    while (node != NULL) {
        if (node->data == value) {
            prev->next = node->next;

            free(node);
            node = NULL;

            return true;
        }

        prev = node;
        node = prev->next;
    }

    return false;
}