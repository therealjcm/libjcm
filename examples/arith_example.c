#include "arith.h"
#include <stdio.h>

int main(void)
{
	printf("Arith examples (floor division toward negative infinity)\n");

	printf("Arith_div(-13, 5) = %d\n", Arith_div(-13, 5));
	printf("Arith_mod(-13, 5) = %d\n", Arith_mod(-13, 5));

	printf("Arith_div(13, -5) = %d\n", Arith_div(13, -5));
	printf("Arith_mod(13, -5) = %d\n", Arith_mod(13, -5));

	printf("Arith_div(13, 5) = %d\n", Arith_div(13, 5));
	printf("Arith_mod(13, 5) = %d\n", Arith_mod(13, 5));

	return 0;
}
