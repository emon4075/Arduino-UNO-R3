
---

## Changing The Tone of Buzzer with Arduino UNO  (Active Buzzer)

### Overview  
This project involves connecting a buzzer to an **Arduino UNO** and generating a beeping sound using digital signals. The buzzer is connected to **digital pin 2**, and it is turned on and off at different time intervals to create a sound pattern.  

### Circuit Diagram  
The circuit consists of:  
- **Arduino UNO**  
- **Buzzer** (connected to **pin D2** and **GND**)  

The buzzer is controlled using the **digitalWrite()** function in the Arduino code.

### How It Works  
1. **The buzzer is turned ON and OFF rapidly** using digital signals to generate sound.
2. **Two different delays** (`myDelay_1 = 30ms` and `myDelay_2 = 40ms`) are used to create variation in the tone.
3. **The first loop** (100 cycles) generates a high-frequency sound by toggling the buzzer every `30ms`.
4. **The second loop** (100 cycles) generates a slightly lower frequency sound by toggling the buzzer every `40ms`.
5. The process **repeats indefinitely** in the `loop()` function.

---

## Code Explanation  

```cpp
int buzzerPin = 2;
int myDelay_1 = 30;
int myDelay_2 = 40;
```
- `buzzerPin = 2`: The buzzer is connected to **digital pin 2**.
- `myDelay_1 = 30`: First delay in milliseconds.
- `myDelay_2 = 40`: Second delay in milliseconds.

```cpp
void setup() {
  pinMode(buzzerPin, OUTPUT);
}
```
- **setup() function** sets the **buzzer pin** as an **OUTPUT**.

```cpp
void loop() {
  for (int i = 0; i < 100; i++) {
    digitalWrite(buzzerPin, HIGH);
    delay(myDelay_1);
    digitalWrite(buzzerPin, LOW);
    delay(myDelay_1);
  }
```
- **First loop (100 iterations)**:  
  - Turns the buzzer ON for `30ms` → OFF for `30ms` → Repeats **100 times**.
  - Produces a **high-pitched** beeping sound.

```cpp
  for (int i = 0; i < 100; i++) {
    digitalWrite(buzzerPin, HIGH);
    delay(myDelay_2);
    digitalWrite(buzzerPin, LOW);
    delay(myDelay_2);
  }
}
```
- **Second loop (100 iterations)**:  
  - Turns the buzzer ON for `40ms` → OFF for `40ms` → Repeats **100 times**.
  - Produces a **slightly lower-pitched** beeping sound.

### Expected Output  
- The buzzer will **beep at two different frequencies** in an alternating manner.
- The beeping pattern will **continue indefinitely**.

### Possible Modifications  
- Change `myDelay_1` and `myDelay_2` to modify the sound frequency.
- Increase or decrease the **loop count** to adjust the duration of each tone.
- Add a **third frequency** to create a more complex sound pattern.

---