/* 
 * File:   Logger.h
 * Author: viproz
 *
 * Created on 17 mai 2015, 20:44
 */

#ifndef LOGGER_H
#define	LOGGER_H
#include <Arduino.h>

class Logger {
public:
    static void init();
    static void log(const char* msg) { serial.println(msg); }
    static void log(char msg) { serial.println(msg); }
    static void log(char* msg) { serial.println(msg); }
    static void log(int msg) { serial.println(msg); }
    static void log(long msg) { serial.println(msg); }
    static void log(String msg) { serial.println(msg); }
    static void log(double msg) { serial.println(msg); }
    
    static void error() { digitalWrite(13, HIGH); }
    
private:
    static HardwareSerial serial;

};

#endif	/* LOGGER_H */

