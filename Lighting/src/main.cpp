#include <Arduino.h>

int _ABVAR_1_var = 0;

void setup()
{
  pinMode(2, INPUT);
  pinMode(4, INPUT);
  pinMode(4, OUTPUT);
  _ABVAR_1_var = 300;
}
void loop()
{
  //digitalWrite(4, HIGH);

  if ((digitalRead(2) && !(digitalRead(4))))
  {
    digitalWrite(4, LOW);
    delay(_ABVAR_1_var);
  }
  if ((digitalRead(2) && digitalRead(4)))
  {
    digitalWrite(4, HIGH);
    delay(_ABVAR_1_var);
  }
}