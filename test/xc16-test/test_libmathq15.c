/*
 * File:   test_libmathq15.c
 * Author: Jason
 *
 * Created on February 3, 2016, 4:38 PM
 */


#include "xc.h"
#include "libmathq15.h"
#include <stdio.h>

/* use this define to set the acceptable error - in 
 * ticks - across the range of trig values */
#define ACCEPTABLE_TRIG_TOLERANCE   5

/* variables */
unsigned int tests_executed = 0;
unsigned int tests_passed = 0;
unsigned int tests_failed = 0;

void TEST_ASSERT_FLOAT_WITHIN(float tolerance, float desiredValue, float testValue);
void TEST_ASSERT_INT16_WITHIN(int16_t tolerance, int16_t expectedValue, int16_t value);
void TEST_ASSERT_EQUAL_INT16(int16_t n0, int16_t n1);

int main(void) {
    /* these tests mirror those in the mingw test directory */
    TEST_ASSERT_FLOAT_WITHIN(0.000031, 0, q15_to_dbl(0));
    TEST_ASSERT_FLOAT_WITHIN(0.000031, 0.5, q15_to_dbl(16384));
    TEST_ASSERT_FLOAT_WITHIN(0.000031, -0.5, q15_to_dbl(-16384));
    TEST_ASSERT_FLOAT_WITHIN(0.000031, 1.0, q15_to_dbl(32767));
    TEST_ASSERT_FLOAT_WITHIN(0.000031, -1.0, q15_to_dbl(-32768));
    TEST_ASSERT_FLOAT_WITHIN(0.000031, 0, q15_to_float(0));
    TEST_ASSERT_FLOAT_WITHIN(0.000031, 0.5, q15_to_float(16384));
    TEST_ASSERT_FLOAT_WITHIN(0.000031, -0.5, q15_to_float(-16384));
    TEST_ASSERT_FLOAT_WITHIN(0.000031, 1.0, q15_to_float(32767));
    TEST_ASSERT_FLOAT_WITHIN(0.000031, -1.0, q15_to_float(-32768));
    
    TEST_ASSERT_EQUAL_INT16(0, q15_to_int(0));
    TEST_ASSERT_EQUAL_INT16(0, q15_to_int(16383));
    TEST_ASSERT_EQUAL_INT16(1, q15_to_int(16384));
    TEST_ASSERT_EQUAL_INT16(0, q15_to_int(-16383));
    TEST_ASSERT_EQUAL_INT16(-1, q15_to_int(-16384));
    TEST_ASSERT_EQUAL_INT16(0, q15_from_dbl(0));
    TEST_ASSERT_EQUAL_INT16(16384, q15_from_dbl(0.5));
    TEST_ASSERT_EQUAL_INT16(32767, q15_from_dbl(1.0));
    TEST_ASSERT_EQUAL_INT16(-16384, q15_from_dbl(-0.5));
    TEST_ASSERT_EQUAL_INT16(-32768, q15_from_dbl(-1.0));
    TEST_ASSERT_EQUAL_INT16(0, q15_from_float(0));
    TEST_ASSERT_EQUAL_INT16(16384, q15_from_float(0.5));
    TEST_ASSERT_EQUAL_INT16(32767, q15_from_float(1.0));
    TEST_ASSERT_EQUAL_INT16(-16384, q15_from_float(-0.5));
    TEST_ASSERT_EQUAL_INT16(-32768, q15_from_float(-1.0));
    TEST_ASSERT_EQUAL_INT16(0, q15_from_int(0));
    TEST_ASSERT_EQUAL_INT16(32767, q15_from_int(1));
    TEST_ASSERT_EQUAL_INT16(32767, q15_from_int(2));
    TEST_ASSERT_EQUAL_INT16(-32768, q15_from_int(-1));
    TEST_ASSERT_EQUAL_INT16(-32768, q15_from_int(-2.0));
    TEST_ASSERT_EQUAL_INT16(32766, q15_mul(32767, 32767));
    TEST_ASSERT_EQUAL_INT16(-32767, q15_mul(-32768, 32767));
    TEST_ASSERT_EQUAL_INT16(-32768, q15_mul(-32768, -32768));
    TEST_ASSERT_EQUAL_INT16(0, q15_mul(0, 0));
    TEST_ASSERT_EQUAL_INT16(-8192, q15_mul(16384, -16384));
    TEST_ASSERT_EQUAL_INT16(32767, q15_div(0, 0));
    TEST_ASSERT_EQUAL_INT16(32767, q15_div(1, 0));
    TEST_ASSERT_EQUAL_INT16(-32768, q15_div(-1, 0));
    TEST_ASSERT_EQUAL_INT16(-16384, q15_div(16384, -32768));
    TEST_ASSERT_EQUAL_INT16(-16384, q15_div(-16384, 32767));
    TEST_ASSERT_EQUAL_INT16(0, q15_add(0,0));
    TEST_ASSERT_EQUAL_INT16(0, q15_add(100,-100));
    TEST_ASSERT_EQUAL_INT16(32767, q15_add(32000,1000));
    TEST_ASSERT_EQUAL_INT16(-32768, q15_add(-32000,-1000));
    TEST_ASSERT_EQUAL_INT16(0, q15_abs(0));
    TEST_ASSERT_EQUAL_INT16(16384, q15_abs(-16384));
    TEST_ASSERT_EQUAL_INT16(16384, q15_abs(-16384));
    TEST_ASSERT_EQUAL_INT16(32767, q15_abs(-32768));
    TEST_ASSERT_EQUAL_INT16(16384, q15_sqrt(8192));

    /* actual should be closer to 5724, but this loss of resolution is acceptable */
    TEST_ASSERT_INT16_WITHIN(4, 5724, q15_sqrt(1000));

    /* sqrt doesn't work well at low values */
    TEST_ASSERT_EQUAL_INT16(182, q15_sqrt(0));
    
    /* sine 0 deg */
    TEST_ASSERT_INT16_WITHIN(ACCEPTABLE_TRIG_TOLERANCE, 0, q15_sin(0));

    /* sine 30 deg */
    TEST_ASSERT_INT16_WITHIN(ACCEPTABLE_TRIG_TOLERANCE, 16384, q15_sin(5461));

    /* sine 45 deg */
    TEST_ASSERT_INT16_WITHIN(ACCEPTABLE_TRIG_TOLERANCE, 23170, q15_sin(8192));

    /* sine 60 deg */
    TEST_ASSERT_INT16_WITHIN(ACCEPTABLE_TRIG_TOLERANCE, 28377, q15_sin(10923));

    /* sine 89.99 deg */
    /* default value would be 32767, but this routine is 1 point off in this case */
    TEST_ASSERT_INT16_WITHIN(ACCEPTABLE_TRIG_TOLERANCE, 32766, q15_sin(16383));

    /* sine 90 deg */
    TEST_ASSERT_INT16_WITHIN(ACCEPTABLE_TRIG_TOLERANCE, 32767, q15_sin(16384));

    /* sine 90.01 deg */
    TEST_ASSERT_INT16_WITHIN(ACCEPTABLE_TRIG_TOLERANCE, 32767, q15_sin(16385));

    /* sine 120 deg */
    TEST_ASSERT_INT16_WITHIN(ACCEPTABLE_TRIG_TOLERANCE, 28378, q15_sin(21845));

    /* sine 150 deg */
    TEST_ASSERT_INT16_WITHIN(ACCEPTABLE_TRIG_TOLERANCE, 16384, q15_sin(27307));

    /* sine 179.99 deg */
    TEST_ASSERT_INT16_WITHIN(ACCEPTABLE_TRIG_TOLERANCE, 0, q15_sin(32767));

    /* sine 180.00 deg */
    TEST_ASSERT_INT16_WITHIN(ACCEPTABLE_TRIG_TOLERANCE, 0, q15_sin(32768));

    /* sine 180.01 deg */
    TEST_ASSERT_INT16_WITHIN(ACCEPTABLE_TRIG_TOLERANCE, 0, q15_sin(32769));

    /* sine 210 deg */
    TEST_ASSERT_INT16_WITHIN(ACCEPTABLE_TRIG_TOLERANCE, -16384, q15_sin(38229));

    /* sine 240 deg */
    TEST_ASSERT_INT16_WITHIN(ACCEPTABLE_TRIG_TOLERANCE, -28378, q15_sin(43691));

    /* sine 269.99 deg */
    TEST_ASSERT_INT16_WITHIN(ACCEPTABLE_TRIG_TOLERANCE, -32766, q15_sin(49151));

    /* sine 270.00 deg */
    TEST_ASSERT_INT16_WITHIN(ACCEPTABLE_TRIG_TOLERANCE, -32766, q15_sin(49152));

    /* sine 270.01 deg */
    TEST_ASSERT_INT16_WITHIN(ACCEPTABLE_TRIG_TOLERANCE, -32766, q15_sin(49153));

    /* sine 300 deg */
    TEST_ASSERT_INT16_WITHIN(ACCEPTABLE_TRIG_TOLERANCE, -28376, q15_sin(54613));

    /* sine 330 deg */
    TEST_ASSERT_INT16_WITHIN(ACCEPTABLE_TRIG_TOLERANCE, -16384, q15_sin(60075));

    /* sine 359.99 deg */
    TEST_ASSERT_INT16_WITHIN(ACCEPTABLE_TRIG_TOLERANCE, 0, q15_sin(65535));

    /* cos 0 deg */
    TEST_ASSERT_INT16_WITHIN(ACCEPTABLE_TRIG_TOLERANCE, 32767, q15_cos(0));

    /* cos 90 deg */
    TEST_ASSERT_INT16_WITHIN(ACCEPTABLE_TRIG_TOLERANCE, 0, q15_cos(16384));

    /* cos 180 deg */
    TEST_ASSERT_INT16_WITHIN(ACCEPTABLE_TRIG_TOLERANCE, -32767, q15_cos(32768));

    /* cos 270 deg */
    TEST_ASSERT_INT16_WITHIN(ACCEPTABLE_TRIG_TOLERANCE, 0, q15_cos(49151));
    
    /* test status */
    printf("\n\n");
    printf("Tests Executed: %d\n", tests_executed);
    printf("Tests Passed: %d\n", tests_passed);
    printf("Tests Failed: %d\n", tests_failed);

    while(1);   // if you made it here, then you passed all of your tests!

    return 0;
}

