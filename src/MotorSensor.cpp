/* 
 * File:   MotorSensor.cpp
 * Author: viproz
 * 
 * Created on 17 mai 2015, 12:22
 */

#include <stdint.h>
#include <Arduino.h>

#include "MotorSensor.h"

MotorSensor::MotorSensor(uint8_t pinContact) :
    pinContact(pinContact)
{
    intersections = 0;
    toGround = false;
}

MotorSensor::~MotorSensor() {
}

/**
 * Reset the counter
 */
void MotorSensor::reset() { 
    intersections = 0; 
}

/**
 * Will read the sensor to count intersections
 * 
 * @return Numbers of intersections passed since the begining
 */
int MotorSensor::tick() {
    int value = analogRead(pinContact);
    
    if((value > 800 && toGround) || (value < 200 && !toGround)) {
        toGround = !toGround;
        intersections++;
    }
    
    return intersections;
}