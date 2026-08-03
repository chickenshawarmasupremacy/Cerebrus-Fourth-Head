/* Code written by Izyan Khan
Simple potentiometer to control the 
*/

//



#include <Arduino.h>
#include <Servo.h>

Servo myServo;
Servo myServo2;

const int inputPin = A0;
const int outputPin = A3;


int pos = 0;   
void  setup() {
  myServo.attach(outputPin);  // attaches the servo on pin 9 to the servo object
  Serial.begin(115200);
  myServo.attach(outputPin);
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
