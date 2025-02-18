int greenPin = 2;
int yellowPin = 3;
int redPin = 4;
int myDelay = 500;

void setup() {
  Serial.begin(9600);
  pinMode(greenPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(redPin, OUTPUT);
}

void loop() {
  Serial.println("Enter the LED color (green, yellow, red): ");
  while (Serial.available() == 0) {

  }
  
  String LED = Serial.readString();
  LED.trim();
  LED.toLowerCase(); 

  Serial.println("Enter the number of times to blink: ");
  
  while (Serial.available() == 0) {

  }
  
  int blinkCount = Serial.parseInt();

  if (blinkCount <= 0) {
    Serial.println("Invalid blink count! Please enter a positive number.");
    return;
  }

  int pin = -1;

  if (LED == "green") {
    pin = greenPin;
  } else if (LED == "yellow") {
    pin = yellowPin;
  } else if (LED == "red") {
    pin = redPin;
  } else {
    Serial.println("Invalid color! Choose between green, yellow, or red.");
    return;
  }

  Serial.print("Blinking ");
  Serial.print(LED);
  Serial.print(" LED ");
  Serial.print(blinkCount);
  Serial.println(" times...");

  for (int i = 0; i < blinkCount; i++) {
    digitalWrite(pin, HIGH);
    delay(myDelay);
    digitalWrite(pin, LOW);
    delay(myDelay);
  }
  Serial.println("Blinking complete!");
}
