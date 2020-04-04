/* 
   CompliantServo.h - Library for compliant servo applications made from hacked rc servos.
   
   For running the servo motor, the Adafruit Motor Shield is used. Therefore the AFMotor.h libary must be installed first.
   
   by Matthias Dietrich @ Didis Maker Industries

   V1.00 - 04/04/2020  
*/

#include "Arduino.h"
#include "Servo.h"
#include "AFMotor.h"
#include "CompliantServo.h"

CompliantServo::CompliantServo(int potiPin, int motorNo) : _potiPin(potiPin), _motor(motorNo)
{
	_prev_error = 0;
}

void CompliantServo::holdPos(int target)
{
  const int friction = 130; // internal joint friction 0-255 (must be lower than maximum)
  const int maximum = 255; // maximum speed 0-255 (must be higher than friction)
  
  const float prop = 0.1; // proportional control value
  const float dyn = 10; // dynamic control value
  
  int ang;
  int error;
  int react;
 
  // compute errors, PD terms and reactions
  ang = analogRead(_potiPin);
  error = target - ang;
  react = error * prop + (error - _prev_error) * dyn;
  _prev_error = error;
  
  // turn Motor according to reaction
  if (react > 0)
  {
    // drive forwards
    _motor.run(FORWARD);
    if (abs(friction + react) < maximum)
    {
      _motor.setSpeed(abs(friction + react));
    }
    else
    {
      _motor.setSpeed(maximum);
    }
  }
  else if (react < 0)
  {
    // drive backwards
    _motor.run(BACKWARD);
    if (abs(friction - react) < maximum)
    {
      _motor.setSpeed(abs(friction - react));
    }
    else
    {
      _motor.setSpeed(maximum);
    }
  }
  else
  {
    _motor.run(RELEASE);
  }
}

int CompliantServo::getPos() {
	return analogRead(_potiPin);
}