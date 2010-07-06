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
#ifndef RPG_GRAPHICS_HOTSPOTTYPE_H
#define RPG_GRAPHICS_HOTSPOTTYPE_H

enum RPG_Graphics_HotspotType
{
  HOTSPOT_ABSOLUTE = 0,
  HOTSPOT_RELATIVE,
  //
  RPG_GRAPHICS_HOTSPOTTYPE_MAX,
  RPG_GRAPHICS_HOTSPOTTYPE_INVALID
};

#include <ace/Global_Macros.h>

#include <map>
#include <string>

typedef std::map<RPG_Graphics_HotspotType, std::string> RPG_Graphics_HotspotTypeToStringTable_t;
typedef RPG_Graphics_HotspotTypeToStringTable_t::const_iterator RPG_Graphics_HotspotTypeToStringTableIterator_t;

class RPG_Graphics_HotspotTypeHelper
{
 public:
  inline static void init()
  {
    myRPG_Graphics_HotspotTypeToStringTable.clear();
    myRPG_Graphics_HotspotTypeToStringTable.insert(std::make_pair(HOTSPOT_ABSOLUTE, ACE_TEXT_ALWAYS_CHAR("HOTSPOT_ABSOLUTE")));
    myRPG_Graphics_HotspotTypeToStringTable.insert(std::make_pair(HOTSPOT_RELATIVE, ACE_TEXT_ALWAYS_CHAR("HOTSPOT_RELATIVE")));
  };

  inline static std::string RPG_Graphics_HotspotTypeToString(const RPG_Graphics_HotspotType& element_in)
  {
    std::string result;
    RPG_Graphics_HotspotTypeToStringTableIterator_t iterator = myRPG_Graphics_HotspotTypeToStringTable.find(element_in);
    if (iterator != myRPG_Graphics_HotspotTypeToStringTable.end())
      result = iterator->second;
    else
      result = ACE_TEXT_ALWAYS_CHAR("RPG_GRAPHICS_HOTSPOTTYPE_INVALID");

    return result;
  };

  inline static RPG_Graphics_HotspotType stringToRPG_Graphics_HotspotType(const std::string& string_in)
  {
    RPG_Graphics_HotspotTypeToStringTableIterator_t iterator = myRPG_Graphics_HotspotTypeToStringTable.begin();
    do
    {
      if (iterator->second == string_in)
        return iterator->first;

      iterator++;
    } while (iterator != myRPG_Graphics_HotspotTypeToStringTable.end());

    return RPG_GRAPHICS_HOTSPOTTYPE_INVALID;
  };

  static RPG_Graphics_HotspotTypeToStringTable_t myRPG_Graphics_HotspotTypeToStringTable;

 private:
  ACE_UNIMPLEMENTED_FUNC(RPG_Graphics_HotspotTypeHelper());
  ACE_UNIMPLEMENTED_FUNC(RPG_Graphics_HotspotTypeHelper(const RPG_Graphics_HotspotTypeHelper&));
  ACE_UNIMPLEMENTED_FUNC(RPG_Graphics_HotspotTypeHelper& operator=(const RPG_Graphics_HotspotTypeHelper&));
};

#endif