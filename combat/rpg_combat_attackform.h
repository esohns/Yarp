
// -------------------------------- * * * ----------------------------------- //
// PLEASE NOTE: this file was/is generated by XML2CppCode 0.0.1-devel
// -------------------------------- * * * ----------------------------------- //

#ifndef RPG_COMBAT_ATTACKFORM_H
#define RPG_COMBAT_ATTACKFORM_H

enum RPG_Combat_AttackForm
{
  ATTACKFORM_MELEE = 0,
  ATTACKFORM_TOUCH,
  ATTACKFORM_RANGED,
  //
  RPG_COMBAT_ATTACKFORM_MAX,
  RPG_COMBAT_ATTACKFORM_INVALID
};

#include "ace/Global_Macros.h"

#include <map>
#include <string>

typedef std::map<RPG_Combat_AttackForm, std::string> RPG_Combat_AttackFormToStringTable_t;
typedef RPG_Combat_AttackFormToStringTable_t::const_iterator RPG_Combat_AttackFormToStringTableIterator_t;

class RPG_Combat_AttackFormHelper
{
 public:
  inline static void init()
  {
    myRPG_Combat_AttackFormToStringTable.clear();
    myRPG_Combat_AttackFormToStringTable.insert(std::make_pair(ATTACKFORM_MELEE, ACE_TEXT_ALWAYS_CHAR("ATTACKFORM_MELEE")));
    myRPG_Combat_AttackFormToStringTable.insert(std::make_pair(ATTACKFORM_TOUCH, ACE_TEXT_ALWAYS_CHAR("ATTACKFORM_TOUCH")));
    myRPG_Combat_AttackFormToStringTable.insert(std::make_pair(ATTACKFORM_RANGED, ACE_TEXT_ALWAYS_CHAR("ATTACKFORM_RANGED")));
  };

  inline static std::string RPG_Combat_AttackFormToString(const RPG_Combat_AttackForm& element_in)
  {
    std::string result;
    RPG_Combat_AttackFormToStringTableIterator_t iterator = myRPG_Combat_AttackFormToStringTable.find(element_in);
    if (iterator != myRPG_Combat_AttackFormToStringTable.end())
      result = iterator->second;
    else
      result = ACE_TEXT_ALWAYS_CHAR("RPG_COMBAT_ATTACKFORM_INVALID");

    return result;
  };

  inline static RPG_Combat_AttackForm stringToRPG_Combat_AttackForm(const std::string& string_in)
  {
    RPG_Combat_AttackFormToStringTableIterator_t iterator = myRPG_Combat_AttackFormToStringTable.begin();
    do
    {
      if (iterator->second == string_in)
        return iterator->first;

      iterator++;
    } while (iterator != myRPG_Combat_AttackFormToStringTable.end());

    return RPG_COMBAT_ATTACKFORM_INVALID;
  };

  static RPG_Combat_AttackFormToStringTable_t myRPG_Combat_AttackFormToStringTable;

 private:
  ACE_UNIMPLEMENTED_FUNC(RPG_Combat_AttackFormHelper());
  ACE_UNIMPLEMENTED_FUNC(RPG_Combat_AttackFormHelper(const RPG_Combat_AttackFormHelper&));
  ACE_UNIMPLEMENTED_FUNC(RPG_Combat_AttackFormHelper& operator=(const RPG_Combat_AttackFormHelper&));
};

#endif
