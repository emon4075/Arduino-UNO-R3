---

# Arduino LED Blinker  

This project demonstrates a simple LED blinking program using an **Arduino UNO R3**. The LED connected to **pin 8** will turn on for **500 milliseconds** and then turn off for **100 milliseconds**, creating a blinking pattern.  

---

## Code  

```cpp
void setup() {
  pinMode(8, OUTPUT);
}

void loop() {
  digitalWrite(8, HIGH);
  delay(500);
  digitalWrite(8, LOW);
  delay(100);
}
```

---

## Code Explanation  

### `setup()`  
The `setup()` function runs once when the Arduino is powered on or reset.  
- `pinMode(8, OUTPUT);`: Configures **pin 8** as an output pin so it can control the LED.  

### `loop()`  
The `loop()` function runs continuously after `setup()`.  
- `digitalWrite(8, HIGH);`: Turns the LED on by setting pin **8** to a high voltage.  
- `delay(500);`: Keeps the LED on for **500 milliseconds** (0.5 seconds).  
- `digitalWrite(8, LOW);`: Turns the LED off by setting pin **8** to a low voltage.  
- `delay(100);`: Keeps the LED off for **100 milliseconds** (0.1 seconds).  

This cycle repeats indefinitely, causing the LED to blink rapidly.  

---

## Requirements  

- **Arduino UNO R3** (or a compatible board)  
- **1 x Red LED**  
- **1 x 10kΩ resistor**  
- **USB cable to upload the code**  

---

## Wiring  

1. **Connect the longer leg (anode) of the LED to pin 8** of the Arduino.  
2. **Connect the shorter leg (cathode) of the LED to one side of a 10kΩ resistor**.  
3. **Connect the other side of the resistor to GND**.  

---

## Uploading the Code  

1. Open the **Arduino IDE**.  
2. Paste the provided code into a new sketch.  
3. Connect the Arduino to your computer.  
4. Select the correct port and board in the **Tools** menu.  
5. Click the **Upload** button.  

---

## Output  

Once uploaded:  
- The LED will turn **on** for **500 milliseconds**.  
- It will then turn **off** for **100 milliseconds**.  
- This blinking pattern will repeat indefinitely.  

---