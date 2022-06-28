#include <Servo.h>
Servo servoMain; // Define our Servo
int trigpin = 3;
int echopin = 2;
int distance;
float duration;
float cm;

void setup()
{
   servoMain.attach(4); // servo on digital pin 10
    pinMode(trigpin, OUTPUT);
    pinMode(echopin, INPUT);
}

void loop()
{ 
  digitalWrite(trigpin, LOW);
  delay(1);  
  digitalWrite(trigpin, HIGH);
  delay(1);  
  digitalWrite(trigpin, LOW);  
  duration = pulseIn(echopin, HIGH);  
  cm = (duration/58.82);
  distance = cm;
  
  if(distance<50)
  {
    servoMain.write(90);  // Turn Servo back to center position (90 degrees)
   delay(100); 
  }
   else{
     servoMain.write(0);
     delay(50);
   }
   
}
