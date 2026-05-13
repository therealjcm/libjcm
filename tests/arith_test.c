#include "arith.h"
#include <assert.h>

int main(void)
{
	assert(Arith_max(5, 3) == 5);
	assert(Arith_max(-10, -20) == -10);
	assert(Arith_min(5, 3) == 3);
	assert(Arith_min(-10, -20) == -20);

	assert(Arith_div(-13, 5) == -3);
	assert(Arith_mod(-13, 5) == 2);

	assert(Arith_div(13, -5) == -3);
	assert(Arith_mod(13, -5) == -2);

	assert(Arith_div(-13, -5) == 2);
	assert(Arith_mod(-13, -5) == -3);

	assert(Arith_div(13, 5) == 2);
	assert(Arith_mod(13, 5) == 3);

	assert(Arith_div(0, 5) == 0);
	assert(Arith_mod(0, 5) == 0);

	return 0;
}
