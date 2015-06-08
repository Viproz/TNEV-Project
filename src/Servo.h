/* 
 * File:   Servo.h
 * Author: viproz
 *
 * Created on 4 juin 2015, 15:01
 */

#ifndef SERVO_H
#define	SERVO_H

class Servo {
public:
    Servo(uint8_t pin);
    virtual ~Servo();
    
    void write(int angle);
private:
    uint8_t servoPin;
};

#endif	/* SERVO_H */

