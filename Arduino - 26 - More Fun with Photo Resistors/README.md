

# Buzzer Control with Analog Sensor

This project demonstrates how to control a buzzer's beep frequency using an analog sensor input with an Arduino. The circuit reads a sensor value, processes it to determine the delay time, and uses this delay to toggle the buzzer, creating a variable tone effect.

---

### Circuit Components
1. **Arduino Board** (e.g., Uno, Nano)
2. **Buzzer** (connected to digital pin `D2`)
3. **Analog Sensor** (e.g., potentiometer, LDR, thermistor) connected to analog pin `A3`
4. **Resistors**:
   - `R1`: Sensor (e.g., potentiometer or variable resistor)
   - `R2`: 1kΩ resistor (used in voltage divider configuration)
5. Wiring and breadboard.

### Circuit Connections
1. **Sensor Setup**:
   - Connect one terminal of the sensor (`R1`) to `3.3V`.
   - Connect the other terminal of the sensor to analog pin `A3` **and** one end of the 1kΩ resistor (`R2`).
   - Connect the remaining end of `R2` to `GND` (forms a voltage divider).
2. **Buzzer Setup**:
   - Connect the positive terminal of the buzzer to digital pin `D2`.
   - Connect the negative terminal to `GND`.

---

### Code Explanation
#### Pins:
- `inPin = A3`: Reads analog input from the sensor.
- `buzzPin = 2`: Controls the buzzer.

#### `setup()`:
- Initializes serial communication (`9600` baud).
- Configures `inPin` as input and `buzzPin` as output.

#### `loop()`:
1. **Read Sensor**:
   - `int readValue = analogRead(inPin)`: Reads the analog value (0–1023) from `A3`.
2. **Calculate Delay**:
   - `delayTime` is computed using the formula:  
     `(9.0 / 298.0) * readValue - (9.0 * 2.0 / 298.0) + 1`.  
     This scales `readValue` to a delay range of **1–10 ms** (adjustable based on sensor input).
3. **Control Buzzer**:
   - The buzzer is toggled `HIGH` and `LOW` with `delayTime`, creating a tone.  
   - The frequency of the tone is inversely proportional to `2 * delayTime`.

---

### How It Works
- The **sensor** (e.g., potentiometer) adjusts the voltage at `A3`, changing `readValue`.
- A higher `readValue` increases `delayTime`, lowering the buzzer frequency.
- A lower `readValue` decreases `delayTime`, raising the buzzer frequency.
- The serial monitor displays the raw sensor value for debugging.

---

### Usage
1. Upload the code to the Arduino.
2. Open the Serial Monitor to observe sensor values.
3. Adjust the sensor (e.g., rotate a potentiometer) to hear the buzzer's pitch change.

---

### Formula Derivation
The delay formula maps the analog input range (0–1023) to a practical delay range (1–10 ms). Adjust the coefficients in the code to modify the sensitivity or delay range.