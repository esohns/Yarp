/***************************************************************************
 *   Copyright (C) 2010 by Erik Sohns   *
 *   erik.sohns@web.de   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

// -------------------------------- * * * -------------------------------- //
// PLEASE NOTE: this file was/is generated by XML2CppCode 0.1
// -------------------------------- * * * -------------------------------- //

#pragma once
#ifndef RPG_GRAPHICS_TYPE_H
#define RPG_GRAPHICS_TYPE_H

enum RPG_Graphics_Type
{
  TYPE_CURSOR_DOOR_OPEN = 0,
  TYPE_CURSOR_NORMAL,
  TYPE_CURSOR_SCROLL_D,
  TYPE_CURSOR_SCROLL_DL,
  TYPE_CURSOR_SCROLL_DR,
  TYPE_CURSOR_SCROLL_L,
  TYPE_CURSOR_SCROLL_R,
  TYPE_CURSOR_SCROLL_U,
  TYPE_CURSOR_SCROLL_UL,
  TYPE_CURSOR_SCROLL_UR,
  TYPE_CURSOR_STAIRS,
  TYPE_CURSOR_WAIT,
  TYPE_FONT_MAIN_SMALL,
  TYPE_FONT_MAIN_NORMAL,
  TYPE_FONT_MAIN_LARGE,
  TYPE_INTERFACE,
  TYPE_IMAGE_INTRO_MAIN,
  TYPE_IMAGE_WM_ICON,
  TYPE_TILE_CEILING,
  TYPE_TILE_CURSOR_HIGHLIGHT,
  TYPE_TILE_FLOOR_INVISIBLE,
  TYPE_TILE_OFF_MAP,
  TYPE_TILESET_DOOR_WOOD,
  TYPE_TILESET_FLOOR_AIR,
  TYPE_TILESET_FLOOR_DARK,
  TYPE_TILESET_WALL_BRICK_HALF,
  TYPE_TILESET_WALL_BRICK_FULL,
  //
  RPG_GRAPHICS_TYPE_MAX,
  RPG_GRAPHICS_TYPE_INVALID
};

#include <ace/Global_Macros.h>

#include <map>
#include <string>

typedef std::map<RPG_Graphics_Type, std::string> RPG_Graphics_TypeToStringTable_t;
typedef RPG_Graphics_TypeToStringTable_t::const_iterator RPG_Graphics_TypeToStringTableIterator_t;

class RPG_Graphics_TypeHelper
{
 public:
  inline static void init()
  {
    myRPG_Graphics_TypeToStringTable.clear();
    myRPG_Graphics_TypeToStringTable.insert(std::make_pair(TYPE_CURSOR_DOOR_OPEN, ACE_TEXT_ALWAYS_CHAR("TYPE_CURSOR_DOOR_OPEN")));
    myRPG_Graphics_TypeToStringTable.insert(std::make_pair(TYPE_CURSOR_NORMAL, ACE_TEXT_ALWAYS_CHAR("TYPE_CURSOR_NORMAL")));
    myRPG_Graphics_TypeToStringTable.insert(std::make_pair(TYPE_CURSOR_SCROLL_D, ACE_TEXT_ALWAYS_CHAR("TYPE_CURSOR_SCROLL_D")));
    myRPG_Graphics_TypeToStringTable.insert(std::make_pair(TYPE_CURSOR_SCROLL_DL, ACE_TEXT_ALWAYS_CHAR("TYPE_CURSOR_SCROLL_DL")));
    myRPG_Graphics_TypeToStringTable.insert(std::make_pair(TYPE_CURSOR_SCROLL_DR, ACE_TEXT_ALWAYS_CHAR("TYPE_CURSOR_SCROLL_DR")));
    myRPG_Graphics_TypeToStringTable.insert(std::make_pair(TYPE_CURSOR_SCROLL_L, ACE_TEXT_ALWAYS_CHAR("TYPE_CURSOR_SCROLL_L")));
    myRPG_Graphics_TypeToStringTable.insert(std::make_pair(TYPE_CURSOR_SCROLL_R, ACE_TEXT_ALWAYS_CHAR("TYPE_CURSOR_SCROLL_R")));
    myRPG_Graphics_TypeToStringTable.insert(std::make_pair(TYPE_CURSOR_SCROLL_U, ACE_TEXT_ALWAYS_CHAR("TYPE_CURSOR_SCROLL_U")));
    myRPG_Graphics_TypeToStringTable.insert(std::make_pair(TYPE_CURSOR_SCROLL_UL, ACE_TEXT_ALWAYS_CHAR("TYPE_CURSOR_SCROLL_UL")));
    myRPG_Graphics_TypeToStringTable.insert(std::make_pair(TYPE_CURSOR_SCROLL_UR, ACE_TEXT_ALWAYS_CHAR("TYPE_CURSOR_SCROLL_UR")));
    myRPG_Graphics_TypeToStringTable.insert(std::make_pair(TYPE_CURSOR_STAIRS, ACE_TEXT_ALWAYS_CHAR("TYPE_CURSOR_STAIRS")));
    myRPG_Graphics_TypeToStringTable.insert(std::make_pair(TYPE_CURSOR_WAIT, ACE_TEXT_ALWAYS_CHAR("TYPE_CURSOR_WAIT")));
    myRPG_Graphics_TypeToStringTable.insert(std::make_pair(TYPE_FONT_MAIN_SMALL, ACE_TEXT_ALWAYS_CHAR("TYPE_FONT_MAIN_SMALL")));
    myRPG_Graphics_TypeToStringTable.insert(std::make_pair(TYPE_FONT_MAIN_NORMAL, ACE_TEXT_ALWAYS_CHAR("TYPE_FONT_MAIN_NORMAL")));
    myRPG_Graphics_TypeToStringTable.insert(std::make_pair(TYPE_FONT_MAIN_LARGE, ACE_TEXT_ALWAYS_CHAR("TYPE_FONT_MAIN_LARGE")));
    myRPG_Graphics_TypeToStringTable.insert(std::make_pair(TYPE_INTERFACE, ACE_TEXT_ALWAYS_CHAR("TYPE_INTERFACE")));
    myRPG_Graphics_TypeToStringTable.insert(std::make_pair(TYPE_IMAGE_INTRO_MAIN, ACE_TEXT_ALWAYS_CHAR("TYPE_IMAGE_INTRO_MAIN")));
    myRPG_Graphics_TypeToStringTable.insert(std::make_pair(TYPE_IMAGE_WM_ICON, ACE_TEXT_ALWAYS_CHAR("TYPE_IMAGE_WM_ICON")));
    myRPG_Graphics_TypeToStringTable.insert(std::make_pair(TYPE_TILE_CEILING, ACE_TEXT_ALWAYS_CHAR("TYPE_TILE_CEILING")));
    myRPG_Graphics_TypeToStringTable.insert(std::make_pair(TYPE_TILE_CURSOR_HIGHLIGHT, ACE_TEXT_ALWAYS_CHAR("TYPE_TILE_CURSOR_HIGHLIGHT")));
    myRPG_Graphics_TypeToStringTable.insert(std::make_pair(TYPE_TILE_FLOOR_INVISIBLE, ACE_TEXT_ALWAYS_CHAR("TYPE_TILE_FLOOR_INVISIBLE")));
    myRPG_Graphics_TypeToStringTable.insert(std::make_pair(TYPE_TILE_OFF_MAP, ACE_TEXT_ALWAYS_CHAR("TYPE_TILE_OFF_MAP")));
    myRPG_Graphics_TypeToStringTable.insert(std::make_pair(TYPE_TILESET_DOOR_WOOD, ACE_TEXT_ALWAYS_CHAR("TYPE_TILESET_DOOR_WOOD")));
    myRPG_Graphics_TypeToStringTable.insert(std::make_pair(TYPE_TILESET_FLOOR_AIR, ACE_TEXT_ALWAYS_CHAR("TYPE_TILESET_FLOOR_AIR")));
    myRPG_Graphics_TypeToStringTable.insert(std::make_pair(TYPE_TILESET_FLOOR_DARK, ACE_TEXT_ALWAYS_CHAR("TYPE_TILESET_FLOOR_DARK")));
    myRPG_Graphics_TypeToStringTable.insert(std::make_pair(TYPE_TILESET_WALL_BRICK_HALF, ACE_TEXT_ALWAYS_CHAR("TYPE_TILESET_WALL_BRICK_HALF")));
    myRPG_Graphics_TypeToStringTable.insert(std::make_pair(TYPE_TILESET_WALL_BRICK_FULL, ACE_TEXT_ALWAYS_CHAR("TYPE_TILESET_WALL_BRICK_FULL")));
  };

  inline static std::string RPG_Graphics_TypeToString(const RPG_Graphics_Type& element_in)
  {
    std::string result;
    RPG_Graphics_TypeToStringTableIterator_t iterator = myRPG_Graphics_TypeToStringTable.find(element_in);
    if (iterator != myRPG_Graphics_TypeToStringTable.end())
      result = iterator->second;
    else
      result = ACE_TEXT_ALWAYS_CHAR("RPG_GRAPHICS_TYPE_INVALID");

    return result;
  };

  inline static RPG_Graphics_Type stringToRPG_Graphics_Type(const std::string& string_in)
  {
    RPG_Graphics_TypeToStringTableIterator_t iterator = myRPG_Graphics_TypeToStringTable.begin();
    do
    {
      if (iterator->second == string_in)
        return iterator->first;

      iterator++;
    } while (iterator != myRPG_Graphics_TypeToStringTable.end());

    return RPG_GRAPHICS_TYPE_INVALID;
  };

  static RPG_Graphics_TypeToStringTable_t myRPG_Graphics_TypeToStringTable;

 private:
  ACE_UNIMPLEMENTED_FUNC(RPG_Graphics_TypeHelper());
  ACE_UNIMPLEMENTED_FUNC(RPG_Graphics_TypeHelper(const RPG_Graphics_TypeHelper&));
  ACE_UNIMPLEMENTED_FUNC(RPG_Graphics_TypeHelper& operator=(const RPG_Graphics_TypeHelper&));
};

#endif
