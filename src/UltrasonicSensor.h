/* 
 * File:   UltrasonicSensor.h
 * Author: viproz
 *
 * Created on 17 mai 2015, 20:26
 */

#ifndef ULTRASONICSENSOR_H
#define	ULTRASONICSENSOR_H
#include <Arduino.h>

class UltrasonicSensor {
public:
    UltrasonicSensor(uint8_t pinSIG);
    virtual ~UltrasonicSensor();
    
    int getDistance();
private:
    uint8_t pinSIG;

};

#endif	/* ULTRASONICSENSOR_H */

