
# Arduino LED Blinker  

This project demonstrates a simple LED blinking program using an **Arduino UNO R3**. The LED connected to pin 13 will turn on for 1 second and then turn off for 3 seconds, creating a blinking pattern.  

---

## Code  

```cpp
void setup() {
  pinMode(13, OUTPUT);
}

void loop() {
  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  delay(3000);
}
```

---

## Code Explanation  

### `setup()`  
The `setup()` function runs once when the Arduino is powered on or reset.  
- `pinMode(13, OUTPUT);`: Configures pin 13 as an output pin so it can control the LED.  

### `loop()`  
The `loop()` function runs continuously after `setup()`.  
- `digitalWrite(13, HIGH);`: Turns the LED on by setting pin 13 to a high voltage.  
- `delay(1000);`: Keeps the LED on for 1000 milliseconds (1 second).  
- `digitalWrite(13, LOW);`: Turns the LED off by setting pin 13 to a low voltage.  
- `delay(3000);`: Keeps the LED off for 3000 milliseconds (3 seconds).  

This cycle repeats indefinitely, causing the LED to blink.  

---

## Requirements  

- **Arduino UNO R3** (or a compatible board)  
- LED (if not using the built-in one on pin 13)  
- USB cable to upload the code  

---

## Wiring  

If your board does not have a built-in LED:  
1. Connect the longer leg of the LED to pin 13.  
2. Connect the shorter leg to the GND pin through a 220-ohm resistor.  

---

## Uploading the Code  

1. Open the Arduino IDE.  
2. Paste the provided code into a new sketch.  
3. Connect the Arduino to your computer.  
4. Select the correct port and board in the **Tools** menu.  
5. Click the **Upload** button.  

---

## Output  

Once uploaded:  
- The LED will turn on for 1 second.  
- It will then turn off for 3 seconds.  
- This blinking pattern will repeat indefinitely.