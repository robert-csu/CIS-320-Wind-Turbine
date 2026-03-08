#include <AccelStepper.h>

#define ldrPin A0
#define MAX_SPEED 800
#define MIN_SPEED 50

AccelStepper turbineArms(AccelStepper::FULL4WIRE, 8, 10, 9, 11);

float currentSpeed = 600;

void initiateTurbine(){
  turbineArms.setMaxSpeed(800);
}

void increaseSpeed(){
  if(currentSpeed <= MAX_SPEED){
      currentSpeed += 50; 
      Serial.print("Speed Increase: "); Serial.println(currentSpeed);
  }
  else{
    currentSpeed = 1000;
    Serial.print("Speed Increase: "); Serial.println(currentSpeed);
  }

  turbineArms.setSpeed(currentSpeed);
  
}

void decreaseSpeed(){
   if(currentSpeed >= MIN_SPEED){
      currentSpeed -= 50; 
      Serial.print("Speed Decrease: "); Serial.println(currentSpeed);
  }
  else{
    currentSpeed = 0;
    Serial.print("Speed Decrease: "); Serial.println(currentSpeed);
  }

  turbineArms.setSpeed(currentSpeed);
}

