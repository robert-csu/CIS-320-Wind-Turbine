#ifndef LED_H
#define LED_H

#define LED_PIN 13

extern bool blinkingFlag;

void initiateLED();
void setBlinking();
void setSolid();
void setOff();

#endif