# Arduino RGB LED Control Project

This project demonstrates how to control an RGB LED using an Arduino Uno. Users can input RGB values (0-255) via the Serial Monitor to dynamically adjust the LED's color.

## Table of Contents
- [Overview](#overview)
- [Circuit Diagram](#circuit-diagram)
- [Components](#components)
- [Setup Instructions](#setup-instructions)
- [Code Explanation](#code-explanation)
- [Usage](#usage)
- [Troubleshooting](#troubleshooting)
- [License](#license)

## Overview
The project uses PWM (Pulse Width Modulation) pins on the Arduino Uno to control the intensity of each color channel (Red, Green, Blue) of an RGB LED. The LED's color is adjusted based on user input provided through the Serial Monitor.

## Circuit Diagram
![Circuit Diagram](image.png)


## Components
- **Arduino Uno**: Main microcontroller board.
- **RGB LED**: Common cathode type.
- **Resistors**: 3 × 1kΩ resistors (for current limiting).
- **Jumper Wires**: For connecting components.

## Setup Instructions
1. **Hardware Setup**:
   - Connect the red, green, and blue pins of the RGB LED to Arduino pins 9, 10, and 11 through 1kΩ resistors respectively.
   - Connect the RGB LED's cathode (common ground) to the Arduino's `GND` pin.
   - Power the Arduino via USB or an external power source.

2. **Software Setup**:
   - Upload the provided code to the Arduino IDE.
   - Open the Serial Monitor (`Tools > Serial Monitor`).

## Code Explanation
### Key Variables
- `redPin`, `greenPin`, `bluePin`: PWM pins connected to the RGB LED.

### `setup()` Function
- Initializes serial communication at `9600` baud.
- Configures pins 9, 10, and 11 as outputs.

### `loop()` Function
1. Prompts the user to enter RGB values via the Serial Monitor.
2. Waits for input using `Serial.available()`.
3. Reads values using `Serial.parseInt()` and clears the buffer with `Serial.read()`.
4. Sets the LED color using `analogWrite()` to send PWM signals.
5. Prints the selected RGB values to the Serial Monitor.

## Usage
1. Open the Serial Monitor (`Ctrl+Shift+M` or `Tools > Serial Monitor`).
2. Ensure the baud rate is set to **9600**.
3. Follow the prompts to enter values for red, green, and blue (0-255).
   - Example input: `255` for red, `0` for green, `100` for blue.
4. The LED will update to the specified color immediately.

## Troubleshooting
- **LED Not Lighting**:
  - Check wiring connections and resistor placement.
  - Verify the LED is a **common cathode** type.
- **Incorrect Colors**:
  - Ensure the RGB pins are connected to the correct Arduino pins.
  - Test individual colors by setting one channel to `255` and others to `0`.
- **Serial Communication Issues**:
  - Confirm the correct COM port is selected in the Arduino IDE.
  - Restart the Arduino if the Serial Monitor freezes.
---