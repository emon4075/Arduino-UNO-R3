# Arduino Serial Port & Print Command : Circle Area

This Arduino sketch calculates and prints the area of a circle to the Serial Monitor. With each iteration of the loop, it increases the circle's radius, recalculates the area, and outputs the new values. This simple example also demonstrates how to initialize serial communication using a specific baud rate.

---

## Code Breakdown

```cpp
int circleRadius = 5;   // Initial radius of the circle.
float pi = 3.14;        // Approximate value of π (pi).
double circleArea;      // Variable to store the calculated area of the circle.
int myDelay = 500;      // Delay between iterations in milliseconds.

void setup() {
  Serial.begin(9600);   // Initializes serial communication at 9600 baud.
}

void loop() {
  // Calculate the area of the circle using the formula: area = π * radius².
  circleArea = pi * circleRadius * circleRadius;
  
  // Print the radius and its corresponding area to the Serial Monitor.
  Serial.print("A Circle With Radius ");
  Serial.print(circleRadius);
  Serial.print(" Has an Area of: ");
  Serial.println(circleArea);
  
  // Increment the radius by 1 for the next iteration.
  circleRadius += 1;
  
  // Wait for 500 milliseconds before repeating the loop.
  delay(myDelay);
}
```

### Key Components:

- **Variables:**
  - `circleRadius`: Starts at 5 and increases by 1 with each loop iteration.
  - `pi`: A float variable representing the approximate value of π.
  - `circleArea`: A double variable to store the computed area.
  - `myDelay`: Represents a 500 millisecond delay between each loop execution.

- **setup() Function:**
  - Runs once when the program starts.
  - `Serial.begin(9600);` initializes serial communication at a baud rate of 9600 bits per second.

- **loop() Function:**
  - Continuously executes after the `setup()` function.
  - Calculates the circle's area using the formula: **area = π * radius²**.
  - Prints the current radius and area to the Serial Monitor.
  - Increments the radius to ensure the next calculation uses a larger circle.
  - Pauses execution for 500 milliseconds before the next iteration.

---

## Baud Rate (9600) Explained

- **What is a Baud Rate?**
  - The baud rate defines the speed of data transmission in a serial communication channel. It is measured in bits per second (bps).

- **Why 9600?**
  - `Serial.begin(9600);` sets the communication speed to **9600 bits per second**.
  - This is a common baud rate for many Arduino projects because it provides a good balance between data transfer speed and reliability.
  
- **Important Considerations:**
  - **Matching Baud Rates:** For successful communication, ensure that the baud rate set in the Arduino sketch (`9600` in this case) matches the baud rate configured in your Serial Monitor or any other serial communication tool.
  - **Data Integrity:** Using a standardized baud rate like 9600 helps prevent data loss and errors during transmission.

---

## How to Use This Sketch

1. **Upload the Code:**
   - Connect your Arduino board to your computer.
   - Open the Arduino IDE, paste the code, and upload it to your board.

2. **Open the Serial Monitor:**
   - After uploading, open the Serial Monitor in the Arduino IDE.
   - Make sure the baud rate in the Serial Monitor is set to **9600** to match the code's configuration.

3. **View the Output:**
   - The Serial Monitor will display messages showing the circle's current radius and the corresponding area.
   - With every loop, the radius increases by 1 and a new area is calculated and displayed.

---

## Summary

This sketch is a straightforward example of:
- **Mathematical Computation:** Calculating the area of a circle.
- **Serial Communication:** Sending data from the Arduino to your computer.
- **Using a Delay:** Creating pauses between loop iterations to control the output frequency.

Understanding how baud rate works is essential for ensuring that the Arduino and your computer communicate effectively, which is particularly important for debugging and monitoring sensor data or other outputs.