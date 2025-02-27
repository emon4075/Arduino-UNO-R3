int inPin = A3;
int myDelay = 200;
int readValue;
int redPin = 2;
int greenPin = 4;

void setup() {
  pinMode(inPin, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  readValue = analogRead(inPin);
  Serial.println(readValue);
  if (readValue > 20) {
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, LOW);
  } else {
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, HIGH);
  }
  delay(myDelay);
}
