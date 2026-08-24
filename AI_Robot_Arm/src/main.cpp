/* Code written by Izyan Khan
Simple robot arm control
*/


#include <Arduino.h>
#include <Servo.h>


//Servo declarations are here(Important to note: Servo is a data type)
Servo clamper;
Servo myServo2;
Servo myServo3;
Servo myServo4;
Servo myServo5Link;
Servo myServo6Link;
Servo rotator;

void moveServo(Servo &motor, int angle, int minAngle = 0, int maxAngle = 180) {
  int currentAngle = motor.read();
  int newAngle = currentAngle + angle;

  // Ensure the new angle is within the specified range
  if (newAngle < minAngle) {
    newAngle = minAngle;
  } else if (newAngle > maxAngle) {
    newAngle = maxAngle;
  }

  motor.write(newAngle);
}


void  setup() {
  //Attaching all servo motors to their respective pins here
  Serial.begin(115200);

  // Attach all servos to their pins
  clamper.attach(32);
  clamper.write(0);
  myServo2.attach(33);
  myServo2.write(0);
  myServo3.attach(25);
  myServo3.write(0);
  myServo4.attach(26);
  myServo4.write(0);
  myServo5Link.attach(27);
  myServo5Link.write(0);
  myServo6Link.attach(14);
  myServo6Link.write(180);
  rotator.attach(12);

  // Initial positions
  clamper.write(0);
  myServo2.write(90);
  myServo3.write(90);
  myServo4.write(90);
  myServo5Link.write(90);
  myServo6Link.write(90);
  rotator.write(90);
}

void loop() {
  if (Serial.available() > 0) {
    char controller = Serial.read();

    switch (controller) {
      case ' ':
        if (clamper.read() == 0) {
        moveServo(clamper, 90, 0, 90); // Open the clamper
        } else {
          moveServo(clamper, -90, 0, 90); // Close the clamper
        }
        break;

      case 'w':
        moveServo(myServo2, 15);
        break;

      case 's':
        moveServo(myServo2, -15);
        break;

      case 'a':
        moveServo(myServo3, 15);
        break;

      case 'd':
        moveServo(myServo3, -15);
        break;

      case 'q':
        moveServo(myServo4, 15);
        break;

      case 'e':
        moveServo(myServo4, -15);
        break;
//Not using the moveServo command here to fix the issue of two seros being connected to drive the same joint.
      case 'z':
        if (myServo5Link.read() < 166) {
          int tempAngle = myServo5Link.read() + 15;
          myServo5Link.write(tempAngle);
          myServo6Link.write(180 - tempAngle);
        }
        else {
          myServo5Link.write(180);
          myServo6Link.write(0);
        }
        break;
      case 'v':
        if (myServo5Link.read() > 15) {
          int tempAngle = myServo5Link.read() - 15;
          myServo5Link.write(tempAngle);
          myServo6Link.write(180 - tempAngle);
        }
        else {
          myServo5Link.write(0);
          myServo6Link.write(180);
        }
        break;

      case 'r':
        moveServo(rotator, 15);
        break;

      case 'f':
        moveServo(rotator, -15);
        break;

      default:
      Serial.println("Invalid command received");
        break;

    }
  }
}
>>>>>>> 5c21d05 (Semi final commit, wifi capabilities need to be added)
