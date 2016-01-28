#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "libmathq15.h"

int main()
{
    double largestError = 0;

    printf("------ accuracy test: libmathq15, q15_sqrt() ------\n");

    FILE *f;
    f = fopen("sqrt.csv", "w");

    int i;
    for(i = 0; i < 32767; i++){
        double dNum = ((double)i)/32767;
        double dSqrt = sqrt(dNum) * 32767;
        q15_t fSqrt = q15_sqrt(i);

        double error = abs(dSqrt - ((double)fSqrt));
        if(error > largestError)
            largestError = error;

        fprintf(f, "%d,%.6f,%d,%.4f\n", i, dSqrt, fSqrt,error);
    }

    fclose(f);

    printf("q15_sqrt largest error: %.4f%%", (100.0 * largestError/32767.0));

    return 0;
}
