// Develop a program to simulate interfacing with the keypad module to record the keystrokes.

#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
	{'1', '2', '3', 'A'},
	{'4', '5', '6', 'B'},
	{'7', '8', '9', 'C'},
	{'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {14, 27, 26, 25}; // Modify as per your wiring
byte colPins[COLS] = {33, 32, 19, 18}; // Avoid GPIOs 34–39

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
	Serial.begin(115200);
	Serial.println("Keypad Ready");
}

void loop() {
	char key = keypad.getKey();

	if (key) {
		Serial.print("Key Pressed: ");
		Serial.println(key);
	}
}