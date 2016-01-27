#include "libmathq15.h"
#include "unity.h"










void setUp(void)

{

}



void tearDown(void)

{

}











void test_q15_mul_32767x32767(void)

{

    q15_t multiplier = 32767;

    q15_t multiplicand = 32767;

    q15_t result = q15_mul(multiplier, multiplicand);



    UnityAssertEqualNumber((_U_SINT)(_US16)((32766)), (_U_SINT)(_US16)((result)), (

   ((void *)0)

   ), (_U_UINT)53, UNITY_DISPLAY_STYLE_INT16);

}



void test_q15_mul_32767xneg32768(void)

{

    q15_t multiplier = -32768;

    q15_t multiplicand = 32767;

    q15_t result = q15_mul(multiplier, multiplicand);



    UnityAssertEqualNumber((_U_SINT)(_US16)((-32767)), (_U_SINT)(_US16)((result)), (

   ((void *)0)

   ), (_U_UINT)62, UNITY_DISPLAY_STYLE_INT16);

}



void test_q15_mul_neg32768xneg32768(void)

{

    q15_t multiplier = -32768;

    q15_t multiplicand = -32768;

    q15_t result = q15_mul(multiplier, multiplicand);



    UnityAssertEqualNumber((_U_SINT)(_US16)((-32768)), (_U_SINT)(_US16)((result)), (

   ((void *)0)

   ), (_U_UINT)71, UNITY_DISPLAY_STYLE_INT16);

}



void test_q15_mul_0x0(void)

{

    q15_t multiplier = 0;

    q15_t multiplicand = 0;

    q15_t result = q15_mul(multiplier, multiplicand);



    UnityAssertEqualNumber((_U_SINT)(_US16)((0)), (_U_SINT)(_US16)((result)), (

   ((void *)0)

   ), (_U_UINT)80, UNITY_DISPLAY_STYLE_INT16);

}



void test_q15_mul_16384xneg16384(void)

{

    q15_t multiplier = 16384;

    q15_t multiplicand = -16384;

    q15_t result = q15_mul(multiplier, multiplicand);



    UnityAssertEqualNumber((_U_SINT)(_US16)((-8192)), (_U_SINT)(_US16)((result)), (

   ((void *)0)

   ), (_U_UINT)89, UNITY_DISPLAY_STYLE_INT16);

}



void test_q15_div_0_0(void){

    q15_t result = q15_div(0, 0);



    UnityAssertEqualNumber((_U_SINT)(_US16)((32767)), (_U_SINT)(_US16)((result)), (

   ((void *)0)

   ), (_U_UINT)95, UNITY_DISPLAY_STYLE_INT16);

}



void test_q15_div_1_0(void){

    q15_t result = q15_div(1, 0);



    UnityAssertEqualNumber((_U_SINT)(_US16)((32767)), (_U_SINT)(_US16)((result)), (

   ((void *)0)

   ), (_U_UINT)101, UNITY_DISPLAY_STYLE_INT16);

}



void test_q15_div_n1_0(void){

    q15_t result = q15_div(-1, 0);



    UnityAssertEqualNumber((_U_SINT)(_US16)((-32768)), (_U_SINT)(_US16)((result)), (

   ((void *)0)

   ), (_U_UINT)107, UNITY_DISPLAY_STYLE_INT16);

}



void test_q15_div_16384_n32768(void){

    q15_t result = q15_div(16384, -32768);



    UnityAssertEqualNumber((_U_SINT)(_US16)((-16384)), (_U_SINT)(_US16)((result)), (

   ((void *)0)

   ), (_U_UINT)113, UNITY_DISPLAY_STYLE_INT16);

}



void test_q15_div_n16384_32767(void){

    q15_t result = q15_div(-16384, 32767);



    UnityAssertEqualNumber((_U_SINT)(_US16)((-16384)), (_U_SINT)(_US16)((result)), (

   ((void *)0)

   ), (_U_UINT)119, UNITY_DISPLAY_STYLE_INT16);

}



void test_q15_add_0_0(void){

    UnityAssertEqualNumber((_U_SINT)(_US16)((0)), (_U_SINT)(_US16)((q15_add(0,0))), (

   ((void *)0)

   ), (_U_UINT)123, UNITY_DISPLAY_STYLE_INT16);

}



void test_q15_add_100_n100(void){

    UnityAssertEqualNumber((_U_SINT)(_US16)((0)), (_U_SINT)(_US16)((q15_add(100,-100))), (

   ((void *)0)

   ), (_U_UINT)127, UNITY_DISPLAY_STYLE_INT16);

}



void test_q15_add_32000_1000(void){

    UnityAssertEqualNumber((_U_SINT)(_US16)((32767)), (_U_SINT)(_US16)((q15_add(32000,1000))), (

   ((void *)0)

   ), (_U_UINT)131, UNITY_DISPLAY_STYLE_INT16);

}



void test_q15_add_n32000_n1000(void){

    UnityAssertEqualNumber((_U_SINT)(_US16)((-32768)), (_U_SINT)(_US16)((q15_add(-32000,-1000))), (

   ((void *)0)

   ), (_U_UINT)135, UNITY_DISPLAY_STYLE_INT16);

}



void test_q15_abs_0(void){

    UnityAssertEqualNumber((_U_SINT)(_US16)((0)), (_U_SINT)(_US16)((q15_abs(0))), (

   ((void *)0)

   ), (_U_UINT)139, UNITY_DISPLAY_STYLE_INT16);

}



void test_q15_abs_16384(void){

    UnityAssertEqualNumber((_U_SINT)(_US16)((16384)), (_U_SINT)(_US16)((q15_abs(-16384))), (

   ((void *)0)

   ), (_U_UINT)143, UNITY_DISPLAY_STYLE_INT16);

}



void test_q15_abs_n16384(void){

    UnityAssertEqualNumber((_U_SINT)(_US16)((16384)), (_U_SINT)(_US16)((q15_abs(-16384))), (

   ((void *)0)

   ), (_U_UINT)147, UNITY_DISPLAY_STYLE_INT16);

}



void test_q15_sqrt_8192(void){

    UnityAssertEqualNumber((_U_SINT)(_US16)((16384)), (_U_SINT)(_US16)((q15_sqrt(8192))), (

   ((void *)0)

   ), (_U_UINT)151, UNITY_DISPLAY_STYLE_INT16);

}



void test_q15_sqrt_1000(void){



    UnityAssertEqualNumber((_U_SINT)(_US16)((5728)), (_U_SINT)(_US16)((q15_sqrt(1000))), (

   ((void *)0)

   ), (_U_UINT)156, UNITY_DISPLAY_STYLE_INT16);

}



void test_q15_sqrt_0(void){



    UnityAssertEqualNumber((_U_SINT)(_US16)((182)), (_U_SINT)(_US16)((q15_sqrt(0))), (

   ((void *)0)

   ), (_U_UINT)161, UNITY_DISPLAY_STYLE_INT16);

}
