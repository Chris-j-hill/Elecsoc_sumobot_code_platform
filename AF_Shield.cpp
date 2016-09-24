//
//This code is an adaption and extension of the adaruit motor library, 
//designed for UCD Electronic and Electricl engineering society. The 
//purpose of the code is to aid in the introductionary development of sumo bots.
//


    // Adafruit Motor shield library
    // copyright Adafruit Industries LLC, 2009
    // this code is public domain, enjoy!

//#include "functions"

#if (ARDUINO >= 100)
  #include "Arduino.h"
#else
  #if defined(__AVR__)
    #include <avr/io.h>
  #endif
  #include "WProgram.h"
#endif

#include "AF_Shield.h"



static uint8_t latch_state;



AFMotorController::AFMotorController(void) {
    TimerInitalized = false;
}

void AFMotorController::enable(void) {
  // setup the latch
 
  pinMode(MOTORLATCH, OUTPUT);
  pinMode(MOTORENABLE, OUTPUT);
  pinMode(MOTORDATA, OUTPUT);
  pinMode(MOTORCLK, OUTPUT);

  latch_state = 0;
  latch_tx();  // "reset"
  digitalWrite(MOTORENABLE, LOW);
}


void AFMotorController::latch_tx(void) {
  uint8_t i;
  digitalWrite(MOTORLATCH, LOW);
  digitalWrite(MOTORDATA, LOW);

  for (i=0; i<8; i++) {
    digitalWrite(MOTORCLK, LOW);

    if (latch_state & _BV(7-i)) {
      digitalWrite(MOTORDATA, HIGH);
    }
    else {
      digitalWrite(MOTORDATA, LOW);
    }
    
    digitalWrite(MOTORCLK, HIGH);
  }
  digitalWrite(MOTORLATCH, HIGH);
}

static AFMotorController MC;

/******************************************
               MOTORS
******************************************/
inline void initPWM1(uint8_t freq) {
#if defined(__AVR_ATmega8__) || \
    defined(__AVR_ATmega48__) || \
    defined(__AVR_ATmega88__) || \
    defined(__AVR_ATmega168__) || \
    defined(__AVR_ATmega328P__)
    // use PWM from timer2A on PB3 (Arduino pin #11)
    TCCR2A |= _BV(COM2A1) | _BV(WGM20) | _BV(WGM21); // fast PWM, turn on oc2a
    TCCR2B = freq & 0x7;
    OCR2A = 0;
#elif defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
    // on arduino mega, pin 11 is now PB5 (OC1A)
    TCCR1A |= _BV(COM1A1) | _BV(WGM10); // fast PWM, turn on oc1a
    TCCR1B = (freq & 0x7) | _BV(WGM12);
    OCR1A = 0;

#else
   #error "This chip is not supported!"
#endif
    #if !defined(PIC32_USE_PIN9_FOR_M1_PWM) && !defined(PIC32_USE_PIN10_FOR_M1_PWM)
        pinMode(11, OUTPUT);
    #endif
}

inline void setPWM1(uint8_t s) {
#if defined(__AVR_ATmega8__) || \
    defined(__AVR_ATmega48__) || \
    defined(__AVR_ATmega88__) || \
    defined(__AVR_ATmega168__) || \
    defined(__AVR_ATmega328P__)
    // use PWM from timer2A on PB3 (Arduino pin #11)
    OCR2A = s;
#elif defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
    // on arduino mega, pin 11 is now PB5 (OC1A)
    OCR1A = s;

#else
   #error "This chip is not supported!"
#endif
}

inline void initPWM2(uint8_t freq) {
#if defined(__AVR_ATmega8__) || \
    defined(__AVR_ATmega48__) || \
    defined(__AVR_ATmega88__) || \
    defined(__AVR_ATmega168__) || \
    defined(__AVR_ATmega328P__)
    // use PWM from timer2B (pin 3)
    TCCR2A |= _BV(COM2B1) | _BV(WGM20) | _BV(WGM21); // fast PWM, turn on oc2b
    TCCR2B = freq & 0x7;
    OCR2B = 0;
#elif defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
    // on arduino mega, pin 3 is now PE5 (OC3C)
    TCCR3A |= _BV(COM1C1) | _BV(WGM10); // fast PWM, turn on oc3c
    TCCR3B = (freq & 0x7) | _BV(WGM12);
    OCR3C = 0;

#else
   #error "This chip is not supported!"
#endif

    pinMode(3, OUTPUT);
}

