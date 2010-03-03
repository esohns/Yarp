/***************************************************************************
 *   Copyright (C) 2009 by Erik Sohns   *
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

#ifndef RPG_MAGIC_SPELL_TARGET_H
#define RPG_MAGIC_SPELL_TARGET_H

enum RPG_Magic_Spell_Target
{
  TARGET_SELF = 0,
  TARGET_FIX,
  TARGET_VARIABLE,
  TARGET_LOCATION,
  TARGET_AREA,
  //
  RPG_MAGIC_SPELL_TARGET_MAX,
  RPG_MAGIC_SPELL_TARGET_INVALID
};

#include <ace/Global_Macros.h>

#include <map>
#include <string>

typedef std::map<RPG_Magic_Spell_Target, std::string> RPG_Magic_Spell_TargetToStringTable_t;
typedef RPG_Magic_Spell_TargetToStringTable_t::const_iterator RPG_Magic_Spell_TargetToStringTableIterator_t;

class RPG_Magic_Spell_TargetHelper
{
 public:
  inline static void init()
  {
    myRPG_Magic_Spell_TargetToStringTable.clear();
    myRPG_Magic_Spell_TargetToStringTable.insert(std::make_pair(TARGET_SELF, ACE_TEXT_ALWAYS_CHAR("TARGET_SELF")));
    myRPG_Magic_Spell_TargetToStringTable.insert(std::make_pair(TARGET_FIX, ACE_TEXT_ALWAYS_CHAR("TARGET_FIX")));
    myRPG_Magic_Spell_TargetToStringTable.insert(std::make_pair(TARGET_VARIABLE, ACE_TEXT_ALWAYS_CHAR("TARGET_VARIABLE")));
    myRPG_Magic_Spell_TargetToStringTable.insert(std::make_pair(TARGET_LOCATION, ACE_TEXT_ALWAYS_CHAR("TARGET_LOCATION")));
    myRPG_Magic_Spell_TargetToStringTable.insert(std::make_pair(TARGET_AREA, ACE_TEXT_ALWAYS_CHAR("TARGET_AREA")));
  };

  inline static std::string RPG_Magic_Spell_TargetToString(const RPG_Magic_Spell_Target& element_in)
  {
    std::string result;
    RPG_Magic_Spell_TargetToStringTableIterator_t iterator = myRPG_Magic_Spell_TargetToStringTable.find(element_in);
    if (iterator != myRPG_Magic_Spell_TargetToStringTable.end())
      result = iterator->second;
    else
      result = ACE_TEXT_ALWAYS_CHAR("RPG_MAGIC_SPELL_TARGET_INVALID");

    return result;
  };

  inline static RPG_Magic_Spell_Target stringToRPG_Magic_Spell_Target(const std::string& string_in)
  {
    RPG_Magic_Spell_TargetToStringTableIterator_t iterator = myRPG_Magic_Spell_TargetToStringTable.begin();
    do
    {
      if (iterator->second == string_in)
        return iterator->first;

      iterator++;
    } while (iterator != myRPG_Magic_Spell_TargetToStringTable.end());

    return RPG_MAGIC_SPELL_TARGET_INVALID;
  };

  static RPG_Magic_Spell_TargetToStringTable_t myRPG_Magic_Spell_TargetToStringTable;

 private:
  ACE_UNIMPLEMENTED_FUNC(RPG_Magic_Spell_TargetHelper());
  ACE_UNIMPLEMENTED_FUNC(RPG_Magic_Spell_TargetHelper(const RPG_Magic_Spell_TargetHelper&));
  ACE_UNIMPLEMENTED_FUNC(RPG_Magic_Spell_TargetHelper& operator=(const RPG_Magic_Spell_TargetHelper&));
};

#endif