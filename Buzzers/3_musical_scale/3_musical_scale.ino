// Pin initialization
const int pino_buzzer = 13;

// Timer initialization
const long timer = 1000;

// Frequencies initialization
const int c = 261; // Dó
const int d = 293; // Ré
const int e = 329; // Mi
const int f = 349; // Fá
const int g = 391; // Sol
const int a = 440; // Lá
const int b = 493; // Si
// The notes are defined in the alphabetic sistem, for silabic sistem look above for the comments sided with each one of them

void setup(){
  // Pin configuration
  pinMode(pino_buzzer, OUTPUT);
}

void loop(){
  tone(pino_buzzer, c);
  delay(timer);

  tone(pino_buzzer, d);
  delay(timer);
  
  tone(pino_buzzer, e);
  delay(timer);
  
  tone(pino_buzzer, f);
  delay(timer);

  tone(pino_buzzer, g);
  delay(timer);

  tone(pino_buzzer, a);
  delay(timer);
  
  tone(pino_buzzer, b);
  delay(timer);

  noTone(pino_buzzer); // Small break
  delay(timer * 4); 
}