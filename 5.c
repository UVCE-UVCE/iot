#define LED_PIN 13  // Pin where LED is connected

void setup() {
  Serial.begin(9600);         // Initialize serial communication
  pinMode(LED_PIN, OUTPUT);   // Set LED pin as output
}

void loop() {
  // Check if data is available to read from Serial Monitor
 
  if (Serial.available() > 0) {
    char input = Serial.read();  // Read the incoming byte

    // Ignore newline or carriage return characters
    if (input == '\n' || input == '\r') {
      return;
    }

    // Turn the LED on or off based on the received input
    if (input == '1') {
      digitalWrite(LED_PIN, HIGH);  // Turn LED on
      Serial.println("LED ON");
    } 
    else if (input == '0') {
      digitalWrite(LED_PIN, LOW);   // Turn LED off
      Serial.println("LED OFF");
    } 
    else {
      // If input is not 1 or 0, print a message
      Serial.println("Invalid input! Please send '1' to turn ON and '0' to turn OFF.");
    }
  }
}
