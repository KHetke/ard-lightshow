#include <IRremote.h>

IRsend IRSender;

uint32_t irON = 0xF700FF;
uint32_t irOFF = 0xF7807F;
uint32_t irTime = 0xF740BF;
uint32_t irSpeed = 0xF7C03F;
uint32_t irFade = 0xF7D02F;
uint32_t irJump = 0xF7F00F;
uint32_t irAsyncFade = 0xF7C837;
uint32_t irAsyncJump = 0xF7E817;
uint32_t irRed = 0xF720DF;
uint32_t irOrange = 0xF710EF;
uint32_t irYellow = 0xF730CF;
uint32_t irYellowGreen = 0xF708F7;
uint32_t irLime = 0xF728D7;
uint32_t irGreen = 0xF7A05F;
uint32_t irLightGreen = 0xF7906F;
uint32_t irTeal = 0xF7B04F;
uint32_t irTurqoise = 0xF78877;
uint32_t irLightBlue = 0xF7A857;
uint32_t irBlue = 0xF7609F;
uint32_t irIndigo = 0xF750AF;
uint32_t irViolet = 0xF7708F;
uint32_t irLavender = 0xF748B7;
uint32_t irPink = 0xF76897;
uint32_t irWhite = 0xF720DF;

void doIR()
{
  IRSender.sendNEC(irTeal, 32, false);
  delay(100);
}
