#include "xArmServoController.h"
#include <stdarg.h>
#include <Arduino.h>
#define txPin 1
#define rxPin 2
//delay time in milliseconds
unsigned int delayTime = 500;
//time passed in milliseconds to robotic arm position function to complete movement
unsigned int timer = 2000;
//declaration of class instance for xArm
xArmServoController myArm = xArmServoController(xArm, Serial);
//declaring digital pin 6 for the electromagnet
int magnetPin = 6;
//declaring pin 5 of the Arduino as the analog voltage pin which will be used for the load sensor input
int analogPin = A5;
int weight = 0;
//declaring pin 7 of the Arduino which will be used as a digital output (5V) to turn the alarm on/off
int digitalPin7 = 7;
//declaring the value of the critical weight limit that will set of the alarm if exceeded
const int criticalWeightLimit = 350;

void setup() 
{

//setting up digital pin for 5V output to energize the electromagnet 
pinMode(magnetPin, OUTPUT);
//setting up pin 7 of the Arduino as an output
pinMode (digitalPin7, OUTPUT);
//setting up serial communication
Serial.begin(9600);

}

void loop()
{

//LOADING MOTOR #1
//defining parameters for robotic arm default position
xArmServo defaultPosition[] ={  
  
                     {2,256},
                     {3,500},
                     {4,500},
                     {5,500},
                     {6,500},
                     };
//passing parameters for robotic arm default position
myArm.setPosition(defaultPosition, 5, timer, true);
delay(delayTime);



//defining parameters for picking up motor 1
xArmServo servoMotor1_A[] ={
                       
                        {2,356},
                        {3,185},
                        {4,114},
                        {5,782},
                        {6,385},
                        };
myArm.setPosition(servoMotor1_A, 5, timer, true);
delay(delayTime);
//set magnetPin to 5V to turn on the electromagnet
digitalWrite(magnetPin,HIGH);
delay(delayTime);

xArmServo servoMotor1_B[] ={
                       
                        {2,356},
                        {3,392},
                        {4,151},
                        {5,596},
                        {6,376},
                        };
myArm.setPosition(servoMotor1_B, 5, timer, true);

xArmServo servoMotor1_C[] ={
                       
                        {2,356},
                        {3,392},
                        {4,151},
                        {5,596},
                        {6,173},
                        };
myArm.setPosition(servoMotor1_C, 5, timer, true);

xArmServo servoMotor1_D[] ={
                       
                        {2,356},
                        {3,416},
                        {4,359},
                        {5,799},
                        {6,49},
                        };
myArm.setPosition(servoMotor1_D, 5, timer, true);

delay(delayTime);
//set magnetPin to 0V to turn off the electromagnet
digitalWrite(magnetPin,LOW);
delay(delayTime);
//calling currentWeight() function to get the measured weight
weight = currentWeight();
//if statement that compares the current weight to the maximum weight limit
if (weight > criticalWeightLimit )
{
  //soundAlarm() function runs if the critical weight limit has been reached
  soundAlarm();
  //return the robotic arm to its default state
  myArm.setPosition(defaultPosition, 5, timer, true);
  //exit the program
  exit(0);
}


//LOADING MOTOR #2
//passing parameters for robotic arm default position
myArm.setPosition(defaultPosition, 5, timer, true);
delay(delayTime);
//defining parameters for picking up motor 2
xArmServo servoMotor2_A[] ={
                       
                        {2,356},
                        {3,238},
                        {4,149},
                        {5,781},
                        {6,368},
                        };
myArm.setPosition(servoMotor2_A, 5, timer, true);

delay(delayTime);
//set magnetPin to 5V to turn on the electromagnet
digitalWrite(magnetPin,HIGH);
delay(delayTime);

xArmServo servoMotor2_B[] ={
                       
                        {2,356},
                        {3,467},
                        {4,242},
                        {5,653},
                        {6,373},
                        };
myArm.setPosition(servoMotor2_B, 5, timer, true);

xArmServo servoMotor2_C[] ={
                       
                        {2,356},
                        {3,467},
                        {4,243},
                        {5,653},
                        {6,185},
                        };
myArm.setPosition(servoMotor2_C, 5, timer, true);

xArmServo servoMotor2_D[] ={
                       
                        {2,356},
                        {3,440},
                        {4,377},
                        {5,805},
                        {6,34},
                        };
myArm.setPosition(servoMotor2_D, 5, timer, true);

delay(delayTime);
//set magnetPin to 0V to turn off the electromagnet
digitalWrite(magnetPin,LOW);
delay(delayTime);
weight = currentWeight();
//if statement that compares the current weight to the maximum weight limit
if (weight > criticalWeightLimit )
{
  //soundAlarm() function runs if the critical weight limit has been reached
  soundAlarm();
  //return the robotic arm to its default state
  myArm.setPosition(defaultPosition, 5, timer, true);
  //exit the program
  exit(0);
}

//LOADING MOTOR #3
//passing parameters for robotic arm default position
myArm.setPosition(defaultPosition, 5, timer, true);
delay(delayTime);
//defining parameters for picking up motor 3
xArmServo servoMotor3_A[] ={
                       
                        {2,356},
                        {3,270},
                        {4,206},
                        {5,804},
                        {6,346},
                        };
myArm.setPosition(servoMotor3_A, 5, timer, true);

delay(delayTime);
//set magnetPin to 5V to turn on the electromagnet
digitalWrite(magnetPin,HIGH);
delay(delayTime);

xArmServo servoMotor3_B[] ={
                       
                        {2,356},
                        {3,569},
                        {4,461},
                        {5,768},
                        {6,336},
                        };
myArm.setPosition(servoMotor3_B, 5, timer, true);

xArmServo servoMotor3_C[] ={
                       
                        {2,356},
                        {3,568},
                        {4,542},
                        {5,820},
                        {6,57},
                        };
myArm.setPosition(servoMotor3_C, 5, timer, true);

xArmServo servoMotor3_D[] ={
                       
                        {2,356},
                        {3,481},
                        {4,466},
                        {5,850},
                        {6,47},
                        };
myArm.setPosition(servoMotor3_D, 5, timer, true);

delay(delayTime);
//set magnetPin to 0V to turn off the electromagnet
digitalWrite(magnetPin,LOW);
delay(delayTime);
//calling currentWeight() function to get the measured weight
weight = currentWeight();
//if statement that compares the current weight to the maximum weight limit
if (weight > criticalWeightLimit )
{
  //soundAlarm() function runs if the critical weight limit has been reached
  soundAlarm();
  //return the robotic arm to its default state
  myArm.setPosition(defaultPosition, 5, timer, true);
  //exit the program
  exit(0);
}

//LOADING MOTOR #4
//passing parameters for robotic arm default position
myArm.setPosition(defaultPosition, 5, timer, true);
delay(delayTime);
//defining parameters for picking up motor 4
xArmServo servoMotor4_A[] ={
                       
                        {2,356},
                        {3,316},
                        {4,293},
                        {5,842},
                        {6,327},
                        };
myArm.setPosition(servoMotor4_A, 5, timer, true);

delay(delayTime);
//set magnetPin to 5V to turn on the electromagnet
digitalWrite(magnetPin,HIGH);
delay(delayTime);

xArmServo servoMotor4_B[] ={
                       
                        {2,356},
                        {3,534},
                        {4,388},
                        {5,693},
                        {6,331},
                        };
myArm.setPosition(servoMotor4_B, 5, timer, true);

xArmServo servoMotor4_C[] ={
                       
                        {2,356},
                        {3,522},
                        {4,478},
                        {5,790},
                        {6,54},
                        };
myArm.setPosition(servoMotor4_C, 5, timer, true);

xArmServo servoMotor4_D[] ={
                       
                        {2,356},
                        {3,473},
                        {4,498},
                        {5,868},
                        {6,38},
                        };
myArm.setPosition(servoMotor4_D, 5, timer, true);

delay(delayTime);
//set magnetPin to 0V to turn off the electromagnet
digitalWrite(magnetPin,LOW);
delay(delayTime);
//calling currentWeight() function to get the measured weight
weight = currentWeight();
//if statement that compares the current weight to the maximum weight limit
if (weight > criticalWeightLimit )
{
  //soundAlarm() function runs if the critical weight limit has been reached
  soundAlarm();
  //return the robotic arm to its default state
  myArm.setPosition(defaultPosition, 5, timer, true);
  //exit the program
  exit(0);
}

//LOADING MOTOR #5
//passing parameters for robotic arm default position
myArm.setPosition(defaultPosition, 5, timer, true);
delay(delayTime);
//defining parameters for picking up motor 5
xArmServo servoMotor5_A[] ={
                       
                        {2,356},
                        {3,392},
                        {4,376},
                        {5,866},
                        {6,305},
                        };
myArm.setPosition(servoMotor5_A, 5, timer, true);

delay(delayTime);
//set magnetPin to 5V to turn on the electromagnet
digitalWrite(magnetPin,HIGH);
delay(delayTime);

xArmServo servoMotor5_B[] ={
                       
                        {2,356},
                        {3,570},
                        {4,430},
                        {5,715},
                        {6,312},
                        };
myArm.setPosition(servoMotor5_B, 5, timer, true);

xArmServo servoMotor5_C[] ={
                       
                        {2,356},
                        {3,542},
                        {4,426},
                        {5,715},
                        {6,47},
                        };
myArm.setPosition(servoMotor5_C, 5, timer, true);

xArmServo servoMotor5_D[] ={
                       
                        {2,356},
                        {3,331},
                        {4,194},
                        {5,715},
                        {6,44},
                        };
myArm.setPosition(servoMotor5_D, 5, timer, true);

delay(delayTime);
//set magnetPin to 0V to turn off the electromagnet
digitalWrite(magnetPin,LOW);
delay(delayTime);
//calling currentWeight() function to get the measured weight
weight = currentWeight();
//if statement that compares the current weight to the maximum weight limit
if (weight > criticalWeightLimit )
{
  //soundAlarm() function runs if the critical weight limit has been reached
  soundAlarm();
  //return the robotic arm to its default state
  myArm.setPosition(defaultPosition, 5, timer, true);
  //exit the program
  exit(0);
}


}
//End of loop

//Declaration of functions
//Fucntion for finding the current weight loaded
int currentWeight ()
{

//declaring valueRead variable to hold analog voltage readings from the load sensor
int valueRead = 0;
//declaring averaging and counting variables
int average = 0;
int count = 5;

while(count > 0)
{
  
//read the incoming analog voltage values and store them in valueRead
valueRead = analogRead(analogPin);
//sum the values of valueRead into average
average += valueRead;
//decrement count variable
count -= 1;
//wait 10ms
delay(10);
}//end of while loop
//re initialize count variable
count = 5;
//calculate an average of the 5 readings from the analog voltage input of the load sensor
average = average/count;
//the input value from the load sensor was in a small range so the value of average is being scaled by a factor of 10
average = 10*average;
return average;

}

//soundAlarm() function that turns the buzzer on when critical weight limit is reached
void soundAlarm ()
{

//set digital pin 7 to high (5V) and turn on the alarm
digitalWrite(digitalPin7, HIGH);
//wait 2.5s
delay(2500);
//set digital pin 7 to low (0V) and turn off the alarm
digitalWrite(digitalPin7, LOW);

}
