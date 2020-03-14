#include <Arduino.h>
int trafficRedPin = 12; //Car red
int trafficYellowPin = 11; //Car Yellow
int trafficGreenPin = 10; //Car reen
int PedRedPin = 9; //Pedestrian red
int PedGreenPin = 8; //Pedestrian green

void setup() {
  pinMode(trafficRedPin, OUTPUT);
  pinMode(trafficYellowPin, OUTPUT);
  pinMode(trafficGreenPin, OUTPUT);
  pinMode(PedRedPin, OUTPUT);
  pinMode(PedGreenPin, OUTPUT);
}

void loop() {
  // Car green
  digitalWrite(trafficRedPin, LOW);
  digitalWrite(trafficYellowPin, LOW);
  digitalWrite(trafficGreenPin, HIGH);
  digitalWrite(PedRedPin, HIGH);
  digitalWrite(PedGreenPin, LOW);
  delay(30000);

  //Pedestrian  red
  digitalWrite(PedRedPin, HIGH);
  digitalWrite(PedGreenPin, LOW);
  delay(3000);
  // Car yellow
  digitalWrite(trafficRedPin, LOW);
  digitalWrite(trafficYellowPin, HIGH);
  digitalWrite(trafficGreenPin, LOW);
  delay(3000);
  // Car red
  digitalWrite(trafficRedPin, HIGH);
  digitalWrite(trafficYellowPin, LOW);
  digitalWrite(trafficGreenPin, LOW);
  delay(3000);
  //Pedestrian green
  digitalWrite(PedRedPin, LOW);
  digitalWrite(PedGreenPin, HIGH);
  delay(30000);
  //Pedestrian red
  digitalWrite(PedRedPin, HIGH);
  digitalWrite(PedGreenPin, LOW);
  delay(3000);
  // Car red - yellow
  digitalWrite(trafficRedPin, HIGH);
  digitalWrite(trafficYellowPin, HIGH);
  digitalWrite(trafficGreenPin, LOW);
  delay(2000);

}