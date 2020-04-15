#include <Arduino.h>
#include <time.h>

int h,m,s;
int set_hours=20;
int set_minutes=49;
int set_seconds=45;

void setup() {
  Serial.begin(115200);
}

void loop(){
  for(h=set_hours;h<24;h++)   //Hours
  {
    for(m=set_minutes;m<60;m++)   //Minutes
    {
      for(s=set_seconds;s<60;s++)     //Seconds
      {
        Serial.println(h);
        delay(1000);
      }
      set_seconds=00;
    }
    set_minutes=00;
  }
  set_hours=00;
}
