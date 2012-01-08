
// -------------------------------- * * * -------------------------------- //
// PLEASE NOTE: this file was/is generated by XML2CppCode 0.1
// -------------------------------- * * * -------------------------------- //

#pragma once
#ifndef RPG_MAGIC_SPELL_PRECONDITIONPROPERTIES_H
#define RPG_MAGIC_SPELL_PRECONDITIONPROPERTIES_H

#include "rpg_magic_exports.h"

struct RPG_Magic_Export RPG_Magic_Spell_PreconditionProperties
{
  RPG_Magic_Spell_Precondition type;
  int value;
  unsigned char levelIncrement;
  unsigned char levelIncrementMax;
  RPG_Character_Alignment alignment;
  RPG_Common_Attribute attribute;
  RPG_Common_Condition condition;
  std::vector<RPG_Common_CreatureType> creatures;
  RPG_Common_Size size;
  RPG_Common_Environment environment;
  bool reverse;
  bool baseIsCasterLevel;
};

#endif
