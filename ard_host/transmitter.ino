const byte address[][5] = {{'A','L','0','0','0'},
                           {'A','L','0','0','1'},
                           {'A','L','0','0','2'},
                           {'A','L','0','0','3'},
                           {'A','L','0','0','4'},
                           {'A','L','0','0','5'},
                           {'A','L','0','0','6'},
                           {'A','L','0','0','7'}};

RF24 radio(RF24CEPin, RF24CSNPin);

void radioInit()
{
  radio.begin();
  radio.stopListening();
  radio.setDataRate( RF24_1MBPS );
  radio.setRetries(4,5); // delay, count
}

void doTX()
{
  for (int i = 0; i <= (sizeof(address)/5); i++) 
  {
    radio.openWritingPipe(address[i]);
    const char text[] = "ABC";
    radio.write(&text, sizeof(text));
  }
}
