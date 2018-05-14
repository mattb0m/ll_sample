/************************************************************************************
 * A trivial sample program using the simple stack implementation.
 * Compile with the stack code, for ex.:
 *     gcc -O3 -march=native -Wall -Wextra -Wpedantic -o stack_demo stack.c main.c
 ************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main() {
	int *val;
	struct stack s;
	stack_init(&s);
	
	for(long i = 0; i < 10; ++i) {
		val = malloc(sizeof(int));
		*val = i;
		stack_push(&s, val);
		printf("%i\t", *val);
	}
	
	printf("\n");
	
	while((val = stack_pop(&s))) {
		printf("%i\t", *val);
		free(val);
	}
	
	printf("\n");
	return 0;
}