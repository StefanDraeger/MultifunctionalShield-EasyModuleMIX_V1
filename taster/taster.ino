#include <Bounce2.h> //Bibliothek zum entprellen der Taster

//Die Taster sind am digitalen Pin D3..D6 angeschlossen
#define sw1 3
#define sw2 4
#define sw3 5
#define sw4 6

//Intervall zum entprellen auf 50ms
const int INTERVAL = 50;

//Initialisieren von Objekten für jeden Taster
Bounce b1 = Bounce(sw1, INTERVAL);
Bounce b2 = Bounce(sw2, INTERVAL);
Bounce b3 = Bounce(sw3, INTERVAL);
Bounce b4 = Bounce(sw4, INTERVAL);

void setup() {
  //beginn der seriellen Kommunikation mit 9600 baud
  Serial.begin(9600);

  //setzen das die digitalen Pins als Eingänge funktionieren
  pinMode(sw1, INPUT);
  pinMode(sw2, INPUT);
  pinMode(sw3, INPUT);
  pinMode(sw4, INPUT);
}

void loop() {
  //aktualisieren der Zustände
  b1.update();
  b2.update();
  b3.update();
  b4.update();

  //Wenn der Taster 1 gedrückt ist, dann...
  if(b1.fell()){
    msgFell(1);
  } else if(b1.rose()){ //Wenn der Taster 1 wieder losgelassen wird, dann...
    msgRose(1);
  } 

  if(b2.fell()){
    msgFell(2);
  }else if(b2.rose()){
    msgRose(2);
  } 
  
  if(b3.fell()){
    msgFell(3);
  }else if(b3.rose()){
    msgRose(3);
  }

  if(b4.fell()){
    msgFell(4);
  }else if(b4.rose()){
    msgRose(4);
  }
}

//Text auf der seriellen Schnittstell ausgeben. Das der Taster gedrückt ist.
void msgFell(int taster){
  Serial.print("Taster ");
  Serial.print(taster);
  Serial.println(" ist gedrückt!");
}

//Text auf der seriellen Schnittstell ausgeben. Das der Taster wieder losgelassen wurde.
void msgRose(int taster){
  Serial.print("Taster ");
  Serial.print(taster);
  Serial.println(" wurde wieder losgelassen!");
}
