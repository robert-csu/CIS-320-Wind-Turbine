#include <AccelStepper.h>

#define ldrPin A0
#define MAX_SPEED 950
#define MIN_SPEED 50
float currentSpeed = 853;

AccelStepper turbineArms(AccelStepper::HALF4WIRE, 8, 10, 9, 11);

void initiateTurbine(){
  turbineArms.setMaxSpeed(1000);
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

