#include <Wire.h> // For I2C




#include <LiquidCrystal_I2C.h>



#include <IRLib2.h>
#include <IRLibDecodeBase.h>
#include <IRLibGlobals.h>
#include <IRLibRecvBase.h>
#include <IRLibRecvLoop.h>



#include <Key.h>
#include <Keypad.h>



IRrecvPCI myReceiver(2);
IRdecode myDecoder;
IRsend mySender;


//KeyBoard STUFF
int kb0=0;
int kb1=0;
int kb2=0;
int kb3=0;
int kb4=0;
int kb5=0;
int kb6=0;
int kb7=0;
int kb8=0;
int kb9=0;
int kbpound=0;
int kbstar=0;
int kba=0;
int kbb=0;
int kbc=0;
int kbd=0;


const byte ROWS = 4; // Four rows
const byte COLS = 4; // Four columns
// Define the Keymap
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
// Connect keypad ROW0, ROW1, ROW2 and ROW3 to these Arduino pins.
byte rowPins[ROWS] = { 22, 24, 26, 28 };
// Connect keypad COL0, COL1 and COL2 COL3 to these Arduino pins.
byte colPins[COLS] = { 30, 32, 34, 36 };
// Create the Keypad
Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );


#define ledpin 13

//LCDSTUFF
char array1[]="array1";
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3,POSITIVE);




//CODE STUFF
unsigned long timestart;
int mag=10;
int keyfreq=600;

int i=1;
int flashstate=0;
int reloaded=1;
int reloadsound=0;
unsigned long reloadbuttontime;
int triggerblockreload=0;
int triggerblockreloading=0;
int triggerblock=0; 
unsigned long triggerpull;        
int gunshotsound=0;
int healthlvl=8;
int deathflag=0;
int respawn=0;
float batterylvl;



void setup() {
Serial.begin(9600);  //to debug

//Pinmodes for mosfets and inputs ect
//IRRECIEVER 2       IRSENDER 5
pinMode(46,INPUT); //trigger
pinMode(A0,INPUT); //batteryLVLsensor
pinMode(12,OUTPUT);//piezobuzzer
pinMode(7,OUTPUT); //flashlight
pinMode(4,OUTPUT); //LED muzzle flash
pinMode(6,OUTPUT); //LED SESSY Mood lights
pinMode(3,OUTPUT); //Laser
pinMode(8,OUTPUT); //Solenoid

// DONT FORGET TO ADD A RELOAD BUTTON CHRAS, FOR NOW ITS #

digitalWrite(12,LOW);
digitalWrite(7,LOW);
digitalWrite(4,LOW);
digitalWrite(6,LOW);
digitalWrite(3,LOW);
digitalWrite(8,LOW);



lcd.begin(16,2);
lcd.clear();

myReceiver.enableIRIn();
timestart=millis();



}

void loop() {
  if(healthlvl==8){
if(mag==10){
lcd.clear();
lcd.home(); // top left
lcd.print("HEALTH/>oooooooo");
lcd.setCursor(0, 1); // bott left
lcd.print("AMMO/>oooooooooo");

delay(3000);
}

}

}
