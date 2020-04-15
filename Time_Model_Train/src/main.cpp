#include <Arduino.h>
#include <time.h>

int h,m,s;
int hours=17;
int minutes=00;
int seconds=00;

void setup() {
  Serial.begin(115200);
}

void loop(){
  for(h=hours;h<24;h++)   //Hours
  {
    for(m=minutes;m<60;m++)   //Minutes
    {
      for(s=seconds;s<60;s++)     //Seconds
      {
        Serial.println(h);
        delay(1000);
      }

    }
    
  }
  
}
