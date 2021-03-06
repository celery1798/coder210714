#include "stack.h"

STACK *stack_create(int size)
{
	return llist_create(size);
}

int stack_push(STACK *ptr, const void *data)
{
	return llist_insert(ptr, data, LLIST_FORWARD);
}

static int always_match(const void *key, const void *node)
{
	return 0;
}

int stack_pop(STACK *ptr, void *data)
{
	return llist_fetch(ptr, (void *)0, always_match, data);
}

void stack_destroy(STACK *ptr)
{
	llist_destroy(ptr);
}