inline void setPWM2(uint8_t s) {
#if defined(__AVR_ATmega8__) || \
    defined(__AVR_ATmega48__) || \
    defined(__AVR_ATmega88__) || \
    defined(__AVR_ATmega168__) || \
    defined(__AVR_ATmega328P__)
    // use PWM from timer2A on PB3 (Arduino pin #11)
    OCR2B = s;
#elif defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
    // on arduino mega, pin 11 is now PB5 (OC1A)
    OCR3C = s;

#else
   #error "This chip is not supported!"
#endif
}

inline void initPWM3(uint8_t freq) {
#if defined(__AVR_ATmega8__) || \
    defined(__AVR_ATmega48__) || \
    defined(__AVR_ATmega88__) || \
    defined(__AVR_ATmega168__) || \
    defined(__AVR_ATmega328P__)
    // use PWM from timer0A / PD6 (pin 6)
    TCCR0A |= _BV(COM0A1) | _BV(WGM00) | _BV(WGM01); // fast PWM, turn on OC0A
    //TCCR0B = freq & 0x7;
    OCR0A = 0;
#elif defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
    // on arduino mega, pin 6 is now PH3 (OC4A)
    TCCR4A |= _BV(COM1A1) | _BV(WGM10); // fast PWM, turn on oc4a
    TCCR4B = (freq & 0x7) | _BV(WGM12);
    //TCCR4B = 1 | _BV(WGM12);
    OCR4A = 0;

#else
   #error "This chip is not supported!"
#endif
    pinMode(6, OUTPUT);
}

inline void setPWM3(uint8_t s) {
#if defined(__AVR_ATmega8__) || \
    defined(__AVR_ATmega48__) || \
    defined(__AVR_ATmega88__) || \
    defined(__AVR_ATmega168__) || \
    defined(__AVR_ATmega328P__)
    // use PWM from timer0A on PB3 (Arduino pin #6)
    OCR0A = s;
#elif defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
    // on arduino mega, pin 6 is now PH3 (OC4A)
    OCR4A = s;

#else
   #error "This chip is not supported!"
#endif
}



inline void initPWM4(uint8_t freq) {
#if defined(__AVR_ATmega8__) || \
    defined(__AVR_ATmega48__) || \
    defined(__AVR_ATmega88__) || \
    defined(__AVR_ATmega168__) || \
    defined(__AVR_ATmega328P__)
    // use PWM from timer0B / PD5 (pin 5)
    TCCR0A |= _BV(COM0B1) | _BV(WGM00) | _BV(WGM01); // fast PWM, turn on oc0a
    //TCCR0B = freq & 0x7;
    OCR0B = 0;
#elif defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
    // on arduino mega, pin 5 is now PE3 (OC3A)
    TCCR3A |= _BV(COM1A1) | _BV(WGM10); // fast PWM, turn on oc3a
    TCCR3B = (freq & 0x7) | _BV(WGM12);
    //TCCR4B = 1 | _BV(WGM12);
    OCR3A = 0;

#else
   #error "This chip is not supported!"
#endif
    pinMode(5, OUTPUT);
}

inline void setPWM4(uint8_t s) {
#if defined(__AVR_ATmega8__) || \
    defined(__AVR_ATmega48__) || \
    defined(__AVR_ATmega88__) || \
    defined(__AVR_ATmega168__) || \
    defined(__AVR_ATmega328P__)
    // use PWM from timer0A on PB3 (Arduino pin #6)
    OCR0B = s;
#elif defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
    // on arduino mega, pin 6 is now PH3 (OC4A)
    OCR3A = s;

#else
   #error "This chip is not supported!"
#endif
}














//      AF_Shield class methods



