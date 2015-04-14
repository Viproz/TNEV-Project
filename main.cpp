#include <Arduino.h>

//PINs
#define MOTOR1_CONTROL_PIN_1 2
#define MOTOR1_CONTROL_PIN_2 3
#define MOTOR1_ENABLE_PIN 9

#define MOTOR2_CONTROL_PIN_1 2
#define MOTOR2_CONTROL_PIN_2 3
#define MOTOR2_ENABLE_PIN 9

#define ON_OFF_BUTTON 5
#define SWITCH_DIRECTION_BUTTON 4
#define POTENTIOMETER 5

extern HardwareSerial Serial;

bool onOffSwitchState = 0;
int previousOnOffSwitchState = 0;
int directionSwitchState = 0;
int previousDirectionSwitchState = 0;

int motorEnabled = 0;
int motorSpeed = 0;
int motorDirection = 1;

void setup() {
  //inputs
  pinMode(ON_OFF_BUTTON, INPUT);
  pinMode(SWITCH_DIRECTION_BUTTON, INPUT);
  
  //outputs
  pinMode(MOTOR1_CONTROL_PIN_1, OUTPUT);
  pinMode(MOTOR1_CONTROL_PIN_1, OUTPUT);
  pinMode(MOTOR1_ENABLE_PIN, OUTPUT);
  pinMode(MOTOR2_CONTROL_PIN_1, OUTPUT);
  pinMode(MOTOR2_CONTROL_PIN_1, OUTPUT);
  pinMode(MOTOR2_ENABLE_PIN, OUTPUT);

  //pull the enable pin LOW to start
  digitalWrite(MOTOR1_ENABLE_PIN, LOW);
  digitalWrite(MOTOR2_ENABLE_PIN, LOW);
}

void loop() {
  // read the value of the on/off switch
  onOffSwitchState = digitalRead(ON_OFF_BUTTON);
  delay(1);

  // read the value of the direction switch
  directionSwitchState = digitalRead(SWITCH_DIRECTION_BUTTON);

  // read the value of the pot and divide by 4 to get
  // a value that can be used for PWM
  motorSpeed = analogRead(POTENTIOMETER) / 4;

  // if the on/off button changed state since the last loop()
  if (onOffSwitchState != previousOnOffSwitchState) {
    // change the value of motorEnabled if pressed
    if (onOffSwitchState == HIGH) {
      motorEnabled = !motorEnabled;
    }
  }

  // if the direction button changed state since the last loop()
  if (directionSwitchState != previousDirectionSwitchState) {
    // change the value of motorDirection if pressed
    if (directionSwitchState == HIGH) {
      motorDirection = !motorDirection;
    }
  }

  // change the direction the motor spins by talking
  // to the control pins on the H-Bridge
  if (motorDirection == 1) {
    digitalWrite(MOTOR1_CONTROL_PIN_1, HIGH);
    digitalWrite(MOTOR1_CONTROL_PIN_2, LOW);
    
    digitalWrite(MOTOR2_CONTROL_PIN_1, HIGH);
    digitalWrite(MOTOR2_CONTROL_PIN_2, LOW);
  }
  else {
    digitalWrite(MOTOR1_CONTROL_PIN_1, LOW);
    digitalWrite(MOTOR1_CONTROL_PIN_2, HIGH);
    
    digitalWrite(MOTOR2_CONTROL_PIN_1, LOW);
    digitalWrite(MOTOR1_CONTROL_PIN_2, HIGH);
  }

  // if the motor is supposed to be on
  if (motorEnabled == 1) {
    // PWM the enable pin to vary the speed
    analogWrite(MOTOR1_ENABLE_PIN, motorSpeed);
      
    analogWrite(MOTOR2_ENABLE_PIN, motorSpeed);
  }
  else { // if the motor is not supposed to be on
    //turn the motor off
    analogWrite(MOTOR1_ENABLE_PIN, 0);
      
    analogWrite(MOTOR2_ENABLE_PIN, 0);
  }
  // save the current On/Offswitch state as the previous
  previousDirectionSwitchState = directionSwitchState;
  // save the current switch state as the previous
  previousOnOffSwitchState = onOffSwitchState;
}
