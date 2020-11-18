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
const int rfCmdLength = 16;
const byte address[][5] = {{'A','L','0','0','0'},
                           {'A','L','0','0','1'},
                           {'A','L','0','0','2'},
                           {'A','L','0','0','3'},
                           {'A','L','0','0','4'},
                           {'A','L','0','0','5'},
                           {'A','L','0','0','6'},
                           {'A','L','0','0','7'}};

// Program Counter
int loopIter = 0;                 // Program counter to check current loop iteration
char lightMatrix[sizeof(address)/5][rfCmdLength] = {0};

// Mic/DFT Values
double micValueReal[loopIterMax]; // Value over program loop from the microphone. Repurposed to DFT values after taken
double micValueImag[loopIterMax]; // Value over program loop from the microphone

// RF Values
byte rf_cmd[rfCmdLength] = "";

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

  radioInit();
}

void loop()
{
  //Serial.println(micValueReal[loopIter]);
  micValueReal[loopIter] = analogRead(MICPin);
  micValueImag[loopIter] = 0.0;
  //Serial.println(micValueReal[loopIter]);
  loopIter++;
  if (loopIter == loopIterMax)
  {
    doFFT();
    translateMatrix();
    doTX();
    loopIter = 0;
    delay(2);
  }
  delay(0.1);
}
