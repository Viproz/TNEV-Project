/* 
 * File:   MotorSensor.h
 * Author: viproz
 *
 * Created on 17 mai 2015, 12:22
 */

#ifndef MOTORSENSOR_H
#define	MOTORSENSOR_H

#include "Logger.h"

class MotorSensor {
public:
    MotorSensor(uint8_t pinPhoto);
    virtual ~MotorSensor();
    
    void reset();
    
    int tick();
    int getAngle();
    int getIntersections() { return intersections; }
private:
    uint8_t pinContact;
    
    unsigned long prevDetection;
    
    int intersections;
};

#endif	/* MOTORSENSOR_H */

