#include <Arduino.h>
#include "RelayController.h"

#define ECHO_PIN 23
#define TRIG_PIN 22

void initiateUltraSonicSensor(){
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

float getDistanceInches(){
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH, 15000);

  float distInches = (duration / 2.0) / 74.05;
  return distInches;
}

bool isIn6Inches(){
  float distance = getDistanceInches();
  Serial.println(distance);
  if(distance <= 0 || distance > 200) return false;
  return distance <= 6.0;
}

void constantDistCheck(){
  bool tooClose = isIn6Inches(); 
  if(tooClose){
    Serial.println("ERROR: TO CLOSE");
    error = true;
  }
  else if(error){
    error = false;
    clearedError();
  }
}
