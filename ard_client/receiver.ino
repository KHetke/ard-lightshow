byte address[5] = {'A','L','0','0','0'};        // RF Address Selection

RF24 radio(RF24CEPin, RF24CSNPin);

void radioInit()
{
  radio.begin();
  radio.setDataRate( RF24_2MBPS );
  
  radio.openReadingPipe(0, address);
  radio.startListening();
}

void doRX()
{
  if (radio.available())
  {
    char text[32] = {0};
    radio.read(&text, sizeof(text));
    Serial.println(text);
  }
}
