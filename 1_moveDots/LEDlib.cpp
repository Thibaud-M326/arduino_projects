#include "LEDlib.h"
#include "LedControl.h"

void writeStart(int X_dot, LedControl lc)
{
    lc.setRow(0, 0, X_dot + X_dot / 2);
    lc.setRow(0, 1, X_dot + X_dot / 2);
}

void moveDot(int X_direction, int Y_direction, int *X_dot, int *Y_dot, LedControl lc)
{
    if(X_direction == -1 && *X_dot != 128)
    {
        lc.clearDisplay(0);
        *X_dot = *X_dot * 2;
        lc.setRow(0, *Y_dot, *X_dot + *X_dot / 2);
        lc.setRow(0, *Y_dot + 1, *X_dot + *X_dot / 2);
    }
    if(X_direction == 1 && *X_dot != 2)
    {
        lc.clearDisplay(0);
        *X_dot = *X_dot / 2;
        lc.setRow(0, *Y_dot, *X_dot + *X_dot / 2);
        lc.setRow(0, *Y_dot + 1, *X_dot + *X_dot / 2);
    }

    if(Y_direction == -1 && *Y_dot > 0)
    {
        lc.clearDisplay(0);
        *Y_dot = *Y_dot - 1;
        lc.setRow(0, *Y_dot, *X_dot + *X_dot / 2);
        lc.setRow(0, *Y_dot + 1, *X_dot + *X_dot / 2);
    }
    if(Y_direction == 1 && *Y_dot < 6)
    {
        lc.clearDisplay(0);
        *Y_dot = *Y_dot + 1;
        lc.setRow(0, *Y_dot, *X_dot + *X_dot / 2);
        lc.setRow(0, *Y_dot + 1, *X_dot + *X_dot / 2);
    }
}