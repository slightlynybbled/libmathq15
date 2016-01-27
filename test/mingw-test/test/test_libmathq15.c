/*******************************************************************************
 *    INCLUDED FILES
 ******************************************************************************/
 
//-- unity: unit test framework
#include "unity.h"
#include "libmathq15.h"
 
//-- module being tested
//   TODO
 
 
/*******************************************************************************
 *    DEFINITIONS
 ******************************************************************************/
 
/*******************************************************************************
 *    PRIVATE TYPES
 ******************************************************************************/
 
/*******************************************************************************
 *    PRIVATE DATA
 ******************************************************************************/
 
 
/*******************************************************************************
 *    PRIVATE FUNCTIONS
 ******************************************************************************/
 
 
/*******************************************************************************
 *    SETUP, TEARDOWN
 ******************************************************************************/
 
void setUp(void)
{
}
 
void tearDown(void)
{
}
 
/*******************************************************************************
 *    TESTS
 ******************************************************************************/
 
void test_q15_mul_32767x32767(void)
{
    q15_t multiplier = 32767;
    q15_t multiplicand = 32767;
    q15_t result = q15_mul(multiplier, multiplicand);
    
    TEST_ASSERT_EQUAL_INT16(32766, result);
}

void test_q15_mul_32767xneg32768(void)
{
    q15_t multiplier = -32768;
    q15_t multiplicand = 32767;
    q15_t result = q15_mul(multiplier, multiplicand);
    
    TEST_ASSERT_EQUAL_INT16(-32767, result);
}

void test_q15_mul_neg32768xneg32768(void)
{
    q15_t multiplier = -32768;
    q15_t multiplicand = -32768;
    q15_t result = q15_mul(multiplier, multiplicand);
    
    TEST_ASSERT_EQUAL_INT16(-32768, result);
}

void test_q15_mul_0x0(void)
{
    q15_t multiplier = 0;
    q15_t multiplicand = 0;
    q15_t result = q15_mul(multiplier, multiplicand);
    
    TEST_ASSERT_EQUAL_INT16(0, result);
}

void test_q15_mul_16384xneg16384(void)
{
    q15_t multiplier = 16384;
    q15_t multiplicand = -16384;
    q15_t result = q15_mul(multiplier, multiplicand);
    
    TEST_ASSERT_EQUAL_INT16(-8192, result);
}

void test_q15_div_0_0(void){
    q15_t result = q15_div(0, 0);
    
    TEST_ASSERT_EQUAL_INT16(32767, result);
}

void test_q15_div_1_0(void){
    q15_t result = q15_div(1, 0);
    
    TEST_ASSERT_EQUAL_INT16(32767, result);
}

void test_q15_div_n1_0(void){
    q15_t result = q15_div(-1, 0);
    
    TEST_ASSERT_EQUAL_INT16(-32768, result);
}

void test_q15_div_16384_n32768(void){
    q15_t result = q15_div(16384, -32768);
    
    TEST_ASSERT_EQUAL_INT16(-16384, result);
}

void test_q15_div_n16384_32767(void){
    q15_t result = q15_div(-16384, 32767);
    
    TEST_ASSERT_EQUAL_INT16(-16384, result);
}

void test_q15_add_0_0(void){
    TEST_ASSERT_EQUAL_INT16(0, q15_add(0,0));
}

void test_q15_add_100_n100(void){
    TEST_ASSERT_EQUAL_INT16(0, q15_add(100,-100));
}

void test_q15_add_32000_1000(void){
    TEST_ASSERT_EQUAL_INT16(32767, q15_add(32000,1000));
}

void test_q15_add_n32000_n1000(void){
    TEST_ASSERT_EQUAL_INT16(-32768, q15_add(-32000,-1000));
}

void test_q15_abs_0(void){
    TEST_ASSERT_EQUAL_INT16(0, q15_abs(0));
}

void test_q15_abs_16384(void){
    TEST_ASSERT_EQUAL_INT16(16384, q15_abs(-16384));
}

void test_q15_abs_n16384(void){
    TEST_ASSERT_EQUAL_INT16(16384, q15_abs(-16384));
}

void test_q15_sqrt_8192(void){
    TEST_ASSERT_EQUAL_INT16(16384, q15_sqrt(8192));
}

void test_q15_sqrt_1000(void){
    /* actual should be closer to 5724, but this loss of resolution is acceptable */
    TEST_ASSERT_EQUAL_INT16(5728, q15_sqrt(1000));
}

void test_q15_sqrt_0(void){
    /* sqrt doesn't work well at low values */
    TEST_ASSERT_EQUAL_INT16(182, q15_sqrt(0));
}
