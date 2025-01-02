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
