#include "libmathq15.h"
#include "unity.h"










void setUp(void)

{

}



void tearDown(void)

{

}









void test_q15_to_dbl_0(void){

    UnityAssertFloatsWithin((_UF)(0.000031), (_UF)(0), (_UF)(q15_to_dbl(0)), (

   ((void *)0)

   ), (_U_UINT)47);

}



void test_q15_to_dbl_16384(void){

    UnityAssertFloatsWithin((_UF)(0.000031), (_UF)(0.5), (_UF)(q15_to_dbl(16384)), (

   ((void *)0)

   ), (_U_UINT)51);

}



void test_q15_to_dbl_n16384(void){

    UnityAssertFloatsWithin((_UF)(0.000031), (_UF)(-0.5), (_UF)(q15_to_dbl(-16384)), (

   ((void *)0)

   ), (_U_UINT)55);

}



void test_q15_to_dbl_32767(void){

    UnityAssertFloatsWithin((_UF)(0.000031), (_UF)(1.0), (_UF)(q15_to_dbl(32767)), (

   ((void *)0)

   ), (_U_UINT)59);

}



void test_q15_to_dbl_n32768(void){

    UnityAssertFloatsWithin((_UF)(0.000031), (_UF)(-1.0), (_UF)(q15_to_dbl(-32768)), (

   ((void *)0)

   ), (_U_UINT)63);

}



void test_q15_to_float_0(void){

    UnityAssertFloatsWithin((_UF)(0.000031), (_UF)(0), (_UF)(q15_to_float(0)), (

   ((void *)0)

   ), (_U_UINT)67);

}



void test_q15_to_float_16384(void){

    UnityAssertFloatsWithin((_UF)(0.000031), (_UF)(0.5), (_UF)(q15_to_float(16384)), (

   ((void *)0)

   ), (_U_UINT)71);

}



void test_q15_to_float_n16384(void){

    UnityAssertFloatsWithin((_UF)(0.000031), (_UF)(-0.5), (_UF)(q15_to_float(-16384)), (

   ((void *)0)

   ), (_U_UINT)75);

}



void test_q15_to_float_32767(void){

    UnityAssertFloatsWithin((_UF)(0.000031), (_UF)(1.0), (_UF)(q15_to_float(32767)), (

   ((void *)0)

   ), (_U_UINT)79);

}



void test_q15_to_float_n32768(void){

    UnityAssertFloatsWithin((_UF)(0.000031), (_UF)(-1.0), (_UF)(q15_to_float(-32768)), (

   ((void *)0)

   ), (_U_UINT)83);

}



void test_q15_to_int_0(void){

    UnityAssertEqualNumber((_U_SINT)(_US16)((0)), (_U_SINT)(_US16)((q15_to_int(0))), (

   ((void *)0)

   ), (_U_UINT)87, UNITY_DISPLAY_STYLE_INT16);

}



void test_q15_to_int_16383(void){

    UnityAssertEqualNumber((_U_SINT)(_US16)((0)), (_U_SINT)(_US16)((q15_to_int(16383))), (

   ((void *)0)

   ), (_U_UINT)91, UNITY_DISPLAY_STYLE_INT16);

}



void test_q15_to_int_16384(void){

    UnityAssertEqualNumber((_U_SINT)(_US16)((1)), (_U_SINT)(_US16)((q15_to_int(16384))), (

   ((void *)0)

   ), (_U_UINT)95, UNITY_DISPLAY_STYLE_INT16);

}



void test_q15_to_int_n16383(void){

    UnityAssertEqualNumber((_U_SINT)(_US16)((0)), (_U_SINT)(_US16)((q15_to_int(-16383))), (

   ((void *)0)

   ), (_U_UINT)99, UNITY_DISPLAY_STYLE_INT16);

}



void test_q15_to_int_n16384(void){

    UnityAssertEqualNumber((_U_SINT)(_US16)((-1)), (_U_SINT)(_US16)((q15_to_int(-16384))), (

   ((void *)0)

   ), (_U_UINT)103, UNITY_DISPLAY_STYLE_INT16);

}



void test_q15_from_dbl_0(){

    UnityAssertEqualNumber((_U_SINT)(_US16)((0)), (_U_SINT)(_US16)((q15_from_dbl(0))), (

   ((void *)0)

   ), (_U_UINT)107, UNITY_DISPLAY_STYLE_INT16);

}



