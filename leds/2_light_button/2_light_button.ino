// Pin initialization
const int BUTTON_PIN = 12;
const int LED_PIN = 13;

void setup(){
  // Pin configuration
  pinMode(BUTTON_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop(){
  if (digitalRead(BUTTON_PIN) == HIGH){ // if pressed light up the LED
    digitalWrite(LED_PIN, HIGH);
  }
  else{ // if not pressed turn it off
    digitalWrite(LED_PIN, LOW); 
  }
}