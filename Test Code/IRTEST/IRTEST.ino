#include <IRLib2.h>
#include <IRLibDecodeBase.h>
#include <IRLibGlobals.h>
#include <IRLibRecvBase.h>
#include <IRLibRecvLoop.h>

IRrecvPCI myReceiver(2);
IRdecode myDecoder;
IRsend mySender;


void setup() {
 Serial.begin(9600);
Serial.println("Starting");
pinMode(22,INPUT);

myReceiver.enableIRIn();




}

void loop() {
  if(digitalRead(22)==HIGH){
Serial.println("Sending");
mySender.send(NEC, 0x5, 56);
myReceiver.enableIRIn();

    
  }



 if (myReceiver.getResults()) {
    myDecoder.decode();           //Decode it
    Serial.println(myDecoder.value);
    myReceiver.enableIRIn();
    
 }




}
