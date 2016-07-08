
#include "AF_Shield.h"        
#include "Sensors.h"
#include "L298N.h"
#include "Monster.h"
#include "Elecsoc_driver_v1.h"



/*class object names:


Only create one instance of a shield class
  AF_Shield         Adafruit motor shield v1
  L298N             H bridge shield
  Monster           Monster motor shield 
  Elecsoc_driver_v1 Diy motor shield for gen 1 sumobots 

Sensor objects only limited by free pins
  HC_RC04           Standard ultrasonic distance sensor
  digitalLine       digital line sensor (NOTE: can be attached to any free pins)
  analogLine        analog line sensor (NOTE: must be attached to analog pins)
  collision         collision sensor


Check out the txt file for a better description of the classes and their methods

Note: in order to get default constructors to compile (ie when creating an object with no input variables) do not 
include epmty brackets (eg L298N mybot;) 
*/





HC_SR04 distance(9,10);    //distance sensor attached to digital 9 and 10 which are the servo pin headers on adafruit motor shield
AF_Shield mybot(1,2);      //adafruit motor shield configured to use terminal block 1 as left and terminal block 2 as right
L298N mybot2; 


void setup() {
  // put your setup code here, to run once:
 
mybot.drive(100);
delay(1000);
mybot.drive(-100);
delay(1000);
mybot.turn_left(100);
delay(1000);
mybot.turn_right(100);
delay(100);
mybot.arc(100,50);
delay(1000);
mybot.arc(50,100);


Serial.begin(9600);

}

void loop() {
Serial.println(distance.ping());  //print out the distance 

delay(1000);

mybot2.drive(100);
}

