#ifndef LIGHTSENSOR_H
#define LIGHTSENSOR_H

#define ldrPin A0

extern bool nightMode;
extern float tolerance;

float ifNight();

#endif