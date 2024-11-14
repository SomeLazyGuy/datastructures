#include "hash_table.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

HashTable *HashTable_new() {
	HashTable *hashTable = malloc(sizeof(HashTable));
	if (hashTable == NULL) return NULL;

	hashTable->m = 8;
	hashTable->n = 0;

	hashTable->data = malloc(hashTable->m * sizeof(Entry*));
	if (hashTable->data == NULL) {
		free(hashTable);
		return NULL;
	}
	for (int i = 0; i < hashTable->m; i++) hashTable->data[i] = NULL;

	return hashTable;
}

void free_chain(Entry *head) {
	if (head == NULL) return;

	Entry *current = head;
	Entry *next = NULL;

	while (current != NULL) {
		next = current->next;
		free(current);
		current = next;
	}
}

void HashTable_destroy(HashTable *hashTable) {
	for (int i = 0; i < hashTable->m; i++) free_chain(hashTable->data[i]);
	free(hashTable->data);
	free(hashTable);
}

int hash(char *key, int m) {
	int sum = 0;
	for (int i = 0; i < strlen(key); i++) sum += (int)key[i];

	return sum % m;
}

void rehash_all(HashTable *hashTable, int new_size) {
	Entry **old_data = hashTable->data;
	int old_size = hashTable->m;

	hashTable->m = new_size;
	hashTable->data = malloc(hashTable->m * sizeof(Entry*));
	for (int i = 0; i < hashTable->m; i++) hashTable->data[i] = NULL;

	hashTable->n = 0;
	
	for (int i = 0; i < old_size; i++) {
		Entry* current = old_data[i];
		Entry* next = NULL;

		while (current != NULL) {
			next = current->next;
			add(hashTable, current->key, current->value);
			free(current);
			current = next;
		}
	}

	free(old_data);
}

void add(HashTable *hashTable, char *key, int value) {
	Entry *item = malloc(sizeof(Entry));
	if (item == NULL) return;
	item->key = key;
	item->value = value;

	int index = hash(key, hashTable->m);

	if (hashTable->data[index] == NULL) {
		hashTable->data[index] = item;
		hashTable->n++;
		if (hashTable->n > hashTable->m / 2) rehash_all(hashTable, hashTable->m * 2);
	} else {
		Entry *last_item = hashTable->data[index];
		while (last_item->next != NULL) {
			if (strcmp(key, last_item->key) == 0) {
				last_item->value = value;
				free(item);
				return;
			}
			last_item = last_item->next;
		}
		
		if (strcmp(key, last_item->key) == 0) {
			last_item->value = value;
			free(item);
			return;
		}

		last_item->next = item;
		hashTable->n++;
		if (hashTable->n > hashTable->m / 2) rehash_all(hashTable, hashTable->m * 2);
	}
}

bool exists(HashTable *hashTable, char *key) {
	int index = hash(key, hashTable->m);

	Entry *current = hashTable->data[index];
	while (current != NULL) {
		if (strcmp(key, current->key) == 0) return true;
		current = current->next;
	}

	return false;
}

int get(HashTable *hashTable, char *key) {
	int index = hash(key, hashTable->m);

	Entry *current = hashTable->data[index];
	while (current != NULL) {
		if (strcmp(key, current->key) == 0) return current->value;
		current = current->next;
	}

	exit(-1);
}

void remove_key(HashTable *hashTable, char *key) {
	int index = hash(key, hashTable->m);

	Entry *current = hashTable->data[index];
	Entry *prev = NULL;

	while (current != NULL) {
		if (strcmp(key, current->key) == 0) {
			if (prev == NULL) hashTable->data[index] = current->next;
			else prev->next = current->next;

			free(current);

			hashTable->n--;
			if (hashTable->n <= hashTable->m / 4) rehash_all(hashTable, hashTable->m / 2);

			return;
		}

		prev = current;
		current = current->next;
	}
}
