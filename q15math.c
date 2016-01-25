#include "q15math.h"

double q15_to_dbl(q15_t num){
    return ((double)num)/((double)32768.0);
}

float q15_to_float(q15_t num){
    return ((float)num)/((float)32768.0);
}

int16_t q15_to_int(q15_t num){
    int16_t value = 0;
    
    if(num > 16383)
        value = 1;
    else if(num < -16383)
        value = -1;
    
    return value;
}

q15_t q15_from_dbl(double num){
    q15_t value;
    
    if(num > 0.99997)
        value = 32767;
    else if(num < -1.0)
        value = -32768;
    else{
        value = (q15_t)(num * 32768.0);
    }
    
    return value
}

q15_t q15_from_float(float num){
    q15_t value;
    
    if(num > 0.99997)
        value = 32767;
    else if(num < -1.0)
        value = -32768;
    else{
        value = (q15_t)(num * 32768.0);
    }
    
    return value
}

q15_t q15_from_int(int num){
    q15_t value = 0;
    
    if(num > 0)
        value = 32767;
    else if(num < 0)
        value = -32768;
    
    return value;
}

q15_t q15_mul(q15_t multiplicand, q15_t multiplier){
    uint32_t product = ((uint32_t)multiplicand * (uint32_t)multiplier) >> 16;
    return (q15_t)product;
}

q15_t q15_div(q15_t dividend, q15_t divisor){
    q15_t quotient;
    
	/* check to ensure dividend is smaller in magnitude
     * than the divisor */
	if(q15_abs(divisor) > q15_abs(dividend)){
		/* saturation: if signs are different,
         * then saturate negative */
		if((divisor & 0x8000) ^ (dividend & 0x8000)){
			quotient = -32768;
		}else{
			quotient = 32767;
		}
	}else{
		/* this is where you should insert the specific
         * division instruction for this processor – if present */
		quotient = dividend/divisor;
	}
    
	return quotient;
}

q15_t q15_add(q15_t addend, q15_t adder){
    int32_t result = (uint32_t)addend + (uint32_t)adder;
    
    if(result > 32767)          result = 32767;
    else if(result < -32768)    result = -32768;
    
    return (q15_t)result;
}

q15_t q15_abs(q15_t num){
    q15_t value = num;
    
    if(value < 0){
        if(value < -32767)  value = 32767;
        else                value = -value;
    }
    
    return value;
}
