#include "libmathq15.h"
#include <avr/io.h>
#include <util/delay.h>

#define FLOAT_PIN DDD2
#define FIXED_PIN DDD4

float dNum0 = 0.0, dNum1 = 0.0, dNum = 0.0;
q15_t fNum0 = 0, fNum1 = 0, fNum = 0;

void setup() {
  Serial.begin(9600);
  
  // put your setup code here, to run once:
  DDRD |= _BV(FLOAT_PIN);
  DDRD |= _BV(FIXED_PIN);
  
  randomSeed(analogRead(0));
}

void loop() {
  /**********************************************/
  /* benchmark of floating-point multiplication */
  dNum0 = ((float)random(1000) * 0.002) - 1.0;
  dNum1 = ((float)random(1000) * 0.002) - 1.0;
  
  PORTD |= _BV(FLOAT_PIN);
  dNum = dNum0 * dNum1;
  PORTD &= ~_BV(FLOAT_PIN);
  
  /* benchmark of fixed-point multiplication */
  fNum0 = (q15_t)(dNum0 * 32767);
  fNum1 = (q15_t)(dNum1 * 32767);
  
  PORTD |= _BV(FIXED_PIN);
  fNum = q15_mul(fNum0, fNum1);
  PORTD &= ~_BV(FIXED_PIN);
  
  /**********************************************/
  /* benchmark of floating-point division */
  dNum1 = ((float)random(1000) * 0.002) - 1.0;
  dNum0 = dNum1 * 0.5;  // should be lower in magnitude than dDum1
  
  PORTD |= _BV(FLOAT_PIN);
  dNum = dNum0 / dNum1;
  PORTD &= ~_BV(FLOAT_PIN);
  
  /* benchmark of fixed-point division */
  fNum0 = (q15_t)(dNum0 * 32767);
  fNum1 = (q15_t)(dNum1 * 32767);
  
  PORTD |= _BV(FIXED_PIN);
  fNum = q15_div(fNum0, fNum1);
  PORTD &= ~_BV(FIXED_PIN);
  
  /**********************************************/
  /* benchmark of floating-point addition */
  dNum1 = ((float)random(1000) * 0.002) - 1.0;
  dNum0 = dNum1 * 0.5;
  
  PORTD |= _BV(FLOAT_PIN);
  dNum = dNum0 + dNum1;
  PORTD &= ~_BV(FLOAT_PIN);
  
  /* benchmark of fixed-point division */
  fNum0 = (q15_t)(dNum0 * 32767);
  fNum1 = (q15_t)(dNum1 * 32767);
  
  PORTD |= _BV(FIXED_PIN);
  fNum = q15_add(fNum0, fNum1);
  PORTD &= ~_BV(FIXED_PIN);
  
  Serial.print(dNum0);
  Serial.print(" x ");
  Serial.print(dNum1);
  Serial.print(" = ");
  Serial.print(dNum);
  Serial.print("\n");
  
  Serial.print(fNum0);
  Serial.print(" x ");
  Serial.print(fNum1);
  Serial.print(" = ");
  Serial.print(fNum);
  Serial.print("\n\n");
}
