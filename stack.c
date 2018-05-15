/*************************************************************************************
 * Stack ADT learning sample. Simple linked-list-based stack.
 *
 * NOTE: This implementation should be performant enough for most uses,
 *    but can be improved, in locality of reference and allocation time,
 *    by allocating list nodes from an object pool
 *************************************************************************************/
#include <stdlib.h>
#include "stack.h"

void stack_init(struct stack *s) {
	s->head = 0;
	s->size = 0;
}

int stack_push(struct stack *s, void* val) {
	struct ll_node *n = malloc(sizeof(struct ll_node));
	if(!n) return 0;
	
	n->val = val;
	n->next = s->head;
	s->head = n;
	++s->size;
	return 1;
}

void* stack_pop(struct stack *s) {
	void *val;
	struct ll_node *old;
	
	if(!s->head) return 0;
	
	val = s->head->val;
	old = s->head;
	s->head = s->head->next;
	free(old);
	--s->size;
	return val;
}

void* stack_peek(struct stack *s) {
	return s->head ? s->head->val : 0;
}

void stack_free(struct stack *s) {
	while(stack_pop(s));
	s->size = 0;
}