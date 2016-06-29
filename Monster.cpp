//This code is based off the big dade sumobot code written Cormac OMeadhra and 
//has been adapted for integration into this project. 



//methods for monster motor shield class


#include "Monster.h"
#include "Arduino.h"



Monster::Monster(){
  pin1 = 8;
  pin2 = 7;
  pin3 = 4;
  pin4 = 9;
  speedpin1 = 5;
  speedpin2 = 6;
  
  pinMode(pin1, OUTPUT);
  pinMode(pin2,OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  pinMode(speedpin1, OUTPUT);
  pinMode(speedpin2, OUTPUT);

  
}

void Monster::drive(int Value){
 
  if (Value>=0){
    int Speed = map(Value, 0, 100, 0, 255);
  
    digitalWrite(pin1, HIGH);
    digitalWrite(pin2, LOW);
    digitalWrite(pin3, HIGH);
    digitalWrite(pin4, LOW);
    analogWrite(speedpin1, Speed);
    analogWrite(speedpin2, Speed);
  }

  else if (Value>0){
    int Speed = map(Value, -100, 0, 255, 0);
  
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, HIGH);
    digitalWrite(pin3, LOW);
    digitalWrite(pin4, HIGH);
    analogWrite(speedpin1, Speed);
    analogWrite(speedpin2, Speed);
  }
}


void Monster::setSpeed(int Value){

  if (Value>=0){
    int Speed = map(Value, 0, 100, 0, 255);
  
     analogWrite(speedpin1, Speed);
     analogWrite(speedpin2, Speed);
  }
  
    else if (Value<0){
    int Speed = map(Value, -100, 0, 255, 0);
  
     analogWrite(speedpin1, Speed);
     analogWrite(speedpin2, Speed);
  }
  
    
}



void Monster::turn_left(int Value){

  if (Value>=0){
    int Speed = map(Value, 0, 100, 0, 255);
  
    digitalWrite(pin1, HIGH);
    digitalWrite(pin2, LOW);
    digitalWrite(pin3, LOW);
    digitalWrite(pin4, HIGH);
    analogWrite(speedpin1, Speed);
    analogWrite(speedpin2, Speed);
  }

  else if (Value>0){
    int Speed = map(Value, -100, 0, 255, 0);
  
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, HIGH);
    digitalWrite(pin3, HIGH);
    digitalWrite(pin4, LOW);
    analogWrite(speedpin1, Speed);
    analogWrite(speedpin2, Speed);
  }
}





void Monster::turn_right(int Value){

  if (Value>=0){
    int Speed = map(Value, 0, 100, 0, 255);
  
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, HIGH);
    digitalWrite(pin3, HIGH);
    digitalWrite(pin4, LOW);
    analogWrite(speedpin1, Speed);
    analogWrite(speedpin2, Speed);
  }

  else if (Value>0){
    int Speed = map(Value, -100, 0, 255, 0);
  
    digitalWrite(pin1, HIGH);
    digitalWrite(pin2, LOW);
    digitalWrite(pin3, LOW);
    digitalWrite(pin4, HIGH);
    analogWrite(speedpin1, Speed);
    analogWrite(speedpin2, Speed);
  }

}

void Monster::arc (int Value1, int Value2){
  if (Value1>=0){
    int Speed = map(Value1, 0, 100, 0, 255);
  
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, HIGH);
   
    analogWrite(speedpin1, Speed);
    
  }

  else if (Value1>0){
    int Speed = map(Value1, -100, 0, 255, 0);
  
    digitalWrite(pin1, HIGH);
    digitalWrite(pin2, LOW);
   
    analogWrite(speedpin1, Speed);
   
  }

  if (Value2>=0){
    int Speed = map(Value2, 0, 100, 0, 255);
  
    digitalWrite(pin3, HIGH);
    digitalWrite(pin4, LOW);
   
    analogWrite(speedpin2, Speed);
  }

  else if (Value2>0){
    int Speed = map(Value2, -100, 0, 255, 0);
  
    digitalWrite(pin3, LOW);
    digitalWrite(pin4, HIGH);
    
    analogWrite(speedpin2, Speed);
  }
  
}


