
// -------------------------------- * * * -------------------------------- //
// PLEASE NOTE: this file was/is generated by XML2CppCode 0.1
// -------------------------------- * * * -------------------------------- //

#pragma once
#ifndef RPG_MAGIC_SPELL_DURATION_H
#define RPG_MAGIC_SPELL_DURATION_H

enum RPG_Magic_Spell_Duration
{
  DURATION_CONCENTRATION = 0,
  DURATION_DISCHARGE,
  DURATION_INSTANTANEOUS,
  DURATION_PERMANENT,
  DURATION_TIMED,
  //
  RPG_MAGIC_SPELL_DURATION_MAX,
  RPG_MAGIC_SPELL_DURATION_INVALID
};

#include <ace/Global_Macros.h>

#include <map>
#include <string>

typedef std::map<RPG_Magic_Spell_Duration, std::string> RPG_Magic_Spell_DurationToStringTable_t;
typedef RPG_Magic_Spell_DurationToStringTable_t::const_iterator RPG_Magic_Spell_DurationToStringTableIterator_t;

class RPG_Magic_Spell_DurationHelper
{
 public:
  inline static void init()
  {
    myRPG_Magic_Spell_DurationToStringTable.clear();
    myRPG_Magic_Spell_DurationToStringTable.insert(std::make_pair(DURATION_CONCENTRATION, ACE_TEXT_ALWAYS_CHAR("DURATION_CONCENTRATION")));
    myRPG_Magic_Spell_DurationToStringTable.insert(std::make_pair(DURATION_DISCHARGE, ACE_TEXT_ALWAYS_CHAR("DURATION_DISCHARGE")));
    myRPG_Magic_Spell_DurationToStringTable.insert(std::make_pair(DURATION_INSTANTANEOUS, ACE_TEXT_ALWAYS_CHAR("DURATION_INSTANTANEOUS")));
    myRPG_Magic_Spell_DurationToStringTable.insert(std::make_pair(DURATION_PERMANENT, ACE_TEXT_ALWAYS_CHAR("DURATION_PERMANENT")));
    myRPG_Magic_Spell_DurationToStringTable.insert(std::make_pair(DURATION_TIMED, ACE_TEXT_ALWAYS_CHAR("DURATION_TIMED")));
  };

  inline static std::string RPG_Magic_Spell_DurationToString(const RPG_Magic_Spell_Duration& element_in)
  {
    std::string result;
    RPG_Magic_Spell_DurationToStringTableIterator_t iterator = myRPG_Magic_Spell_DurationToStringTable.find(element_in);
    if (iterator != myRPG_Magic_Spell_DurationToStringTable.end())
      result = iterator->second;
    else
      result = ACE_TEXT_ALWAYS_CHAR("RPG_MAGIC_SPELL_DURATION_INVALID");

    return result;
  };

  inline static RPG_Magic_Spell_Duration stringToRPG_Magic_Spell_Duration(const std::string& string_in)
  {
    RPG_Magic_Spell_DurationToStringTableIterator_t iterator = myRPG_Magic_Spell_DurationToStringTable.begin();
    do
    {
      if (iterator->second == string_in)
        return iterator->first;

      iterator++;
    } while (iterator != myRPG_Magic_Spell_DurationToStringTable.end());

    return RPG_MAGIC_SPELL_DURATION_INVALID;
  };

  static RPG_Magic_Spell_DurationToStringTable_t myRPG_Magic_Spell_DurationToStringTable;

 private:
  ACE_UNIMPLEMENTED_FUNC(RPG_Magic_Spell_DurationHelper());
  ACE_UNIMPLEMENTED_FUNC(RPG_Magic_Spell_DurationHelper(const RPG_Magic_Spell_DurationHelper&));
  ACE_UNIMPLEMENTED_FUNC(RPG_Magic_Spell_DurationHelper& operator=(const RPG_Magic_Spell_DurationHelper&));
};

#endif
