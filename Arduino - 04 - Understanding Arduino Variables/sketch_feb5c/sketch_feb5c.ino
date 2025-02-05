int redLight = 8;
int dit = 100;
int dah = 300;
int longWait = 1000;

void setup() {
  pinMode(redLight, OUTPUT);
}

void loop() {
  digitalWrite(redLight, HIGH);
  delay(dit);
  digitalWrite(redLight, LOW);
  delay(dit);
  digitalWrite(redLight, HIGH);
  delay(dit);
  digitalWrite(redLight, LOW);
  delay(dit);
  digitalWrite(redLight, HIGH);
  delay(dit);
  digitalWrite(redLight, LOW);
  delay(dit);

  digitalWrite(redLight, HIGH);
  delay(dah);
  digitalWrite(redLight, LOW);
  delay(dah);
  digitalWrite(redLight, HIGH);
  delay(dah);
  digitalWrite(redLight, LOW);
  delay(dah);
  digitalWrite(redLight, HIGH);
  delay(dah);
  digitalWrite(redLight, LOW);
  delay(dah);

  digitalWrite(redLight, HIGH);
  delay(dit);
  digitalWrite(redLight, LOW);
  delay(dit);
  digitalWrite(redLight, HIGH);
  delay(dit);
  digitalWrite(redLight, LOW);
  delay(dit);
  digitalWrite(redLight, HIGH);
  delay(dit);
  digitalWrite(redLight, LOW);
  delay(dit);

  delay(longWait);
}
