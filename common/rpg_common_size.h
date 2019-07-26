
// -------------------------------- * * * ----------------------------------- //
// PLEASE NOTE: this file was/is generated by // -------------------------------- * * * ----------------------------------- //

#pragma once
#ifndef RPG_COMMON_SIZE_H
#define RPG_COMMON_SIZE_H

enum RPG_Common_Size
{
  SIZE_FINE = 0,
  SIZE_DIMINUTIVE,
  SIZE_TINY,
  SIZE_SMALL,
  SIZE_MEDIUM,
  SIZE_LARGE,
  SIZE_HUGE,
  SIZE_GARGANTUAN,
  SIZE_COLOSSAL,
  //
  RPG_COMMON_SIZE_MAX,
  RPG_COMMON_SIZE_INVALID
};

#include "rpg_common_exports.h"

#include "ace/Global_Macros.h"

#include <map>
#include <string>

typedef std::map<RPG_Common_Size, std::string> RPG_Common_SizeToStringTable_t;
typedef RPG_Common_SizeToStringTable_t::const_iterator RPG_Common_SizeToStringTableIterator_t;

class RPG_Common_Export RPG_Common_SizeHelper
{
 public:
  inline static void init()
  {
    myRPG_Common_SizeToStringTable.clear();
    myRPG_Common_SizeToStringTable.insert(std::make_pair(SIZE_FINE, ACE_TEXT_ALWAYS_CHAR("SIZE_FINE")));
    myRPG_Common_SizeToStringTable.insert(std::make_pair(SIZE_DIMINUTIVE, ACE_TEXT_ALWAYS_CHAR("SIZE_DIMINUTIVE")));
    myRPG_Common_SizeToStringTable.insert(std::make_pair(SIZE_TINY, ACE_TEXT_ALWAYS_CHAR("SIZE_TINY")));
    myRPG_Common_SizeToStringTable.insert(std::make_pair(SIZE_SMALL, ACE_TEXT_ALWAYS_CHAR("SIZE_SMALL")));
    myRPG_Common_SizeToStringTable.insert(std::make_pair(SIZE_MEDIUM, ACE_TEXT_ALWAYS_CHAR("SIZE_MEDIUM")));
    myRPG_Common_SizeToStringTable.insert(std::make_pair(SIZE_LARGE, ACE_TEXT_ALWAYS_CHAR("SIZE_LARGE")));
    myRPG_Common_SizeToStringTable.insert(std::make_pair(SIZE_HUGE, ACE_TEXT_ALWAYS_CHAR("SIZE_HUGE")));
    myRPG_Common_SizeToStringTable.insert(std::make_pair(SIZE_GARGANTUAN, ACE_TEXT_ALWAYS_CHAR("SIZE_GARGANTUAN")));
    myRPG_Common_SizeToStringTable.insert(std::make_pair(SIZE_COLOSSAL, ACE_TEXT_ALWAYS_CHAR("SIZE_COLOSSAL")));
  };

  inline static std::string RPG_Common_SizeToString(const RPG_Common_Size& element_in)
  {
    std::string result;
    RPG_Common_SizeToStringTableIterator_t iterator = myRPG_Common_SizeToStringTable.find(element_in);
    if (iterator != myRPG_Common_SizeToStringTable.end())
      result = iterator->second;
    else
      result = ACE_TEXT_ALWAYS_CHAR("RPG_COMMON_SIZE_INVALID");

    return result;
  };

  inline static RPG_Common_Size stringToRPG_Common_Size(const std::string& string_in)
  {
    RPG_Common_SizeToStringTableIterator_t iterator = myRPG_Common_SizeToStringTable.begin();
    do
    {
      if (iterator->second == string_in)
        return iterator->first;

      iterator++;
    } while (iterator != myRPG_Common_SizeToStringTable.end());

    return RPG_COMMON_SIZE_INVALID;
  };

  static RPG_Common_SizeToStringTable_t myRPG_Common_SizeToStringTable;

 private:
  ACE_UNIMPLEMENTED_FUNC(RPG_Common_SizeHelper());
  ACE_UNIMPLEMENTED_FUNC(RPG_Common_SizeHelper(const RPG_Common_SizeHelper&));
  ACE_UNIMPLEMENTED_FUNC(RPG_Common_SizeHelper& operator=(const RPG_Common_SizeHelper&));
};

#endif
