//This driver is based off the instructable available here. 
//The code is base off the big dade code written by Cormac OMeadhra and has been adapted for integration in this project

#include "Elecsoc_driver_v1.h"
#include "Arduino.h"


Elecsoc_driver_v1::Elecsoc_driver_v1(){
  Left1 = 5;
  Left2 = 6;
  Right1 = 10;
  Right2 = 11;

  pinMode(Left1, OUTPUT);
  pinMode(Left2, OUTPUT);
  pinMode(Right1, OUTPUT);
  pinMode(Right2, OUTPUT);
  
}

void Elecsoc_driver_v1::drive(int Value){

 if (Value>=0){
    if (Value >100) 
      Value=100;
    
    int Speed = map(Value, 0, 100, 0, 255);

    analogWrite(Left1, Speed);
    analogWrite(Left2, LOW);

    analogWrite(Right1, Speed);
    analogWrite(Right2, LOW);
  }

  else if (Value<0){
    if (Value<-100)
      Value =-100;
      
    int Speed = map(Value, -100, 0, 0, 255);

    analogWrite(Left2, Speed);
    analogWrite(Left1, LOW);

    analogWrite(Right2, Speed);
    analogWrite(Right1, LOW);   
  }  
}

void Elecsoc_driver_v1::turn_left(int Value){

   if (Value>=0){
    if (Value >100) 
      Value=100;
    
    int Speed = map(Value, 0, 100, 0, 255);

    analogWrite(Left2, Speed);
    analogWrite(Left1, LOW);

    analogWrite(Right1, Speed);
    analogWrite(Right2, LOW); 
  }

  else if (Value<0){
    if (Value<-100)
      Value =-100;
      
    int Speed = map(Value, -100, 0, 0, 255);

    analogWrite(Left1, Speed);
    analogWrite(Left2, LOW);

    analogWrite(Right2, Speed);
    analogWrite(Right1, LOW);
  }  
}

void Elecsoc_driver_v1:: turn_right(int Value){

   if (Value>=0){
    if (Value >100) 
      Value=100;
    
    int Speed = map(Value, 0, 100, 0, 255);

    analogWrite(Left1, Speed);
    analogWrite(Left2, LOW);

    analogWrite(Right2, Speed);
    analogWrite(Right1, LOW); 
  }

  else if (Value<0){
    if (Value<-100)
      Value =-100;
      
    int Speed = map(Value, -100, 0, 0, 255);

    analogWrite(Left2, Speed);
    analogWrite(Left1, LOW);

    analogWrite(Right1, Speed);
    analogWrite(Right2, LOW);
  }  
}

void Elecsoc_driver_v1::arc(int Value1, int Value2){

   if (Value1>=0){
    if (Value1 >100) 
      Value1=100;
    
    int Speed = map(Value1, 0, 100, 0, 255);

    analogWrite(Left1, Speed);
    analogWrite(Left2, LOW);

  }

  else if (Value1<0){
    if (Value1<-100)
      Value1 =-100;
      
    int Speed = map(Value1, -100, 0, 0, 255);

    analogWrite(Left2, Speed);
    analogWrite(Left1, LOW);

    
  }  

   if (Value2>=0){
    if (Value2 >100) 
      Value2=100;
    
    int Speed = map(Value2, 0, 100, 0, 255);

    analogWrite(Right1, Speed);
    analogWrite(Right2, LOW); 
  }

  else if (Value2<0){
    if (Value2<-100)
      Value2 =-100;
      
    int Speed = map(Value2, -100, 0, 0, 255);

    analogWrite(Right2, Speed);
    analogWrite(Right1, LOW);
  }  
}

