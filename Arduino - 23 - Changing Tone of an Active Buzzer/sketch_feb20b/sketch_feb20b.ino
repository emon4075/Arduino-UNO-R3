int buzzerPin = 2;
int myDelay_1 = 30;
int myDelay_2 = 40;
void setup() {
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  for (int i = 0; i < 100; i++) {
    digitalWrite(buzzerPin, HIGH);
    delay(myDelay_1);
    digitalWrite(buzzerPin, LOW);
    delay(myDelay_1);
  }
  for (int i = 0; i < 100; i++) {
    digitalWrite(buzzerPin, HIGH);
    delay(myDelay_2);
    digitalWrite(buzzerPin, LOW);
    delay(myDelay_2);
  }
}
