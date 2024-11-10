#include "hash_table.h"
#include <stdio.h>

int main() {
	HashTable *hashTable = HashTable_new();

	HashTable_destroy(hashTable);
}
