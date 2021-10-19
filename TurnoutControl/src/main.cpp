#include <Arduino.h>
#include <Servo.h> // zugriff auf Servo Bibliothek

const int taster = 12; // Pushbutton Pin auf dem Board (12)
int tasterstatus=0;
Servo servo; // deklariert den Namen des ersten Servos

//Funktion für Links-Abzweig
void Links(){
      for (int j = 170; j > 0; j--){
      servo.write(j);
      delay(20);
      }
}

//Funktion für Rechts-Abzweig
void Rechts(){
      for (int j = 0; j < 170; j++){
      servo.write(j);
      delay(20);
      }
}

void setup() {
  Serial.begin(9600);
  pinMode(taster, INPUT_PULLUP); // Gibt an dass Buttom ein Input ist - DAS IST GEÄNDERT
  servo.attach(13); // gibt an auf welchem Pin der Servo mit dem steuerkabel anliegt
  servo.write(0); // gibt die Grundstellung des Servo beim start an
}

//Definition state maschine
enum TextState { RECHTS, LINKS } nextTextState = RECHTS;

void loop(){
  tasterstatus=digitalRead(taster);
  if (tasterstatus == HIGH) {
    switch (nextTextState) {
      case RECHTS:
      Rechts();
      nextTextState = LINKS;
      break;
      case LINKS:
      Links();
      nextTextState = RECHTS;
      break;
    }
  }
}