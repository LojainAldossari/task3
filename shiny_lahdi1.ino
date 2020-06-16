/* Stepper Motor with potentiometer */
#include <Stepper.h>

const int stepsPerRevolution = 200; 


Stepper myStepper(stepsPerRevolution, 2, 3, 4, 5);

int stepCount = 0;  

void setup() {
  
}

void loop() {
  // read the sensor value from A0
  int sensorReading = analogRead(A0);
  // map it to a range from 0 to 100:
  int motorSpeed = map(sensorReading, 0, 1023, 0, 100);
  // set the motor speed:
  if (motorSpeed > 0) {
    myStepper.setSpeed(motorSpeed);
    // step 1/100 of a revolution:
    myStepper.step(stepsPerRevolution / 100);
  }
}