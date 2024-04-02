#ifndef Ship_h
#define Ship_h

#if (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

#include "LedControl.h"

void printShip(LedControl lc, int shipGun, int shipBody);

void moveShip(LedControl lc, int *shipGun, int *shipBody, int XshipDirection, unsigned long currentTime, unsigned long *delayMoveShip, int delayMoveShipAdd);

void shoot(LedControl lc, int shipGun, int *firingLine, int *bullet, unsigned long currentTime, unsigned long *delayShoot, unsigned long *delayClear, int delayShootAdd);

void printArmy(LedControl lc, int *armyBackline, int *armyFrontline, int *firingLine, int *bullet);

#endif