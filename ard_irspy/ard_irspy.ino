#include <IRremote.h>

const int RXPIN = 3;
IRrecv irrecv(RXPIN);
decode_results results;

void setup(){
  Serial.begin(9600);
  while(!Serial);
  Serial.println("Ready");

  pinMode(RXPIN, INPUT);
  
  irrecv.enableIRIn();
  irrecv.blink13(true);
}

void loop(){
  if (irrecv.decode(&results)){
        Serial.println(results.value, HEX);
        irrecv.resume();
  }
}
