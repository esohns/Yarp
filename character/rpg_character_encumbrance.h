
// -------------------------------- * * * ----------------------------------- //
// PLEASE NOTE: this file was/is generated by XML2CppCode 0.0.1-devel
// -------------------------------- * * * ----------------------------------- //

#ifndef RPG_CHARACTER_ENCUMBRANCE_H
#define RPG_CHARACTER_ENCUMBRANCE_H

enum RPG_Character_Encumbrance
{
  LOAD_LIGHT = 0,
  LOAD_MEDIUM,
  LOAD_HEAVY,
  //
  RPG_CHARACTER_ENCUMBRANCE_MAX,
  RPG_CHARACTER_ENCUMBRANCE_INVALID
};

#include "ace/Global_Macros.h"

#include <map>
#include <string>

typedef std::map<RPG_Character_Encumbrance, std::string> RPG_Character_EncumbranceToStringTable_t;
typedef RPG_Character_EncumbranceToStringTable_t::const_iterator RPG_Character_EncumbranceToStringTableIterator_t;

class RPG_Character_EncumbranceHelper
{
 public:
  inline static void init()
  {
    myRPG_Character_EncumbranceToStringTable.clear();
    myRPG_Character_EncumbranceToStringTable.insert(std::make_pair(LOAD_LIGHT, ACE_TEXT_ALWAYS_CHAR("LOAD_LIGHT")));
    myRPG_Character_EncumbranceToStringTable.insert(std::make_pair(LOAD_MEDIUM, ACE_TEXT_ALWAYS_CHAR("LOAD_MEDIUM")));
    myRPG_Character_EncumbranceToStringTable.insert(std::make_pair(LOAD_HEAVY, ACE_TEXT_ALWAYS_CHAR("LOAD_HEAVY")));
  };

  inline static std::string RPG_Character_EncumbranceToString(const RPG_Character_Encumbrance& element_in)
  {
    std::string result;
    RPG_Character_EncumbranceToStringTableIterator_t iterator = myRPG_Character_EncumbranceToStringTable.find(element_in);
    if (iterator != myRPG_Character_EncumbranceToStringTable.end())
      result = iterator->second;
    else
      result = ACE_TEXT_ALWAYS_CHAR("RPG_CHARACTER_ENCUMBRANCE_INVALID");

    return result;
  };

  inline static RPG_Character_Encumbrance stringToRPG_Character_Encumbrance(const std::string& string_in)
  {
    RPG_Character_EncumbranceToStringTableIterator_t iterator = myRPG_Character_EncumbranceToStringTable.begin();
    do
    {
      if (iterator->second == string_in)
        return iterator->first;

      iterator++;
    } while (iterator != myRPG_Character_EncumbranceToStringTable.end());

    return RPG_CHARACTER_ENCUMBRANCE_INVALID;
  };

  static RPG_Character_EncumbranceToStringTable_t myRPG_Character_EncumbranceToStringTable;

 private:
  ACE_UNIMPLEMENTED_FUNC(RPG_Character_EncumbranceHelper());
  ACE_UNIMPLEMENTED_FUNC(RPG_Character_EncumbranceHelper(const RPG_Character_EncumbranceHelper&));
  ACE_UNIMPLEMENTED_FUNC(RPG_Character_EncumbranceHelper& operator=(const RPG_Character_EncumbranceHelper&));
};

#endif
