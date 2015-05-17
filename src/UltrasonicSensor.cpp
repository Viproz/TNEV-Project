/* 
 * File:   UltrasonicSensor.cpp
 * Author: viproz
 * 
 * Created on 17 mai 2015, 20:26
 */

#include "UltrasonicSensor.h"

UltrasonicSensor::UltrasonicSensor(uint8_t pinSIG) :
    pinSIG(pinSIG)
{
}

UltrasonicSensor::~UltrasonicSensor() {
}

int UltrasonicSensor::getDistance() {
    // establish variables for duration of the ping, 
    // and the distance result in inches and centimeters:
    unsigned long duration;
    
    // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
    // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
    pinMode(pinSIG, OUTPUT);
    digitalWrite(pinSIG, LOW);
    delayMicroseconds(2);
    digitalWrite(pinSIG, HIGH);
    delayMicroseconds(5);
    digitalWrite(pinSIG, LOW);
    
    // The same pin is used to read the signal from the PING))): a HIGH
    // pulse whose duration is the time (in microseconds) from the sending
    // of the ping to the reception of its echo off of an object.
    pinMode(pinSIG, INPUT);
    duration = pulseIn(pinSIG, HIGH);
    
    //Return the value in cm
    return duration / 29 / 2;
}