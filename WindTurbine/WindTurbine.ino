

#include "Turbine.h"
#include "ServoMotor.h"
//#include "IR_Reader.h"


bool step_flag = false;

void setup() {
  Serial.begin(9600);
  initiateTurbine();
}

void loop() {
  // put your main code here, to run repeatedly:

  //IRwait();

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


