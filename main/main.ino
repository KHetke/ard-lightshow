// Libraries
#include <SPI.h>
#include <nRF24L01.h>
#include <printf.h>
#include <RF24.h>
#include <RF24_config.h>

// Pins
const int RF24CEPin = 9;  // RF24 Chip Enable
const int RF24CSNPin = 8;  // RF24 Chip Select Not
const int RFModePin = 7;  // Controls the RF mode
const int LEDEnableBPin = 6;  // Enables the LEDs
const int MICPin = A0;

// Constants
const uint16_t loopIterMax = 128; // Iterations of the loop before resetting
const uint8_t fftDecimationFactor = 16; // Decimation factor for determining lightMatrix codes
const uint8_t fftTrigAmplitude = 10; // Trigger amplitude to turn on light element

// Mode Selection
int RFMode;   // RF Mode; 0=TX, 1=RX

// Objects
RF24 radio(RF24CEPin, RF24CSNPin);

// Internal Values
byte address[6] = "00000";        // RF Address Selection
int loopIter = 0;                 // Program counter to check current loop iteration
double micValueReal[loopIterMax]; // Value over program loop from the microphone
double micValueImag[loopIterMax]; // Value over program loop from the microphone
int lightMatrix[loopIterMax/fftDecimationFactor]; // Light Matrix contains integer values to trigger lights per address
int rxLightEnableB = 1;

void setup()
{
  // Open Serial
  Serial.begin(115200);
  while(!Serial);
  Serial.println("Ready");

  // Designate Pin Modes
  pinMode(RF24CEPin, OUTPUT);
  pinMode(RF24CSNPin, OUTPUT);
  pinMode(LEDEnableBPin, OUTPUT);
  pinMode(RFModePin, INPUT);
  pinMode(MICPin, INPUT);
  
  // Read Mode Pins
  RFMode = digitalRead(RFModePin);

  // Initialize Radio
  radio.begin();
  
}

void loop()
{
  if (RFMode == 0) 
  {
    micValueReal[loopIter] = analogRead(MICPin);
    micValueImag[loopIter] = 0.0;
    // Serial.println(micValueReal[loopIter]);
    loopIter++;
    if (loopIter == loopIterMax)
    {
      doAudio();
      doTX();
      loopIter = 0;
      delay(1000);
    }
  }
  if (RFMode == 1)
  {
    loopIter++;
    if (loopIter == loopIterMax)
    {
      doRX();
      digitalWrite(LEDEnableBPin, rxLightEnableB);
      loopIter = 0;
      delay(1000);
    }
  }
  delay(10);
}
