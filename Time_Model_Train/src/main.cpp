#include <Arduino.h>
#include <time.h>

int h,m,s;
int hours=23;
int minutes=58;
int seconds=00;

void setup() {
  Serial.begin(115200);
}

void loop(){
  for(h=hours;h<24;h++){   //Hours
     
    for(m=minutes;m<60;m++){   //Minutes
        
      for(s=seconds;s<60;s++){     //Seconds
      Serial.print(h);
      Serial.print(":");
      Serial.print(m);
      Serial.print(":");
      Serial.print(s);
      Serial.println();
      delay(100);
      }
      seconds = 00;
    }
    minutes = 00;    
  }
  hours = 00;  
}