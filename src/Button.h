/* 
 * File:   Button.h
 * Author: viproz
 *
 * Created on 31 mai 2015, 17:24
 */

#ifndef BUTTON_H
#define	BUTTON_H

#include <Arduino.h>

class Button {
public:
    Button(uint8_t pinButton);
    virtual ~Button();
    
    bool pushed();
private:
    uint8_t pinButton;
    bool pressed;
};

#endif	/* BUTTON_H */

