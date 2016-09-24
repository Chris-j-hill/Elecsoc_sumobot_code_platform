//This code is based off the big dade sumobot code written Cormac OMeadhra and 
//has been adapted for integration into this project. 

//class for the monster motor driver shield

class Monster{
private:
  int pin1;
  int pin2;
  int pin3;
  int pin4;
  int speedpin1;
  int speedpin2;

  float voltage_scale;
  

public:
  //    constructor
  Monster(float scale);                  //constructor, there is no choice of pins here and the program assumes you use both motors, just input the voltage scaling factor
  
  
  //    drive methods
  void drive(int Value);      //drive frowards or backward in straight line
  void setSpeed(int Value);     //set the speed without changing the current drive state
  void turn_left(int Value);  //turn motors in oposite directions at equal rates
  void turn_right(int Value);
  void arc(int Value1, int Value2);  //specify exact motor speeds for traveling in an arc

  //    voltage scaling controls
  void set_voltage_scale(float scale); //change voltage scaling multiplier
  float return_voltage_scaling();      //read voltage scaling
  
};

