#ifndef Ship_h
#define Ship_h

#if (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

#include "LedControl.h"

//print initial ship position
void printShip(LedControl lc, int shipGun, int shipBody);

//move ship through joystick data
void moveShip(LedControl lc, int *shipGun, int *shipBody, int XshipDirection, unsigned long currentTime, unsigned long *delayMoveShip, int delayMoveShipAdd);

//shoot bullet inline with current firingline with a time delay loop
void shoot(LedControl lc, int shipGun, int *firingLine, int *bullet, unsigned long currentTime, unsigned long *delayShoot, unsigned long *delayClear, int delayShootAdd);

//print army current state every loop
void printArmy(LedControl lc, int *armyBackline, int *armyFrontline);

//when a bullet hit a soldier, remove it from armyLines tab
void killSoldier(LedControl lc, int *armyBackline, int *armyFrontline, int firingLine, int *bullet);

#endif