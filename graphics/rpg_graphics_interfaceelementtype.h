
// -------------------------------- * * * -------------------------------- //
// PLEASE NOTE: this file was/is generated by XML2CppCode 0.1
// -------------------------------- * * * -------------------------------- //

#pragma once
#ifndef RPG_GRAPHICS_INTERFACEELEMENTTYPE_H
#define RPG_GRAPHICS_INTERFACEELEMENTTYPE_H

enum RPG_Graphics_InterfaceElementType
{
  INTERFACEELEMENT_BORDER_TOP_LEFT = 0,
  INTERFACEELEMENT_BORDER_TOP_RIGHT,
  INTERFACEELEMENT_BORDER_BOTTOM_LEFT,
  INTERFACEELEMENT_BORDER_BOTTOM_RIGHT,
  INTERFACEELEMENT_BORDER_TOP,
  INTERFACEELEMENT_BORDER_RIGHT,
  INTERFACEELEMENT_BORDER_LEFT,
  INTERFACEELEMENT_BORDER_BOTTOM,
  INTERFACEELEMENT_BORDER_CENTER,
  INTERFACEELEMENT_BACKGROUND,
  //
  RPG_GRAPHICS_INTERFACEELEMENTTYPE_MAX,
  RPG_GRAPHICS_INTERFACEELEMENTTYPE_INVALID
};

#include "rpg_graphics_exports.h"

#include <ace/Global_Macros.h>

#include <map>
#include <string>

typedef std::map<RPG_Graphics_InterfaceElementType, std::string> RPG_Graphics_InterfaceElementTypeToStringTable_t;
typedef RPG_Graphics_InterfaceElementTypeToStringTable_t::const_iterator RPG_Graphics_InterfaceElementTypeToStringTableIterator_t;

class RPG_Graphics_Export RPG_Graphics_InterfaceElementTypeHelper
{
 public:
  inline static void init()
  {
    myRPG_Graphics_InterfaceElementTypeToStringTable.clear();
    myRPG_Graphics_InterfaceElementTypeToStringTable.insert(std::make_pair(INTERFACEELEMENT_BORDER_TOP_LEFT, ACE_TEXT_ALWAYS_CHAR("INTERFACEELEMENT_BORDER_TOP_LEFT")));
    myRPG_Graphics_InterfaceElementTypeToStringTable.insert(std::make_pair(INTERFACEELEMENT_BORDER_TOP_RIGHT, ACE_TEXT_ALWAYS_CHAR("INTERFACEELEMENT_BORDER_TOP_RIGHT")));
    myRPG_Graphics_InterfaceElementTypeToStringTable.insert(std::make_pair(INTERFACEELEMENT_BORDER_BOTTOM_LEFT, ACE_TEXT_ALWAYS_CHAR("INTERFACEELEMENT_BORDER_BOTTOM_LEFT")));
    myRPG_Graphics_InterfaceElementTypeToStringTable.insert(std::make_pair(INTERFACEELEMENT_BORDER_BOTTOM_RIGHT, ACE_TEXT_ALWAYS_CHAR("INTERFACEELEMENT_BORDER_BOTTOM_RIGHT")));
    myRPG_Graphics_InterfaceElementTypeToStringTable.insert(std::make_pair(INTERFACEELEMENT_BORDER_TOP, ACE_TEXT_ALWAYS_CHAR("INTERFACEELEMENT_BORDER_TOP")));
    myRPG_Graphics_InterfaceElementTypeToStringTable.insert(std::make_pair(INTERFACEELEMENT_BORDER_RIGHT, ACE_TEXT_ALWAYS_CHAR("INTERFACEELEMENT_BORDER_RIGHT")));
    myRPG_Graphics_InterfaceElementTypeToStringTable.insert(std::make_pair(INTERFACEELEMENT_BORDER_LEFT, ACE_TEXT_ALWAYS_CHAR("INTERFACEELEMENT_BORDER_LEFT")));
    myRPG_Graphics_InterfaceElementTypeToStringTable.insert(std::make_pair(INTERFACEELEMENT_BORDER_BOTTOM, ACE_TEXT_ALWAYS_CHAR("INTERFACEELEMENT_BORDER_BOTTOM")));
    myRPG_Graphics_InterfaceElementTypeToStringTable.insert(std::make_pair(INTERFACEELEMENT_BORDER_CENTER, ACE_TEXT_ALWAYS_CHAR("INTERFACEELEMENT_BORDER_CENTER")));
    myRPG_Graphics_InterfaceElementTypeToStringTable.insert(std::make_pair(INTERFACEELEMENT_BACKGROUND, ACE_TEXT_ALWAYS_CHAR("INTERFACEELEMENT_BACKGROUND")));
  };

  inline static std::string RPG_Graphics_InterfaceElementTypeToString(const RPG_Graphics_InterfaceElementType& element_in)
  {
    std::string result;
    RPG_Graphics_InterfaceElementTypeToStringTableIterator_t iterator = myRPG_Graphics_InterfaceElementTypeToStringTable.find(element_in);
    if (iterator != myRPG_Graphics_InterfaceElementTypeToStringTable.end())
      result = iterator->second;
    else
      result = ACE_TEXT_ALWAYS_CHAR("RPG_GRAPHICS_INTERFACEELEMENTTYPE_INVALID");

    return result;
  };

  inline static RPG_Graphics_InterfaceElementType stringToRPG_Graphics_InterfaceElementType(const std::string& string_in)
  {
    RPG_Graphics_InterfaceElementTypeToStringTableIterator_t iterator = myRPG_Graphics_InterfaceElementTypeToStringTable.begin();
    do
    {
      if (iterator->second == string_in)
        return iterator->first;

      iterator++;
    } while (iterator != myRPG_Graphics_InterfaceElementTypeToStringTable.end());

    return RPG_GRAPHICS_INTERFACEELEMENTTYPE_INVALID;
  };

  static RPG_Graphics_InterfaceElementTypeToStringTable_t myRPG_Graphics_InterfaceElementTypeToStringTable;

 private:
  ACE_UNIMPLEMENTED_FUNC(RPG_Graphics_InterfaceElementTypeHelper());
  ACE_UNIMPLEMENTED_FUNC(RPG_Graphics_InterfaceElementTypeHelper(const RPG_Graphics_InterfaceElementTypeHelper&));
  ACE_UNIMPLEMENTED_FUNC(RPG_Graphics_InterfaceElementTypeHelper& operator=(const RPG_Graphics_InterfaceElementTypeHelper&));
};

#endif
