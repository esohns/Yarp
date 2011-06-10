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

// -------------------------------- * * * -------------------------------- //
// PLEASE NOTE: this file was/is generated by XML2CppCode 0.1
// -------------------------------- * * * -------------------------------- //

#pragma once
#ifndef RPG_MONSTER_ORGANIZATION_H
#define RPG_MONSTER_ORGANIZATION_H

enum RPG_Monster_Organization
{
  ORGANIZATION_ANY = 0,
  ORGANIZATION_BAND,
  ORGANIZATION_BROOD,
  ORGANIZATION_COLONY,
  ORGANIZATION_CLAN,
  ORGANIZATION_CLUSTER,
  ORGANIZATION_CLUTCH,
  ORGANIZATION_COMPANY,
  ORGANIZATION_CROWD,
  ORGANIZATION_FLIGHT,
  ORGANIZATION_FLOCK,
  ORGANIZATION_GANG,
  ORGANIZATION_GROUP,
  ORGANIZATION_MOB,
  ORGANIZATION_PACK,
  ORGANIZATION_PAIR,
  ORGANIZATION_PATCH,
  ORGANIZATION_PRIDE,
  ORGANIZATION_SOLITARY,
  ORGANIZATION_SQUAD,
  ORGANIZATION_SWARM,
  ORGANIZATION_TEAM,
  ORGANIZATION_TRIBE,
  ORGANIZATION_TROOP,
  ORGANIZATION_TROUPE,
  //
  RPG_MONSTER_ORGANIZATION_MAX,
  RPG_MONSTER_ORGANIZATION_INVALID
};

#include <ace/Global_Macros.h>

#include <map>
#include <string>

typedef std::map<RPG_Monster_Organization, std::string> RPG_Monster_OrganizationToStringTable_t;
typedef RPG_Monster_OrganizationToStringTable_t::const_iterator RPG_Monster_OrganizationToStringTableIterator_t;

