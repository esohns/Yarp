
// -------------------------------- * * * ----------------------------------- //
// PLEASE NOTE: this file was/is generated by // -------------------------------- * * * ----------------------------------- //

#pragma once
#ifndef RPG_MAGIC_SPELL_PRECONDITION_H
#define RPG_MAGIC_SPELL_PRECONDITION_H

enum RPG_Magic_Spell_Precondition
{
  PRECONDITION_ALLY = 0,
  PRECONDITION_ALIGNMENT,
  PRECONDITION_ATTACK_MELEE_ANY,
  PRECONDITION_ATTACK_MELEE_RANGED_TOUCH,
  PRECONDITION_ATTRIBUTE_MAX,
  PRECONDITION_CASTER_PLANE,
  PRECONDITION_CONDITION,
  PRECONDITION_ENVIRONMENT,
  PRECONDITION_HD_MAX,
  PRECONDITION_HD_MIN,
  PRECONDITION_IMMUNITY_POISON,
  PRECONDITION_SPELLLEVEL_MAX,
  PRECONDITION_MANUFACTURED,
  PRECONDITION_NONMAGICAL,
  PRECONDITION_OBJECT,
  PRECONDITION_SIGHTLESS,
  PRECONDITION_SIZE_MAX,
  PRECONDITION_SIZE_RELATIVE,
  PRECONDITION_TYPE,
  //
  RPG_MAGIC_SPELL_PRECONDITION_MAX,
  RPG_MAGIC_SPELL_PRECONDITION_INVALID
};

#include "ace/Global_Macros.h"

#include <map>
#include <string>

typedef std::map<RPG_Magic_Spell_Precondition, std::string> RPG_Magic_Spell_PreconditionToStringTable_t;
typedef RPG_Magic_Spell_PreconditionToStringTable_t::const_iterator RPG_Magic_Spell_PreconditionToStringTableIterator_t;

