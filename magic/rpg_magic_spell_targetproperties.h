
// -------------------------------- * * * -------------------------------- //
// PLEASE NOTE: this file was/is generated by XML2CppCode 0.1
// -------------------------------- * * * -------------------------------- //

#pragma once
#ifndef RPG_MAGIC_SPELL_TARGETPROPERTIES_H
#define RPG_MAGIC_SPELL_TARGETPROPERTIES_H

struct RPG_Magic_Spell_TargetProperties
{
  RPG_Magic_Spell_Target type;
  unsigned int value;
  RPG_Dice_Roll range;
  unsigned char levelIncrement;
  RPG_Magic_Spell_AreaOfEffect effect;
  RPG_Common_AreaOfEffect shape;
  unsigned char radius;
  unsigned char height;
  bool rangeIsInHD;
};

#endif
