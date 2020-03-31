 #include <Arduino.h>
 #include <Servo.h>  

Servo servo;

void setup()

{

servo.attach(8);
servo.write(90); //hier wird Pos 90° angefahren

} 

void loop() {

  delay(20000);

  for (int i = 0; i < 90; i++) //hier fahren wir von 90° zu 0°
  {
    servo.write(i);
    delay(12);
  }
  delay(3000);


  for (int i = 90; i > 0; i--) //hier fahren wir wieder auf 90° zurück
  {
    servo.write(i);
    delay(12);
  }
  delay(3000);

  for (int i = 0; i < 180; i++) //hier fahren wir von 90° auf 270° --> 90° + 180°
  {
    servo.write(i);
    delay(12);
  }
  delay(3000);


  for (int i = 180; i > 0; i--) //hier fahren wir wieder auf 90° zurück --> 270° - 180°
  {
    servo.write(i);
    delay(12);
  }
  delay(3000);
  
}