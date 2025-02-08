# Arduino Potentiometer and LED Circuit

## Circuit Explanation
This circuit consists of an **Arduino Uno**, a **10kΩ potentiometer**, a **red LED**, and a **1kΩ resistor**. It is designed to measure the voltage from the potentiometer using the **A4 analog pin** and control the brightness of the LED connected to **pin 3** based on the voltage level.

### Components Used:
1. **Arduino Uno (U1)**: Microcontroller board that reads the potentiometer value and controls the LED.
2. **Potentiometer (RPOT1, 10kΩ)**: Provides an adjustable voltage that is read by the Arduino's analog pin (A4).
3. **LED (D1, Red)**: Lights up depending on the voltage reading.
4. **Resistor (R1, 1kΩ)**: Limits the current to protect the LED.

### Working Principle:
- The potentiometer acts as a variable resistor, providing an analog voltage between 0V and 5V at its wiper.
- The Arduino reads this voltage from **A4** using `analogRead()`, which gives values from **0 to 1023**.
- The voltage is calculated using:
  
  ```cpp
  float V2 = (5.0 / 1023.0) * readValue;
  ```
  
- If the voltage is **greater than or equal to 3V**, the LED glows dimly using `analogWrite(redPin, 20);`.
- If the voltage is **greater than or equal to 4V**, the LED turns on fully with `digitalWrite(redPin, HIGH);`.
- Otherwise, the LED remains off.
- The **Serial Monitor** displays the voltage readings.

---

## Arduino Code Explanation

```cpp
int readValue;        // Variable to store the analog reading
int myDelay = 500;    // Delay between readings
int myPin = A4;       // Analog input pin connected to potentiometer
int redPin = 3;       // Digital output pin connected to LED

void setup() {
  Serial.begin(9600);    // Initialize serial communication at 9600 baud rate
  pinMode(myPin, INPUT); // Set potentiometer pin as input
  pinMode(redPin, OUTPUT); // Set LED pin as output
}

void loop() {
  readValue = analogRead(myPin); // Read the potentiometer value
  float V2 = (5.0 / 1023.0) * readValue; // Convert to voltage
  
  if (V2 >= 3.0) {
    Serial.println("Voltage is Too Much.");
    analogWrite(redPin, 20); // Dim LED
    
    if (V2 >= 4.0) {
      digitalWrite(redPin, HIGH); // Fully turn on LED
    }
  } else {
    Serial.println(V2); // Print voltage value
    digitalWrite(redPin, LOW); // Turn off LED
  }
  delay(myDelay); // Wait before next reading
}
```

### Key Points:
- `analogRead(myPin)`: Reads the potentiometer value (0-1023).
- `Serial.println(V2)`: Displays the voltage on the serial monitor.
- `analogWrite(redPin, 20)`: Lights the LED dimly if voltage is **≥ 3V**.
- `digitalWrite(redPin, HIGH)`: Turns the LED fully on if voltage is **≥ 4V**.
- `digitalWrite(redPin, LOW)`: Turns the LED off otherwise.
- `delay(myDelay)`: Adds a **500ms delay** between readings.

---

## Applications
- **Basic Voltage Monitoring**: The circuit can monitor voltage levels and respond accordingly.
- **Analog Input Demonstration**: Useful for beginners learning **analog-to-digital conversion** in Arduino.
- **Variable Brightness LED**: Demonstrates PWM (Pulse Width Modulation) for LED brightness control.

---

## Possible Improvements
- Use `map()` function to scale values directly.
- Add an **LCD display** to show real-time voltage values.
- Implement a **buzzer warning system** for high voltages.

This setup provides a simple yet effective way to interact with analog sensors and output devices using an Arduino Uno. 🚀
