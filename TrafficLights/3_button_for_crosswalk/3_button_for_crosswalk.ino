// Pin initialization
const int LED_CAR_RED = 13;
const int LED_CAR_YELLOW = 12;
const int LED_CAR_GREEN = 11;

const int LED_PEDESTRIAN_RED = 10;
const int LED_PEDESTRIAN_GREEN = 9;

const int PEDESTRIAN_BUTTON = 6; // There is a resistor in the protoboard exclusive to this button, sop there is no flutuation.
const int WAIT_LED = 5; // Blinks to indicate the passing of time until the pedestrian's traffic light turns green.

enum TrafficLightState {
  CAR_GREEN,
  WAITING,
  CAR_YELLOW,
  PEDESTRIAN_GREEN,
  PEDESTRIAN_BLINK
};

TrafficLightState currentState = CAR_GREEN;

const long YELLOW_INTERVAL = 2800;
const long PEDESTRIAN_GREEN_INTERVAL = 5000;

const long PEDESTRIAN_RED_BLINK_INTERVAL = 350;
const int PEDESTRIAN_RED_BLINKS = 4;

const long WAIT_LED_BLINK_INTERVAL = 200;
const int WAIT_LED_BLINKS = 6;

unsigned long previousTime;
int blinkCounter = 0;

void manageCarGreenState(unsigned long currentTime) {
  if (digitalRead(PEDESTRIAN_BUTTON) == HIGH) {
    Serial.println("Button pressed! Starting countdown to change to Yellow...");
    previousTime = currentTime;
    blinkCounter = 0;
    currentState = WAITING;
  }
}

void manageWaitingState(unsigned long currentTime) {
  if (currentTime - previousTime >= WAIT_LED_BLINK_INTERVAL) {
    digitalWrite(WAIT_LED, !digitalRead(WAIT_LED));
    previousTime = currentTime;
    blinkCounter++;
  }

  if (blinkCounter >= WAIT_LED_BLINKS * 2) {
    Serial.println("End of waiting period.");
    digitalWrite(LED_CAR_GREEN, LOW);
    digitalWrite(LED_CAR_YELLOW, HIGH);
    digitalWrite(WAIT_LED, LOW);
    previousTime = currentTime;
    currentState = CAR_YELLOW;
  }
}

void manageCarYellowState(unsigned long currentTime) {
  if (currentTime - previousTime >= YELLOW_INTERVAL) {
    Serial.println("Yellow light time expired. Green for pedestrians and red for cars.");
    digitalWrite(LED_CAR_RED, HIGH);
    digitalWrite(LED_PEDESTRIAN_GREEN, HIGH);
    digitalWrite(LED_CAR_YELLOW, LOW);
    digitalWrite(LED_PEDESTRIAN_RED, LOW);
    previousTime = currentTime;
    currentState = PEDESTRIAN_GREEN;
  }
}

void managePedestrianGreenState(unsigned long currentTime) {
  if (currentTime - previousTime >= PEDESTRIAN_GREEN_INTERVAL) {
    Serial.println("Pedestrian time expired. Starting blinking red for pedestrians.");
    digitalWrite(LED_PEDESTRIAN_GREEN, LOW);
    digitalWrite(LED_PEDESTRIAN_RED, HIGH);
    previousTime = currentTime;
    blinkCounter = 0;
    currentState = PEDESTRIAN_BLINK;
  }
}

void managePedestrianBlinkState(unsigned long currentTime) {
  if (currentTime - previousTime >= PEDESTRIAN_RED_BLINK_INTERVAL) {
    digitalWrite(LED_PEDESTRIAN_RED, !digitalRead(LED_PEDESTRIAN_RED));
    previousTime = currentTime;
    blinkCounter++;
  }

  if (blinkCounter >= PEDESTRIAN_RED_BLINKS * 2) {
    Serial.println("End of pedestrian cycle. Returning to initial state.");
    digitalWrite(LED_PEDESTRIAN_GREEN, LOW);
    digitalWrite(LED_PEDESTRIAN_RED, HIGH);
    digitalWrite(LED_CAR_RED, LOW);
    digitalWrite(LED_CAR_GREEN, HIGH);
    currentState = CAR_GREEN;
  }
}

void setup() {
  pinMode(LED_CAR_GREEN, OUTPUT);
  pinMode(LED_CAR_YELLOW, OUTPUT);
  pinMode(LED_CAR_RED, OUTPUT);
  pinMode(LED_PEDESTRIAN_GREEN, OUTPUT);
  pinMode(LED_PEDESTRIAN_RED, OUTPUT);
  pinMode(PEDESTRIAN_BUTTON, INPUT);
  Serial.begin(9600);
  
  Serial.println("Initial State: Green for cars");
  digitalWrite(LED_CAR_GREEN, HIGH);
  digitalWrite(LED_PEDESTRIAN_RED, HIGH);
}

void loop() {
  unsigned long currentTime = millis();

  switch (currentState) {
    case CAR_GREEN:
      manageCarGreenState(currentTime);
      break;
    case WAITING:
      manageWaitingState(currentTime);
      break;
    case CAR_YELLOW:
      manageCarYellowState(currentTime);
      break;
    case PEDESTRIAN_GREEN:
      managePedestrianGreenState(currentTime);
      break;
    case PEDESTRIAN_BLINK:
      managePedestrianBlinkState(currentTime);
      break;
  }
}