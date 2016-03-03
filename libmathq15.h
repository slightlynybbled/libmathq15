#ifndef _Q15_MATH
#define _Q15_MATH

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>

/* define the desired trigonometric resolution (higher bit values create larger tables)
 * note that, if all are undefined, the default will be the 8-bit table */
#undef SINE_TABLE_4BIT
#undef SINE_TABLE_5BIT
#undef SINE_TABLE_6BIT
#undef SINE_TABLE_7BIT
#undef SINE_TABLE_8BIT

typedef int16_t q15_t;
typedef uint16_t q16angle_t;

double q15_to_dbl(q15_t num);
float q15_to_float(q15_t num);
int16_t q15_to_int(q15_t num);
q15_t q15_from_dbl(double num);
q15_t q15_from_float(float num);
q15_t q15_from_int(int num);

q15_t q15_mul(q15_t multiplicand, q15_t multiplier);
q15_t q15_div(q15_t dividend, q15_t divisor);
q15_t q15_add(q15_t addend, q15_t adder);
q15_t q15_abs(q15_t num);
q15_t q15_sqrt(q15_t num);

q15_t q15_sin(q16angle_t theta);
q15_t q15_fast_sin(q16angle_t theta);
q15_t q15_cos(q16angle_t theta);
q15_t q15_fast_cos(q16angle_t theta);
q15_t q15_tan(q16angle_t theta);
q15_t q15_fast_tan(q16angle_t theta);


/* TODO:
q16angle_t q15_acos(q15_t num);
q16angle_t q15_asin(q15_t num);
q16angle_t q15_atan(q15_t num);
q16angle_t q15_atan2(q15_t num);
q15_t q15_exp(q16angle_t theta);
... more? ...
*/

#ifdef __cplusplus
}
#endif

#endif

