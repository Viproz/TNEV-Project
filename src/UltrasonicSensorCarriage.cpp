/* 
 * File:   UltrasonicSensorCarriage.cpp
 * Author: viproz
 * 
 * Created on 17 mai 2015, 20:25
 */

#include "UltrasonicSensorCarriage.h"
#include "UltrasonicSensor.h"
#include "Logger.h"

#define PIN_SENSOR 3
#define PIN_SERVO 7

UltrasonicSensorCarriage::UltrasonicSensorCarriage()
{
    sensor = new UltrasonicSensor(PIN_SENSOR);
    servo.attach(PIN_SERVO);
}

UltrasonicSensorCarriage::~UltrasonicSensorCarriage() {
    delete sensor;
}

void UltrasonicSensorCarriage::findNearest(int& angle, int& distance) {
    //We will sweep 144° 18° by 18°
    
    int servoAngle = 18;
    int nearestObject = 1000;
    int firstAngle = 0;
    int lastAngle = 0;
    while(servoAngle < 180) {
        servo.write(servoAngle);
        delay(100);
        
        int objectDist = sensor->getDistance();
        Logger::log(objectDist);
        if(nearestObject - objectDist > 15) {
            firstAngle = servoAngle;
            lastAngle = 0;
            nearestObject = objectDist;
        } else if(objectDist - nearestObject > 15 && lastAngle == 0) {
            lastAngle = servoAngle;
        }
        
        servoAngle += 18;
    }
    if(lastAngle == 0)
        lastAngle = servoAngle;
    
    angle = (firstAngle + lastAngle) / 2;
    distance = nearestObject;
}

void UltrasonicSensorCarriage::reset() {
    servo.write(90);
}