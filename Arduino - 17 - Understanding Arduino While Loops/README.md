# Arduino Sketch: Controlling an LED with a Potentiometer

## Description
This Arduino sketch reads the analog value from a potentiometer connected to pin `A4` and prints the value to the Serial Monitor. If the read value is greater than or equal to 1000, it turns on a yellow LED connected to digital pin `2`. The LED remains on until the value drops below 1000.

## Code Breakdown

### Global Variables:
- `int yellowPin = 2;` → Defines the pin controlling the yellow LED.
- `int readValue;` → Stores the analog value read from the potentiometer.
- `int inPin = A4;` → Defines the pin connected to the potentiometer output.
- `int myDelay = 500;` → Specifies a delay of 500 milliseconds between readings.

### `setup()` Function:
- `Serial.begin(9600);` → Initializes serial communication at a baud rate of 9600.
- `pinMode(yellowPin, OUTPUT);` → Sets the LED pin as an output.
- `pinMode(inPin, INPUT);` → Sets the potentiometer pin as an input.

### `loop()` Function:
- Reads the potentiometer value using `analogRead(inPin)`, stores it in `readValue`, and prints it to the Serial Monitor.
- If `readValue` is greater than or equal to 1000, the LED is turned on (`digitalWrite(yellowPin, HIGH)`).
- The loop keeps checking the potentiometer value and keeps the LED on while `readValue` remains >= 1000.
- If `readValue` drops below 1000, the LED is turned off (`digitalWrite(yellowPin, LOW)`).

## Expected Serial Monitor Output (Example)
```
512
600
750
1020
1023
1023
980
900
...
```

## Circuit Diagram Components
- **Arduino Uno** (U1)
- **Potentiometer** (R1, 250kΩ)
- **Yellow LED** (D1)
- **Resistor** (R2, 1kΩ)
- **Power Supply** (5V and GND)

## How to Use
1. Connect the components as per the circuit diagram.
2. Copy and paste the code into the Arduino IDE.
3. Upload the sketch to your Arduino board.
4. Open the Serial Monitor (set baud rate to 9600) to view the potentiometer values.
5. Turn the potentiometer knob and observe the LED behavior based on the threshold value of 1000.

## Applications
- Learning how to use analog inputs with an Arduino.
- Controlling LEDs based on sensor inputs.
- Understanding how to read and interpret sensor data in embedded systems.
---

