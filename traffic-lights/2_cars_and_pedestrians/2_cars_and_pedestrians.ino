// Pins initialization
const int RED_CAR_LED = 13;
const int YELLOW_CAR_LED = 12;
const int GREEN_CAR_LED = 11;

const int RED_PEDESTRIAN_LED = 10;
const int GREEN_PEDESTRIAN_LED = 9;

//Timers configuration
const long RED_CARS_TIMER = 3000;
const long YELLOW_CARS_LIGHT_TIMER = 2000;
const long GREEN_CARS_LIGHT_TIMER = 3000;

// Pedestrian's blink configuration
const long PEDESTRIAN_LED_ON_DELAY = 300;
const long PEDESTRIAN_LED_OFF_DELAY = 200;

const int PEDESTRIAN_BLINK_MAX = 4;

void setup(){
  // - Pins configuration

  // Cars traffic lights
  pinMode(RED_CAR_LED, OUTPUT);
  pinMode(YELLOW_CAR_LED, OUTPUT);
  pinMode(GREEN_CAR_LED, OUTPUT);

  // Pedestrians traffic lights
  pinMode(RED_PEDESTRIAN_LED, OUTPUT);
  pinMode(GREEN_PEDESTRIAN_LED, OUTPUT);
}

void loop(){
  // Green for cars
  digitalWrite(RED_CAR_LED, LOW);
  digitalWrite(GREEN_CAR_LED, HIGH);
  // Red for pedestrians
  digitalWrite(RED_PEDESTRIAN_LED, HIGH);

  delay(GREEN_CARS_LIGHT_TIMER);
  
  
  // Yellow for cars
  digitalWrite(GREEN_CAR_LED, LOW);
  digitalWrite(YELLOW_CAR_LED, HIGH);

  delay(YELLOW_CARS_LIGHT_TIMER);
  

  // Red for cars
  digitalWrite(YELLOW_CAR_LED, LOW);
  digitalWrite(RED_CAR_LED, HIGH);
  // Green for pedestrians
  digitalWrite(RED_PEDESTRIAN_LED, LOW);
  digitalWrite(GREEN_PEDESTRIAN_LED, HIGH);

  delay(RED_CARS_TIMER);

  
  // The time for pedestrians is going low
  digitalWrite(GREEN_PEDESTRIAN_LED, LOW);
  digitalWrite(RED_PEDESTRIAN_LED, HIGH);

  // Start to blink the pedestrians red light
  for(int i = 0; i < PEDESTRIAN_BLINK_MAX; i++){
    delay(PEDESTRIAN_LED_ON_DELAY);
    digitalWrite(RED_PEDESTRIAN_LED, LOW);

    delay(PEDESTRIAN_LED_OFF_DELAY);
    digitalWrite(RED_PEDESTRIAN_LED, HIGH);
  }
}