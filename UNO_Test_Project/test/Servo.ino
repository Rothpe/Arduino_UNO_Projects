 #include <Arduino.h>
 #include <Servo.h>  

Servo servo; //Declaration for servo

void setup()

{
servo.attach(8); //Declaration servo to Pin 8 
servo.write(0); //first Startposoition 0°
} 

void loop() {

  delay(3000);//Start delay update value possible

  for (int i = 0; i < 90; i++) // run Pos 0° to Pos 90°
  {
    servo.write(i); //approach starting position
    delay(14); //servo speed update value possible
  }
  delay(3000); //delay time between each position change update value possible

  for (int i = 90; i < 180; i++) //run Pos 90° to Pos 180°
  {
    servo.write(i); //approach starting position
    delay(14); //servo speed update value possible
  }
  delay(3000); //delay time between each position change update value possible

  for (int i = 180; i > 90; i--) //run Pos 180° to Pos 90°
  {
    servo.write(i); //approach starting position
    delay(14); //servo speed update value possible
  }
  delay(3000); //delay time between each position change update value possible

  for (int i = 90; i > 0; i--) //run Pos 90° to Pos 0°
  {
    servo.write(i); //approach starting position
    delay(14); //servo speed update value possible
  }
  delay(3000); //delay time between each position change update value possible
}