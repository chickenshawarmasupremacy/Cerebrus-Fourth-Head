/* Code written by Izyan Khan
Simple potentiometer to control the 
*/



#include <Arduino.h>
#include <Servo.h>


// put function declarations here:
int myFunction(int, int);

Servo myServo;


const int inputPin = A0;
const int outputPin = A3;
/*
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(inputPin, INPUT);
  pinMode(outputPin, OUTPUT);
  myServo.attach(outputPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  int input_value = analogRead(inputPin);
  int final_val = (input_value/(91/4));
  Serial.print("The value is: ");
  Serial.println(final_val);
  myServo.write(final_val);
  delay(15);
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}
*/

int pos = 0;   
void  setup() {
  myServo.attach(outputPin);  // attaches the servo on pin 9 to the servo object
  Serial.begin(115200);
  myServo.attach(outputPin);
}

void loop() {

  for (int pos = 0; pos <= 180; pos += 1) {
    Serial.println(pos);
    myServo.write(pos);
    delay(15);
  }

  for (int pos = 180; pos >= 0; pos -= 1) {
    Serial.println(pos);
    myServo.write(pos);
    delay(15);
    
  }
}
