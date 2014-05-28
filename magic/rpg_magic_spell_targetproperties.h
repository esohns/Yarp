
// -------------------------------- * * * ----------------------------------- //
// PLEASE NOTE: this file was/is generated by XML2CppCode 0.1
// -------------------------------- * * * ----------------------------------- //

#pragma once
#ifndef RPG_MAGIC_SPELL_TARGETPROPERTIES_H
#define RPG_MAGIC_SPELL_TARGETPROPERTIES_H

#include "rpg_magic_exports.h"

struct RPG_Magic_Export RPG_Magic_Spell_TargetProperties
{
  RPG_Common_Amount base;
  unsigned char levelIncrement;
  unsigned char levelIncrementMax;
  RPG_Magic_Spell_AreaOfEffect effect;
  RPG_Common_AreaOfEffect shape;
  unsigned int radius;
  unsigned int height;
  RPG_Magic_Spell_Target target;
  bool shapeable;
  bool rangeIsInHD;
  bool incrementIsReciprocal;
};

#endif
