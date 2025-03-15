# Joystick-Controlled LED Circuit with Arduino UNO

## Overview
This project demonstrates how to control LEDs using a joystick module and an Arduino UNO. The joystick's X and Y axis values determine which LED should light up, while the built-in switch triggers all LEDs.

## Components Required
- Arduino UNO
- Joystick module
- Breadboard
- 3 LEDs (Red, Yellow, Green)
- Resistors (220Ω - 330Ω)
- Jumper wires

## Circuit Explanation
1. **Joystick Module:**
   - The joystick has two analog outputs (X & Y) and a digital switch.
   - The X and Y axis values range from 0 to 1023 (centered at ~512).
   - A built-in switch is activated when pressed.

2. **Connections:**
   - **Joystick Pins:**
     - `VCC` → `5V` (Arduino)
     - `GND` → `GND` (Arduino)
     - `VRX` → `A0` (Arduino - X-axis)
     - `VRY` → `A1` (Arduino - Y-axis)
     - `SW` → `D2` (Arduino - Switch Button)
   - **LEDs:**
     - Red LED (X1) → `D9`
     - Yellow LED (X2) → `D5`
     - Green LED (Y1) → `D6`
     - Another Red LED (Y2) → `D3`

3. **Working:**
   - Moving the joystick left or right controls the red and yellow LEDs.
   - Moving it up or down controls the green and red LEDs.
   - Pressing the joystick switch turns all LEDs ON.

## Code Explanation
```cpp
int switchPin = 2;        // Joystick switch pin
int xAxisPin = A0;        // X-axis analog input
int yAxisPin = A1;        // Y-axis analog input
int myDelay = 200;        // Delay for stability

int X1_Pin = 9;           // Red LED (Left)
int X2_Pin = 5;           // Yellow LED (Right)
int Y1_Pin = 6;           // Green LED (Up)
int Y2_Pin = 3;           // Red LED (Down)

const int deadZone = 50;  // Ignore small movements
const int centerValue = 512;  // Midpoint of joystick values

void setup() {
  pinMode(switchPin, INPUT_PULLUP);
  pinMode(xAxisPin, INPUT);
  pinMode(yAxisPin, INPUT);
  pinMode(X1_Pin, OUTPUT);
  pinMode(X2_Pin, OUTPUT);
  pinMode(Y1_Pin, OUTPUT);
  pinMode(Y2_Pin, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  int xAxisValue = analogRead(xAxisPin);
  int yAxisValue = analogRead(yAxisPin);
  int switchValue = digitalRead(switchPin);

  // X-axis control
  if (xAxisValue < centerValue - deadZone) {
    analogWrite(X1_Pin, (xAxisValue / 4));
    analogWrite(X2_Pin, 0);
  } else if (xAxisValue > centerValue + deadZone) {
    analogWrite(X2_Pin, (xAxisValue / 4));
    analogWrite(X1_Pin, 0);
  } else {
    analogWrite(X1_Pin, 0);
    analogWrite(X2_Pin, 0);
  }

  // Y-axis control
  if (yAxisValue < centerValue - deadZone) {
    analogWrite(Y1_Pin, (yAxisValue / 4));
    analogWrite(Y2_Pin, 0);
  } else if (yAxisValue > centerValue + deadZone) {
    analogWrite(Y2_Pin, (yAxisValue / 4));
    analogWrite(Y1_Pin, 0);
  } else {
    analogWrite(Y1_Pin, 0);
    analogWrite(Y2_Pin, 0);
  }

  // Switch button pressed
  if (switchValue == LOW) {
    Serial.println("Button Pressed!");
    digitalWrite(X1_Pin, HIGH);
    digitalWrite(X2_Pin, HIGH);
    digitalWrite(Y1_Pin, HIGH);
    digitalWrite(Y2_Pin, HIGH);
  }

  // Print values for debugging
  Serial.print("X: ");
  Serial.print(xAxisValue);
  Serial.print(" Y: ");
  Serial.print(yAxisValue);
  Serial.print(" Switch: ");
  Serial.println(switchValue);

  delay(myDelay);
}
```

## Expected Behavior
- Moving the joystick left turns on the left LED (X1).
- Moving the joystick right turns on the right LED (X2).
- Moving the joystick up turns on the top LED (Y1).
- Moving the joystick down turns on the bottom LED (Y2).
- Pressing the joystick button lights up all LEDs.

## Conclusion
This project provides a basic understanding of how to interface a joystick with an Arduino and control LEDs based on directional input. The concept can be extended to control motors, robotic arms, and more interactive applications.

# Remark
For Simulating The Ciruit Visit Wokwi and Paste The "diagram.json" Along With Code