#include <Wire.h>
#include "RTClib.h"
#include <LiquidCrystal_I2C.h>
#include <LCD.h>
#include <Arduino.h>

LiquidCrystal_I2C lcd(0x27, 2,  1,  0,  4,  5,  6,  7,  3, POSITIVE);  // .kbv constructor for I2C

RTC_DS3231 rtc; //start of RTC clock

char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
                            //array of weekdays

void setup () {

  lcd.begin(20, 4);  //start of LCD()

  Serial.begin(9600); //start serial

  delay(3000); // wait for console opening

  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (rtc.lostPower()) {
    Serial.println("RTC lost power, lets set the time!");
    // following line sets the RTC to the date & time this sketch was compiled
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    //rtc.adjust(DateTime(2020, 4, 18, 18, 10, 0));
  }
}

void loop () {
    
    DateTime now = rtc.now(); // call date and time
    
    lcd.clear();
    lcd.setCursor(5,0); // set cursor to line 1, cell 5
    lcd.print(daysOfTheWeek[now.dayOfTheWeek()]); //print week day
    
    lcd.setCursor(5,1); // set cursor to line 2, cell 5
    
       
     if (now.day()<10){lcd.print("0");} // if date is single digit, print leading 0, same for month
     lcd.print(now.day(), DEC); lcd.print("."); // print date with semikolon
 
    if (now.month()<10){lcd.print("0");}
    lcd.print(now.month(), DEC); lcd.print(".");
  
    lcd.print(now.year(), DEC);

    lcd.setCursor(6,2); // set cursor to line 3, cell 6
    if (now.hour()<10){lcd.print("0");} // if hour is single digit, print leading 0, same for minute and second
    lcd.print(now.hour(), DEC); lcd.print(":");
    
    if (now.minute()<10){lcd.print("0");}
    lcd.print(now.minute(), DEC); lcd.print(":");
    
    if (now.second()<10){lcd.print("0");}
    lcd.print(now.second(), DEC);

    delay(1000); // wait 1 sec
    
}