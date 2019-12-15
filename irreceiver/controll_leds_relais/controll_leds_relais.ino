#include <IRremote.h>

//LEDs
#define led1 3
#define led2 4 //Power On
#define led3 5
#define led4 6 //Power Off

//IR Receiver am digitalen Pin D10
#define irPin  10

//Relais am digitalen Pion D12 angeschlossen
#define relais 12

IRrecv irrecv(irPin); //Objekt initialisieren für die IR Übertragung
decode_results results;

//Variablen für das speichern der Status
boolean isPowerOn = true;
boolean relaisIsActive = true;
boolean led1IsActive = false;
boolean led3IsActive = false;

//Konstante für die Zeitberechnung 
const int timeGap = 1500;
long lastReceivedValueTime = -1;

long lastReceivedValue = -1;

void setup() {
  pinMode(irPin, INPUT);  //den digitalen Pin des IR Empfängers als Eingang deklarieren
  pinMode(relais, OUTPUT);  //den digitalen Pin des Relais als Eingang deklarieren

  irrecv.enableIRIn(); //Den IR Pin aktivieren
  Serial.begin(9600); //Serielle kommunikation mit 9600 Baud beginnen.

  //Initialiesieren
  //Das "Gerät" ist AUS
  togglePowerState();
}

void loop() {
  if (irrecv.decode(&results)) { //Wenn etwas gelesen wurde dann...
    //lesen des aktuellen Wertes 
    int value = results.value;
    //Ausgabe des Wertes auf die Serielle Schnittstelle.
    Serial.println(value, DEC);
    //lesen der aktuellen Millisekunde seid dem der Microcontroller gestartet wurde
    long currentTime = millis();
    //Wenn seid der letzten aktion mindestens "timeGap" Sekunden verstrichen sind, dann...
    if (lastReceivedValueTime < (currentTime - timeGap) || (lastReceivedValue != value)) {
      //ersetzen des Zeitstempels
      lastReceivedValueTime = currentTime;
      lastReceivedValue = value;
      switch (value) {
        case 1223: togglePowerState(); break; //Power On / Off
        case 1090: activateLed1(); break; //LED1 (blau), aktivieren / deaktivieren
        case 1068: toggleRelais(); break; //Relais, aktivieren / deaktivieren
        case 1116: activateLed3(); break; //LED3 (gelb), aktivieren / deaktivieren
      }
    }
    
    irrecv.resume(); // auf den nächsten Wert warten
  }
}

void activateLed1() {
  //Wenn aktiv dann...
  if (isPowerOn) {
    led1IsActive = !led1IsActive;
    toggleState(led1IsActive, led1);
  }
}

void activateLed3() {
  //Wenn aktiv dann...
  if (isPowerOn) {
    led3IsActive = !led3IsActive;
    toggleState(led3IsActive, led3);
  }
}

void toggleRelais() {
  //Wenn aktiv dann...
  if (isPowerOn) {
    relaisIsActive = !relaisIsActive;
    toggleState(relaisIsActive, relais);
  }
}

//Wechselt einen Status am digitalen Pin
//wenn der "state" TRUE ist dann wird der "pin" auf HIGH gesetzt
//wenn der "state" FALSE ist dann wird der "pin" auf LOW gesetzt
void toggleState(boolean state, int pin) {
  if (state) {
    digitalWrite(pin, HIGH);
  } else {
    digitalWrite(pin, LOW);
  }
}

void togglePowerState() {
  digitalWrite(led2, LOW);
  digitalWrite(led4, LOW);

  isPowerOn = !isPowerOn;
  if (isPowerOn) {
    digitalWrite(led2, HIGH);
  } else {
    digitalWrite(led4, HIGH);
    digitalWrite(led1, LOW);
    digitalWrite(relais, HIGH);

    relaisIsActive = false;
    relaisIsActive = false;
    led1IsActive = false;
    led3IsActive = false;
  }
}
