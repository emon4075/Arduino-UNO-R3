int buzzerPin = 2;
float readValue;
int myDelay = 200;
int inPin = A4;

void setup() {
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
  pinMode(inPin, INPUT);
}

void loop() {
  readValue = analogRead(inPin);
  Serial.println(readValue);
  delay(myDelay);
  while (readValue > 1000) {
    digitalWrite(buzzerPin, HIGH);
    readValue = analogRead(inPin);
    Serial.println(readValue);
    delay(myDelay);
  }
  digitalWrite(buzzerPin, LOW);
}