class RPG_Magic_Spell_PreconditionHelper
{
 public:
  inline static void init()
  {
    myRPG_Magic_Spell_PreconditionToStringTable.clear();
    myRPG_Magic_Spell_PreconditionToStringTable.insert(std::make_pair(PRECONDITION_ALLY, ACE_TEXT_ALWAYS_CHAR("PRECONDITION_ALLY")));
    myRPG_Magic_Spell_PreconditionToStringTable.insert(std::make_pair(PRECONDITION_ALIGNMENT, ACE_TEXT_ALWAYS_CHAR("PRECONDITION_ALIGNMENT")));
    myRPG_Magic_Spell_PreconditionToStringTable.insert(std::make_pair(PRECONDITION_ATTACK_MELEE_ANY, ACE_TEXT_ALWAYS_CHAR("PRECONDITION_ATTACK_MELEE_ANY")));
    myRPG_Magic_Spell_PreconditionToStringTable.insert(std::make_pair(PRECONDITION_ATTACK_MELEE_RANGED_TOUCH, ACE_TEXT_ALWAYS_CHAR("PRECONDITION_ATTACK_MELEE_RANGED_TOUCH")));
    myRPG_Magic_Spell_PreconditionToStringTable.insert(std::make_pair(PRECONDITION_ATTRIBUTE_MAX, ACE_TEXT_ALWAYS_CHAR("PRECONDITION_ATTRIBUTE_MAX")));
    myRPG_Magic_Spell_PreconditionToStringTable.insert(std::make_pair(PRECONDITION_CASTER_PLANE, ACE_TEXT_ALWAYS_CHAR("PRECONDITION_CASTER_PLANE")));
    myRPG_Magic_Spell_PreconditionToStringTable.insert(std::make_pair(PRECONDITION_CONDITION, ACE_TEXT_ALWAYS_CHAR("PRECONDITION_CONDITION")));
    myRPG_Magic_Spell_PreconditionToStringTable.insert(std::make_pair(PRECONDITION_ENVIRONMENT, ACE_TEXT_ALWAYS_CHAR("PRECONDITION_ENVIRONMENT")));
    myRPG_Magic_Spell_PreconditionToStringTable.insert(std::make_pair(PRECONDITION_HD_MAX, ACE_TEXT_ALWAYS_CHAR("PRECONDITION_HD_MAX")));
    myRPG_Magic_Spell_PreconditionToStringTable.insert(std::make_pair(PRECONDITION_HD_MIN, ACE_TEXT_ALWAYS_CHAR("PRECONDITION_HD_MIN")));
    myRPG_Magic_Spell_PreconditionToStringTable.insert(std::make_pair(PRECONDITION_IMMUNITY_POISON, ACE_TEXT_ALWAYS_CHAR("PRECONDITION_IMMUNITY_POISON")));
    myRPG_Magic_Spell_PreconditionToStringTable.insert(std::make_pair(PRECONDITION_SPELLLEVEL_MAX, ACE_TEXT_ALWAYS_CHAR("PRECONDITION_SPELLLEVEL_MAX")));
    myRPG_Magic_Spell_PreconditionToStringTable.insert(std::make_pair(PRECONDITION_MANUFACTURED, ACE_TEXT_ALWAYS_CHAR("PRECONDITION_MANUFACTURED")));
    myRPG_Magic_Spell_PreconditionToStringTable.insert(std::make_pair(PRECONDITION_NONMAGICAL, ACE_TEXT_ALWAYS_CHAR("PRECONDITION_NONMAGICAL")));
    myRPG_Magic_Spell_PreconditionToStringTable.insert(std::make_pair(PRECONDITION_OBJECT, ACE_TEXT_ALWAYS_CHAR("PRECONDITION_OBJECT")));
    myRPG_Magic_Spell_PreconditionToStringTable.insert(std::make_pair(PRECONDITION_SIGHTLESS, ACE_TEXT_ALWAYS_CHAR("PRECONDITION_SIGHTLESS")));
    myRPG_Magic_Spell_PreconditionToStringTable.insert(std::make_pair(PRECONDITION_SIZE_MAX, ACE_TEXT_ALWAYS_CHAR("PRECONDITION_SIZE_MAX")));
    myRPG_Magic_Spell_PreconditionToStringTable.insert(std::make_pair(PRECONDITION_SIZE_RELATIVE, ACE_TEXT_ALWAYS_CHAR("PRECONDITION_SIZE_RELATIVE")));
    myRPG_Magic_Spell_PreconditionToStringTable.insert(std::make_pair(PRECONDITION_TYPE, ACE_TEXT_ALWAYS_CHAR("PRECONDITION_TYPE")));
  };

  inline static std::string RPG_Magic_Spell_PreconditionToString(const RPG_Magic_Spell_Precondition& element_in)
  {
    std::string result;
    RPG_Magic_Spell_PreconditionToStringTableIterator_t iterator = myRPG_Magic_Spell_PreconditionToStringTable.find(element_in);
    if (iterator != myRPG_Magic_Spell_PreconditionToStringTable.end())
      result = iterator->second;
    else
      result = ACE_TEXT_ALWAYS_CHAR("RPG_MAGIC_SPELL_PRECONDITION_INVALID");

    return result;
  };

  inline static RPG_Magic_Spell_Precondition stringToRPG_Magic_Spell_Precondition(const std::string& string_in)
  {
    RPG_Magic_Spell_PreconditionToStringTableIterator_t iterator = myRPG_Magic_Spell_PreconditionToStringTable.begin();
    do
    {
      if (iterator->second == string_in)
        return iterator->first;

      iterator++;
    } while (iterator != myRPG_Magic_Spell_PreconditionToStringTable.end());

    return RPG_MAGIC_SPELL_PRECONDITION_INVALID;
  };

  static RPG_Magic_Spell_PreconditionToStringTable_t myRPG_Magic_Spell_PreconditionToStringTable;

 private:
  ACE_UNIMPLEMENTED_FUNC(RPG_Magic_Spell_PreconditionHelper());
  ACE_UNIMPLEMENTED_FUNC(RPG_Magic_Spell_PreconditionHelper(const RPG_Magic_Spell_PreconditionHelper&));
  ACE_UNIMPLEMENTED_FUNC(RPG_Magic_Spell_PreconditionHelper& operator=(const RPG_Magic_Spell_PreconditionHelper&));
};

#endif
