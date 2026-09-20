// Develop a program to deploy smart street light system using LDR sensor.

const int ldrPin = A0;
const int lightPin = 5;
const int lightThreshold = 200;

void setup() {
    pinMode(ldrPin, INPUT);
    pinMode(lightPin, OUTPUT);
    Serial.begin(9600);
}

void loop() {
	int ldrValue = analogRead(ldrPin);
    Serial.print("LDR Value: ");
    Serial.println(ldrValue);

	if (ldrValue < lightThreshold) {
		analogWrite(lightPin, HIGH);
	} else {
		analogWrite(lightPin, LOW);
	}
    delay(500);
}