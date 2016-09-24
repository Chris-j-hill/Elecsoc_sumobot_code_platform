//This driver is based off the instructable available here: http://www.instructables.com/id/DIY-Arduino-Motor-Shield-L298N-Chip-2-4-Amps-/
//This code is base off the big dade code written by Cormac OMeadhra and has been adapted for integration in this project

//class for the elecsoc motor diver first built in 2015 for elecsocs gen 1 sumobots.


class Elecsoc_driver_v1{
private:
  int Left1;
  int Left2;
  int Right1;
  int Right2;
  float voltage_scale;


public:
  //    constructor
  Elecsoc_driver_v1(float scale);                //no alternative pin setup, just include voltage scaling factor
  
  
  //    drive methods
  void drive(int Value);              
  void turn_left(int Value);    
  void turn_right(int Value);
  void arc(int Value1, int Value2); 


  //    voltage scaling controls
  void set_voltage_scale(float scale); //change voltage scaling multiplier
  float return_voltage_scaling();      //read voltage scaling

};

