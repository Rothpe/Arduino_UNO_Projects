#include<Arduino.h>
#include <Servo.h> // Zugriff auf Servo Bibliothek
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

const int taster = 2; // Pushbutton Pin auf dem Board (2)
const int taster2 = 3;// Pushbutton Pin auf dem Board (3)
int tasterstatus=0;//Tasterstatus Taster
int taster2status=0;//Tasterstatus Taster2
Servo servo; // deklariert den Namen des ersten Servos
Servo servo2;// deklariert den Namen des zweiten Servos

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

//Display Grundeinstellung
void Display_Start(){
  lcd.backlight();
}

//Funktion für Links-Abzweig Servo
void Servo_Links(){
  for (int j = 120; j > 80; j--){
    servo.write(j);
    delay(40);
  }
  Display_Start();
  lcd.setCursor(0,0);
  lcd.print("                    ");     // Überschreiben mit "nichts" :)
  lcd.setCursor(0,0);
  lcd.print("Servo steht links");
}

//Funktion für Rechts-Abzweig Servo
void Servo_Rechts(){
  for (int j = 80; j < 120; j++){
    servo.write(j);
    delay(40);
  }
  Display_Start();
  lcd.setCursor(0,0);
  lcd.print("                    ");     // Überschreiben mit "nichts" :)
  lcd.setCursor(0,0);
  lcd.print("Servo steht rechts");
}

//Funktion für Links-Abzweig Servo2
void Servo2_Links(){
  for (int j = 120; j > 80; j--){
    servo2.write(j);
    delay(40);
  }
  Display_Start();
  lcd.setCursor(0,1);
  lcd.print("                    ");     // Überschreiben mit "nichts" :)
  lcd.setCursor(0,1);
  lcd.print("Servo2 steht links");
}

//Funktion für Rechts-Abzweig Servo2
void Servo2_Rechts(){
  for (int j = 80; j < 120; j++){
    servo2.write(j);
    delay(40);
  }
  Display_Start();
  lcd.setCursor(0,1);
  lcd.print("                    ");     // Überschreiben mit "nichts" :)
  lcd.setCursor(0,1);
  lcd.print("Servo2 steht rechts");
}

void setup() {
  Serial.begin(9600);
  lcd.init();                      // initialize the lcd 
  pinMode(taster, INPUT_PULLUP); // Gibt an dass die Taster ein Input ist
  pinMode (taster2,INPUT_PULLUP);
  servo.attach(8); // gibt an auf welchem Pin die Servo mit dem Steuerkabel anliegen
  servo2.attach(9);
  servo.write(80); // gibt die Grundstellung der Servo beim Start an
  servo2.write(80);
}

//Definition state maschine
enum TasterState { RECHTS, LINKS } nextTasterState = RECHTS;
enum TasterState2 { RECHTS2, LINKS2 } nextTasterState2 = RECHTS2;

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
    switch (nextTasterState2) {
      case RECHTS2:
      Servo2_Rechts();
      nextTasterState2 = LINKS2;
      break;
      case LINKS2:
      Servo2_Links();
      nextTasterState2 = RECHTS2;
      break;
    }
  }  
}
