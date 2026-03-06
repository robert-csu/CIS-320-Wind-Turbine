#ifndef SERVOMOTOR_H
#define SERVOMOTOR_H

#include <Arduino.h>
#include <Servo.h>

extern Servo servo;

void initiateServo();
void turnLeft();
void turnRight();

#endif