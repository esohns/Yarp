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

#ifndef RPG_MAGIC_ABILITYTYPE_H
#define RPG_MAGIC_ABILITYTYPE_H

enum RPG_Magic_AbilityType
{
  ABILITYTYPE_SMITE = 0,
  //
  RPG_MAGIC_ABILITYTYPE_MAX,
  RPG_MAGIC_ABILITYTYPE_INVALID
};

#include <ace/Global_Macros.h>

#include <map>
#include <string>

typedef std::map<RPG_Magic_AbilityType, std::string> RPG_Magic_AbilityTypeToStringTable_t;
typedef RPG_Magic_AbilityTypeToStringTable_t::const_iterator RPG_Magic_AbilityTypeToStringTableIterator_t;

class RPG_Magic_AbilityTypeHelper
{
 public:
  inline static void init()
  {
    myRPG_Magic_AbilityTypeToStringTable.clear();
    myRPG_Magic_AbilityTypeToStringTable.insert(std::make_pair(ABILITYTYPE_SMITE, ACE_TEXT_ALWAYS_CHAR("ABILITYTYPE_SMITE")));
  };

  inline static std::string RPG_Magic_AbilityTypeToString(const RPG_Magic_AbilityType& element_in)
  {
    std::string result;
    RPG_Magic_AbilityTypeToStringTableIterator_t iterator = myRPG_Magic_AbilityTypeToStringTable.find(element_in);
    if (iterator != myRPG_Magic_AbilityTypeToStringTable.end())
      result = iterator->second;
    else
      result = ACE_TEXT_ALWAYS_CHAR("RPG_MAGIC_ABILITYTYPE_INVALID");

    return result;
  };

  inline static RPG_Magic_AbilityType stringToRPG_Magic_AbilityType(const std::string& string_in)
  {
    RPG_Magic_AbilityTypeToStringTableIterator_t iterator = myRPG_Magic_AbilityTypeToStringTable.begin();
    do
    {
      if (iterator->second == string_in)
        return iterator->first;

      iterator++;
    } while (iterator != myRPG_Magic_AbilityTypeToStringTable.end());

    return RPG_MAGIC_ABILITYTYPE_INVALID;
  };

  static RPG_Magic_AbilityTypeToStringTable_t myRPG_Magic_AbilityTypeToStringTable;

 private:
  ACE_UNIMPLEMENTED_FUNC(RPG_Magic_AbilityTypeHelper());
  ACE_UNIMPLEMENTED_FUNC(RPG_Magic_AbilityTypeHelper(const RPG_Magic_AbilityTypeHelper&));
  ACE_UNIMPLEMENTED_FUNC(RPG_Magic_AbilityTypeHelper& operator=(const RPG_Magic_AbilityTypeHelper&));
};

#endif