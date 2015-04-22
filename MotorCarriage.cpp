#include "MotorCarriage.h"

#define MOTOR1_CONTROL_PIN_1 2
#define MOTOR1_CONTROL_PIN_2 3
#define MOTOR1_ENABLE_PIN 9

#define MOTOR2_CONTROL_PIN_1 2
#define MOTOR2_CONTROL_PIN_2 3
#define MOTOR2_ENABLE_PIN 9

MotorCarriage::MotorCarriage() {
    rightMotor = new Motor(MOTOR1_CONTROL_PIN_1, MOTOR1_CONTROL_PIN_2, MOTOR1_ENABLE_PIN);
    leftMotor = new Motor(MOTOR2_CONTROL_PIN_1, MOTOR2_CONTROL_PIN_2, MOTOR2_ENABLE_PIN);
}

MotorCarriage::~MotorCarriage() {
    delete rightMotor;
    delete leftMotor;
}

void MotorCarriage::setSpeed(int percent) {
    leftMotor->setSpeed(percent);
    rightMotor->setSpeed(percent);
}

void MotorCarriage::turn(int degree) {
    //Maybe do something with a gyroscope ?
}