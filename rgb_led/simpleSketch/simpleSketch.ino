//Pin für die rote Farbe der LED am digitalen PWM Pin D3 angeschlossen
#define led_r 3 
//Pin für die grüne Farbe der LED am digitalen PWM Pin D5 angeschlossen
#define led_g 5
//Pin für die blaue Farbe der LED am digitalen PWM Pin D9 angeschlossen
#define led_b 9

void setup() {
  //setzen der Pins als Ausgänge
  pinMode(led_r, OUTPUT);
  pinMode(led_g, OUTPUT);
  pinMode(led_b, OUTPUT);
}

void loop() {
  //schreiben der RGB Werte auf die einzelnen Ausgänge
  analogWrite(led_r, 125);
  analogWrite(led_g, 25);
  analogWrite(led_b, 95);
}
