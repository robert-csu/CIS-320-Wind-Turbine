#ifndef SERVOMOTOR_H
#define SERVOMOTOR_H

#include <Arduino.h>
#include <Servo.h>

#define SERVO_PIN 12

#define LEFT_TURN_SPEED 180
#define RIGHT_TURN_SPEED 0

extern Servo servo;

void initiateServo();
void turnLeft();
void turnRight();
void stopServo();

#endif