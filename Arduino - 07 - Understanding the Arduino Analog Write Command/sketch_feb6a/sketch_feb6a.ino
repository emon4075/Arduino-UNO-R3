int redPin = 3;
int myDelay = 200;
int highBrightness = 180;
int lowBrightness = 20;
void setup() {
  pinMode(redPin, OUTPUT);
}

void loop() {
  analogWrite(redPin, highBrightness);
  delay(myDelay);
  analogWrite(redPin, lowBrightness);
  delay(myDelay);
}
