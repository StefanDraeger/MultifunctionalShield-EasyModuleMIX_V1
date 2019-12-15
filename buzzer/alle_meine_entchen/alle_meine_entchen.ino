int buzzer=12;

#define a  1136 //Note a
#define c  1915 //Note c
#define d  1700 //Note d
#define e  1519 //Note e
#define f  1432 //Note f
#define g  1275 //Note g

//Die Noten
int notes[] = {c, d, e, f, g, g,-1, a, a, a, a, g,-1, a, a, a, a, g,-1, f, f, f, f, e, e,-1, d, d, d, d, c};
//Die länge der Note
int beat[] =  {2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 2};
int tempo = 200; //Das Tempo des Liedes

//Anzahl der Noten
//hier kann man auch die Länge des Arrays mit der Funktion sizeOf() ermitteln
//aber für dieses Beispiel mit einer festen Länge ist das einfacher.
const int numberOfNotes = 31;

void setup() {
  Serial.begin(9600); //Begin der seriellen Kommunikation mit 9600 Baud
  pinMode(buzzer, OUTPUT); //Setzen des Buzzers als Ausgangssignal
}

void loop() {
  //Für jede Note im Array 
  for(int i=0; i<numberOfNotes; i++){
    int value = notes[i]; //Holen der Note aus dem Array an der Position i
    // den Takt * das Tempo
    int b = beat[i]* tempo;
    //Wenn die Note den Wert -1 hat dann
    //eine Pause einlegen
    if (notes[i] == -1) {
      delay(b);
    } else {
      //Wenn die Note nicht den Wert -1 hat
      //dann die Note wiedergeben
      playTone(value, b);  
    }
    //Eine kleine Pause zwischen den Noten.
    delay(tempo / 2); 
  }
 //Nachdem das Lied abgespielt wurde eine Pause von 5 sek. einlegen.
  delay(5000);
}

//Funktion zum abspielen einer Frequenz.
//Erwartet eine Freuqenz (tone) und eine Dauer (duration)
void playTone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(buzzer, HIGH);
    delayMicroseconds(tone);
    digitalWrite(buzzer, LOW);
    delayMicroseconds(tone);
  }
}
