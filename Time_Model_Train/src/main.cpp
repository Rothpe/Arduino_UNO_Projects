#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SPI.h>
#include <Wire.h>

// OLED display TWI address
#define OLED_ADDR 0x3C

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32

int h,m,s;
int hours=23;
int minutes=58;
int seconds=00;

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Serial.begin(115200);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

    display.clearDisplay();
    display.display();
    display.setTextColor(WHITE);
    display.setCursor(0, 5);
}

void loop(){
  for(h=hours;h<24;h++){   //Hours
     
    for(m=minutes;m<60;m++){   //Minutes
        
      for(s=seconds;s<60;s++){     //Seconds
      /*Serial.print(h);
      Serial.print(":");
      Serial.print(m);
      Serial.print(":");
      Serial.print(s);
      Serial.println();*/
      display.printf("%02d:%02:%02d", h, m, s);
      
      }
      delay(100);
      seconds = 00;
    }
    minutes = 00;    
  }
  hours = 00;  
}