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
    prevDetection = 0;
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
    
    if(value > 800 && millis() - prevDetection > 100) {
        prevDetection = millis();
        intersections++;
        Logger::log(intersections);
    }
    
    return intersections;
}