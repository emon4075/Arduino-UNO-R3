# Light-Based Servo Motor Control with Arduino

## Overview
This project demonstrates how to control a servo motor based on light intensity using an **Arduino UNO**. A **photoresistor (LDR)** is used to detect light levels, and the servo motor moves accordingly.

## Circuit Components
- **Arduino UNO** (U1)
- **Servo Motor** (SERVO1)
- **Photoresistor (LDR)**
- **Resistors**: 1kΩ (R2), and a pull-down resistor (R1)
- **LED** (optional, connected in series with R1)
- **Power Supply**: 5V

## Circuit Explanation
1. **Light Detection**: The LDR is connected in a voltage divider configuration with R2, providing an analog voltage to **A3**.
2. **Servo Motor Control**: The servo motor is connected to **D3**, receiving PWM signals.
3. **Voltage Reference**: The Arduino reads the LDR’s voltage and determines the light intensity.
4. **LED Indication (Optional)**: If the LDR detects light intensity changes, an LED (R1) can glow accordingly.

## Code Explanation
```cpp
#include <Servo.h>

Servo myServo;
int servoPin = 3;
int inPin = A3;
int servoPosition = 0;

void setup() {
  Serial.begin(9600);
  pinMode(inPin, INPUT);
  myServo.attach(servoPin);
}

void loop() {
  int brightValue = analogRead(inPin);
  Serial.println(brightValue);
  delay(100);
  if (brightValue > 160) {
    servoPosition = 180;
  }
  if (brightValue > 100) {
    servoPosition = 120;
  }
  myServo.write(brightValue);
}
```

### Functionality
1. **Reading Light Intensity**: The `analogRead(inPin)` reads the LDR’s voltage.
2. **Printing Values**: The light intensity is printed to the serial monitor.
3. **Adjusting Servo Position**:
   - If light intensity (`brightValue`) is **greater than 160**, the servo moves to **180°**.
   - If intensity is **greater than 100**, it moves to **120°**.
   - The servo’s position is controlled using `myServo.write(brightValue);`.

## Possible Improvements
- The servo should be set within valid PWM ranges (0-180 degrees).
- Introduce `map()` function to scale the brightness to servo movement.
- Add hysteresis to avoid jittering when values fluctuate.

## Applications
- **Automatic Curtain Control**
- **Light-Tracking Solar Panels**
- **Security Systems Based on Light Detection**