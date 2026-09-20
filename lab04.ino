// Develop a program to control a DC motor with Arduino board.

const int relayPin = 7;
const int buttonPin = 2;

void setup() {
	pinMode(relayPin, OUTPUT);
    pinMode(buttonPin, INPUT);
    Serial.begin(9600);
}

void loop() {
	int buttonState = digitalRead(buttonPin);
    Serial.println(buttonState);
    if (buttonState == 0) {
        digitalWrite(relayPin, HIGH);
    } else {
        digitalWrite(relayPin, LOW);
    }
}