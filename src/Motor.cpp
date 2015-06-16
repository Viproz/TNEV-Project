#include "Motor.h"
#include "Logger.h"
#include "MotorSensor.h"

Motor::Motor(uint8_t pinControl1, uint8_t pinControl2, uint8_t pinEnable, MotorSensor* sensor) :
pinControl1(pinControl1), pinControl2(pinControl2), pinEnable(pinEnable) , sensor(sensor)
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

void Motor::goDistance(int centimeters, int speedPercent) {
    
    //ta da dam
    centimeters *= 2;
    
    //We'll use the sensor to mesure
    previousAngle = sensor->getAngle();
    
    forward = centimeters >= 0;
    distToGo = abs(centimeters);
    setSpeed(speedPercent * (forward ? 1 : -1));
}

bool Motor::tick() {
    if(distToGo > 0) {
        int newAngle = sensor->getAngle();
        distToGo -= getArc(previousAngle, newAngle, forward);
        Logger::log(distToGo);
    }
    if(distToGo < 0) {
        analogWrite(pinEnable, 0);
        return false;
    }
    return true;
}

float Motor::getArc(int prevAngle, int newAngle, bool direction) {
    //direction == true means trigonometric rotation
    int angle = 0;
    
    
    if(abs(prevAngle - newAngle) < 5)
        return 0;
    
    if(!direction) {
        if(prevAngle > newAngle)
            angle = newAngle - prevAngle + 360;
        else
            angle = newAngle - prevAngle;
    }
    
    if(direction) {
        if(prevAngle < newAngle)
            angle = prevAngle - newAngle + 360;
        else
            angle = prevAngle - newAngle;
    }
    
    //Caluculate the arc length
    //d = PI*degree/180*r
    //diameter = 62cm
    Logger::log((float)angle * 0.0541);
    return (float)angle * 0.0541;
}