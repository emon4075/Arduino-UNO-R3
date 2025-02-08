int readValue;
int myDelay = 500;
int myPin = A4;
int redPin = 3;

void setup() {
  Serial.begin(9600);
  pinMode(myPin, INPUT);
  pinMode(redPin, OUTPUT);
}

void loop() {
  readValue = analogRead(myPin);
  float V2 = (5.0 / 1023.0) * readValue;
  if (V2 >= 3.0) {
    Serial.println("Voltage is Too Much.");
    analogWrite(redPin, 20);
    if (V2 >= 4.0) {
      digitalWrite(redPin, HIGH);
    }
  } else {
    Serial.println(V2);
    digitalWrite(redPin, LOW);
  }
  delay(myDelay);
}
