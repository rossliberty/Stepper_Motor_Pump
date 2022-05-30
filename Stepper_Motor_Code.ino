//***************************************************************************
// - Liberty Produce - Ross Lambert
// - Arduino
//This program runs a stepper motor pump using a TB6600 driver.
//The Enable, DIR and Pulse negative on the driver are all connected to
// ground.
// The stepper motor is an 8 wire (4 coils) and has been wired in parrallel. 
// See wiring drawing in same folder.
// https://knowledge.ni.com/KnowledgeArticleDetails?id=kA00Z000000PAkPSAW
//***************************************************************************
// Connections from driver to Arduino:
// Enable (+) = pin 10 on Arduino
// DIR (+) = pin 3 on Arduino
// Pulse (+) = pin 2 on Arduino (STEPPIN)
// 
//Globals

// Pins that connect the Arduino to the TB6600 driver
#define STEPPIN 2 // This is sometimes labelled as Pul on the driver
#define DIRPIN 3
#define ENAPIN 4

// Variable to hold value to delay for freq of pulse.
// The pump has a max speed that pumps 800ml/min which 
// is a value of 650 microseconds delay in our code. Remember
// the delay happens twice so we have a duty cycle of 1300.
// 1/1300 gives us a frequency of 0.77mHz.

// Change the delay, called STEPTIME to change pump speed.

// Range - 500 to 2500

// Delay : ml pumped - higher value less water pumped


const int STEPTIME = 1250; 

void setup() {

  Serial.begin(9600);
 // Set pins as output
  pinMode(STEPPIN,OUTPUT);
  pinMode(DIRPIN,OUTPUT);
  pinMode(ENAPIN,OUTPUT);
  
}

void loop() {

Pump();

}

void Pump(){
  
  digitalWrite(ENAPIN,LOW);//ENABLE IS ACTIVE LOW
  digitalWrite(DIRPIN,HIGH);//SET DIRECTION
  //Move pump 
  digitalWrite(STEPPIN,HIGH);
  delayMicroseconds(STEPTIME);
  digitalWrite(STEPPIN,LOW);
  delayMicroseconds(STEPTIME);
  }
