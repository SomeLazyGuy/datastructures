#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>

typedef struct item {
	struct item *next;
	struct item *prev;
	void *data;
} Item;

typedef struct queue {
	Item *head;
	Item *tail;
} Queue;

Queue *Queue_new();
void Queue_destroy(Queue *queue);
void Queue_destroy(Queue *queue);
void enqueue(Queue *queue, void *value);
void *dequeue(Queue *queue);
bool empty(Queue *queue);

#endif //QUEUE_H
