#include <Servo.h>

int servoPin = 9;
int servoPosition = 0;
Servo myServo;

void setup() {
  Serial.begin(9600);
  myServo.attach(servoPin);
}

void loop() {
  Serial.println("Enter The Angle To Move: ");
  while (Serial.available() == 0) {
  }
  if (Serial.available() > 0) {
    servoPosition = Serial.parseInt();
    while (Serial.available()) {
      Serial.read();
    }
  }
  myServo.write(servoPosition);
}
