int switchPin = 2;
int xAxisPin = A0;
int yAxisPin = A1;
int myDelay = 200;

int X1_Pin = 9;
int X2_Pin = 5;
int Y1_Pin = 6;
int Y2_Pin = 3;

const int deadZone = 50;
const int centerValue = 512;

void setup() {
  pinMode(switchPin, INPUT_PULLUP);
  pinMode(xAxisPin, INPUT);
  pinMode(yAxisPin, INPUT);
  pinMode(X1_Pin, OUTPUT);
  pinMode(X2_Pin, OUTPUT);
  pinMode(Y1_Pin, OUTPUT);
  pinMode(Y2_Pin, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  int xAxisValue = analogRead(xAxisPin);
  int yAxisValue = analogRead(yAxisPin);
  int switchValue = digitalRead(switchPin);

  if (xAxisValue < centerValue - deadZone) {
    analogWrite(X1_Pin, (xAxisValue / 4));
    analogWrite(X2_Pin, 0);
  } else if (xAxisValue > centerValue + deadZone) {
    analogWrite(X2_Pin, (xAxisValue / 4));
    analogWrite(X1_Pin, 0);
  } else {
    analogWrite(X1_Pin, 0);
    analogWrite(X2_Pin, 0);
  }

  if (yAxisValue < centerValue - deadZone) {
    analogWrite(Y1_Pin, (yAxisValue / 4));
    analogWrite(Y2_Pin, 0);
  } else if (yAxisValue > centerValue + deadZone) {
    analogWrite(Y2_Pin, (yAxisValue / 4));
    analogWrite(Y1_Pin, 0);
  } else {
    analogWrite(Y1_Pin, 0);
    analogWrite(Y2_Pin, 0);
  }

  if (switchValue == LOW) {
    Serial.println("Button Pressed!");
    digitalWrite(X1_Pin, HIGH);
    digitalWrite(X2_Pin, HIGH);
    digitalWrite(Y1_Pin, HIGH);
    digitalWrite(Y2_Pin, HIGH);
  }

  Serial.print("X: ");
  Serial.print(xAxisValue);
  Serial.print(" Y: ");
  Serial.print(yAxisValue);
  Serial.print(" Switch: ");
  Serial.println(switchValue);

  delay(myDelay);
}
