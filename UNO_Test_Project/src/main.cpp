#include <Arduino.h>
#include <Servo.h>  

Servo servo; //Declaration for servo

#define PIN_LED 10                         // Pin, an dem die LED angeschlossen ist.
#define PIN_BUTTON 9                      // Pin, an dem der Taster angeschlossen ist.

boolean aLedEnabled = false;                                        // True, wenn die LED leuchtet, sonst false.
boolean aButtonPressed = false;                                     // True, wenn der Taster gedrÃ¼ckt wird, sonst false.

void setup()
{
  Serial.begin(115200);
  pinMode(PIN_LED, OUTPUT);                                         // Pin, an dem die LED angeschlossen ist, als Ausgang festlegen.
  pinMode(PIN_BUTTON, INPUT_PULLUP);  // Pin, an dem der Taster angeschlossen ist, als Eingang mit aktiviertem Pull-Up-Widerstand festlegen.           
  servo.attach(8); //Declaration servo to Pin 8 
  servo.write(0); //first Startposoition 0° 
  int value = servo.read();
  Serial.println(value);                            
}

void loop()
{
  /*if (digitalRead(PIN_BUTTON) == LOW) {                             // Wenn der Taster aktuell gedrÃ¼ckt wird, ...
    aButtonPressed = true;                                          // merke dir, dass der Taster gedrÃ¼ckt wurde, ...
    delay(10);                                                      // und warte 10 Millisekunden bis die Kontakte des Tasters vollstÃ¤ndig geschlossen sind.
  }

  if (digitalRead(PIN_BUTTON) == HIGH && aButtonPressed == true) {  // Wenn der Taster nicht gedrÃ¼ckt wird, aber zuvor gedrÃ¼ckt wurde ...
    aButtonPressed = false;                                         // vergesse, dass der Taster gedrÃ¼ckt wude.
    
    if (aLedEnabled == true) {                                      // Wenn die LED gerade leuchtet ...
      digitalWrite(PIN_LED, LOW);                                   // schalte die LED aus ...
      aLedEnabled = false;                                          // und merke dir, dass die LED gerade nicht leuchtet,
    } else {                                                        // sonst ...
      digitalWrite(PIN_LED, HIGH);                                  // schalte die LED ein ...
      aLedEnabled = true;                                           // und merke dir, dass die LED gerade leuchtet.
    }
  }*/
  delay(3000);//Start delay update value possible

  int value;
  
  for (int i = 0; i < 90; i++) // run Pos 0° to Pos 90°
  {
    servo.write(i); //approach starting position
    value = servo.read();
    Serial.println(value); 
    delay(14); //servo speed update value possible
  }
  delay(3000); //delay time between each position change update value possible

  for (int i = 90; i < 180; i++) //run Pos 90° to Pos 180°
  {
    servo.write(i); //approach starting position
    value = servo.read();
    Serial.println(value); 
    delay(14); //servo speed update value possible
  }
  delay(3000); //delay time between each position change update value possible

  for (int i = 180; i > 90; i--) //run Pos 180° to Pos 90°
  {
    servo.write(i); //approach starting position
    value = servo.read();
    Serial.println(value); 
    delay(14); //servo speed update value possible
  }
  delay(3000); //delay time between each position change update value possible

  for (int i = 90; i > 0; i--) //run Pos 90° to Pos 0°
  {
    servo.write(i); //approach starting position
    value = servo.read();
    Serial.println(value); 
    delay(14); //servo speed update value possible
  }

  delay(3000); //delay time between each position change update value possible



}