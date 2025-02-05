# Arduino Morse Code Blinker (SOS)  

This project demonstrates how to blink an LED to display the Morse code pattern for **SOS** (· · · — — — · · ·) using an **Arduino UNO R3**. The LED on **pin 8** will produce three short blinks, three long blinks, and then three short blinks again, with a pause before repeating.  

---

## Code  

```cpp
int redLight = 8;
int dit = 100;
int dah = 300;
int longWait = 1000;

void setup() {
  pinMode(redLight, OUTPUT);
}

void loop() {
  // Three short blinks (S)
  digitalWrite(redLight, HIGH);
  delay(dit);
  digitalWrite(redLight, LOW);
  delay(dit);
  digitalWrite(redLight, HIGH);
  delay(dit);
  digitalWrite(redLight, LOW);
  delay(dit);
  digitalWrite(redLight, HIGH);
  delay(dit);
  digitalWrite(redLight, LOW);
  delay(dit);

  // Three long blinks (O)
  digitalWrite(redLight, HIGH);
  delay(dah);
  digitalWrite(redLight, LOW);
  delay(dah);
  digitalWrite(redLight, HIGH);
  delay(dah);
  digitalWrite(redLight, LOW);
  delay(dah);
  digitalWrite(redLight, HIGH);
  delay(dah);
  digitalWrite(redLight, LOW);
  delay(dah);

  // Three short blinks (S)
  digitalWrite(redLight, HIGH);
  delay(dit);
  digitalWrite(redLight, LOW);
  delay(dit);
  digitalWrite(redLight, HIGH);
  delay(dit);
  digitalWrite(redLight, LOW);
  delay(dit);
  digitalWrite(redLight, HIGH);
  delay(dit);
  digitalWrite(redLight, LOW);
  delay(dit);

  // Pause before repeating
  delay(longWait);
}
```

---

## Code Explanation  

### Variables  

- **`redLight = 8`**: The pin number controlling the LED.  
- **`dit = 100`**: The duration (in milliseconds) of a short blink (·).  
- **`dah = 300`**: The duration (in milliseconds) of a long blink (—).  
- **`longWait = 1000`**: The pause (in milliseconds) at the end of one SOS sequence.  

### `setup()`  
The `setup()` function runs once when the Arduino is powered on or reset.  
- **`pinMode(redLight, OUTPUT);`**: Configures pin 8 as an output pin so it can control the LED.  

### `loop()`  
The `loop()` function runs continuously after `setup()`.  

1. **Three short blinks (S)**  
   - Each short blink (`dit`) turns the LED on for 100 ms and then off for 100 ms.  
   - This is repeated three times to form **S** in Morse code.  

2. **Three long blinks (O)**  
   - Each long blink (`dah`) turns the LED on for 300 ms and then off for 300 ms.  
   - This is repeated three times to form **O** in Morse code.  

3. **Three short blinks (S)**  
   - Same as step 1, another three short blinks to form **S** again.  

4. **Pause**  
   - A delay of 1000 ms (`longWait`) provides a break before the sequence repeats.  

This pattern (· · · — — — · · ·) is the Morse code representation of **SOS**.  

---

## Requirements  

- **Arduino UNO R3** (or a compatible board)  
- **1 x Orange LED** (color is optional; any LED will work)  
- **1 x 10kΩ resistor**  
- **USB cable to upload the code**  

> **Note**: Typically, an LED current-limiting resistor is between 220 Ω and 1 kΩ, but the schematic shows 10 kΩ. You can use a lower resistor value (e.g., 330 Ω) to get a brighter LED if desired.

---

## Wiring  

1. **Connect the longer leg (anode) of the LED to pin 8** on the Arduino.  
2. **Connect the shorter leg (cathode) of the LED to one side of a 10kΩ resistor**.  
3. **Connect the other side of the resistor to GND** on the Arduino.  

---

## Uploading the Code  

1. Open the **Arduino IDE**.  
2. Paste the provided code into a new sketch.  
3. Connect the Arduino to your computer using a USB cable.  
4. In the **Tools** menu, select the correct board (Arduino UNO) and port.  
5. Click the **Upload** button.  

---

## Output  

Once uploaded:  
- The LED will blink three short pulses (S).  
- Then three long pulses (O).  
- Then three short pulses (S) again.  
- The sequence will pause for 1 second.  
- This **SOS** pattern repeats indefinitely.  

You can adjust `dit`, `dah`, or `longWait` to change the timing or overall speed of the Morse code sequence.