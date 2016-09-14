#include "Sensors.h"
#include "Arduino.h"



//Distance sensor methods
HC_SR04::HC_SR04(int trig, int echo){   //constructor, set up pins 
  pin_echo = echo;
  pin_trig = trig;
  pinMode(pin_trig, OUTPUT);
  pinMode(pin_echo, INPUT);
  type = 1;                             //defines if using one or two pins on arduino, 
                                        //two requires less complecated wiring, one requires less pins
}


HC_SR04::HC_SR04(int pin){              // second constructor for instance of 1 pin used (connect trig and echo together)
  pin1 = pin;
  type =2;
}

int HC_SR04::ping(){                    //method for getting distance, works for both wiring set ups

  if (type = 1){
  digitalWrite(pin_trig, LOW);          //pulse high twice for short time
  delayMicroseconds(2);
  digitalWrite(pin_trig, HIGH);
  delayMicroseconds(5);
  digitalWrite(pin_trig, LOW);

  int duration = pulseIn(pin_echo, HIGH); //listen for response, will probably miss start so can
                                          //judge distance by how much of pulse is recieved
  
  return duration / 29 / 2;
  }

  else if (type = 2){
  pinMode(pin1, OUTPUT);
  digitalWrite(pin1, LOW);
  delayMicroseconds(2);
  digitalWrite(pin1, HIGH);
  delayMicroseconds(5);
  digitalWrite(pin1, LOW);

  pinMode(pin1, INPUT);
  int duration = pulseIn(pin1, HIGH);
  return duration / 29 / 2;
  }
}




//Digital Line Sensor Methods
digitalLine::digitalLine(int pin1){
  pin = pin1; 
}


int digitalLine::read_sensor(){
 return(digitalRead(pin));    //return either high or low form sensing pin
  }




//analog line sensor methods
analogLine::analogLine(int pin1){
  pin = pin1;
  threshold = 512;    //set to somewhat arbitrary initial value, half of 10 bit value 
}

int analogLine::read_sensor(){
  
int temp;

  if(pin >= 14 && pin <= 19)
  temp = analogRead(pin);

  else {
    Serial.println("WARNING: reading an analog input using a digital pin, reading will not be accurate");
    temp = digitalRead(pin);
    return(temp);
  }

  
  if (temp > threshold){
    return (1);
  }
  else{
    return (0);
  }
}


void analogLine:: set_threshold(int thresh){
threshold = thresh;
}




//collision sensor methods

collision::collision (int pin1){
  pin = pin1;
}

int collision::state(){
    int temp = digitalRead(pin);    //read if sensor is either hit or not
    return(temp);               //return 0 or 1
}





