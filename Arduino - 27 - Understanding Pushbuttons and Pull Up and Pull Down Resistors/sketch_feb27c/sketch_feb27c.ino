int ledPin = 2;
int readPin = 12;
int myDelay = 100;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(readPin, INPUT);
  delay(myDelay);
}

void loop() {
  int readValue = digitalRead(readPin);
  Serial.println(readValue);
  delay(myDelay);
  if (readValue == 1) {
    digitalWrite(ledPin, LOW);
  } else {
    digitalWrite(ledPin, HIGH);
  }
}
