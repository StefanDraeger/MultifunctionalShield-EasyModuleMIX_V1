//LEDs
#define led1 3
#define led2 4
#define led3 5
#define led4 6

int leds[] = {led1, led2, led3, led4};

const int PAUSE = 50;

void setup() {
  //beginn der seriellen Kommunikation
  Serial.begin(9600);
}

void loop() {
  for(int i = 0;i<=3;i++){
    digitalWrite(leds[i], HIGH);
    delay(PAUSE);
    digitalWrite(leds[i], LOW);
    delay(PAUSE);
  }

   for(int i = 2;i>=0;i--){
    digitalWrite(leds[i], HIGH);
    delay(PAUSE);
    digitalWrite(leds[i], LOW);
    delay(PAUSE);
  }
}
