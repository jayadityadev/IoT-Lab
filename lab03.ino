// Develop a program to deploy an intruson detection system using ultrasonic and sound sensor.

const int triggerPin = 9;
const int echoPin = 10;
const int buzzerPin = 8;
long duration;
int distance;

void setup() {
	pinMode(triggerPin, OUTPUT);
	pinMode(echoPin, INPUT);
	pinMode(buzzerPin, OUTPUT);
	Serial.begin(9600);
}

void loop() {
	digitalWrite(triggerPin, LOW);
	delayMicroseconds(2);
	digitalWrite(triggerPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(triggerPin, LOW);

	duration = pulseIn(echoPin, HIGH);
	distance = duration * 0.034 / 2;

	if (distance < 50) {
		digitalWrite(buzzerPin, HIGH);
        Serial.println("Intrusion detected!");
	} else {
		digitalWrite(buzzerPin, LOW);
	}

	Serial.print("Distance: ");
	Serial.print(distance);
	Serial.println(" cm");
	Serial.print("Duration: ");
    Serial.print(duration);
    Serial.println(" µs");
	delay(500);
}