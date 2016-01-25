#ifndef _Q15_MATH
#define _Q15_MATH

#include <stdint.h>

typedef int16_t q15_t
typedef uint16_t theta

double q15_to_dbl(q15_t num);
float q15_to_float(q15_t num);
int16_t q15_to_int(q15_t num);
q15_t q15_from_dbl(double num);
q15_t q15_from_float(float num);
q15_t q15_from_int(int num);

/* TODO:

q15_t q15_from_float(float num);
q15_t q15_from_int(int num);

q15_t q15_acos(q15_t num);
q15_t q15_asin(q15_t num);
q15_t q15_atan(q15_t num);
q15_t q15_atan2(q15_t num);
q15_t q15_cos(q15_t num);
q15_t q15_exp(q15_t num);
q15_t q15_sin(q15_t num);
q15_t q15_sqrt(q15_t num);
q15_t q15_tan(q15_t num);
q15_t q15_mul(q15_t multiplicand, q15_t multiplier);
q15_t q15_div(q15_t dividend, q15_t divisor);
q15_t q15_add(q15_t addend, q15_t adder);
*/

#endif