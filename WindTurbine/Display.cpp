#include <Arduino.h>
#include <LiquidCrystal.h>

#include "Turbine.h"
#include "LightSensor.h"

#define RS 48
#define E 49

LiquidCrystal display(RS, E, 50, 51, 52, 53);

byte sun[8] = {
  0b00100,
  0b10101,
  0b01110,
  0b11111,
  0b01110,
  0b10101,
  0b00100,
  0b00000
};

byte moon[8] = {
  B11100,
  B11110,
  B01111,
  B00111,
  B01111,
  B11110,
  B11100,
  B00000
};

void initiateDisplay(){
  display.begin(16,2);
  display.createChar(0, sun);
  display.createChar(1, moon);
  display.clear();
}

void updateDisplay(bool nightMode){
  float rpm = (currentSpeed * 60.0) / 2048.0;

  display.setCursor(0, 0);
  display.print("SPD:");
  display.print(rpm, 1);
  display.print("RPM ");
  display.setCursor(15, 0);
  display.write(nightMode ? byte(1) : byte(0));

  display.setCursor(0, 1);
  display.print("ENERGY: ");
}

void errorDisplay(){
  display.clear();
  display.setCursor(0, 0);
  display.print(" ERROR:TOO CLOSE");
  display.setCursor(0, 1);
  display.print("                ");
}

void clearDisplay(){
  display.clear();
}

