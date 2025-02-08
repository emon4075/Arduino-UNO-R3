int readValue;
int myVoltPin = A4;
float V2;
int myDelay = 500;

void setup() {
  Serial.begin(9600);
}

void loop() {
  readValue = analogRead(myVoltPin);
  V2 = (5.0 / 1023.0) * readValue;
  Serial.println(V2);
  delay(myDelay);
}
