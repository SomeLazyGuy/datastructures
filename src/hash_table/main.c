#include "hash_table.h"
#include <stdio.h>

int main() {
	HashTable *hashTable = HashTable_new();

	printf("%d\n", exists(hashTable, "Test"));

	add(hashTable, "Test", 10);

	printf("%d\n", exists(hashTable, "Test"));
	printf("%d\n", get(hashTable, "Test"));

	add(hashTable, "Test2", 12);
	add(hashTable, "Test", 13);
	add(hashTable, "Uess", 16);

	printf("%d\n", get(hashTable, "Test2"));
	printf("%d\n", get(hashTable, "Test"));
	printf("%d\n", get(hashTable, "Uess"));
	printf("%d\n", get(hashTable, "Test"));

	remove_key(hashTable, "Test");
	printf("%d\n", exists(hashTable, "Test"));

	HashTable_destroy(hashTable);
}
