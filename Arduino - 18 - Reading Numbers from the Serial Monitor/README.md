# Arduino Sketch: Blinking an LED Based on User Input

## Description
This Arduino sketch allows the user to input a number via the Serial Monitor, determining how many times an LED blinks. The LED is connected to digital pin `2`, and each blink consists of turning the LED on and off with a `500ms` delay between states.

## Code Breakdown

### Global Variables:
- `int yellowPin = 2;` → Defines the pin controlling the yellow LED.
- `int myDelay = 500;` → Specifies a delay of 500 milliseconds between turning the LED on and off.
- `int blinkNumber;` → Stores the number of blinks input by the user.

### `setup()` Function:
- `Serial.begin(9600);` → Initializes serial communication at a baud rate of 9600.
- `pinMode(yellowPin, OUTPUT);` → Sets the LED pin as an output.

### `loop()` Function:
1. Prints a message to the Serial Monitor asking for user input.
2. Waits until input is available using `while (Serial.available() == 0) {}`.
3. Reads the user input using `Serial.parseInt()` and stores it in `blinkNumber`.
4. A `for` loop runs `blinkNumber` times, blinking the LED:
   - Turns the LED on (`digitalWrite(yellowPin, HIGH)`).
   - Waits `500ms`.
   - Turns the LED off (`digitalWrite(yellowPin, LOW)`).
   - Waits `500ms` before the next cycle.

## Expected Serial Monitor Interaction
```
How Many Blinks Do You Want:
(Enter a number, e.g., 5)
```
If the user inputs `5`, the LED will blink 5 times.

## Circuit Diagram Components
- **Arduino Uno** (U1)
- **Orange LED** (D1)
- **Resistor** (R1, 10kΩ)
- **Power Supply** (GND connection to Arduino)

## How to Use
1. Connect the components as per the circuit diagram.
2. Copy and paste the code into the Arduino IDE.
3. Upload the sketch to your Arduino board.
4. Open the Serial Monitor (set baud rate to 9600).
5. Enter a number corresponding to the desired number of blinks and press Enter.
6. Observe the LED blinking as per the entered value.

## Applications
- Understanding serial input and output in Arduino programming.
- Learning to control LEDs with user-defined inputs.
- Implementing interactive projects requiring user control over hardware behavior.

---