#include <AccelStepper.h>
#include <IRremote.hpp>

#define IR_RECEIVE_PIN 3

#define OK 0xBF40FF00
#define UP 0xB946FF00
#define DOWN 0xEA15FF00
#define LEFT 0xBB44FF00
#define RIGHT 0xBC43FF00

float currentSpeed = 853;
bool step_flag = false;

AccelStepper turbineArms(AccelStepper::HALF4WIRE, 8, 10, 9, 11);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK); 
  turbineArms.setMaxSpeed(1000);
  Serial.println("Ready to receive IR signals...");
}

void loop() {
  // put your main code here, to run repeatedly:

  if (IrReceiver.decode()) {
    // This is the "void method" logic you requested
    whatButtonCheck(IrReceiver.decodedIRData.decodedRawData);
    IrReceiver.resume(); 
  }

  if(step_flag){
    turbineArms.setSpeed(currentSpeed);
    turbineArms.runSpeed();
  }
  else{
    turbineArms.setSpeed(0);
    turbineArms.stop(); 
    turbineArms.disableOutputs();
  }
  
}

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
      // Stervo motor left
      break;
    case RIGHT:
     // Stervo motor right
    default:
      // code to execute if variable does not match any case
      break;
  }
}

void checkSTEPFLAG(){
  step_flag = !step_flag; 
  if(step_flag) turbineArms.enableOutputs(); 
  Serial.print("Turbine: ");
  Serial.println(step_flag ? "ON (25 RPM)" : "OFF"); 
}

void increaseSpeed(){
  currentSpeed += 50; 
  Serial.print("Speed Increase: "); Serial.println(currentSpeed);
}

void decreaseSpeed(){
  currentSpeed -= 50;
  Serial.print("Speed down: "); Serial.println(currentSpeed);
}

/*
int ifNight(){
  int lightLevel = analogRead(ldrPin); // Read the light sensor
  
  if (lightLevel < threshold) {
    digitalWrite(ledPin, HIGH); 
    return 30;
  } else {
    digitalWrite(ledPin, HIGH);
    return 10;
  }
}
*/
