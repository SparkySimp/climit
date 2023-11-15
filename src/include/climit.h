/*
 * climit.h - real analysis functions (limit, derivative and integration) for c
 * copyright (c) 2023 Kıvılcım Selda Luna Öztürk, see LICENSE at project root for more
 * information.
 */

#ifndef climit_h /* BEGIN <climit.h> */
#define climit_h
#include <float.h>
#include <math.h>

/* real number */
typedef double climit_real_t;
/* any function defined in real numbers (f: r -> r) */
typedef climit_real_t (* climit_realfunc_t)(climit_real_t);

/* approach direction for limits */
typedef enum _CLIMIT_APPROACH_DIRECTION {
	CLIMIT_APPROACH_BOTH,
	CLIMIT_APPROACH_LEFT,
	CLIMIT_APPROACH_RIGHT
} climit_approach_direction_t;

/* limit of a function */
extern climit_real_t climit_limit(climit_realfunc_t func, climit_real_t c, 
		climit_approach_direction_t approach_direction);
/* derivative of a function */
extern climit_realfunc_t climit_derivative(climit_realfunc_t func);

/* indefinite integral of a function */
extern climit_realfunc_t climit_integrate(climit_realfunc_t func);

/* definite integral of a function */
extern climit_real_t climit_defintegrate(climit_realfunc_t func);

/* a simple, internal function for derivatives */
climit_real_t __climit_internal_derivative(climit_realfunc_t f, climit_real_t x, climit_real_t h) {
	return (f(x + h) - f(x)) / h;
}
#endif           /* END   <climit.h> */
