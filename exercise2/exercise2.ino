// Define LED pin assignments
#define RED_LED 10 // Assign the red LED to pin 10
#define GREEN_LED 9 // Assign the green LED to pin 9
#define YELLOW_LED 8 // Assign the yellow LED to pin 8

// Define sensor pin assignments
#define LIGHT A5 // Assign the light sensor to pin A5
#define TMP A3 // Assign the temperature sensor to pin A3

void setup() {
  Serial.begin(9600); // Initialize serial communication at 9600 bits per second
  
  // Set the LED pins as outputs
  pinMode(RED_LED, OUTPUT); // Set red LED pin as an output
  pinMode(GREEN_LED, OUTPUT); // Set green LED pin as an output
  pinMode(YELLOW_LED, OUTPUT); // Set yellow LED pin as an output
}

void loop() {
  // Read the simulated temperature value
  int temRead = (analogRead(TMP) * 4.88 - 500) / 10; // Convert the analog reading (0-1023) to temperature in Celsius
  
  // Read the light intensity value
  int lightRead = analogRead(LIGHT); // Read the analog value from the light sensor (0-1023)
  
  // Print the temperature and light intensity to the serial monitor
  Serial.print("Simulated Temperature: ");
  Serial.print(temRead);
  Serial.print("C, The Light Intensity: ");
  Serial.print(lightRead);
  Serial.println("%.");
  
  // Check the dependency between temperature and light intensity and act accordingly
  dependency(temRead, lightRead);
  
  // Wait for 2 seconds before repeating the loop
  delay(2000); 
}

// Function to act based on the temperature and light conditions
void dependency(float tem, int light) {
  // Turn off all LEDs initially
  digitalWrite(RED_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  
  // Check for normal conditions and light up the green LED if true
  if ((tem < -12 && light == 0) ||
      (tem >= -12 && tem < 0 && light >= 1 && light <= 20) ||
      (tem >= 0 && tem < 21 && light >= 21 && light <= 60) ||
      (tem >= 21 && light >= 61 && light <= 100)) {
    Serial.println("Normal condition - Green LED ON");
    digitalWrite(GREEN_LED, HIGH); // Turn on the green LED under normal conditions
  } 
  // Check conditions where the temperature is lower than expected for the given light intensity and turn on the yellow LED
  else if ((tem >= -12 && tem < 0 && light > 20) ||
           (tem >= 0 && tem < 21 && light > 60) ||
           (tem < -12 && light > 0)) { // This condition might not actually occur, as below -12°C should be 0% light
    Serial.println("Temperature is lower than expected for the light intensity - Yellow LED ON");
    digitalWrite(YELLOW_LED, HIGH); // Turn on the yellow LED when temperature is lower than expected
  } 
  // Check conditions where the temperature is higher than expected for the given light intensity and turn on the red LED
  else if ((tem >= 21 && light < 61) ||
           (tem >= 0 && tem < 21 && light < 21) ||
           (tem >= -12 && tem < 0 && light < 1)) {
    Serial.println("Temperature is higher than expected for the light intensity - Red LED ON");
    digitalWrite(RED_LED, HIGH); // Turn on the red LED when temperature is higher than expected
  }

  // Wait for 2 seconds
  delay(2000); // Wait for 2 seconds
  
  // Turn off all LEDs to prepare for the next loop iteration
  digitalWrite(RED_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
}
