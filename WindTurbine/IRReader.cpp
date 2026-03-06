#include <Arduino.h>
#include "Turbine.h"
#include "ServoMotor.h"
#include "WindTurbine.h"

#define OK 0xBF40FF00
#define UP 0xB946FF00
#define DOWN 0xEA15FF00
#define LEFT 0xBB44FF00
#define RIGHT 0xBC43FF00


void whatButtonCheck(unsigned long code){

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
      break;
    case RIGHT:
     turnRight();
     break;
    default:
      break;
  }
}



