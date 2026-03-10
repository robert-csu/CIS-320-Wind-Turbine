#ifndef LIGHTSENSOR_H
#define LIGHTSENSOR_H

#define ldrPin A0

extern float tolerance;
extern float ldrValue;

float ifNight();

#endif