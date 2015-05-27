/* 
 * File:   UltrasonicSensorCarriage.cpp
 * Author: viproz
 * 
 * Created on 17 mai 2015, 20:25
 */

#include "UltrasonicSensorCarriage.h"
#include "UltrasonicSensor.h"

#define PIN_SENSOR A0
#define PIN_SERVO 8

UltrasonicSensorCarriage::UltrasonicSensorCarriage()
{
    /*sensor = new UltrasonicSensor(PIN_SENSOR);
    servo.attach(PIN_SERVO);*/
}

UltrasonicSensorCarriage::~UltrasonicSensorCarriage() {
    //delete sensor;
}
