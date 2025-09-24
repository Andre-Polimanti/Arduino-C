// LED pin initialization
const int RED_PIN = 11;
const int GREEN_PIN = 10;
const int BLUE_PIN = 9;

// Button pin initialization
const int RED_BUTTON = 7;
const int GREEN_BUTTON = 6;
const int BLUE_BUTTON = 5;

struct RGB { // We are working with a RGB LED, and, as such, it receives 3 int values that represents the intensities of each color
  int r;
  int g;
  int b;

  RGB() : r(0), g(0), b(0) {} // Default values
}; 

RGB reading; // Global intensities variable

void setup() {
  // LED pin configuration
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN,OUTPUT);
  pinMode(BLUE_PIN,OUTPUT);

  // Button pin configuration
  pinMode(RED_BUTTON, INPUT_PULLUP);
  pinMode(GREEN_BUTTON, INPUT_PULLUP);
  pinMode(BLUE_BUTTON, INPUT_PULLUP);
}

void loop() {
  reading = getReading();
  updateColoring(reading);
}

RGB getReading() { // setting values of each color sccording to the buttons pressed
  RGB val;
  
  if (digitalRead(RED_BUTTON) == LOW) {
    val.r = 1;
  }
  if (digitalRead(GREEN_BUTTON) == LOW) {
    val.g = 1;
  }
  if (digitalRead(BLUE_BUTTON) == LOW) {
    val.b = 1;
  }
  return val;
}

// This function implements a "latching" behavior: colors are added and accumulated when a button is pressed, only being erased when all buttons are unpressed
// You can mix colors if you press at least two buttons, and can keep the mixed color while pressing at least one of the involved buttons
// When Red, Green and Blue are accumulated, according to theory the color showed is White
void updateColoring(RGB val) { // LED control
  if(val.r){
    analogWrite(RED_PIN, 255);
  }
  if(val.g){
    analogWrite(GREEN_PIN, 255);
  }
  if(val.b){
    analogWrite(BLUE_PIN, 255);
  }
  if(!(val.r) && !(val.g) && !(val.b)){ // Only deactivates the colors in the cenario where all buttons are unpressed
    analogWrite(RED_PIN, 0);
    analogWrite(GREEN_PIN, 0);
    analogWrite(BLUE_PIN, 0);
  }
}