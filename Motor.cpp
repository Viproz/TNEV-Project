/* 
 * File:   Motor.cpp
 * Author: viproz
 * 
 * Created on 15 avril 2015, 15:50
 */

#include "Motor.h"

Motor::Motor(int pinControl1, int pinControl2, int pinEnable) :
pinControl1(pinControl1), pinControl2(pinControl2), pinEnable(pinEnable) 
{
    pinMode(pinControl1, OUTPUT);
    pinMode(pinControl2, OUTPUT);
    pinMode(pinEnable, OUTPUT);
    
    digitalWrite(pinEnable, LOW);
}

Motor::setSpeed(int percent) {
    int motorSpeed = (float)percent / 100.0 * 255.0;
    
}
