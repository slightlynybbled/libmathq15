### Speed Comparisons ###

At this time, I have only run this test on the AVR/arduino.  I am surprised at the performance of the floating-point library on the AVR.  Most of my background has been with the Microchip PIC product line and the performance of floating-point vs. fixed-point on that platform is very different.

#### AVR/Arduino UNO ####
|                      | Floating-Point | Fixed-Point |
|----------------------|----------------|-------------|
| Multiplication       | 9.4us          | 10.6us      |
| Division             | 28.4us         | 54.8us      |
| Addition/Subtraction | 8.2us          | 3.2us       |

#### PIC24 and dsPIC ####

My apologies for mixing standards (micro-seconds above, cycles here), but I know how to use the microchip debugger and I don't know how to use the AVR Studio debugger.  Having said that, I have hand-tuned some of the most common fixed-point operations to work on the 24-bit instruction set from Microchip.  Below are the results.  The methods used for hand-tuning could have taken advantage of the DSP or made other assumptions about the calling functions in order to make the code somewhat more efficient, but the code - as written - does certain bounds checking and saturation which do require some cycles to perform.

I have also taken a moment to compare - where possible - the equivalent function in Microchip's internal library (provided in 'libq.h' and 'libq-elf.a').  The microchip-provided functions are slightly more efficient, but the source is not directly available.  One could look at the disassembly listing and go through lots of effort to squeeze the last cycle out of it, but I suspect that our efforts are better spent elsewhere.

|                | float        | Microchip fixed-point lib | q15_t     |
|----------------|--------------|---------------------------|-----------|
| Multiplication | 156 cycles   | not provided              | 12 cycles |
| Division       | 494 cycles   | not provided              | 59 cycles |
| Addition       | 184 cycles   | 12 cycles                 | 13 cycles |
| Absolute Value | not provided | 8 cycles                  | 11 cycles |