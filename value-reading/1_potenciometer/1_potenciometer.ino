// Pin initialization
const int POTENCIOMETER_PIN = A0;

// Global variables
int reading = 0; // variável para armazenar o valor lido pelo ADC
float voltage = 0.0; // variável para armazenar a tensão

// Constants
const int SLEEP = 150; // Delay in reading

void setup() {
  Serial.begin(9600);

  // Pin configuration
  pinMode(POTENCIOMETER_PIN, INPUT);
}

void loop() {
  reading = analogRead(POTENCIOMETER_PIN);

  voltage = reading * 5.0 / 1024.0;

  // if you want to see the serial monitor, uncomment the following line 
  //Serial.print("Voltage: ")

  Serial.println(voltage); // serial plotter print
  
  delay(SLEEP);
}