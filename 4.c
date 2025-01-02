const int ledPin = 13;    // Pin connected to LED
const int buttonPin = 2;  // Pin connected to button
bool ledState = false;    // Tracks the LED state
bool buttonState = false; // Tracks button pressed state

void setup() {
  pinMode(ledPin, OUTPUT);          // LED as output
  pinMode(buttonPin, INPUT); // Button as input with pull-up
}

void loop() {
  // Check if button is pressed (LOW state due to pull-up)
  if (digitalRead(buttonPin) == LOW && !buttonState) {
    buttonState = true;             // Mark button as pressed
    ledState = !ledState;           // Toggle LED state
    digitalWrite(ledPin, ledState); // Update LED
    delay(200);                     // Small debounce delay
  }

  // Reset buttonState when button is released (HIGH state)
  if (digitalRead(buttonPin) == HIGH) {
    buttonState = false;
  }
}
