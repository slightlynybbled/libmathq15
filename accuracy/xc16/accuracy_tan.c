/*
 * File:   accuracy_sine.c
 * Author: Jason
 *
 */


// PIC24FJ32GA002 Configuration Bit Settings

// 'C' source line config statements

#include <xc.h>
#include <stdio.h>
#include <math.h>
#include "libmathq15.h"

// CONFIG2
#pragma config POSCMOD = NONE           // Primary Oscillator Select (Primary oscillator disabled)
#pragma config I2C1SEL = PRI            // I2C1 Pin Location Select (Use default SCL1/SDA1 pins)
#pragma config IOL1WAY = ON             // IOLOCK Protection (Once IOLOCK is set, cannot be changed)
#pragma config OSCIOFNC = OFF           // Primary Oscillator Output Function (OSC2/CLKO/RC15 functions as CLKO (FOSC/2))
#pragma config FCKSM = CSDCMD           // Clock Switching and Monitor (Clock switching and Fail-Safe Clock Monitor are disabled)
#pragma config FNOSC = FRCDIV           // Oscillator Select (Fast RC Oscillator with Postscaler (FRCDIV))
#pragma config SOSCSEL = SOSC           // Sec Oscillator Select (Default Secondary Oscillator (SOSC))
#pragma config WUTSEL = LEG             // Wake-up timer Select (Legacy Wake-up Timer)
#pragma config IESO = ON                // Internal External Switch Over Mode (IESO mode (Two-Speed Start-up) enabled)

// CONFIG1
#pragma config WDTPS = PS32768          // Watchdog Timer Postscaler (1:32,768)
#pragma config FWPSA = PR128            // WDT Prescaler (Prescaler ratio of 1:128)
#pragma config WINDIS = ON              // Watchdog Timer Window (Standard Watchdog Timer enabled,(Windowed-mode is disabled))
#pragma config FWDTEN = OFF             // Watchdog Timer Enable (Watchdog Timer is disabled)
#pragma config ICS = PGx1               // Comm Channel Select (Emulator EMUC1/EMUD1 pins are shared with PGC1/PGD1)
#pragma config GWRP = OFF               // General Code Segment Write Protect (Writes to program memory are allowed)
#pragma config GCP = OFF                // General Code Segment Code Protect (Code protection is disabled)
#pragma config JTAGEN = ON              // JTAG Port Enable (JTAG port is enabled)



int main(void) {
    /* print column headers */
    printf("float_val,fixed_val,float_tan,fixed_tan,scaled_float,fixed_err\n");
    
    q16angle_t q16_angle_num = 0;
    
    while(q16_angle_num < 65535){
        /* convert fixed-point to radians */
        float float_val = (float)q16_angle_num * 2.0 * 3.14159/65536.0;
        
        /* calculate the sine */
        float float_tan = tan(float_val);
        q15_t fixed_tan = q15_tan(q16_angle_num);
        
        /* scale the floating-point to fixed-point for comparison */
        float scaled_tan = (float_tan * 32768.0);
        
        /* calculate the error in points */
        float fixed_err = scaled_tan - (float)fixed_tan;
        
        /* print relevant values to the screen */
        printf("%f,%.0f,%f,%d,%.0f,%f\n", 
                (double)float_val, 
                (double)q16_angle_num, 
                (double)float_tan, 
                fixed_tan,
                (double)scaled_tan,
                (double)fixed_err);
        
        q16_angle_num++;
    }
    
    Nop();
    
    while(1);

    return 0;
}

