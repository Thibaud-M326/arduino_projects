#ifndef LEDlib_h
#define LEDlib_h 

#if (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

#include "LedControl.h"

//create a basic 2*2 pixel bloc starting x = 128 && y = 0
void writeStart(int X_dot, LedControl lc);

//move pixel on LED module
void moveDot(int X_direction, int Y_direction, int *X_dot, int *Y_dot, LedControl lc);

#endif