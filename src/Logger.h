/* 
 * File:   Logger.h
 * Author: viproz
 *
 * Created on 17 mai 2015, 20:44
 */

#ifndef LOGGER_H
#define	LOGGER_H
#include <Arduino.h>

extern HardwareSerial Serial;

class Logger {
public:
    static void init();
    static void log(const char* msg) { Serial.println(msg); }
    static void log(char msg) { Serial.println(msg); }
    static void log(char* msg) { Serial.println(msg); }
    static void log(int msg) { Serial.println(msg); }
    static void log(long msg) { Serial.println(msg); }
    static void log(String msg) { Serial.println(msg); }
    static void log(double msg) { Serial.println(msg); }
    
    static void error() { ; }
    
private:
    

};

#endif	/* LOGGER_H */

