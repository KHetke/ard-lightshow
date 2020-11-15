#include <arduinoFFT.h>

arduinoFFT FFT = arduinoFFT(); 

void doAudio()
{
  doFFT();
  for (int i = 0; i < loopIterMax; i+=fftDecimationFactor) 
  {
    double decimatedElement = (micValueReal[i]+micValueReal[i+1]+micValueReal[i+2]+micValueReal[i+3])/fftDecimationFactor;
    if (decimatedElement > fftTrigAmplitude) lightMatrix[i] = 1;
    else lightMatrix[i] = 0;
  }
}

void doFFT()
{
  FFT.DCRemoval(micValueReal, loopIterMax);
  FFT.Windowing(micValueReal, loopIterMax, FFT_WIN_TYP_RECTANGLE, FFT_FORWARD);  /* Weigh data */
  FFT.Compute(micValueReal, micValueImag, loopIterMax, FFT_FORWARD); /* Compute FFT */
  FFT.ComplexToMagnitude(micValueReal, micValueImag, loopIterMax); /* Compute magnitudes */
}
