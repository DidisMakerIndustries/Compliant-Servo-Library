/* 
   CompliantServo.h - Library for compliant servo applications made from hacked rc servos.
   
   For running the servo motor, the Adafruit Motor Shield is used. Therefore the AFMotor.h libary must be installed first.
   
   by Matthias Dietrich @ Didis Maker Industries

   V1.00 - 04/04/2020  
*/

#ifndef CompliantServo_h
#define CompliantServo_h

#include "Arduino.h"
#include "Servo.h"
#include "AFMotor.h"

class CompliantServo
{
  public:
    CompliantServo(int potiPin, int motorNo);
    void holdPos(int target);
	int getPos();
	
  private:
    int _potiPin;
	AF_DCMotor _motor;
	int _prev_error;
};

#endif
