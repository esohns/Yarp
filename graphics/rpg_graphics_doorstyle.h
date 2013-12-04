
// -------------------------------- * * * -------------------------------- //
// PLEASE NOTE: this file was/is generated by XML2CppCode 0.1
// -------------------------------- * * * -------------------------------- //

#pragma once
#ifndef RPG_GRAPHICS_DOORSTYLE_H
#define RPG_GRAPHICS_DOORSTYLE_H

enum RPG_Graphics_DoorStyle
{
  DOORSTYLE_DRAWBRIDGE = 0,
  DOORSTYLE_TELEPORTER,
  DOORSTYLE_WOOD,
  //
  RPG_GRAPHICS_DOORSTYLE_MAX,
  RPG_GRAPHICS_DOORSTYLE_INVALID
};

#include "rpg_graphics_exports.h"

#include <ace/Global_Macros.h>

#include <map>
#include <string>

typedef std::map<RPG_Graphics_DoorStyle, std::string> RPG_Graphics_DoorStyleToStringTable_t;
typedef RPG_Graphics_DoorStyleToStringTable_t::const_iterator RPG_Graphics_DoorStyleToStringTableIterator_t;

class RPG_Graphics_Export RPG_Graphics_DoorStyleHelper
{
 public:
  inline static void init()
  {
    myRPG_Graphics_DoorStyleToStringTable.clear();
    myRPG_Graphics_DoorStyleToStringTable.insert(std::make_pair(DOORSTYLE_DRAWBRIDGE, ACE_TEXT_ALWAYS_CHAR("DOORSTYLE_DRAWBRIDGE")));
    myRPG_Graphics_DoorStyleToStringTable.insert(std::make_pair(DOORSTYLE_TELEPORTER, ACE_TEXT_ALWAYS_CHAR("DOORSTYLE_TELEPORTER")));
    myRPG_Graphics_DoorStyleToStringTable.insert(std::make_pair(DOORSTYLE_WOOD, ACE_TEXT_ALWAYS_CHAR("DOORSTYLE_WOOD")));
  };

  inline static std::string RPG_Graphics_DoorStyleToString(const RPG_Graphics_DoorStyle& element_in)
  {
    std::string result;
    RPG_Graphics_DoorStyleToStringTableIterator_t iterator = myRPG_Graphics_DoorStyleToStringTable.find(element_in);
    if (iterator != myRPG_Graphics_DoorStyleToStringTable.end())
      result = iterator->second;
    else
      result = ACE_TEXT_ALWAYS_CHAR("RPG_GRAPHICS_DOORSTYLE_INVALID");

    return result;
  };

  inline static RPG_Graphics_DoorStyle stringToRPG_Graphics_DoorStyle(const std::string& string_in)
  {
    RPG_Graphics_DoorStyleToStringTableIterator_t iterator = myRPG_Graphics_DoorStyleToStringTable.begin();
    do
    {
      if (iterator->second == string_in)
        return iterator->first;

      iterator++;
    } while (iterator != myRPG_Graphics_DoorStyleToStringTable.end());

    return RPG_GRAPHICS_DOORSTYLE_INVALID;
  };

  static RPG_Graphics_DoorStyleToStringTable_t myRPG_Graphics_DoorStyleToStringTable;

 private:
  ACE_UNIMPLEMENTED_FUNC(RPG_Graphics_DoorStyleHelper());
  ACE_UNIMPLEMENTED_FUNC(RPG_Graphics_DoorStyleHelper(const RPG_Graphics_DoorStyleHelper&));
  ACE_UNIMPLEMENTED_FUNC(RPG_Graphics_DoorStyleHelper& operator=(const RPG_Graphics_DoorStyleHelper&));
};

#endif
