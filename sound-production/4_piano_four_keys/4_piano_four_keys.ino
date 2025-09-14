// Pin initialization
const int BUZZER_PIN = 13;

const int KEY_1 = 4;
const int KEY_2 = 5;
const int KEY_3 = 6;
const int KEY_4 = 7;

// Frequencies initialization
const int C = 261; // Dó
const int D = 293; // Ré
const int E = 329; // Mi
const int F = 349; // Fá
const int G = 391; // Sol
const int A = 440; // Lá
const int B = 493; // Si
// The notes are defined in the alphabetic sistem, for silabic sistem look above for the comments sided with each one of them

void setup() {
  // Pin configuration
  pinMode(BUZZER_PIN, OUTPUT); // Buzzer

  // Key configuration
  pinMode(KEY_1, INPUT_PULLUP);
  pinMode(KEY_2, INPUT_PULLUP);
  pinMode(KEY_3, INPUT_PULLUP);
  pinMode(KEY_4, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(KEY_1) == LOW) {
    tone(BUZZER_PIN, C);
  }
  else if (digitalRead(KEY_2) == LOW) {
    tone(BUZZER_PIN, D);
  }
  else if (digitalRead(KEY_3) == LOW) {
    tone(BUZZER_PIN, E);
  }
  else if (digitalRead(KEY_4) == LOW) {
    tone(BUZZER_PIN, F);
  }
  else {
    noTone(BUZZER_PIN);
  }
}
