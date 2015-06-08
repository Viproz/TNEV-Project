/* 
 * File:   Servo.cpp
 * Author: viproz
 * 
 * Created on 4 juin 2015, 15:01
 */

#include <stdio.h>
#include <Arduino.h>

#include "Servo.h"
#include "Logger.h"

Servo::Servo(uint8_t pin) : 
    servoPin(pin) {
    pinMode(pin, OUTPUT);
}

Servo::~Servo() {
}

void Servo::write(int angle) {
    //In total it lasts 100ms
    unsigned long time = millis();
    int micro = 5.56 * (float)angle + 1000;
    
    while(millis() - time < 100) {
        //Logger::log("therdsfe");
        digitalWrite(servoPin, HIGH);
        delayMicroseconds(micro);
        digitalWrite(servoPin, LOW);
        delayMicroseconds(20000);
    }
}