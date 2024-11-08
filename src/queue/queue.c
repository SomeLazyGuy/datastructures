#include "queue.h"
#include <stdlib.h>

Queue *Queue_new() {
	Queue *new_queue = malloc(sizeof(Queue));
	if (new_queue == NULL) return NULL;

	new_queue->head = malloc(sizeof(Item));
	if (new_queue->head == NULL) {
		free(new_queue);
		return NULL;
	}

	new_queue->tail = malloc(sizeof(Item));
	if (new_queue->tail == NULL) {
		free(new_queue->head);
		free(new_queue);
		return NULL;
	}

	new_queue->head->next = new_queue->tail;
	new_queue->tail->prev = new_queue->head;

	return new_queue;
}

void Queue_destroy(Queue *queue) {
	Item *item = queue->head;
	while (item != NULL) {
		Item *current = item;
		item = current->next;
		free(current);
	}

	free(queue);
}

void enqueue(Queue *queue, void *value) {
	Item *item = malloc(sizeof(Item));
	if (item == NULL) return;

	item->data = value;
	item->next = queue->tail;
	item->prev = queue->tail->prev;
	item->prev->next = item;

	queue->tail->prev = item;
}

void *dequeue(Queue *queue) {
	if (empty(queue)) return NULL;

	void *key = queue->head->next->data;

	Item *new_head = queue->head->next->next;
	new_head->prev = queue->head;
	free(queue->head->next);
	queue->head->next = new_head;

	return key;
}

bool empty(Queue *queue) {
	return queue->head->next == queue->tail;
}
