

### **Servo Motor Control with Arduino UNO**
This project demonstrates how to control a servo motor using an **Arduino UNO** and receive angle inputs from the **serial monitor**.  

---

## **Circuit Diagram**
![Circuit Diagram](image.png)

### **Connections:**
| Servo Motor | Arduino UNO |
|-------------|------------|
| PWR (Power) | 5V |
| GND (Ground) | GND |
| SIG (Signal) | D9 |

- The servo motor **PWR pin** is connected to the **5V** pin of the Arduino UNO.
- The **GND pin** of the servo is connected to the **GND** pin of the Arduino.
- The **signal pin (SIG)** is connected to **digital pin 9 (D9)** on the Arduino.

---

## **Code Explanation**
```cpp
#include <Servo.h>
```
- Includes the Servo library to control the servo motor.

```cpp
int servoPin = 9;
int servoPosition = 0;
Servo myServo;
```
- **servoPin** is set to **9**, which matches the circuit connection.
- **servoPosition** is initialized to **0**.
- An instance of the **Servo** class (`myServo`) is created.

```cpp
void setup() {
  Serial.begin(9600);
  myServo.attach(servoPin);
}
```
- **Serial.begin(9600)** starts serial communication to read input from the serial monitor.
- **myServo.attach(servoPin)** links the servo to pin 9.

```cpp
void loop() {
  Serial.println("Enter The Angle To Move: ");
  while (Serial.available() == 0) {
  }
```
- **Serial.println()** prompts the user to enter an angle.
- **while (Serial.available() == 0)** waits for user input.

```cpp
  if (Serial.available() > 0) {
    servoPosition = Serial.parseInt();
    while (Serial.available()) {
      Serial.read();
    }
  }
```
- **Serial.parseInt()** reads the entered number and stores it in `servoPosition`.
- **while (Serial.available()) { Serial.read(); }** clears the buffer.

```cpp
  myServo.write(servoPosition);
}
```
- Moves the servo to the specified angle.

---

## **How to Use**
1. **Upload** the code to the Arduino UNO.
2. **Open** the Serial Monitor (Baud Rate: **9600**).
3. **Enter** an angle (0-180) in the Serial Monitor and press Enter.
4. The servo motor will move to the entered angle.

---
