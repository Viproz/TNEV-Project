#ifndef MOTORCARRIAGE_H
#define	MOTORCARRIAGE_H
#include "Motor.h"

class MotorCarriage {
public:
    MotorCarriage();
    virtual ~MotorCarriage();
    
    Motor getRightMotor() { return rightMotor; }
    Motor getLeftMotor() { return rightMotor; }
    
    void setSpeed(int percent);
    void turn(int degree);
    
private:
    Motor* rightMotor;
    Motor* leftMotor;
};

#endif	/* MOTORCARRIAGE_H */

