#include <Arduino.h>
#include "WindTurbine.h"
#include "Turbine.h"
#include "LightSensor.h"
#include "LED.h"

float tolerance = 700;

float ifNight(){
  float ldrValue = analogRead(ldrPin);

  if(ldrValue >= tolerance){
    setBlinking();
    Serial.println(ldrValue);
    return 512;
   
  }
  else{
    Serial.println(ldrValue);
    setOff();
    return currentSpeed;
  }
}
