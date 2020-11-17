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
uint32_t irTurquoise = 0xF78877; 
uint32_t irLightBlue = 0xF7A857;
uint32_t irBlue = 0xF7609F;
uint32_t irIndigo = 0xF750AF;
uint32_t irViolet = 0xF7708F;
uint32_t irLavender = 0xF748B7;
uint32_t irPink = 0xF76897;
uint32_t irWhite = 0xF720DF;

void doIR()
{
  if((strcmp(rf_cmd, rf_cmd_prev) == 0) && (strcmp(rf_cmd, "irSpeed") != 0) && (strcmp(rf_cmd, "irTime") != 0));
  else
  {
    if(strcmp(rf_cmd, "irON") == 0) IRSender.sendNEC(irON, 32, false);
    if(strcmp(rf_cmd, "irOFF") == 0) IRSender.sendNEC(irOFF, 32, false);
    if(strcmp(rf_cmd, "irTime") == 0) IRSender.sendNEC(irTime, 32, false);
    if(strcmp(rf_cmd, "irSpeed") == 0) IRSender.sendNEC(irSpeed, 32, false);
    if(strcmp(rf_cmd, "irFade") == 0) IRSender.sendNEC(irFade, 32, false);
    if(strcmp(rf_cmd, "irJump") == 0) IRSender.sendNEC(irJump, 32, false);
    if(strcmp(rf_cmd, "irAsyncFade") == 0) IRSender.sendNEC(irAsyncFade, 32, false);
    if(strcmp(rf_cmd, "irAsyncJump") == 0) IRSender.sendNEC(irAsyncJump, 32, false);
    if(strcmp(rf_cmd, "irRed") == 0) IRSender.sendNEC(irRed, 32, false);
    if(strcmp(rf_cmd, "irOrange") == 0) IRSender.sendNEC(irOrange, 32, false);
    if(strcmp(rf_cmd, "irYellow") == 0) IRSender.sendNEC(irYellow, 32, false);
    if(strcmp(rf_cmd, "irYellowGreen") == 0) IRSender.sendNEC(irYellowGreen, 32, false);
    if(strcmp(rf_cmd, "irLime") == 0) IRSender.sendNEC(irLime, 32, false);
    if(strcmp(rf_cmd, "irGreen") == 0) IRSender.sendNEC(irGreen, 32, false);
    if(strcmp(rf_cmd, "irLightGreen") == 0) IRSender.sendNEC(irLightGreen, 32, false);
    if(strcmp(rf_cmd, "irTeal") == 0) IRSender.sendNEC(irTeal, 32, false);
    if(strcmp(rf_cmd, "irTurquoise") == 0) IRSender.sendNEC(irTurquoise, 32, false);
    if(strcmp(rf_cmd, "irLightBlue") == 0) IRSender.sendNEC(irLightBlue, 32, false);
    if(strcmp(rf_cmd, "irBlue") == 0) IRSender.sendNEC(irBlue, 32, false);
    if(strcmp(rf_cmd, "irIndigo") == 0) IRSender.sendNEC(irIndigo, 32, false);
    if(strcmp(rf_cmd, "irViolet") == 0) IRSender.sendNEC(irViolet, 32, false);
    if(strcmp(rf_cmd, "irLavender") == 0) IRSender.sendNEC(irLavender, 32, false);
    if(strcmp(rf_cmd, "irPink") == 0) IRSender.sendNEC(irPink, 32, false);
    if(strcmp(rf_cmd, "irWhite") == 0) IRSender.sendNEC(irWhite, 32, false);
  }
  memcpy(rf_cmd_prev, rf_cmd, rfCmdLength);
}
