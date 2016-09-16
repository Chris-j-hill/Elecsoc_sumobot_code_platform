//This code is an adaption and extension of the adaruit motor library, 
//designed for UCD Electronic and Electricl engineering society. The 
//purpose of the code is to aid in the introductionary development of sumo bots.




    // Adafruit Motor shield library
    // copyright Adafruit Industries LLC, 2009
    // this code is public domain, enjoy!
    


#ifndef _AFMotor_h_
#define _AFMotor_h_

#include <inttypes.h>
#if defined(__AVR__)
    #include <avr/io.h>

    #define MOTOR12_64KHZ _BV(CS20)             // no prescale
    #define MOTOR12_8KHZ _BV(CS21)              // divide by 8
    #define MOTOR12_2KHZ _BV(CS21) | _BV(CS20)  // divide by 32
    #define MOTOR12_1KHZ _BV(CS22)              // divide by 64

    #define MOTOR34_64KHZ _BV(CS00)             // no prescale
    #define MOTOR34_8KHZ _BV(CS01)              // divide by 8
    #define MOTOR34_1KHZ _BV(CS01) | _BV(CS00)  // divide by 64
    
    #define DC_MOTOR_PWM_RATE   MOTOR34_8KHZ    // PWM rate for DC motors
    #define STEPPER1_PWM_RATE   MOTOR12_64KHZ   // PWM rate for stepper 1
    #define STEPPER2_PWM_RATE   MOTOR34_64KHZ   // PWM rate for stepper 2
    

#endif

// Bit positions in the 74HCT595 shift register output
#define MOTOR1_A 2
#define MOTOR1_B 3
#define MOTOR2_A 1
#define MOTOR2_B 4
#define MOTOR4_A 0
#define MOTOR4_B 6
#define MOTOR3_A 5
#define MOTOR3_B 7

// Constants that the user passes in to the motor calls
#define FORWARD 1
#define BACKWARD 2
#define BRAKE 3
#define RELEASE 4



// Arduino pin names for interface to 74HCT595 latch
#define MOTORLATCH 12
#define MOTORCLK 4
#define MOTORENABLE 7
#define MOTORDATA 8

class AFMotorController
{
  public:
    AFMotorController(void);
    void enable(void);
    friend class AF_Shield;
    void latch_tx(void);
    uint8_t TimerInitalized;
};






//          AF_Shield class methods

class AF_Shield
{
 public:
  AF_Shield(uint8_t motor1, uint8_t motor2, uint8_t freq = DC_MOTOR_PWM_RATE);
  void drive(int Value);      //drive frowards or backward in straight line
  void setSpeed(uint8_t speed);     //set the speed without changing the current drive state
  void turn_left(int Value);  //turn motors in oposite directions at equal rates
  void turn_right(int Value);
  void arc(int Value1, int Value2);  //specify exact motor speeds for traveling in an arc


 private:
  uint8_t motor1, motor2, pwmfreq;
};

uint8_t getlatchstate(void);

#endif
