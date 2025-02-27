# Arduino Sensor LED Control

This project demonstrates a simple circuit that uses an Arduino to read a sensor value and control two LEDs based on a threshold. The code turns on a red LED if the sensor value exceeds a certain level, otherwise a green LED remains on.

## Components
- Arduino UNO
- Sensor (e.g., potentiometer, light sensor) connected to analog pin **A3**
- Red LED connected to digital pin **2**
- Green LED connected to digital pin **4**
- 220Ω resistors for LEDs
- Breadboard and jumper wires

## Circuit Diagram
![Circuit Diagram](image.png)

### Key Connections:
- **Sensor**:  
  - Signal wire → **A3** (analog input)  
  - Power → **3.7V** (or appropriate voltage for your sensor)  
  - Ground → **GND**  
- **Red LED**:  
  - Anode (long leg) → **Pin 2** through a 220Ω resistor  
  - Cathode (short leg) → **GND**  
- **Green LED**:  
  - Anode (long leg) → **Pin 4** through a 220Ω resistor  
  - Cathode (short leg) → **GND**  

## Code Explanation
### `setup()`
- Configures **A3** as an input for the sensor.
- Sets pins **2** (red LED) and **4** (green LED) as outputs.
- Initializes serial communication at 9600 baud for debugging.

### `loop()`
1. Reads the analog value from **A3** using `analogRead()`.
2. Prints the sensor value to the Serial Monitor.
3. Checks if the sensor value exceeds **20**:
   - If **YES**: Turns on the red LED and turns off the green LED.
   - If **NO**: Turns on the green LED and turns off the red LED.
4. Adds a delay of **200ms** to stabilize readings.

## How It Works
- The sensor input (e.g., light, rotation, or force) is converted to a voltage between 0V and 5V.
- The Arduino maps this voltage to a value between **0** and **1023**.
- When the value exceeds **20**, the red LED lights up as a warning/indicator. Otherwise, the green LED stays on.

## Usage
1. Upload the code to the Arduino.
2. Open the Serial Monitor (`Tools > Serial Monitor`) to view real-time sensor values.
3. Adjust the sensor (e.g., rotate a potentiometer or cover a light sensor) to see the LEDs switch based on the threshold.

## Calibration
- Modify the threshold value (`20` in `if (readValue > 20)`) depending on your sensor’s expected range.
- Adjust `myDelay` to change the sampling rate.

## Troubleshooting
- LEDs not lighting up? Check resistor connections and ensure correct pin assignments.
- Garbage values in Serial Monitor? Verify the baud rate is set to **9600**.