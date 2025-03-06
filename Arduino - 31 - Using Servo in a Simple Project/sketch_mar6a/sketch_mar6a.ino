#include <Servo.h>

Servo myServo;
int servoPin = 3;
int inPin = A3;
int servoPosition = 0;

void setup() {
  Serial.begin(9600);
  pinMode(inPin, INPUT);
  myServo.attach(servoPin);
}

void loop() {
  int brightValue = analogRead(inPin);
  Serial.println(brightValue);
  delay(100);
  if (brightValue > 160) {
    servoPosition = 180;
  }
  if (brightValue > 100) {
    servoPosition = 120;
  }

  myServo.write(brightValue);
}
