// In this project, we will use a LDR, associated with a voltage divider and a laser to be able to know if there is an obstacle between the laser and the LDR.

// Pin initialization
const int LDR_PIN = A0;

// Constants
const float CONNECTED_VOLTAGE = 5.0;
const float ADC_RESOLUTION = 1024.0; // The analogic conversor is one of 10 bits

// Laser specification
const float LASER_INTENSITY = 800.0; // Change for a higher number if the ambient light is too strong

// Variables
int reading = 0; // Read value
float voltage = 0.0;

void setup() {
  Serial.begin(9600); // 9600bps

  // Pin configuration
  pinMode(LDR_PIN, INPUT);
}

void loop() {
  reading = analogRead(LDR_PIN);

  Serial.print("Analogic reading: ");
  Serial.print(reading);
  Serial.print("\t");

  voltage = reading * CONNECTED_VOLTAGE / ADC_RESOLUTION;
  Serial.print("Transformed to voltage: ");
  Serial.print(voltage);
  Serial.print("V");

  Serial.println();

  Serial.print("Obstacle: ");
  if (reading <= LASER_INTENSITY) {
    Serial.print("Yes");
  }
  else {
    Serial.print("No");
  }

  Serial.println();

  delay(1000);
}
