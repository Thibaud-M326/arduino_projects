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
            Serial.print("SHOOT!!!");
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

void printArmy(LedControl lc, int *armyBackline, int *armyFrontline)
{
    int armyLineSize = 7;
    int backline = 0;
    int frontline = 1;
    int armyBacklineSoldiers = 0;
    int armyFrontlineSoldiers = 0;
    while(armyLineSize >= 0)
    {
        armyBacklineSoldiers += armyBackline[armyLineSize];
        armyFrontlineSoldiers += armyFrontline[armyLineSize];
        armyLineSize--;
    }
    if(armyBacklineSoldiers != 0)
    {
        lc.setRow(0, backline, armyBacklineSoldiers);
    }
    if(armyFrontlineSoldiers != 0)
    {
        lc.setRow(0, frontline, armyFrontlineSoldiers);
    }
}

void killSoldier(LedControl lc, int *armyBackline, int *armyFrontline, int firingLine, int *bullet)
{
    int armyLineSize = 7;
    int backline = 0;
    int frontline = 1;
    while(armyLineSize >= 0)
    {
        if(armyFrontline[armyLineSize] == firingLine && *bullet == 1)
        {
            armyFrontline[armyLineSize] = 0; 
            *bullet = 5;
        }
        else if(armyBackline[armyLineSize] == firingLine && *bullet == 0)
        {
            armyBackline[armyLineSize] = 0;
        }
        armyLineSize--;
    }
}