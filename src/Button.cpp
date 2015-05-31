/* 
 * File:   Button.cpp
 * Author: viproz
 * 
 * Created on 31 mai 2015, 17:24
 */

#include "Button.h"

Button::Button(uint8_t pinButton) :
    pinButton(pinButton) {
    pressed = false;
}

Button::~Button() {
}

/**
 * Reads the value of the pin and compares it with his previous state
 * 
 * This function will a the same time tick the pin and analyse the data, it have to be called frequently.
 * 
 * @return true if the button have been pushed
 */
bool Button::pushed() {
    int state = digitalRead(pinButton);
    
    if(state == LOW && pressed) {
        pressed = false;
        return true;
    }
    
    pressed = state == HIGH;
    
    return false;
}
