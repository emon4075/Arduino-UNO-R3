int yellowPin = 2;
int myDelay = 500;
int blinkNumber;

void setup() {
  Serial.begin(9600);
  pinMode(yellowPin, OUTPUT);
}

void loop() {
  Serial.println("How Many Blinks Do You Want: ");
  while (Serial.available() == 0) {
  }
  blinkNumber = Serial.parseInt();

  for (int i = 0; i < blinkNumber; i++) {
    digitalWrite(yellowPin, HIGH);
    delay(myDelay);
    digitalWrite(yellowPin, LOW);
    delay(myDelay);
  }
}
