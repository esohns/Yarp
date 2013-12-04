
// -------------------------------- * * * -------------------------------- //
// PLEASE NOTE: this file was/is generated by XML2CppCode 0.1
// -------------------------------- * * * -------------------------------- //

#pragma once
#ifndef RPG_COMMON_SAVEREDUCTIONTYPE_H
#define RPG_COMMON_SAVEREDUCTIONTYPE_H

enum RPG_Common_SaveReductionType
{
  SAVEREDUCTION_HALF = 0,
  SAVEREDUCTION_NEGATES,
  SAVEREDUCTION_PARTIAL,
  //
  RPG_COMMON_SAVEREDUCTIONTYPE_MAX,
  RPG_COMMON_SAVEREDUCTIONTYPE_INVALID
};

#include "rpg_common_exports.h"

#include <ace/Global_Macros.h>

#include <map>
#include <string>

typedef std::map<RPG_Common_SaveReductionType, std::string> RPG_Common_SaveReductionTypeToStringTable_t;
typedef RPG_Common_SaveReductionTypeToStringTable_t::const_iterator RPG_Common_SaveReductionTypeToStringTableIterator_t;

class RPG_Common_Export RPG_Common_SaveReductionTypeHelper
{
 public:
  inline static void init()
  {
    myRPG_Common_SaveReductionTypeToStringTable.clear();
    myRPG_Common_SaveReductionTypeToStringTable.insert(std::make_pair(SAVEREDUCTION_HALF, ACE_TEXT_ALWAYS_CHAR("SAVEREDUCTION_HALF")));
    myRPG_Common_SaveReductionTypeToStringTable.insert(std::make_pair(SAVEREDUCTION_NEGATES, ACE_TEXT_ALWAYS_CHAR("SAVEREDUCTION_NEGATES")));
    myRPG_Common_SaveReductionTypeToStringTable.insert(std::make_pair(SAVEREDUCTION_PARTIAL, ACE_TEXT_ALWAYS_CHAR("SAVEREDUCTION_PARTIAL")));
  };

  inline static std::string RPG_Common_SaveReductionTypeToString(const RPG_Common_SaveReductionType& element_in)
  {
    std::string result;
    RPG_Common_SaveReductionTypeToStringTableIterator_t iterator = myRPG_Common_SaveReductionTypeToStringTable.find(element_in);
    if (iterator != myRPG_Common_SaveReductionTypeToStringTable.end())
      result = iterator->second;
    else
      result = ACE_TEXT_ALWAYS_CHAR("RPG_COMMON_SAVEREDUCTIONTYPE_INVALID");

    return result;
  };

  inline static RPG_Common_SaveReductionType stringToRPG_Common_SaveReductionType(const std::string& string_in)
  {
    RPG_Common_SaveReductionTypeToStringTableIterator_t iterator = myRPG_Common_SaveReductionTypeToStringTable.begin();
    do
    {
      if (iterator->second == string_in)
        return iterator->first;

      iterator++;
    } while (iterator != myRPG_Common_SaveReductionTypeToStringTable.end());

    return RPG_COMMON_SAVEREDUCTIONTYPE_INVALID;
  };

  static RPG_Common_SaveReductionTypeToStringTable_t myRPG_Common_SaveReductionTypeToStringTable;

 private:
  ACE_UNIMPLEMENTED_FUNC(RPG_Common_SaveReductionTypeHelper());
  ACE_UNIMPLEMENTED_FUNC(RPG_Common_SaveReductionTypeHelper(const RPG_Common_SaveReductionTypeHelper&));
  ACE_UNIMPLEMENTED_FUNC(RPG_Common_SaveReductionTypeHelper& operator=(const RPG_Common_SaveReductionTypeHelper&));
};

#endif
