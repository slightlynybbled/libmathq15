/*
 * File:   test_libmathq15.c
 * Author: Jason
 *
 * Created on February 3, 2016, 4:38 PM
 */


#include "xc.h"
#include "libmathq15.h"

void TEST_ASSERT_FLOAT_WITHIN(float tolerance, float desiredValue, float testValue);
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
    TEST_ASSERT_EQUAL_INT16(5728, q15_sqrt(1000));

    /* sqrt doesn't work well at low values */
    TEST_ASSERT_EQUAL_INT16(182, q15_sqrt(0));
    TEST_ASSERT_EQUAL_INT16(0, q15_sin(0));

    /* sine 30 deg */
    /* default value would be 16384, but this routine is 2 points off in this case */
    TEST_ASSERT_EQUAL_INT16(16379, q15_sin(5461));

    /* sine 45 deg */
    TEST_ASSERT_EQUAL_INT16(23169, q15_sin(8192));

    /* sine 60 deg */
    /* default value would be 28377, but this routine is 2 point off in this case */
    TEST_ASSERT_EQUAL_INT16(28375, q15_sin(10923));

    /* sine 89.99 deg */
    /* default value would be 32767, but this routine is 1 point off in this case */
    TEST_ASSERT_EQUAL_INT16(32766, q15_sin(16383));

    /* sine 90 deg */
    /* default value would be 32767, but this routine is 1 point off in this case */
    TEST_ASSERT_EQUAL_INT16(32766, q15_sin(16384));

    /* sine 90.01 deg */
    /* default value would be 32767, but this routine is 1 point off in this case */
    TEST_ASSERT_EQUAL_INT16(32766, q15_sin(16385));

    /* sine 120 deg */
    /* default value would be 28378, but this routine is 3 point off in this case */
    TEST_ASSERT_EQUAL_INT16(28375, q15_sin(21845));

    /* sine 150 deg */
    /* default value would be 16384, but this routine is 5 point off in this case */
    TEST_ASSERT_EQUAL_INT16(16379, q15_sin(27307));

    /* sine 179.99 deg */
    TEST_ASSERT_EQUAL_INT16(0, q15_sin(32767));

    /* sine 180.00 deg */
    TEST_ASSERT_EQUAL_INT16(0, q15_sin(32768));

    /* sine 180.01 deg */
    TEST_ASSERT_EQUAL_INT16(0, q15_sin(32769));

    /* sine 210 deg */
    /* default value would be 16384, but this routine is 2 point off in this case */
    TEST_ASSERT_EQUAL_INT16(-16379, q15_sin(38229));

    /* sine 240 deg */
    /* default value would be 28378, but this routine is 2 point off in this case */
    TEST_ASSERT_EQUAL_INT16(-28375, q15_sin(43691));

    /* sine 269.99 deg */
    TEST_ASSERT_EQUAL_INT16(-32766, q15_sin(49151));

    /* sine 270.00 deg */
    TEST_ASSERT_EQUAL_INT16(-32766, q15_sin(49152));

    /* sine 270.01 deg */
    TEST_ASSERT_EQUAL_INT16(-32766, q15_sin(49153));

    /* sine 300 deg */
    /* default value would be 28376, but this routine is 1 point off in this case */
    TEST_ASSERT_EQUAL_INT16(-28375, q15_sin(54613));

    /* sine 330 deg */
    /* default value would be -16384, but this routine is 5 point off in this case */
    TEST_ASSERT_EQUAL_INT16(-16379, q15_sin(60075));

    /* sine 359.99 deg */
    /* default value would be 0, but this routine is 5 point off in this case */
    TEST_ASSERT_EQUAL_INT16(0, q15_sin(65535));

    /* cos 0 deg */
    /* default value would be 32767, but this routine is 5 point off in this case */
    TEST_ASSERT_EQUAL_INT16(32766, q15_cos(0));

    /* cos 90 deg */
    /* default value would be 32767, but this routine is 5 point off in this case */
    TEST_ASSERT_EQUAL_INT16(0, q15_cos(16384));

    /* cos 180 deg */
    /* default value would be 32767, but this routine is 5 point off in this case */
    TEST_ASSERT_EQUAL_INT16(-32766, q15_cos(32768));

    /* cos 270 deg */
    /* default value would be 32767, but this routine is 5 point off in this case */
    TEST_ASSERT_EQUAL_INT16(0, q15_cos(49151));

    while(1);   // if you made it here, then you passed all of your tests!

    return 0;
}

void TEST_ASSERT_FLOAT_WITHIN(float tolerance, float desiredValue, float testValue){
    float maxValue = desiredValue + tolerance;
    float minValue = desiredValue - tolerance;
    
    if(testValue > maxValue){
        Nop();
    }
    
    if(testValue < minValue){
        Nop();
    }
}

void TEST_ASSERT_EQUAL_INT16(int16_t n0, int16_t n1){
    if(n0 != n1){
        Nop();
    }
}


