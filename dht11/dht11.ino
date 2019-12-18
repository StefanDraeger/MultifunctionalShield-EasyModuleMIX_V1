#include "DHT.h" //einbinden der Adafruit Blibothek DHT11

//der Sensor ist am digitalen Pin D3 angeschlossen
#define DHTPIN 3 

//Die verwendete Bibliothek kann für den DHT11, DHT22 verwendet werden, daher
//muessen wir definieren welchen Sensor wir ansprechen möchten.
#define DHTTYPE DHT11

//initialisieren eines Objektes fuer das spaetere auslesen der Daten
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  //beginn der seriellen Kommunikation mit 9600 baud
  Serial.begin(9600);

  //beginn der Kommunikation mit dem Sensor
  dht.begin();

  //ausgeben eines Tabellenkopfes auf der seriellen Schnittstelle
  Serial.println("rel. Luftfeuchtigkeit\t\t|\tTemperatur");
}

void loop() {
  //eine kleine Pause von 2sek.
  //Der DHT11 Sensor liefert alle 1,5sek. einen neuen Messwert.
  delay(2000);

  //lesen der Daten
  float h = dht.readHumidity(); //relative Luftfeuchtigkeit
  float t = dht.readTemperature(); //Temperatur in Celsius
  float f = dht.readTemperature(true); //Temperatur in Fahrenheit

  //wenn eines der gelesenen Werte ungueltig ist dann...
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Fehler beim lesen der Daten vom DHT Sensor!");
    return;
  }

  //Ausgabe der Daten auf der seriellen Schnittstelle.
  Serial.print(h);
  Serial.print("%");
  Serial.print("\t\t\t\t|\t");
  Serial.print(t);
  Serial.print("°C");
  Serial.print(" | ");
  Serial.print(f);
  Serial.print("°F");
  Serial.println("");
}
