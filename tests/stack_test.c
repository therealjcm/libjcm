#include "stack.h"
#include <assert.h>

int main(void)
{
	Stack_T *stk = Stack_new();
	assert(Stack_empty(stk));

	int a = 10, b = 20, c = 30;
	int aa = 314, bb = 25, cc = 92;

	Stack_push(stk, &a);
	assert(!Stack_empty(stk));
	Stack_push(stk, &b);
	assert(Stack_size(stk) == 2);

	assert(*(int *)Stack_pop(stk) == 20);
	assert(Stack_size(stk) == 1);

	Stack_push(stk, &aa);
	Stack_push(stk, &c);
	Stack_push(stk, &bb);
	Stack_push(stk, &cc);
	assert(Stack_size(stk) == 5);

	assert(*(int *)Stack_pop(stk) == 92);
	assert(*(int *)Stack_pop(stk) == 25);
	assert(*(int *)Stack_pop(stk) == 30);
	assert(*(int *)Stack_pop(stk) == 314);
	assert(*(int *)Stack_pop(stk) == 10);
	assert(Stack_empty(stk));

	Stack_free(&stk);
	assert(stk == NULL);

	return 0;
}
