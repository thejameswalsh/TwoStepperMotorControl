#include "arduino.h"

class ultrasonic
{
  public:
  //input two ints that relate to the pins
  ultrasonic(
    int trigpin,
    int echopin)
    {
      trigpin_ = trigpin;
      echopin_ = echopin;

      pinMode(trigpin_, OUTPUT);
      pinMode(echopin_, INPUT);
    }
    //return the caluated value for the data
  void getdata();
  int returndata(){
    return data_;
  }
  
  private:
    int trigpin_;
    int echopin_;
    int distance;
    long duration;
    int data_;
};

