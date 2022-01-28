// OLED Model railway Station Platform Display - Rudy B, August 2019
// 6 different messages can be shown, based on 6 inputs
// OLED SSD1306 - I2C wires: SDA or A4, SCL or A5

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_I2CDevice.h>

//#define TMIN       5 // departure time of next train, minimum of random time
//#define TMAX      13 // departure time of next train, maximum of random time

// setup oled
Adafruit_SSD1306 oled(4);

byte hour, minute, second; 
byte bg, fg, msgnr, msgnr_old, msgflag, msghour, msgminute;

unsigned long time_to_update;
float angle;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  oled.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C
}

void loop() {

// update time
  if(millis() > time_to_update) {
    time_to_update = millis() + 1000UL;
    second = second + 1;
    if(second == 60) {
      second = 0;
      minute = minute + 1;
    }
    if (minute == 60) {
      minute = 0;
      hour = (hour + 1) % 24;
    }
  }

// clear oled  
  oled.clearDisplay();
  oled.fillRect(0,0,127,31,BLACK);

// draw clock ticks
  for(int z=0; z<360;z=z+30){
    angle = (float)z / 57.3;
    int x1=(16+(sin(angle)*15));
    int y1=(15-(cos(angle)*15));
    int x2=(16+(sin(angle)*(12)));
    int y2=(15-(cos(angle)*(12)));
    oled.drawLine(x1,y1,x2,y2,WHITE);
    
  }
// draw clock second
  angle=((float)second * 6 / 57.3) ; //Convert degrees to radians  
  int x2=(16+(sin(angle)*(14)));
  int y2=(15-(cos(angle)*(14)));
  oled.drawLine(16,15,x2,y2,WHITE);
  

// draw clock minute
  angle=((float)minute * 6 / 57.3) ; //Convert degrees to radians  
  x2=(16+(sin(angle)*(12)));
  y2=(15-(cos(angle)*(12)));
  oled.drawLine(16,15,x2,y2,WHITE);
  

// draw clock hour
  angle=((float)hour * 30 + (float)minute / 2) / 57.3 ; //Convert degrees to radians  
  x2=(16+(sin(angle)*(10)));
  y2=(15-(cos(angle)*(10)));
  oled.drawLine(16,15,x2,y2,WHITE);
  


// refresh screen
  oled.display();
}