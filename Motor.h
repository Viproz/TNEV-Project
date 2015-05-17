#ifndef MOTOR_H
#define	MOTOR_H
#include <Arduino.h>

class Motor {
public:
    Motor(uint8_t pinControl1, uint8_t pinControl2, uint8_t pinEnable);
    
    void setSpeed(int percent);
    void setMaxVoltage(int max) { maxVoltage = max; }
    
private:
    uint8_t pinControl1;
    uint8_t pinControl2;
    uint8_t pinEnable;
    
    int maxVoltage;
    
};

#endif	/* MOTOR_H */

