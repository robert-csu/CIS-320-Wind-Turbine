
#include <IRremote.hpp>
#include "Turbine.h"
#include "ServoMotor.h"
#include "IRReader.h"
#include "LightSensor.h"
#include "WindTurbine.h"
#include "LED.h"
#include "RelayController.h"
#include "UltraSonicSensor.h"
#include "Display.h"



bool step_flag = false;


void IRwait(){
  if (IrReceiver.decode()) {
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
    whatButtonCheck(IrReceiver.decodedIRData.decodedRawData);
    IrReceiver.resume(); 
  }
}

void setup() {
  Serial.begin(9600);
  initiateTurbine();
  initiateServo();
  initiateLED();
  initiateDisplay();

  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(error){
    return;
  }

  IRwait();
  updateLED();

<<<<<<< Updated upstream
=======
  if(millis() - lastDistCheck >= 200){
    lastDistCheck = millis();
    constantDistCheck();
  }

  if(error){
    errorStop();
    errorDisplay();
  }

>>>>>>> Stashed changes
  if(step_flag){
    turbineArms.setSpeed(ifNight());
    turbineArms.runSpeed();
    updateDisplay(nightMode);
  }
  else{
    turbineArms.setSpeed(0);
    turbineArms.stop(); 
    turbineArms.disableOutputs();
    setOff();
    clearDisplay();
  }


  
}

void checkSTEPFLAG(){
  step_flag = !step_flag; 
  if(step_flag) turbineArms.enableOutputs(); 
  Serial.print("Turbine: ");
  Serial.println(step_flag ? "ON (25 RPM)" : "OFF"); 
}


