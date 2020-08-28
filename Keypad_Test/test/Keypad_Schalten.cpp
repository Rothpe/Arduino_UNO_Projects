#include <Keypad.h>
#include <Servo.h>
char P1 = '1';
char P2 = '2';
char P3 = '3';
char P4 = 'A';       // Hier werden die vier Zeichen des Passwortes eingegeben Hier: "123A"
char C1, C2, C3, C4; // Unter C1 bis C4 werden im Loop die vier eingegebenen Zeichen gespeichert

Servo servoblau;    //Servo wird ab jetzt mit „servoblau“ angesprochen
int roteLED = 12;   //Die rote LED ist an Pin 12 angeschlossen
int grueneLED = 13; //Die grüne LED wird an Pin 13 angeschlossen
//Hier wird die größe des Keypads definiert
const byte COLS = 4;    //4 Spalten
const byte ROWS = 4;    //4 Zeilen
int z1 = 0, z2, z3, z4; // Diese Variablen werden verwendet um für die einzelnen Zahlencodes die EIngabe freizuschalten. Damit wird im Sketch verhindert, dass eine einzene Codeziffer einer falschen Position zugeordnet wird.
//Die Ziffern und Zeichen des Keypads werden eingegeben:
char hexaKeys[ROWS][COLS] = {
    {'D', '#', '0', '*'},
    {'C', '9', '8', '7'},
    {'B', '6', '5', '4'},
    {'A', '3', '2', '1'}};

byte colPins[COLS] = {2, 3, 4, 5};                                              //Definition der Pins für die 3 Spalten
byte rowPins[ROWS] = {6, 7, 8, 9};                                              //Definition der Pins für die 4 Zeilen
char Taste;                                                                     //Taste ist die Variable für die jeweils gedrückte Taste.
Keypad Tastenfeld = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); //Das Keypad kann absofort mit "Tastenfeld" angesprochen werden

void setup()
{
    Serial.begin(9600);
    pinMode(roteLED, OUTPUT); //Die LEDs werden als Ausgang festgelegt
    pinMode(grueneLED, OUTPUT);
    servoblau.attach(11); //Der Servo ist an Pin 11 angeschlossen
}

void loop()
{
Anfang:                          // Dies ist eine Markierung, zu der per "goto-"Befehl gesprungen werden kann.
    Taste = Tastenfeld.getKey(); //Mit Unter der Variablen pressedKey entspricht der gedrückten Taste
    if (Taste)                   //Wenn eine Taste gedrückt wurde...
                                 //Ab hier werden die Eingaben des Tastenfeldes verarbeitet. Zunächst die "*"Taste, da diese eine Sonderfunktion für die Verriegelung besitzt und danach die #-Taste, nach deren Eingabe der zuvor eingegebene Code auf Richtigkeit geprüft wird.
    {
        if (Taste == '*') // Wenn die "*" Taste gedrückt wurde...
        {
            Serial.println("Tuer verriegelt");
            delay(3000);
            servoblau.write(90);          //Servo zum verriegeln auf 90 Grad ansteuern.
            digitalWrite(roteLED, HIGH);  //..die rote LED einschalten
            digitalWrite(grueneLED, LOW); //..die grüne LED einschalten
            z1 = 0;
            z2 = 1;
            z3 = 1;
            z4 = 1;      // Zugang zur ersten Zeicheneingabe freischalten
            goto Anfang; //An dieser Stelle springt der Sketch zur Eingabe der Taste zurück, damit das Zeichen "*" nicht im folgenden Abschlitt als Codeeingabe gewertet wird.
        }

        if (Taste == '#') // Wenn die Rautetaste gedrückt wurde...
        {
            if (C1 == P1 && C2 == P2 && C3 == P3 && C4 == P4) //wird gepüft, ob die eingaben Codezeichen (C1 bis C4) mit den Zeichen des Passwortes (P1 bis P4) übereinstimmen. Falls der eingegebene Code richtig ist...
            {
                Serial.println("Code korrekt, Schloss offen");
                servoblau.write(0);            //Servo zum öffnen auf 0 Grad ansteuern.
                digitalWrite(roteLED, LOW);    //..die rote LED nicht leuchten..
                digitalWrite(grueneLED, HIGH); //..die grüne LED leuchten..
            }
            else // ist das nicht der Fall, bleibt das Schloss gesperrt
            {
                Serial.println("Code falsch, Schloss gesperrt");
                digitalWrite(roteLED, HIGH);  // Die rote LED leuchtet
                digitalWrite(grueneLED, LOW); // Die grüne LED is aus
                delay(3000);
                z1 = 0;
                z2 = 1;
                z3 = 1;
                z4 = 1;      // Der Zugang für die erste Zeicheneingabe wird wieder freigeschaltet
                goto Anfang; //An dieser Stelle springt der Sketch zur Eingabe der Taste zurück, damit das Zeichen "#" nicht im folgenden Abschlitt als Codeeingabe gewertet wird.
            }
        }
        // Ab hier werden die vier Code-positionen unter den Variablen C1 bis C4 abgespeichert. Damit die eingegebenen Zeichen auch an der richtigen Position des Passwortes gespeichert werden, wird mit den Variablen z1 bis z4 der Zugang zu den einzelnen Positinen freigegeben oder gesperrt.
        if (z1 == 0) // Wenn das erste Zeichen noch nicht gespeichert wurde...
        {
            C1 = Taste;                 //Unter der Variablen "C1" wird nun die aktuell gedrückte Taste gespeichert
            Serial.print("Die Taste "); //Teile uns am Serial Monitor die gedrückte Taste mit
            Serial.print(C1);
            Serial.println(" wurde gedrueckt");
            z1 = 1;
            z2 = 0;
            z3 = 1;
            z4 = 1; // Zugang zur zweiten Zeicheneingabe freischalten
            goto Anfang;
        }

        if (z2 == 0) // Wenn das zweite Zeichen noch nicht gespeichert wurde...
        {
            C2 = Taste;                 //Unter der Variablen "C2" wird nun die aktuell gedrückte Taste gespeichert
            Serial.print("Die Taste "); //Teile uns am Serial Monitor die gedrückte Taste mit
            Serial.print(C2);
            Serial.println(" wurde gedrueckt");
            z1 = 1;
            z2 = 1;
            z3 = 0;
            z4 = 1; // Zugang zur dritten Zeicheneingabe freischalten
            goto Anfang;
        }

        if (z3 == 0) // Wenn das dritte Zeichen noch nicht gespeichert wurde...
        {
            C3 = Taste;                 //Unter der Variablen "C3" wird nun die aktuell gedrückte Taste gespeichert
            Serial.print("Die Taste "); //Teile uns am Serial Monitor die gedrückte Taste mit
            Serial.print(C3);
            Serial.println(" wurde gedrueckt");
            z1 = 1;
            z2 = 1;
            z3 = 1;
            z4 = 0; // Zugang zur vierten Zeicheneingabe freischalten
            goto Anfang;
        }

        if (z4 == 0) // Wenn das vierte Zeichen noch nicht gespeichert wurde...
        {
            C4 = Taste;                 //Unter der Variablen "C4" wird nun die aktuell gedrückte Taste gespeichert
            Serial.print("Die Taste "); //Teile uns am Serial Monitor die gedrückte Taste mit
            Serial.print(C4);
            Serial.println(" wurde gedrueckt");
            z1 = 1;
            z2 = 1;
            z3 = 1;
            z4 = 1; // Zugang zur weiteren Zeicheneingabe sperren
        }
    }
}