void test_q15_from_dbl_0500(){

    UnityAssertEqualNumber((_U_SINT)(_US16)((16384)), (_U_SINT)(_US16)((q15_from_dbl(0.5))), (

   ((void *)0)

   ), (_U_UINT)111, UNITY_DISPLAY_STYLE_INT16);

}



void test_q15_from_dbl_1000(){

    UnityAssertEqualNumber((_U_SINT)(_US16)((32767)), (_U_SINT)(_US16)((q15_from_dbl(1.0))), (

   ((void *)0)

   ), (_U_UINT)115, UNITY_DISPLAY_STYLE_INT16);

}



void test_q15_from_dbl_n0500(){

    UnityAssertEqualNumber((_U_SINT)(_US16)((-16384)), (_U_SINT)(_US16)((q15_from_dbl(-0.5))), (

   ((void *)0)

   ), (_U_UINT)119, UNITY_DISPLAY_STYLE_INT16);

}



void test_q15_from_dbl_n1000(){

    UnityAssertEqualNumber((_U_SINT)(_US16)((-32768)), (_U_SINT)(_US16)((q15_from_dbl(-1.0))), (

   ((void *)0)

   ), (_U_UINT)123, UNITY_DISPLAY_STYLE_INT16);

}



void test_q15_from_float_0(){

    UnityAssertEqualNumber((_U_SINT)(_US16)((0)), (_U_SINT)(_US16)((q15_from_float(0))), (

   ((void *)0)

   ), (_U_UINT)127, UNITY_DISPLAY_STYLE_INT16);

}



void test_q15_from_float_0500(){

    UnityAssertEqualNumber((_U_SINT)(_US16)((16384)), (_U_SINT)(_US16)((q15_from_float(0.5))), (

   ((void *)0)

   ), (_U_UINT)131, UNITY_DISPLAY_STYLE_INT16);

}



void test_q15_from_float_1000(){

    UnityAssertEqualNumber((_U_SINT)(_US16)((32767)), (_U_SINT)(_US16)((q15_from_float(1.0))), (

   ((void *)0)

   ), (_U_UINT)135, UNITY_DISPLAY_STYLE_INT16);

}



void test_q15_from_float_n0500(){

    UnityAssertEqualNumber((_U_SINT)(_US16)((-16384)), (_U_SINT)(_US16)((q15_from_float(-0.5))), (

   ((void *)0)

   ), (_U_UINT)139, UNITY_DISPLAY_STYLE_INT16);

}



void test_q15_from_float_n1000(){

    UnityAssertEqualNumber((_U_SINT)(_US16)((-32768)), (_U_SINT)(_US16)((q15_from_float(-1.0))), (

   ((void *)0)

   ), (_U_UINT)143, UNITY_DISPLAY_STYLE_INT16);

}



void test_q15_from_int_0(){

    UnityAssertEqualNumber((_U_SINT)(_US16)((0)), (_U_SINT)(_US16)((q15_from_int(0))), (

   ((void *)0)

   ), (_U_UINT)147, UNITY_DISPLAY_STYLE_INT16);

}



void test_q15_from_int_1(){

    UnityAssertEqualNumber((_U_SINT)(_US16)((32767)), (_U_SINT)(_US16)((q15_from_int(1))), (

   ((void *)0)

   ), (_U_UINT)151, UNITY_DISPLAY_STYLE_INT16);

}



void test_q15_from_int_2(){

    UnityAssertEqualNumber((_U_SINT)(_US16)((32767)), (_U_SINT)(_US16)((q15_from_int(2))), (

   ((void *)0)

   ), (_U_UINT)155, UNITY_DISPLAY_STYLE_INT16);

}



void test_q15_from_int_n1(){

    UnityAssertEqualNumber((_U_SINT)(_US16)((-32768)), (_U_SINT)(_US16)((q15_from_int(-1))), (

   ((void *)0)

   ), (_U_UINT)159, UNITY_DISPLAY_STYLE_INT16);

}



void test_q15_from_int_n2(){

    UnityAssertEqualNumber((_U_SINT)(_US16)((-32768)), (_U_SINT)(_US16)((q15_from_int(-2.0))), (

   ((void *)0)

   ), (_U_UINT)163, UNITY_DISPLAY_STYLE_INT16);

}



void test_q15_mul_32767x32767(void)

{

    q15_t multiplier = 32767;

    q15_t multiplicand = 32767;

    q15_t result = q15_mul(multiplier, multiplicand);



    UnityAssertEqualNumber((_U_SINT)(_US16)((32766)), (_U_SINT)(_US16)((result)), (

   ((void *)0)

   ), (_U_UINT)172, UNITY_DISPLAY_STYLE_INT16);

}



