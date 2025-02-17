# LED Blinking Circuit with Arduino Uno

## Overview
This project demonstrates how to blink two LEDs (Green and Yellow) using an Arduino Uno. The LEDs are connected to digital pins 2 and 4 of the Arduino, and they blink in a specific sequence controlled by the uploaded code.

## Circuit Diagram
The circuit consists of:
- **Arduino Uno (U1)**: The microcontroller board that controls the LEDs.
- **LEDs (D1 & D2)**:
  - D1 (Yellow) is connected to digital pin 4.
  - D2 (Green) is connected to digital pin 2.
- **Resistors (R1 & R2 - 1kΩ each)**: Used to limit the current flowing through the LEDs to prevent damage.
- **GND (Ground)**: The negative terminal of the circuit.

### Wiring
| Component  | Connection |
|------------|------------|
| Green LED (D2) | Anode to pin 2 (via R2, 1kΩ), Cathode to GND |
| Yellow LED (D1) | Anode to pin 4 (via R1, 1kΩ), Cathode to GND |

## Code Explanation
The provided Arduino sketch controls the blinking pattern of the two LEDs.

### Variables
- `greenPin = 2`: Defines the digital pin for the Green LED.
- `yellowPin = 4`: Defines the digital pin for the Yellow LED.
- `blinkGreen = 10`: Number of times the Green LED blinks.
- `blinkYellow = 5`: Number of times the Yellow LED blinks.
- `myDelay = 200`: Delay (in milliseconds) between LED ON and OFF states.

### `setup()`
- Sets `greenPin` and `yellowPin` as output pins using a loop.

### `loop()`
- Blinks the Green LED `blinkGreen` times.
- Blinks the Yellow LED `blinkYellow` times.
- Each LED blinks with a delay of `200ms` between ON and OFF states.

## Expected Output
1. The Green LED blinks **10 times**, turning ON and OFF every **200 milliseconds**.
2. The Yellow LED blinks **5 times**, following the same delay pattern.
3. The sequence repeats indefinitely.

## Applications
- Basic LED control using Arduino.
- Understanding digital output pins.
- Practicing loop structures and timing in Arduino programming.

## How to Run
1. Connect the circuit as per the diagram.
2. Upload the provided Arduino code to the Arduino Uno.
3. Observe the blinking sequence of the LEDs.

---