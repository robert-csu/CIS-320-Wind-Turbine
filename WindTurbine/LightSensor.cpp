#include <Arduino.h>
#include "WindTurbine.h"
#include "Turbine.h"
#include "LightSensor.h"
#include "LED.h"

float tolerance = 300;

float ifNight(){
  float ldrValue = analogRead(ldrPin);

  if(ldrValue <= tolerance){
    return 512;
    setBlinking();
  }
  else{
    setOff();
    return currentSpeed;
  }
}
