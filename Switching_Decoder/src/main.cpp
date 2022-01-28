#include<Arduino.h>
#include <Servo.h> // Zugriff auf Servo Bibliothek

const int taster1 = 0; // Pushbutton Pin auf dem Board (2)
const int taster2 = 1; // Pushbutton Pin auf dem Board (2)

//int tasterstatus1=0;//Tasterstatus Taster
//int tasterstatus2=0;//Tasterstatus Taster

Servo servo1; // deklariert den Namen des ersten Servos

//Funktion für Links-Abzweig Servo
void Servo_Links(){
  for (int j = 120; j > 80; j--){
    servo1.write(j);
    delay(40);
  }
}

//Funktion für Rechts-Abzweig Servo
void Servo_Rechts(){
  for (int j = 80; j < 120; j++){
    servo1.write(j);
    delay(40);
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(taster1, INPUT_PULLUP); // Gibt an dass die Taster ein Input ist
  pinMode(taster2, INPUT_PULLUP); // Gibt an dass die Taster ein Input ist
  servo1.attach(8); // gibt an auf welchem Pin die Servo mit dem Steuerkabel anliegen
  servo1.write(80); // gibt die Grundstellung der Servo beim Start an
}

void loop(){
  if (digitalRead(taster1) == HIGH){
  Servo_Links();
  }

  if (digitalRead(taster2) == HIGH){
    Servo_Rechts();
  }
}
