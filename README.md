
# CMPE310_Lab7
Arduino LCD Voltage Measurement

## Objective
Design and develop an Arduino-based voltage measurement
device that displays the measured voltage on an I2C LCD.

## 1. External Power Source
Does the circuit require an external power source?

Yes, the circuit requires 5V from the Arduino, which
receives power through USB from a laptop/computer.
The Arduino then supplies 5V to the circuit.

## 2. Required Libraries
Which Arduino libraries are required?

- `Wire.h`: Supports I2C communication.
- `LiquidCrystal_I2C.h`: Allows the Arduino to control the LCD.

## 3. Communication Protocol
Which communication protocol does the LCD use, and why?

The LCD uses I2C because it only requires two
signal wires (SDA and SCL) to communicate with
the Arduino.

## 4. Pin Connections
Identify the Arduino pins used for the LCD and
voltage measurements.

| Component | Arduino Pin |
|---|---|
| LCD GND | GND |
| LCD VCC | 5V |
| LCD SDA | A4 |
| LCD SCL | A5 |
| Voltage Divider Output | A0 |

## 5. Circuit Design
Explain the voltage divider and why this circuit
was selected.

The voltage divider was chosen because it allows
us to calculate a predictable voltage using resistors
and compare it to the Arduino's measured voltage.

### Voltage Divider Formula

**Case 1 - Two Resistors**

$$
V_{out} = V_{in}\frac{R_1}{R_1 + R_2}
$$

**Case 2 - Three Resistors**

$$
V_{out} = V_{in}\frac{R_1}{R_1 + R_2 + R_3}
$$

These formulas assume R1 is connected between
A0 and GND.

## 6. Arduino Implementation

The Arduino program uses `analogRead(A0)` to read
the voltage at the analog input.

The measured voltage is converted using:

$$
V_{measure} = \frac{5.0}{1023.0} \times voltageMeasure
$$

Both calculated and measured voltages are
displayed on the 16×2 LCD.

## 7. Experimental Results

### Case 1 - Two Resistors

| Measurement | Voltage (V) |
|---|---|
| Calculated | 2.50 |
| Measured | 2.40 |
| Difference | 0.10 |
| Percent Error | 4.00% |

### Case 2 - Three Resistors

| Measurement | Voltage (V) |
|---|---|
| Calculated | 1.67 |
| Measured | 1.60 |
| Difference | 0.07 |
| Percent Error | 4.19% |

### Results Discussion

In Case 1, the calculated voltage was 2.50V
and the measured voltage was 2.40V.

In Case 2, the calculated voltage was 1.67V
and the measured voltage was 1.60V.

Both measured voltages were close to their
calculated values.

The differences could be due to slight variations
in resistor values from their assumed ideal values
or the power supply not being exactly 5V.

## 8. Conclusion

The voltage measurement device worked as expected,
and there were no issues with the final results.
