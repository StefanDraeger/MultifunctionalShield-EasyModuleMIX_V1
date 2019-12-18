#define drehpoti A0

void setup() {
  //beginn der seriellen Kommunikation mit 9600 baud
  Serial.begin(9600);  
}

void loop() {
  //auslesen des Wertes des Drehpotentiometers
  //und speichern in einer Variable
  //der Wert liegt Ganzzahlig zwischen 0 und 1023
  unsigned int value = analogRead(drehpoti);
  //ausgeben des Wertes auf der seriellen Schnittstelle
  Serial.println(value);  
  
  //oder 
  //gleichzeitiges auslesen des Wertes und ausgabe
  //auf der seriellen Schnittstelle
  //Serial.println(analogRead(drehpoti));  
}
