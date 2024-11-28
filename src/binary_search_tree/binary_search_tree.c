#include "binary_search_tree.h"
#include <stdlib.h>
#include <stdio.h>

Node *Node_new(Node *parent, int value) {
	Node *node = malloc(sizeof(Node));

	node->parent = parent;
	node->value = value;
	node->left = NULL;
	node->right = NULL;

	return node;
}

void destroy_tree(Node *root) {
	if (root->left != NULL) {
		destroy_tree(root->left);
	}

	if (root->right != NULL) {
		destroy_tree(root->right);
	}

	free(root);
}

int get_node_count(Node *root) {
	if (root == NULL) {
		return 0;
	}

	return 1 + get_node_count(root->left) + get_node_count(root->right);
}

void print_values(Node *root) {
	if (root == NULL) {
		return;
	}

	print_values(root->left);

	printf("%d\n", root->value);

	print_values(root->right);
}

void print_tree(Node *root, int level) {
	if (root == NULL) {
		return;
	}

	print_tree(root->right, level + 1);

	for (int i = 0; i < 4 * level; i++) {
		printf(" ");
	}

	printf("%d\n", root->value);

	print_tree(root->left, level + 1);
}

int get_height(Node *root) {
	if (root == NULL) {
		return 0;
	}

	int height_left = get_height(root->left);
	int height_right = get_height(root->right);

	if (height_left < height_right) {
		return 1 + height_right;
	}

	return 1 + height_left;
}

int get_min(Node *root) {
	Node *current = root;

	while (current->left != NULL) {
		current = current->left;
	}

	return current->value;
}

int get_max(Node *root) {
	Node *current = root;

	while (current->right != NULL) {
		current = current->right;
	}

	return current->value;
}

bool is_valid_bst(Node *root) {
	if (root == NULL) {
		return true;
	}

	if (root->left != NULL) {
		if (root->left->value > root->value) {
			return false;
		}
	}

	if (root->right != NULL) {
		if (root->right->value < root->value) {
			return false;
		}
	}

	return is_valid_bst(root->left) && is_valid_bst(root->right);
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

int get_child_count(Node *node) {
	int child_count = 0;

	if (node->left != NULL) {
		child_count++;
	}

	if (node->right != NULL) {
		child_count++;
	}

	return child_count;
}

void remove_node_no_childs(Node *node) {
	Node *parent = node->parent;
	
	if (parent->left == node) {
		parent->left = NULL;
	} else {
		parent->right = NULL;
	}

	free(node);
}

void remove_node_one_child(Node *node) {
	Node *child = node->left == NULL ? node->right : node->left;

	Node *parent = node->parent;

	if (parent->left == node) {
		parent->left = child;
	} else {
		parent->right = child;
	}

	free(node);
}

void remove_node_two_childs(Node *node) {
	Node *successor = node->right;

	while (successor->left != NULL) {
		successor = successor->left;
	}

	node->value = successor->value;

	int child_count = get_child_count(successor);

	if (child_count == 0) {
		remove_node_no_childs(successor);
	} else if (child_count == 1) {
		remove_node_one_child(successor);
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

	int child_count = get_child_count(current);

	if (child_count == 0) {
		remove_node_no_childs(current);
	} else if (child_count == 1) {
		remove_node_one_child(current);
	} else {
		remove_node_two_childs(current);
	}
}
