import paho.mqtt client as mgtt
from random import randrange, uniform
import time
Mqttb=”mqtt.eclipseprojects.io”
Client=mqtt.client(“Temp-out”)
Client.connect(mqttb)
While True:
 randNumber=randrange(0,10)
 Client.publish(“Temperature”,randNumber)
 Print(“Just published “+str(randNumber)+”to topic Temperature”)
Time.sleep(2)
