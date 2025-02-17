# Potentiometer-Controlled LED Brightness using Arduino UNO

## Overview
This project demonstrates how to control the brightness of an LED using a potentiometer and an Arduino UNO. The analog value from the potentiometer is read by the Arduino, which then adjusts the LED's brightness through PWM (Pulse Width Modulation).

## Components Used
- **Arduino UNO**
- **Potentiometer (250k ohm)**
- **Green LED**
- **Resistor (1k ohm)**
- **Jumper wires**
- **Breadboard**

## Circuit Explanation

### Connections:
- The **middle pin of the potentiometer** is connected to **A4** (analog pin) on the Arduino.
- One end of the potentiometer is connected to **5V**.
- The other end of the potentiometer is connected to **GND**.
- The **anode (long leg) of the LED** is connected to **pin 11** (PWM pin) through a **1k ohm resistor**.
- The **cathode (short leg) of the LED** is connected to **GND**.

### Working Principle:
- The potentiometer acts as a variable resistor, providing a voltage between 0V and 5V depending on its position.
- The Arduino reads this analog voltage from **A4** (range: 0 to 1023).
- The value is scaled down to match the PWM range (0 to 255).
- The Arduino then outputs the scaled value as a PWM signal to pin **11**, adjusting the LED's brightness.

## Code Explanation

```cpp
int greenPin = 11;  // Pin connected to LED
int myDelay = 500;  // Unused delay variable (can be removed)

int myInPin = A4;  // Pin connected to potentiometer
float readValue;   // To store the analog reading

void setup() {
  pinMode(greenPin, OUTPUT); // Set LED pin as output
  pinMode(myInPin, INPUT);    // Set potentiometer pin as input
  Serial.begin(9600);         // Initialize serial monitor
}

void loop() {
  readValue = analogRead(A4);  // Read potentiometer value (0-1023)
  float ledValue = (253.0 / 1023.0) * readValue;  // Scale to PWM range (0-255)
  analogWrite(greenPin, ledValue);  // Set LED brightness
  Serial.println(ledValue);  // Display value in serial monitor
}
```

### Explanation of the code:
- **setup():**
  - Configures **greenPin** as an output for the LED.
  - Configures **myInPin** as an input for the potentiometer.
  - Initializes serial communication at 9600 baud rate.

- **loop():**
  - Reads the analog value from **A4** (0-1023).
  - Scales the value to the PWM range (0-255).
  - Adjusts the LED brightness using **analogWrite()**.
  - Prints the scaled PWM value to the Serial Monitor.

## How to Run
1. Build the circuit according to the diagram.
2. Connect the Arduino UNO to your computer via USB.
3. Upload the code using the Arduino IDE.
4. Open the Serial Monitor (9600 baud rate) to view the PWM values.
5. Rotate the potentiometer and observe the LED brightness change.

## Improvements
- Add a delay to stabilize readings.
- Use **map()** function for a cleaner way to scale values.
- Display both raw analog readings and PWM values in the serial monitor.

## Author
This project was created as part of an exploration into Arduino and basic analog input handling.

---
