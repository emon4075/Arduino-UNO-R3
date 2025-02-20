# Buzzer Tone Control using Arduino UNO and Potentiometer

## Overview
This project demonstrates how to control the tone of a buzzer using an **Arduino UNO** and a **potentiometer**. The potentiometer acts as an analog input, changing the frequency of the buzzer's sound based on its position.

## Components Used
1. **Arduino UNO**
2. **Buzzer** (Piezoelectric speaker)
3. **Potentiometer** (250kΩ)
4. **Connecting Wires**

## Circuit Diagram
The circuit consists of:
- A **potentiometer** connected to **analog pin A4**.
- A **buzzer** connected to **digital pin 3**.
- **Power supply** from Arduino's 5V and GND.

### Circuit Connections:
- The **middle pin** of the potentiometer is connected to **A4** (Analog input pin of Arduino).
- One outer pin of the potentiometer is connected to **5V**.
- The other outer pin is connected to **GND**.
- The **buzzer's positive terminal** is connected to **D3**.
- The **buzzer's negative terminal** is connected to **GND**.

## Code Explanation
```cpp
int buzzerPin = 3;
int inPin = A4;
float readValue;
int myDelay_1 = 25;

void setup() {
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
  pinMode(inPin, INPUT);
}

void loop() {
  readValue = analogRead(inPin);  // Read potentiometer value
  int toneValue = ((0.08) * readValue) + 100;  // Calculate frequency
  Serial.println(readValue);  // Print value to Serial Monitor

  digitalWrite(buzzerPin, HIGH);
  delayMicroseconds(toneValue);
  digitalWrite(buzzerPin, LOW);
  delayMicroseconds(toneValue);

  delayMicroseconds(myDelay_1);
}
```

### How the Code Works:
1. The **analogRead()** function reads the potentiometer value (0 to 1023).
2. This value is mapped to generate a suitable tone frequency.
3. The buzzer is turned ON and OFF rapidly to create a sound.
4. The **Serial Monitor** displays the potentiometer reading in real time.

## Expected Behavior
- Rotating the **potentiometer** changes the **buzzer's tone**.
- A **higher potentiometer value** results in a **higher frequency sound**.
- A **lower potentiometer value** results in a **lower frequency sound**.

## Applications
- Basic **tone generators**.
- Sound-based feedback systems.
- Music synthesizers.
- Interactive sound-based projects.

## Notes
- Ensure the buzzer is connected correctly to avoid damage.
- If no sound is heard, check the potentiometer wiring and values in the Serial Monitor.
- The delay values can be adjusted to fine-tune the frequency range.
---