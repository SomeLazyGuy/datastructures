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
void destroy_tree(Node *root);
int get_node_count(Node *root);
void print_values(Node *root);
void print_tree(Node *root, int level); // prints the the tree top to bottom from left to right in the terminal
int get_height(Node *root);
int get_min(Node *root);
int get_max(Node *root);
bool is_valid_bst(Node *root);
bool search_value(Node *root, int value);
void insert_value(Node *root, int value);
void remove_value(Node *root, int value);

#endif // BINARY_SEARCH_TREE
