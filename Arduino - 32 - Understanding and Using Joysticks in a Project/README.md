# Joystick Module with Arduino

## Overview
The joystick module is an input device that allows users to control the movement in two dimensions (X and Y) and can also be pressed like a button (Z-axis or switch). It is commonly used in projects like robotic control, gaming, and graphical applications.

## Working Principle
The joystick module consists of two potentiometers that measure movement along the X and Y axes. These potentiometers output an analog signal that varies between 0 and 1023 (for a 10-bit ADC). The module also includes a switch that is triggered when the joystick is pressed.

- **X-Axis:** Controls horizontal movement.
- **Y-Axis:** Controls vertical movement.
- **Switch (Z-Axis):** Detects if the joystick is pressed.

The module is connected to the Arduino as follows:
- **VCC (Power Supply):** 5V (Red Wire)
- **GND (Ground):** GND (Black Wire)
- **VRX (X-Axis Output):** Analog pin A0
- **VRY (Y-Axis Output):** Analog pin A1
- **SW (Switch Output):** Digital pin 2

## Code Explanation
```cpp
int switchPin = 2;       // Digital pin for the switch
int xAxisPin = A0;       // Analog pin for the X-axis
int yAxisPin = A1;       // Analog pin for the Y-axis
int myDelay = 500;       // Delay time in milliseconds

void setup() {
  pinMode(switchPin, OUTPUT);    // Setting switch pin as output
  pinMode(xAxisPin, INPUT);      // Setting X-axis pin as input
  pinMode(yAxisPin, INPUT);      // Setting Y-axis pin as input
  digitalWrite(switchPin, HIGH); // Enabling internal pull-up resistor
  Serial.begin(9600);            // Initializing serial communication
}

void loop() {
  int xAxisValue = analogRead(xAxisPin);  // Read X-axis value
  int yAxisValue = analogRead(yAxisPin);  // Read Y-axis value
  int switchValue = digitalRead(switchPin); // Read switch state
  
  Serial.print("X Value: ");
  Serial.print(xAxisValue);
  Serial.print(" Y Value: ");
  Serial.print(yAxisValue);
  Serial.print(" Switch Value: ");
  Serial.print(switchValue);
  Serial.println();
  
  delay(myDelay);  // Wait before next reading
}
```
### Explanation:
- `int switchPin = 2;` → Assigns the digital pin 2 for the switch.
- `int xAxisPin = A0;` → Assigns the analog pin A0 for the X-axis.
- `int yAxisPin = A1;` → Assigns the analog pin A1 for the Y-axis.
- `pinMode(switchPin, OUTPUT);` → Configures the switch pin as an output (which is incorrect; it should be `INPUT`).
- `pinMode(xAxisPin, INPUT);` → Configures the X-axis pin as an input.
- `pinMode(yAxisPin, INPUT);` → Configures the Y-axis pin as an input.
- `digitalWrite(switchPin, HIGH);` → Enables the internal pull-up resistor for the switch.
- `Serial.begin(9600);` → Starts serial communication at 9600 baud rate.
- `analogRead(xAxisPin);` → Reads the joystick's X-axis value.
- `analogRead(yAxisPin);` → Reads the joystick's Y-axis value.
- `digitalRead(switchPin);` → Reads the state of the joystick's switch.
- `Serial.print()` → Prints the values to the Serial Monitor.
- `delay(myDelay);` → Adds a delay of 500 milliseconds before the next loop iteration.


## Applications
- Remote control of robots
- Game controllers
- 2D graphical movement
- Camera pan/tilt control

## Conclusion
The joystick module is an essential component for controlling motion in Arduino projects. By reading the analog values from the X and Y axes and detecting button presses, users can implement interactive controls efficiently.

# Remark
For Simulating The Ciruit Visit Wokwi and Paste The "diagram.json" Along With Code