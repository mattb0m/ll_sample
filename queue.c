#include <stdlib.h>
#include "queue.h"

void queue_init(struct queue *q) {
	q->head = 0;
	q->tail = 0;
	q->size = 0;
}

int queue_enq(struct queue *q, void* val) {
	struct ll_node *n = malloc(sizeof(struct ll_node));
	if(!n) return 0;
	
	n->val = val;
	n->next = 0;
	if(q->tail)
		q->tail->next = n;
	q->tail = n;
	if(!q->head)
		q->head = n;
	++q->size;
	return 1;
}

void* queue_deq(struct queue *q) {
	void *val;
	struct ll_node *old;
	
	if(!q->head) return 0;
	
	val = q->head->val;
	old = q->head;
	q->head = q->head->next;
	free(old);
	if(!q->head)
		q->tail = 0;
	--q->size;
	return val;
}

void* queue_peek(struct queue *q) {
	return q->head ? q->head->val : 0;
}

void* queue_peekback(struct queue *q) {
	return q->tail ? q->tail->val : 0;
}

void queue_free(struct queue *q) {
	while(queue_deq(q));
	q->size = 0;
}