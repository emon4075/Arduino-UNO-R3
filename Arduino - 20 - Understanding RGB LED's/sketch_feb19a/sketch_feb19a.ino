int redPin = 9;
int greenPin = 10;
int bluePin = 11;

void setup() {
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  Serial.println("You Will Have To Enter The RGB Values.");

  Serial.println("Enter The Value For RED (0-255): ");
  while (Serial.available() == 0) {
  }
  int redVal = Serial.parseInt();
  Serial.read();

  Serial.println("Enter The Value For GREEN (0-255): ");
  while (Serial.available() == 0) {
  }
  int greenVal = Serial.parseInt();
  Serial.read();

  Serial.println("Enter The Value For BLUE (0-255): ");
  while (Serial.available() == 0) {
  }
  int blueVal = Serial.parseInt();
  Serial.read();

  analogWrite(redPin, redVal);
  analogWrite(greenPin, greenVal);
  analogWrite(bluePin, blueVal);

  Serial.print("Setting LED to: R=");
  Serial.print(redVal);
  Serial.print(", G=");
  Serial.print(greenVal);
  Serial.print(", B=");
  Serial.println(blueVal);
}
