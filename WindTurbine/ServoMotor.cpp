/*
Going to need to time the servo motor or the specific rpm so I can time the rotations.
 - Going a full rotation to the left will be +1
 - Going a full rotation to the right will be -1
 - when turnLeft() is it add to the rotational variable
 - when turnRight() is it subtract from the rotational variable
*/

#include <Arduino.h>
#include <Servo.h>

#define SERVO_PIN 12

#define MAX_LEFT_ROTATION 1.00
#define MAX_RIGHT_ROTATION -1.00

#define CIRCLE_SPEED_MS 2000 // DEFAULT CIRCLE NEED TO CHANGE
#define STOP_SPEED 90
#define LEFT_TURN_SPEED 100
#define RIGHT_TURN_SPEED 80
#define TURN_AMOUNT 0.02

Servo servo;

double rotation = 0.0;

unsigned long servoStartTime = 0;
bool isServoMoving = false;

void initiateServo(){
  servo.attach(SERVO_PIN);
  servo.write(STOP_SPEED);
}

void updateServo(){
  if (isServoMoving && (millis() - servoStartTime >= (unsigned long)(CIRCLE_SPEED_MS * TURN_AMOUNT))) {
    servo.write(STOP_SPEED);
    isServoMoving = false;
  }
}

void turnLeft(){
  if (rotation >= MAX_LEFT_ROTATION || isServoMoving){
    return;
  }

  rotation += TURN_AMOUNT;

  servo.write(LEFT_TURN_SPEED);
  servoStartTime = millis();
  servo.write(STOP_SPEED);
}

void turnRight(){
  if (rotation <= MAX_RIGHT_ROTATION || isServoMoving){
    return;
  }
  rotation -= TURN_AMOUNT;

  servo.write(RIGHT_TURN_SPEED);
  servoStartTime = millis();
  servo.write(STOP_SPEED);
}
