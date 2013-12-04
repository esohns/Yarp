
// -------------------------------- * * * -------------------------------- //
// PLEASE NOTE: this file was/is generated by XML2CppCode 0.1
// -------------------------------- * * * -------------------------------- //

#pragma once
#ifndef RPG_COMMON_EFFECTTYPE_H
#define RPG_COMMON_EFFECTTYPE_H

enum RPG_Common_EffectType
{
  EFFECT_BATTLE = 0,
  EFFECT_IMMEDIATE,
  EFFECT_PERMANENT,
  EFFECT_TEMPORARY,
  //
  RPG_COMMON_EFFECTTYPE_MAX,
  RPG_COMMON_EFFECTTYPE_INVALID
};

#include "rpg_common_exports.h"

#include <ace/Global_Macros.h>

#include <map>
#include <string>

typedef std::map<RPG_Common_EffectType, std::string> RPG_Common_EffectTypeToStringTable_t;
typedef RPG_Common_EffectTypeToStringTable_t::const_iterator RPG_Common_EffectTypeToStringTableIterator_t;

class RPG_Common_Export RPG_Common_EffectTypeHelper
{
 public:
  inline static void init()
  {
    myRPG_Common_EffectTypeToStringTable.clear();
    myRPG_Common_EffectTypeToStringTable.insert(std::make_pair(EFFECT_BATTLE, ACE_TEXT_ALWAYS_CHAR("EFFECT_BATTLE")));
    myRPG_Common_EffectTypeToStringTable.insert(std::make_pair(EFFECT_IMMEDIATE, ACE_TEXT_ALWAYS_CHAR("EFFECT_IMMEDIATE")));
    myRPG_Common_EffectTypeToStringTable.insert(std::make_pair(EFFECT_PERMANENT, ACE_TEXT_ALWAYS_CHAR("EFFECT_PERMANENT")));
    myRPG_Common_EffectTypeToStringTable.insert(std::make_pair(EFFECT_TEMPORARY, ACE_TEXT_ALWAYS_CHAR("EFFECT_TEMPORARY")));
  };

  inline static std::string RPG_Common_EffectTypeToString(const RPG_Common_EffectType& element_in)
  {
    std::string result;
    RPG_Common_EffectTypeToStringTableIterator_t iterator = myRPG_Common_EffectTypeToStringTable.find(element_in);
    if (iterator != myRPG_Common_EffectTypeToStringTable.end())
      result = iterator->second;
    else
      result = ACE_TEXT_ALWAYS_CHAR("RPG_COMMON_EFFECTTYPE_INVALID");

    return result;
  };

  inline static RPG_Common_EffectType stringToRPG_Common_EffectType(const std::string& string_in)
  {
    RPG_Common_EffectTypeToStringTableIterator_t iterator = myRPG_Common_EffectTypeToStringTable.begin();
    do
    {
      if (iterator->second == string_in)
        return iterator->first;

      iterator++;
    } while (iterator != myRPG_Common_EffectTypeToStringTable.end());

    return RPG_COMMON_EFFECTTYPE_INVALID;
  };

  static RPG_Common_EffectTypeToStringTable_t myRPG_Common_EffectTypeToStringTable;

 private:
  ACE_UNIMPLEMENTED_FUNC(RPG_Common_EffectTypeHelper());
  ACE_UNIMPLEMENTED_FUNC(RPG_Common_EffectTypeHelper(const RPG_Common_EffectTypeHelper&));
  ACE_UNIMPLEMENTED_FUNC(RPG_Common_EffectTypeHelper& operator=(const RPG_Common_EffectTypeHelper&));
};

#endif
