#include <Bounce2.h>

//Relais am digitalen Pin D8 angeschlossen
const int relaisPin = 8;

//Taster am digitalen Pin D3 angeschlossen
const int btnPin = 3;

//Variable zum speichern des Status des Relais
boolean relaisIsActive = false;

//"Hilfs" Object damit der Taster entprellt wird
//Parameter
//der Pin an welchem der Taster angeschlossen ist
//eine Zeit in Millisekunden
Bounce btnBounce = Bounce(btnPin, 50);

void setup() {
  pinMode(relaisPin, OUTPUT); // den Pin des Relais als Ausgang setzen
  pinMode(btnPin, INPUT); // den Pin des Relais als Ausgang setzen
}

void loop() {
  //aktualisieren des Objectes
  btnBounce.update();
  //Wenn der Taster gedrückt wird dann...
  if (btnBounce.fell()) {
    //negieren des Status
    relaisIsActive = !relaisIsActive;
    //Wenn das Relais deaktiviert ist dann...
    if (relaisIsActive) {
      digitalWrite(relaisPin, LOW);
    } else {
      digitalWrite(relaisPin, HIGH);
    }
    //eine kleine Pause von 250ms.
    delay(250);
  }
}
