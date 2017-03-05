/* 
 MAE 322
 2/28/2017
 Robot Motion Script version 0.1 (not stable)
 Authors: Jan Bernhard,
 Last modified: xx/xx/xxxx 

 Discription: This script holds the main commands for the MAE 322 robot.
 Capabilities: 
  - Finds light and drives to it. 
*/
void forwardDistance(){
  /*
   * This function moves forward until it gets too close to an Obstacle.  
   * It checks the proximity to the next object and decides on that basis
   * how fast it will move. 
   */
  //********************** CONSTANTS ***************************************
  int nextObject = proximitySensor;
  int closeDistance = 250; //approximate proximity sensor value at 1 foot
  
  //********************** MAIN OPERATION **********************************
  // call motion module functions with step value
  // start slow for increased friction then switch to fast and back to slow.
  if(nextObject <= tooClose){
    StopBot(500);
    return;
  }
  if(nextObject < closeDistance) {
    Lwheel = left_forward_slow;
    Rwheel = right_forward_slow;
    pulseMotors();
  }
  else {
    Lwheel = left_forward_slow;
    Rwheel = right_forward_slow;
    pulseMotors();
    delay(1000);
    Lwheel = left_forward_fast;
    Rwheel = right_forward_fast;
    pulseMotors();
    delay(1000);
    Lwheel = left_forward_slow;
    Rwheel = right_forward_slow;
    pulseMotors();
    delay(1000);  
  }
}

void tLeft(){
  Lwheel = left_forward_slow;
  Rwheel = right_backward_slow;
  pulseMotors();
}

void tRight(){
  Lwheel = left_backward_slow;
  Rwheel = right_forward_slow;
  pulseMotors();
}

void findLight() {
  /*
   * This function makes the robot search and drive towards a bright light 
   * source. 
   */
 //********************** CONSTANTS ***************************************
  int brightLight; // assign value after determining it emperically
  int foundLight; //min signal value for detecting light
  int tolerance; //error for detecting same signal from both sensors
  int signalDifference = photonSensorL - photonSensorR; //difference between right and left photosensor signal
  

 //********************** MAIN OPERATION **********************************
 //rotate until light is initially found
 if(photonSensorR < foundLight) {
  tRight();
 }
 void loop() {
 //adjust direction toward light
   while(abs(signalDifference) > tolerance) {
    if(signalDifference > tolerance){
     tLeft();
    }
    if(signalDifference < tolerance){
     tRight();
    }
   }
   forwardDistance();
 }
 
}