AF_Shield::AF_Shield(uint8_t num1, uint8_t num2, float scale, uint8_t freq) {

  voltage_scale = scale;

  if (num1 ==num2) {       //error prevention, will stop same terminal being set as both motors
    Serial.println("motor terminals cannot be the same for both motors");
    return;
  }
  motor1 = num1;
  motor2 = num2;
  pwmfreq = freq;

  MC.enable();

  switch (num1) {
  case 1:
    latch_state &= ~_BV(MOTOR1_A) & ~_BV(MOTOR1_B); // set both motor pins to 0
    MC.latch_tx();
    initPWM1(freq);
    break;
  case 2:
    latch_state &= ~_BV(MOTOR2_A) & ~_BV(MOTOR2_B); // set both motor pins to 0
    MC.latch_tx();
    initPWM2(freq);
    break;
  case 3:
    latch_state &= ~_BV(MOTOR3_A) & ~_BV(MOTOR3_B); // set both motor pins to 0
    MC.latch_tx();
    initPWM3(freq);
    break;
  case 4:
    latch_state &= ~_BV(MOTOR4_A) & ~_BV(MOTOR4_B); // set both motor pins to 0
    MC.latch_tx();
    initPWM4(freq);
    break;
  }


  switch (num2) {
  case 1:
    latch_state &= ~_BV(MOTOR1_A) & ~_BV(MOTOR1_B); // set both motor pins to 0
    MC.latch_tx();
    initPWM1(freq);
    break;
  case 2:
    latch_state &= ~_BV(MOTOR2_A) & ~_BV(MOTOR2_B); // set both motor pins to 0
    MC.latch_tx();
    initPWM2(freq);
    break;
  case 3:
    latch_state &= ~_BV(MOTOR3_A) & ~_BV(MOTOR3_B); // set both motor pins to 0
    MC.latch_tx();
    initPWM3(freq);
    break;
  case 4:
    latch_state &= ~_BV(MOTOR4_A) & ~_BV(MOTOR4_B); // set both motor pins to 0
    MC.latch_tx();
    initPWM4(freq);
    break;
  }
}




//     Standard drive function


void AF_Shield::drive(int Value) {    //  Value can be positive or negative
  uint8_t a, b, c, d;
  switch (motor1) {
  case 1:
    a = MOTOR1_A; b = MOTOR1_B; break;
  case 2:
    a = MOTOR2_A; b = MOTOR2_B; break;
  case 3:
    a = MOTOR3_A; b = MOTOR3_B; break;
  case 4:
    a = MOTOR4_A; b = MOTOR4_B; break;
  default:
    return;
  }

switch (motor2) {
  case 1:
    c = MOTOR1_A; d = MOTOR1_B; break;
  case 2:
    c = MOTOR2_A; d = MOTOR2_B; break;
  case 3:
    c = MOTOR3_A; d = MOTOR3_B; break;
  case 4:
    c = MOTOR4_A; d = MOTOR4_B; break;
  default:
    return;
  }
  
  int modValue = abs(Value);      // Get the absolute speed value and map to byte value
  int Speed = map(modValue, 0, 100, 0, voltage_scale*255);
  Serial.println(voltage_scale);
  
  
  if (Value <0){      //drive backwards
    if (Value <= -100)   { Value = -100;}  //correct value if outside range

    latch_state &= ~_BV(a); //set pin states for reverse driving
    latch_state |= _BV(b); 
    latch_state &= ~_BV(c);
    latch_state |= _BV(d); 
    MC.latch_tx();
  } 

   
  else if (Value >=0){ //Drive forward
    if (Value >= 100)   { Value = 100;}  //correct value if outside range

    latch_state |= _BV(a);  //set pin states for forward driving
    latch_state &= ~_BV(b);
    latch_state |= _BV(c);
    latch_state &= ~_BV(d); 
    MC.latch_tx();
    }

    switch (motor1) {     //Set motor speeds (direction already defined by latch states)
    case 1:
      setPWM1(Speed); break;
    case 2:
      setPWM2(Speed); break;
    case 3:
      setPWM3(Speed); break;
    case 4:
      setPWM4(Speed); break;
    }
  
    switch (motor2) {
    case 1:
      setPWM1(Speed); break;
    case 2:
      setPWM2(Speed); break;
    case 3:
      setPWM3(Speed); break;
    case 4:
      setPWM4(Speed); break;
    }  
  
}


