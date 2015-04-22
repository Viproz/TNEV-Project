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
    
    if(motorSpeed < 0) {
        digitalWrite(pinControl1, LOW);
        digitalWrite(pinControl2, HIGH);
    } else {
        digitalWrite(pinControl1, HIGH);
        digitalWrite(pinControl2, LOW);
    }
    
    analogWrite(pinEnable, motorSpeed);
}
