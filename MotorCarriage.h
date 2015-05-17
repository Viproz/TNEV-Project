#ifndef MOTORCARRIAGE_H
#define	MOTORCARRIAGE_H
#include "Motor.h"
#include "MotorSensor.h"

class MotorCarriage {
public:
    MotorCarriage();
    virtual ~MotorCarriage();
    
    Motor* getRightMotor() { return rightMotor; }
    Motor* getLeftMotor() { return leftMotor; }
    
    void calibrate();
    
    void setSpeed(int percent);
    void turn(int degree);
    
private:
    Motor* rightMotor;
    Motor* leftMotor;
    
    MotorSensor* rightSensor;
    MotorSensor* leftSensor;
};

#endif	/* MOTORCARRIAGE_H */

