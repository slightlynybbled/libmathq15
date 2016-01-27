#include "libmathq15.h"
#include "unity.h"










void setUp(void)

{

}



void tearDown(void)

{

}











void test_q15_mul(void)

{

    q15_t multiplier = 32767;

    q15_t multiplicand = 32767;

    q15_t result = q15_mul(multiplier, multiplicand);



    UnityAssertEqualNumber((_U_SINT)(_US16)((32766)), (_U_SINT)(_US16)((result)), (

   ((void *)0)

   ), (_U_UINT)53, UNITY_DISPLAY_STYLE_INT16);

}
