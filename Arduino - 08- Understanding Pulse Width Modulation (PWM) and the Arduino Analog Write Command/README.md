# Arduino PWM Tutorial - Lesson 8

This lesson from Top Tech Boy explains Pulse Width Modulation (PWM) on the Arduino and demonstrates how the `analogWrite()` command uses PWM to simulate analog voltage levels using digital outputs.

---

## Table of Contents

- [Overview](#overview)
- [How PWM Works](#how-pwm-works)
- [PWM on Arduino with `analogWrite()`](#pwm-on-arduino-with-analogwrite)
- [Observing PWM with an Oscilloscope](#observing-pwm-with-an-oscilloscope)
- [Smoothing the PWM Signal](#smoothing-the-pwm-signal)
- [Conclusion](#conclusion)

---

## Overview

- **Objective:**  
  Learn how PWM allows the Arduino to simulate varying voltage outputs (e.g., to control LED brightness or motor speed) by rapidly switching between HIGH (5V) and LOW (0V).

- **Context:**  
  In previous lessons, you learned about digital commands (HIGH/LOW). This lesson explains how the Arduino produces intermediate values (like 2.5V) using PWM.

---

## How PWM Works

- **Digital Output Limitations:**  
  Arduino pins are digital, meaning they can only output 0V (LOW) or 5V (HIGH).

- **Simulating Analog Voltages:**  
  PWM achieves analog-like behavior by rapidly toggling the output between HIGH and LOW.

- **Duty Cycle Concept:**  
  - The **duty cycle** is the percentage of one period that the signal is HIGH.
  - A duty cycle of 50% (e.g., using `analogWrite(pin, 127)`, where 127 is roughly half of 255) means:
    - The signal is HIGH (5V) half the time.
    - The signal is LOW (0V) half the time.
  - **Average Voltage:**  
    The average voltage over a complete cycle is determined by the duty cycle. For a 50% duty cycle, the average is approximately 2.5V.

- **Constant Period:**  
  The PWM signal maintains a fixed period (about 4 milliseconds in this lesson). Only the duration of the HIGH state within that period changes.

---

## PWM on Arduino with `analogWrite()`

- **Functionality:**  
  The command `analogWrite(pin, value)` accepts a value between 0 and 255:
  - `0` corresponds to a 0% duty cycle (0V, LED off).
  - `255` corresponds to a 100% duty cycle (5V, LED fully on).
  - Intermediate values (like 127) set the duty cycle to simulate intermediate voltages (e.g., ~2.5V).

- **Demonstration Examples:**
  - **Setting brightness to 0:**  
    The LED remains off; the output is 0V.
  - **Setting brightness to 255:**  
    The LED is at full brightness; the output is nearly 5V.
  - **Setting brightness to 127:**  
    The LED appears at half brightness; the PWM signal alternates between 5V and 0V with a 50% duty cycle, averaging around 2.5V.

---

## Observing PWM with an Oscilloscope

- **Waveform Visualization:**  
  An oscilloscope displays the PWM signal as a square wave:
  - The waveform shows distinct periods of 5V and 0V.
  - For a mid-range `analogWrite` value (e.g., 127), the scope reveals a pattern where the output is 5V for half the cycle and 0V for the other half.
  
- **Measuring the Period:**  
  In the demonstration, the PWM period was observed to be around 4 milliseconds. The duty cycle (percentage of time HIGH) remains the only variable affecting the average output voltage.

---

## Smoothing the PWM Signal

- **Need for Smoothing:**  
  While PWM is effective for applications like LED dimming or motor control, some applications require a true analog voltage.

- **Using a Capacitor:**  
  - Placing a capacitor (e.g., 1000µF) across the PWM output can smooth the rapid on-off transitions.
  - The capacitor charges during the HIGH phases and discharges during the LOW phases, resulting in a steadier voltage that approximates the PWM’s average value.

---

## Conclusion

- **Summary:**  
  - **PWM** is a technique that lets the Arduino simulate analog voltage levels using digital outputs by varying the duty cycle of a constant-period square wave.
  - The **`analogWrite()`** command sets a PWM duty cycle corresponding to a value between 0 and 255.
  - An **oscilloscope** can be used to visualize the PWM waveform, confirming the switching between 5V and 0V.
  - A **capacitor** can smooth the PWM signal to produce a more constant analog voltage if needed.

- **Takeaway:**  
  Understanding PWM is essential for controlling devices like LEDs and motors on the Arduino. It’s also a gateway to more advanced techniques where you may need to create true analog signals.