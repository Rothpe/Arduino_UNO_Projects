 #include <Arduino.h>
 #include <Servo.h>  

Servo servo_left;
Servo servo_right; 

void setup()

{

servo_left.attach(8);
servo_right.attach(9);
servo_left.write(0);
servo_right.write(180);

} 

void loop() {

  for (int i = 0; i < 90; i++)
  {
    servo_left.write(i);
    delay(4);
  }

  for (int j = 180; j > 90; j--)
  {
    servo_right.write(j);
    delay(4);
  }
  delay(3000);


  for (int i = 90; i > 0; i--)
  {
    servo_left.write(i);
    delay(4);
  }

  for (int j = 90; j < 180; j++)
  {
    servo_right.write(j);
    delay(4);
  }
  delay(3000);
  
}