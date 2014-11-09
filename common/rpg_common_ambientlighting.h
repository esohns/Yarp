
// -------------------------------- * * * ----------------------------------- //
// PLEASE NOTE: this file was/is generated by XML2CppCode 0.1
// -------------------------------- * * * ----------------------------------- //

#pragma once
#ifndef RPG_COMMON_AMBIENTLIGHTING_H
#define RPG_COMMON_AMBIENTLIGHTING_H

enum RPG_Common_AmbientLighting
{
  AMBIENCE_BRIGHT = 0,
  AMBIENCE_SHADOWY,
  AMBIENCE_DARKNESS,
  //
  RPG_COMMON_AMBIENTLIGHTING_MAX,
  RPG_COMMON_AMBIENTLIGHTING_INVALID
};

#include "rpg_common_exports.h"

#include "ace/Global_Macros.h"

#include <map>
#include <string>

typedef std::map<RPG_Common_AmbientLighting, std::string> RPG_Common_AmbientLightingToStringTable_t;
typedef RPG_Common_AmbientLightingToStringTable_t::const_iterator RPG_Common_AmbientLightingToStringTableIterator_t;

class RPG_Common_Export RPG_Common_AmbientLightingHelper
{
 public:
  inline static void init()
  {
    myRPG_Common_AmbientLightingToStringTable.clear();
    myRPG_Common_AmbientLightingToStringTable.insert(std::make_pair(AMBIENCE_BRIGHT, ACE_TEXT_ALWAYS_CHAR("AMBIENCE_BRIGHT")));
    myRPG_Common_AmbientLightingToStringTable.insert(std::make_pair(AMBIENCE_SHADOWY, ACE_TEXT_ALWAYS_CHAR("AMBIENCE_SHADOWY")));
    myRPG_Common_AmbientLightingToStringTable.insert(std::make_pair(AMBIENCE_DARKNESS, ACE_TEXT_ALWAYS_CHAR("AMBIENCE_DARKNESS")));
  };

  inline static std::string RPG_Common_AmbientLightingToString(const RPG_Common_AmbientLighting& element_in)
  {
    std::string result;
    RPG_Common_AmbientLightingToStringTableIterator_t iterator = myRPG_Common_AmbientLightingToStringTable.find(element_in);
    if (iterator != myRPG_Common_AmbientLightingToStringTable.end())
      result = iterator->second;
    else
      result = ACE_TEXT_ALWAYS_CHAR("RPG_COMMON_AMBIENTLIGHTING_INVALID");

    return result;
  };

  inline static RPG_Common_AmbientLighting stringToRPG_Common_AmbientLighting(const std::string& string_in)
  {
    RPG_Common_AmbientLightingToStringTableIterator_t iterator = myRPG_Common_AmbientLightingToStringTable.begin();
    do
    {
      if (iterator->second == string_in)
        return iterator->first;

      iterator++;
    } while (iterator != myRPG_Common_AmbientLightingToStringTable.end());

    return RPG_COMMON_AMBIENTLIGHTING_INVALID;
  };

  static RPG_Common_AmbientLightingToStringTable_t myRPG_Common_AmbientLightingToStringTable;

 private:
  ACE_UNIMPLEMENTED_FUNC(RPG_Common_AmbientLightingHelper());
  ACE_UNIMPLEMENTED_FUNC(RPG_Common_AmbientLightingHelper(const RPG_Common_AmbientLightingHelper&));
  ACE_UNIMPLEMENTED_FUNC(RPG_Common_AmbientLightingHelper& operator=(const RPG_Common_AmbientLightingHelper&));
};

#endif
