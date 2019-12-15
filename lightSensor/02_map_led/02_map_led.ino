//Lichtsensor / Fotowiderstand am analogen Pin A0
#define lightSensor A0

//LEDs
#define led1 3
#define led2 4
#define led3 5
#define led4 6

int leds[] = {led1, led2, led3, led4};

void setup() {
  //beginn der seriellen Kommunikation
  Serial.begin(9600);
}

void loop() {
  resetLeds();
  //lesen des aktuellen, analogen Wertes des Lichtsensors
  int value = analogRead(lightSensor);
  //ausgeben des Wertes auf der seriellen Schnittstelle
  Serial.print("Wert des Lichtsensors: ");
  Serial.println(value);

  int led = map(value,300,820,0,3);
  digitalWrite(leds[led], HIGH);
  delay(125);
  Serial.print("aktive LED: ");
  Serial.println(led);
}

void resetLeds(){
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
}
