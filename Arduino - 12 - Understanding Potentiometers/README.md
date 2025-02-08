
# Potentiometer and Arduino UNO Connection

### How a Potentiometer Works
A potentiometer is a variable resistor that can be used to control voltage. It has three terminals:
- **One terminal** is connected to a fixed voltage source (5V in this case).
- **The second terminal** is connected to ground (0V).
- **The third terminal** (wiper) provides a variable voltage based on the knob's position, which is read by the Arduino.

As the knob of the potentiometer is rotated, the resistance changes, and the voltage at the wiper varies between 0V and 5V. This varying voltage is read by the Arduino as an analog input.

### Circuit Explanation
In the schematic:
- The **potentiometer** (RPOT1, 10kΩ) is connected to **5V** and **GND**.
- The **wiper** (middle pin) of the potentiometer is connected to **A4 (Analog Pin 4)** on the Arduino.

This allows the Arduino to measure the varying voltage output from the potentiometer.

## Code Explanation
The provided Arduino code reads the voltage from the potentiometer and prints it to the Serial Monitor.

### Code Breakdown
#### 1. Variable Declaration:
```cpp
int readValue;
int myVoltPin = A4;
float V2;
int myDelay = 500;
```
- `readValue` stores the raw analog value from the potentiometer.
- `myVoltPin` is set to `A4`, which is the pin where the potentiometer's wiper is connected.
- `V2` will store the calculated voltage.
- `myDelay` defines a delay of **500 milliseconds** between readings.

#### 2. Setup Function:
```cpp
void setup() {
  Serial.begin(9600);
}
```
- Initializes the Serial Monitor with a **baud rate of 9600**, allowing data to be displayed on the computer.

#### 3. Loop Function:
```cpp
void loop() {
  readValue = analogRead(myVoltPin);
  V2 = (5.0 / 1023.0) * readValue;
  Serial.println(V2);
  delay(myDelay);
}
```
- Reads the **analog value** from `A4` (range: 0-1023).
- Converts this value to a **voltage** (0V to 5V) using:
  ```cpp
  V2 = (5.0 / 1023.0) * readValue;
  ```
- Prints the voltage to the Serial Monitor.
- Waits for **500 milliseconds** before the next reading.

### Expected Output
When the potentiometer knob is turned:
- Rotating towards **GND** (0Ω) → **Voltage decreases** (close to 0V).
- Rotating towards **5V** (10kΩ) → **Voltage increases** (close to 5V).

The output on the Serial Monitor will show varying voltage values as the potentiometer is adjusted.

## Applications
- Used in **volume control** for audio devices.
- Can be used for **sensor calibration**.
- Helpful in **analog signal processing**.

This simple project demonstrates how a potentiometer can be used as an input device to control an Arduino program dynamically.