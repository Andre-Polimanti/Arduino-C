const int BUZZER_PIN = 13; // The buzzer is connected to the 13 pin.

const int SOUND_FREQUENCY = 1300; // Lower for low-pitched sounds and higher otherwise.

// Timers control
const int SOUND_DURATION = 300;
const int SILENCE_DURATION = 500;

void setup(){
  pinMode(BUZZER_PIN, OUTPUT); // Pin configuration.
}

void loop(){
  tone(BUZZER_PIN, SOUND_FREQUENCY); // Generates sound.
  delay(SOUND_DURATION);

  noTone(BUZZER_PIN); // Initiates a break.
  delay(SILENCE_DURATION);
}