#include "WindTurbine.h"
#include "Turbine.h"
#include "ServoMotor.h"
#include "LED.h"

#define RELAY_ON LOW
#define RELAY_OFF HIGH

#define RELAY_PIN 7

bool error = false;

void initialRelay(){
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, RELAY_OFF);
}

void errorStop(){
  if(error){
    turbineArms.setSpeed(0);
    turbineArms.stop();
    stopServo();
    setSolid();

    digitalWrite(RELAY_PIN, RELAY_OFF);
  }
}

void clearedError(){
  digitalWrite(RELAY_PIN, RELAY_OFF);

  step_flag = true;
  initiateLED();
}

