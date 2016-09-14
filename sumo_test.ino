
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



AF_Shield mybot(1,2);        //adafruit motor shield configured to use terminal block 1 as left and terminal block 2 as right

HC_SR04 distance(14, 15);    //distance sensor attached to Analog pin A0 (also called pin 14) and A1 (15) 
digitalLine left_line (16);  //line sensor connected to A3 (also called pin 16)
digitalLine right_line (17); //line sensor connected to A4 (also called pin 17)


void setup() {
  // put your setup code here, to run once:
 

Serial.begin(9600);       //establish communication link datarate

}

void loop() {

int temp;

mybot.drive(100);               //drive forward for 3 seconds
Serial.println("forward");
delay(3000);

mybot.drive(-100);              //reverse for 3 seconds
Serial.println("backwards");
delay(3000);

mybot.turn_left(100);           //turn left
Serial.println("turn_left");
delay(3000);

mybot.turn_right(100);          //turn right
Serial.println("turn_right");
delay(3000);

temp = distance.ping();         //set value of temp equal to the current distance reading
Serial.print("distance: ");     //print result to screen
Serial.println(temp);
delay(10);

temp = left_line.read_sensor(); //reuse temp variable, set it to left line sensor reading
Serial.print("see line left: ");
Serial.println(temp);
delay(10);

temp = right_line.read_sensor();  //reuse temp variable, set it to right line sensor reading
Serial.print("see line right: ");
Serial.println(temp);
delay(10);


}

