# Arduino Sketch: Printing Even Numbers to Serial Monitor

## Description
This Arduino sketch prints even numbers from 1 to `N` (where `N = 10`) to the Serial Monitor, introducing a delay between each print. It demonstrates basic serial communication and loop control in an Arduino program.

## Code Breakdown

### Global Variables:
- `int N = 10;` → Defines the upper limit of the loop.
- `int myDelay = 500;` → Specifies a delay of 500 milliseconds (0.5 seconds) between prints.

### `setup()` Function:
- `Serial.begin(9600);` → Initializes serial communication at a baud rate of 9600.

### `loop()` Function:
- A `for` loop iterates from `1` to `N` (10).
- The `if` statement checks if `i` is even (`i % 2 == 0`). If true, it prints the value of `i` to the Serial Monitor.
- `delay(myDelay);` introduces a 500ms pause between prints.
- After completing the loop, a blank line is printed for separation before the loop restarts.

## Expected Serial Monitor Output
```
2
4
6
8
10

2
4
6
8
10

...
```
The sequence repeats indefinitely due to the continuous execution of the `loop()` function.

## How to Use
1. Copy and paste the code into the Arduino IDE.
2. Connect your Arduino board to your computer.
3. Upload the sketch to the board.
4. Open the Serial Monitor (set baud rate to 9600) to view the output.

## Applications
- Understanding loops and conditionals in Arduino programming.
- Learning serial communication basics.
- Implementing timed executions in embedded systems.
---