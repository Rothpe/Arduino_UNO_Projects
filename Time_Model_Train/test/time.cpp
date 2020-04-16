#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SPI.h>

// OLED display TWI address
#define OLED_ADDR 0x3C

//define display size
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32

int h,m,s;

//set time for start
int hours=23; 
int minutes=58;
int seconds=00;

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
Serial.begin(115200);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

    // Settings for Display
    display.clearDisplay();
    display.display();
    display.setTextColor(WHITE);
    display.setTextSize(2);
}

void loop(){

  for(h=hours;h<24;h++){   //Hours

    for(m=minutes;m<60;m++){   //Minutes

      for(s=seconds;s<60;s++){     //Seconds
        display.setCursor(5 , 5);
        char timestring[6];     //timestring for formatted output to display
        sprintf(timestring, "%02d:%02d ", h, m);
        display.print(timestring);
        display.display();


      //only for checking in serial monitor
      /*Serial.print(h);
      Serial.print(":");
      Serial.print(m);
      Serial.print(":");
      Serial.print(s);
      Serial.println();*/

      delay(100); //delay for time lapse
      }
      display.clearDisplay(); //clear display after 60 sec
      display.display();
      seconds = 00;
    }
    minutes = 00;    
  }
  hours = 00;  
}