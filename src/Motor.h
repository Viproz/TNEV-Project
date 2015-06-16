#ifndef MOTOR_H
#define	MOTOR_H
#include <Arduino.h>

#include "MotorSensor.h"

class Motor {
public:
    Motor(uint8_t pinControl1, uint8_t pinControl2, uint8_t pinEnable, MotorSensor* sensor);
    
    void setSpeed(int percent);
    void setMaxVoltage(int max) { maxVoltage = max; }
    void goDistance(int centimeters, int speedPercent = 100);
    bool tick();
    float getArc(int prevAngle, int newAngle, bool direction);
    
private:
    uint8_t pinControl1;
    uint8_t pinControl2;
    uint8_t pinEnable;
    
    MotorSensor* sensor;
    
    int maxVoltage;
    float distToGo;
    int previousAngle;
    bool forward;
    
};

#endif	/* MOTOR_H */

