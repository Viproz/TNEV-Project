#include "Motor.h"

Motor::Motor(int pinControl1, int pinControl2, int pinEnable) :
pinControl1(pinControl1), pinControl2(pinControl2), pinEnable(pinEnable) 
{
    //Inititialize pins
    pinMode(pinControl1, OUTPUT);
    pinMode(pinControl2, OUTPUT);
    pinMode(pinEnable, OUTPUT);
    
    //Make sure the motor is stopped
    digitalWrite(pinEnable, LOW);
}

Motor::setSpeed(int percent) {
    //For now simple conversion to 0 -> 255 later we may add calibration
    int motorSpeed = (float)percent / 100.0 * 255.0;
    digitalWrite(pinEnable, motorSpeed);
}
