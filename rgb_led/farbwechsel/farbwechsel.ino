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
  //Eine Schleife von 0 bis 255 in 5er Schritten
  for (int r = 0; r <= 255; r= r+5) {
    //setzen der Farbe "rot"
    analogWrite(led_r, r);
    for (int g = 0; g <= 255; g= g+5) {
      //setzen der Farbe "grün"
      analogWrite(led_g, g);
      for (int b = 0; b <= 255; b=b+5) {
        //setzen der Farbe "blau"
        analogWrite(led_b, b);
        delay(15); //eine kleine Pause von 15ms.
      }
    }
  }
}
