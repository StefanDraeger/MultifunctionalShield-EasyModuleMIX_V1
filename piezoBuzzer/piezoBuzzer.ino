//Buzzer am digitalen Pin D3 angeschlossen
#define buzzer 3

//Drehpotentiometer am analogen Pin A0 angeschlossen
#define rot A0

void setup() {
  //den Pin als Ausgang definieren
  pinMode(buzzer, OUTPUT);
  //beginn der seriellen Kommunikation mit 9600 baud
  Serial.begin(9600);
}

void loop() {
  //lesen des aktuellen, analogen Wertes vom Drehpotentiometer
  int value = analogRead(rot);  
  //Ausgeben des Wertes auf der seriellen Schnittstelle
  Serial.println(value);
  //einen Ton ausgeben.
  tone(buzzer, value);
}
