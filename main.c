/******************************************************************************************
 * A trivial sample program using the simple stack implementation.
 * Compile with the stack and queue code, for ex.:
 *     gcc -O3 -march=native -Wall -Wextra -Wpedantic -o stack_demo stack.c queue.c main.c
 ******************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "queue.h"

int main() {
	int *val;
	struct stack s;
	struct queue q;
	
	stack_init(&s);
	queue_init(&q);
	
	printf("INIT:\t");
	
	for(long i = 0; i < 10; ++i) {
		val = malloc(sizeof(int));
		*val = i;
		stack_push(&s, val);
		printf("%i\t", *val);
	}
	
	printf("\nLIFO:\t");
	
	while((val = stack_pop(&s))) {
		printf("%i\t", *val);
		queue_enq(&q, val);
	}
	
	printf("\nFIFO:\t");
	
	while((val = queue_deq(&q))) {
		printf("%i\t", *val);
		free(val);
	}
	
	printf("\n");
	return 0;
}