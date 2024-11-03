#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stdbool.h>

typedef struct dynamic_array {
	int size;
	int capacity;
	void **array;
} DynamicArray;

DynamicArray *DynamicArray_new();
void DynamicArray_destroy(DynamicArray *array);

bool is_empty(const DynamicArray *array);
void *at(const DynamicArray *array, int index);
void push(DynamicArray *array, void *item);
void insert(DynamicArray *array, int index, void *item);
void prepend(DynamicArray *array, void *item);
void *pop(DynamicArray *array);
void delete_item(DynamicArray *array, int index);
void remove_item(DynamicArray *array, void *item);
int find(const DynamicArray *array, void *item);

#endif // DYNAMIC_ARRAY_H
