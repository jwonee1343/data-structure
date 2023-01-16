// UTF-8 encoding
/**
 * @brief	스택를 쉽게 구현하고 사용하기 위한 매크로들을 정의함
 * @author	Jaewon Choi <jwonee1343@gmail.com>
 */
#ifndef __STACK_H
#define __STACK_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>
#include <stdbool.h>

/**
 * @brief	스택 구조체를 정의하는 매크로
 * @param	type		처리하려는 데이터 타입
 * @param	max_count	할당하려는 데이터 공간의 수
 */
#define STACK_STRUCT(type, max_count)	\
	struct {			\
		uint32_t top;		\
		type items[max_count];	\
	}

/**
 * @brief	스택을 초기화한다
 * @param	stack		스택 구조체의 포인터
 */
#define STACK_INIT(stack)		\
	do {				\
		(stack)->top = 0;	\
	} while (0)

/**
 * @brief	스택의 전체 데이터 공간의 수를 구한다
 * @param	stack		스택 구조체의 포인터
 * @return	전체 데이터 공간 수
 */
#define STACK_MAX_COUNT(stack) \
	((uint32_t)(sizeof((stack)->items) / sizeof((stack)->items[0])))

/**
 * @brief	스택의 빈 데이터 공간의 수를 구한다
 * @param	stack		스택 구조체의 포인터
 * @return	빈 데이터 공간의 수
 */
#define STACK_CAPACITY(stack) \
	((uint32_t)(STACK_MAX_COUNT(stack) - (stack)->top))

/**
 * @brief	스택가 비어있는 지 확인한다
 * @param	stack		스택 구조체의 포인터
 * @return	true = 스택이 비어있음, false = 큐이 비어있지 않음
 */
#define STACK_EMPTY(stack) ((bool)((stack)->top <= 0))

/**
 * @brief	스택이 꽉 차있는 지 확인한다
 * @param	stack		스택 구조체의 포인터
 * @return	true = 스택이 꽉 참, false = 스택이 꽉 차지 않음
 */
#define STACK_FULL(stack) \
	((bool)((stack)->top >= STACK_MAX_COUNT(stack)))

/**
 * @brief	스택에 빈 공간이 있으면, 데이터를 삽입합다
 * @param	stack		스택 구조체의 포인터
 */
#define STACK_PUSH(stack, item)							\
	do {									\
		if (!STACK_FULL(stack)) {					\
			(stack)->items[(stack)->top++] = item;			\
		}                                                               \
	} while (0)

/**
 * @brief	스택에 데이터가 있으면, 데이터를 삭제하고 반환한다
 * @param	stack		스택 구조체의 포인터
 * @return	가장 마지막에 삽입된 데이터
 */
#define STACK_POP(stack) \
	(STACK_EMPTY(stack) ? (typeof((stack)->items[0]))0 : (stack)->items[--(stack)->top])

#ifdef __cplusplus
}
#endif

#endif // __STACK_H
