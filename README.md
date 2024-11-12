# Real-Time Clock and Temperature Monitor with OLED Display

This Arduino-based project reads the current time from a DS3231 real-time clock (RTC) module, displays it on an OLED screen, and monitors the ambient temperature using an analog temperature sensor. Additionally, it controls an RGB LED, setting its color based on the current time, and turns an LED on if the current second is a prime number.

## Features
- **Real-Time Clock Display**: Displays the current time in `HH:MM:SS` format.
- **Temperature Monitoring**: Measures and displays the current temperature in Celsius.
- **RGB LED Control**: Sets RGB LED color based on the current time.
- **Prime Second Detection**: Turns an LED on if the current second is a prime number.

## Requirements
- **Hardware**:
  - DS3231 Real-Time Clock (RTC) Module
  - OLED Display (128x64 resolution, SSD1306 driver)
  - Analog Temperature Sensor (e.g., NTC Thermistor)
  - RGB LED
  - LED (for prime seconds indication)
- **Libraries**:
  - [RTClib](https://github.com/adafruit/RTClib)
  - [U8glib](https://github.com/olikraus/u8glib)

## Wiring
| Component         | Arduino Pin |
|-------------------|-------------|
| DS3231 RTC Module | I2C (SDA, SCL) |
| OLED Display      | I2C (SDA, SCL) |
| Temperature Sensor| A0          |
| RGB LED - Red     | Digital Pin 8 |
| RGB LED - Green   | Digital Pin 9 |
| RGB LED - Blue    | Digital Pin 10 |
| LED (Prime)       | Digital Pin 7 |

## Setup
1. **Install Libraries**:
   - Install RTClib and U8glib libraries in the Arduino IDE via the Library Manager.
2. **Connect Hardware** according to the wiring table above.
3. **Upload Code** to your Arduino.

## Code Overview

### Setup
- Initializes serial communication, I2C communication for the RTC and OLED, and configures pins.
- Sets the RTC module to the current time during upload.

### Loop
- **Display Time and Temperature**: Continuously writes the current time and temperature to the OLED.
- **Prime Second LED Control**: Turns an LED on if the current second is a prime number.
- **RGB LED Color Control**: Changes the RGB LED color based on the current hour, minute, and second values.

### Functions
- getTime(): Retrieves the current time from the RTC and formats it.
- getTemp()`: Reads the temperature sensor and calculates temperature in Celsius.
- oledWrite(x1, y1, text1, x2, y2, text2)`: Writes text to specified coordinates on the OLED display.
- isPrime(n)`: Checks if a number is prime.
- getSeconds(), getHours(), getMinutes(): Returns the current seconds, hours, and minutes.
- setColor(red, green, blue): Sets the color of the RGB LED.

## Example Output
The OLED screen will display:

Time: HH:MM:SS
Temp: XX.X °C


The RGB LED changes color based on the time, and the prime indicator LED turns on when the current second is a prime number.

## License
This project is open-source and available under the MIT License. Feel free to modify and distribute as needed.

Enjoy building your real-time clock and temperature monitor with Arduino!
