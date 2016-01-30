# Q1.15 Library for 8- and 16-bit Embedded Applications #

There are a number of math libraries that support Q16.16 and some other fixed-point notations, but I have noted a distinct lack of open-source libraries for Q1.15.  In most applications, Q1.15 math will work well enough to get the job done and there should be an easy-to-use, open source, and optimized library for it.

# Contributions #

 * optimizations - provide optimizations for your favorite embedded platform
 * testing - some testing has been completed for correctness, but not all
 * expansion - adding functionality to the library
 * documentation - there are some comments within the source code, but not much
 
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

# Performance #

## Look at the readme within each metric (speed/accuracy/test) for performance metrics.  If you don't see a metric, feel free to run it and send your results!

## Memory Footprint ##

There can be significant memory overhead in some functions - especially trigonometric functions.  Memory overhead can also differ greatly between implementations.  This should be quantified, particularly for devices which have limited memory.

# Future #
 
I would like to see assembly-optimized code for the major functions (multiplication/division/addition) on:

 * Microchip 16-bit devices (PIC24 and dsPIC33)
 * Microchip 8-bit devices (PIC18 and PIC16)
 * TI MSP430 devices
 * STM32 Devices
 * AVR/Arduino 8-bit Devices
 
I have programmed all of these devices to some degree, but I have only written assembly on a couple of them, so some help is needed!

# Library Details #

## Defines ##

The user may customize the header to suit the application for some operations.  For instance, a look-up table is utilized for trigonometric functions.  Simply 'define' the appropriate SINE_TABLE_xBIT based on the amount of program memory that you can dedicate to the task.

## Macros ##

There are currently no macros implemented, but I suspect that a conversion from float-to-q15 will be implemented in the future.

## Type Definitions ##

There are two type definitions that the user must be aware of:

 * q15_t
 * q16angle_t

The 'q15_t' type is a 16-bit, signed number that represents decimal values ranging from -1.0 to +0.9997.  Actual values are -32768 to +32767.  The C compiler will allow the user to simply add two q15_t numbers together, but it is always recommended to use the q15_add() function to keep the number from rolling over.

The 'q16angle_t' type is a 16-bit, unsigned number that represents an angle between 0 degrees and 359.99 degrees (0 radians to 6.283 radians).  Angles can be added or subtracted at will and do not saturate.  For instance, 359 degrees + 1 result in 0 degrees and 655535 + 1 results in 0.  The rollover model is the same.

## Conversion Functions ##

 * double q15_to_dbl(q15_t num) - This function will take a q15 number and convert it to a double between -1.0 and +0.9997.  Note that some embedded target compilers implement 'double' as 'float'.
 * float q15_to_float(q15_t num) - This function will take a q15 number and convert it to a float between -1.0 and +0.9997
 * int16_t q15_to_int(q15_t num) - This function will take a q15 number and convert it to an integer between -1 and 1
 * q15_t q15_from_dbl(double num) - This function will take a double in the range of -1.0 to +0.99997 and convert it to the q15 format
 * q15_t q15_from_float(float num) - This function will take a double in the range of -1.0 to +0.99997 and convert it to the q15 format
 * q15_t q15_from_int(int num) - This function will take an integer in the range of -1 to 1 and convert it to a q15 format.  This function is included for completenes, but it is not expected that it will be utilized in most applications.  Generally, typecasts will be used to convert integers to q15 format.

## Basic Arithmetic ##

 * q15_t q15_mul(q15_t multiplicand, q15_t multiplier) - Multiplies two q15 numbers and returns the result
 * q15_t q15_div(q15_t dividend, q15_t divisor) - Divides two q15 numbers and returns the result.  Note that that the dividend MUST be smaller than the divisor or the output will saturate!
 * q15_t q15_add(q15_t addend, q15_t adder) - Adds two q15 numbers together and returns the result.  Note that if the result is greater than 32767 or less than -32768, the result will saturate!
 * q15_t q15_abs(q15_t num) - Returns the absoluate value of the given q15 number.
 * q15_t q15_sqrt(q15_t num) - Returns the square root of the given q15 number.  Due to resolution, the input 'num' should generally be larger than '1000' or the results will suffer significant skew.
 
## Trigonometry ##
 * q15_t q15_sin(q16angle_t theta) - Returns the sine of the angle in q15 format.  Note that this function uses a lookup table (see 'defines') and interpolation.
 * q15_t q15_fast_sin(q16angle_t theta) - Returns the sine of the angle in q15 format.  This function uses a lookup table only, but is faster than the standard implementation.
 * q15_t q15_cos(q16angle_t theta) - Returns the cosine of the angle in q15 format.  Note that this function uses a lookup table (see 'defines') and interpolation.
 * q15_t q15_fast_cos(q16angle_t theta) - Returns the cosine of the angle in q15 format.  This function uses a lookup table only, but is faster than the standard implementation.
 * q15_t q15_tan(q16angle_t theta) - Returns the tangent of the angle in q15 format.   Note that this function uses a lookup table (see 'defines') and interpolation.  Note also that the return type is q15_t, which will saturate at values which are less than -1.0 (-32768) or greater than 0.9997 (+32767).  If you require a higher range, then you should probably use a method that offers that range.
 * q15_t q15_fast_tan(q16angle_t theta) - Returns the cosine of the angle in q15 format.  This function uses a lookup table only, but is faster than the standard implementation.
 
 
 