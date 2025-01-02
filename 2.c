// Define thepins for the traffic lights
#define red 11
#define yellow 10
#define green 9

void setup() {
  // Set the light pins as outputs
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
}

void loop() {
  // Turn on the red light
  digitalWrite(red, HIGH);
  digitalWrite(yellow, LOW);
  digitalWrite(green, LOW);
  delay(5000); // Red light for 5 seconds

  // Turn on the green light
  digitalWrite(green, HIGH);
  digitalWrite(red, LOW);
  digitalWrite(yellow, LOW);
  delay(2000); // Green light for 5 seconds

  // Turn on the yellow light
  digitalWrite(yellow, HIGH);
    digitalWrite(green, LOW);
  digitalWrite(red, LOW);
  delay(2000); // Yellow light for 2 seconds
 
}
