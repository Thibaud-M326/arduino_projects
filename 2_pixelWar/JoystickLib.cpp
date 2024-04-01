/*
Function defined in JoystickControl.h
*/

#include "JoystickLib.h"

void printJoystick(int SW_pin, int X_pin, int Y_pin)
{
    Serial.print("Switch:  ");
    Serial.print(digitalRead(SW_pin));
    Serial.print("\n");
    Serial.print("X-axis: ");
    Serial.print(analogRead(X_pin));
    Serial.print("\n");
    Serial.print("Y-axis: ");
    Serial.println(analogRead(Y_pin));
    Serial.print("\n\n");
}

void printDirection(int X_direction, int Y_direction)
{
    if(X_direction == -1)
    {
        Serial.print("LEFT ");
        Serial.print(X_direction);
    }
    if(X_direction == 1)
    {
        Serial.print("RIGHT ");
        Serial.print(X_direction);
    }

    if(Y_direction == -1)
    {
        Serial.print("UP ");
        Serial.print(Y_direction);
    }
    if(Y_direction == 1)
    {
        Serial.print("BOTTOM ");
        Serial.print(Y_direction);
    }
}

void readDirection(int *X_direction, int *Y_direction, int SW_pin, int X_pin, int Y_pin)
{
    int X;
    int Y;
    int SW;

    SW = analogRead(SW_pin);
    X = analogRead(X_pin);
    Y = analogRead(Y_pin);
    if(X <= 400)
    {
        *X_direction = -1;
    }
    if(X >= 600)
    {
        *X_direction = 1;
    }

    if(Y <= 400)
    {
        *Y_direction = -1;
    }
    if(Y >= 600)
    {
        *Y_direction = 1;
    }
}