int buzzerPin = 3;
int inPin = A4;
float readValue;
int myDelay_1 = 25;

void setup() {
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
  pinMode(inPin, INPUT);
}

void loop() {
  readValue = analogRead(inPin);
  int toneValue = ((0.08) * readValue) + 100;
  Serial.println(readValue);

  digitalWrite(buzzerPin, HIGH);
  delayMicroseconds(toneValue);
  digitalWrite(buzzerPin, LOW);
  delayMicroseconds(toneValue);

  delayMicroseconds(myDelay_1);
}
