/* The purpose of this file is to test the accuracy of the
 * libmathq15 library of math functions.  The 'math.h' double
 * precisions are being used as the reference. In addition
 * to printing the overall accuracy, this fill will generate
 * CSV files which reflect the results at each point for
 * plotting or other archiving methods */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include "libmathq15.h"

#define PI 3.14159265

int main(){
    double largestError = 0;

    printf("------ accuracy test: libmathq15, q15_sqrt() ------\n");

    FILE *f;
    f = fopen("sqrt.csv", "w");

    /* create a file header */
    fprintf(f, "number,sqrt(),q15_sqrt(),error\n");

    q16angle_t i;
    for(i = 0; i < 32767; i++){
        double dNum = ((double)i)/32767;
        double dSqrt = sqrt(dNum) * 32767;
        q15_t fSqrt = q15_sqrt(i);

        double error = abs(dSqrt - ((double)fSqrt));
        if(error > largestError)
            largestError = error;

        fprintf(f, "%d,%.6f,%d,%.4f\n", i, dSqrt, fSqrt, error);
    }

    fclose(f);

    printf("q15_sqrt largest error: %.0f\n\n", largestError);

    printf("------ accuracy test: libmathq15, q15_sin() ------\n");

    largestError = 0;
    f = fopen("sin.csv", "w");

    /* create a file header */
    fprintf(f, "angle,sin(),q15_sin(),error\n");

    for(i = 0; i < 65535; i++){
        double dAngle;
        dAngle = ((double)i)/65536.0;

        double floatValue = sin(dAngle * 2 * PI) * 32768;
        double fixedValue = (double)q15_sin(i);

        double error = abs(floatValue - fixedValue);
        if(error > largestError)
            largestError = error;

        fprintf(f, "%0.6f,%0.4f,%d,%f.4\n", dAngle, floatValue, q15_sin(i), error);
    }

    fclose(f);

    printf("q15_sin largest error: %0.0f\n", largestError);

    return 0;
}

