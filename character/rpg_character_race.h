
// -------------------------------- * * * -------------------------------- //
// PLEASE NOTE: this file was/is generated by XML2CppCode 0.1
// -------------------------------- * * * -------------------------------- //

#pragma once
#ifndef RPG_CHARACTER_RACE_H
#define RPG_CHARACTER_RACE_H

enum RPG_Character_Race
{
  RACE_NONE = 0,
  RACE_DWARF,
  RACE_ELF,
  RACE_GNOME,
  RACE_HALFLING,
  RACE_HUMAN,
  RACE_ORC,
  //
  RPG_CHARACTER_RACE_MAX,
  RPG_CHARACTER_RACE_INVALID
};

#include "rpg_character_exports.h"

#include <ace/Global_Macros.h>

#include <map>
#include <string>

typedef std::map<RPG_Character_Race, std::string> RPG_Character_RaceToStringTable_t;
typedef RPG_Character_RaceToStringTable_t::const_iterator RPG_Character_RaceToStringTableIterator_t;

class RPG_Character_Export RPG_Character_RaceHelper
{
 public:
  inline static void init()
  {
    myRPG_Character_RaceToStringTable.clear();
    myRPG_Character_RaceToStringTable.insert(std::make_pair(RACE_NONE, ACE_TEXT_ALWAYS_CHAR("RACE_NONE")));
    myRPG_Character_RaceToStringTable.insert(std::make_pair(RACE_DWARF, ACE_TEXT_ALWAYS_CHAR("RACE_DWARF")));
    myRPG_Character_RaceToStringTable.insert(std::make_pair(RACE_ELF, ACE_TEXT_ALWAYS_CHAR("RACE_ELF")));
    myRPG_Character_RaceToStringTable.insert(std::make_pair(RACE_GNOME, ACE_TEXT_ALWAYS_CHAR("RACE_GNOME")));
    myRPG_Character_RaceToStringTable.insert(std::make_pair(RACE_HALFLING, ACE_TEXT_ALWAYS_CHAR("RACE_HALFLING")));
    myRPG_Character_RaceToStringTable.insert(std::make_pair(RACE_HUMAN, ACE_TEXT_ALWAYS_CHAR("RACE_HUMAN")));
    myRPG_Character_RaceToStringTable.insert(std::make_pair(RACE_ORC, ACE_TEXT_ALWAYS_CHAR("RACE_ORC")));
  };

  inline static std::string RPG_Character_RaceToString(const RPG_Character_Race& element_in)
  {
    std::string result;
    RPG_Character_RaceToStringTableIterator_t iterator = myRPG_Character_RaceToStringTable.find(element_in);
    if (iterator != myRPG_Character_RaceToStringTable.end())
      result = iterator->second;
    else
      result = ACE_TEXT_ALWAYS_CHAR("RPG_CHARACTER_RACE_INVALID");

    return result;
  };

  inline static RPG_Character_Race stringToRPG_Character_Race(const std::string& string_in)
  {
    RPG_Character_RaceToStringTableIterator_t iterator = myRPG_Character_RaceToStringTable.begin();
    do
    {
      if (iterator->second == string_in)
        return iterator->first;

      iterator++;
    } while (iterator != myRPG_Character_RaceToStringTable.end());

    return RPG_CHARACTER_RACE_INVALID;
  };

  static RPG_Character_RaceToStringTable_t myRPG_Character_RaceToStringTable;

 private:
  ACE_UNIMPLEMENTED_FUNC(RPG_Character_RaceHelper());
  ACE_UNIMPLEMENTED_FUNC(RPG_Character_RaceHelper(const RPG_Character_RaceHelper&));
  ACE_UNIMPLEMENTED_FUNC(RPG_Character_RaceHelper& operator=(const RPG_Character_RaceHelper&));
};

#endif
