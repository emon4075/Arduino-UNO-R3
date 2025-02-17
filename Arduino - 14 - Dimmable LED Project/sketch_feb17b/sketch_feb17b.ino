int greenPin = 11;
int myDelay = 500;

int myInPin = A4;
float readValue;

void setup() {
  pinMode(greenPin, OUTPUT);
  pinMode(myInPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  readValue = analogRead(A4);
  float ledValue = (253.0 / 1023.0) * readValue;
  analogWrite(greenPin, ledValue);
  Serial.println(ledValue);
}
