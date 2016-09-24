
#include "L298N.h"
#include "arduino.h"

L298N::L298N(float scale){ //default constructor, uses pins 6-11 in order of pins on board, ena, in1, in2, in3, in4, enb
  enA = 6;
  enB = 7;
  in1 = 8;
  in2 = 9;
  in3 = 10;
  in4 = 11;

  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
}




L298N::L298N(int ENA, int IN1, int IN2, int IN3, int IN4, int ENB, float scale){   //secondary constructor, set pins directly so as to suit those used
  enA = ENA;
  enB = ENB;
  in1 = IN1;
  in2 = IN2;
  in3 = IN3;
  in4 = IN4;

  float voltage_scale = scale;

  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}





void L298N::set_pins(int ENA, int IN1, int IN2, int IN3, int IN4, int ENB){   //set pins after constructor call
  
  pinMode(enA, INPUT);    //safer to set unused pins as inputs, bad idea to leave pins as outputs indefinitely
  pinMode(enB, INPUT);
  pinMode(in1, INPUT);
  pinMode(in2, INPUT);
  pinMode(in3, INPUT);
  pinMode(in4, INPUT);
  
  
  enA = ENA;              //set new pin numbers
  enB = ENB;
  in1 = IN1;
  in2 = IN2;
  in3 = IN3;
  in4 = IN4;

  pinMode(enA, OUTPUT);   //set new pins to be outputs
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
  }



void L298N::drive(int Value){
    if (Value>=0){   // drive forward
      if (Value>=100){ Value=100;} //change to limit if outside limit

    int Speed = map(Value,0,100, 0, voltage_scale*255); //map Value to 8 bit Speed

    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enA, Speed);
    analogWrite(enB, Speed);

      
    }
    

    else if (Value<0){   // drive backwards
      if (Value<=-100){ Value = -100;} //change to limit if outside limit

    int Speed = map(Value,-100,0,voltage_scale*255, 0);

    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enA, Speed);
    analogWrite(enB, Speed);
    }
  
}


void L298N:: turn_left(int Value){
    if (Value>=0){   // turn left
      if (Value>=100){ Value=100;} //change to limit if outside limit

    int Speed = map(Value,0,100, 0, voltage_scale*255); //map Value to 8 bit Speed

    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enA, Speed);
    analogWrite(enB, Speed);

      
    }
    

    else if (Value<0){   // turn right
      if (Value<=-100){ Value = -100;} //change to limit if outside limit

    int Speed = map(Value,-100,0,voltage_scale*255, 0);

    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enA, Speed);
    analogWrite(enB, Speed);
    }
  
}
  




void L298N:: turn_right(int Value){

    if (Value>=0){   // turn right
      if (Value>=100){ Value=100;} //change to limit if outside limit

    int Speed = map(Value,0,100, 0, voltage_scale*255); //map Value to 8 bit Speed

    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enA, Speed);
    analogWrite(enB, Speed);

      
    }
    

    else if (Value<0){   // turn left
      if (Value<=-100){ Value = -100;} //change to limit if outside limit

    int Speed = map(Value,-100,0,voltage_scale*255, 0);

    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enA, Speed);
    analogWrite(enB, Speed);
    }
}


void L298N:: arc(int Value1, int Value2){   //arc, turn motors at differnet speeds


   //motor 1 speed
    if (Value1>=0){   // drive forward
      if (Value1>=100){ Value1=100;} //change to limit if outside limit

    int Speed1 = map(Value1,0,100, 0, voltage_scale*255); //map Value to 8 bit Speed

    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    
    analogWrite(enA, Speed1);
    

      
    }
    
    
    else if (Value1<0){   // drive backwards
      if (Value1<=-100){ Value1 = -100;} //change to limit if outside limit

    int Speed1 = map(Value1,-100,0,voltage_scale*255, 0);

    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    
    analogWrite(enA, Speed1);
    
    }

    //motor 2

    if (Value2>=0){   // drive forward
      if (Value2>=100){ Value2=100;} //change to limit if outside limit

    int Speed2 = map(Value2,0,100, 0, voltage_scale*255); //map Value to 8 bit Speed

    
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    
    analogWrite(enB, Speed2);

      
    }
    

    else if (Value2<0){   // drive backwards
      if (Value2<=-100){ Value2 = -100;} //change to limit if outside limit

    int Speed2 = map(Value2,-100,0,voltage_scale*255, 0);

    
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    
    analogWrite(enB, Speed2);
    }
}

void L298N::set_voltage_scale(float scaling){     //method to change the output voltage stepdown scaling mid program
  voltage_scale = scaling;
  
}


float L298N::return_voltage_scaling(){            //return the stepdown voltage scaling factor
  return voltage_scale;
}
