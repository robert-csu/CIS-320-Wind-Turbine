
#include <IRremote.hpp>
#include "Turbine.h"
#include "ServoMotor.h"
#include "IRReader.h"
#include "LightSensor.h"
#include "WindTurbine.h"


bool step_flag = false;


void IRwait(){
  if (IrReceiver.decode()) {
    whatButtonCheck(IrReceiver.decodedIRData.decodedRawData);
    IrReceiver.resume(); 
  }
}

void setup() {
  Serial.begin(9600);
  initiateTurbine();
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
}

void loop() {
  // put your main code here, to run repeatedly:

  IRwait();
  updateServo();

  if(step_flag){
    turbineArms.setSpeed(ifNight());
    turbineArms.runSpeed();
  }
  else{
    turbineArms.setSpeed(0);
    turbineArms.stop(); 
    turbineArms.disableOutputs();
  }
  
}

void checkSTEPFLAG(){
  step_flag = !step_flag; 
  if(step_flag) turbineArms.enableOutputs(); 
  Serial.print("Turbine: ");
  Serial.println(step_flag ? "ON (25 RPM)" : "OFF"); 
}


