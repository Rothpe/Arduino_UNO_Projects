 #include <Arduino.h>
 #include <Servo.h>  

Servo servo;

void setup()

{

servo.attach(8);
servo.write(90);

} 

void loop() {

  delay(20000);

  for (int i = 0; i < 90; i++)
  {
    servo.write(i);
    //delay(4);
  }
  delay(3000);


  for (int i = 90; i > 0; i--)
  {
    servo.write(i);
    //delay(4);
  }
  delay(3000);
  
}