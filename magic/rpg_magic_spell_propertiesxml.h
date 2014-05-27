
// -------------------------------- * * * ----------------------------------- //
// PLEASE NOTE: this file was/is generated by XML2CppCode 0.1
// -------------------------------- * * * ----------------------------------- //

#pragma once
#ifndef RPG_MAGIC_SPELL_PROPERTIESXML_H
#define RPG_MAGIC_SPELL_PROPERTIESXML_H

#include "rpg_magic_exports.h"

struct RPG_Magic_Export RPG_Magic_Spell_PropertiesXML
{
  std::string name;
  RPG_Magic_Spell_Type type;
  std::vector<RPG_Magic_Spell_Level> levels;
  unsigned int cost;
  RPG_Magic_Spell_CastingTime time;
  RPG_Magic_Spell_RangeProperties range;
  std::vector<RPG_Magic_Spell_TargetProperties> targets;
  RPG_Magic_Spell_DurationProperties duration;
  std::vector<RPG_Magic_Spell_PreconditionProperties> preconditions;
  std::vector<RPG_Magic_Spell_EffectProperties> effects;
  std::vector<RPG_Magic_CounterMeasure> counterMeasures;
  RPG_Common_SavingThrow saveable;
  bool resistible;
  bool effectsAreInclusive;
};

#endif
