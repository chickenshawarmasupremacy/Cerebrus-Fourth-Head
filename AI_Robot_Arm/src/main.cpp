/* Code written by Izyan Khan
Simple potentiometer to control the 
*/

//



#include <Arduino.h>
#include <Servo.h>

Servo myServo;
Servo myServo2;

const int inputPin = A0;
const int outputPin1 = 3;
const int outputPin2 = 2;

void setup() {
  Serial.begin(115200);
  pinMode(inputPin, INPUT);
  pinMode(outputPin1, OUTPUT);
  pinMode(outputPin2, OUTPUT);
  myServo.attach(outputPin1);
  myServo2.attach(outputPin2);
}

void loop() {
  
  for (int i = 0; i < 180; i++){
    myServo.write(i);
    myServo2.write(180-i);
    delay(15);
    Serial.println("Servo 1: " + String(myServo.read()));
    Serial.println("Servo 2: " + String(myServo2.read()));
  }
  for (int i = 180; i > 0; i--){
    myServo.write(i);
    myServo2.write(180-i);
    delay(15);
    Serial.println("Servo 1: " + String(myServo.read()));
    Serial.println("Servo 2: " + String(myServo2.read()));
  }
}
