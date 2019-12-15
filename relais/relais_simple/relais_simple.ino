const int relaisPin = 8;
 
void setup() {
  pinMode(relaisPin, OUTPUT); // den Pin des Relais als Ausgang setzen
}
 
void loop() {
  digitalWrite(relaisPin, HIGH); //Relais aus
  delay(500);  //500ms warten
  digitalWrite(relaisPin, LOW);  //Relais an
  delay(500);// 500ms warten
}
