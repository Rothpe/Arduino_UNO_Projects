#include<Arduino.h>
#include <Servo.h> // Zugriff auf Servo Bibliothek

const int taster = 2; // Pushbutton Pin auf dem Board (2)
const int taster2 = 3;// Pushbutton Pin auf dem Board (3)
int tasterstatus=0;//Tasterstatus Taster
int taster2status=0;//Tasterstatus Taster2
Servo servo; // deklariert den Namen des ersten Servos
Servo servo2;// deklariert den Namen des zweiten Servos

//Funktion für Links-Abzweig Servo
void Servo_Links(){
  for (int j = 120; j > 80; j--){
    servo.write(j);
    delay(40);
  }
}

//Funktion für Rechts-Abzweig Servo
void Servo_Rechts(){
  for (int j = 80; j < 120; j++){
    servo.write(j);
    delay(40);
  }
}

//Funktion für Links-Abzweig Servo2
void Servo2_Links(){
  for (int j = 120; j > 80; j--){
    servo2.write(j);
    delay(40);
  }
}

//Funktion für Rechts-Abzweig Servo2
void Servo2_Rechts(){
  for (int j = 80; j < 120; j++){
    servo2.write(j);
    delay(40);
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(taster, INPUT_PULLUP); // Gibt an dass die Taster ein Input ist
  pinMode (taster2,INPUT_PULLUP);
  servo.attach(8); // gibt an auf welchem Pin die Servo mit dem Steuerkabel anliegen
  servo2.attach(9);
  servo.write(80); // gibt die Grundstellung der Servo beim Start an
  servo2.write(80);
}

//Definition state maschine
enum TasterState { RECHTS, LINKS } nextTasterState = RECHTS;
enum Taster1State { RECHTS2, LINKS2 } nextTaster1State = RECHTS2;

void loop(){

  //State machine Servo
  tasterstatus=digitalRead(taster);
  if (tasterstatus == HIGH) {
    switch (nextTasterState) {
      case RECHTS:
      Servo_Rechts();
      nextTasterState = LINKS;
      break;
      case LINKS:
      Servo_Links();
      nextTasterState = RECHTS;
      break;
    }
  }

  //State machine Servo2
  taster2status=digitalRead(taster2);
  if (taster2status == HIGH) {
    switch (nextTaster1State) {
      case RECHTS:
      Servo2_Rechts();
      nextTaster1State = LINKS2;
      break;
      case LINKS:
      Servo2_Links();
      nextTaster1State = RECHTS2;
      break;
    }
  }  
}
