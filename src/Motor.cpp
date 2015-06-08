#include "Motor.h"
#include "Logger.h"

Motor::Motor(uint8_t pinControl1, uint8_t pinControl2, uint8_t pinEnable) :
pinControl1(pinControl1), pinControl2(pinControl2), pinEnable(pinEnable) 
{
    //Inititialize pins
    pinMode(pinControl1, OUTPUT);
    pinMode(pinControl2, OUTPUT);
    pinMode(pinEnable, OUTPUT);
    
    //Make sure the motor is stopped
    digitalWrite(pinEnable, LOW);
    
    //Before calibration maxVoltage is 255
    maxVoltage = 255;
}

/**
 * Changes the speed of the motor
 * 
 * @param percent Speed in percentage
 */
void Motor::setSpeed(int percent) {
    Logger::log("max thingy");
    Logger::log(maxVoltage);
    //For now simple conversion to 0 -> 255 later we may add calibration
    int motorSpeed = (float)percent / 100.0 * (float)maxVoltage;
    Logger::log(motorSpeed);
    
    if(motorSpeed < 0) {
        digitalWrite(pinControl1, LOW);
        digitalWrite(pinControl2, HIGH);
    } else {
        digitalWrite(pinControl1, HIGH);
        digitalWrite(pinControl2, LOW);
    }
    
    analogWrite(pinEnable, abs(motorSpeed));
}
