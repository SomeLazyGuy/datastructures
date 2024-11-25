#ifndef BINARY_SEARCH_TREE
#define BINARY_SEARCH_TREE

#include <stdbool.h>

typedef struct node {
	int value;
	struct node *left;
	struct node *right;
	struct node *parent;
} Node;

Node *Node_new(Node *parent, int value);
void Node_destroy(Node *node);
bool search_value(Node *root, int value);
void insert_value(Node *root, int value);
void remove_value(Node *root, int value);

#endif // BINARY_SEARCH_TREE
