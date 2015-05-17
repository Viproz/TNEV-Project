#ifndef MOTORCARRIAGE_H
#define	MOTORCARRIAGE_H
#include "Motor.h"
#include "MotorSensor.h"
#include "Logger.h"

class MotorCarriage {
public:
    MotorCarriage();
    virtual ~MotorCarriage();
    
    Motor* getRightMotor() { return rightMotor; }
    Motor* getLeftMotor() { return leftMotor; }
    
    void calibrate();
    
    void setSpeed(int percent);
    void turn(int degree, int speedPercent = 100);
    void goDistance(int centimeter, int speedPercent = 100);
    
private:
    Motor* rightMotor;
    Motor* leftMotor;
    
    MotorSensor* rightSensor;
    MotorSensor* leftSensor;
    
    float maxSpeed;
};

#endif	/* MOTORCARRIAGE_H */

