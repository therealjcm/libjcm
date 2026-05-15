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

#define T Stack_T

struct T {
	struct node {
		void *x;
		struct node *link;
	} *head;
	size_t size;
};

T *Stack_new()
{
	T *stk = malloc(sizeof(*stk));
	assert(stk);
	stk->head = NULL;
	stk->size = 0;
	return stk;
}

bool Stack_empty(const T *stk)
{
	assert(stk);
	return stk->size == 0;
}

void Stack_push(T *stk, void *x)
{
	assert(stk);
	struct node *p = malloc(sizeof(*p));
	assert(p);
	p->x = x;
	p->link = stk->head;
	stk->head = p;
	stk->size += 1;
}

void *Stack_pop(T *stk)
{
	assert(stk);
	assert(stk->head);

	struct node *p = stk->head;
	void *x = p->x;
	stk->head = p->link;
	free(p);
	stk->size -= 1;
	return x;
}

void Stack_free(T **stk)
{
	assert(stk && *stk);
	while ((*stk)->head) {
		struct node *p = (*stk)->head;
		(*stk)->head = p->link;
		free(p);
	}
	free(*stk);
	*stk = NULL;
}

size_t Stack_size(const T *stk)
{
	assert(stk);
	return stk->size;
}
