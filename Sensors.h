//
// This file contains the classes for control of the sensors that are used a sumobot
// Classes are provided for distance sensors, both analog and digital line sensors, and collision sensors
//

// class for ultrasonic distance sensor

class HC_SR04{    
  private:        //class variables available to all methods
  int pin_trig;
  int pin_echo;
  int pin1;
  int type;


  
  public:
  HC_SR04 (int trig, int echo);   //standard constructor
  HC_SR04 (int pin);    //alternate constructor in case that trig and echo are wired together
  int ping ();          //get distance
  
};





//class for digital line sensors

class digitalLine{
  private:
  int pin;
  

  public:
  digitalLine(int pin1);
  int read_sensor();
  

  
};


//class for analog line sensors, such as QRD1114 (see here: http://digitalmedia.risd.edu/pbadger/PhysComp/?n=Devices.QRD1114)


class analogLine{
  private:
  int pin;
  int threshold;
   

  public:
  analogLine(int pin1);
  int read_sensor();
  void set_threshold(int thresh);
  
};




class collision{

private:
int pin;

public:
collision(int pin1);
int state();



  
};








