#include <arduinoFFT.h>

arduinoFFT FFT = arduinoFFT(); 

void doFFT()
{
  FFT.DCRemoval(micValueReal, loopIterMax);
  FFT.Windowing(micValueReal, loopIterMax, FFT_WIN_TYP_RECTANGLE, FFT_FORWARD);  /* Weigh data */
  FFT.Compute(micValueReal, micValueImag, loopIterMax, FFT_FORWARD); /* Compute FFT */
  FFT.ComplexToMagnitude(micValueReal, micValueImag, loopIterMax); /* Compute magnitudes */
}

void translateMatrix()
{
  /* Creating a for loop here allows better control of lightMatrix 
   * by ignoring sets when the number of sent addresses are smaller.
   */
  int j_max = floor((loopIterMax-1)/((sizeof(address)/5)));
  for (int i = 0; i <= ((sizeof(address)/5)-1); i++)
  {
    for (int j = 0; j <= j_max; j++)
    {
      // if ((i*j_max+j) == 0) Serial.println("0"); // To call specific DFT positions.
      // if ((j) == 0) Serial.println("0");         // To call per sub-channel
      // if ((i) == 0) Serial.println("0");         // To call per address
      if ((i*j_max+j) == 0);
      else
      {
        if (micValueReal[i*j_max+4] >= 700.0) memcpy(lightMatrix[i], "irRed", rfCmdLength);
        else if (micValueReal[i*j_max+4] >= 550.0) memcpy(lightMatrix[i], "irOrange", rfCmdLength);
        else if (micValueReal[i*j_max+4] >= 400.0) memcpy(lightMatrix[i], "irYellow", rfCmdLength);
        else if (micValueReal[i*j_max+4] >= 250.0) memcpy(lightMatrix[i], "irGreen", rfCmdLength);
        else if (micValueReal[i*j_max+4] >= 100.0) memcpy(lightMatrix[i], "irTeal", rfCmdLength);
        else if (micValueReal[i*j_max+4] >= 0.0) memcpy(lightMatrix[i], "irBlue", rfCmdLength);
      }
      Serial.println(lightMatrix[i]);
    }
  }
}
