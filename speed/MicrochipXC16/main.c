/*
 * File:   main.c
 * Author: Jason
 *
 * Created on January 29, 2016, 8:34 AM
 */


#include "xc.h"
#include "libmathq15.h"
#include <libq.h>

int main(void) {
    float dNum0, dNum1, dNum;
    q15_t fNum0, fNum1, fNum;
    
    /**********************************************/
    /* benchmark of floating-point multiplication */
    dNum0 = 0.4286;
    dNum1 = 0.7582;
    fNum0 = (q15_t)(dNum0 * 32767);
    fNum1 = (q15_t)(dNum1 * 32767);

    dNum = dNum0 * dNum1;
    
    /* benchmark of fixed-point multiplication - microchip fixed-point lib */
    /* not provided */

    /* benchmark of fixed-point multiplication - q15 lib*/
    fNum = q15_mul(fNum0, fNum1);
    


    /**********************************************/
    /* benchmark of floating-point division */
    dNum = dNum0 / dNum1;
    
    /* benchmark of fixed-point division - microchip fixed-point lib */
    /* not provided */

    /* benchmark of fixed-point division - libmathq15 */
    fNum = q15_div(fNum0, fNum1);
    
    
    
    
    
    /**********************************************/
    /* benchmark of floating-point addition */
    dNum = dNum0 + dNum1;
    
    /* benchmark of fixed-point addition - microchip fixed-point lib */
    fNum = _Q15add(fNum0, fNum1);

    /* benchmark of fixed-point addition - libmathq15 */
    fNum = q15_add(fNum0, fNum1);
    
    
    
    /**********************************************/
    /* benchmark of floating-point abs - function not provided */
    /* not provided */
    
    /* benchmark of fixed-point abs - microchip fixed-point lib */
    fNum = _Q15abs(fNum0);

    /* benchmark of fixed-point abs - libmathq15 */
    fNum = q15_abs(fNum0);
    
    Nop();
    
    return 0;
}
