// Develop a program to classify dry and wet waste with the moisture sensor.

#define MOISTURE_SENSOR_PIN 34 // Use A0 for Arduino Uno

void setup() {
	Serial.begin(115200);
	delay(1000);
	Serial.println("Moisture-Based Waste Classification Started...");
}

void loop() {
	int moistureValue = analogRead(MOISTURE_SENSOR_PIN);

	Serial.print("Moisture Sensor Value: ");
	Serial.println(moistureValue);

	if (moistureValue > 2000) {
		Serial.println("Waste Type: DRY");
	} else {
		Serial.println("Waste Type: WET");
	}

	Serial.println("----------------------");
	delay(2000); // Delay for readability
}