void AF_Shield::setSpeed(uint8_t speed) {
  switch (motor1) {
  case 1:
    setPWM1(speed); break;
  case 2:
    setPWM2(speed); break;
  case 3:
    setPWM3(speed); break;
  case 4:
    setPWM4(speed); break;
  }

  switch (motor2) {
  case 1:
    setPWM1(speed); break;
  case 2:
    setPWM2(speed); break;
  case 3:
    setPWM3(speed); break;
  case 4:
    setPWM4(speed); break;
  }
}




void AF_Shield::turn_left(int Value){
uint8_t a, b, c, d;
  switch (motor1) {
  case 1:
    a = MOTOR1_A; b = MOTOR1_B; break;
  case 2:
    a = MOTOR2_A; b = MOTOR2_B; break;
  case 3:
    a = MOTOR3_A; b = MOTOR3_B; break;
  case 4:
    a = MOTOR4_A; b = MOTOR4_B; break;
  default:
    return;
  }

switch (motor2) {
  case 1:
    c = MOTOR1_A; d = MOTOR1_B; break;
  case 2:
    c = MOTOR2_A; d = MOTOR2_B; break;
  case 3:
    c = MOTOR3_A; d = MOTOR3_B; break;
  case 4:
    c = MOTOR4_A; d = MOTOR4_B; break;
  default:
    return;
  }

  int modValue = abs(Value);      // Get the absolute speed value and map to byte value
  int Speed = map(modValue, 0, 100, 0, voltage_scale*255);
  

  if (Value <0){      //turn right, incase negative speed entered
    if (Value <= -100)   { Value = -100;}  //correct value if outside range

    latch_state |= _BV(a);
    latch_state &= ~_BV(b); 
    latch_state &= ~_BV(c);
    latch_state |= _BV(d); 
    MC.latch_tx();
  } 

   
  else if (Value >=0){ //turn left
    if (Value >= 100)   { Value = 100;}  //correct value if outside range

    latch_state &= ~_BV(a);
    latch_state |= _BV(b); 
    latch_state |= _BV(c);
    latch_state &= ~_BV(d); 
    MC.latch_tx();
    
    }

    switch (motor1) {     //Set motor speeds (direction already defined by latch states)
    case 1:
      setPWM1(Speed); break;
    case 2:
      setPWM2(Speed); break;
    case 3:
      setPWM3(Speed); break;
    case 4:
      setPWM4(Speed); break;
    }
  
    switch (motor2) {
    case 1:
      setPWM1(Speed); break;
    case 2:
      setPWM2(Speed); break;
    case 3:
      setPWM3(Speed); break;
    case 4:
      setPWM4(Speed); break;
    }  
  
}


void AF_Shield::turn_right(int Value){
uint8_t a, b, c, d;
  switch (motor1) {
  case 1:
    a = MOTOR1_A; b = MOTOR1_B; break;
  case 2:
    a = MOTOR2_A; b = MOTOR2_B; break;
  case 3:
    a = MOTOR3_A; b = MOTOR3_B; break;
  case 4:
    a = MOTOR4_A; b = MOTOR4_B; break;
  default:
    return;
  }

switch (motor2) {
  case 1:
    c = MOTOR1_A; d = MOTOR1_B; break;
  case 2:
    c = MOTOR2_A; d = MOTOR2_B; break;
  case 3:
    c = MOTOR3_A; d = MOTOR3_B; break;
  case 4:
    c = MOTOR4_A; d = MOTOR4_B; break;
  default:
    return;
  }

  int modValue = abs(Value);      // Get the absolute speed value and map to byte value
  int Speed = map(modValue, 0, 100, 0, voltage_scale*255);
  

  if (Value <0){      //turn left, incase negative speed entered
    if (Value <= -100)   { Value = -100;}  //correct value if outside range

    latch_state &= ~_BV(a);
    latch_state |= _BV(b); 
    latch_state |= _BV(c);
    latch_state &= ~_BV(d); 
    MC.latch_tx();
    
  } 

   
  else if (Value >=0){ //turn right
    if (Value >= 100)   { Value = 100;}  //correct value if outside range

    latch_state |= _BV(a);
    latch_state &= ~_BV(b); 
    latch_state &= ~_BV(c);
    latch_state |= _BV(d); 
    MC.latch_tx();
    
    }

    switch (motor1) {     //Set motor speeds (direction already defined by latch states)
    case 1:
      setPWM1(Speed); break;
    case 2:
      setPWM2(Speed); break;
    case 3:
      setPWM3(Speed); break;
    case 4:
      setPWM4(Speed); break;
    }
  
    switch (motor2) {
    case 1:
      setPWM1(Speed); break;
    case 2:
      setPWM2(Speed); break;
    case 3:
      setPWM3(Speed); break;
    case 4:
      setPWM4(Speed); break;
    }  
  
}





