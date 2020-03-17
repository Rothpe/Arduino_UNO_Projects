 #include <Arduino.h>
 #include <Servo.h> //Die Servobibliothek wird aufgerufen. Sie wird benötigt, damit die Ansteuerung des Servos vereinfacht wird.
 

Servo servolinks;
Servo servorechts;

 

void setup()

{

servolinks.attach(8);
servorechts.attach(9);
servolinks.write(0);
servorechts.write(180);

}

 

void loop() {

  for (int i = 0; i < 90; i++)
  {
    servolinks.write(i);
    delay(8);
  }

  for (int j = 180; j > 90; j--)
  {
    servorechts.write(j);
    delay(8);
  }
  delay(3000);


  for (int i = 90; i > 0; i--)
  {
    servolinks.write(i);
    delay(8);
  }

  for (int j = 90; j < 180; j++)
  {
    servorechts.write(j);
    delay(8);
  }
  delay(3000);
  
  




/*servolinks.write(0); //Position 1 ansteuern mit dem Winkel 0°
servorechts.write(180);

delay(10000); //Das Programm stoppt für 3 Sekunden

servolinks.write(90); //Position 2 ansteuern mit dem Winkel 90°
servorechts.write(90);

delay(10000); //Das Programm stoppt für 3 Sekunden*/

}