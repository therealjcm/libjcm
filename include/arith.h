/* arith.h - Arith interface from "C Interfaces and Implementations"
 * by David R. Hanson. Modernized C11 implementation.
 *
 * Original Copyright (c) 1994-1997 David R. Hanson.
 * Modern portions Copyright (c) 2026 Jason Messer.
 * MIT licensed. See top-level LICENSE file.
 */

#ifndef ARITH_INCLUDED
#define ARITH_INCLUDED

extern int Arith_max(int x, int y);
extern int Arith_min(int x, int y);

/*
 * Arith_div and Arith_mod implement "floor" division/modulo
 * toward negative infinity, unlike C99+ toward zero
 * This makes behavior consistent across signs
 */

extern int Arith_div(int x, int y);
extern int Arith_mod(int x, int y);

extern int Arith_ceiling(int x, int y);
extern int Arith_floor(int x, int y);

#endif /* ARITH_INCLUDED */
