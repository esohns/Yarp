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
#ifndef RPG_GRAPHICS_CATEGORY_H
#define RPG_GRAPHICS_CATEGORY_H

enum RPG_Graphics_Category
{
  CATEGORY_CURSOR = 0,
  CATEGORY_FONT,
  CATEGORY_INTERFACE,
  CATEGORY_IMAGE,
  CATEGORY_SPRITE,
  CATEGORY_TILE,
  CATEGORY_TILESET,
  //
  RPG_GRAPHICS_CATEGORY_MAX,
  RPG_GRAPHICS_CATEGORY_INVALID
};

#include <ace/Global_Macros.h>

#include <map>
#include <string>

typedef std::map<RPG_Graphics_Category, std::string> RPG_Graphics_CategoryToStringTable_t;
typedef RPG_Graphics_CategoryToStringTable_t::const_iterator RPG_Graphics_CategoryToStringTableIterator_t;

class RPG_Graphics_CategoryHelper
{
 public:
  inline static void init()
  {
    myRPG_Graphics_CategoryToStringTable.clear();
    myRPG_Graphics_CategoryToStringTable.insert(std::make_pair(CATEGORY_CURSOR, ACE_TEXT_ALWAYS_CHAR("CATEGORY_CURSOR")));
    myRPG_Graphics_CategoryToStringTable.insert(std::make_pair(CATEGORY_FONT, ACE_TEXT_ALWAYS_CHAR("CATEGORY_FONT")));
    myRPG_Graphics_CategoryToStringTable.insert(std::make_pair(CATEGORY_INTERFACE, ACE_TEXT_ALWAYS_CHAR("CATEGORY_INTERFACE")));
    myRPG_Graphics_CategoryToStringTable.insert(std::make_pair(CATEGORY_IMAGE, ACE_TEXT_ALWAYS_CHAR("CATEGORY_IMAGE")));
    myRPG_Graphics_CategoryToStringTable.insert(std::make_pair(CATEGORY_SPRITE, ACE_TEXT_ALWAYS_CHAR("CATEGORY_SPRITE")));
    myRPG_Graphics_CategoryToStringTable.insert(std::make_pair(CATEGORY_TILE, ACE_TEXT_ALWAYS_CHAR("CATEGORY_TILE")));
    myRPG_Graphics_CategoryToStringTable.insert(std::make_pair(CATEGORY_TILESET, ACE_TEXT_ALWAYS_CHAR("CATEGORY_TILESET")));
  };

  inline static std::string RPG_Graphics_CategoryToString(const RPG_Graphics_Category& element_in)
  {
    std::string result;
    RPG_Graphics_CategoryToStringTableIterator_t iterator = myRPG_Graphics_CategoryToStringTable.find(element_in);
    if (iterator != myRPG_Graphics_CategoryToStringTable.end())
      result = iterator->second;
    else
      result = ACE_TEXT_ALWAYS_CHAR("RPG_GRAPHICS_CATEGORY_INVALID");

    return result;
  };

  inline static RPG_Graphics_Category stringToRPG_Graphics_Category(const std::string& string_in)
  {
    RPG_Graphics_CategoryToStringTableIterator_t iterator = myRPG_Graphics_CategoryToStringTable.begin();
    do
    {
      if (iterator->second == string_in)
        return iterator->first;

      iterator++;
    } while (iterator != myRPG_Graphics_CategoryToStringTable.end());

    return RPG_GRAPHICS_CATEGORY_INVALID;
  };

  static RPG_Graphics_CategoryToStringTable_t myRPG_Graphics_CategoryToStringTable;

 private:
  ACE_UNIMPLEMENTED_FUNC(RPG_Graphics_CategoryHelper());
  ACE_UNIMPLEMENTED_FUNC(RPG_Graphics_CategoryHelper(const RPG_Graphics_CategoryHelper&));
  ACE_UNIMPLEMENTED_FUNC(RPG_Graphics_CategoryHelper& operator=(const RPG_Graphics_CategoryHelper&));
};

#endif
