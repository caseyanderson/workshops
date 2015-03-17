/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

long randNumberRest;  //allows for random wait time
int minRest = 50;
int maxRest = 3500;

long randPos;        //allows for random pos
int maxPos = 180;
int pos = 0;    // variable to store the servo position


void setup()
{
  Serial.begin(9600);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop()
{

  randPos = random(maxPos);
  for (pos = 0; pos <= randPos; pos += 20) // goes from 0 degrees to 180 degrees
  { // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(2);                       // waits 15ms for the servo to reach the position
  }
  
  randNumberRest = random(minRest, maxRest);
  Serial.print( "random pos up is ");
  Serial.println(randNumberRest);
  delay(randNumberRest);

  for (pos = randPos; pos >= 0; pos -= 20) // goes from 180 degrees to 0 degrees
  {
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(2);                       // waits 15ms for the servo to reach the position
  }
  
  randNumberRest = random(minRest, maxRest);
  Serial.print( "random pos down is ");
  Serial.println(randNumberRest);
  delay(randNumberRest);
}

