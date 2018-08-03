#include "mutistep.h"

void mutistep::printtest(){
//  Serial.println(usedata);
//  Serial.println("hello");
}

void mutistep::setspeeds(int motor_1_speed, int motor_2_speed){
//  Serial.println("entered set speed");
  stepdelay_motor1 = 60L * 1000L * 1000L / motorsteps / motor_1_speed;
  stepdelay_motor2 = 60L * 1000L * 1000L / motorsteps / motor_2_speed;
//  Serial.println(stepdelay_motor1);
//  Serial.println(stepdelay_motor2);
}

void mutistep::drive(int stepstodrive){
//  Serial.println("hey from drive");
  int stepsleft_onmotor1 = abs(stepstodrive);
  int stepsleft_onmotor2 = abs(stepstodrive);
//  Serial.println(stepsleft_onmotor1);
  bool direction;
  if(stepstodrive > 0){direction = true;}
  if(stepstodrive < 0){direction = false;}
  unsigned long last_step_time_motor1;
  unsigned long last_step_time_motor2;
//  if(stepsleft_onmotor1 > 0){Serial.println("true");}
//  else{Serial.println("false");}
while (stepsleft_onmotor1 > 0 && stepsleft_onmotor2){
//  Serial.println(millis());
  unsigned long now = micros();
  if(now - last_step_time_motor1 >= stepdelay_motor1){
    last_step_time_motor1 = now;

    if(direction){
      postionstep_motor1++;
      if (postionstep_motor1 == motorsteps){
        postionstep_motor1 = 0;
      }
    }
    if(!direction){
      if(postionstep_motor1 == 0){
        postionstep_motor1 = motorsteps;
      }
      postionstep_motor1--;
    }
    stepsleft_onmotor1--;
    stepmotor(postionstep_motor1 % 4, motor_1_pin_1_, motor_1_pin_2_, motor_1_pin_3_, motor_1_pin_4_);    
  }
  if(now - last_step_time_motor2 >= stepdelay_motor2){
    last_step_time_motor2 = now;

    if(direction){
      postionstep_motor2++;
      if (postionstep_motor2 == motorsteps){
        postionstep_motor2 = 0;
      }
    }
    if(!direction){
      if(postionstep_motor2 == 0){
        postionstep_motor2 = motorsteps;
      }
      postionstep_motor2--;
    }
    stepsleft_onmotor2--;
    stepmotor(postionstep_motor2 % 4, motor_2_pin_1_, motor_2_pin_2_, motor_2_pin_3_, motor_2_pin_4_);    
  }
}
}

void mutistep::stepmotor(int thisStep, int pin1, int pin2, int pin3, int pin4){
//  Serial.println(thisStep);
  switch (thisStep) {
      case 0:  // 1010
        digitalWrite(pin1, HIGH);
        digitalWrite(pin2, LOW);
        digitalWrite(pin3, HIGH);
        digitalWrite(pin4, LOW);
      break;
      case 1:  // 0110
        digitalWrite(pin1, LOW);
        digitalWrite(pin2, HIGH);
        digitalWrite(pin3, HIGH);
        digitalWrite(pin4, LOW);
      break;
      case 2:  //0101
        digitalWrite(pin1, LOW);
        digitalWrite(pin2, HIGH);
        digitalWrite(pin3, LOW);
        digitalWrite(pin4, HIGH);
      break;
      case 3:  //1001
        digitalWrite(pin1, HIGH);
        digitalWrite(pin2, LOW);
        digitalWrite(pin3, LOW);
        digitalWrite(pin4, HIGH);
      break;
  }
}

