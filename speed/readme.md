### Speed Comparisons ###

At this time, I have only run this test on the AVR/arduino.  I am surprised at the performance of the floating-point library on the AVR.  Most of my background has been with the Microchip PIC product line and the performance of floating-point vs. fixed-point on that platform is very different.

#### AVR/Arduino UNO ####
|                      | Floating-Point | Fixed-Point |
|----------------------|----------------|-------------|
| Multiplication       | 9.4us          | 10.6us      |
| Division             | 28.4us         | 54.8us      |
| Addition/Subtraction | 8.2us          | 3.2us       |