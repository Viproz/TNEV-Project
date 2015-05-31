/* 
 * File:   UltrasonicSensorCarriage.h
 * Author: viproz
 *
 * Created on 17 mai 2015, 20:25
 */

#ifndef ULTRASONICSENSORCARRIAGE_H
#define	ULTRASONICSENSORCARRIAGE_H
#include "UltrasonicSensor.h"
#include <Servo.h>

class UltrasonicSensorCarriage {
public:
    UltrasonicSensorCarriage();
    virtual ~UltrasonicSensorCarriage();
private:
    Servo servo;
    UltrasonicSensor* sensor;
    
};

#endif	/* ULTRASONICSENSORCARRIAGE_H */

