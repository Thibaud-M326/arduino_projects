/*
All function i created related to joystick control and reading
*/
#ifndef JoystickLib_h
#define Joystick_h

#if (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

//print the values ​​of switch x and y in real time
void printJoystick(int SW_pin, int X_pin, int Y_pin);

//print the direction name and value
void printDirection(int X_direction, int Y_direction);

//read the value of X and Y and assign a -1 || 1 value to X_direction and Y_direction
void readDirection(int *X_direction, int *Y_direction, int SW_pin, int X_pin, int Y_pin);

#endif