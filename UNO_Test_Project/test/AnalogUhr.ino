#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
 
#define OLED_RESET 4
//Adafruit_SSD1306 display(OLED_RESET);
Adafruit_SSD1306 display(128, 64, &Wire, -1);
 
#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2
 
 
 
#define LOGO16_GLCD_HEIGHT 16
#define LOGO16_GLCD_WIDTH  16
static const unsigned char PROGMEM logo16_glcd_bmp[] =
{ B00000000, B11000000,
  B00000001, B11000000,
  B00000001, B11000000,
  B00000011, B11100000,
  B11110011, B11100000,
  B11111110, B11111000,
  B01111110, B11111111,
  B00110011, B10011111,
  B00011111, B11111100,
  B00001101, B01110000,
  B00011011, B10100000,
  B00111111, B11100000,
  B00111111, B11110000,
  B01111100, B11110000,
  B01110000, B01110000,
  B00000000, B00110000 };
 
void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.drawCircle(display.width()/2, display.height()/2, 15, WHITE);
  display.drawCircle(display.width()/2, display.height()/2, 1, WHITE);
  //
  //hour ticks
  for( int z=0; z < 360;z= z + 30 ){
  //Begin at 0° and stop at 360°
    float angle = z ;
    angle=(angle/57.29577951) ;
    int x2=(64+(sin(angle)*20));
    int y2=(32-(cos(angle)*20));
    int x3=(64+(sin(angle)*(20-5)));
    int y3=(32-(cos(angle)*(20-5)));
    display.drawLine(x2,y2,x3,y3,WHITE);
  }
  display.display();
  int minut = 40 ;
  int angle = minut * 6 ;
  angle=(angle/57.29577951) ;
  int x31=(64+(sin(angle)*(20-3)));
  int y31=(32-(cos(angle)*(20-3)));
  display.drawLine(64,32,x31,y31,WHITE);
  display.display();
 
  int stunde = 11;
  int angle2 = stunde * 30 + int((minut / 12) * 6 )   ;
  angle2=(angle2/57.29577951) ;  
  int x32=(64+(sin(angle2)*(20-11)));
  int y32=(32-(cos(angle2)*(20-11)));
  display.drawLine(64,32,x32,y32,WHITE);
  display.display();
}
void loop() {
  // put your main code here, to run repeatedly:
 
}