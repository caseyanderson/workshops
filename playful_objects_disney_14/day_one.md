# Intro to Electronics / Arduino
*Disney, Casey Anderson*

note: unless otherwise noted, these examples come packaged with the arduino software

### Intro / Examples
[Be Our Guest](http://www.youtube.com/watch?v=afzmwAKUppU), beauty and the beast
[Laughing Furniture](http://www.metacafe.com/watch/mv-EsVn/evil_dead_ii_evil_furniture), evil dead 2
[Animism and Interaction Design](http://www.philvanallen.com/animism-interaction-design/), phil van allen
[The Macguffin Library](http://noamtoran.com/NT2009/projects/the-macguffin-library), noam toran
[Desire Management](http://noamtoran.com/NT2009/projects/desire-management), noam toran
[Androp: Worlds Words Lights](http://yurisuzuki.com/works/robots-for-music-video/), yuri suzuki, kimura, tomoaki yanagisawa

### Parts
Sparkfun
Adafruit
All Electronics
DigiKey
Jameco

### Tutorials
Arduino
Adafruit
Sparkfun

### The Electronics
(assumes usage of the Arduino Uno)

For a comprehensive overview of the Uno, go [here](http://arduino.cc/en/Main/ArduinoBoardUno).

The Uno is based on the ATmega328, the datasheet for which you can find [here](http://www.atmel.com/Images/doc8161.pdf).

Get used to looking for datasheets. They are generally published by the manufacturer as a complete resource for how a particular Integrated Circuit functions, containing things like detailed information regarding Current, Voltage, etc. features/requirements, as well as the role of each pin. Any time you are trying to build something that requires an IC you have not used before your first step should be to look for the datasheet. This is almost always accomplished via a simple Google search (example: ATmega328 datasheet).

### Intro to Electronics

Working in the Arduino environment necessarily involves at least a basic understanding of electronics.

So, What is electricity?

Electricity is any flow of electrons

How do we measure electricity? Or, what are we referring to when we measure?
We need to be able to say how many electrons were in the flow.

For example, let's think of the flow of water through a pipe. More specifically, let's imagine that we have a tank of water (atop a tall building), a pipe coming out of it, and a bucket of water. What would we want to know about these things?

Furthermore, let's say that the water has an evenly distributed number of dust particles in it. For example, there are 10 specks of dust in ever cubic centimeter of water...

If x amount of water flows through the pipe, we can calculate the number of specks of dust which have flowed through the pipe.

-or-

By knowing the number of specks of dust which have flowed through the pipe, we can calculate the volume of water.

This is the same with electricity, but instead is measured in coulombs. In this case, the dust specks are electrons.

How would we measure the rate at which the water flows through the pipe and into the bucket?

The “flow rate” would be measured as some volume of water which flowed through the pipe during a defined period of time.

But in our case we refer to flow rate as current, denoted by the symbol I (just imagine that it stands for “intensity”).

Electric Current is measure in amperes (or amps, symbol: A)

1 amp = the quantity of 1 coulomb passing a point in one second.

What else would be useful to know about our tank of water, tube, and bucket?
Flow pressure

Thinking back to our earlier example, we could imagine the building is three stories in one scenario and one story in another. What would be the difference between these two scenarios?

The energy contained in the water in the tank defines the water pressure. In other words, the higher the water tank, the more energy potentially exists if it were to flow.

With electricity, flow pressure is defined by the difference in numbers of electrons between two points. We refer to this as a potential difference because the difference depends on the positions of the points and how many electrons potentially exist.

Let's imagine another scenario in which we have a battery powering a small lightbulb. We could describe the order of events as follows:

1. battery generates electrons at one terminal and takes in electrons at the other terminal
2. bulb lights up as electrons flow around the circuit
3. electrons flow around the circuit due to potential difference of battery

A battery forces electrons around a circuit only when the circuit is complete. If it is not connected, no electrons flow, but the battery still has the POTENTIAL to make them flow.

If we were to disconnect the circuit, the scenario would change as follows:

1. Even though battery is not connected to the bulb, it still has the potential to light the bulb
2. Bulb is not lit up, no electrons flow
3. The circuit is disconnected, so no electrons can flow

Since the two terminals are not connected via the circuit, electrons cannot flow. Air, an insulator, prevents them from jumping from one conductor to the other.

Nonetheless, a battery has the POTENTIAL to light the bulb and so the difference in numbers of electrons between two points (terminals) is known as the potential difference.

This is normally referred to as voltage, or volts, and normally symbolized with a V.

The higher the voltage, the harder a cell can force electrons around a circuit
  so, voltage is a way of expressing electrical pushing power.

Resistors
used to control current and voltage in specified ways

it would be impractical to have resistors of every possible value...there would be millions

so, there is an agreed upon range of values, however made within a certain tolerance

  RESISTOR TOLERANCE – specified as a plus or minus percentage

  A 10ohm plus/minus 10% resistor

    -so, what is the actual range?
    9-11ohms

  resistors are also rated by the amount of power they can safely dissipate as heat without being   damaged.
    -this is the power rating, measured in watts
    typical resistors – 1/4W, 1/3W, 1/2W, etc.
    in other words, exceeding this value will likely melt the componen

  generally – higher the resister, the less current flows...

Ohm's Law
  volts - “pushing power”
  amps - “rate of electron flow”

  3V
  vs
  4V

  V/I = a constant
    -where the constant depends on the substance through which current flows and voltage is 
    applied across

  Draw picture
1. Cell has 2V
2. current of 0.4A
3. substance with a resistance of 5ohms

  cell has a voltage of 2V, so the voltage applied across the substance is also 2V.

  The current through the substance is 0.4A

  Ohm's Law:
    2V/0.4A = 5ohms
  the constant is commonly called the substance's resistance and is given the unit omega
    -pronounced ohm

  So the resistance is 5ohms
    -sometimes people use the letter R instead of omega

  So, if a voltage (V, measured in volts) is applied across a resistance (R, measured in ohms), a current (I, measured in amps) will flow.

  In other words: V/I = R

  What does the current depend on?
    -values of resistance and voltage
  
  How would you determine the current if you already knew the voltage?
    How would we do this with our example?
    V/R = I
    2V/5ohms = 0.4A

  So, what would a voltage of 10V, applied across a resistance of 20ohms, produce a current of?

    First, let's write this out:
    10V/20ohms = 0.5A

  What if we know the resistance and current and want to deduce the voltage?
    -in other words, if we have a resistance, and a current is made to flow through it, then a 
    voltage is produced across it
      how would we write this?
      V = IR
      5ohms x 0.4A = 2V

  What if we had a current of 1A flowing through a resistance of 5ohms
    how would we write this?
      1A * 5ohms = 5V
  
  Another way to remember
    draw triangle
    Cover up the missing one and do the calculation
    V/R = I
    V/I = R
    IR = V
    RI = V

  Note: voltage always applied ACROSS
    why?
      It is the force that pushes electrons...the pushing power
    
    current always flows THROUGH
    why?
      It is the rate at which electrons flow through



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