void test_q15_mul_32767xneg32768(void)

{

    q15_t multiplier = -32768;

    q15_t multiplicand = 32767;

    q15_t result = q15_mul(multiplier, multiplicand);



    UnityAssertEqualNumber((_U_SINT)(_US16)((-32767)), (_U_SINT)(_US16)((result)), (

   ((void *)0)

   ), (_U_UINT)181, UNITY_DISPLAY_STYLE_INT16);

}



void test_q15_mul_neg32768xneg32768(void)

{

    q15_t multiplier = -32768;

    q15_t multiplicand = -32768;

    q15_t result = q15_mul(multiplier, multiplicand);



    UnityAssertEqualNumber((_U_SINT)(_US16)((-32768)), (_U_SINT)(_US16)((result)), (

   ((void *)0)

   ), (_U_UINT)190, UNITY_DISPLAY_STYLE_INT16);

}



void test_q15_mul_0x0(void)

{

    q15_t multiplier = 0;

    q15_t multiplicand = 0;

    q15_t result = q15_mul(multiplier, multiplicand);



    UnityAssertEqualNumber((_U_SINT)(_US16)((0)), (_U_SINT)(_US16)((result)), (

   ((void *)0)

   ), (_U_UINT)199, UNITY_DISPLAY_STYLE_INT16);

}



void test_q15_mul_16384xneg16384(void)

{

    q15_t multiplier = 16384;

    q15_t multiplicand = -16384;

    q15_t result = q15_mul(multiplier, multiplicand);



    UnityAssertEqualNumber((_U_SINT)(_US16)((-8192)), (_U_SINT)(_US16)((result)), (

   ((void *)0)

   ), (_U_UINT)208, UNITY_DISPLAY_STYLE_INT16);

}



void test_q15_div_0_0(void){

    q15_t result = q15_div(0, 0);



    UnityAssertEqualNumber((_U_SINT)(_US16)((32767)), (_U_SINT)(_US16)((result)), (

   ((void *)0)

   ), (_U_UINT)214, UNITY_DISPLAY_STYLE_INT16);

}



void test_q15_div_1_0(void){

    q15_t result = q15_div(1, 0);



    UnityAssertEqualNumber((_U_SINT)(_US16)((32767)), (_U_SINT)(_US16)((result)), (

   ((void *)0)

   ), (_U_UINT)220, UNITY_DISPLAY_STYLE_INT16);

}



void test_q15_div_n1_0(void){

    q15_t result = q15_div(-1, 0);



    UnityAssertEqualNumber((_U_SINT)(_US16)((-32768)), (_U_SINT)(_US16)((result)), (

   ((void *)0)

   ), (_U_UINT)226, UNITY_DISPLAY_STYLE_INT16);

}



void test_q15_div_16384_n32768(void){

    q15_t result = q15_div(16384, -32768);



    UnityAssertEqualNumber((_U_SINT)(_US16)((-16384)), (_U_SINT)(_US16)((result)), (

   ((void *)0)

   ), (_U_UINT)232, UNITY_DISPLAY_STYLE_INT16);

}



void test_q15_div_n16384_32767(void){

    q15_t result = q15_div(-16384, 32767);



    UnityAssertEqualNumber((_U_SINT)(_US16)((-16384)), (_U_SINT)(_US16)((result)), (

   ((void *)0)

   ), (_U_UINT)238, UNITY_DISPLAY_STYLE_INT16);

}



void test_q15_add_0_0(void){

    UnityAssertEqualNumber((_U_SINT)(_US16)((0)), (_U_SINT)(_US16)((q15_add(0,0))), (

   ((void *)0)

   ), (_U_UINT)242, UNITY_DISPLAY_STYLE_INT16);

}



void test_q15_add_100_n100(void){

    UnityAssertEqualNumber((_U_SINT)(_US16)((0)), (_U_SINT)(_US16)((q15_add(100,-100))), (

   ((void *)0)

   ), (_U_UINT)246, UNITY_DISPLAY_STYLE_INT16);

}



void test_q15_add_32000_1000(void){

    UnityAssertEqualNumber((_U_SINT)(_US16)((32767)), (_U_SINT)(_US16)((q15_add(32000,1000))), (

   ((void *)0)

   ), (_U_UINT)250, UNITY_DISPLAY_STYLE_INT16);

}



void test_q15_add_n32000_n1000(void){

    UnityAssertEqualNumber((_U_SINT)(_US16)((-32768)), (_U_SINT)(_US16)((q15_add(-32000,-1000))), (

   ((void *)0)

   ), (_U_UINT)254, UNITY_DISPLAY_STYLE_INT16);

}



