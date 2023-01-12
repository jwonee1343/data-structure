#include <stdio.h>
#include <stdint.h>
#include "queue.h"

typedef QUEUE_STRUCT(int, 10) queue_t; 

int main(int argc, char *argv[])
{
	queue_t q;
	uint32_t i = 0;

	QUEUE_INIT(&q);
	for (i = 0; !QUEUE_FULL(&q); i++) {
		printf("queue_put() -> %d\n", i);
		QUEUE_PUT(&q, i);
	}

	while (!QUEUE_EMPTY(&q)) {
		printf("queue_get() -> %d\n", QUEUE_GET(&q));
	}

	return 0;
}
