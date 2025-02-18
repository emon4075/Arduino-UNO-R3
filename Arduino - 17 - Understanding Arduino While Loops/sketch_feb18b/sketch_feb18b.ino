int yellowPin = 2;
int readValue;
int inPin = A4;
int myDelay = 500;

void setup() {
  Serial.begin(9600);
  pinMode(yellowPin, OUTPUT);
  pinMode(inPin, INPUT);
}

void loop() {
  readValue = analogRead(inPin);
  Serial.println(readValue);
  delay(myDelay);
  while (readValue >= 1000) {
    digitalWrite(yellowPin, HIGH);
    readValue = analogRead(inPin);
    Serial.println(readValue);
    delay(myDelay);
  }
  digitalWrite(yellowPin, LOW);
}
