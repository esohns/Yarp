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
#ifndef RPG_GRAPHICS_IMAGE_H
#define RPG_GRAPHICS_IMAGE_H

enum RPG_Graphics_Image
{
  IMAGE_INTERFACE = 0,
  IMAGE_INTRO_MAIN,
  IMAGE_WM_ICON,
  //
  RPG_GRAPHICS_IMAGE_MAX,
  RPG_GRAPHICS_IMAGE_INVALID
};

#include <ace/Global_Macros.h>

#include <map>
#include <string>

typedef std::map<RPG_Graphics_Image, std::string> RPG_Graphics_ImageToStringTable_t;
typedef RPG_Graphics_ImageToStringTable_t::const_iterator RPG_Graphics_ImageToStringTableIterator_t;

class RPG_Graphics_ImageHelper
{
 public:
  inline static void init()
  {
    myRPG_Graphics_ImageToStringTable.clear();
    myRPG_Graphics_ImageToStringTable.insert(std::make_pair(IMAGE_INTERFACE, ACE_TEXT_ALWAYS_CHAR("IMAGE_INTERFACE")));
    myRPG_Graphics_ImageToStringTable.insert(std::make_pair(IMAGE_INTRO_MAIN, ACE_TEXT_ALWAYS_CHAR("IMAGE_INTRO_MAIN")));
    myRPG_Graphics_ImageToStringTable.insert(std::make_pair(IMAGE_WM_ICON, ACE_TEXT_ALWAYS_CHAR("IMAGE_WM_ICON")));
  };

  inline static std::string RPG_Graphics_ImageToString(const RPG_Graphics_Image& element_in)
  {
    std::string result;
    RPG_Graphics_ImageToStringTableIterator_t iterator = myRPG_Graphics_ImageToStringTable.find(element_in);
    if (iterator != myRPG_Graphics_ImageToStringTable.end())
      result = iterator->second;
    else
      result = ACE_TEXT_ALWAYS_CHAR("RPG_GRAPHICS_IMAGE_INVALID");

    return result;
  };

  inline static RPG_Graphics_Image stringToRPG_Graphics_Image(const std::string& string_in)
  {
    RPG_Graphics_ImageToStringTableIterator_t iterator = myRPG_Graphics_ImageToStringTable.begin();
    do
    {
      if (iterator->second == string_in)
        return iterator->first;

      iterator++;
    } while (iterator != myRPG_Graphics_ImageToStringTable.end());

    return RPG_GRAPHICS_IMAGE_INVALID;
  };

  static RPG_Graphics_ImageToStringTable_t myRPG_Graphics_ImageToStringTable;

 private:
  ACE_UNIMPLEMENTED_FUNC(RPG_Graphics_ImageHelper());
  ACE_UNIMPLEMENTED_FUNC(RPG_Graphics_ImageHelper(const RPG_Graphics_ImageHelper&));
  ACE_UNIMPLEMENTED_FUNC(RPG_Graphics_ImageHelper& operator=(const RPG_Graphics_ImageHelper&));
};

#endif
