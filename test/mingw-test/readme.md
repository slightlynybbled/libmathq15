# Testing #

I am utilizing ceedling with unity for testing basic correctness of the code.  I have included all tests and test configuration under '/test/mingw-test/'.
 
I have setup the project.yml file so that the paths are relative.  To use this test file, you will have to have ruby installed and added to your environment variables/paths.  You will also need some form of gcc and to have the environment variable/paths set up for that as well.
 
It would be great to have the correctness test cases automated on the target simulator or target processor, and I may get to this at some point in the future.  If you are so inclined, the source it here!
 
## Test Case Status ##

I have added - and completed test cases for the following functions:
 * double q15_to_dbl(q15_t num);
 * float q15_to_float(q15_t num);
 * int16_t q15_to_int(q15_t num);
 * q15_t q15_from_dbl(double num);
 * q15_t q15_from_float(float num);
 * q15_t q15_from_int(int num);
 
 * q15_t q15_mul(q15_t multiplicand, q15_t multiplier);
 * q15_t q15_div(q15_t dividend, q15_t divisor);
 * q15_t q15_add(q15_t addend, q15_t adder);
 * q15_t q15_abs(q15_t num);
 * q15_t q15_sqrt(q15_t num);
 
 * q15_t q15_sin(q16angle_t theta);
 * q15_t q15_fast_sin(q16angle_t theta);
 * q15_t q15_cos(q16angle_t theta);
 * q15_t q15_fast_cos(q16angle_t theta);
 
Functions that still require testing:
 * q15_t q15_tan(q16angle_t theta);
 * q15_t q15_fast_tan(q16angle_t theta);
 
I still need to add test cases for the trigonometric functions.