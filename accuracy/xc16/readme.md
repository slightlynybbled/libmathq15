# Purpose #

To test the accurace of the function vs. floating-point equivalents.

# Method #

In the MPLAB X environment, the sumulator was used to export the values to a CSV file for post-processing.  The built-in assumption is that the floating point implementations provided in <math.c> are more accurate and are being used as the reference values.

# Notes #

There is a C file for each function tested and a CSV file for the results.  Where possible, every single number was tested and data saved.