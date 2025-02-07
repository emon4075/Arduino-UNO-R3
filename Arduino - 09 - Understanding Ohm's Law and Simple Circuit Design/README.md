# Ohm's Law and Simple Circuit Analysis

## Table of Contents

- [Introduction](#introduction)
- [Ohm's Law Fundamentals](#ohms-law-fundamentals)
- [Circuit Analysis Examples](#circuit-analysis-examples)
  - [Single Resistor Circuit](#single-resistor-circuit)
  - [Two-Resistor Series Circuit](#two-resistor-series-circuit)
- [Building the Circuit](#building-the-circuit)
- [Testing and Troubleshooting](#testing-and-troubleshooting)
- [Next Steps](#next-steps)
- [Conclusion](#conclusion)

---

## Ohm's Law Fundamentals

- **Ohm's Law Equation:**  
  \[
  V = I \times R
  \]
  - **V:** Voltage (volts)
  - **I:** Current (amps, though in Arduino applications, currents are usually in milliamps or microamps)
  - **R:** Resistance (ohms)
- **Alternate Forms:**
  - To calculate current:  
    \[
    I = \frac{V}{R}
    \]
  - To calculate resistance:  
    \[
    R = \frac{V}{I}
    \]
- **Conceptual Analogy:**
  - **Voltage** is likened to water pressure.
  - **Current** is compared to water flow.
  - **Resistance** is similar to an obstruction in a pipe that restricts flow.
- **Note on Current Flow:**  
  Conventional current flows from the positive terminal to the negative terminal, which is opposite to the actual electron flow.

---

## Circuit Analysis Examples

### Single Resistor Circuit

- **Scenario:** A 5V supply is applied across a single resistor of 330 ohms.
- **Calculation:**  
  \[
  I = \frac{5\text{ V}}{330\Omega} \approx 15.15 \text{ mA}
  \]
- **Insight:**  
  - Using too small a resistor can result in excessive current, potentially damaging components (e.g., burning out an LED).
  - Using too large a resistor will limit the current excessively, possibly causing a component (like an LED) to be too dim.

### Two-Resistor Series Circuit

- **Circuit Setup:**  
  - Two resistors in series:  
    - \( R_1 = 330\Omega \)
    - \( R_2 = 100\Omega \)
  - Voltage Supply: 5V
- **Steps:**
  1. **Calculate the Equivalent Resistance:**  
     \[
     R_{\text{eq}} = R_1 + R_2 = 330\Omega + 100\Omega = 430\Omega
     \]
  2. **Determine the Circuit Current:**  
     \[
     I = \frac{5\text{ V}}{430\Omega} \approx 11.63 \text{ mA}
     \]
  3. **Calculate Voltage Drops Across Each Resistor:**
     - For \( R_1 \):  
       \[
       V_1 = I \times R_1 \approx 11.63\text{ mA} \times 330\Omega \approx 3.84 \text{ V}
       \]
     - For \( R_2 \):  
       \[
       V_2 = I \times R_2 \approx 11.63\text{ mA} \times 100\Omega \approx 1.16 \text{ V}
       \]
  4. **Verification:**  
     The sum of the voltage drops should equal the supply voltage:
     \[
     V_1 + V_2 \approx 3.84\text{ V} + 1.16\text{ V} = 5\text{ V}
     \]

---

## Building the Circuit

- **Hardware Needed:**
  - Arduino board (using the 5V output)
  - A prototyping (breadboard) kit (e.g., the Arduino “Lego” super starter kit)
  - Resistors: one 330Ω and one 100Ω resistor
  - Jumper wires
- **Assembly Overview:**
  - Connect the Arduino’s 5V pin to the first resistor (330Ω).
  - Wire the resistors in series by placing them in connected columns on the breadboard.
  - Complete the circuit by connecting the end of the resistor chain back to the Arduino’s ground (GND).
- **Tip:**  
  Even if the circuit is simple, careful placement and clear connections on the breadboard are essential.

---

## Testing and Troubleshooting

- **Digital Voltmeter Use:**
  - **Measuring Supply Voltage:**  
    The Arduino's 5V pin may output around 4.9V (instead of a perfect 5V) due to regulator tolerances.
  - **Voltage Verification:**
    - Voltage across \( R_2 \) is measured at approximately 1.16V.
    - Voltage across \( R_1 \) is measured at about 3.73V (a slight discrepancy due to the actual supply voltage).
- **Why Use a Voltmeter:**  
  - It is an invaluable tool for diagnosing circuit issues, such as checking if a resistor is burned out or if the Arduino is delivering the expected voltage.
  - Ensures that your calculated values match the physical measurements, confirming that your circuit analysis is correct.


---

## Conclusion

- This lesson provided a detailed introduction to Ohm's Law and basic circuit analysis, demonstrating:
  - How to calculate current and voltage drops in a circuit.
  - The importance of using the correct resistor values to ensure proper operation of components like LEDs.
  - Practical skills in assembling a circuit on a breadboard and verifying its operation using a digital voltmeter.
- Mastering these fundamentals will prepare you for more advanced projects and circuit designs in future lessons.
---