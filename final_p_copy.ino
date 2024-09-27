#include "DHT.h"
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define DHTPIN 8          // Digital pin connected to the DHT sensor
#define mq135Pin A1       // Analog pin for MQ-135 sensor
#define mq135HeaterPin 2  // Digital pin to control the heater
#define dustPin A0        // Analog pin for GP2Y10 sensor
#define pressurePin A3    // Analog pin for Pressure sensor
#define OLED_WIDTH 128    // OLED display width, in pixels
#define OLED_HEIGHT 32    // OLED display height, in pixels

#define DHTTYPE DHT11     // DHT 11
#define OLED_ADDR 0x3C    // OLED I2C address
Adafruit_SSD1306 display(OLED_WIDTH, OLED_HEIGHT);

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx, MQ-135, GP2Y10 test!"));

  // DHT sensor setup
  dht.begin();

  // MQ-135 sensor setup
  pinMode(mq135HeaterPin, OUTPUT);
  digitalWrite(mq135HeaterPin, HIGH);  // Turn on the heater
  delay(20000);  // Allow the sensor to stabilize (heating time)

  // OLED display setup
  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
  display.clearDisplay();
  display.setTextSize(1.3);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("Welcome to");
  display.println("Our Project");
  display.println("Sandipan & Sarfaraj");
  display.display();
  delay(5000);
}

void loop() {
  // DHT sensor loop
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);

  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    display.clearDisplay();
    display.setCursor(0, 0);
    display.print("Failed to read from DHT sensor!");
  } else {
    float hic = dht.computeHeatIndex(t, h, false);
    Serial.print(F("DHT - Humidity: "));
    Serial.print(h);
    Serial.print(F("%  Temperature: "));
    Serial.print(t);
    Serial.print(F("°C "));
    Serial.print(f);
    Serial.print(F("°F  Heat index: "));
    Serial.print(hic);
    Serial.println(F("°C "));

    display.clearDisplay();
    display.setCursor(0, 0);
    display.println(F("Temperature and Humidity: "));
    display.print(F("Humidity : "));
    display.print(h);
    display.println(F("%"));
    display.display();
    delay(5000);

    display.clearDisplay();
    display.setCursor(0, 0);
    display.println(F("Temperature: "));
    display.print("Temperature: ");
    display.print(t);
    display.print(F(" deg C, "));
    display.print(f);
    display.println(F(" deg F"));
    display.display();
  }

  delay(5000);

  // MQ-135 sensor loop
  int mq135SensorValue = analogRead(mq135Pin);
  Serial.print("MQ-135 Raw Sensor Value: ");
  Serial.println(mq135SensorValue);

  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("MQ-135 Sensor: ");
  display.print("Raw Sensor Value: ");
  display.println(mq135SensorValue);
  display.display();
  delay(5000);

  // GP2Y10 sensor loop (Dust sensor)
  int dustSensorValue = analogRead(dustPin);
  float voltage = dustSensorValue * (5.0 / 1023.0);  // Convert to voltage (assuming 5V Arduino)
  float dustDensity = 0.17 * voltage - 0.1;          // Example formula, adjust based on your sensor's datasheet

  // Pressure sensor loop
  int pressureValue = analogRead(pressurePin);
  float voltagePressure = pressureValue * (5.0 / 1023.0);  // Convert raw ADC value to voltage

  // Assuming sensor outputs 0-5V for 0-100 kPa pressure
  float pressure_kPa = (voltagePressure / 5.0) * 100.0;    // Convert voltage to pressure in kPa
  float pressure_Pa = pressure_kPa * 1000;                 // Convert kPa to Pascals
  float mm_of_Hg = pressure_Pa * 0.00750062;               // Convert Pascals to mmHg

  // Print the pressure values to the serial monitor
  Serial.print("Pressure: ");
  Serial.print(pressure_Pa);
  Serial.println(" Pa, ");
  Serial.print(mm_of_Hg);
  Serial.println(" mm of Hg");

  display.clearDisplay();
  display.setCursor(0, 0);
  display.println("Pressure Sensor: ");
  display.print("Pressure: ");
  display.print(pressure_Pa);
  display.println(" Pa");
  display.print(mm_of_Hg);
  display.println(" mm of Hg");
  display.display();
  delay(3500);

  // Print the dust values to the serial monitor
  Serial.print("GP2Y10 Sensor Value: ");
  Serial.print(dustSensorValue);
  Serial.print(", Voltage: ");
  Serial.print(voltage);
  Serial.print("V, Dust Density: ");
  Serial.print(dustDensity);
  Serial.println(" mg/m^3");

  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Dust Density: ");
  display.print(dustDensity);
  display.println(" mg/m^3");
  display.display();

  delay(5000);  // Delay for readability, adjust as needed
}

