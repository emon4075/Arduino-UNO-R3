int N = 10;
int myDelay = 500;
void setup() {
  Serial.begin(9600);
}

void loop() {
  for (int i = 1; i <= N; i++) {
    if (i % 2 == 0) {
      Serial.println(i);
    }
    delay(myDelay);
  }
  Serial.println();
}
