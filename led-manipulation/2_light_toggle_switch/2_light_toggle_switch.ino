// Pin initialization
const int BUTTON_PIN = 12;
const int LED_PIN = 13;

// Possible light(LED) switch states
enum SwitchState {
  ON,
  OFF
};

const int WAIT = 160; // Will be needed for button functional consistency

// State initialization
SwitchState currentState = OFF;

void setup(){
  // Pin configuration
  pinMode(BUTTON_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void manageOnState (){
  digitalWrite(LED_PIN, HIGH);
  if(digitalRead(BUTTON_PIN) == HIGH)
    changeState();
}

void manageOffState () {
  digitalWrite(LED_PIN, LOW);
  if(digitalRead(BUTTON_PIN) == HIGH)
    changeState();
}

void changeState() {
  currentState = (SwitchState)!currentState; // I don't really know if it was a good choice to do this, maybe it was too much modularization, but there we go
  // As there is only two possible states, this is a viable logic for state manipulation
}

void loop(){
  switch (currentState){
    case ON:
      manageOnState();
      break;
    case OFF:
      manageOffState();
      break;
  }
  delay(WAIT); // A loop starts and ends too quickly, so, to not change states various times at one press of the button, there needs to be some kind of blockage.
  // As  this is a very simple aplication, that will not be ampliated, there isn't a real problem at the use of delay
  // Since the execution is blocked, during the period of time that has been designated for the delay, any button presses will be ignored
}