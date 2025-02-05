# PWM LED Blinking Circuit with Arduino UNO

## Overview
This project demonstrates **Pulse Width Modulation (PWM)** using an **Arduino Uno** to control the brightness of an LED. The LED alternates between two brightness levels at a regular interval using `analogWrite()`.

## Components
| Name  | Quantity | Component |
|-------|----------|------------|
| U1    | 1       | Arduino Uno R3 |
| R1    | 1       | 10 kΩ Resistor |
| D1    | 1       | Red LED |

## Circuit Explanation
The LED is connected to **pin 3** of the Arduino, which is a **PWM-supported pin**. A **10 kΩ resistor** is placed in series with the LED to limit the current and protect both the LED and the microcontroller.

### **Pin Connections:**
- The **anode** (+) of the LED is connected to **pin 3** of the Arduino.
- The **cathode** (-) of the LED is connected to **ground (GND)** through a **10 kΩ resistor**.
- Arduino's **GND** is connected to the **common ground**.

## **Understanding PWM (Pulse Width Modulation)**
Pulse Width Modulation (PWM) allows us to simulate an **analog voltage** using a digital pin by rapidly switching it **on and off**. The ratio of the "ON" time to the total cycle time is called the **duty cycle**.

- **High Duty Cycle (More ON Time)** → Higher brightness.
- **Low Duty Cycle (More OFF Time)** → Lower brightness.

### **Code Explanation**
The Arduino code below uses `analogWrite()` to control the LED brightness:

```cpp
int redPin = 3; // PWM-capable pin
int myDelay = 200;
int highBrightness = 180; // 70% brightness (PWM value: 0-255)
int lowBrightness = 20;  // 8% brightness

void setup() {
  pinMode(redPin, OUTPUT);
}

void loop() {
  analogWrite(redPin, highBrightness); // Set LED to high brightness
  delay(myDelay);
  analogWrite(redPin, lowBrightness);  // Set LED to low brightness
  delay(myDelay);
}
```

### **Code Functionality:**
1. The LED starts at **high brightness** (PWM value **180** out of **255** → ~70% duty cycle).
2. It stays in this state for **200 ms**.
3. The LED then switches to **low brightness** (PWM value **20** → ~8% duty cycle).
4. This cycle repeats indefinitely, making the LED appear to "pulse."

## **Why Use PWM Instead of `digitalWrite()`?**
Unlike `digitalWrite(HIGH/LOW)`, which turns the LED fully **ON** or **OFF**, `analogWrite()` allows for **variable brightness** by rapidly toggling between ON and OFF states. This is useful in applications such as:
- LED dimming
- Motor speed control
- Signal generation

## **Expected Behavior**
When running this code, the LED should pulse with alternating brightness levels, creating a **breathing effect** instead of simple blinking.

---
This simple circuit demonstrates how PWM can be used effectively for LED dimming with Arduino.
