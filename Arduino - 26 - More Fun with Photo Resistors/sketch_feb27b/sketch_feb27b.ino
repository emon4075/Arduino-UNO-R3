int inPin = A3;
int buzzPin = 2;

void setup() {
  Serial.begin(9600);
  pinMode(inPin, INPUT);
  pinMode(buzzPin, OUTPUT);
}

void loop() {
  int readValue = analogRead(inPin);
  int delayTime = (9.0 / 298.0) * readValue - (9.0 * 2.0 / 298.0) + 1;
  Serial.println(readValue);
  digitalWrite(buzzPin, HIGH);
  delay(delayTime);
  digitalWrite(buzzPin, LOW);
  delay(delayTime);
}