class RPG_Monster_OrganizationHelper
{
 public:
  inline static void init()
  {
    myRPG_Monster_OrganizationToStringTable.clear();
    myRPG_Monster_OrganizationToStringTable.insert(std::make_pair(ORGANIZATION_ANY, ACE_TEXT_ALWAYS_CHAR("ORGANIZATION_ANY")));
    myRPG_Monster_OrganizationToStringTable.insert(std::make_pair(ORGANIZATION_BAND, ACE_TEXT_ALWAYS_CHAR("ORGANIZATION_BAND")));
    myRPG_Monster_OrganizationToStringTable.insert(std::make_pair(ORGANIZATION_BROOD, ACE_TEXT_ALWAYS_CHAR("ORGANIZATION_BROOD")));
    myRPG_Monster_OrganizationToStringTable.insert(std::make_pair(ORGANIZATION_COLONY, ACE_TEXT_ALWAYS_CHAR("ORGANIZATION_COLONY")));
    myRPG_Monster_OrganizationToStringTable.insert(std::make_pair(ORGANIZATION_CLAN, ACE_TEXT_ALWAYS_CHAR("ORGANIZATION_CLAN")));
    myRPG_Monster_OrganizationToStringTable.insert(std::make_pair(ORGANIZATION_CLUSTER, ACE_TEXT_ALWAYS_CHAR("ORGANIZATION_CLUSTER")));
    myRPG_Monster_OrganizationToStringTable.insert(std::make_pair(ORGANIZATION_CLUTCH, ACE_TEXT_ALWAYS_CHAR("ORGANIZATION_CLUTCH")));
    myRPG_Monster_OrganizationToStringTable.insert(std::make_pair(ORGANIZATION_COMPANY, ACE_TEXT_ALWAYS_CHAR("ORGANIZATION_COMPANY")));
    myRPG_Monster_OrganizationToStringTable.insert(std::make_pair(ORGANIZATION_CROWD, ACE_TEXT_ALWAYS_CHAR("ORGANIZATION_CROWD")));
    myRPG_Monster_OrganizationToStringTable.insert(std::make_pair(ORGANIZATION_FLIGHT, ACE_TEXT_ALWAYS_CHAR("ORGANIZATION_FLIGHT")));
    myRPG_Monster_OrganizationToStringTable.insert(std::make_pair(ORGANIZATION_FLOCK, ACE_TEXT_ALWAYS_CHAR("ORGANIZATION_FLOCK")));
    myRPG_Monster_OrganizationToStringTable.insert(std::make_pair(ORGANIZATION_GANG, ACE_TEXT_ALWAYS_CHAR("ORGANIZATION_GANG")));
    myRPG_Monster_OrganizationToStringTable.insert(std::make_pair(ORGANIZATION_GROUP, ACE_TEXT_ALWAYS_CHAR("ORGANIZATION_GROUP")));
    myRPG_Monster_OrganizationToStringTable.insert(std::make_pair(ORGANIZATION_MOB, ACE_TEXT_ALWAYS_CHAR("ORGANIZATION_MOB")));
    myRPG_Monster_OrganizationToStringTable.insert(std::make_pair(ORGANIZATION_PACK, ACE_TEXT_ALWAYS_CHAR("ORGANIZATION_PACK")));
    myRPG_Monster_OrganizationToStringTable.insert(std::make_pair(ORGANIZATION_PAIR, ACE_TEXT_ALWAYS_CHAR("ORGANIZATION_PAIR")));
    myRPG_Monster_OrganizationToStringTable.insert(std::make_pair(ORGANIZATION_PATCH, ACE_TEXT_ALWAYS_CHAR("ORGANIZATION_PATCH")));
    myRPG_Monster_OrganizationToStringTable.insert(std::make_pair(ORGANIZATION_PRIDE, ACE_TEXT_ALWAYS_CHAR("ORGANIZATION_PRIDE")));
    myRPG_Monster_OrganizationToStringTable.insert(std::make_pair(ORGANIZATION_SOLITARY, ACE_TEXT_ALWAYS_CHAR("ORGANIZATION_SOLITARY")));
    myRPG_Monster_OrganizationToStringTable.insert(std::make_pair(ORGANIZATION_SQUAD, ACE_TEXT_ALWAYS_CHAR("ORGANIZATION_SQUAD")));
    myRPG_Monster_OrganizationToStringTable.insert(std::make_pair(ORGANIZATION_SWARM, ACE_TEXT_ALWAYS_CHAR("ORGANIZATION_SWARM")));
    myRPG_Monster_OrganizationToStringTable.insert(std::make_pair(ORGANIZATION_TEAM, ACE_TEXT_ALWAYS_CHAR("ORGANIZATION_TEAM")));
    myRPG_Monster_OrganizationToStringTable.insert(std::make_pair(ORGANIZATION_TRIBE, ACE_TEXT_ALWAYS_CHAR("ORGANIZATION_TRIBE")));
    myRPG_Monster_OrganizationToStringTable.insert(std::make_pair(ORGANIZATION_TROOP, ACE_TEXT_ALWAYS_CHAR("ORGANIZATION_TROOP")));
    myRPG_Monster_OrganizationToStringTable.insert(std::make_pair(ORGANIZATION_TROUPE, ACE_TEXT_ALWAYS_CHAR("ORGANIZATION_TROUPE")));
  };

  inline static std::string RPG_Monster_OrganizationToString(const RPG_Monster_Organization& element_in)
  {
    std::string result;
    RPG_Monster_OrganizationToStringTableIterator_t iterator = myRPG_Monster_OrganizationToStringTable.find(element_in);
    if (iterator != myRPG_Monster_OrganizationToStringTable.end())
      result = iterator->second;
    else
      result = ACE_TEXT_ALWAYS_CHAR("RPG_MONSTER_ORGANIZATION_INVALID");

    return result;
  };

  inline static RPG_Monster_Organization stringToRPG_Monster_Organization(const std::string& string_in)
  {
    RPG_Monster_OrganizationToStringTableIterator_t iterator = myRPG_Monster_OrganizationToStringTable.begin();
    do
    {
      if (iterator->second == string_in)
        return iterator->first;

      iterator++;
    } while (iterator != myRPG_Monster_OrganizationToStringTable.end());

    return RPG_MONSTER_ORGANIZATION_INVALID;
  };

  static RPG_Monster_OrganizationToStringTable_t myRPG_Monster_OrganizationToStringTable;

 private:
  ACE_UNIMPLEMENTED_FUNC(RPG_Monster_OrganizationHelper());
  ACE_UNIMPLEMENTED_FUNC(RPG_Monster_OrganizationHelper(const RPG_Monster_OrganizationHelper&));
  ACE_UNIMPLEMENTED_FUNC(RPG_Monster_OrganizationHelper& operator=(const RPG_Monster_OrganizationHelper&));
};

#endif
