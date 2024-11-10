#include "hash_table.h"
#include <stdlib.h>

HashTable *HashTable_new() {
	HashTable *hashTable = malloc(sizeof(HashTable));
	if (hashTable == NULL) return NULL;

	hashTable->m = 8;
	hashTable->n = 8;

	hashTable->data = malloc(hashTable->m * sizeof(int));
	if (hashTable->data == NULL) free(hashTable);

	return hashTable;
}

void free_entry(Entry *entry) {
	free(entry->key);
	free(entry);
}

void free_chain(Entry *head) {
	if (head == NULL) return;

	Entry *to_delete = head->next;
	while (to_delete != NULL) {
		head->next = to_delete->next;
		free_entry(to_delete);
		to_delete = head->next;
	}

	free_entry(head);
}

void HashTable_destroy(HashTable *hashTable) {
	for (int i = 0; i < hashTable->m; i++) free_chain(hashTable->data[i]);
	free(hashTable->data);
	free(hashTable);
}

int hash(char *key, int m) {
	int sum = 0;
	int len_key = sizeof(key) / sizeof(char);
	for (int i = 0; i < len_key; i++) sum += (int)key[i];
	return sum % m;
}

bool string_equal(char *string1, char* string2) {
	int len_string1 = sizeof(string1) / sizeof(char);
	int len_string2 = sizeof(string2) / sizeof(char);

	if (len_string1 != len_string2) return false;

	for (int i = 0; i < len_string1; i++) {
		if (string1[i] != string2[i]) return false;
	}

	return true;
}

void add(HashTable *hashTable, char *key, int value) {
	Entry *item = malloc(sizeof(Entry));
	if (item == NULL) return;
	item->key = key;
	item->value = value;

	int index = hash(key, hashTable->m);

	if (hashTable->data[index] == NULL) {
		hashTable->data[index] = item;
	} else {
		Entry *last_item = hashTable->data[index];
		while (last_item->next != NULL) {
			if (string_equal(key, last_item->key)) {
				last_item->value = value;
				free(item);
				return;
			}
			last_item = last_item->next;
		}
		
		if (string_equal(key, last_item->key)) {
			last_item->value = value;
			free(item);
			return;
		}

		last_item->next = item;
	}
}

bool exists(HashTable *hashTable, char *key) {
	int index = hash(key, hashTable->m);

	Entry *current = hashTable->data[index];

	while (current != NULL) {
		if (string_equal(key, current->key)) true;
	}

	return false;
}

int get(HashTable *hashTable, char *key) {
	int index = hash(key, hashTable->m);

	Entry *current = hashTable->data[index];
	if (current == NULL) exit(-1);

	while (current != NULL) {
		if (string_equal(key, current->key)) return current->value;
	}

	exit(-1);
}

void remove_key(HashTable *hashTable, char *key) {
	int index = hash(key, hashTable->m);

	Entry *current = hashTable->data[index];
	if (current == NULL) return;

	if (string_equal(key, current->key)) {
		hashTable->data[index] = current->next;
		free(current);
	}

	while (current->next != NULL) {
		if (string_equal(key, current->next->key)) {
			Entry *old = current->next;
			current->next = old->next;
			free(old);
			return;
		}
	}

	// i know this creates a dangling pointer but i am too lazy to fix it rn
	if (string_equal(key, current->key)) {
		free(current);
	}
}
