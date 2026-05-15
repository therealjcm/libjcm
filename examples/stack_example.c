#include "stack.h"
#include <stdio.h>

int main(void)
{
	Stack_T *stk = Stack_new();

	int a = 10, b = 20, c = 30;
	float fa = 3.14, fb = 2.5, fc = 0.92;

	Stack_push(stk, &a);
	Stack_push(stk, &b);
	printf("stack size: %zu\n", Stack_size(stk));
	printf("pop got %d\n", *(int *)Stack_pop(stk));
	printf("stack size: %zu\n", Stack_size(stk));

	Stack_push(stk, &fa);
	Stack_push(stk, &c);
	Stack_push(stk, &fb);
	Stack_push(stk, &fc);
	printf("stack size: %zu\n", Stack_size(stk));

	printf("pop got %f\n", *(float *)Stack_pop(stk));
	printf("pop got %f\n", *(float *)Stack_pop(stk));
	printf("pop got %d\n", *(int *)Stack_pop(stk));
	printf("pop got %f\n", *(float *)Stack_pop(stk));
	printf("stack size: %zu\n", Stack_size(stk));

	Stack_free(&stk);

	return 0;
}
