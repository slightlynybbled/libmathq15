# Q1.15 Library for 8- and 16-bit Embedded Applications #

There are a number of math libraries that support Q16.16 and some other fixed-point notations, but I have noted a distinct lack of open-source libraries for Q1.15.  In most applications, Q1.15 math will work well enough to get the job done and there should be an easy-to-use, open source, and optimized library for it.

# Contributions #

 * optimizations - provide optimizations for your favorite embedded platform
 * testing - some testing has been completed for correctness, but not all
 * expansion - adding functionality to the library
 * documentation - there are some comments within the source code, but not much
 
# Testing #

 I am utilizing ceedling with unity for test testing.  I have included all tests and test configuration under '/test/mingw-test/'.
 
 I have setup the project.yml file so that the paths are relative.  To use this test file, you will have to have ruby installed and added to your environment variables/paths.  You will also need some form of gcc and to have the environment variable/paths set up for that as well.
 
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
 
Functions that still require testing:
 * q15_t q15_sin(q16angle_t theta);
 * q15_t q15_fast_sin(q16angle_t theta);
 * q15_t q15_cos(q16angle_t theta);
 * q15_t q15_fast_cos(q16angle_t theta);
 * q15_t q15_tan(q16angle_t theta);
 * q15_t q15_fast_tan(q16angle_t theta);
 
I still need to add test cases for the trigonometric functions.

# Performance #
None of the functions have been tested - nor optimized! - for performance on any platform.  Currently, testing is focused on correctness.  Before optimization on your platform, these libraries will likely not perform much better than normal integer operations on your toolchain and processor.
 
# Future #
 
 I have personally utilized many similar routines in the past, so I plan to continue contributing in the above ways myself.  I just know that I won't be able to do everything right now, so I'm publishing the 'beginning' to the community to help out if they wish.
 
