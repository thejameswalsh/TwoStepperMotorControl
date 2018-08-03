#include "arduino.h"

class mutistep
{
  public:
    void printtest();
    //constructors
    mutistep(int input){
      usedata = input;
    }
    //constructor assuming two identical stepper motors
    mutistep(int steps,
    int motor_1_pin_1,
    int motor_1_pin_2,
    int motor_1_pin_3,
    int motor_1_pin_4,
    int motor_2_pin_1,
    int motor_2_pin_2,
    int motor_2_pin_3,
    int motor_2_pin_4){
      motor_1_pin_1_ = motor_1_pin_1;
      motor_1_pin_2_ = motor_1_pin_2;
      motor_1_pin_3_ = motor_1_pin_3;
      motor_1_pin_4_ = motor_1_pin_4;
      motor_2_pin_1_ = motor_2_pin_1;
      motor_2_pin_2_ = motor_2_pin_2;
      motor_2_pin_3_ = motor_2_pin_3;
      motor_2_pin_4_ = motor_2_pin_4;

      postionstep_motor1 = 0;
      postionstep_motor2 = 0;

      motorsteps = steps;

      pinMode(motor_1_pin_1, OUTPUT);
      pinMode(motor_1_pin_2, OUTPUT);
      pinMode(motor_1_pin_3, OUTPUT);
      pinMode(motor_1_pin_4, OUTPUT);
      pinMode(motor_2_pin_1, OUTPUT);
      pinMode(motor_2_pin_2, OUTPUT);
      pinMode(motor_2_pin_3, OUTPUT);
      pinMode(motor_2_pin_4, OUTPUT);
    }
    //functions
    void setspeeds(int motor_1_speed, int motor_2_speed);
    void drive(int stepstodrive);
  private:
    void stepmotor(int thisstep, int pin1, int pin2, int pin3, int pin4);
    int usedata;
    int motor_1_pin_1_;
    int motor_1_pin_2_;
    int motor_1_pin_3_;
    int motor_1_pin_4_;
    int motor_2_pin_1_;
    int motor_2_pin_2_;
    int motor_2_pin_3_;
    int motor_2_pin_4_;

    int motorsteps;
    unsigned long stepdelay_motor1;
    unsigned long stepdelay_motor2;
    int postionstep_motor1;
    int postionstep_motor2;
};

