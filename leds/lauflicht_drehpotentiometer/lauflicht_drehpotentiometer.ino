//LEDs
#define led1 3
#define led2 4
#define led3 5
#define led4 6

//Drehpotentiometer am analogen Pin A0 angeschlossen
#define drehpoti A0

int leds[] = {led1, led2, led3, led4};

void setup() {
  //beginn der seriellen Kommunikation
  Serial.begin(9600);
}

void loop() {

  //Schleife über das Array mit den LEDs,
  //von der ersten bis zur letzten LED
  for(int i = 0;i<=3;i++){
    //aktivieren der LED
    digitalWrite(leds[i], HIGH);
    //lesen des aktuellen Wertes des Drehpotis und
    //verwenden als Pause
    delay(readDrehpoti());
    //deaktivieren der LED
    digitalWrite(leds[i], LOW);
    delay(readDrehpoti());
  }

   //Schleife über das Array mit den LEDs,
   //jedoch beginnen wir mit der vorletzen LED
   //da die letzte LED bereits in der Schleife zuvor geblinkt hat.
   for(int i = 2;i>=0;i--){
    digitalWrite(leds[i], HIGH);
    delay(readDrehpoti());
    digitalWrite(leds[i], LOW);
    delay(readDrehpoti());
  }
}

//Liefert den aktuellen Wert des Drehpotentiometers
int readDrehpoti(){
  return analogRead(drehpoti);
}
