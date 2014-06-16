
// -------------------------------- * * * ----------------------------------- //
// PLEASE NOTE: this file was/is generated by XML2CppCode 0.1
// -------------------------------- * * * ----------------------------------- //

#pragma once
#ifndef RPG_COMBAT_SPECIALATTACK_H
#define RPG_COMBAT_SPECIALATTACK_H

enum RPG_Combat_SpecialAttack
{
  SPECIALATTACK_INCORPOREAL_TOUCH = 0,
  SPECIALATTACK_SMITE,
  //
  RPG_COMBAT_SPECIALATTACK_MAX,
  RPG_COMBAT_SPECIALATTACK_INVALID
};

#include "rpg_combat_exports.h"

#include <ace/Global_Macros.h>

#include <map>
#include <string>

typedef std::map<RPG_Combat_SpecialAttack, std::string> RPG_Combat_SpecialAttackToStringTable_t;
typedef RPG_Combat_SpecialAttackToStringTable_t::const_iterator RPG_Combat_SpecialAttackToStringTableIterator_t;

class RPG_Combat_Export RPG_Combat_SpecialAttackHelper
{
 public:
  inline static void init()
  {
    myRPG_Combat_SpecialAttackToStringTable.clear();
    myRPG_Combat_SpecialAttackToStringTable.insert(std::make_pair(SPECIALATTACK_INCORPOREAL_TOUCH, ACE_TEXT_ALWAYS_CHAR("SPECIALATTACK_INCORPOREAL_TOUCH")));
    myRPG_Combat_SpecialAttackToStringTable.insert(std::make_pair(SPECIALATTACK_SMITE, ACE_TEXT_ALWAYS_CHAR("SPECIALATTACK_SMITE")));
  };

  inline static std::string RPG_Combat_SpecialAttackToString(const RPG_Combat_SpecialAttack& element_in)
  {
    std::string result;
    RPG_Combat_SpecialAttackToStringTableIterator_t iterator = myRPG_Combat_SpecialAttackToStringTable.find(element_in);
    if (iterator != myRPG_Combat_SpecialAttackToStringTable.end())
      result = iterator->second;
    else
      result = ACE_TEXT_ALWAYS_CHAR("RPG_COMBAT_SPECIALATTACK_INVALID");

    return result;
  };

  inline static RPG_Combat_SpecialAttack stringToRPG_Combat_SpecialAttack(const std::string& string_in)
  {
    RPG_Combat_SpecialAttackToStringTableIterator_t iterator = myRPG_Combat_SpecialAttackToStringTable.begin();
    do
    {
      if (iterator->second == string_in)
        return iterator->first;

      iterator++;
    } while (iterator != myRPG_Combat_SpecialAttackToStringTable.end());

    return RPG_COMBAT_SPECIALATTACK_INVALID;
  };

  static RPG_Combat_SpecialAttackToStringTable_t myRPG_Combat_SpecialAttackToStringTable;

 private:
  ACE_UNIMPLEMENTED_FUNC(RPG_Combat_SpecialAttackHelper());
  ACE_UNIMPLEMENTED_FUNC(RPG_Combat_SpecialAttackHelper(const RPG_Combat_SpecialAttackHelper&));
  ACE_UNIMPLEMENTED_FUNC(RPG_Combat_SpecialAttackHelper& operator=(const RPG_Combat_SpecialAttackHelper&));
};

#endif
