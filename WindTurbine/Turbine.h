#ifndef TURBINE_H
#define TURBINE_H

#include <AccelStepper.h>

extern AccelStepper turbineArms;

void initiateTurbine();

void increaseSpeed();
void decreaseSpeed();
int ifNight();

#endif