/* 
 * File:   MotorSensor.cpp
 * Author: viproz
 * 
 * Created on 17 mai 2015, 12:22
 */

#include <stdint.h>
#include <Arduino.h>

#include "MotorSensor.h"

MotorSensor::MotorSensor(uint8_t pinPhoto) :
    pinPhoto(pinPhoto)
{
    intersections = 0;
}

MotorSensor::~MotorSensor() {
}

int MotorSensor::tick() {
    int value = analogRead(pinPhoto);
    if(abs(value - prevValue) > 600)
        intersections++;
    
    return intersections;
}