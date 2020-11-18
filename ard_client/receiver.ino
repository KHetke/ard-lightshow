byte address[5] = {'A','L','0','0','0'};        // RF Address Selection

RF24 radio(RF24CEPin, RF24CSNPin);

void radioInit()
{
  radio.begin();
  radio.setDataRate( RF24_250KBPS );
  
  radio.openReadingPipe(0, address);
  radio.startListening();
}

void doRX()
{
  if (radio.available())
  {
    radio.read(&rf_cmd, sizeof(rf_cmd));
    Serial.println(rf_cmd);
  }
}
