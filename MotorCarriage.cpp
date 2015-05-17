#include "MotorCarriage.h"

#define MOTOR1_CONTROL_PIN_1 2
#define MOTOR1_CONTROL_PIN_2 3
#define MOTOR1_ENABLE_PIN 9

#define MOTOR2_CONTROL_PIN_1 2
#define MOTOR2_CONTROL_PIN_2 3
#define MOTOR2_ENABLE_PIN 9

#define MOTOR1_SENSOR_PIN A0
#define MOTOR2_SENSOR_PIN A1

MotorCarriage::MotorCarriage() {
    rightMotor = new Motor(MOTOR1_CONTROL_PIN_1, MOTOR1_CONTROL_PIN_2, MOTOR1_ENABLE_PIN);
    leftMotor = new Motor(MOTOR2_CONTROL_PIN_1, MOTOR2_CONTROL_PIN_2, MOTOR2_ENABLE_PIN);
    
    rightSensor = new MotorSensor(MOTOR1_SENSOR_PIN);
    leftSensor = new MotorSensor(MOTOR2_SENSOR_PIN);
}

MotorCarriage::~MotorCarriage() {
    delete rightMotor;
    delete leftMotor;
}

void MotorCarriage::calibrate() {
    //First step : Go forward
    setSpeed(100);
    int time = millis();
    while(true) {
        //With a timout of 10 sec
        if((rightSensor->tick() > 20 && leftSensor->tick() > 20) || millis() - time > 10000)
            break;
    }
    //Check to see if one turned more then the other
    if(rightSensor->getIntersections() > leftSensor->getIntersections())
        rightMotor->setMaxVoltage(255 * (leftSensor->getIntersections() / rightSensor->getIntersections()));
    else
        leftMotor->setMaxVoltage(255 * (rightSensor->getIntersections() / leftSensor->getIntersections()));
}

void MotorCarriage::setSpeed(int percent) {
    leftMotor->setSpeed(percent);
    rightMotor->setSpeed(percent);
}

void MotorCarriage::turn(int degree) {
    //Maybe do something with a gyroscope ?
}