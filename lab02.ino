// Develop a program to interface a relay with Arduino board.

const int relayPin = 7;

void setup() {
	pinMode(relayPin, OUTPUT);
	digitalWrite(relayPin, HIGH);
}

void loop() {
	digitalWrite(relayPin, LOW);
	delay(1000);
	digitalWrite(relayPin, HIGH);
	delay(1000);
}