# Voltage Divider Circuit with Arduino UNO

## Overview
This project demonstrates how to measure voltage using an **Arduino UNO** and a voltage divider circuit. The circuit consists of two **1kΩ resistors** forming a voltage divider. The divided voltage is read by the **A4 analog pin** of the Arduino and displayed on the **Serial Monitor**.

## Circuit Components
- **Arduino UNO**
- **Resistors:** 2 × 1kΩ
- **Power supply:** 5V from Arduino
- **Connecting wires**
- **Breadboard (optional)**

## Circuit Explanation
The circuit consists of a voltage divider formed using two 1kΩ resistors. The 5V supply from the Arduino is applied to the voltage divider, and the divided voltage is measured at the midpoint (between the two resistors) using **A4** of the Arduino.

### Voltage Divider Formula:
The output voltage across **R2** (measured at A4) is given by:

\[ V_2 = V_{in} \times \frac{R_2}{R_1 + R_2} \]

Since **R1 = R2 = 1kΩ**, the formula simplifies to:

\[ V_2 = \frac{V_{in}}{2} \]

For **V_{in} = 5V**, we get:

\[ V_2 = \frac{5V}{2} = 2.5V \]

Thus, the Arduino should read approximately **2.5V** at A4.

## Circuit Diagram
![Circuit Diagram](https://github.com/emon4075/Arduino-UNO-R3/blob/master/Arduino%20-%2010%20-%20Understanding%20How%20To%20Read%20Analog%20Voltage%20using%20analogRead%20Command/Arduino%20-%2010%20-%20Understanding%20How%20To%20Read%20Analog%20Voltage%20using%20analogRead%20Command.png)

## Code Explanation
The provided **Arduino sketch** reads the analog voltage at **A4** and converts it to a voltage value, which is then displayed on the **Serial Monitor**.

### Code Breakdown:
1. **Initialize variables:**
   - `readPin` is set to **A4**.
   - `readValue` stores the analog reading.
   - `V2` stores the converted voltage value.
   - `delayTime` defines a delay of **500ms** between readings.

2. **`setup()` function:**
   - Sets A4 as an **input**.
   - Initializes the **Serial Monitor** at **9600 baud**.

3. **`loop()` function:**
   - Reads the analog value from **A4**.
   - Converts it to voltage using the formula:
     
     \[ V2 = \frac{5.0}{1023.0} \times readValue \]
     
   - Prints the measured voltage to the **Serial Monitor**.
   - Introduces a delay of **500ms** between consecutive readings.

### Arduino Code:
```cpp
int readPin = A4;
int readValue;
float V2 = 0;
int delayTime = 500;

void setup() {
  pinMode(readPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  readValue = analogRead(readPin);
  V2 = (5.0 / 1023.0) * readValue;
  Serial.println(V2);
  delay(delayTime);
}
```

## Expected Output
When the circuit is correctly set up and the Arduino is powered, the **Serial Monitor** should display a voltage close to **2.5V**, which is the expected value based on the voltage divider calculation.

Example output:
```
2.48
2.50
2.51
2.49
```

## Applications
- **Voltage measurement:** This setup is useful for measuring voltage within a safe range.
- **Analog sensor interfacing:** Many sensors provide analog outputs that can be measured using a similar setup.
- **Battery monitoring:** This can be used to monitor battery levels using a scaled-down voltage.

## Conclusion
This project demonstrates a simple voltage divider circuit to measure and display voltage using an **Arduino UNO**. The concept of voltage division is fundamental in electronics, and this method can be applied to various applications, including battery monitoring and sensor interfacing.

