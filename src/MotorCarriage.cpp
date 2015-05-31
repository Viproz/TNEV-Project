#include "MotorCarriage.h"

#define MOTOR1_CONTROL_PIN_1 13
#define MOTOR1_CONTROL_PIN_2 12
#define MOTOR1_ENABLE_PIN 11

#define MOTOR2_CONTROL_PIN_1 10
#define MOTOR2_CONTROL_PIN_2 8
#define MOTOR2_ENABLE_PIN 9

#define MOTOR1_SENSOR_PIN A2
#define MOTOR2_SENSOR_PIN A3

MotorCarriage::MotorCarriage() {
    rightMotor = new Motor(MOTOR1_CONTROL_PIN_1, MOTOR1_CONTROL_PIN_2, MOTOR1_ENABLE_PIN);
    leftMotor = new Motor(MOTOR2_CONTROL_PIN_1, MOTOR2_CONTROL_PIN_2, MOTOR2_ENABLE_PIN);
    
    rightSensor = new MotorSensor(MOTOR1_SENSOR_PIN);
    leftSensor = new MotorSensor(MOTOR2_SENSOR_PIN);
}

MotorCarriage::~MotorCarriage() {
    delete rightMotor;
    delete leftMotor;
    
    delete rightSensor;
    delete leftSensor;
}

/**
 * This will be used to calibrate the motors
 */
void MotorCarriage::calibrate() {
    //First step : Go forward
    leftMotor->setMaxVoltage(255);
    rightMotor->setMaxVoltage(255);
    setSpeed(100);
    int time = millis();
    while(true) {
        //With a timout of 10 sec
        if(millis() - time > 10000) {
            Logger::log("Calibration timeout");
            Logger::error();
            break;
        }
        if((rightSensor->tick() > 20 && leftSensor->tick() > 20)) {
            break;
        }
    }
    //Get the minimal number of ticks
    int minIntersections = 0;
    
    //Check to see if one turned more then the other
    if(rightSensor->getIntersections() > leftSensor->getIntersections()) {
        minIntersections = leftSensor->getIntersections();
        rightMotor->setMaxVoltage(255 * (leftSensor->getIntersections() / rightSensor->getIntersections()));
    } else {
        minIntersections = rightSensor->getIntersections();
        leftMotor->setMaxVoltage(255 * (rightSensor->getIntersections() / leftSensor->getIntersections()));
    }
    
    //Get the speed in cm/s of the robot d = intersections * (2pi / number of intersections of the wheel) * radius of the wheel
    maxSpeed = (float)minIntersections * 1.047 * 2 / ((float)(millis() - time) / 1000.0);
    //TODO: Change 1.047 (pi/3) * 2 (radius of the wheel) to a precalculated value
}

/**
 * Change the speed of the carriage
 * 
 * @param percent Speed in percent
 */
void MotorCarriage::setSpeed(int percent) {
    leftMotor->setSpeed(percent);
    rightMotor->setSpeed(percent);
}

/**
 * Make the carriage turn
 * 
 * Be carefull this function is blocking
 * 
 * @param degree Angle in degree to turn, in trigonometric direction
 * @param speedPercent
 */
void MotorCarriage::turn(int degree, int speedPercent) {
    //Both wheels will move
    //d = angle / 2 * pi * (dist between the two wheels) / 180 and t = d / v
    //TODO: precalculate 1/2 * pi * (dist between the two wheels) / 180
    float timeToMove = (abs(degree) * 0.123 / maxSpeed) / ((float)speedPercent / 100.0);
    
    float sign = 1;
    
    //Reverse the sign to move in the othrt direction
    if(degree < 0)
        sign = -1;
    
    //TODO: Find a way to be able to remove the delay
    rightMotor->setSpeed(speedPercent * sign);
    leftMotor->setSpeed(-1.0 * speedPercent * sign);
    delayMicroseconds(timeToMove * 1000.0);
    rightMotor->setSpeed(0);
    leftMotor->setSpeed(0);
}

/**
 * Moves the carriage to some distance
 * 
 * Be carefull this function is blocking
 * 
 * @param centimeters Distance to move
 * @param speedPercent Speed in percent
 */
void MotorCarriage::goDistance(int centimeters, int speedPercent) {
    //t = d / v
    float timeToMove = abs(centimeters) / maxSpeed / ((float)speedPercent / 100.0);
    
    //TODO: Find a way to be able to remove the delay
    setSpeed(speedPercent);
    delayMicroseconds(timeToMove * 1000.0);
    setSpeed(0);
}