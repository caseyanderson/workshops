# Intro to Arduino
*Media Design Practices, 2/12/14, Casey Anderson*

note: unless otherwise noted, these examples come packaged with the arduino software

### The Electronics
(assumes usage of the Arduino Uno)

For a comprehensive overview of the Uno, go [here](http://arduino.cc/en/Main/ArduinoBoardUno).

The Uno is based on the ATmega328, the datasheet for which you can find [here](http://www.atmel.com/Images/doc8161.pdf).

Get used to looking for datasheets. They are generally published by the manufacturer as a complete resource for how a particular Integrated Circuit functions, containing things like detailed information regarding Current, Voltage, etc. features/requirements, as well as the role of each pin. Any time you are trying to build something that requires an IC you have not used before your first step should be to look for the datasheet. This is almost always accomplished via a simple Google search (example: ATmega328 datasheet).

### BareMinimum
Here is the basic structure for almost every Arduino program you will need to implement:
```arduino
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly: 
  
}
```
The lines of code that start with two forward slashes are ignored by the Arduino and are known as comments. You can use these to leave yourself notes, or to explain parts of your code to other users (which is considered best practice).

```void setup()``` vs. ```void loop()```
Whatever code is placed in ```void setup()``` will be called once immediately when the application starts. It will not be called again. Therefore, this is a good place to declare variables, pin modes, start using libraries, etc.

The ```loop()``` function is called repeatedly from then on. So, any component of your code that accepts changing values (for example, monitoring live sensor input) should go here.

### Blinking LED
```
int led = 13;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);     
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);               // wait for a second
}
```
We start by declaring a variable named ```led``` of data type ```int```. ```int``` is short for integer, or any whole number. This is a different data type than a ```float``` (floating point, or decimal number) or ```string``` (unicode text character), and Arduino needs to know ahead of time what type of data is going to be held in any variable. The equals sign is an assignment operator. It tells Arduino that the variable named led is assigned the value 13. This is different than the ```==``` sign, which is the way to test to see if some variable is a particular value.

Next we have ```void setup()```
Here we set the ```pinMode```. ```pinMode()``` allows us to set a particular pin as either an output or an input. In order to do this, we need to tell ```pinMode``` which pin we are referring to as well as whether it will be an input (```INPUT```) or output (```OUTPUT```). Since we already told the interpreter that the variable led has the value 13, we can just use ```led``` in the space of the first parameter (for pin number), and then the word ```OUTPUT``` (all caps) in the second parameter.

As discussed earlier, ```void loop()``` runs repeatedly. We are alternating between two kinds of code in this example: ```digitalWrite```, and ```delay```. ```digitalWrite()``` writes a ```HIGH``` or ```LOW``` value to a digital pin. We can think of ```HIGH``` as “on” and ```LOW``` as “off,” but the more accurate way to imagine what is happening is that ```HIGH``` is the power source value (either 5V or 3.3V) and ```LOW``` is ground (or 0V). In the first line of code, we turn the LED on.

```delay()``` pauses the program for however many milliseconds one has entered into its parameter. If we did not have delay here, we would likely not see our LED turn on at all. So, here, the LED is turned on, and then the entire program is paused for 1 second.

Hopefully the next two lines of code now make sense: the LED is turned off, and then the entire program is paused for another second, at which point the ```loop()``` function repeats.

When using ```delay()```, all other functions/processes happening in your program will be paused. In other words, nothing happens during a ```delay()```. So, though this is fine for a simple blinking LED, if you were trying to control the time-flow of simultaneous functions at different intervals, you would want to use ```millis()```. The Arduino website recommends avoiding the use of ```delay()``` unless you are only pausing the program for 10s of milliseconds, favoring ```millis()``` for more substantial, human-noticeable amounts of time.

### Fade
```/*
 Fade
 
 This example shows how to fade an LED on pin 9
 using the analogWrite() function.
 
 This example code is in the public domain.
 */

int led = 9;           // the pin that the LED is attached to
int brightness = 0;    // how bright the LED is
int fadeAmount = 5;    // how many points to fade the LED by

// the setup routine runs once when you press reset:
void setup()  { 
  // declare pin 9 to be an output:
  pinMode(led, OUTPUT);
} 

// the loop routine runs over and over again forever:
void loop()  { 
  // set the brightness of pin 9:
  analogWrite(led, brightness);    

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade: 
  if (brightness == 0 || brightness == 255) {
    fadeAmount = -fadeAmount ; 
  }     
  // wait for 30 milliseconds to see the dimming effect    
  delay(30);                            
}
```
Open the Blink and Fade examples and compare/contrast them. Are there any key differences between the two?
### Voltage Dividers

A voltage divider is any circuit that produces an output that is a fraction of its input. For example:

![voltage_divider.png](voltage_divider.png?raw=true)

The above diagram represents the most basic way to use two resistors (labeled as Z1 and Z2) to take some changing voltage (Vin) and output a fraction of it (Vout). The amount of Vin that is output at Vout depends on the values of the two resistors. This is the basic wiring pattern for almost any sensor input into a microcontroller.

You are probably wondering how to calculate the value of R1 and R2 (fyi: in this case, I am using Z and R interchangeably, but generally Z refers to impedance and R refers to resistance) such that you can get a specific Vout. Here is the formula:

![voltage_divider_formula.png](voltage_divider_formula.png?raw=true)

### Sensors
Let's start with a Potentiometer.

You can think of this as having two ears and a nose. The nose is the output, the ears are inputs. The only thing that matters regarding which ear you use is which direction you turn the knob to increase/decrease resistance.

So, for a pot, to interface with our Arduino:

Nose to any input (example: A0)
Ear 1 to ground
Ear 2 to 5V or 3.3V

Attach a potentiometer to your Arduino and copy the code below into a new window:
```
//Potentiometer testing sketch.

int potPin = 0; // Nose of pot is connected to analog 0
int LEDpin = 11;      // connect Red LED to pin 11 (PWM pin)
int potReading;      // the analog reading from the Potentiometer
int LEDbrightness;

void setup(void) {
  Serial.begin(9600);   // We'll send debugging information via the Serial monitor
  pinMode(LEDpin, OUTPUT);
}

void loop(void) {
  potReading = analogRead(potPin);
  Serial.print("Analog reading = ");
  Serial.println(potReading);

  // we'll need to change the range from the analog reading (0-1023) down to the range
  // used by analogWrite (0-255) with map!

  LEDbrightness = map(potReading, 0, 1023, 0, 255);

  analogWrite(LEDpin, LEDbrightness);
  Serial.print( "LED value = " );
  Serial.println( LEDbrightness );
  delay(10);
}
```
All of this should look more or less familiar, with the exception of ```Serial.begin()```, etc.

The ```Serial``` class is used for communication between Arduino and a computer. Serial enables you to do a lot of things, but in this case it is going to allow us to monitor the value of the potentiometer. We set the serial data rate in bits per second to start serial transmission. Generally, 9600 will be a perfectly fine ```BAUD``` rate to use (particularly when starting out).

```Serial.print```/```println()``` prints the incoming values from the potentiometer to the Serial Monitor.

Lastly, we are mapping the incoming pot reading from ```0 - 1023``` to ```0 - 255```. Any time you need to change the data range of one variable to some other range and do not feel like doing the math, you can simply use ```map()```.

We can use this basic framework for most other sensor input, the only thing that will change is how you attach the sensor to the Arduino.

*homework:* Download the pdf [here](http://caseythomasanderson.com/casey/sensor_workshop_notes.pdf) and try to use the above patch with other sensors.

As an example: modifying our potentiometer code to utilize a flex sensor:
```
// Flex sensor test program

// Sensor pin - GND
// Sensor pin - Analog In 0, with 10K resistor to +5V

// INSTRUCTIONS:
// Upload this sketch to your Arduino, then activate the Serial Monitor
// (set the Serial Monitor to 9600 baud)

int LEDpin = 11;      // connect Red LED to pin 11 (PWM pin)
int LEDbrightness;

void setup()
{
  // initialize serial communications
  Serial.begin(9600); 
}

void loop()
{
  int sensor, degrees;
  
  // read the voltage from the voltage divider (sensor plus resistor)
  sensor = analogRead(0);
  degrees = map(sensor, 768, 853, 0, 90);
  
  LEDbrightness = map( sensor, 768, 853, 0, 255 )l
  analogWrite(LEDpin, LEDbrightness);
  
  // print out the result
  Serial.print("analog input: ");
  Serial.print(sensor,DEC);
  Serial.print("   degrees: ");
  Serial.println(degrees,DEC);
  
  // pause before taking the next reading
  delay(10);                     
}
```
### Smoothing

Sensors are designed to output a changing voltages, but what happens if your sensor is too sensitive or you need to "massage" you data for some reason? We can define any unnecessary information, like the information provided by sensor y in either of the previous cases, as "noise." Certain sensors are so noisey that some amount of work needs to be done to make them not as "nearly random"/more usable. The code below shows one example of how to average x amount of Vin samples (in this case, 10 "samples" or ```Array``` positions) in order to smooth the input to something less chaotic. 

Keep in mind, though, that the smaller the ```Array``` (i.e., the less positions in which it can store samples prior to averaging), the more prone to "noiseyness" your averaged data will be. At the same time, though, a smaller ```Array``` will take less time to fill, and therefore be able to output average amounts more quickly.

On the other side of the spectrum, the longer your ```Array``` (i.e. the more position in which it can store samples prior to averaging), the more "smoothed" the data will be. For a particularly noisey sensor, this might be a good strategy (emphasis on "might"). However, the longer the ```Array```, the more positions need to be filled prior to averaging, which will therefore slow down the rate at which you are getting usable information into the Arduino.
```
/*

  Smoothing

  Reads repeatedly from an analog input, calculating a running average
  and printing it to the computer.  Keeps ten readings in an array and 
  continually averages them.
  
  The circuit:
    * Analog sensor (potentiometer will do) attached to analog input 0

  Created 22 April 2007
  By David A. Mellis  <dam@mellis.org>
  modified 9 Apr 2012
  by Tom Igoe
  http://www.arduino.cc/en/Tutorial/Smoothing
  
  This example code is in the public domain.


*/


// Define the number of samples to keep track of.  The higher the number,
// the more the readings will be smoothed, but the slower the output will
// respond to the input.  Using a constant rather than a normal variable lets
// use this value to determine the size of the readings array.
const int numReadings = 10;

int readings[numReadings];      // the readings from the analog input
int index = 0;                  // the index of the current reading
int total = 0;                  // the running total
int average = 0;                // the average

int inputPin = A0;

void setup()
{
  // initialize serial communication with computer:
  Serial.begin(9600);                   
  // initialize all the readings to 0: 
  for (int thisReading = 0; thisReading < numReadings; thisReading++)
    readings[thisReading] = 0;          
}

void loop() {
  // subtract the last reading:
  total= total - readings[index];         
  // read from the sensor:  
  readings[index] = analogRead(inputPin); 
  // add the reading to the total:
  total= total + readings[index];       
  // advance to the next position in the array:  
  index = index + 1;                    

  // if we're at the end of the array...
  if (index >= numReadings)              
    // ...wrap around to the beginning: 
    index = 0;                           

  // calculate the average:
  average = total / numReadings;         
  // send it to the computer as ASCII digits
  Serial.println(average);   
  delay(1);        // delay in between reads for stability            
}
```