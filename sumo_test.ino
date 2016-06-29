
#include "AF_Shield.h"        
#include "Sensors.h"
#include "L298N.h"




/*class object names:

AF_Shield     Adafruit motor shield v1
L298N         H bridge shield  

HC_RC04       Standard ultrasonic distance sensor
digitalLine   digital line sensor (NOTE: can be attached to any free pins)
analogLine    analog line sensor (NOTE: must be attached to analog pins)
collision     collision sensor


Check out the txt file for a better description of the classes and their methods
*/





HC_SR04 distance(14,15);
AF_Shield mybot(1,2); //left, right
L298N mybot2 ();


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

}

void loop() {

}

