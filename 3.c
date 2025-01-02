// Define the LDR pin and the LED pin
int ldr=A0;  // Analog pin connected to the LDR
int led=13;  // Digital pin connected to the LED
int threshold=400;

void setup() {
  Serial.begin(9600);  // Initialize serial communication
  pinMode(led, OUTPUT); // Set the LED pin as output
}

void loop() {
  int ldrValue = analogRead(ldr); // Read the LDR value

  // Print the LDR value to the Serial Monitor
  Serial.print("LDR Value: ");
  Serial.println(ldrValue);

  // Turn the LED on or off based on the LDR value
  if (ldrValue < threshold) { // Adjust the threshold as needed
    digitalWrite(led, HIGH);  // Turn the LED on
  } else {
    digitalWrite(led, LOW);   // Turn the LED off
  }

  delay(1000); // Wait for 1 second before reading the LDR again
}
