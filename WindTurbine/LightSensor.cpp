#include <Arduino.h>
#include "WindTurbine.h"
#include "Turbine.h"
#include "LightSensor.h"
#include "LED.h"

bool nightMode = false;
float tolerance = 700;

float ifNight(){
  float ldrValue = analogRead(ldrPin);

  if(ldrValue >= tolerance){
    nightMode = true;
    setBlinking();
    Serial.print("NIGHT TIME | "); Serial.println(ldrValue);
    return 512;
   
  }
  else{
    nightMode = false;
    Serial.print("DAY TIME | "); Serial.println(ldrValue);
    setOff();
    return currentSpeed;
  }
}
