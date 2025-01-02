#include <SimpleDHT.h>

int dhtPin = 8; // Pin where the DHT11 is connected
int led = 13;   // Pin where the LED is connected

SimpleDHT11 dht(dhtPin); // Initialize DHT11 object

void setup() {
    Serial.begin(9600);      // Initialize serial communication
    pinMode(led, OUTPUT);    // Set LED pin as output
    Serial.println("Temperature and Sensor");
}

void loop() {
    byte temp, humid;
    int val = dht.read(&temp, &humid, nullptr); // Use 'dht' instead of 'dht11'
    if (val != SimpleDHTErrSuccess) {
        Serial.println("Error");
        return;
    }
    Serial.print((int)temp);
    Serial.println(" C");
    Serial.print((int)humid);
    Serial.println(" H");

    if ((int)temp > 32) {
        digitalWrite(led, HIGH);
    } else {
        digitalWrite(led, LOW);
    }
}

//////////////////////////////////////////////////////////////////////////
#include <DHT.h>

// Constants
#define DHTPIN 2 // Pin connected to the DHT sensor
#define DHTTYPE DHT11 // Define sensor type (DHT11)
#define LEDPIN 13 // Pin connected to the LED
#define TEMP_THRESHOLD 30 // Temperature threshold for turning on the LED

DHT dht(DHTPIN, DHTTYPE); // Initialize DHT sensor

// Variables
int h; // Stores humidity value
int t; // Stores temperature value

void setup()
{
  Serial.begin(9600);
  Serial.println("Temperature and Humidity Sensor Test");
  
  dht.begin(); // Start the DHT sensor
  pinMode(LEDPIN, OUTPUT); // Set LED pin as output
}

void loop()
{
  // Read data and store it to variables h (humidity) and t (temperature)
  h = dht.readHumidity();
  t = dht.readTemperature();

  // Check if the readings are valid
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Print temp and humidity values to the serial monitor
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %, Temp: ");
  Serial.print(t);
  Serial.println(" °C");

  // Turn LED on if temperature exceeds threshold, otherwise turn it off
  if (t > TEMP_THRESHOLD) {
    digitalWrite(LEDPIN, HIGH); // Turn on LED
    Serial.println("Temperature too high! LED ON.");
  } else {
    digitalWrite(LEDPIN, LOW); // Turn off LED
    Serial.println("Temperature is normal. LED OFF.");
  }

  delay(1000); // Delay 1 second
}