#ifndef QUEUE_H
#define QUEUE_H

#include "ll.h"

struct queue {
	struct ll_node *head, *tail;
	size_t size;
};

void queue_init(struct queue *s);
int queue_enq(struct queue *s, void* val);
void* queue_deq(struct queue *s);
void* queue_peek(struct queue *s);
void* queue_peekback(struct queue *s);
void queue_free(struct queue *s);

#endif