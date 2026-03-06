#ifndef SERVOMOTOR_H
#define SERVOMOTOR_H

#include <Arduino.h>
#include <Servo.h>

extern Servo servo;

void initiateServo();
void updateServo();
void turnLeft();
void turnRight();
void stopServo();

#endif