int readPin = A4;
int readValue;
float V2 = 0;
int delayTime = 500;

void setup() {
  pinMode(readPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  readValue = analogRead(readPin);
  V2 = (5.0 / 1023.0) * readValue;
  Serial.println(V2);
  delay(delayTime);
}
