# Accuracy #

Using the <math.h> double as the standard, the accuracy of some functions is tested below.

## Platform: MINGW ##

### Standard Sine ###

| Table Width                   | 8-bit   | 7-bit   | 6-bit   | 5-bit   | 4-bit   |
|-------------------------------|---------|---------|---------|---------|---------|
| Ticks error (worst case)      | 5       | 5       | 6       | 12      | 41      |
| Percent vs. range             | 0.0076% | 0.0076% | 0.0091% | 0.0183% | 0.0626% |
| Memory Footprint - LUT(Bytes) | 512     | 256     | 128     | 64      | 32      |

### Fast Sine ###

The fast sine function has significantly more error, but doesn't involve interpolation.  A comparison of the <math.h> sine and the 4-bit fast sine can be found in '\accuracy\mingw\results\'.

| Table Width                   | 8-bit   | 7-bit   | 6-bit   | 5-bit   | 4-bit   |
|-------------------------------|---------|---------|---------|---------|---------|
| Ticks error (worst case)      | 201     | 402     | 804     | 1607    | 3211    |
| Percent vs. range             | 0.613%  | 1.23%   | 2.45%   | 4.90%   | 9.80%   |
| Memory Footprint - LUT(Bytes) | 512     | 256     | 128     | 64      | 32      |

### Square Root ###

The q15_sqrt() function is very accurate with input numbers ranging from 32767 (0.99997) down to about 100 (0.00305).  If the user will require square roots below this threshold value, then the user should probably use floating point methods or methods with higher resolutions.

The error of the q15_sqrt() function is non-linear and is characterized in '/accuracy/mingw/results/'.  The worst error is at an input of 0 and returns a value of 182 (0.00556) rather than 0.

## Platform: XC16 ##

The XC16 details are still being tabulated.  Current details are located in the xc16 directory.  Summary will be posted here when that is complete.

## Platform: MSP430 ##

The MSP430 results have not been started.
