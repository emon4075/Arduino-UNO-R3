# Arduino LED Blinking Project

## Overview
This project allows users to control three LEDs (Red, Green, and Yellow) using an Arduino UNO. The user can specify the LED color and the number of times it should blink via the Serial Monitor.

## Circuit Diagram
![Circuit Diagram](https://github.com/emon4075/Arduino-UNO-R3/blob/master/Arduino%20-%2019%20-%20Reading%20Strings%20from%20the%20Serial%20Monitor/Arduino%20-%2019%20-%20Reading%20Strings%20from%20the%20Serial%20Monitor.png)

## Components Used
- **Arduino UNO** (U1)
- **LEDs**:
  - **Red LED** (D1) - Connected to pin 4
  - **Green LED** (D2) - Connected to pin 2
  - **Yellow LED** (D3) - Connected to pin 3
- **Resistors** (1kΩ each) (R1, R2, R3)
- **Wires** and **Breadboard**

## Circuit Connections
Each LED is connected in series with a **1kΩ resistor** to limit the current and prevent damage.
- **Green LED** → Digital Pin **2**
- **Yellow LED** → Digital Pin **3**
- **Red LED** → Digital Pin **4**
- The **negative terminals** of all LEDs are connected to **GND** of Arduino.

## Code Explanation
The Arduino program works as follows:
### 1. Initialization
- The LED pins are set as `OUTPUT`.
- Serial communication is started at **9600 baud rate**.

### 2. User Input via Serial Monitor
- The program prompts the user to enter a **color** (`green`, `yellow`, or `red`).
- Then, it asks for the **number of times** the LED should blink.

### 3. LED Blinking Process
- The entered LED color is matched with the respective pin.
- The selected LED blinks for the given number of times using a `for` loop.

### 4. Error Handling
- If an invalid color is entered, an error message is displayed.
- If an invalid blink count (zero or negative) is entered, an error message is shown.

## How to Use
1. Upload the code to your **Arduino UNO** using the **Arduino IDE**.
2. Open the **Serial Monitor** (`Ctrl + Shift + M`).
3. Enter the LED color (`green`, `yellow`, or `red`) and press **Enter**.
4. Enter the number of blinks and press **Enter**.
5. The selected LED will blink the specified number of times.

## Expected Output
If the user enters:
```
green
5
```
The **Green LED** will blink **5 times**.
