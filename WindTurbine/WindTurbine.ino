#include <Stepper.h>

Stepper turbineArms(2048, 8,10,9,11);

void setup() {
  // put your setup code here, to run once:
}

void loop() {
  // put your main code here, to run repeatedly:
  checkSpeed();
}

void checkSpeed(){
  int currentSpeed = 10;//ifNight();
  turbineArms.setSpeed(currentSpeed);
  turbineArms.step(100);
}

/*
int ifNight(){
  int lightLevel = analogRead(ldrPin); // Read the light sensor
  
  if (lightLevel < threshold) {
    digitalWrite(ledPin, HIGH); 
    return 30;
  } else {
    digitalWrite(ledPin, HIGH);
    return 10;
  }
}
*/
