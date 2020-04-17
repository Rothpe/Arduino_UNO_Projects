#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3,POSITIVE);

void setup() {
  lcd.begin(20, 4);
  lcd.clear();

  /*lcd.setCursor(0,0);
  lcd.print("Test");
  lcd.setCursor(0,1);
  lcd.print("20x4 & FC-113!");*/
  

}

void loop() {
lcd.setCursor(0,0);
lcd.print("Oberstdorf");
delay(10000);
lcd.clear();
delay(1000);
lcd.print("Sonthofen");
delay(10000);
lcd.clear();
delay(1000);
lcd.print("Lindau");
delay(10000);
lcd.clear();
delay(1000);
}