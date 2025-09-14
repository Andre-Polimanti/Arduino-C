int const BUZZER_PIN = 13;

// Frequency control
int const BUTTON_PIN_1 = 2; // When pressed, lows the sound frequency.
int const BUTTON_PIN_2 = 3; // When pressed, increases it.

int const FREQUENCY_VARIATION = 50; // The value added or substracted on the frequency the moment one button is pressed.

int soundFrequency;

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);

  pinMode(BUTTON_PIN_1, INPUT_PULLUP);
  pinMode(BUTTON_PIN_2, INPUT_PULLUP);

  soundFrequency = 1000; // Inicial frequency value
}

void loop() {  
  tone(BUZZER_PIN, soundFrequency);
  
  if(digitalRead(BUTTON_PIN_1) == HIGH){
    soundFrequency -= FREQUENCY_VARIATION;
  }
  if(digitalRead(BUTTON_PIN_2) == HIGH){
    soundFrequency += FREQUENCY_VARIATION;
  }

  delay(100);
}
