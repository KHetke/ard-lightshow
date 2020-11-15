// Libraries
#include <SPI.h>
#include <nRF24L01.h>
#include <printf.h>
#include <RF24.h>
#include <RF24_config.h>

// Pins
const int RF24CEPin = 9;  // RF24 Chip Enable
const int RF24CSNPin = 8;  // RF24 Chip Select Not
const int MICPin = A0;

// Constants
const uint16_t loopIterMax = 128; // Iterations of the loop before resetting
const uint8_t fftDecimationFactor = 16; // Decimation factor for determining lightMatrix codes
const uint8_t fftTrigAmplitude = 10; // Trigger amplitude to turn on light elements

// Objects
RF24 radio(RF24CEPin, RF24CSNPin);

// Internal Values
int loopIter = 0;                 // Program counter to check current loop iteration
double micValueReal[loopIterMax]; // Value over program loop from the microphone
double micValueImag[loopIterMax]; // Value over program loop from the microphone
int lightMatrix[loopIterMax/fftDecimationFactor]; // Light Matrix contains integer values to trigger lights per address
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
  pinMode(MICPin, INPUT);

  // Initialize Radio
  radio.begin();
}

void loop()
{
  micValueReal[loopIter] = analogRead(MICPin);
  micValueImag[loopIter] = 0.0;
  loopIter++;
  if (loopIter == loopIterMax)
  {
    doAudio();
    doTX();
    loopIter = 0;
    delay(5);
  }
  delay(1);
}
