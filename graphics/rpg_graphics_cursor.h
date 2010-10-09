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
#ifndef RPG_GRAPHICS_CURSOR_H
#define RPG_GRAPHICS_CURSOR_H

enum RPG_Graphics_Cursor
{
  CURSOR_DOOR_OPEN = 0,
  CURSOR_NORMAL,
  CURSOR_SCROLL_D,
  CURSOR_SCROLL_DL,
  CURSOR_SCROLL_DR,
  CURSOR_SCROLL_L,
  CURSOR_SCROLL_R,
  CURSOR_SCROLL_U,
  CURSOR_SCROLL_UL,
  CURSOR_SCROLL_UR,
  CURSOR_STAIRS,
  CURSOR_WAIT,
  //
  RPG_GRAPHICS_CURSOR_MAX,
  RPG_GRAPHICS_CURSOR_INVALID
};

#include <ace/Global_Macros.h>

#include <map>
#include <string>

typedef std::map<RPG_Graphics_Cursor, std::string> RPG_Graphics_CursorToStringTable_t;
typedef RPG_Graphics_CursorToStringTable_t::const_iterator RPG_Graphics_CursorToStringTableIterator_t;

class RPG_Graphics_CursorHelper
{
 public:
  inline static void init()
  {
    myRPG_Graphics_CursorToStringTable.clear();
    myRPG_Graphics_CursorToStringTable.insert(std::make_pair(CURSOR_DOOR_OPEN, ACE_TEXT_ALWAYS_CHAR("CURSOR_DOOR_OPEN")));
    myRPG_Graphics_CursorToStringTable.insert(std::make_pair(CURSOR_NORMAL, ACE_TEXT_ALWAYS_CHAR("CURSOR_NORMAL")));
    myRPG_Graphics_CursorToStringTable.insert(std::make_pair(CURSOR_SCROLL_D, ACE_TEXT_ALWAYS_CHAR("CURSOR_SCROLL_D")));
    myRPG_Graphics_CursorToStringTable.insert(std::make_pair(CURSOR_SCROLL_DL, ACE_TEXT_ALWAYS_CHAR("CURSOR_SCROLL_DL")));
    myRPG_Graphics_CursorToStringTable.insert(std::make_pair(CURSOR_SCROLL_DR, ACE_TEXT_ALWAYS_CHAR("CURSOR_SCROLL_DR")));
    myRPG_Graphics_CursorToStringTable.insert(std::make_pair(CURSOR_SCROLL_L, ACE_TEXT_ALWAYS_CHAR("CURSOR_SCROLL_L")));
    myRPG_Graphics_CursorToStringTable.insert(std::make_pair(CURSOR_SCROLL_R, ACE_TEXT_ALWAYS_CHAR("CURSOR_SCROLL_R")));
    myRPG_Graphics_CursorToStringTable.insert(std::make_pair(CURSOR_SCROLL_U, ACE_TEXT_ALWAYS_CHAR("CURSOR_SCROLL_U")));
    myRPG_Graphics_CursorToStringTable.insert(std::make_pair(CURSOR_SCROLL_UL, ACE_TEXT_ALWAYS_CHAR("CURSOR_SCROLL_UL")));
    myRPG_Graphics_CursorToStringTable.insert(std::make_pair(CURSOR_SCROLL_UR, ACE_TEXT_ALWAYS_CHAR("CURSOR_SCROLL_UR")));
    myRPG_Graphics_CursorToStringTable.insert(std::make_pair(CURSOR_STAIRS, ACE_TEXT_ALWAYS_CHAR("CURSOR_STAIRS")));
    myRPG_Graphics_CursorToStringTable.insert(std::make_pair(CURSOR_WAIT, ACE_TEXT_ALWAYS_CHAR("CURSOR_WAIT")));
  };

  inline static std::string RPG_Graphics_CursorToString(const RPG_Graphics_Cursor& element_in)
  {
    std::string result;
    RPG_Graphics_CursorToStringTableIterator_t iterator = myRPG_Graphics_CursorToStringTable.find(element_in);
    if (iterator != myRPG_Graphics_CursorToStringTable.end())
      result = iterator->second;
    else
      result = ACE_TEXT_ALWAYS_CHAR("RPG_GRAPHICS_CURSOR_INVALID");

    return result;
  };

  inline static RPG_Graphics_Cursor stringToRPG_Graphics_Cursor(const std::string& string_in)
  {
    RPG_Graphics_CursorToStringTableIterator_t iterator = myRPG_Graphics_CursorToStringTable.begin();
    do
    {
      if (iterator->second == string_in)
        return iterator->first;

      iterator++;
    } while (iterator != myRPG_Graphics_CursorToStringTable.end());

    return RPG_GRAPHICS_CURSOR_INVALID;
  };

  static RPG_Graphics_CursorToStringTable_t myRPG_Graphics_CursorToStringTable;

 private:
  ACE_UNIMPLEMENTED_FUNC(RPG_Graphics_CursorHelper());
  ACE_UNIMPLEMENTED_FUNC(RPG_Graphics_CursorHelper(const RPG_Graphics_CursorHelper&));
  ACE_UNIMPLEMENTED_FUNC(RPG_Graphics_CursorHelper& operator=(const RPG_Graphics_CursorHelper&));
};

#endif
