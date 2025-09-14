// Pin initialization
const int BUZZER_PIN = 13;

// Timer initialization
const long TIMER = 1000;

// Frequencies initialization
const int C = 261; // Dó
const int D = 293; // Ré
const int E = 329; // Mi
const int F = 349; // Fá
const int G = 391; // Sol
const int A = 440; // Lá
const int B = 493; // Si
// The notes are defined in the alphabetic sistem, for silabic sistem look above for the comments sided with each one of them

void setup(){
  // Pin configuration
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop(){
  tone(BUZZER_PIN, C);
  delay(TIMER);

  tone(BUZZER_PIN, D);
  delay(TIMER);
  
  tone(BUZZER_PIN, E);
  delay(TIMER);
  
  tone(BUZZER_PIN, F);
  delay(TIMER);

  tone(BUZZER_PIN, G);
  delay(TIMER);

  tone(BUZZER_PIN, A);
  delay(TIMER);
  
  tone(BUZZER_PIN, B);
  delay(TIMER);

  noTone(BUZZER_PIN); // Small break
  delay(TIMER * 3); 
}