void test_q15_abs_0(void){

    UnityAssertEqualNumber((_U_SINT)(_US16)((0)), (_U_SINT)(_US16)((q15_abs(0))), (

   ((void *)0)

   ), (_U_UINT)258, UNITY_DISPLAY_STYLE_INT16);

}



void test_q15_abs_16384(void){

    UnityAssertEqualNumber((_U_SINT)(_US16)((16384)), (_U_SINT)(_US16)((q15_abs(-16384))), (

   ((void *)0)

   ), (_U_UINT)262, UNITY_DISPLAY_STYLE_INT16);

}



void test_q15_abs_n16384(void){

    UnityAssertEqualNumber((_U_SINT)(_US16)((16384)), (_U_SINT)(_US16)((q15_abs(-16384))), (

   ((void *)0)

   ), (_U_UINT)266, UNITY_DISPLAY_STYLE_INT16);

}



void test_q15_sqrt_8192(void){

    UnityAssertEqualNumber((_U_SINT)(_US16)((16384)), (_U_SINT)(_US16)((q15_sqrt(8192))), (

   ((void *)0)

   ), (_U_UINT)270, UNITY_DISPLAY_STYLE_INT16);

}



void test_q15_sqrt_1000(void){



    UnityAssertEqualNumber((_U_SINT)(_US16)((5728)), (_U_SINT)(_US16)((q15_sqrt(1000))), (

   ((void *)0)

   ), (_U_UINT)275, UNITY_DISPLAY_STYLE_INT16);

}



void test_q15_sqrt_0(void){



    UnityAssertEqualNumber((_U_SINT)(_US16)((182)), (_U_SINT)(_US16)((q15_sqrt(0))), (

   ((void *)0)

   ), (_U_UINT)280, UNITY_DISPLAY_STYLE_INT16);

}



void test_q15_sin_0(void){

    UnityAssertEqualNumber((_U_SINT)(_US16)((0)), (_U_SINT)(_US16)((q15_sin(0))), (

   ((void *)0)

   ), (_U_UINT)284, UNITY_DISPLAY_STYLE_INT16);

}





void test_q15_sin_5161(void){



    UnityAssertEqualNumber((_U_SINT)(_US16)((16382)), (_U_SINT)(_US16)((q15_sin(5461))), (

   ((void *)0)

   ), (_U_UINT)290, UNITY_DISPLAY_STYLE_INT16);

}





void test_q15_sin_8192(void){

    UnityAssertEqualNumber((_U_SINT)(_US16)((23169)), (_U_SINT)(_US16)((q15_sin(8192))), (

   ((void *)0)

   ), (_U_UINT)295, UNITY_DISPLAY_STYLE_INT16);

}





void test_q15_sin_10923(void){



    UnityAssertEqualNumber((_U_SINT)(_US16)((28376)), (_U_SINT)(_US16)((q15_sin(10923))), (

   ((void *)0)

   ), (_U_UINT)301, UNITY_DISPLAY_STYLE_INT16);

}





void test_q15_sin_16383(void){



    UnityAssertEqualNumber((_U_SINT)(_US16)((32766)), (_U_SINT)(_US16)((q15_sin(16383))), (

   ((void *)0)

   ), (_U_UINT)307, UNITY_DISPLAY_STYLE_INT16);

}





void test_q15_sin_16384(void){



    UnityAssertEqualNumber((_U_SINT)(_US16)((32766)), (_U_SINT)(_US16)((q15_sin(16384))), (

   ((void *)0)

   ), (_U_UINT)313, UNITY_DISPLAY_STYLE_INT16);

}





void test_q15_sin_16385(void){



    UnityAssertEqualNumber((_U_SINT)(_US16)((32766)), (_U_SINT)(_US16)((q15_sin(16385))), (

   ((void *)0)

   ), (_U_UINT)319, UNITY_DISPLAY_STYLE_INT16);

}





void test_q15_sin_21845(void){



    UnityAssertEqualNumber((_U_SINT)(_US16)((28375)), (_U_SINT)(_US16)((q15_sin(21845))), (

   ((void *)0)

   ), (_U_UINT)325, UNITY_DISPLAY_STYLE_INT16);

}





void test_q15_sin_27307(void){



    UnityAssertEqualNumber((_U_SINT)(_US16)((16379)), (_U_SINT)(_US16)((q15_sin(27307))), (

   ((void *)0)

   ), (_U_UINT)331, UNITY_DISPLAY_STYLE_INT16);

}





