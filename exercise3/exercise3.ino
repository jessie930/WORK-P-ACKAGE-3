// C code for Arduino
#define tem_pin A0 // Define tem_pin as A0, where the temperature sensor is connected

void setup() {
  pinMode(tem_pin, INPUT); // Set the temperature sensor pin as an input
  
  Serial.begin(9600); // Start serial communication at 9600 bits per second
}

void loop() {
  int temValue = analogRead(tem_pin); // Read the analog value from the temperature sensor
  float voltag = temValue * (5.0 / 1023.0) * 1000; // Convert the analog value to voltage in millivolts
  float temperature = (voltag - 500) / 10; // Calculate the temperature in Celsius from the voltage
  
  Serial.print("Temperature: "); // Print "Temperature: " to the serial monitor
  Serial.print(temperature); // Print the calculated temperature value to the serial monitor
  Serial.println(" C"); // Print " C" to denote Celsius and move to a new line
  
  delay(500); // Wait for half a second (500 milliseconds) before repeating the loop
}
