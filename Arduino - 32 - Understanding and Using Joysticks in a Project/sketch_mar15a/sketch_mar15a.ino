int switchPin = 2;
int xAxisPin = A0;
int yAxisPin = A1;
int myDelay = 500;

void setup() {
  pinMode(switchPin, INPUT);
  pinMode(xAxisPin, INPUT);
  pinMode(yAxisPin, INPUT);
  digitalWrite(switchPin, HIGH);
  Serial.begin(9600);
}

void loop() {
  int xAxisValue = analogRead(xAxisPin);
  int yAxisValue = analogRead(yAxisPin);
  int switchValue = digitalRead(switchPin);
  Serial.print("X Value: ");
  Serial.print(xAxisValue);
  Serial.print(" Y Value: ");
  Serial.print(yAxisValue);
  Serial.print(" Switch Value: ");
  Serial.print(switchValue);
  Serial.println();
  delay(myDelay);
}
