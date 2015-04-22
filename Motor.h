#ifndef MOTOR_H
#define	MOTOR_H
#include <Arduino.h>

class Motor {
public:
    Motor(int pinControl1, int pinControl2, int pinEnable);
    
    void setSpeed(int percent);
    
private:
    int pinControl1;
    int pinControl2;
    int pinEnable;
    
};

#endif	/* MOTOR_H */

