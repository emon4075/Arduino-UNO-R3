int circleRadius = 5;
float pi = 3.14;
double circleArea;
int myDelay = 500;

void setup() {
  Serial.begin(9600);
}

void loop() {
  circleArea = pi * circleRadius * circleRadius;
  Serial.print("A Circle With Radius ");
  Serial.print(circleRadius);
  Serial.print(" Has an Area of: ");
  Serial.println(circleArea);
  circleRadius += 1;
  delay(myDelay);
}
