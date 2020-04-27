#include <Arduino.h>
int digitalPin = 8; // linear Hall digital interface
int digitalVal;     // digital readings

void setup ()
{
  pinMode(digitalPin, INPUT); 
  Serial.begin(9600);
}

void loop ()
{
  // Read the digital interface
  digitalVal = digitalRead(digitalPin);
  Serial.println(digitalVal); // print digital value
  delay(100);
}
