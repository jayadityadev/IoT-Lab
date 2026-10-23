// Develop a program to read the pH value of various substances like milk, lime, and water.

#define PH_SENSOR_PIN 36 // GPIO36 (VP on ESP32)

void setup() {
	Serial.begin(115200);
	analogReadResolution(12); // 12-bit ADC (0–4095)
}

void loop() {
	int adc_value = analogRead(PH_SENSOR_PIN); // Read raw ADC value
	float voltage = (adc_value * 5.0) / 4095.0; // Convert ADC to voltage (0–3.3V)

	// Assume pH sensor gives 0V = pH 0 and 3.0V = pH 14 (standard range)
	float pH_value = (voltage / 3.0) * 14.0; // Linear mapping to pH

	Serial.print("ADC: ");
	Serial.print(adc_value);
	Serial.print(" | Voltage: ");
	Serial.print(voltage, 3);
	Serial.print(" V | Estimated pH: ");
	Serial.println(pH_value, 2);

	delay(2000); // Read every 2 seconds
}