void test_q15_sin_32767(void){

    UnityAssertEqualNumber((_U_SINT)(_US16)((0)), (_U_SINT)(_US16)((q15_sin(32767))), (

   ((void *)0)

   ), (_U_UINT)336, UNITY_DISPLAY_STYLE_INT16);

}





void test_q15_sin_32768(void){

    UnityAssertEqualNumber((_U_SINT)(_US16)((0)), (_U_SINT)(_US16)((q15_sin(32768))), (

   ((void *)0)

   ), (_U_UINT)341, UNITY_DISPLAY_STYLE_INT16);

}





void test_q15_sin_32769(void){

    UnityAssertEqualNumber((_U_SINT)(_US16)((-3)), (_U_SINT)(_US16)((q15_sin(32769))), (

   ((void *)0)

   ), (_U_UINT)346, UNITY_DISPLAY_STYLE_INT16);

}





void test_q15_sin_38229(void){



    UnityAssertEqualNumber((_U_SINT)(_US16)((-16382)), (_U_SINT)(_US16)((q15_sin(38229))), (

   ((void *)0)

   ), (_U_UINT)352, UNITY_DISPLAY_STYLE_INT16);

}





void test_q15_sin_43691(void){



    UnityAssertEqualNumber((_U_SINT)(_US16)((-28376)), (_U_SINT)(_US16)((q15_sin(43691))), (

   ((void *)0)

   ), (_U_UINT)358, UNITY_DISPLAY_STYLE_INT16);

}





void test_q15_sin_49151(void){

    UnityAssertEqualNumber((_U_SINT)(_US16)((-32766)), (_U_SINT)(_US16)((q15_sin(49151))), (

   ((void *)0)

   ), (_U_UINT)363, UNITY_DISPLAY_STYLE_INT16);

}





void test_q15_sin_49152(void){

    UnityAssertEqualNumber((_U_SINT)(_US16)((-32766)), (_U_SINT)(_US16)((q15_sin(49152))), (

   ((void *)0)

   ), (_U_UINT)368, UNITY_DISPLAY_STYLE_INT16);

}





void test_q15_sin_49153(void){

    UnityAssertEqualNumber((_U_SINT)(_US16)((-32766)), (_U_SINT)(_US16)((q15_sin(49153))), (

   ((void *)0)

   ), (_U_UINT)373, UNITY_DISPLAY_STYLE_INT16);

}





void test_q15_sin_54613(void){



    UnityAssertEqualNumber((_U_SINT)(_US16)((-28375)), (_U_SINT)(_US16)((q15_sin(54613))), (

   ((void *)0)

   ), (_U_UINT)379, UNITY_DISPLAY_STYLE_INT16);

}





void test_q15_sin_60075(void){



    UnityAssertEqualNumber((_U_SINT)(_US16)((-16379)), (_U_SINT)(_US16)((q15_sin(60075))), (

   ((void *)0)

   ), (_U_UINT)385, UNITY_DISPLAY_STYLE_INT16);

}





void test_q15_sin_65535(void){



    UnityAssertEqualNumber((_U_SINT)(_US16)((0)), (_U_SINT)(_US16)((q15_sin(65535))), (

   ((void *)0)

   ), (_U_UINT)391, UNITY_DISPLAY_STYLE_INT16);

}





void test_q15_cos_0(void){



    UnityAssertEqualNumber((_U_SINT)(_US16)((32766)), (_U_SINT)(_US16)((q15_cos(0))), (

   ((void *)0)

   ), (_U_UINT)397, UNITY_DISPLAY_STYLE_INT16);

}





void test_q15_cos_16384(void){



    UnityAssertEqualNumber((_U_SINT)(_US16)((0)), (_U_SINT)(_US16)((q15_cos(16384))), (

   ((void *)0)

   ), (_U_UINT)403, UNITY_DISPLAY_STYLE_INT16);

}





void test_q15_cos_32768(void){



    UnityAssertEqualNumber((_U_SINT)(_US16)((-32766)), (_U_SINT)(_US16)((q15_cos(32768))), (

   ((void *)0)

   ), (_U_UINT)409, UNITY_DISPLAY_STYLE_INT16);

}





void test_q15_cos_49151(void){



    UnityAssertEqualNumber((_U_SINT)(_US16)((0)), (_U_SINT)(_US16)((q15_cos(49151))), (

   ((void *)0)

   ), (_U_UINT)415, UNITY_DISPLAY_STYLE_INT16);

}
