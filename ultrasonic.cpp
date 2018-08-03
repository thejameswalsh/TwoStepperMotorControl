#include "ultrasonic.h"

void ultrasonic::getdata(){
    // Clears the trigPin
digitalWrite(trigpin_, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigpin_, HIGH);
delayMicroseconds(10);
digitalWrite(trigpin_, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echopin_, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
//Serial.print("Distance: ");
//Serial.println(distance);
data_ = distance;
}

