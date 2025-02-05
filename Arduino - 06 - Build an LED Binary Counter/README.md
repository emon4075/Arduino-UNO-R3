# LED Binary Counter with Arduino UNO

## Overview
This project implements a **4-bit binary counter** using an **Arduino UNO** and four LEDs (Red, Green, Blue, and Orange). The LEDs are connected to digital pins **2, 3, 4, and 5** of the Arduino and sequentially display numbers from **0 to 15** in binary format.

## Components Used
- **Arduino UNO**
- **4 LEDs** (Red, Green, Blue, Orange)
- **4 Resistors** (10kΩ each)
- **Jumper Wires**
- **Breadboard**

## Circuit Explanation
- Each LED represents a **bit** in a 4-bit binary number.
- The LEDs are connected to **pins 2, 3, 4, and 5** of the Arduino.
- The **circuit is completed with 10kΩ resistors** to limit the current and prevent damage to the LEDs.
- The **common ground** of the circuit is connected to the **GND pin** of the Arduino.

### LED to Pin Mapping:
| LED Color  | Arduino Pin | Binary Bit |
|------------|------------|------------|
| **Blue**   | **2**      | LSB (2⁰)   |
| **Green**  | **3**      | 2nd Bit (2¹) |
| **Red**    | **4**      | 3rd Bit (2²) |
| **Orange** | **5**      | MSB (2³)   |

## Code Explanation
The provided Arduino sketch cycles through **all 16 (0-15) binary states**, updating the LED status accordingly:
1. The **setup()** function initializes **pins 2, 3, 4, and 5** as OUTPUT.
2. The **loop()** function iterates through binary numbers **0 to 15**, setting the LEDs **HIGH or LOW** based on the binary representation.
3. Each number is displayed for **250ms** before switching to the next.

### Example Binary Representation
| Decimal | Binary | LED States |
|---------|--------|------------|
| 0       | 0000   | All OFF    |
| 1       | 0001   | Only Orange ON |
| 2       | 0010   | Only Red ON |
| 3       | 0011   | Red & Orange ON |
| 4       | 0100   | Only Green ON |
| 8       | 1000   | Only Blue ON |
| 15      | 1111   | All ON |

## How to Run the Project
1. **Connect the Arduino UNO** to your computer using a USB cable.
2. **Upload the provided Arduino sketch** to the board using the Arduino IDE.
3. Observe the **LEDs counting in binary** from 0 to 15 in a continuous loop.

## Applications
- Understanding **binary counting** with LEDs.
- Learning **digital output control** with Arduino.
- Practical implementation of **bitwise operations** in embedded systems.

## Possible Enhancements
- Using **buttons** to manually increment the counter.
- Displaying the **binary value on an LCD screen**.
- Increasing the **bit size** to count beyond 15.

