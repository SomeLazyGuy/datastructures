#include "stack.h"
#include <stdlib.h>

void Stack_destroy(Stack *stack) {
	free(stack->data);
	free(stack);
}

Stack *Stack_new(int capacity) {
	Stack *new_stack = malloc(sizeof(Stack));

	if (new_stack == NULL) {
		free(new_stack);
		return NULL;
	}

	new_stack->data = malloc(capacity * sizeof(void*));
	if (new_stack->data == NULL) {
		Stack_destroy(new_stack);
		return NULL;
	}

	new_stack->capacity = capacity;
	new_stack->size = 0;

	return new_stack;
}

void push(Stack *stack, void *item) {
	if (stack->size >= stack->capacity) return;

	*(stack->data + stack->size) = item;
	stack->size += 1;
}

void *top(const Stack *stack) {
	return *(stack->data + stack->size);
}

void *pop(Stack *stack) {
	if (is_empty(stack)) return NULL;

	stack->size -= 1;
	void* item = *(stack->data + stack->size);

	return item;
}

bool is_empty(Stack* stack) {
	return stack->size == 0;
}
