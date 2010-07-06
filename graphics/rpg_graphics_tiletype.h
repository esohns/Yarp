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
#ifndef RPG_GRAPHICS_TILETYPE_H
#define RPG_GRAPHICS_TILETYPE_H

enum RPG_Graphics_TileType
{
  TILETYPE_DOOR = 0,
  TILETYPE_EFFECT,
  TILETYPE_FIGURINE,
  TILETYPE_FLOOR,
  TILETYPE_MONSTER,
  TILETYPE_OBJECT,
  TILETYPE_WALL,
  //
  RPG_GRAPHICS_TILETYPE_MAX,
  RPG_GRAPHICS_TILETYPE_INVALID
};

#include <ace/Global_Macros.h>

#include <map>
#include <string>

typedef std::map<RPG_Graphics_TileType, std::string> RPG_Graphics_TileTypeToStringTable_t;
typedef RPG_Graphics_TileTypeToStringTable_t::const_iterator RPG_Graphics_TileTypeToStringTableIterator_t;

class RPG_Graphics_TileTypeHelper
{
 public:
  inline static void init()
  {
    myRPG_Graphics_TileTypeToStringTable.clear();
    myRPG_Graphics_TileTypeToStringTable.insert(std::make_pair(TILETYPE_DOOR, ACE_TEXT_ALWAYS_CHAR("TILETYPE_DOOR")));
    myRPG_Graphics_TileTypeToStringTable.insert(std::make_pair(TILETYPE_EFFECT, ACE_TEXT_ALWAYS_CHAR("TILETYPE_EFFECT")));
    myRPG_Graphics_TileTypeToStringTable.insert(std::make_pair(TILETYPE_FIGURINE, ACE_TEXT_ALWAYS_CHAR("TILETYPE_FIGURINE")));
    myRPG_Graphics_TileTypeToStringTable.insert(std::make_pair(TILETYPE_FLOOR, ACE_TEXT_ALWAYS_CHAR("TILETYPE_FLOOR")));
    myRPG_Graphics_TileTypeToStringTable.insert(std::make_pair(TILETYPE_MONSTER, ACE_TEXT_ALWAYS_CHAR("TILETYPE_MONSTER")));
    myRPG_Graphics_TileTypeToStringTable.insert(std::make_pair(TILETYPE_OBJECT, ACE_TEXT_ALWAYS_CHAR("TILETYPE_OBJECT")));
    myRPG_Graphics_TileTypeToStringTable.insert(std::make_pair(TILETYPE_WALL, ACE_TEXT_ALWAYS_CHAR("TILETYPE_WALL")));
  };

  inline static std::string RPG_Graphics_TileTypeToString(const RPG_Graphics_TileType& element_in)
  {
    std::string result;
    RPG_Graphics_TileTypeToStringTableIterator_t iterator = myRPG_Graphics_TileTypeToStringTable.find(element_in);
    if (iterator != myRPG_Graphics_TileTypeToStringTable.end())
      result = iterator->second;
    else
      result = ACE_TEXT_ALWAYS_CHAR("RPG_GRAPHICS_TILETYPE_INVALID");

    return result;
  };

  inline static RPG_Graphics_TileType stringToRPG_Graphics_TileType(const std::string& string_in)
  {
    RPG_Graphics_TileTypeToStringTableIterator_t iterator = myRPG_Graphics_TileTypeToStringTable.begin();
    do
    {
      if (iterator->second == string_in)
        return iterator->first;

      iterator++;
    } while (iterator != myRPG_Graphics_TileTypeToStringTable.end());

    return RPG_GRAPHICS_TILETYPE_INVALID;
  };

  static RPG_Graphics_TileTypeToStringTable_t myRPG_Graphics_TileTypeToStringTable;

 private:
  ACE_UNIMPLEMENTED_FUNC(RPG_Graphics_TileTypeHelper());
  ACE_UNIMPLEMENTED_FUNC(RPG_Graphics_TileTypeHelper(const RPG_Graphics_TileTypeHelper&));
  ACE_UNIMPLEMENTED_FUNC(RPG_Graphics_TileTypeHelper& operator=(const RPG_Graphics_TileTypeHelper&));
};

#endif