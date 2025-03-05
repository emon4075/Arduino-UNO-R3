int inPin1 = 12;
int inPin2 = 11;
int Value1, Value2;
int ledPin = 3;
int ledValue = 0;
int buzzerPin = 2;
int myDelay = 100;

void setup() {
  Serial.begin(9600);
  pinMode(inPin1, INPUT);
  pinMode(inPin2, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  Value1 = digitalRead(inPin1);
  Value2 = digitalRead(inPin2);

  if (Value1 == 0 && Value2 == 1) {
    ledValue += 5;
  }
  if (Value2 == 0 && Value1 == 1) {
    ledValue -= 10;
  }
  if (ledValue > 254) {
    ledValue = 255;
    digitalWrite(buzzerPin, HIGH);
    delay(myDelay);
    digitalWrite(buzzerPin, LOW);
  }
  if (ledValue < 0) {
    ledValue = 0;
    digitalWrite(buzzerPin, HIGH);
    delay(myDelay);
    digitalWrite(buzzerPin, LOW);
  }
  analogWrite(ledPin, ledValue);
  delay(myDelay);
}
