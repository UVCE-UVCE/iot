//Temp and humidity using lcd
#include <SimpleDHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

int dhtPin = 8; 
int led = 13;  

SimpleDHT11 dht(dhtPin); 

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Initialization..");
  delay(2000);
  lcd.clear();
    Serial.begin(9600);      
    pinMode(led, OUTPUT);    
    Serial.println("Temperature and Sensor");
}

void loop() {
    byte temp, humid;
    int val = dht.read(&temp, &humid, nullptr); 
    if (val != SimpleDHTErrSuccess) {
        Serial.println("Error");
        return;
    }
    lcd.setCursor(0,0);
   lcd.print("temp : ");
   lcd.print((int)temp);
    lcd.setCursor(0,1);
   lcd.print("Humidity : ");
   lcd.print((int)humid);

    if ((int)temp >32) {
    
        digitalWrite(led, HIGH);
    } else {
        digitalWrite(led, LOW);
    }
}

// time and date using lcd
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd (0x27,16,2);
int sec=0,m=0,hr=0;
int d=1,mon=1,y=2025;
int previousmillis=0;
int interval=1000;
void setup() {
  // put your setup code here, to run once:
  lcd.init();
  lcd.backlight();
  lcd.print("Initialization<<<<<");
   delay(1000);
   lcd.clear();
}

void updateDateTime(){
  sec++;
  if(sec==60){
    m++;
    if(m==60){
      hr++;
      if(hr==24){
        hr=0;
      }
    }
  }
} 

void printTime(){
  lcd.print(hr);
  lcd.print(":");
  lcd.print(m);
  lcd.print(":");
  lcd.print(sec);
}
void printDate(){
  lcd.print(d);
  lcd.print(":");
  lcd.print(mon);
  lcd.print(":");
  lcd.print(y);
}

void loop() {
if(millis()- previousmillis > interval){
  previousmillis=millis();
  updateDateTime();

  lcd.setCursor(0,0);
  lcd.print("Time: ");
  printTime();
  lcd.setCursor(0,1);
  lcd.print("Date: ");
  printDate();
}

}
