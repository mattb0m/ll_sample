#ifndef STACK_H
#define STACK_H

struct ll_node;

struct stack {
	struct ll_node *head;
	size_t size;
};

void stack_init(struct stack *s);
int stack_push(struct stack *s, void* val);
void* stack_pop(struct stack *s);
void* stack_peek(struct stack *s);
void stack_free(struct stack *s);

#endif