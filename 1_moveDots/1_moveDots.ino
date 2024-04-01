//ce projet a pour but de faire bouger
//un point sur la matrice LED 8x8 grace au joystick 
//connecté au arduino

//je dois d'abord verifier que l'arduino peut prendre les
//2 module en meme temps.

//ensuite je dois recuperer les valeur du module jostick 
//avec une tare pour ne pas qu'il soit trop sensible

//je dois en suite permettre qu'a la lecture d'une direction
//le point affiché sur l'arduino se deplace de 1 en x ou y

//j'ai besoin de la librairie 
#include "LedControl.h"
#include "JoystickLib.h"
#include "LEDlib.h"

const int pow_pin = 5; // digital pin powering joystick 5v
const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = 0; // analog pin connected to X output
const int Y_pin = 1; // analog pin connected to Y output

LedControl lc = LedControl(12, 10, 11, 1);
int X_dot = 128;
int Y_dot = 0;

void setup() {
    pinMode(pow_pin, OUTPUT);
    digitalWrite(pow_pin, HIGH);
    pinMode(SW_pin, INPUT);
    digitalWrite(SW_pin, HIGH);
    Serial.begin(9600);

    lc.shutdown(0, false);
    lc.setIntensity(0, 1);
    lc.clearDisplay(0);
    writeStart(X_dot, lc);
}

void loop() {
    int X_direction;
    int Y_direction;

    X_direction = 0;
    Y_direction = 0;
    printJoystick(SW_pin, X_pin, Y_pin);
    readDirection(&X_direction, &Y_direction, SW_pin, X_pin, Y_pin);
    printDirection(X_direction, Y_direction);
    moveDot(X_direction, Y_direction, &X_dot, &Y_dot, lc);
    delay(70);
}