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

int MotorSensor::tick(HardwareSerial* Serial) {
    int value = analogRead(pinPhoto);
    Serial->println("Thing");
    Serial->println(prevValue);
    Serial->println(value);
    if(abs(value - prevValue) > 200) {
        intersections++;
        prevValue = value;
        //Logger::log("Tick");
        //Logger::log(intersections);
    }
    
    return intersections;
}