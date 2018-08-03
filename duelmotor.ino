#include "mutistep.h"
#include "ultrasonic.h"
#include <Servo.h>
const double diameter = 0.08;
const double circumfrance = diameter * 3.14;
const double dps = circumfrance/200;
const int stepsPerRevolution = 200;  // change this to fit the number of steps per revolution
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

int rollermotor = 50;
int scissorliftmotor = 51;

const int trigPin = 12;
const int echoPin = 1;
const int startbutton = 3;

mutistep mu2(200,8,9,10,11,7,6,5,4);
//ultrasonic us1(trigPin, echoPin);
//ultrasonic us2(3, 2);

const int bottomservopin = 12;
Servo bottomservo;
const int topservopin = 13;
Servo topservo;

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(22, OUTPUT);
  digitalWrite(22, HIGH);
  Serial.begin(9600);
  bottomservo.attach(bottomservopin);
  topservo.attach(topservopin);
  
  pinMode(rollermotor, OUTPUT);
  bool flag = true;
  while(flag){
    if(digitalRead(startbutton)){
      digitalWrite(rollermotor, HIGH);
      flag = false;
    }
  }
}

void loop() {

// first part gets to first tube
//exit after button?

  delay(1000);
//  digitalWrite(rollermotor, LOW);
  mu2.setspeeds(120,120);
  sendbefore(0.5);
  mu2.setspeeds(120,100);
  sendbefore(0.56);
  mu2.setspeeds(120,120);
  sendbefore(1.47);
  mu2.setspeeds(100,120);
  sendbefore(0.1);
  
  for(int i = 0; i < 90; i++){
    topservo.write(i);
    delay(10);
  }
  mu2.setspeeds(120,0);
  sendbefore(-0.45);
  delay(10);
  mu2.setspeeds(120,120);
  sendbefore(1.45);
  delay(10);

  digitalWrite(scissorliftmotor, HIGH);
  delay(1000) //might need adjusting
  digitalWrite(scissorliftmotor, LOW);
  delay(50);
 
  sendbefore(0.05); //go closer
  
  for(int i = 0; i < 90; i++){
    bottomservo.write(i);
    delay(10);
  }

  //done

  while(1){
    
  }

//releaseballs

//  while(1){
//    us1.getdata();
//    int data = us1.returndata();
//    if(data < 500){
//      mu2.drive(-20);
//    }
//  }


//second section backing up
//    mu2.setspeeds(0, 50);
//    mu2.drive(600);
//    while(1){
//      us1.getdata();
//      us2.getdata();
//
//      digitalWrite(rollermotor, HIGH);
//      delay(1000);
//      digitalWrite(rollermotor, LOW);
//      delay(500);
//      
//      Serial.print("us1: ");
//      Serial.println(us1.returndata() )      ;
//      Serial.print("us2: ");
//      Serial.println(us2.returndata());
//    }

    //third needs to realine itself
    //very close to the first





    
  
//  int value = us1.returndata();
//  if(value > 200){
////  mu2.setspeeds(120, 120);
////  mu2.drive(10);
////  Serial.println(returndistance());
//  Serial.print(value);
//  Serial.println("hit");
//  }
//  else{
//    Serial.print(value);
//    Serial.println("miss");
//  }
//  
}

//void function(){
//  us1.getdata();
//  us2.getdata();
//  if(us1.returndata() < 400 && us2.returndata() < 400){
//    mu2.setspeeds(120, 120);
//  }
//  if(us1.returndata() > 400 && us2.returndata() > 400){
//    mu2.setspeeds(90, 120);
//  }
//  if(us1.returndata() < 400 && us2.returndata() < 400){
//    mu2.setspeeds(120, 90);
//  }
//  if(us1.returndata() > 400 && us2.returndata() > 400){
//    mu2.setspeeds(200, 200);
//  }
//  mu2.drive(10);
//}

void sendbefore(double meters){
  int stepsneeded = (1*meters/dps);
  mu2.drive(stepsneeded);
}

