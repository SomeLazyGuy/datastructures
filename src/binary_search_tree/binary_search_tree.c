#include "binary_search_tree.h"
#include <stdlib.h>

Node *Node_new(Node *parent, int value) {
	Node *node = malloc(sizeof(Node));

	node->parent = parent;
	node->value = value;
	node->left = NULL;
	node->right = NULL;

	return node;
}

void Node_destroy(Node *node) {
	if (node->left != NULL) {
		Node_destroy(node->left);
	}

	if (node->right != NULL) {
		Node_destroy(node->right);
	}

	free(node);
}

bool search_value(Node *root, int value) {
	if (root == NULL) {
		return false;
	}

	if (root->value == value) {
		return true;
	}

	return search_value(root->left, value) || search_value(root->right, value);
}

void insert_value(Node *root, int value) {
	Node *current = root;

	while (current->value != value) {
		if (current->value < value) {
			if (current->right == NULL) {
				current->right = Node_new(current, value);
				return;
			}

			current = current->right;
		} else {
			if (current->left == NULL) {
				current->left = Node_new(current, value);
				return;
			}

			current = current->left;
		}
	}
}

void remove_value(Node *root, int value) {
	Node *current = root;

	while (current->value != value) {
		if (current == NULL) {
			return;
		}

		if (current->value < value) {
			current = current->right;
		} else if (current->value > value) {
			current = current->left;
		}
	}

	int child_count = 0;

	if (current->left != NULL) {
		child_count++;
	}

	if (current->right != NULL) {
		child_count++;
	}

	if (child_count == 0) {
		Node_destroy(current);
	} else if (child_count == 1) {
		Node *child;

		if (current->left != NULL) {
			child = current->left;
		} else {
			child = current->right;
		}

		current->value = child->value;
		Node_destroy(child);
	} else {
		/*
		 * if the right child node has a left child node:
		 *	find the smallest value that is still bigger than the value we want to delete
		 *	swap them and delete the leaf node witch now contains the value we want to delete
		 *
		 * if the right child node doesn't have a left child node:
		 *	the right child is the successor to the value we want to delete
		 *	swap the value and the value of the right child
		 *	and delete the node we actually want to delete that now only has one child
		 */
	}
}
