/*
using mcp4131 to fade an led

PINOUT
MCP4131 (bottom left of the notch for pin 1, counting counter-clockwise)
Pin 1 = 10
Pin 2 = 13
Pin 3 = 11
pin 4 = GRND
pin 5 = GRND
pin 6 = Pot output
Pin 7 = V+
pin 8 = V+

*/

// inslude the SPI library:
#include <SPI.h>

// set pin 10 as the slave select for the digital pot:
const int slaveSelectPin = 10;
int delayTime = 10;
int potMax = 128;

void setup() {
  // set the slaveSelectPin as an output:
  pinMode(slaveSelectPin, OUTPUT);
  // initialize SPI:
  SPI.begin(); 
}

void loop(){
  //increase resistance
  for(int fadeValue = 0 ; fadeValue <= potMax; fadeValue +=1) { 
    // sets the value (range from 0 to 128):
    digitalPotWrite(fadeValue);         
    // wait for 30 milliseconds
    delay(delayTime);                            
  }
  
  //decrease resistance
    for(int fadeValue = potMax ; fadeValue >= 0; fadeValue -=1) { 
    // sets the value (range from 0 to 128):
    digitalPotWrite(fadeValue);         
    // wait for 30 milliseconds
    delay(delayTime); 
  
}
}

int digitalPotWrite(int value ) {
  // Take the SS/CS pin low to select the chip:
  digitalWrite(slaveSelectPin, LOW);
  // Send in the address and value via SPI:
  SPI.transfer(0);
  SPI.transfer(value);
  // Take the SS/CS pin high to de-select the chip:
  digitalWrite(slaveSelectPin, HIGH); 
}


