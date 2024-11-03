#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

// for a real implementation a dynamic array would probably be a better choice
typedef struct stack {
	void **data;
	int capacity;
	int size;
} Stack;

Stack* Stack_new(int capacity);
void Stack_destroy(Stack *stack);
void push(Stack *stack, void *item);
void *top(const Stack *stack);
void *pop(Stack *stack);
bool is_empty(Stack *stack);

#endif // STACK_H
