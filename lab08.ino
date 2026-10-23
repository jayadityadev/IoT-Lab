// Develop a program to detect gas leakage in the surrounding environment.

const int gasSensorPin = A0;  // Use GPIO34 or GPIO36 if using ESP32.
const int buzzerPin = 13;     // Connect buzzer to digital pin.

void setup() {
	Serial.begin(115200);
	pinMode(buzzerPin, OUTPUT);
}

void loop() {
	int gasValue = analogRead(gasSensorPin);

	Serial.print("Gas Sensor Value: ");
	Serial.println(gasValue);

	if (gasValue > 300) {  // Threshold may vary depending on environment.
		digitalWrite(buzzerPin, HIGH);
		Serial.println("Gas leakage detected!");
	} else {
		digitalWrite(buzzerPin, LOW);
	}

	delay(1000);
}