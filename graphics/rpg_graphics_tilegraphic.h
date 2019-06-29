
// -------------------------------- * * * ----------------------------------- //
// PLEASE NOTE: this file was/is generated by // -------------------------------- * * * ----------------------------------- //

#pragma once
#ifndef RPG_GRAPHICS_TILEGRAPHIC_H
#define RPG_GRAPHICS_TILEGRAPHIC_H

enum RPG_Graphics_TileGraphic
{
  TILE_CEILING = 0,
  TILE_CURSOR_HIGHLIGHT,
  TILE_FLOOR_INVISIBLE,
  TILE_OFF_MAP,
  //
  RPG_GRAPHICS_TILEGRAPHIC_MAX,
  RPG_GRAPHICS_TILEGRAPHIC_INVALID
};

#include "ace/Global_Macros.h"

#include <map>
#include <string>

typedef std::map<RPG_Graphics_TileGraphic, std::string> RPG_Graphics_TileGraphicToStringTable_t;
typedef RPG_Graphics_TileGraphicToStringTable_t::const_iterator RPG_Graphics_TileGraphicToStringTableIterator_t;

class RPG_Graphics_TileGraphicHelper
{
 public:
  inline static void init()
  {
    myRPG_Graphics_TileGraphicToStringTable.clear();
    myRPG_Graphics_TileGraphicToStringTable.insert(std::make_pair(TILE_CEILING, ACE_TEXT_ALWAYS_CHAR("TILE_CEILING")));
    myRPG_Graphics_TileGraphicToStringTable.insert(std::make_pair(TILE_CURSOR_HIGHLIGHT, ACE_TEXT_ALWAYS_CHAR("TILE_CURSOR_HIGHLIGHT")));
    myRPG_Graphics_TileGraphicToStringTable.insert(std::make_pair(TILE_FLOOR_INVISIBLE, ACE_TEXT_ALWAYS_CHAR("TILE_FLOOR_INVISIBLE")));
    myRPG_Graphics_TileGraphicToStringTable.insert(std::make_pair(TILE_OFF_MAP, ACE_TEXT_ALWAYS_CHAR("TILE_OFF_MAP")));
  };

  inline static std::string RPG_Graphics_TileGraphicToString(const RPG_Graphics_TileGraphic& element_in)
  {
    std::string result;
    RPG_Graphics_TileGraphicToStringTableIterator_t iterator = myRPG_Graphics_TileGraphicToStringTable.find(element_in);
    if (iterator != myRPG_Graphics_TileGraphicToStringTable.end())
      result = iterator->second;
    else
      result = ACE_TEXT_ALWAYS_CHAR("RPG_GRAPHICS_TILEGRAPHIC_INVALID");

    return result;
  };

  inline static RPG_Graphics_TileGraphic stringToRPG_Graphics_TileGraphic(const std::string& string_in)
  {
    RPG_Graphics_TileGraphicToStringTableIterator_t iterator = myRPG_Graphics_TileGraphicToStringTable.begin();
    do
    {
      if (iterator->second == string_in)
        return iterator->first;

      iterator++;
    } while (iterator != myRPG_Graphics_TileGraphicToStringTable.end());

    return RPG_GRAPHICS_TILEGRAPHIC_INVALID;
  };

  static RPG_Graphics_TileGraphicToStringTable_t myRPG_Graphics_TileGraphicToStringTable;

 private:
  ACE_UNIMPLEMENTED_FUNC(RPG_Graphics_TileGraphicHelper());
  ACE_UNIMPLEMENTED_FUNC(RPG_Graphics_TileGraphicHelper(const RPG_Graphics_TileGraphicHelper&));
  ACE_UNIMPLEMENTED_FUNC(RPG_Graphics_TileGraphicHelper& operator=(const RPG_Graphics_TileGraphicHelper&));
};

#endif
