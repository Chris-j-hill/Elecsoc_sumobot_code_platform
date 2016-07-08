//This driver is based off the instructable available here: http://www.instructables.com/id/DIY-Arduino-Motor-Shield-L298N-Chip-2-4-Amps-/
//This code is base off the big dade code written by Cormac OMeadhra and has been adapted for integration in this project

//class for the elecsoc motor diver first built in 2015 for elecsocs gen 1 sumobots.


class Elecsoc_driver_v1{
private:
  int Left1;
  int Left2;
  int Right1;
  int Right2;


public:
  Elecsoc_driver_v1();                //no alternative pin setup 
  void drive(int Value);              
  void turn_left(int Value);    
  void turn_right(int Value);
  void arc(int Value1, int Value2);  
};

