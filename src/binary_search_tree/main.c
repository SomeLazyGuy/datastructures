#include "binary_search_tree.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	Node *bst = Node_new(NULL, 20);

	insert_value(bst, 17);
	insert_value(bst, 13);
	insert_value(bst, 10);
	insert_value(bst, 14);
	insert_value(bst, 18);
	insert_value(bst, 25);
	insert_value(bst, 22);
	insert_value(bst, 33);
	insert_value(bst, 30);
	insert_value(bst, 45);

	print_tree(bst, 0);

	destroy_tree(bst);
}
