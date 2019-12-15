#include <IRremote.h>

int irPin = 10; //Pin am Arduino Nano für die IR LED

IRrecv irrecv(irPin); //Objekt initialisieren für die IR Übertragung
decode_results results;

void setup() {
  pinMode(irPin, INPUT);  //Den IR Pin als Eingang deklarieren.
  irrecv.enableIRIn(); //Den IR Pin aktivieren
  Serial.begin(9600); //Serielle kommunikation mit 9600 Baud beginnen.
}
 
void loop(){
   if (irrecv.decode(&results)) { //Wenn etwas gelesen wurde dann...
      //Ausgabe des Wertes auf die Serielle Schnittstelle.
      int value = results.value;
      Serial.println(value, DEC);
      irrecv.resume(); // auf den nächsten Wert warten
 }
}
