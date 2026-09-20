// Develop a program to blink 5 LEDs back and forth.

const int ledPins[] = {5, 6, 7, 8, 9};
const int numLeds = sizeof(ledPins) / sizeof(ledPins[0]);

int currentIndex = 0;
int direction = 1;

void setup() {
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins[i], LOW);
  }
}

void loop() {
  digitalWrite(ledPins[currentIndex], HIGH);
  delay(200);
  digitalWrite(ledPins[currentIndex], LOW);

  currentIndex += direction;

  if (currentIndex == numLeds - 1 || currentIndex == 0) {
    direction = -direction;
  }
}