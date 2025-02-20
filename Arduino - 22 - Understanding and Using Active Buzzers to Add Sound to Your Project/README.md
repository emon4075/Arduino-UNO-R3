# Buzzer Circuit with Arduino UNO

## Overview
This project demonstrates how to use an Arduino UNO with a potentiometer and a buzzer. The circuit reads the analog input from a potentiometer (connected to pin A4) and activates a buzzer (connected to pin 2) when the input value exceeds a threshold.

## Circuit Components
- **Arduino UNO**: The main microcontroller board
- **Potentiometer (250K Ohm)**: Used to provide an adjustable voltage input to the Arduino
- **Buzzer (Active/Passive)**: Produces sound output when activated
- **Power Supply (5V)**: Provides power to the circuit
- **Connecting Wires**

## Circuit Description
1. The **potentiometer** is connected to **5V**, **GND**, and the **A4** analog input pin of the Arduino.
2. The **buzzer** is connected to **digital pin 2** of the Arduino and **GND**.
3. The Arduino reads the analog value from the potentiometer.
4. If the analog reading exceeds 1000, the buzzer is turned on.
5. Otherwise, the buzzer remains off.

## Code Explanation
The Arduino sketch does the following:
- Reads the potentiometer value.
- Prints the read value to the Serial Monitor.
- If the value exceeds 1000, the buzzer turns on.
- Otherwise, the buzzer remains off.

### Code Snippet
```cpp
int buzzerPin = 2;
float readValue;
int myDelay = 200;
int inPin = A4;

void setup() {
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
  pinMode(inPin, INPUT);
}

void loop() {
  readValue = analogRead(inPin);
  Serial.println(readValue);
  delay(myDelay);
  while (readValue > 1000) {
    digitalWrite(buzzerPin, HIGH);
    readValue = analogRead(inPin);
    Serial.println(readValue);
    delay(myDelay);
  }
  digitalWrite(buzzerPin, LOW);
}
```

## Active vs. Passive Buzzer
### **Active Buzzer**
- Has an internal oscillator.
- Produces a sound when a DC voltage is applied.
- Easier to use as it requires only a HIGH/LOW signal.

### **Passive Buzzer**
- Does not have an internal oscillator.
- Needs a PWM (Pulse Width Modulation) signal to produce sound.
- More flexible as it can generate different tones and frequencies.

## Usage
1. Upload the provided Arduino code to the Arduino UNO.
2. Open the Serial Monitor to observe the potentiometer values.
3. Rotate the potentiometer to change the voltage.
4. If the value exceeds 1000, the buzzer will turn on.
5. If the value drops below 1000, the buzzer turns off.

## Applications
- Alert and alarm systems
- Sound-based feedback mechanisms
- Volume control testing

---