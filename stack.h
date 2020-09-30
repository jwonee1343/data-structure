#ifndef _STACK_H
#define _STACK_H

#define STACK(type, count)						\
	struct {							\
		type *top;						\
		type items[count];					\
	}

#define DEFAULT_STACK(name)						\
		name = (typeof(name)){ .top = (name).items, .items = { 0, } }

#define STACK_SIZE(stack)						\
	(sizeof (stack).items / sizeof *(stack).items)

#define STACK_COUNT(stack)						\
	((stack).top - (stack).items)

#define STACK_EMPTY(stack)						\
	((stack).top == (stack).items)

#define STACK_FULL(stack)						\
	((stack).top == (stack).items + STACK_SIZE(stack))

#define STACK_PUSH(stack, item)						\
	(*(stack).top++ = (item))

#define STACK_POP(stack)						\
	((stack).items[*--(stack).top])

#endif /* _STACK_H */

