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
#ifndef RPG_GRAPHICS_DOORSTYLE_H
#define RPG_GRAPHICS_DOORSTYLE_H

enum RPG_Graphics_DoorStyle
{
  DOORSTYLE_IRON = 0,
  DOORSTYLE_IRON_GATE,
  DOORSTYLE_STONE,
  DOORSTYLE_TELEPORTER,
  DOORSTYLE_WOOD,
  //
  RPG_GRAPHICS_DOORSTYLE_MAX,
  RPG_GRAPHICS_DOORSTYLE_INVALID
};

#include <ace/Global_Macros.h>

#include <map>
#include <string>

typedef std::map<RPG_Graphics_DoorStyle, std::string> RPG_Graphics_DoorStyleToStringTable_t;
typedef RPG_Graphics_DoorStyleToStringTable_t::const_iterator RPG_Graphics_DoorStyleToStringTableIterator_t;

class RPG_Graphics_DoorStyleHelper
{
 public:
  inline static void init()
  {
    myRPG_Graphics_DoorStyleToStringTable.clear();
    myRPG_Graphics_DoorStyleToStringTable.insert(std::make_pair(DOORSTYLE_IRON, ACE_TEXT_ALWAYS_CHAR("DOORSTYLE_IRON")));
    myRPG_Graphics_DoorStyleToStringTable.insert(std::make_pair(DOORSTYLE_IRON_GATE, ACE_TEXT_ALWAYS_CHAR("DOORSTYLE_IRON_GATE")));
    myRPG_Graphics_DoorStyleToStringTable.insert(std::make_pair(DOORSTYLE_STONE, ACE_TEXT_ALWAYS_CHAR("DOORSTYLE_STONE")));
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
