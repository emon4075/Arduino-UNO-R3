const int greenPin = 2;
const int yellowPin = 4;
const int blinkGreen = 10;
const int blinkYellow = 5;
const int myDelay = 200;

void setup() {
  int pins[] = { greenPin, yellowPin };
  for (int i = 0; i < 2; i++) {
    pinMode(pins[i], OUTPUT);
  }
}

void loop() {
  /*
   * Blink Green LED
   */
  for (int i = 0; i < blinkGreen; i++) {
    digitalWrite(greenPin, HIGH);
    delay(myDelay);
    digitalWrite(greenPin, LOW);
    delay(myDelay);
  }

  /*
   * Blink Yellow LED
   */
  for (int i = 0; i < blinkYellow; i++) {
    digitalWrite(yellowPin, HIGH);
    delay(myDelay);
    digitalWrite(yellowPin, LOW);
    delay(myDelay);
  }
}
