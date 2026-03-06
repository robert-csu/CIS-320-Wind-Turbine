#include <Arduino.h>

#define LED_PIN 13

bool blinkingFlag = false;

void setBlinking(){
  while(blinkingFlag){
    digitalWrite(LED_BUILTIN, HIGH);
    delay(1000);
    digitalWrite(LED_BUILTIN, LOW);
    delay(1000);
  }
}

void setSolid(){
  digitalWrite(LED_BUILTIN, HIGH);
}

void setOff(){
  digitalWrite(LED_BUILTIN, LOW);
}

void initiateLED(){
  pinMode(LED_BUILTIN, LED_PIN);
  setOff();
}