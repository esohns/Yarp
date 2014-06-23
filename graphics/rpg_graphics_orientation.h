
// -------------------------------- * * * ----------------------------------- //
// PLEASE NOTE: this file was/is generated by XML2CppCode 0.1
// -------------------------------- * * * ----------------------------------- //

#pragma once
#ifndef RPG_GRAPHICS_ORIENTATION_H
#define RPG_GRAPHICS_ORIENTATION_H

enum RPG_Graphics_Orientation
{
  ORIENTATION_NORTH = 0,
  ORIENTATION_NORTH_EAST,
  ORIENTATION_NORTH_WEST,
  ORIENTATION_SOUTH,
  ORIENTATION_SOUTH_EAST,
  ORIENTATION_SOUTH_WEST,
  ORIENTATION_WEST,
  ORIENTATION_EAST,
  ORIENTATION_HORIZONTAL,
  ORIENTATION_VERTICAL,
  //
  RPG_GRAPHICS_ORIENTATION_MAX,
  RPG_GRAPHICS_ORIENTATION_INVALID
};

#include "rpg_graphics_exports.h"

#include <ace/Global_Macros.h>

#include <map>
#include <string>

typedef std::map<RPG_Graphics_Orientation, std::string> RPG_Graphics_OrientationToStringTable_t;
typedef RPG_Graphics_OrientationToStringTable_t::const_iterator RPG_Graphics_OrientationToStringTableIterator_t;

class RPG_Graphics_Export RPG_Graphics_OrientationHelper
{
 public:
  inline static void init()
  {
    myRPG_Graphics_OrientationToStringTable.clear();
    myRPG_Graphics_OrientationToStringTable.insert(std::make_pair(ORIENTATION_NORTH, ACE_TEXT_ALWAYS_CHAR("ORIENTATION_NORTH")));
    myRPG_Graphics_OrientationToStringTable.insert(std::make_pair(ORIENTATION_NORTH_EAST, ACE_TEXT_ALWAYS_CHAR("ORIENTATION_NORTH_EAST")));
    myRPG_Graphics_OrientationToStringTable.insert(std::make_pair(ORIENTATION_NORTH_WEST, ACE_TEXT_ALWAYS_CHAR("ORIENTATION_NORTH_WEST")));
    myRPG_Graphics_OrientationToStringTable.insert(std::make_pair(ORIENTATION_SOUTH, ACE_TEXT_ALWAYS_CHAR("ORIENTATION_SOUTH")));
    myRPG_Graphics_OrientationToStringTable.insert(std::make_pair(ORIENTATION_SOUTH_EAST, ACE_TEXT_ALWAYS_CHAR("ORIENTATION_SOUTH_EAST")));
    myRPG_Graphics_OrientationToStringTable.insert(std::make_pair(ORIENTATION_SOUTH_WEST, ACE_TEXT_ALWAYS_CHAR("ORIENTATION_SOUTH_WEST")));
    myRPG_Graphics_OrientationToStringTable.insert(std::make_pair(ORIENTATION_WEST, ACE_TEXT_ALWAYS_CHAR("ORIENTATION_WEST")));
    myRPG_Graphics_OrientationToStringTable.insert(std::make_pair(ORIENTATION_EAST, ACE_TEXT_ALWAYS_CHAR("ORIENTATION_EAST")));
    myRPG_Graphics_OrientationToStringTable.insert(std::make_pair(ORIENTATION_HORIZONTAL, ACE_TEXT_ALWAYS_CHAR("ORIENTATION_HORIZONTAL")));
    myRPG_Graphics_OrientationToStringTable.insert(std::make_pair(ORIENTATION_VERTICAL, ACE_TEXT_ALWAYS_CHAR("ORIENTATION_VERTICAL")));
  };

  inline static std::string RPG_Graphics_OrientationToString(const RPG_Graphics_Orientation& element_in)
  {
    std::string result;
    RPG_Graphics_OrientationToStringTableIterator_t iterator = myRPG_Graphics_OrientationToStringTable.find(element_in);
    if (iterator != myRPG_Graphics_OrientationToStringTable.end())
      result = iterator->second;
    else
      result = ACE_TEXT_ALWAYS_CHAR("RPG_GRAPHICS_ORIENTATION_INVALID");

    return result;
  };

  inline static RPG_Graphics_Orientation stringToRPG_Graphics_Orientation(const std::string& string_in)
  {
    RPG_Graphics_OrientationToStringTableIterator_t iterator = myRPG_Graphics_OrientationToStringTable.begin();
    do
    {
      if (iterator->second == string_in)
        return iterator->first;

      iterator++;
    } while (iterator != myRPG_Graphics_OrientationToStringTable.end());

    return RPG_GRAPHICS_ORIENTATION_INVALID;
  };

  static RPG_Graphics_OrientationToStringTable_t myRPG_Graphics_OrientationToStringTable;

 private:
  ACE_UNIMPLEMENTED_FUNC(RPG_Graphics_OrientationHelper());
  ACE_UNIMPLEMENTED_FUNC(RPG_Graphics_OrientationHelper(const RPG_Graphics_OrientationHelper&));
  ACE_UNIMPLEMENTED_FUNC(RPG_Graphics_OrientationHelper& operator=(const RPG_Graphics_OrientationHelper&));
};

#endif
