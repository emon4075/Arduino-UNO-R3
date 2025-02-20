# Mixing Colors with an RGB LED Using Arduino

## Overview
This tutorial explores how to mix primary colors using an RGB LED and an Arduino. It builds upon the concepts introduced in Lesson 20, explaining how to control an RGB LED to create various colors. By modifying the intensity of Red, Green, and Blue using the `analogWrite` function, we can produce a wide range of colors, including Yellow, Cyan, and Magenta. With **256 intensity levels** for each channel, over **16 million colors** can be generated.

---

## Prerequisites
Before proceeding with this tutorial, ensure that you have:
- Completed Lesson 20 on RGB LEDs.
- Access to an Elegoo Super Starter Kit (or an equivalent kit) containing:
  - An RGB LED (common anode or common cathode)
  - Resistors (if required for your LED type)
  - An Arduino board (e.g., Arduino Uno)
  - Jumper wires and a breadboard

As the presenter states:
> "...if you haven't already done lesson 20 you probably need to go back and do that one I don't want to start over from scratch because then this lesson would be too long but this is a follow-on from the earlier lesson number 20."

---

## Components Required
- **Arduino Uno**
- **RGB LED**
- **220Ω resistors (3x)**
- **Jumper wires**
- **Breadboard**

---

## Understanding RGB LED Control
RGB LEDs consist of three light-emitting diodes (Red, Green, and Blue) that can be controlled individually. By adjusting their intensity, we can mix colors to create new ones. The tutorial starts by demonstrating how to turn each color on individually using Arduino code:

```cpp
analogWrite(redPin, 255);   // Full intensity Red
analogWrite(greenPin, 0);   // Green Off
analogWrite(bluePin, 0);    // Blue Off
```

When this code runs, the LED will emit a pure red color.

---

## Color Mixing Theory
In this tutorial, the presenter explains:
- Mixing **Red** and **Green** produces **Yellow**.
- Mixing **Green** and **Blue** produces **Cyan**.
- Mixing **Blue** and **Red** produces **Magenta**.
- Combining all three colors produces **White**.

As the presenter explains:
> "If you take red and green you can mix and make yellow if you could take green and blue you can mix and make cyan if you take blue in red you can mix and get magenta okay but red and green and blue are not the only primary colors you could also come at it from this angle."

---

## Arduino Code Example

```cpp
// Define RGB pins (adjust based on your circuit)
const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  // Cycle through colors with 2-second delays
  setColor(255, 0, 0);    // Red
  delay(2000);
  setColor(0, 255, 0);    // Green
  delay(2000);
  setColor(0, 0, 255);    // Blue
  delay(2000);
  setColor(255, 255, 0);  // Yellow
  delay(2000);
  setColor(0, 255, 255);  // Cyan
  delay(2000);
  setColor(255, 0, 255);  // Magenta
  delay(2000);
}

void setColor(int red, int green, int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
}
```

---

## Adjusting Colors
- **Trial and Error**: Start with maximum values (e.g., `255` for Red + Green for Yellow) and tweak intensities to refine the color.
  - Example: If Magenta appears too blue, reduce the Blue value:
    ```cpp
    setColor(255, 0, 200);  // Adjusted Magenta
    ```
- **Tips**:
  - Use serial communication to test RGB values in real-time.
  - Account for variations in LED manufacturing (some may require balancing).

---

## The Full Range of Colors
With RGB LEDs, there are **256 intensity levels** (0-255) for each color channel. The total number of possible colors is calculated as:

> "255 different choices of how strong you want the red to be 255 choices of how strong you want the green to be and 255 choices of how strong you want the blue to be and actually if you include zero that's really 256 which results in 16 million different colors just by adjusting these three commands."

---

## Conclusion
This tutorial provides a hands-on approach to color mixing using an RGB LED and Arduino. It highlights key takeaways:
- **RGB LEDs allow for a vast range of color possibilities.**
- **Modifying the intensity of each channel creates different colors.**
- **Trial and error can help fine-tune colors for desired results.**

As the presenter summarizes:
> "...you can mix them to get cyan magenta and yellow and then you can just get any imaginable colors..."
