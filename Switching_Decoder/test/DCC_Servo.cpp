//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Arduino DCC Servo and Function Decoder.
// Author: Author: Ruud Boer - January 2015
// This sketch turns an Arduino into a DCC decoder with max 12 servo motor outputs combined with function outputs.
// The DCC signal is optically separated and fed to pin 2 (=Interrupt 0). Schematics: www.mynabay.com
// Many thanks to www.mynabay.com for publishing their DCC monitor and -decoder code, which is used in this sketch.
//
// Important Change:
// This sketch from Ruud Boer was changed by lordbrummi in April 2016
// Now you can connect a PWM Arduino Servo Shield with 16 possible servos and adress them with DCC adresses
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// IMPORTANT: GOTO lines 22, 49, 72 to configure some data!
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// https://www.youtube.com/watch?v=Y1ShXjbzcmo
// https://www.youtube.com/watch?v=j7EbenPWuU4
// https://forum.opendcc.de/viewtopic.php?f=71&p=38354#p38354

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#include <DCC_Decoder.h>
#include <Servo.h> 
#define kDCC_INTERRUPT 0

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Fill in these 1 value ...
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const byte maxservos = 2; //The number of servos you have connected to this Arduino                    IMPORTANT!!!!!
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const byte servotimer = 40; 

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Set the Servomin and the Servomax of your servo between the gear range possibility                  IMPORTANT!!!!!
const int SERVOMIN = 150; // this is the 'minimum' pulse length count (out of 4096) 
const int SERVOMAX = 600; // this is the 'maximum' pulse length count (out of 4096)
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

unsigned long timetoupdatesetpoint = millis() + servotimer;



struct DCCAccessoryAddress {
  int address; // DCC address to respond to
  byte output; // State of accessory: 1=on, 0=off (for internal use only)
  int outputPin; // Arduino output pin
};
DCCAccessoryAddress accessory[maxservos];

struct servoItem {
  int angle;
  int setpoint;
  int offangle;
  int onangle;
  byte inverted;
  int servo;
  byte functionnumber;
 };
servoItem servos[maxservos];

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Fill in the address and pin for every accessory / function. Servos are 'coupled' to accessory[n] in line 72 and further.           IMPORTANT!!!!!
// COPY - PASTE as many times as you have functions. The amount must be same as in line 22 above!
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ConfigureDecoderFunctions() 
{
  accessory[0].address = 1;     // DCC address for this accessory
  accessory[0].outputPin = 13;  // Arduino pin where accessoryis connected to

  accessory[1].address = 2;     // DCC address for this accessory
  accessory[1].outputPin = 13;  // Arduino pin where accessory is connected to

  
  // Setup output pins for accessories
  for(int i=0; i<maxservos; i++)
  {
    if( accessory[i].outputPin )
		{
      pinMode (accessory[i].outputPin, OUTPUT );
      digitalWrite (accessory[i].outputPin, LOW);
    }
  }
} // END ConfigureDecoderFunctions


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Fill in the attributes for every servo
// COPY - PASTE as many times as you have servo's. The amount must be same as maxservos in line 22 above!
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ConfigureDecoderServos()
{
  servos[0].angle=90;          //initial angle of servo. Make this the same as offangle to avoid startup jitter.
  servos[0].offangle=40;       //minimum angle. Do not use value too close to 0, servo may stutter at the extremes.
  servos[0].onangle=80;        //maximum angle. Do not use value too close to 180, servo may stutter at the extremes.
  servos[0].servo=0;           //Arduino pin number where servo is connected to
  servos[0].functionnumber=0;  // CONNECTION BETWEEN FUNCTION AND SERVO ()accessory[functionnumber] - see above)

  servos[1].angle=90;
  servos[1].offangle=120;
  servos[1].onangle=160;
  servos[1].servo=1;
  servos[1].functionnumber=1;
 

  // A servo is coupled to an accessory[n]. It rotates based on accessory[n].output = 1 or 0
  // If you have multiple servos you need to couple them to different accessories. However ...
  // accessories may switch the same output pin (e.g. pin 13, which has the on board led attached)
	
} // END ConfigureDecoderServos

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// DCC packet handler 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void BasicAccDecoderPacket_Handler(int address, boolean activate, byte data)
{
  // Convert NMRA packet address format to human address
  address -= 1;
  address *= 4;
  address += 1;
  address += (data & 0x06) >> 1;

  boolean enable = (data & 0x01) ? 1 : 0;
  
  for(int i=0; i<maxservos; i++)
  {
    if(address == accessory[i].address)
		{
      if(enable) accessory[i].output = 1;
      else accessory[i].output = 0;
     
    }
  }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Setup (run once)
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void setup() 
{ 
  DCC.SetBasicAccessoryDecoderPacketHandler(BasicAccDecoderPacket_Handler, true);
  ConfigureDecoderFunctions();
  ConfigureDecoderServos();
  DCC.SetupDecoder( 0x00, 0x00, kDCC_INTERRUPT );
  pinMode(2,INPUT_PULLUP); //Interrupt 0 with internal pull up resistor (can get rid of external 10k)
  //pinMode(A5,INPUT_PULLUP); //If made LOW, all servos go to their min angle, to avoid jitter at starup.      - Not to use with PWM Servoshield because it uses already pinMode A5
  pinMode(13,OUTPUT);
  digitalWrite(13,LOW); //switch off Arduino led at startup
  
  for (int n=0; n<maxservos; n++) 
     {
        pinMode(accessory[n].outputPin,OUTPUT); //Set accessory pins to OUTPUT mode
         servos[n].onangle=map(servos[n].onangle,0,180,SERVOMIN,SERVOMAX);         // Adjust the angles to the range given by Servomin and Servomax
         servos[n].offangle=map(servos[n].offangle,0,180,SERVOMIN,SERVOMAX);
         servos[n].angle=map(servos[n].angle,0,180,SERVOMIN,SERVOMAX);
     }

  Serial.begin(9600);
  Serial.println("Los gehts");

  pwm.begin();
  
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates

  yield();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Main loop (run continuous)
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void loop()
{
  static int addr = 0;
  

  DCC.loop(); // DCC library
   
  if( ++addr >= maxservos ) addr = 0; // Next address to test

  // Set accessory output pin
  if (accessory[addr].output) digitalWrite(accessory[addr].outputPin, HIGH);
  else digitalWrite(accessory[addr].outputPin, LOW);

  // Every 'servotimer' ms, modify setpoints and move servos 1 step (if needed)
  if (millis() > timetoupdatesetpoint)
 {
    timetoupdatesetpoint = millis() + servotimer;
    for (int n=0; n<maxservos; n++)
    {
      if (accessory[servos[n].functionnumber].output) servos[n].setpoint=servos[n].onangle;
      else servos[n].setpoint=servos[n].offangle;
      pwm.setPWM(servos[n].servo, 0, servos[n].setpoint);
    }
  }
  
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Move all servos to min position and set all function outputs to 0, to eliminate startup servo jerk current draw
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  
  //if (digitalRead(A5)==LOW) {for (int n=0; n<maxservos; n++) accessory[n].output = 0;}               - Not to use with PWM Servoshield because it uses already pinMode A5

} //END MAIN LOOP


