// Poteciometer pin initialization
const int POTENCIOMETER_PIN = A0;

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

struct RGB { // We are working with a RGB LED, and, as such, it receives 3 int values that represents the intensities of each color
  uint8_t r;
  uint8_t g;
  uint8_t b;

  RGB() : r(0), g(0), b(0) {} // Default values
}; 

// GLobal variables
RGB ledWriting; // color selected

uint8_t pwm = 0; // intensity reading
int potenciometerReading = 0; // potenciometer reading (needs adjustment)
char colorPressed = '0'; // Button control


void setup() {
  // LED pin configuration
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN,OUTPUT);
  pinMode(BLUE_PIN,OUTPUT);

  // Button pin configuration
  pinMode(RED_BUTTON, INPUT_PULLUP);
  pinMode(GREEN_BUTTON, INPUT_PULLUP);
  pinMode(BLUE_BUTTON, INPUT_PULLUP);

  // Potenciometer pin configuration
  pinMode(POTENCIOMETER_PIN, INPUT);
  
  // Blackout button initialization  
  pinMode(BLACKOUT_BUTTON, INPUT_PULLUP);  
}

void loop() {
  potenciometerReading = analogRead(POTENCIOMETER_PIN); // The objective is to control the insensity of a color by the use of a potenciometer
  pwm = map(potenciometerReading, 0, 1023, 0, 255); // 10 bits to 8 bits

  colorPressed = getButtonReading();
  updateRgbValues(colorPressed, pwm, &ledWriting); // Updating the RBG instance values
  
  updateLedColoring(ledWriting); // You can add or update a color and it's intesity by adjusting the potenciometer befor pressing the respective button, or turn everything off by pressing the determinated button.
}

char getButtonReading() { // setting values of each color according to the buttons pressed
  char color = 'stay';
  if (digitalRead(RED_BUTTON) == LOW) {
    color = 'r';
  }
  if (digitalRead(GREEN_BUTTON) == LOW) {
    color = 'g';
  }
  if (digitalRead(BLUE_BUTTON) == LOW) {
    color = 'b';
  }
  if (digitalRead(BLACKOUT_BUTTON) == LOW) {
    color = '0'; // Turn off button pressed
  }
  return color;
}

// Activates a color in a determinated intensity
void updateRgbValues(char buttonReading, int intensity, RGB* currentColoring) { // LED control
  int colorPin = 0;
  switch(buttonReading){
    case 'r':
      colorPin = RED_PIN;
      currentColoring->r = intensity;
      break;
    case 'g':
      colorPin = GREEN_PIN;
      currentColoring->g = intensity;
      break;
    case 'b':
      colorPin = BLUE_PIN;
      currentColoring->b = intensity;
      break;
    case '0': // turn off
      currentColoring->r = 0;
      currentColoring->g = 0;
      currentColoring->b = 0;
      break;
  }
}

void updateLedColoring (RGB led) {
  int redIntensity = led.r;
  int greenIntensity = led.g;
  int blueIntensity = led.b;

  analogWrite(RED_PIN, redIntensity);
  analogWrite(GREEN_PIN, greenIntensity);
  analogWrite(BLUE_PIN, blueIntensity);
}
