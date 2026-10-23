// Develop a program to a water level detection system using an ultrasonic sensor.

const int trigPin = 5;
const int echoPin = 18;

void setup() {
	Serial.begin(115200);
	pinMode(trigPin, OUTPUT);
	pinMode(echoPin, INPUT);
}

long getDistance() {
	digitalWrite(trigPin, LOW);
	delayMicroseconds(2);
	digitalWrite(trigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigPin, LOW);

	long duration = pulseIn(echoPin, HIGH);
	long distance = duration * 0.034 / 2;
	return distance;
}

void loop() {
	long distance = getDistance();
	Serial.print("Water Level Distance: ");
	Serial.print(distance);
	Serial.println(" cm");
	delay(1000);
}
