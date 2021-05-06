#include <IRLibAll.h>



IRrecvPCI myReceiver(2);
IRdecode myDecoder;



void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);  
 

myReceiver.enableIRIn();

pinMode(7,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
if (myReceiver.getResults()) {
    myDecoder.decode();           //Decode it
    myDecoder.dumpResults(true);  //Now print results. Use false for less detail
    digitalWrite(7,HIGH);
    delay(300);
     digitalWrite(7,LOW);
    myReceiver.enableIRIn();      //Restart receiver
  
  }

}



