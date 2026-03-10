
#include <Arduino.h>
#include "IRReader.h"
#include "Turbine.h"
#include "ServoMotor.h"
#include "WindTurbine.h"
#include "UltraSonicSensor.h"


#define OK 0xBF40FF00
#define UP 0xB946FF00
#define DOWN 0xEA15FF00
#define LEFT 0xBB44FF00
#define RIGHT 0xBC43FF00
#define STAR 0xBD42FF00

bool isValidCode(unsigned long code){
  return (code == OK || code == UP || code == DOWN || 
          code == LEFT || code == RIGHT || code == STAR);
}

void whatButtonCheck(unsigned long code){
  if (code == 0 || code == 0xFFFFFFFF) return;
  if (!isValidCode(code)) return;

  switch (code) {
    case OK:
      checkSTEPFLAG(); 
      break;
    case UP:
      increaseSpeed();
      break;
    case DOWN:
      decreaseSpeed();
      break;
    case LEFT:
      turnLeft();
      constantDistCheck();
      break;
    case RIGHT:
     turnRight();
     constantDistCheck();
     break;
    case STAR:
      stopServo();
      break;
    default:
      break;
  }
}



