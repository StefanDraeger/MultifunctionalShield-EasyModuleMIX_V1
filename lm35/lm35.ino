//Temperatursensor LM35DZ am analogen Pin A0
#define lm35 A0

void setup() {
  //beginn der seriellen Kommunikation
  Serial.begin(9600);
}

void loop() {
  //lesen des aktuellen, analogen Wertes des Temperatursensors
  int value = analogRead(lm35);
  //umrechnen in ein Temperaturwert
  int temp = (125*value)>>8 ; 
  //Ausgeben der Temperatur auf der seriellen Schnittstelle
  Serial.print(temp) ;
  Serial.println("°C"); 
  //eine kleine Pause von 125ms
  delay(125);
}
