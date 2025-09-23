// Pin initilization
const int POTENCIOMETER_PIN = A0;
const int LED_PIN = 11; // One of the pins that are compatible with pwm

// Global variables
int reading = 0;
int pwm = 0;

void setup() {
  // Pin configuration
  pinMode(POTENCIOMETER_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  reading = analogRead(POTENCIOMETER_PIN);
  
  // converts the data of 8 bits to 6
  pwm = map(reading, 0, 1023, 0, 255); 

  analogWrite(LED_PIN, pwm);
}
