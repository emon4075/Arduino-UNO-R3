# Arduino Button-controlled LED with Pull-up Resistor

## Pull-up vs. Pull-down Resistors

### Pull-up Resistor
- Connects a pin to **VCC (5V/3.3V)** to ensure a **HIGH** default state when no input is detected.
- When a button is pressed, the pin is connected to **GND**, pulling it **LOW**.
- Prevents "floating" (undefined) states on input pins.

### Pull-down Resistor
- Connects a pin to **GND** to ensure a **LOW** default state.
- Pressing a button connects the pin to **VCC**, pulling it **HIGH**.

## Circuit Description
This circuit uses an **external pull-up resistor** to read a button input and control an LED.

### Components:
- **Arduino Uno**
- **R1 (1kΩ)**: Pull-up resistor between `5V` and input pin `D12`.
- **R2 (1kΩ)**: Current-limiting resistor for the LED (connected to `D2`).
- **Button**: Connected between `D12` and `GND`. When pressed, it overrides the pull-up resistor and pulls `D12` to `LOW`.
- **LED**: Anode connected to `D2` (through R2), cathode to `GND`.

### Key Connections:
- `D12`: Input pin with pull-up resistor (R1) to `5V`.
- `D2`: Output pin driving the LED (via R2).
- Button bridges `D12` and `GND` when pressed.

## Code Explanation
The code reads the state of `D12` and controls the LED on `D2` inversely.

### Setup:
- `Serial.begin(9600)`: Initializes serial communication.
- `pinMode(ledPin, OUTPUT)`: Sets `D2` as output.
- `pinMode(readPin, INPUT)`: Sets `D12` as input (**no internal pull-up**; relies on external resistor R1).

### Loop:
1. **Read Input**: `digitalRead(readPin)` checks `D12`.
   - Default: `HIGH` (due to pull-up resistor R1).
   - Pressed: `LOW` (button connects `D12` to `GND`).
2. **Serial Output**: Prints the input value for debugging.
3. **LED Control**:
   - If `readValue == 1` (button not pressed), LED turns **OFF** (`LOW`).
   - If `readValue == 0` (button pressed), LED turns **ON** (`HIGH`).
4. **Delay**: `myDelay = 100ms` reduces noise and stabilizes readings.

## Behavior
- **LED OFF** by default (input `HIGH` due to pull-up resistor).
- **LED ON** when the button is pressed (input `LOW`).
- Serial Monitor displays `1` (unpressed) or `0` (pressed).

## Schematic Overview
```
         +5V
          |
          R1 (1kΩ)
          |
D12 >----+----> Button ---> GND

D2 >----R2 (1kΩ)----> LED ---> GND
``` 
