#include "dynamic_array.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

DynamicArray *DynamicArray_new() {
  DynamicArray *array = malloc(sizeof(DynamicArray));
  if (array == NULL) return NULL;

  array->capacity = 16;
  array->array = malloc(array->capacity * sizeof(void *));

  if (array->array == NULL) {
    free(array);
    return NULL;
  }

  return array;
}

void DynamicArray_destroy(DynamicArray *array) {
  free(array->array);
  free(array);
}

bool resize(DynamicArray *array) {
  if (array->size == array->capacity) {
    void *new_array = realloc(array->array, array->capacity * 2 * sizeof(void *));

    if (new_array == NULL) {
      array->array = new_array;
      array->capacity = array->capacity * 2;
      return true;
    }

    DynamicArray_destroy(array);
    return false;
  }

  if (array->size == array->capacity / 4) {
    void *new_array = NULL;
    new_array = realloc(array->array, array->capacity / 2 * sizeof(void *));

    array->capacity = array->capacity / 2;

    if (new_array == NULL) {
      array->array = new_array;
      array->capacity = array->capacity / 2;
      return true;
    }

    DynamicArray_destroy(array);
    return false;
  }

  return true;
}

int size(const DynamicArray *array) { return array->size; }

int capacity(const DynamicArray *array) { return array->capacity; }

bool is_empty(const DynamicArray *array) { return array->size == 0; }

void *at(const DynamicArray *array, const int index) {
  if (is_empty(array) || array->size <= index) return NULL;

  return *(array->array + index);
}

void push(DynamicArray *array, void *item) {
  array->size += 1;
  if (!resize(array)) return;

  *(array->array + array->size - 1) = item;
}

void insert(DynamicArray *array, int index, void *item) {
  if (is_empty(array) || array->size <= index) return;

  array->size += 1;
  if (!resize(array)) return;

  memmove(array->array + index + 1, array->array + index, (array->size - index) * sizeof(void*));

  *(array->array + index) = item;
}

void prepend(DynamicArray *array, void *item) {
  insert(array, 0, item);
}

void delete_item(DynamicArray *array, int index) {
  if (is_empty(array) || array->size <= index) return;

  memmove(array->array + index, array->array + index + 1, (array->size - index) * sizeof(void*));

  array->size -= 1;
  resize(array);
}

void *pop(DynamicArray *array) {
  void *value = *(array->array + array->size - 1);

  delete_item(array, array->size - 1);

  return value;
}

int find(const DynamicArray *array, void *item) {
  for (int i = 0; i < array->size; i++) {
    if (*(array->array + i) == item) return i;
  }

  return -1;
}

void remove_item(DynamicArray *array, void *item) {
  const int index = find(array, item);
  delete_item(array, index);
}
