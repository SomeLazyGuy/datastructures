#include "hash_table.h"
#include <stdio.h>

int main() {
	HashTable *hashTable = HashTable_new();

	add(hashTable, "Test1", 11);
	add(hashTable, "Test2", 12);
	add(hashTable, "Test3", 13);
	add(hashTable, "Test4", 14);
	add(hashTable, "Test5", 15);

	printf("m: %d, n: %d\n", hashTable->m, hashTable->n);

	for (int i = 0; i < hashTable->m; i++) {
		Entry *current = hashTable->data[i];
		if (current == NULL) {
			printf("NULL");
		}

		while (current != NULL) {
			printf("%s\t", current->key);
			current = current->next;
		}

		printf("\n");
	}

	remove_key(hashTable, "Test1");

	printf("\n\nm: %d, n: %d\n", hashTable->m, hashTable->n);

	for (int i = 0; i < hashTable->m; i++) {
		Entry *current = hashTable->data[i];
		if (current == NULL) {
			printf("NULL");
		}

		while (current != NULL) {
			printf("%s\t", current->key);
			current = current->next;
		}

		printf("\n");
	}

	HashTable_destroy(hashTable);
}
