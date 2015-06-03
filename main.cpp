#include <Arduino.h>
//#include "src/Motor.h"
//#include "src/MotorCarriage.h"
#include "src/MotorSensor.h"
#include <HardwareSerial.h>
#include "src/Button.h"
#include "src/MotorCarriage.h"

//PINs Some pins are in MotorCarriage
#define PIN_START 2
#define PIN_STOP 5
#define PIN_CALIBRATE 4

Button *buttonStart;
Button *buttonStop;
Button *buttonCalibrate;

MotorCarriage motors;

MotorSensor* sensor;

void setup() {
    //Initialize variables and classes
    Logger::init();
    sensor = new MotorSensor(A0);
    buttonCalibrate = new Button(PIN_CALIBRATE);
    buttonStart = new Button(PIN_START);
    buttonStop = new Button(PIN_STOP);
}

void loop() {    
    //Buttons
    if(buttonStop->pushed()) {
        Logger::log("pres.3se2d");
    }
    if(buttonStart->pushed()) {
        motors.goDistance(20);
        Logger::log("pressed");
    }
    if(buttonCalibrate->pushed()) {
        motors.calibrate();
        Logger::log("presse2d");
    }
}
