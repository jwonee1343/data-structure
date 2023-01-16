#include <stdio.h>
#include <stdint.h>
#include "queue.h"
#include "stack.h"

typedef QUEUE_STRUCT(int, 10) queue_t; 
typedef STACK_STRUCT(int, 10) stack_t;

int main(int argc, char *argv[])
{
	queue_t q;
	stack_t s;
	uint32_t i = 0;

	QUEUE_INIT(&q);
	for (i = 0; !QUEUE_FULL(&q); i++) {
		printf("queue_put() -> %d\n", i);
		QUEUE_PUT(&q, i);
	}

	while (!QUEUE_EMPTY(&q)) {
		printf("queue_get() -> %d\n", QUEUE_GET(&q));
	}

	STACK_INIT(&s);
	for (i = 0; !STACK_FULL(&s); i++) {
		printf("stack_push() -> %d\n", i);
		STACK_PUSH(&s, i);
	}

	while (!STACK_EMPTY(&s)) {
		printf("stack_pop() -> %d\n", STACK_POP(&s));
	}

	return 0;
}
