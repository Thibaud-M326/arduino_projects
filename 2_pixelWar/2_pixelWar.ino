// pour ce projet je souhaite realiser une petit jeux style space invader
// je dois faire plusieur chose pour ça

//d'abord je dois creer un petit vaiseau spatial en 4 bloc 
//   +
//  +++

//de ce vaisseau depuis le canon je dois envoyer un boulet

//ensuite je doit creer deux ligne de pixel a casser en face du vaisseau
//a chaque fois que le boulet va toucher un pixel du haut celui la va disparaitre
//et laisser le boulet passer a celui situé derriere

#include "JoystickLib.h"
#include "LedControl.h"
#include "ship.h"

const int pow_pin = 5; // digital pin powering joystick 5v
const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = 0; // analog pin connected to X output
const int Y_pin = 1; // analog pin connected to Y output

LedControl lc = LedControl(12, 10, 11, 1);
//shipGun Max 64 Min 2
int shipGun = 64;
//shipBody Max 224 Min 4
int shipBody = 128;
//change ship speed
unsigned long delayMoveShip = 60;
int delayMoveShipAdd = delayMoveShip;
//change shoot speed
unsigned long delayShoot = 20;
unsigned long delayClear = delayShoot * 2;
int delayShootAdd = delayShoot * 2;
unsigned long currentTime = 0;
int bullet = 5;
int firingLine = shipGun;
//army line
int armyBackline = 126;
int armyFrontline = 126;

void setup()
{
    pinMode(pow_pin, OUTPUT);
    digitalWrite(pow_pin, HIGH);
    pinMode(SW_pin, INPUT);
    digitalWrite(SW_pin, HIGH);
    Serial.begin(9600);

    lc.shutdown(0, false);
    lc.setIntensity(0, 1);
    lc.clearDisplay(0);
    printShip(lc, shipGun, shipBody);
}

void loop()
{
    int X_direction;
    int Y_direction;

    X_direction = 0;
    Y_direction = 0;
    currentTime = millis();
    readDirection(&X_direction, &Y_direction, SW_pin, X_pin, Y_pin);
    moveShip(lc, &shipGun, &shipBody, X_direction, currentTime, &delayMoveShip, delayMoveShipAdd);
    shoot(lc, shipGun, &firingLine ,&bullet, currentTime, &delayShoot, &delayClear, delayShootAdd);
    printArmy(lc, &armyBackline, &armyFrontline, &firingLine, &bullet);
}
