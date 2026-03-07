#include <Arduino.h>

#define LED_PIN 13

bool blinkingFlag = false;
unsigned long lastBlinkTime = 0;
bool ledState = false;

void setBlinking(){
  blinkingFlag = true;  // ← just set the flag, let loop() handle it
}

void setOff(){
  blinkingFlag = false;
  digitalWrite(LED_PIN, LOW);
  ledState = false;
}

void setSolid(){
  blinkingFlag = false;
  digitalWrite(LED_PIN, HIGH);
}

void updateLED(){  // ← call this in loop()
  if(!blinkingFlag) return;
  if(millis() - lastBlinkTime >= 1000){
    ledState = !ledState;
    digitalWrite(LED_PIN, ledState);
    lastBlinkTime = millis();
  }
}

void initiateLED(){
  pinMode(LED_PIN, OUTPUT);
  setOff();
}