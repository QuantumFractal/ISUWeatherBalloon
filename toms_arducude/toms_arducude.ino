/* Arduino Weather Balloon Code
      Purpose: to capture data on a weather balloon rig.
      
   Created by:
   Thomas Moll and Michael Snook
   15 October 2013

  Motor Layout (For testing)
    Tube Cover Servo = PWM 2  
    Cartridge Motor  = PWM 3
    Fan Motor        = PWM 4
*/
#include <Servo.h>

Servo fanMotor;                                    //creates the servo objects
Servo cartridgeMotor;                              
Servo tubeCoverServo;
/*
void openTube();
void closeTube();
void runFan(int duration);
void takeMicrobeSample(int cartridgePosition);
*/
int switch1 = 0;                                   //For testing
int switch1PIN = 8;                                //Testing
int cartridgePosition = 0;                         //Initial Position of the Cartridge

void setup(){
  fanMotor.attach(4);                              //Set the pins for the motors and serial out
  cartridgeMotor.attach(3);
  tubeCoverServo.attach(2);
  Serial.begin(9600);
  Serial.print("Setup Finished\n");
}


void loop(){
  Serial.println("-------------------------");
  cartridgePosition = takeMicrobeSample(cartridgePosition);
}


int takeMicrobeSample(int cartridgePosition){
  //Serial.print("Cartridge Position is at ");
  //Serial.print(cartridgePosition);
  //Serial.print("\n");
  if(cartridgePosition == 0){
    openTube();
    runFan(3000);
    closeTube(); 
  }
  else{
    turnCartridge();
    openTube();
    runFan(3000);
    closeTube();
  }
  cartridgePosition++;
}
void runFan(int duration){
  Serial.print("Fan Running\n");
  fanMotor.write(90);
  delay(duration);
  fanMotor.write(0);
  Serial.print("Fan Stopped\n");  
}
void turnCartridge(){
  Serial.print("Cartridge Turned\n");
  cartridgeMotor.write(90);
  delay(1000);
  cartridgeMotor.write(0); 
}
void openTube(){
  Serial.print("Tube Opened\n");
  tubeCoverServo.write(0);
  delay(1000);
}
void closeTube(){
  Serial.print("Tube Closed\n");
  tubeCoverServo.write(90);
  delay(1000);
}
