// Libraries
#include <SPI.h>
#include <nRF24L01.h>
#include <printf.h>
#include <RF24.h>
#include <RF24_config.h>

// Pins
const int RF24CEPin = 9;  // RF24 Chip Enable
const int RF24CSNPin = 8;  // RF24 Chip Select Not
const int LEDEnablePin = 7;  // Enables the LEDs

// Constants
const uint16_t loopIterMax = 128; // Iterations of the loop before resetting

// Objects
RF24 radio(RF24CEPin, RF24CSNPin);

// Internal Values
int loopIter = 0;                 // Program counter to check current loop iteration
int rxLightEnable = 1;

void setup()
{
  // Open Serial
  Serial.begin(115200);
  while(!Serial);
  Serial.println("Ready");

  // Designate Pin Modes
  pinMode(RF24CEPin, OUTPUT);
  pinMode(RF24CSNPin, OUTPUT);
  pinMode(LEDEnablePin, OUTPUT);

  // Initialize Radio
  radio.begin();
  
}

void loop()
{
  loopIter++;
  if (loopIter == loopIterMax)
  {
    doRX();
    digitalWrite(LEDEnablePin, rxLightEnable);
    loopIter = 0;
    delay(5);
  }
  delay(1);
}
