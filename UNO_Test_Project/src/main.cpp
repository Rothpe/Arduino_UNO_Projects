#include <Arduino.h>

#define PIN_LED_1 10                         // Pin, an dem die LED angeschlossen ist.
#define PIN_LED_2 11
#define PIN_BUTTON_2 7
#define PIN_BUTTON_1 9                      // Pin, an dem der Taster angeschlossen ist.

boolean a1LedEnabled = false;                                        // True, wenn die LED leuchtet, sonst false.
boolean a1ButtonPressed = false;
boolean a2LedEnabled = false;                                        // True, wenn die LED leuchtet, sonst false.
boolean a2ButtonPressed = false;                                       // True, wenn der Taster gedrÃ¼ckt wird, sonst false.

void setup()
{
  pinMode(PIN_LED_1, OUTPUT);                                         // Pin, an dem die LED angeschlossen ist, als Ausgang festlegen.
  pinMode(PIN_LED_2, OUTPUT);
  pinMode(PIN_BUTTON_1, INPUT_PULLUP);
  pinMode(PIN_BUTTON_2, INPUT_PULLUP);                                // Pin, an dem der Taster angeschlossen ist, als Eingang mit aktiviertem Pull-Up-Widerstand festlegen.
}

void loop()
{
  if (digitalRead(PIN_BUTTON_1) == LOW) {                             // Wenn der Taster aktuell gedrÃ¼ckt wird, ...
    a1ButtonPressed = true;                                          // merke dir, dass der Taster gedrÃ¼ckt wurde, ...
    delay(10);                                                      // und warte 10 Millisekunden bis die Kontakte des Tasters vollstÃ¤ndig geschlossen sind.
  }

  if (digitalRead(PIN_BUTTON_1) == HIGH && a1ButtonPressed == true) {  // Wenn der Taster nicht gedrÃ¼ckt wird, aber zuvor gedrÃ¼ckt wurde ...
    a1ButtonPressed = false;                                         // vergesse, dass der Taster gedrÃ¼ckt wude.
    
    if (a1LedEnabled == true) {                                      // Wenn die LED gerade leuchtet ...
      digitalWrite(PIN_LED_1, LOW);                                   // schalte die LED aus ...
      a1LedEnabled = false;                                          // und merke dir, dass die LED gerade nicht leuchtet,
    } else {                                                        // sonst ...
      digitalWrite(PIN_LED_1, HIGH);                                  // schalte die LED ein ...
      a1LedEnabled = true;                                           // und merke dir, dass die LED gerade leuchtet.
    }
  }

  if (digitalRead(PIN_BUTTON_2) == LOW) {                             // Wenn der Taster aktuell gedrÃ¼ckt wird, ...
    a2ButtonPressed = true;                                          // merke dir, dass der Taster gedrÃ¼ckt wurde, ...
    delay(10);                                                      // und warte 10 Millisekunden bis die Kontakte des Tasters vollstÃ¤ndig geschlossen sind.
  }

  if (digitalRead(PIN_BUTTON_2) == HIGH && a2ButtonPressed == true) {  // Wenn der Taster nicht gedrÃ¼ckt wird, aber zuvor gedrÃ¼ckt wurde ...
    a2ButtonPressed = false;                                         // vergesse, dass der Taster gedrÃ¼ckt wude.
    
    if (a2LedEnabled == true) {                                      // Wenn die LED gerade leuchtet ...
      digitalWrite(PIN_LED_2, LOW);                                   // schalte die LED aus ...
      a2LedEnabled = false;                                          // und merke dir, dass die LED gerade nicht leuchtet,
    } else {                                                        // sonst ...
      digitalWrite(PIN_LED_2, HIGH);                                  // schalte die LED ein ...
      a2LedEnabled = true;                                           // und merke dir, dass die LED gerade leuchtet.
    }
  }
}