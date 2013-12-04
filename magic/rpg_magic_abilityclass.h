
// -------------------------------- * * * -------------------------------- //
// PLEASE NOTE: this file was/is generated by XML2CppCode 0.1
// -------------------------------- * * * -------------------------------- //

#pragma once
#ifndef RPG_MAGIC_ABILITYCLASS_H
#define RPG_MAGIC_ABILITYCLASS_H

enum RPG_Magic_AbilityClass
{
  ABILITYCLASS_EXTRAORDINARY = 0,
  ABILITYCLASS_SPELLLIKE,
  ABILITYCLASS_SUPERNATURAL,
  //
  RPG_MAGIC_ABILITYCLASS_MAX,
  RPG_MAGIC_ABILITYCLASS_INVALID
};

#include "rpg_magic_exports.h"

#include <ace/Global_Macros.h>

#include <map>
#include <string>

typedef std::map<RPG_Magic_AbilityClass, std::string> RPG_Magic_AbilityClassToStringTable_t;
typedef RPG_Magic_AbilityClassToStringTable_t::const_iterator RPG_Magic_AbilityClassToStringTableIterator_t;

class RPG_Magic_Export RPG_Magic_AbilityClassHelper
{
 public:
  inline static void init()
  {
    myRPG_Magic_AbilityClassToStringTable.clear();
    myRPG_Magic_AbilityClassToStringTable.insert(std::make_pair(ABILITYCLASS_EXTRAORDINARY, ACE_TEXT_ALWAYS_CHAR("ABILITYCLASS_EXTRAORDINARY")));
    myRPG_Magic_AbilityClassToStringTable.insert(std::make_pair(ABILITYCLASS_SPELLLIKE, ACE_TEXT_ALWAYS_CHAR("ABILITYCLASS_SPELLLIKE")));
    myRPG_Magic_AbilityClassToStringTable.insert(std::make_pair(ABILITYCLASS_SUPERNATURAL, ACE_TEXT_ALWAYS_CHAR("ABILITYCLASS_SUPERNATURAL")));
  };

  inline static std::string RPG_Magic_AbilityClassToString(const RPG_Magic_AbilityClass& element_in)
  {
    std::string result;
    RPG_Magic_AbilityClassToStringTableIterator_t iterator = myRPG_Magic_AbilityClassToStringTable.find(element_in);
    if (iterator != myRPG_Magic_AbilityClassToStringTable.end())
      result = iterator->second;
    else
      result = ACE_TEXT_ALWAYS_CHAR("RPG_MAGIC_ABILITYCLASS_INVALID");

    return result;
  };

  inline static RPG_Magic_AbilityClass stringToRPG_Magic_AbilityClass(const std::string& string_in)
  {
    RPG_Magic_AbilityClassToStringTableIterator_t iterator = myRPG_Magic_AbilityClassToStringTable.begin();
    do
    {
      if (iterator->second == string_in)
        return iterator->first;

      iterator++;
    } while (iterator != myRPG_Magic_AbilityClassToStringTable.end());

    return RPG_MAGIC_ABILITYCLASS_INVALID;
  };

  static RPG_Magic_AbilityClassToStringTable_t myRPG_Magic_AbilityClassToStringTable;

 private:
  ACE_UNIMPLEMENTED_FUNC(RPG_Magic_AbilityClassHelper());
  ACE_UNIMPLEMENTED_FUNC(RPG_Magic_AbilityClassHelper(const RPG_Magic_AbilityClassHelper&));
  ACE_UNIMPLEMENTED_FUNC(RPG_Magic_AbilityClassHelper& operator=(const RPG_Magic_AbilityClassHelper&));
};

#endif
