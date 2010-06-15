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
#ifndef RPG_GRAPHICS_WALLSTYLE_H
#define RPG_GRAPHICS_WALLSTYLE_H

enum RPG_Graphics_WallStyle
{
  WALLSTYLE_AIR = 0,
  WALLSTYLE_DARK,
  WALLSTYLE_STONE,
  WALLSTYLE_WATER,
  //
  RPG_GRAPHICS_WALLSTYLE_MAX,
  RPG_GRAPHICS_WALLSTYLE_INVALID
};

#include <ace/Global_Macros.h>

#include <map>
#include <string>

typedef std::map<RPG_Graphics_WallStyle, std::string> RPG_Graphics_WallStyleToStringTable_t;
typedef RPG_Graphics_WallStyleToStringTable_t::const_iterator RPG_Graphics_WallStyleToStringTableIterator_t;

class RPG_Graphics_WallStyleHelper
{
 public:
  inline static void init()
  {
    myRPG_Graphics_WallStyleToStringTable.clear();
    myRPG_Graphics_WallStyleToStringTable.insert(std::make_pair(WALLSTYLE_AIR, ACE_TEXT_ALWAYS_CHAR("WALLSTYLE_AIR")));
    myRPG_Graphics_WallStyleToStringTable.insert(std::make_pair(WALLSTYLE_DARK, ACE_TEXT_ALWAYS_CHAR("WALLSTYLE_DARK")));
    myRPG_Graphics_WallStyleToStringTable.insert(std::make_pair(WALLSTYLE_STONE, ACE_TEXT_ALWAYS_CHAR("WALLSTYLE_STONE")));
    myRPG_Graphics_WallStyleToStringTable.insert(std::make_pair(WALLSTYLE_WATER, ACE_TEXT_ALWAYS_CHAR("WALLSTYLE_WATER")));
  };

  inline static std::string RPG_Graphics_WallStyleToString(const RPG_Graphics_WallStyle& element_in)
  {
    std::string result;
    RPG_Graphics_WallStyleToStringTableIterator_t iterator = myRPG_Graphics_WallStyleToStringTable.find(element_in);
    if (iterator != myRPG_Graphics_WallStyleToStringTable.end())
      result = iterator->second;
    else
      result = ACE_TEXT_ALWAYS_CHAR("RPG_GRAPHICS_WALLSTYLE_INVALID");

    return result;
  };

  inline static RPG_Graphics_WallStyle stringToRPG_Graphics_WallStyle(const std::string& string_in)
  {
    RPG_Graphics_WallStyleToStringTableIterator_t iterator = myRPG_Graphics_WallStyleToStringTable.begin();
    do
    {
      if (iterator->second == string_in)
        return iterator->first;

      iterator++;
    } while (iterator != myRPG_Graphics_WallStyleToStringTable.end());

    return RPG_GRAPHICS_WALLSTYLE_INVALID;
  };

  static RPG_Graphics_WallStyleToStringTable_t myRPG_Graphics_WallStyleToStringTable;

 private:
  ACE_UNIMPLEMENTED_FUNC(RPG_Graphics_WallStyleHelper());
  ACE_UNIMPLEMENTED_FUNC(RPG_Graphics_WallStyleHelper(const RPG_Graphics_WallStyleHelper&));
  ACE_UNIMPLEMENTED_FUNC(RPG_Graphics_WallStyleHelper& operator=(const RPG_Graphics_WallStyleHelper&));
};

#endif
