#include<SoftwareSerial.h>
#include “Adafruit-FONA.h”
#define FONA_RX 12
#define FONA_TX 13
#define FONA_R!_INTERRUPT 11
Char sendto[21]=”70xxxxxxxxx”;
Char meg[141]=”welcome”;
String t;
SoftwareSerial fonass=softwareSerial(FONA_TX,FONA_RX);
Adafruit_FONA fona=Adafruit_FONA(FONA_RST);
Void setup (){
 Serial.begin(115200);
 Serial.println(F(“FONA incoming call”));
 Delay(5000);
 Fonass.begin(4800);
 If(!fona.begin(fonass)){
Serial.println(F(“FONA is ok”));
 Fona.print(“AT+(SMP =17,167,0,0\r”);
Fona.sendSMS(sendto,message);
Delay(100);
}
