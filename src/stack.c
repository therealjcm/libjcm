/* stack.c - Stack implementation from "C Interfaces and Implementations"
 * by David R. Hanson. Modernized C11 implementation.
 *
 * Original Copyright (c) 1994-1997 David R. Hanson.
 * Modern portions Copyright (c) 2026 Jason Messer.
 * MIT licensed. See top-level LICENSE file.
 */

#include "stack.h"
#include <stdlib.h>
#include <assert.h>

struct Stack_Node {
	void *x;
	struct Stack_Node *link;
}; 

struct Stack_T {
	struct Stack_Node *head;
	size_t size;
};

Stack_T *Stack_new()
{
	Stack_T *stk = malloc(sizeof(*stk));
	assert(stk);
	stk->head = NULL;
	stk->size = 0;
	return stk;
}

bool Stack_empty(const Stack_T *stk)
{
	assert(stk);
	return stk->size == 0;
}

void Stack_push(Stack_T *stk, void *x)
{
	assert(stk);
	struct Stack_Node *p = malloc(sizeof(*p));
	assert(p);
	p->x = x;
	p->link = stk->head;
	stk->head = p;
	stk->size += 1;
}

void *Stack_pop(Stack_T *stk)
{
	assert(stk);
	assert(stk->head);

	struct Stack_Node *p = stk->head;
	void *x = p->x;
	stk->head = p->link;
	free(p);
	stk->size -= 1;
	return x;
}

void Stack_free(Stack_T **stk)
{
	assert(stk && *stk);
	while ((*stk)->head) {
		struct Stack_Node *p = (*stk)->head;
		(*stk)->head = p->link;
		free(p);
	}
	free(*stk);
	*stk = NULL;
}

size_t Stack_size(const Stack_T *stk)
{
	assert(stk);
	return stk->size;
}
