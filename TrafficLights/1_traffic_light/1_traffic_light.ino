// Pins initialization
const int RED_LED = 13;
const int YELLOW_LED = 12;
const int GREEN_LED = 11;

// Timers initialization
const long RED_TIMER = 5000;
const long YELLOW_TIMER = 2000;
const long GREEN_TIMER = 3000;

void setup(){
  // Pin configuration
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
}

// As this is a simple project, there should be no problem in using delay.
void loop(){
  // Red light
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(RED_LED, HIGH);
  delay(RED_TIMER);
  
  // Yellow light
  digitalWrite(RED_LED, LOW);
  digitalWrite(YELLOW_LED, HIGH);
  delay(YELLOW_TIMER);
  
  // Green light
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(GREEN_LED, HIGH);
  delay(GREEN_TIMER);
}