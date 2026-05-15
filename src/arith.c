/* arith.c - Arith implementation from "C Interfaces and Implementations"
 * by David R. Hanson. Modernized C11 implementation.
 *
 * Original Copyright (c) 1994-1997 David R. Hanson.
 * Modern portions Copyright (c) 2026 Jason Messer.
 * MIT licensed. See top-level LICENSE file.
 */

#include "arith.h"
#include <assert.h>

_Static_assert(sizeof(int) >= 4, "Arith assumes at least 32-bit int");  // Optional

int Arith_max(int x, int y) {
	return x > y ? x : y;
}

int Arith_min(int x, int y) {
	return x > y ? y : x;
}

int Arith_div(int x, int y) {
	assert(y != 0);

	int q = x / y;          // C99+ toward-zero
	int r = x % y;
    
	// Adjust toward negative infinity when signs differ and there's a remainder
	if ((x ^ y) < 0 && r != 0) {
		q -= 1;
	}
	return q;
}

int Arith_mod(int x, int y) {
	assert(y != 0);

	int r = x % y;
	if ((x ^ y) < 0 && r != 0) {
		r += y;             // Make remainder positive (or sign of y)
	}
	return r;
}

int Arith_floor(int x, int y) {
	return Arith_div(x, y);
}

int Arith_ceiling(int x, int y) {
	return Arith_div(x, y) + (x % y != 0 ? 1 : 0);  // More explicit
}
