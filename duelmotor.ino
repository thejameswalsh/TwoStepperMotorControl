#include "mutistep.h"
const int stepsPerRevolution = 200;
const double diameter = 0.08;
const double circumfrance = diameter * 3.14;
const double dps = circumfrance/stepsPerRevolution;
  // change this to fit the number of steps per revolution
// for your motor
//
int motor1_pin_1 =8;
int motor1_pin_2 =9;
int motor1_pin_3 =10;
int motor1_pin_4 =11;
//
int motor2_pin_1 = 7;
int motor2_pin_2 = 6;
int motor2_pin_3 = 5;
int motor2_pin_4 = 4;

mutistep mu2(200,8,9,10,11,7,6,5,4);

void setup() {
  Serial.begin(9600);
}

void loop() {
  //stepper.setspeeds takes two inputs left and right wheel depending on your config
  //input_meters takes one input only how many meters you want to go based ont the diameter of your wheel in meters
  mu2.setspeeds(120,120);
  input_meters(0.5);
  mu2.setspeeds(120,100);
  input_meters(0.56);
  mu2.setspeeds(120,120);
  input_meters(1.47);
  mu2.setspeeds(100,120);
  input_meters(0.1);
  mu2.setspeeds(120,0);
  input_meters(-0.45);
  delay(10);
  mu2.setspeeds(120,120);
  input_meters(1.45);
  delay(10);
 
  input_meters(0.05); //go closer
  while(1){
    Serial.print("end of demo");    
  }
}

void input_meters(double meters){
  mu2.drive((1*meters/dps));
}


