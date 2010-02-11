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

#ifndef RPG_MAGIC_DESCRIPTOR_H
#define RPG_MAGIC_DESCRIPTOR_H

enum RPG_Magic_Descriptor
{
  DESCRIPTOR_ACID = 0,
  DESCRIPTOR_AIR,
  DESCRIPTOR_CHAOTIC,
  DESCRIPTOR_COLD,
  DESCRIPTOR_DARKNESS,
  DESCRIPTOR_DEATH,
  DESCRIPTOR_EARTH,
  DESCRIPTOR_ELECTRICITY,
  DESCRIPTOR_EVIL,
  DESCRIPTOR_FEAR,
  DESCRIPTOR_FIRE,
  DESCRIPTOR_FORCE,
  DESCRIPTOR_GOOD,
  DESCRIPTOR_LANGUAGE_DEPENDENT,
  DESCRIPTOR_LAWFUL,
  DESCRIPTOR_LIGHT,
  DESCRIPTOR_MIND_AFFECTING,
  DESCRIPTOR_SONIC,
  DESCRIPTOR_WATER,
  //
  RPG_MAGIC_DESCRIPTOR_MAX,
  RPG_MAGIC_DESCRIPTOR_INVALID
};

#include <ace/Global_Macros.h>

#include <map>
#include <string>

typedef std::map<RPG_Magic_Descriptor, std::string> RPG_Magic_DescriptorToStringTable_t;
typedef RPG_Magic_DescriptorToStringTable_t::const_iterator RPG_Magic_DescriptorToStringTableIterator_t;

class RPG_Magic_DescriptorHelper
{
 public:
  inline static void init()
  {
    myRPG_Magic_DescriptorToStringTable.clear();
    myRPG_Magic_DescriptorToStringTable.insert(std::make_pair(DESCRIPTOR_ACID, ACE_TEXT_ALWAYS_CHAR("DESCRIPTOR_ACID")));
    myRPG_Magic_DescriptorToStringTable.insert(std::make_pair(DESCRIPTOR_AIR, ACE_TEXT_ALWAYS_CHAR("DESCRIPTOR_AIR")));
    myRPG_Magic_DescriptorToStringTable.insert(std::make_pair(DESCRIPTOR_CHAOTIC, ACE_TEXT_ALWAYS_CHAR("DESCRIPTOR_CHAOTIC")));
    myRPG_Magic_DescriptorToStringTable.insert(std::make_pair(DESCRIPTOR_COLD, ACE_TEXT_ALWAYS_CHAR("DESCRIPTOR_COLD")));
    myRPG_Magic_DescriptorToStringTable.insert(std::make_pair(DESCRIPTOR_DARKNESS, ACE_TEXT_ALWAYS_CHAR("DESCRIPTOR_DARKNESS")));
    myRPG_Magic_DescriptorToStringTable.insert(std::make_pair(DESCRIPTOR_DEATH, ACE_TEXT_ALWAYS_CHAR("DESCRIPTOR_DEATH")));
    myRPG_Magic_DescriptorToStringTable.insert(std::make_pair(DESCRIPTOR_EARTH, ACE_TEXT_ALWAYS_CHAR("DESCRIPTOR_EARTH")));
    myRPG_Magic_DescriptorToStringTable.insert(std::make_pair(DESCRIPTOR_ELECTRICITY, ACE_TEXT_ALWAYS_CHAR("DESCRIPTOR_ELECTRICITY")));
    myRPG_Magic_DescriptorToStringTable.insert(std::make_pair(DESCRIPTOR_EVIL, ACE_TEXT_ALWAYS_CHAR("DESCRIPTOR_EVIL")));
    myRPG_Magic_DescriptorToStringTable.insert(std::make_pair(DESCRIPTOR_FEAR, ACE_TEXT_ALWAYS_CHAR("DESCRIPTOR_FEAR")));
    myRPG_Magic_DescriptorToStringTable.insert(std::make_pair(DESCRIPTOR_FIRE, ACE_TEXT_ALWAYS_CHAR("DESCRIPTOR_FIRE")));
    myRPG_Magic_DescriptorToStringTable.insert(std::make_pair(DESCRIPTOR_FORCE, ACE_TEXT_ALWAYS_CHAR("DESCRIPTOR_FORCE")));
    myRPG_Magic_DescriptorToStringTable.insert(std::make_pair(DESCRIPTOR_GOOD, ACE_TEXT_ALWAYS_CHAR("DESCRIPTOR_GOOD")));
    myRPG_Magic_DescriptorToStringTable.insert(std::make_pair(DESCRIPTOR_LANGUAGE_DEPENDENT, ACE_TEXT_ALWAYS_CHAR("DESCRIPTOR_LANGUAGE_DEPENDENT")));
    myRPG_Magic_DescriptorToStringTable.insert(std::make_pair(DESCRIPTOR_LAWFUL, ACE_TEXT_ALWAYS_CHAR("DESCRIPTOR_LAWFUL")));
    myRPG_Magic_DescriptorToStringTable.insert(std::make_pair(DESCRIPTOR_LIGHT, ACE_TEXT_ALWAYS_CHAR("DESCRIPTOR_LIGHT")));
    myRPG_Magic_DescriptorToStringTable.insert(std::make_pair(DESCRIPTOR_MIND_AFFECTING, ACE_TEXT_ALWAYS_CHAR("DESCRIPTOR_MIND_AFFECTING")));
    myRPG_Magic_DescriptorToStringTable.insert(std::make_pair(DESCRIPTOR_SONIC, ACE_TEXT_ALWAYS_CHAR("DESCRIPTOR_SONIC")));
    myRPG_Magic_DescriptorToStringTable.insert(std::make_pair(DESCRIPTOR_WATER, ACE_TEXT_ALWAYS_CHAR("DESCRIPTOR_WATER")));
  };

  inline static std::string RPG_Magic_DescriptorToString(const RPG_Magic_Descriptor& element_in)
  {
    std::string result;
    RPG_Magic_DescriptorToStringTableIterator_t iterator = myRPG_Magic_DescriptorToStringTable.find(element_in);
    if (iterator != myRPG_Magic_DescriptorToStringTable.end())
      result = iterator->second;
    else
      result = ACE_TEXT_ALWAYS_CHAR("RPG_MAGIC_DESCRIPTOR_INVALID");

    return result;
  };

  inline static RPG_Magic_Descriptor stringToRPG_Magic_Descriptor(const std::string& string_in)
  {
    RPG_Magic_DescriptorToStringTableIterator_t iterator = myRPG_Magic_DescriptorToStringTable.begin();
    do
    {
      if (iterator->second == string_in)
        return iterator->first;

      iterator++;
    } while (iterator != myRPG_Magic_DescriptorToStringTable.end());

    return RPG_MAGIC_DESCRIPTOR_INVALID;
  };

  static RPG_Magic_DescriptorToStringTable_t myRPG_Magic_DescriptorToStringTable;

 private:
  ACE_UNIMPLEMENTED_FUNC(RPG_Magic_DescriptorHelper());
  ACE_UNIMPLEMENTED_FUNC(RPG_Magic_DescriptorHelper(const RPG_Magic_DescriptorHelper&));
  ACE_UNIMPLEMENTED_FUNC(RPG_Magic_DescriptorHelper& operator=(const RPG_Magic_DescriptorHelper&));
};

#endif
