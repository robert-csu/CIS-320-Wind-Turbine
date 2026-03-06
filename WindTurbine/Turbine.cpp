#include <AccelStepper.h>

#define ldrPin A0

float currentSpeed = 853;

AccelStepper turbineArms(AccelStepper::HALF4WIRE, 8, 10, 9, 11);

void initiateTurbine(){
  turbineArms.setMaxSpeed(1000);
}

void increaseSpeed(){
  currentSpeed += 50; 
  turbineArms.setSpeed(currentSpeed);
  turbineArms.runSpeed();
  Serial.print("Speed Increase: "); Serial.println(currentSpeed);
}

void decreaseSpeed(){
  currentSpeed -= 50;
  turbineArms.setSpeed(currentSpeed);
  turbineArms.runSpeed();
  Serial.print("Speed down: "); Serial.println(currentSpeed);
}

