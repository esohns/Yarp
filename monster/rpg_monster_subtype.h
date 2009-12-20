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

#ifndef RPG_MONSTER_SUBTYPE_H
#define RPG_MONSTER_SUBTYPE_H

enum RPG_Monster_SubType
{
  SUBTYPE_AIR = 0,
  SUBTYPE_ANGEL,
  SUBTYPE_AQUATIC,
  SUBTYPE_ARCHON,
  SUBTYPE_AUGMENTED,
  SUBTYPE_CHAOTIC,
  SUBTYPE_COLD,
  SUBTYPE_EARTH,
  SUBTYPE_EVIL,
  SUBTYPE_EXTRAPLANAR,
  SUBTYPE_FIRE,
  SUBTYPE_GOBLINOID,
  SUBTYPE_GOOD,
  SUBTYPE_INCORPOREAL,
  SUBTYPE_LAWFUL,
  SUBTYPE_NATIVE,
  SUBTYPE_REPTILIAN,
  SUBTYPE_SHAPECHANGER,
  SUBTYPE_SWARM,
  SUBTYPE_WATER,
  //
  RPG_MONSTER_SUBTYPE_MAX,
  RPG_MONSTER_SUBTYPE_INVALID
};

#include <ace/Global_Macros.h>

#include <map>
#include <string>

typedef std::map<RPG_Monster_SubType, std::string> RPG_Monster_SubTypeToStringTable_t;
typedef RPG_Monster_SubTypeToStringTable_t::const_iterator RPG_Monster_SubTypeToStringTableIterator_t;

class RPG_Monster_SubTypeHelper
{
 public:
  inline static void init()
  {
    myRPG_Monster_SubTypeToStringTable.clear();
    myRPG_Monster_SubTypeToStringTable.insert(std::make_pair(SUBTYPE_AIR, ACE_TEXT_ALWAYS_CHAR("SUBTYPE_AIR")));
    myRPG_Monster_SubTypeToStringTable.insert(std::make_pair(SUBTYPE_ANGEL, ACE_TEXT_ALWAYS_CHAR("SUBTYPE_ANGEL")));
    myRPG_Monster_SubTypeToStringTable.insert(std::make_pair(SUBTYPE_AQUATIC, ACE_TEXT_ALWAYS_CHAR("SUBTYPE_AQUATIC")));
    myRPG_Monster_SubTypeToStringTable.insert(std::make_pair(SUBTYPE_ARCHON, ACE_TEXT_ALWAYS_CHAR("SUBTYPE_ARCHON")));
    myRPG_Monster_SubTypeToStringTable.insert(std::make_pair(SUBTYPE_AUGMENTED, ACE_TEXT_ALWAYS_CHAR("SUBTYPE_AUGMENTED")));
    myRPG_Monster_SubTypeToStringTable.insert(std::make_pair(SUBTYPE_CHAOTIC, ACE_TEXT_ALWAYS_CHAR("SUBTYPE_CHAOTIC")));
    myRPG_Monster_SubTypeToStringTable.insert(std::make_pair(SUBTYPE_COLD, ACE_TEXT_ALWAYS_CHAR("SUBTYPE_COLD")));
    myRPG_Monster_SubTypeToStringTable.insert(std::make_pair(SUBTYPE_EARTH, ACE_TEXT_ALWAYS_CHAR("SUBTYPE_EARTH")));
    myRPG_Monster_SubTypeToStringTable.insert(std::make_pair(SUBTYPE_EVIL, ACE_TEXT_ALWAYS_CHAR("SUBTYPE_EVIL")));
    myRPG_Monster_SubTypeToStringTable.insert(std::make_pair(SUBTYPE_EXTRAPLANAR, ACE_TEXT_ALWAYS_CHAR("SUBTYPE_EXTRAPLANAR")));
    myRPG_Monster_SubTypeToStringTable.insert(std::make_pair(SUBTYPE_FIRE, ACE_TEXT_ALWAYS_CHAR("SUBTYPE_FIRE")));
    myRPG_Monster_SubTypeToStringTable.insert(std::make_pair(SUBTYPE_GOBLINOID, ACE_TEXT_ALWAYS_CHAR("SUBTYPE_GOBLINOID")));
    myRPG_Monster_SubTypeToStringTable.insert(std::make_pair(SUBTYPE_GOOD, ACE_TEXT_ALWAYS_CHAR("SUBTYPE_GOOD")));
    myRPG_Monster_SubTypeToStringTable.insert(std::make_pair(SUBTYPE_INCORPOREAL, ACE_TEXT_ALWAYS_CHAR("SUBTYPE_INCORPOREAL")));
    myRPG_Monster_SubTypeToStringTable.insert(std::make_pair(SUBTYPE_LAWFUL, ACE_TEXT_ALWAYS_CHAR("SUBTYPE_LAWFUL")));
    myRPG_Monster_SubTypeToStringTable.insert(std::make_pair(SUBTYPE_NATIVE, ACE_TEXT_ALWAYS_CHAR("SUBTYPE_NATIVE")));
    myRPG_Monster_SubTypeToStringTable.insert(std::make_pair(SUBTYPE_REPTILIAN, ACE_TEXT_ALWAYS_CHAR("SUBTYPE_REPTILIAN")));
    myRPG_Monster_SubTypeToStringTable.insert(std::make_pair(SUBTYPE_SHAPECHANGER, ACE_TEXT_ALWAYS_CHAR("SUBTYPE_SHAPECHANGER")));
    myRPG_Monster_SubTypeToStringTable.insert(std::make_pair(SUBTYPE_SWARM, ACE_TEXT_ALWAYS_CHAR("SUBTYPE_SWARM")));
    myRPG_Monster_SubTypeToStringTable.insert(std::make_pair(SUBTYPE_WATER, ACE_TEXT_ALWAYS_CHAR("SUBTYPE_WATER")));
  };

  inline static std::string RPG_Monster_SubTypeToString(const RPG_Monster_SubType& element_in)
  {
    std::string result;
    RPG_Monster_SubTypeToStringTableIterator_t iterator = myRPG_Monster_SubTypeToStringTable.find(element_in);
    if (iterator != myRPG_Monster_SubTypeToStringTable.end())
      result = iterator->second;
    else
      result = ACE_TEXT_ALWAYS_CHAR("RPG_MONSTER_SUBTYPE_INVALID");

    return result;
  };

  inline static RPG_Monster_SubType stringToRPG_Monster_SubType(const std::string& string_in)
  {
    RPG_Monster_SubTypeToStringTableIterator_t iterator = myRPG_Monster_SubTypeToStringTable.begin();
    do
    {
      if (iterator->second == string_in)
        return iterator->first;

      iterator++;
    } while (iterator != myRPG_Monster_SubTypeToStringTable.end());

    return RPG_MONSTER_SUBTYPE_INVALID;
  };

  static RPG_Monster_SubTypeToStringTable_t myRPG_Monster_SubTypeToStringTable;

 private:
  ACE_UNIMPLEMENTED_FUNC(RPG_Monster_SubTypeHelper());
  ACE_UNIMPLEMENTED_FUNC(RPG_Monster_SubTypeHelper(const RPG_Monster_SubTypeHelper&));
  ACE_UNIMPLEMENTED_FUNC(RPG_Monster_SubTypeHelper& operator=(const RPG_Monster_SubTypeHelper&));
};

#endif
