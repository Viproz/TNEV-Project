#include "MotorCarriage.h"

#define MOTOR1_CONTROL_PIN_1 13
#define MOTOR1_CONTROL_PIN_2 12
#define MOTOR1_ENABLE_PIN 11

#define MOTOR2_CONTROL_PIN_1 10
#define MOTOR2_CONTROL_PIN_2 8
#define MOTOR2_ENABLE_PIN 9

#define MOTOR1_SENSOR_PIN A5
#define MOTOR2_SENSOR_PIN A4

MotorCarriage::MotorCarriage() {
    rightSensor = new MotorSensor(MOTOR1_SENSOR_PIN);
    leftSensor = new MotorSensor(MOTOR2_SENSOR_PIN);
    
    rightMotor = new Motor(MOTOR1_CONTROL_PIN_1, MOTOR1_CONTROL_PIN_2, MOTOR1_ENABLE_PIN, rightSensor);
    leftMotor = new Motor(MOTOR2_CONTROL_PIN_1, MOTOR2_CONTROL_PIN_2, MOTOR2_ENABLE_PIN, leftSensor);
    
    
    maxSpeed = 28;
    
    setSpeed(0);
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
    rightSensor->reset();
    leftSensor->reset();
    setSpeed(100);
    unsigned long time = millis();
    Logger::log("there");
    while(true) {
        //With a timout of 10 sec
        if(millis() - time > 15000) {
            Logger::log("Calibration timeout");
            Logger::error();
            break;
        }
        if((rightSensor->tick() >= 20) & (leftSensor->tick() >= 20)) {
            break;
        }
    }
    setSpeed(0);
    //Get the minimal number of ticks
    int minIntersections = 0;
    
    //Check to see if one turned more then the other
    if(rightSensor->getIntersections() > leftSensor->getIntersections()) {
        minIntersections = leftSensor->getIntersections();
        rightMotor->setMaxVoltage(255.0 * ((float)leftSensor->getIntersections() / (float)rightSensor->getIntersections()));
        Logger::log(255.0 * ((float)leftSensor->getIntersections() / (float)rightSensor->getIntersections()));
    } else {
        minIntersections = rightSensor->getIntersections();
        leftMotor->setMaxVoltage(255.0 * ((float)rightSensor->getIntersections() / (float)leftSensor->getIntersections()));
        Logger::log(255.0 * ((float)rightSensor->getIntersections() / (float)leftSensor->getIntersections()));
    }
    
    //Get the speed in cm/s of the robot d = intersections * (2pi / number of intersections of the wheel) * radius of the wheel
    maxSpeed = (float)minIntersections * 19.415 / ((float)(millis() - time) / 1000.0);
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
    //d = angle / 2 * pi * (dist between the two wheels) / 180
    
    float sign = 1;
    
    //Reverse the sign to move in the othrt direction
    if(degree < 0)
        sign = -1;
    
    int d = (float)degree * 1.23;
    
    rightMotor->goDistance(d * sign);
    leftMotor->goDistance(-1 * d * sign);
    
    while(rightMotor->tick() | leftMotor->tick()) {
        //do nothing right now
    }
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
    
    rightMotor->goDistance(centimeters, speedPercent);
    leftMotor->goDistance(centimeters, speedPercent);
    while(rightMotor->tick() | leftMotor->tick()) {
        //do nothing right now
    }
    
    
    /*//t = d / v
    float timeToMove = abs(centimeters) / maxSpeed / ((float)speedPercent / 100.0);
    
    int sign = 1;
    if(centimeters < 0)
        sign = -1;
    
    setSpeed(speedPercent * sign);
    delay(timeToMove * 1000.0);
    setSpeed(0);*/
}