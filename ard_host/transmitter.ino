byte address_max[6]= "00007";     // RF Address Selection
byte address[6] = "00000";        // RF Address Selection

void doTX()
{
  for (int i = 0; i <= address_max[6]; i++) 
  {
    address[6] = i;
    radio.openWritingPipe(address);
  }
}
