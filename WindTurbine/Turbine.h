#ifndef TURBINE_H
#define TURBINE_H

#include <AccelStepper.h>

extern AccelStepper turbineArms;

extern float currentSpeed;

void initiateTurbine();

void increaseSpeed();
void decreaseSpeed();

#endif