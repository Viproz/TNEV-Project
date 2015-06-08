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
    servo = new Servo(PIN_SERVO);
}

UltrasonicSensorCarriage::~UltrasonicSensorCarriage() {
    delete sensor;
}

void UltrasonicSensorCarriage::findNearest(int& angle, int& distance) {
    //We will sweep 144° 9° by 9°
    
#define SENSOR_RESOLUTION 9
    
    int servoAngle = SENSOR_RESOLUTION;
    int nearestObject = 1000;
    int firstAngle = 0;
    int lastAngle = 0;
    while(servoAngle < 180) {
        servo->write(servoAngle);
        
        int objectDist = sensor->getDistance();
        Logger::log(objectDist);
        if(nearestObject - objectDist > 15) {
            firstAngle = servoAngle;
            lastAngle = 0;
            nearestObject = objectDist;
        } else if(objectDist - nearestObject > 15 && lastAngle == 0) {
            lastAngle = servoAngle;
        }
        
        servoAngle += SENSOR_RESOLUTION;
    }
    if(lastAngle == 0)
        lastAngle = servoAngle;
    
    angle = (firstAngle + lastAngle) / 2;
    distance = nearestObject;
}

int UltrasonicSensorCarriage::getDistance() {
    return sensor->getDistance();
}
void UltrasonicSensorCarriage::reset() {
    servo->write(90);
}