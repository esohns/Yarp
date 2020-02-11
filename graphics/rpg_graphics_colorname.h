
// -------------------------------- * * * ----------------------------------- //
// PLEASE NOTE: this file was/is generated by // -------------------------------- * * * ----------------------------------- //

#pragma once
#ifndef RPG_GRAPHICS_COLORNAME_H
#define RPG_GRAPHICS_COLORNAME_H

enum RPG_Graphics_ColorName
{
  COLOR_BLACK_A0 = 0,
  COLOR_BLACK_A10,
  COLOR_BLACK_A30,
  COLOR_BLACK_A50,
  COLOR_BLACK_A70,
  COLOR_BLACK_A90,
  COLOR_BLACK,
  COLOR_GREEN,
  COLOR_YELLOW,
  COLOR_ORANGE,
  COLOR_RED,
  COLOR_GRAY20,
  COLOR_GRAY20_A10,
  COLOR_GRAY70,
  COLOR_GRAY77,
  COLOR_PURPLE44,
  COLOR_LIGHTPINK,
  COLOR_LIGHTGREEN,
  COLOR_BROWN,
  COLOR_WHITE,
  COLOR_BLESS_BLUE,
  COLOR_CURSE_RED,
  COLOR_GOLD_SHADE,
  //
  RPG_GRAPHICS_COLORNAME_MAX,
  RPG_GRAPHICS_COLORNAME_INVALID
};

#include "ace/Global_Macros.h"

#include <map>
#include <string>

typedef std::map<RPG_Graphics_ColorName, std::string> RPG_Graphics_ColorNameToStringTable_t;
typedef RPG_Graphics_ColorNameToStringTable_t::const_iterator RPG_Graphics_ColorNameToStringTableIterator_t;

