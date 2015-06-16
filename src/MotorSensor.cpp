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
    
    if(value > 800 && millis() - prevDetection > 300) {
        prevDetection = millis();
        intersections++;
        Logger::log(intersections);
    }
    
    return intersections;
}

/**
 * 
 * @return Angle of the wheel
 */
int MotorSensor::getAngle() {
    int value = (analogRead(pinContact) + analogRead(pinContact) + analogRead(pinContact)) / 3;
    Logger::log("Valiue");
    Logger::log(value);
    Logger::log(map(value, 0, 1024, 0, 360));
    
    return map(value, 0, 1024, 0, 360);
}