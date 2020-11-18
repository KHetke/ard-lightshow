RF24 radio(RF24CEPin, RF24CSNPin);

void radioInit()
{
  radio.begin();
  radio.stopListening();
  radio.setDataRate( RF24_250KBPS );
  radio.setRetries(4,5); // delay, count
}

void doTX()
{
  for (int i = 0; i <= (sizeof(address)/5); i++) 
  {
    memcpy(rf_cmd, lightMatrix[i], rfCmdLength);
    radio.openWritingPipe(address[i]);
    radio.write(&rf_cmd, sizeof(rf_cmd));
  }
}
