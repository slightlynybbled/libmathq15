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