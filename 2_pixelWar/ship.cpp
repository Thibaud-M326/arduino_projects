/*
ship related functions
*/
#include "ship.h"
#include "LedControl.h"

void printShip(LedControl lc, int shipGun, int shipBody)
{
    shipBody = shipBody + (shipBody >> 1) + (shipBody >> 2);

    lc.setRow(0, 6, shipGun);
    lc.setRow(0, 7, shipBody);
}


void moveShip(LedControl lc, int *shipGun, int *shipBody, int XshipDirection, unsigned long currentTime, unsigned long *delayMoveShip, int delayMoveShipAdd)
{
    if(currentTime > *delayMoveShip)
    {
        if(XshipDirection == -1 && *shipBody < 128)
        {
            *shipGun = *shipGun << 1;
            *shipBody = *shipBody << 1;
        }
        if(XshipDirection == 1 && *shipBody > 4)
        {
            *shipGun = *shipGun >> 1;
            *shipBody = *shipBody >> 1;
        }
        printShip(lc, *shipGun, *shipBody);
        *delayMoveShip = currentTime + delayMoveShipAdd;
    }
}

void shoot(LedControl lc, int shipGun, int *firingLine, int *bullet, unsigned long currentTime, unsigned long *delayShoot, unsigned long *delayClear, int delayShootAdd)
{
    if(currentTime > *delayShoot && *bullet >= 0)
    {
        if(*bullet == 5)
        {
            *firingLine = shipGun;
        }
        lc.setRow(0, *bullet, *firingLine);
        *delayShoot = currentTime + delayShootAdd;
    }
    if(currentTime > *delayClear)
    {
        lc.setRow(0, *bullet, 0);
        *delayClear = currentTime + delayShootAdd;
        (*bullet)--;
    }
    if(*bullet == -1)
    {
        *bullet = 5;
    }
}

void printArmy(LedControl lc, int *armyBackline, int *armyFrontline, int *firingLine, int *bullet)
{
    int backline;
    int frontline;

    backline = 0;
    frontline = 1;
    if(*bullet == 1)
    {
        *armyFrontline -= *firingLine;
        *bullet = 5;
    }
    lc.setRow(0, frontline, *armyFrontline);
}