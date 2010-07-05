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
#ifndef RPG_GRAPHICS_TILESETTYPE_H
#define RPG_GRAPHICS_TILESETTYPE_H

enum RPG_Graphics_TileSetType
{
  TILESETTYPE_DOOR = 0,
  TILESETTYPE_FLOOR,
  TILESETTYPE_WALL,
  //
  RPG_GRAPHICS_TILESETTYPE_MAX,
  RPG_GRAPHICS_TILESETTYPE_INVALID
};

#include <ace/Global_Macros.h>

#include <map>
#include <string>

typedef std::map<RPG_Graphics_TileSetType, std::string> RPG_Graphics_TileSetTypeToStringTable_t;
typedef RPG_Graphics_TileSetTypeToStringTable_t::const_iterator RPG_Graphics_TileSetTypeToStringTableIterator_t;

class RPG_Graphics_TileSetTypeHelper
{
 public:
  inline static void init()
  {
    myRPG_Graphics_TileSetTypeToStringTable.clear();
    myRPG_Graphics_TileSetTypeToStringTable.insert(std::make_pair(TILESETTYPE_DOOR, ACE_TEXT_ALWAYS_CHAR("TILESETTYPE_DOOR")));
    myRPG_Graphics_TileSetTypeToStringTable.insert(std::make_pair(TILESETTYPE_FLOOR, ACE_TEXT_ALWAYS_CHAR("TILESETTYPE_FLOOR")));
    myRPG_Graphics_TileSetTypeToStringTable.insert(std::make_pair(TILESETTYPE_WALL, ACE_TEXT_ALWAYS_CHAR("TILESETTYPE_WALL")));
  };

  inline static std::string RPG_Graphics_TileSetTypeToString(const RPG_Graphics_TileSetType& element_in)
  {
    std::string result;
    RPG_Graphics_TileSetTypeToStringTableIterator_t iterator = myRPG_Graphics_TileSetTypeToStringTable.find(element_in);
    if (iterator != myRPG_Graphics_TileSetTypeToStringTable.end())
      result = iterator->second;
    else
      result = ACE_TEXT_ALWAYS_CHAR("RPG_GRAPHICS_TILESETTYPE_INVALID");

    return result;
  };

  inline static RPG_Graphics_TileSetType stringToRPG_Graphics_TileSetType(const std::string& string_in)
  {
    RPG_Graphics_TileSetTypeToStringTableIterator_t iterator = myRPG_Graphics_TileSetTypeToStringTable.begin();
    do
    {
      if (iterator->second == string_in)
        return iterator->first;

      iterator++;
    } while (iterator != myRPG_Graphics_TileSetTypeToStringTable.end());

    return RPG_GRAPHICS_TILESETTYPE_INVALID;
  };

  static RPG_Graphics_TileSetTypeToStringTable_t myRPG_Graphics_TileSetTypeToStringTable;

 private:
  ACE_UNIMPLEMENTED_FUNC(RPG_Graphics_TileSetTypeHelper());
  ACE_UNIMPLEMENTED_FUNC(RPG_Graphics_TileSetTypeHelper(const RPG_Graphics_TileSetTypeHelper&));
  ACE_UNIMPLEMENTED_FUNC(RPG_Graphics_TileSetTypeHelper& operator=(const RPG_Graphics_TileSetTypeHelper&));
};

#endif
