#include <Arduino.h>
#include <Servo.h>

#define SERVO_PIN 12

#define MAX_LEFT_POS  180
#define MAX_RIGHT_POS -10
#define CENTER_POS    90
#define STEP_SIZE     10

Servo servo;
int servoPos = CENTER_POS;

void initiateServo(){
  servo.attach(SERVO_PIN);
  servoPos = CENTER_POS;
  servo.write(servoPos);
}

void turnLeft(){
  if (servoPos >= MAX_LEFT_POS){
    Serial.println("At max left");
    return;
  }
  servoPos += STEP_SIZE;
  servoPos = min(servoPos, MAX_LEFT_POS);
  servo.write(servoPos);
  Serial.print("Turning Left | Position: "); Serial.println(servoPos);
}

void turnRight(){
  if (servoPos <= MAX_RIGHT_POS){
    Serial.println("At max right");
    return;
  }
  servoPos -= STEP_SIZE;
  servoPos = max(servoPos, MAX_RIGHT_POS); 
  servo.write(servoPos);
  Serial.print("Turning Right | Position: "); Serial.println(servoPos);
}

void stopServo(){
  servo.write(servoPos);  
  Serial.print("Servo stopped at: "); Serial.println(servoPos);
}