#include <Arduino.h>
//#include "src/Motor.h"
//#include "src/MotorCarriage.h"
#include "src/MotorSensor.h"
#include <HardwareSerial.h>

//PINs Some pins are in MotorCarriage
#define ON_OFF_BUTTON 5
#define SWITCH_DIRECTION_BUTTON 4

//MotorCarriage motors;

bool move = false;
bool direction = true;
bool onOffSwitchState = 0;
int previousOnOffSwitchState = 0;
int directionSwitchState = 0;
int previousDirectionSwitchState = 0;

MotorSensor* sensor;

extern HardwareSerial Serial;

void setup() {
    //inputs
    pinMode(ON_OFF_BUTTON, INPUT);
    pinMode(SWITCH_DIRECTION_BUTTON, INPUT);
    sensor = new MotorSensor(A0);
    Serial.begin(9600);
}

void loop() {
    delayMicroseconds(200);
    Serial.println(sensor->tick(&Serial));
    
    /*// read the value of the on/off switch
    onOffSwitchState = digitalRead(ON_OFF_BUTTON);
    
    // read the value of the direction switch
    directionSwitchState = digitalRead(SWITCH_DIRECTION_BUTTON);
    
    
    // if the direction button changed state since the last loop()
    if (directionSwitchState != previousDirectionSwitchState) {
        // change the value of motorDirection if pressed
        if (directionSwitchState == HIGH) {
            direction = !direction;
        }
    }
    
    
    // if the on/off button changed state since the last loop()
    if (onOffSwitchState != previousOnOffSwitchState) {
        // change the value of motorEnabled if pressed
        if (onOffSwitchState == HIGH) {
            move = !move;
            int speed = 50; //Speed to 50%
            if (!direction) {
                speed = -speed;
            }
            
            // if the motor is supposed to be on
            if (move) {
                motors.setSpeed(speed);
            } else { 
                motors.setSpeed(0);
            }
        }
    }
    
    
    // save the current On/Offswitch state as the previous
    previousDirectionSwitchState = directionSwitchState;
    // save the current switch state as the previous
    previousOnOffSwitchState = onOffSwitchState;*/
}
