
// -------------------------------- * * * -------------------------------- //
// PLEASE NOTE: this file was/is generated by XML2CppCode 0.1
// -------------------------------- * * * -------------------------------- //

#pragma once
#ifndef RPG_GRAPHICS_EDGESTYLE_H
#define RPG_GRAPHICS_EDGESTYLE_H

enum RPG_Graphics_EdgeStyle
{
  EDGESTYLE_FLOOR_STONE_COBBLED = 0,
  //
  RPG_GRAPHICS_EDGESTYLE_MAX,
  RPG_GRAPHICS_EDGESTYLE_INVALID
};

#include "rpg_graphics_exports.h"

#include <ace/Global_Macros.h>

#include <map>
#include <string>

typedef std::map<RPG_Graphics_EdgeStyle, std::string> RPG_Graphics_EdgeStyleToStringTable_t;
typedef RPG_Graphics_EdgeStyleToStringTable_t::const_iterator RPG_Graphics_EdgeStyleToStringTableIterator_t;

class RPG_Graphics_Export RPG_Graphics_EdgeStyleHelper
{
 public:
  inline static void init()
  {
    myRPG_Graphics_EdgeStyleToStringTable.clear();
    myRPG_Graphics_EdgeStyleToStringTable.insert(std::make_pair(EDGESTYLE_FLOOR_STONE_COBBLED, ACE_TEXT_ALWAYS_CHAR("EDGESTYLE_FLOOR_STONE_COBBLED")));
  };

  inline static std::string RPG_Graphics_EdgeStyleToString(const RPG_Graphics_EdgeStyle& element_in)
  {
    std::string result;
    RPG_Graphics_EdgeStyleToStringTableIterator_t iterator = myRPG_Graphics_EdgeStyleToStringTable.find(element_in);
    if (iterator != myRPG_Graphics_EdgeStyleToStringTable.end())
      result = iterator->second;
    else
      result = ACE_TEXT_ALWAYS_CHAR("RPG_GRAPHICS_EDGESTYLE_INVALID");

    return result;
  };

  inline static RPG_Graphics_EdgeStyle stringToRPG_Graphics_EdgeStyle(const std::string& string_in)
  {
    RPG_Graphics_EdgeStyleToStringTableIterator_t iterator = myRPG_Graphics_EdgeStyleToStringTable.begin();
    do
    {
      if (iterator->second == string_in)
        return iterator->first;

      iterator++;
    } while (iterator != myRPG_Graphics_EdgeStyleToStringTable.end());

    return RPG_GRAPHICS_EDGESTYLE_INVALID;
  };

  static RPG_Graphics_EdgeStyleToStringTable_t myRPG_Graphics_EdgeStyleToStringTable;

 private:
  ACE_UNIMPLEMENTED_FUNC(RPG_Graphics_EdgeStyleHelper());
  ACE_UNIMPLEMENTED_FUNC(RPG_Graphics_EdgeStyleHelper(const RPG_Graphics_EdgeStyleHelper&));
  ACE_UNIMPLEMENTED_FUNC(RPG_Graphics_EdgeStyleHelper& operator=(const RPG_Graphics_EdgeStyleHelper&));
};

#endif
