//Lichtsensor / Fotowiderstand am analogen Pin A0
#define lightSensor A0

void setup() {
  //beginn der seriellen Kommunikation
  Serial.begin(9600);
}

void loop() {
  //lesen des aktuellen, analogen Wertes des Lichtsensors
  int value = analogRead(lightSensor);
  //ausgeben des Wertes auf der seriellen Schnittstelle
  Serial.println(value);
}
