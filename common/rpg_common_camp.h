
// -------------------------------- * * * ----------------------------------- //
// PLEASE NOTE: this file was/is generated by XML2CppCode 0.1
// -------------------------------- * * * ----------------------------------- //

#pragma once
#ifndef RPG_COMMON_CAMP_H
#define RPG_COMMON_CAMP_H

enum RPG_Common_Camp
{
  REST_FULL = 0,
  REST_NORMAL,
  //
  RPG_COMMON_CAMP_MAX,
  RPG_COMMON_CAMP_INVALID
};

#include "rpg_common_exports.h"

#include <ace/Global_Macros.h>

#include <map>
#include <string>

typedef std::map<RPG_Common_Camp, std::string> RPG_Common_CampToStringTable_t;
typedef RPG_Common_CampToStringTable_t::const_iterator RPG_Common_CampToStringTableIterator_t;

class RPG_Common_Export RPG_Common_CampHelper
{
 public:
  inline static void init()
  {
    myRPG_Common_CampToStringTable.clear();
    myRPG_Common_CampToStringTable.insert(std::make_pair(REST_FULL, ACE_TEXT_ALWAYS_CHAR("REST_FULL")));
    myRPG_Common_CampToStringTable.insert(std::make_pair(REST_NORMAL, ACE_TEXT_ALWAYS_CHAR("REST_NORMAL")));
  };

  inline static std::string RPG_Common_CampToString(const RPG_Common_Camp& element_in)
  {
    std::string result;
    RPG_Common_CampToStringTableIterator_t iterator = myRPG_Common_CampToStringTable.find(element_in);
    if (iterator != myRPG_Common_CampToStringTable.end())
      result = iterator->second;
    else
      result = ACE_TEXT_ALWAYS_CHAR("RPG_COMMON_CAMP_INVALID");

    return result;
  };

  inline static RPG_Common_Camp stringToRPG_Common_Camp(const std::string& string_in)
  {
    RPG_Common_CampToStringTableIterator_t iterator = myRPG_Common_CampToStringTable.begin();
    do
    {
      if (iterator->second == string_in)
        return iterator->first;

      iterator++;
    } while (iterator != myRPG_Common_CampToStringTable.end());

    return RPG_COMMON_CAMP_INVALID;
  };

  static RPG_Common_CampToStringTable_t myRPG_Common_CampToStringTable;

 private:
  ACE_UNIMPLEMENTED_FUNC(RPG_Common_CampHelper());
  ACE_UNIMPLEMENTED_FUNC(RPG_Common_CampHelper(const RPG_Common_CampHelper&));
  ACE_UNIMPLEMENTED_FUNC(RPG_Common_CampHelper& operator=(const RPG_Common_CampHelper&));
};

#endif