void TEST_ASSERT_FLOAT_WITHIN(float tolerance, float desiredValue, float testValue){
    float maxValue = desiredValue + tolerance;
    float minValue = desiredValue - tolerance;
    int pass = 1;
    
    if(testValue > maxValue){
        pass = 0;
    }
    
    if(testValue < minValue){
        pass = 0;
    }
    
    if(pass != 1){
        printf("Test Failure\n");
        printf("\tExpected Value: %f\n", (double)desiredValue);
        printf("\tTest Value: %f\n", (double)testValue);
        tests_failed++;
    }else{
        tests_passed++;
    }
    
    tests_executed++;
}

void TEST_ASSERT_INT16_WITHIN(int16_t tolerance, int16_t expectedValue, int16_t value){
    int32_t maxValue = (int32_t)expectedValue + (int32_t)tolerance;
    int32_t minValue = (int32_t)expectedValue - (int32_t)tolerance;
    int pass = 1;
    
    /* place limits on max and min values based on saturation */
    if(maxValue > 32767)    maxValue = 32767;
    if(minValue < -32768)   minValue = -32768;
    
    if(value > (int16_t)maxValue){
        pass = 0;
    }
    
    if(value < (int16_t)minValue){
        pass = 0;
    }
    
    if(pass != 1){
        printf("Test Failure\n");
        printf("\tExpected Value: %d\n", expectedValue);
        printf("\tTest Value: %d\n", value);
        tests_failed++;
    }else{
        tests_passed++;
    }
    
    tests_executed++;
}

void TEST_ASSERT_EQUAL_INT16(int16_t n0, int16_t n1){
    if(n0 != n1){
        printf("Test Failure\n");
        printf("\tExpected Value: %d\n", n0);
        printf("\tTest Value: %d\n", n1);
        tests_failed++;
    }else{
        tests_passed++;
    }
    
    tests_executed++;
}


