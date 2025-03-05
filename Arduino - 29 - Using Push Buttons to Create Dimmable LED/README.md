# Arduino LED and Buzzer Control Circuit

This project demonstrates how to control an LED's brightness and trigger a buzzer using two push buttons. The circuit consists of an Arduino UNO, an LED, a buzzer, and two push buttons.

## Circuit Components
- **Arduino UNO** (U1)
- **Push Buttons** (S1, S2)
- **Resistors** (R1, R2, R3 - 1kΩ each)
- **LED** (D1 - Red)
- **Buzzer** (L2)
- **Power Supply** (5V from Arduino)

## Circuit Diagram
The circuit is designed as follows:
- **S1 and S2** are connected to digital pins **12** and **11**, respectively, with pull-down resistors (1kΩ) to ground.
- **D1 (LED)** is connected to **pin 3** via a 1kΩ resistor.
- **L2 (Buzzer)** is connected to **pin 2**.
- The circuit is powered by the **5V and GND** of the Arduino.

## Code Explanation

The Arduino code manages the LED brightness based on button presses:

### **Variables**
```cpp
int inPin1 = 12;  // Button 1 (S1)
int inPin2 = 11;  // Button 2 (S2)
int Value1, Value2;  // Variables to store button states
int ledPin = 3;  // LED output pin
int ledValue = 0;  // LED brightness level
int buzzerPin = 2;  // Buzzer output pin
int myDelay = 100;  // Delay time in milliseconds
```

### **Setup Function**
```cpp
void setup() {
  Serial.begin(9600);
  pinMode(inPin1, INPUT);
  pinMode(inPin2, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}
```
- Initializes serial communication.
- Sets input pins for buttons.
- Sets output pins for the LED and buzzer.

### **Loop Function**
```cpp
void loop() {
  Value1 = digitalRead(inPin1);
  Value2 = digitalRead(inPin2);
```
- Reads the button states.

```cpp
  if (Value1 == 0 && Value2 == 1) {
    ledValue += 5;  // Increase brightness if only S2 is pressed
  }
  if (Value2 == 0 && Value1 == 1) {
    ledValue -= 10;  // Decrease brightness if only S1 is pressed
  }
```
- If **S2 is pressed**, the LED brightness increases.
- If **S1 is pressed**, the LED brightness decreases.

```cpp
  if (ledValue > 254) {
    ledValue = 255;
    digitalWrite(buzzerPin, HIGH);
    delay(myDelay);
    digitalWrite(buzzerPin, LOW);
  }
```
- If brightness exceeds **255**, it is capped at **255**, and the **buzzer** beeps.

```cpp
  if (ledValue < 0) {
    ledValue = 0;
    digitalWrite(buzzerPin, HIGH);
    delay(myDelay);
    digitalWrite(buzzerPin, LOW);
  }
```
- If brightness goes below **0**, it is set to **0**, and the **buzzer** beeps.

```cpp
  analogWrite(ledPin, ledValue);
  delay(myDelay);
```
- The LED brightness is updated using **PWM** on pin 3.

## How It Works
1. **Press S2** → LED **brightens**.
2. **Press S1** → LED **dims**.
3. If **maximum brightness** is reached, the **buzzer** beeps.
4. If **minimum brightness** is reached, the **buzzer** beeps.

## Conclusion
This project helps in understanding button-controlled **PWM brightness control** and **buzzer alerts** using Arduino.

