
/*
 * This file is designed for any functions associated with the operation of the sumobot that could 
 * require access by both classes and/or other functions
 * 
 * If you choose to write any functions yourself, please include them here as it will keep things neater
 */


float input_voltage = 7.0;      //change this value to whatever the input volage is to the motor driver

float motor_limit = 3.0;        //sumobot kits have a motor rated at 3v, competition sumobots have 9v limit

float voltage_map() {

  if (motor_limit <= input_voltage){    //if the motor voltage limit is less than the input voltage, return the fractional difference
  
    float reduction_ratio = motor_limit/input_voltage;
    Serial.println(reduction_ratio);
    return (reduction_ratio);
  }

 else {                               //if the motor voltage limit higher, then return 1
  return(1);
 }
}

