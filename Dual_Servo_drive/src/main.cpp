 #include <Arduino.h>
 #include <Servo.h>  

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
  
}