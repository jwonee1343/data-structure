// UTF-8 encoding
/**
 * @brief 큐를 쉽게 구현하고 사용하기 위한 매크로들을 정의함
 * @author Jaewon Choi <jwonee1343@gmail.com>
 */
#ifndef __QUEUE_H
#define __QUEUE_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>
#include <stdbool.h>

/**
 * @brief	큐 구조체를 정의하는 매크로
 * @param	type		처리하려는 데이터 타입
 * @param	max_count	할당하려는 데이터 공간의 수
 */
#define QUEUE_STRUCT(type, max_count)	\
	struct {			\
		uint32_t front;		\
		uint32_t rear;		\
		uint32_t count;		\
		type items[max_count];	\
	}

/**
 * @brief	큐를 초기화한다
 * @param	queue		큐 구조체의 포인터
 */
#define QUEUE_INIT(queue)		\
	do {				\
		(queue)->front = 0;	\
		(queue)->rear = 0;	\
		(queue)->count = 0;	\
	} while (0)

/**
 * @brief	큐의 전체 데이터 공간의 수를 구한다
 * @param	queue		큐 구조체의 포인터
 * @return	전체 데이터 공간 수
 */
#define QUEUE_MAX_COUNT(queue) \
	((uint32_t)(sizeof((queue)->items) / sizeof((queue)->items[0])))

/**
 * @brief	큐의 빈 데이터 공간의 수를 구한다
 * @param	queue		큐 구조체의 포인터
 * @return	빈 데이터 공간의 수
 */
#define QUEUE_CAPACITY(queue) \
	((uint32_t)(QUEUE_MAX_COUNT(queue) - (queue)->count))

/**
 * @brief	큐가 비어있는 지 확인한다
 * @param	queue		큐 구조체의 포인터
 * @return	true = 큐가 비어있음, false = 큐가 비어있지 않음
 */
#define QUEUE_EMPTY(queue) ((bool)((queue)->count <= 0))

/**
 * @brief	큐가 꽉 차있는 지 확인한다
 * @param	queue		큐 구조체의 포인터
 * @return	true = 큐가 꽉 참, false = 큐가 꽉 차지 않음
 */
#define QUEUE_FULL(queue) \
	((bool)((queue)->count >= QUEUE_MAX_COUNT(queue)))

/**
 * @brief	큐에 빈 공간이 있으면, 데이터를 삽입합다
 * @param	queue		큐 구조체의 포인터
 */
#define QUEUE_PUT(queue, item)							\
	do {									\
		if (!QUEUE_FULL(queue)) {					\
			(queue)->items[(queue)->rear] = item;			\
			(queue)->rear++;					\
			(queue)->rear %= QUEUE_MAX_COUNT(queue);		\
			(queue)->count++;					\
		}                                                               \
	} while (0)

/**
 * @brief	큐에 데이터가 있으면, 데이터를 삭제하고 반환한다
 * @param	queue		큐 구조체의 포인터
 * @return	가장 먼저 삽입된 데이터
 */
#define QUEUE_GET(queue)								\
	({										\
	 	typeof((queue)->items[0]) item = 0;					\
	 										\
	 	if (!QUEUE_EMPTY(queue)) {						\
	 		item = (queue)->items[(queue)->front];				\
	 		(queue)->front = ((queue)->front + 1) % QUEUE_MAX_COUNT(queue);	\
	 		(queue)->count--;						\
	 	}									\
	 	item;									\
	 })

#ifdef __cplusplus
}
#endif

#endif // __QUEUE_H
