# Arduino LED Toggle Using Push Button

## Overview
This project demonstrates how to use an Arduino Uno to control an LED using a push button. The LED toggles its state (ON/OFF) each time the button is pressed.

## Circuit Diagram
The circuit consists of:
- **Arduino Uno (U1)** as the microcontroller.
- **Push button (S1)** as an input device.
- **LED (D1)** as an output device.
- **Resistors (R1 and R2, both 1KΩ)** to limit current.

### Circuit Explanation
1. **Push Button Connection**:
   - One terminal of the button is connected to **pin 12** of the Arduino.
   - The other terminal is connected to **ground (GND)**.
   - A **pull-up resistor (R1, 1KΩ)** is connected between **pin 12** and **5V**, ensuring that the pin remains HIGH when the button is not pressed.

2. **LED Connection**:
   - The LED (D1) is connected to **pin 2** of the Arduino.
   - A **current-limiting resistor (R2, 1KΩ)** is connected in series with the LED to prevent excessive current flow.
   - The other terminal of the LED is connected to **ground (GND)**.

## Arduino Code Explanation
The provided Arduino sketch toggles the LED each time the button is pressed.

```cpp
int ledState = 0;        // Stores the state of the LED (0 = OFF, 1 = ON)
int ledPin = 2;          // LED connected to digital pin 2
int buttonPin = 12;      // Push button connected to digital pin 12
int buttonNew;           // Stores the current state of the button
int buttonOld = 1;       // Stores the previous state of the button
int myDelay = 100;       // Debounce delay in milliseconds

void setup() {
  Serial.begin(9600);    // Start serial communication for debugging
  pinMode(ledPin, OUTPUT);  // Set LED pin as output
  pinMode(buttonPin, INPUT); // Set button pin as input
}

void loop() {
  buttonNew = digitalRead(buttonPin);  // Read the button state
  
  // Check if button was released (falling edge detection)
  if (buttonOld == 0 && buttonNew == 1) {
    if (ledState == 0) {
      digitalWrite(ledPin, HIGH); // Turn LED ON
      ledState = 1;
    } else {
      digitalWrite(ledPin, LOW);  // Turn LED OFF
      ledState = 0;
    }
  }
  
  buttonOld = buttonNew; // Store the button state for the next loop iteration
  delay(myDelay);        // Small delay for debounce effect
}
```

### Code Explanation
1. **Variable Initialization**:
   - `ledState`: Stores the current state of the LED.
   - `ledPin`: Defines the pin where the LED is connected.
   - `buttonPin`: Defines the pin where the button is connected.
   - `buttonNew`: Stores the current button state.
   - `buttonOld`: Stores the previous button state to detect button presses.
   - `myDelay`: Defines a small delay to avoid bouncing issues.

2. **Setup Function**:
   - Initializes the serial monitor (`Serial.begin(9600)`).
   - Sets the LED pin as an output (`pinMode(ledPin, OUTPUT)`).
   - Sets the button pin as an input (`pinMode(buttonPin, INPUT)`).

3. **Loop Function**:
   - Reads the current state of the button (`buttonNew = digitalRead(buttonPin)`).
   - Checks if the button was released (`buttonOld == 0 && buttonNew == 1`).
   - If true, toggles the LED state.
   - Updates `buttonOld` with the new button state.
   - Includes a short delay (`delay(myDelay)`) to prevent debounce issues.

## How It Works
- When the push button is **pressed**, the pin reads **LOW (0)**.
- When the button is **released**, the pin reads **HIGH (1)**.
- The code detects the transition from LOW to HIGH (button release) and toggles the LED state.

## Applications
- Simple LED toggling mechanism.
- Learning input handling in Arduino.
- Building interactive projects using buttons.

## Improvements
- Implementing **hardware debouncing** using a capacitor.
- Using **interrupts** instead of polling to detect button presses.
- Expanding the project to control multiple LEDs.

This project is an excellent starting point for understanding digital input and output in Arduino.

