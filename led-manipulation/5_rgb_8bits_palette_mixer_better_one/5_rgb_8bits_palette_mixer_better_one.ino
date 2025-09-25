// Poteciometer pin initialization
const int POTENTIOMETER_PIN = A0;

// LED pin initialization
const int RED_PIN = 11;
const int GREEN_PIN = 10;
const int BLUE_PIN = 9;

// Blackout button pin initialization
const int BLACKOUT_BUTTON = 13;

// Button pin initialization
const int RED_BUTTON = 7;
const int GREEN_BUTTON = 6;
const int BLUE_BUTTON = 5;
const int STAY = -1;

struct RGB { // We are working with a RGB LED, and, as such, it receives 3 int values that represents the intensities of each color
	uint8_t r;
	uint8_t g;
	uint8_t b;

	RGB(): r(0), g(0), b(0) {} // Default values

	void update(char buttonReading, int intensity) { // values control
		switch(buttonReading){
		case RED_BUTTON:
			r = intensity;
			break;
		case GREEN_BUTTON:
			g = intensity;
			break;
		case BLUE_BUTTON:
			b = intensity;
			break;
		}
	}

	void reset() { // blackout
		r = 0;
		g = 0;
		b = 0;
	}
};

// GLobal variables
RGB ledWriting; // color selected

uint8_t pwm = 0; // intensity reading
int potentiometerReading = 0; // potentiometer reading (needs adjustment)
char colorPressed = '0'; // Button control

int DEBOUNCE = 50;


void setup() {
	// LED pin configuration
	pinMode(RED_PIN, OUTPUT);
	pinMode(GREEN_PIN,OUTPUT);
	pinMode(BLUE_PIN,OUTPUT);

	// Button pin configuration
	pinMode(RED_BUTTON, INPUT_PULLUP);
	pinMode(GREEN_BUTTON, INPUT_PULLUP);
	pinMode(BLUE_BUTTON, INPUT_PULLUP);

	// Potentiometer pin configuration
	pinMode(POTENTIOMETER_PIN, INPUT);
	
	// Blackout button initialization  
	pinMode(BLACKOUT_BUTTON, INPUT_PULLUP);  
}

void loop() {
	potentiometerReading = analogRead(POTENTIOMETER_PIN); // The objective is to control the intensity of a color by the use of a potentiometer
	pwm = map(potentiometerReading, 0, 1023, 0, 255); // 10 bits to 8 bits

	colorPressed = getButtonReading();

	if (colorPressed == BLACKOUT_BUTTON) {
		ledWriting.reset();
	} else {
		ledWriting.update(colorPressed, pwm);
	}

	updateLedColoring(ledWriting); // You can add or update a color and it's intensity by adjusting the potentiometer before pressing the respective button, or turn everything off by pressing the designated button.
}

int getButtonReading() { // buttons control
	int btns[] = {RED_BUTTON, GREEN_BUTTON, BLUE_BUTTON, BLACKOUT_BUTTON};
	
	for (uint8_t i = 0; i < 4; i++) {
		if (digitalRead(btns[i]) == LOW){
			delay(DEBOUNCE);
			return btns[i];
		}
	}

	return STAY;
}

void updateLedColoring(RGB led) { // LED control
	analogWrite(RED_PIN, led.r);
	analogWrite(GREEN_PIN, led.g);
	analogWrite(BLUE_PIN, led.b);
}
