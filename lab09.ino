// Develop a program to demonstrate weather station readings using Arduino.

#include <DHT.h>
#include <Wire.h>
#include <Adafruit_BMP085.h> // For BMP180

#define DHTPIN 4
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);
Adafruit_BMP085 bmp;

void setup() {
	Serial.begin(115200);
	dht.begin();

	if (!bmp.begin()) {
		Serial.println("BMP180 not detected.");
		while (1);
	}
}

void loop() {
	float temp = dht.readTemperature();
	float hum = dht.readHumidity();
	float pressure = bmp.readPressure() / 100.0;

	Serial.print("Temp: ");
	Serial.print(temp);
	Serial.print(" °C, ");
	Serial.print("Humidity: ");
	Serial.print(hum);
	Serial.print(" %, ");
	Serial.print("Pressure: ");
	Serial.print(pressure);
	Serial.println(" hPa");

	delay(2000);
}