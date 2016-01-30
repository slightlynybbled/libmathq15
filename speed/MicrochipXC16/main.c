/*
 * File:   main.c
 * Author: Jason
 *
 * Code used for testing speed of floats vs. fixed.  Used
 * the microchip debugger to test.
 */


#include "xc.h"
#include "libmathq15.h"

int main(void) {
    float dNum0, dNum1, dNum;
    q15_t fNum0, fNum1, fNum;
    
    /**********************************************/
    /* benchmark of floating-point multiplication */
    dNum0 = 0.4286;
    dNum1 = 0.7582;

    dNum = dNum0 * dNum1;

    /* benchmark of fixed-point multiplication */
    fNum0 = (q15_t)(dNum0 * 32767);
    fNum1 = (q15_t)(dNum1 * 32767);

    fNum = q15_mul(fNum0, fNum1);
    
    
    
    
    /**********************************************/
    /* benchmark of floating-point division */
    dNum = dNum0 / dNum1;

    /* benchmark of fixed-point multiplication */
    fNum0 = (q15_t)(dNum0 * 32767);
    fNum1 = (q15_t)(dNum1 * 32767);

    fNum = q15_div(fNum0, fNum1);
    
    
    
    
    
    /**********************************************/
    /* benchmark of floating-point addition */
    dNum = dNum0 + dNum1;

    /* benchmark of fixed-point multiplication */
    fNum0 = (q15_t)(dNum0 * 32767);
    fNum1 = (q15_t)(dNum1 * 32767);

    fNum = q15_add(15000, 1000);
    

    
    return 0;
}
