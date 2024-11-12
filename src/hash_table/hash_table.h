#ifndef HASH_TABLE
#define HASH_TABLE

#include <stdbool.h>

typedef struct entry {
	char *key;
	int value;
	struct entry *next;
} Entry;

typedef struct hash_table {
	Entry **data;
	int m;
	int n;
} HashTable;

HashTable *HashTable_new();
void HashTable_destroy(HashTable *hashTable);
void add(HashTable *hashTable, char *key, int value);
bool exists(HashTable *hashTable, char *key);
int get(HashTable *hashTable, char *key);
void remove_key(HashTable *hashTable, char *key);
int hash(char *key, int m);

#endif // HASH_TABLE
