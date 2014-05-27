
// -------------------------------- * * * ----------------------------------- //
// PLEASE NOTE: this file was/is generated by XML2CppCode 0.1
// -------------------------------- * * * ----------------------------------- //

#pragma once
#ifndef RPG_MAGIC_SPELL_AREAOFEFFECT_H
#define RPG_MAGIC_SPELL_AREAOFEFFECT_H

enum RPG_Magic_Spell_AreaOfEffect
{
  EFFECT_BURST = 0,
  EFFECT_EMANATION,
  EFFECT_SPREAD,
  //
  RPG_MAGIC_SPELL_AREAOFEFFECT_MAX,
  RPG_MAGIC_SPELL_AREAOFEFFECT_INVALID
};

#include "rpg_magic_exports.h"

#include <ace/Global_Macros.h>

#include <map>
#include <string>

typedef std::map<RPG_Magic_Spell_AreaOfEffect, std::string> RPG_Magic_Spell_AreaOfEffectToStringTable_t;
typedef RPG_Magic_Spell_AreaOfEffectToStringTable_t::const_iterator RPG_Magic_Spell_AreaOfEffectToStringTableIterator_t;

class RPG_Magic_Export RPG_Magic_Spell_AreaOfEffectHelper
{
 public:
  inline static void init()
  {
    myRPG_Magic_Spell_AreaOfEffectToStringTable.clear();
    myRPG_Magic_Spell_AreaOfEffectToStringTable.insert(std::make_pair(EFFECT_BURST, ACE_TEXT_ALWAYS_CHAR("EFFECT_BURST")));
    myRPG_Magic_Spell_AreaOfEffectToStringTable.insert(std::make_pair(EFFECT_EMANATION, ACE_TEXT_ALWAYS_CHAR("EFFECT_EMANATION")));
    myRPG_Magic_Spell_AreaOfEffectToStringTable.insert(std::make_pair(EFFECT_SPREAD, ACE_TEXT_ALWAYS_CHAR("EFFECT_SPREAD")));
  };

  inline static std::string RPG_Magic_Spell_AreaOfEffectToString(const RPG_Magic_Spell_AreaOfEffect& element_in)
  {
    std::string result;
    RPG_Magic_Spell_AreaOfEffectToStringTableIterator_t iterator = myRPG_Magic_Spell_AreaOfEffectToStringTable.find(element_in);
    if (iterator != myRPG_Magic_Spell_AreaOfEffectToStringTable.end())
      result = iterator->second;
    else
      result = ACE_TEXT_ALWAYS_CHAR("RPG_MAGIC_SPELL_AREAOFEFFECT_INVALID");

    return result;
  };

  inline static RPG_Magic_Spell_AreaOfEffect stringToRPG_Magic_Spell_AreaOfEffect(const std::string& string_in)
  {
    RPG_Magic_Spell_AreaOfEffectToStringTableIterator_t iterator = myRPG_Magic_Spell_AreaOfEffectToStringTable.begin();
    do
    {
      if (iterator->second == string_in)
        return iterator->first;

      iterator++;
    } while (iterator != myRPG_Magic_Spell_AreaOfEffectToStringTable.end());

    return RPG_MAGIC_SPELL_AREAOFEFFECT_INVALID;
  };

  static RPG_Magic_Spell_AreaOfEffectToStringTable_t myRPG_Magic_Spell_AreaOfEffectToStringTable;

 private:
  ACE_UNIMPLEMENTED_FUNC(RPG_Magic_Spell_AreaOfEffectHelper());
  ACE_UNIMPLEMENTED_FUNC(RPG_Magic_Spell_AreaOfEffectHelper(const RPG_Magic_Spell_AreaOfEffectHelper&));
  ACE_UNIMPLEMENTED_FUNC(RPG_Magic_Spell_AreaOfEffectHelper& operator=(const RPG_Magic_Spell_AreaOfEffectHelper&));
};

#endif