void AF_Shield::arc(int Value1, int Value2){
uint8_t a, b, c, d;
  switch (motor1) {
  case 1:
    a = MOTOR1_A; b = MOTOR1_B; break;
  case 2:
    a = MOTOR2_A; b = MOTOR2_B; break;
  case 3:
    a = MOTOR3_A; b = MOTOR3_B; break;
  case 4:
    a = MOTOR4_A; b = MOTOR4_B; break;
  default:
    return;
  }

switch (motor2) {
  case 1:
    c = MOTOR1_A; d = MOTOR1_B; break;
  case 2:
    c = MOTOR2_A; d = MOTOR2_B; break;
  case 3:
    c = MOTOR3_A; d = MOTOR3_B; break;
  case 4:
    c = MOTOR4_A; d = MOTOR4_B; break;
  default:
    return;
  }

  int modValue1 = abs(Value1);      // Get the absolute speed value and map to byte value
  int Speed1 = map(modValue1, 0, 100, 0, voltage_scale*255);

  int modValue2 = abs(Value2);      // Get the absolute speed value and map to byte value
  int Speed2 = map(modValue2, 0, 100, 0, voltage_scale*255);

  if (Value1 <0){      //turn motor 1 backwards
    if (Value1 <= -100)   { Value1 = -100;}  //correct value if outside range

    latch_state &= ~_BV(a); //set pin states for reverse driving
    latch_state |= _BV(b); 
    MC.latch_tx();
    
  } 

   
  else if (Value1 >=0){ //turn motor 1 forwards
    if (Value1 >= 100)   { Value1 = 100;}  //correct value if outside range

    latch_state |= _BV(a);  //set pin states for forward driving
    latch_state &= ~_BV(b);
    MC.latch_tx();
    
    }


if (Value2 <0){      //turn motor 1 backwards
    if (Value2 <= -100)   { Value1 = -100;}  //correct value if outside range

    latch_state &= ~_BV(c); //set pin states for reverse driving
    latch_state |= _BV(d); 
    MC.latch_tx();
    
  } 

   
  else if (Value2 >=0){ //turn motor 1 forwards
    if (Value2 >= 100)   { Value1 = 100;}  //correct value if outside range

    latch_state |= _BV(c);  //set pin states for forward driving
    latch_state &= ~_BV(d);
    MC.latch_tx();
    
    }

    switch (motor1) {     //Set motor speeds (direction already defined by latch states)
    case 1:
      setPWM1(Speed1); break;
    case 2:
      setPWM2(Speed1); break;
    case 3:
      setPWM3(Speed1); break;
    case 4:
      setPWM4(Speed1); break;
    }
  
    switch (motor2) {
    case 1:
      setPWM1(Speed2); break;
    case 2:
      setPWM2(Speed2); break;
    case 3:
      setPWM3(Speed2); break;
    case 4:
      setPWM4(Speed2); break;
    }  
  
}


void AF_Shield::set_voltage_scale(float scaling){     //method to change the output voltage stepdown scaling mid program
  
  voltage_scale = scaling;                            //NOTE: do not use this method without full understanding of the result
                                                      //of changing the scaling factor (ie added strain on motors/drivers)
  
}


float AF_Shield::return_voltage_scaling(){            //return the stepdown voltage scaling factor
  return voltage_scale;
}
  



