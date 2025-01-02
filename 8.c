int trig=8;
int echo=9;

void setup() {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.println(9600);

}

void loop() {
  long distance,duration;

  digitalWrite(trig, HIGH);
  delayMicroseconds(2);
  digitalWrite(trig, LOW);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  duration=pulseIn(echo,HIGH);
  distance= (duration/29)/2;
  Serial.println(distance);
  delay(100);

}