class RPG_Graphics_ColorNameHelper
{
 public:
  inline static void init()
  {
    myRPG_Graphics_ColorNameToStringTable.clear();
    myRPG_Graphics_ColorNameToStringTable.insert(std::make_pair(COLOR_BLACK_A0, ACE_TEXT_ALWAYS_CHAR("COLOR_BLACK_A0")));
    myRPG_Graphics_ColorNameToStringTable.insert(std::make_pair(COLOR_BLACK_A10, ACE_TEXT_ALWAYS_CHAR("COLOR_BLACK_A10")));
    myRPG_Graphics_ColorNameToStringTable.insert(std::make_pair(COLOR_BLACK_A30, ACE_TEXT_ALWAYS_CHAR("COLOR_BLACK_A30")));
    myRPG_Graphics_ColorNameToStringTable.insert(std::make_pair(COLOR_BLACK_A50, ACE_TEXT_ALWAYS_CHAR("COLOR_BLACK_A50")));
    myRPG_Graphics_ColorNameToStringTable.insert(std::make_pair(COLOR_BLACK_A70, ACE_TEXT_ALWAYS_CHAR("COLOR_BLACK_A70")));
    myRPG_Graphics_ColorNameToStringTable.insert(std::make_pair(COLOR_BLACK_A90, ACE_TEXT_ALWAYS_CHAR("COLOR_BLACK_A90")));
    myRPG_Graphics_ColorNameToStringTable.insert(std::make_pair(COLOR_BLACK, ACE_TEXT_ALWAYS_CHAR("COLOR_BLACK")));
    myRPG_Graphics_ColorNameToStringTable.insert(std::make_pair(COLOR_GREEN, ACE_TEXT_ALWAYS_CHAR("COLOR_GREEN")));
    myRPG_Graphics_ColorNameToStringTable.insert(std::make_pair(COLOR_YELLOW, ACE_TEXT_ALWAYS_CHAR("COLOR_YELLOW")));
    myRPG_Graphics_ColorNameToStringTable.insert(std::make_pair(COLOR_ORANGE, ACE_TEXT_ALWAYS_CHAR("COLOR_ORANGE")));
    myRPG_Graphics_ColorNameToStringTable.insert(std::make_pair(COLOR_RED, ACE_TEXT_ALWAYS_CHAR("COLOR_RED")));
    myRPG_Graphics_ColorNameToStringTable.insert(std::make_pair(COLOR_GRAY20, ACE_TEXT_ALWAYS_CHAR("COLOR_GRAY20")));
    myRPG_Graphics_ColorNameToStringTable.insert(std::make_pair(COLOR_GRAY20_A10, ACE_TEXT_ALWAYS_CHAR("COLOR_GRAY20_A10")));
    myRPG_Graphics_ColorNameToStringTable.insert(std::make_pair(COLOR_GRAY70, ACE_TEXT_ALWAYS_CHAR("COLOR_GRAY70")));
    myRPG_Graphics_ColorNameToStringTable.insert(std::make_pair(COLOR_GRAY77, ACE_TEXT_ALWAYS_CHAR("COLOR_GRAY77")));
    myRPG_Graphics_ColorNameToStringTable.insert(std::make_pair(COLOR_PURPLE44, ACE_TEXT_ALWAYS_CHAR("COLOR_PURPLE44")));
    myRPG_Graphics_ColorNameToStringTable.insert(std::make_pair(COLOR_LIGHTPINK, ACE_TEXT_ALWAYS_CHAR("COLOR_LIGHTPINK")));
    myRPG_Graphics_ColorNameToStringTable.insert(std::make_pair(COLOR_LIGHTGREEN, ACE_TEXT_ALWAYS_CHAR("COLOR_LIGHTGREEN")));
    myRPG_Graphics_ColorNameToStringTable.insert(std::make_pair(COLOR_BROWN, ACE_TEXT_ALWAYS_CHAR("COLOR_BROWN")));
    myRPG_Graphics_ColorNameToStringTable.insert(std::make_pair(COLOR_WHITE, ACE_TEXT_ALWAYS_CHAR("COLOR_WHITE")));
    myRPG_Graphics_ColorNameToStringTable.insert(std::make_pair(COLOR_BLESS_BLUE, ACE_TEXT_ALWAYS_CHAR("COLOR_BLESS_BLUE")));
    myRPG_Graphics_ColorNameToStringTable.insert(std::make_pair(COLOR_CURSE_RED, ACE_TEXT_ALWAYS_CHAR("COLOR_CURSE_RED")));
    myRPG_Graphics_ColorNameToStringTable.insert(std::make_pair(COLOR_GOLD_SHADE, ACE_TEXT_ALWAYS_CHAR("COLOR_GOLD_SHADE")));
  };

  inline static std::string RPG_Graphics_ColorNameToString(const RPG_Graphics_ColorName& element_in)
  {
    std::string result;
    RPG_Graphics_ColorNameToStringTableIterator_t iterator = myRPG_Graphics_ColorNameToStringTable.find(element_in);
    if (iterator != myRPG_Graphics_ColorNameToStringTable.end())
      result = iterator->second;
    else
      result = ACE_TEXT_ALWAYS_CHAR("RPG_GRAPHICS_COLORNAME_INVALID");

    return result;
  };

  inline static RPG_Graphics_ColorName stringToRPG_Graphics_ColorName(const std::string& string_in)
  {
    RPG_Graphics_ColorNameToStringTableIterator_t iterator = myRPG_Graphics_ColorNameToStringTable.begin();
    do
    {
      if (iterator->second == string_in)
        return iterator->first;

      iterator++;
    } while (iterator != myRPG_Graphics_ColorNameToStringTable.end());

    return RPG_GRAPHICS_COLORNAME_INVALID;
  };

  static RPG_Graphics_ColorNameToStringTable_t myRPG_Graphics_ColorNameToStringTable;

 private:
  ACE_UNIMPLEMENTED_FUNC(RPG_Graphics_ColorNameHelper());
  ACE_UNIMPLEMENTED_FUNC(RPG_Graphics_ColorNameHelper(const RPG_Graphics_ColorNameHelper&));
  ACE_UNIMPLEMENTED_FUNC(RPG_Graphics_ColorNameHelper& operator=(const RPG_Graphics_ColorNameHelper&));
};

#endif
