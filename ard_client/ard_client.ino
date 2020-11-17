// Libraries
#include <SPI.h>
#include <nRF24L01.h>
#include <printf.h>
#include <RF24.h>
#include <RF24_config.h>

// Pins
const int RF24CEPin = 9;  // RF24 Chip Enable
const int RF24CSNPin = 8;  // RF24 Chip Select Not
const int IRSendPin = 3;  // Enables the LEDs

// Constants
const uint16_t loopIterMax = 128; // Iterations of the loop before resetting
const int rfCmdLength = 16;

// Program Counter
int loopIter = 0;                 // Program counter to check current loop iteration

//RF Values
char rf_cmd[rfCmdLength] = {0};
char rf_cmd_prev[rfCmdLength] = {0};

void setup()
{
  // Open Serial
  Serial.begin(115200);
  while(!Serial);
  Serial.println("Ready");

  // Designate Pin Modes
  pinMode(RF24CEPin, OUTPUT);
  pinMode(RF24CSNPin, OUTPUT);
  pinMode(IRSendPin, OUTPUT);

  radioInit();
  
}

void loop()
{
  loopIter++;
  if (loopIter == loopIterMax)
  {
    doRX();
    doIR();
    loopIter = 0;
    delay(10);
  }
  delay(2);
}
