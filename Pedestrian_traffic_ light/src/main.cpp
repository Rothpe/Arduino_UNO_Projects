#include <Arduino.h>
int ampelRotPin = 12;
int ampelGelbPin = 11;
int ampelGruenPin = 10;
int fgRotPin = 9;
int fgGruenPin = 8;

void setup() {
  pinMode(ampelRotPin, OUTPUT);
  pinMode(ampelGelbPin, OUTPUT);
  pinMode(ampelGruenPin, OUTPUT);
  pinMode(fgRotPin, OUTPUT);
  pinMode(fgGruenPin, OUTPUT);
}

void loop() {
  // gruen
  digitalWrite(ampelRotPin, LOW);
  digitalWrite(ampelGelbPin, LOW);
  digitalWrite(ampelGruenPin, HIGH);
  digitalWrite(fgRotPin, HIGH);
  digitalWrite(fgGruenPin, LOW);
  delay(10000);
  // gelb
  digitalWrite(ampelRotPin, LOW);
  digitalWrite(ampelGelbPin, HIGH);
  digitalWrite(ampelGruenPin, LOW);
  digitalWrite(fgRotPin, HIGH);
  digitalWrite(fgGruenPin, LOW);
  delay(2000);
  // rot
  digitalWrite(ampelRotPin, HIGH);
  digitalWrite(ampelGelbPin, LOW);
  digitalWrite(ampelGruenPin, LOW);
  digitalWrite(fgRotPin, LOW);
  digitalWrite(fgGruenPin, HIGH);
  delay(10000);
  // rot-gelb
  digitalWrite(ampelRotPin, HIGH);
  digitalWrite(ampelGelbPin, HIGH);
  digitalWrite(ampelGruenPin, LOW);
  digitalWrite(fgRotPin, HIGH);
  digitalWrite(fgGruenPin, LOW);
  delay(2000);
}