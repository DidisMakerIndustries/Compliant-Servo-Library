#include <CompliantServo.h>

CompliantServo ellbowJoint(14,4); // generates a Compliant servo object

void setup() {
 
}

void loop() {
  ellbowJoint.holdPos(500); // holds servo on position 500
}
