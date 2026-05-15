/* stack.h - Stack interface from "C Interfaces and Implementations"
 * by David R. Hanson. Modernized C11 implementation.
 *
 * Original Copyright (c) 1994-1997 David R. Hanson.
 * Modern portions Copyright (c) 2026 Jason Messer.
 * MIT licensed. See top-level LICENSE file.
 */

#ifndef STACK_INCLUDED
#define STACK_INCLUDED

#include <stdbool.h>
#include <stddef.h>

typedef struct Stack_T Stack_T;

/* returns a new, empty stack */
extern Stack_T *Stack_new(void);

/* pushes the pointer x onto the stack */
extern void Stack_push(Stack_T *stk, void *x);

/* pop and return top item
 * it is a checked runtime error to pop an empty stack
 */
extern void *Stack_pop(Stack_T *stk);

/* returns true if stack is empty */
extern bool Stack_empty(const Stack_T *stk);

/* return the number of items currently on the stack */
extern size_t Stack_size(const Stack_T *stk);

/* free the stack and set *stk to NULL */
extern void Stack_free(Stack_T **stk);

#endif
