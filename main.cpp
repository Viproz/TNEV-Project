#include <Arduino.h>
//#include "src/Motor.h"
//#include "src/MotorCarriage.h"
#include "src/MotorSensor.h"
#include <HardwareSerial.h>
#include "src/Button.h"
#include "src/MotorCarriage.h"
#include "src/UltrasonicSensorCarriage.h"

//PINs Some pins are in MotorCarriage
#define PIN_START 2
#define PIN_STOP 5
#define PIN_CALIBRATE 4

Button *buttonStart;
Button *buttonStop;
Button *buttonCalibrate;

MotorCarriage motors;

MotorSensor* sensor;
UltrasonicSensorCarriage* sound;

void setup() {
    //Initialize variables and classes
    Logger::init();
    sensor = new MotorSensor(A0);
    buttonCalibrate = new Button(PIN_CALIBRATE);
    buttonStart = new Button(PIN_START);
    buttonStop = new Button(PIN_STOP);
     sound = new UltrasonicSensorCarriage();
}

void loop() {
    //Buttons
    if(buttonStop->pushed()) {
        Logger::log("pres.3se2d");
        int angle, dist = 1;
        sound->findNearest(angle, dist);
        Logger::log("Result : Angle & dist");
        Logger::log(angle);
        Logger::log(dist);
        sound->write(angle);
    }
    if(buttonStart->pushed()) {
        Logger::log("pressed");
        sound->reset();
        
        int angle, dist = 0;
        
        //Do the slalom
        sound->findNearest(angle, dist);
        motors.turn(90 - angle);
        sound->reset();
        dist = sound->getDistance();
        motors.goDistance(dist - 35);
        motors.turn(-90);
        motors.goDistance(35);
        motors.turn(90);
        motors.goDistance(70);
        sound->findNearest(angle, dist);
        //fix f
        motors.turn(90 - (angle - 45));
        motors.goDistance(70);
        
        
        
    }
    if(buttonCalibrate->pushed()) {
        motors.calibrate();
        Logger::log("presse2d");
    }
}

