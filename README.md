# Environmental Monitoring System

This project is an **Environmental Monitoring System** that measures various environmental parameters using multiple sensors. It collects data such as temperature, humidity, air quality, dust density, and atmospheric pressure, and displays the results on an OLED screen. The system is based on an Arduino and integrates several key components like the DHT11, MQ-135, GP2Y10, and a pressure sensor.

## Features:
- **Temperature & Humidity Monitoring (DHT11)**: Continuously measures ambient temperature and humidity levels, calculating the heat index for a more accurate representation of perceived temperature.
- **Air Quality Monitoring (MQ-135)**: Detects air quality and harmful gases like CO2, ammonia, and alcohol vapors, providing a raw sensor reading.
- **Dust Density Detection (GP2Y10)**: Measures particulate matter in the air to detect dust density, outputting data in mg/m³.
- **Atmospheric Pressure Monitoring**: Converts analog readings from the pressure sensor into atmospheric pressure in Pascals and millimeters of mercury (mmHg).
- **OLED Display**: Real-time data display for temperature, humidity, air quality, dust levels, and pressure values.

## Components:
- **Arduino**: Central microcontroller for managing sensor data and control logic.
- **DHT11**: Temperature and humidity sensor.
- **MQ-135**: Air quality sensor.
- **GP2Y10**: Dust sensor for particulate matter detection.
- **Pressure Sensor**: Analog sensor for measuring atmospheric pressure.
- **OLED Display (128x32)**: Displays real-time environmental data.

## How It Works:
1. The system continuously gathers data from the connected sensors.
2. Each sensor's reading is processed and converted into a human-readable format.
3. The data is displayed on the OLED screen, cycling through the different environmental metrics (temperature, humidity, air quality, dust density, and pressure).
4. All sensor values are also printed to the Serial Monitor for easy debugging and logging.

## Getting Started:

### Prerequisites:
- Arduino IDE
- Required Libraries:
  - `Adafruit_GFX`
  - `Adafruit_SSD1306`
  - `DHT`

### Installation:
1. **Install Required Libraries**: The system uses the `Adafruit_GFX`, `Adafruit_SSD1306`, and `DHT` libraries. Make sure these are installed in your Arduino IDE.
2. **Wiring**: Connect the sensors to the appropriate pins as specified in the code.
3. **Upload the Code**: Compile and upload the Arduino code to your board.
4. **Monitor**: View real-time data on the OLED display or in the Serial Monitor.

## Wiring Diagram:
- **DHT11**: Pin 8
- **MQ-135**: Analog Pin A1
- **GP2Y10 (Dust Sensor)**: Analog Pin A0
- **Pressure Sensor**: Analog Pin A3
- **OLED Display**: I2C pins (A4 for SDA, A5 for SCL on Arduino Uno)

## Future Enhancements:
- Integration of more advanced sensors (e.g., CO2 or PM2.5 sensors).
- Data logging to an SD card for long-term environmental monitoring.
- Wireless connectivity to send data to a cloud platform for remote monitoring.

## Contributors:
- **Sandipan**
- **Sarfaraj**

---

This project serves as a foundation for building more complex environmental monitoring systems, making it ideal for hobbyists, students, and researchers interested in IoT and environmental data collection.
