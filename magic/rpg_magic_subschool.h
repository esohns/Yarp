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
#ifndef RPG_MAGIC_SUBSCHOOL_H
#define RPG_MAGIC_SUBSCHOOL_H

enum RPG_Magic_SubSchool
{
  SUBSCHOOL_SUMMONING = 0,
  SUBSCHOOL_CALLING,
  SUBSCHOOL_HEALING,
  SUBSCHOOL_TELEPORTATION,
  SUBSCHOOL_CREATION,
  SUBSCHOOL_SCRYING,
  SUBSCHOOL_CHARM,
  SUBSCHOOL_COMPULSION,
  SUBSCHOOL_FIGMENT,
  SUBSCHOOL_GLAMER,
  SUBSCHOOL_PATTERN,
  SUBSCHOOL_PHANTASM,
  SUBSCHOOL_SHADOW,
  //
  RPG_MAGIC_SUBSCHOOL_MAX,
  RPG_MAGIC_SUBSCHOOL_INVALID
};

#include <ace/Global_Macros.h>

#include <map>
#include <string>

typedef std::map<RPG_Magic_SubSchool, std::string> RPG_Magic_SubSchoolToStringTable_t;
typedef RPG_Magic_SubSchoolToStringTable_t::const_iterator RPG_Magic_SubSchoolToStringTableIterator_t;

class RPG_Magic_SubSchoolHelper
{
 public:
  inline static void init()
  {
    myRPG_Magic_SubSchoolToStringTable.clear();
    myRPG_Magic_SubSchoolToStringTable.insert(std::make_pair(SUBSCHOOL_SUMMONING, ACE_TEXT_ALWAYS_CHAR("SUBSCHOOL_SUMMONING")));
    myRPG_Magic_SubSchoolToStringTable.insert(std::make_pair(SUBSCHOOL_CALLING, ACE_TEXT_ALWAYS_CHAR("SUBSCHOOL_CALLING")));
    myRPG_Magic_SubSchoolToStringTable.insert(std::make_pair(SUBSCHOOL_HEALING, ACE_TEXT_ALWAYS_CHAR("SUBSCHOOL_HEALING")));
    myRPG_Magic_SubSchoolToStringTable.insert(std::make_pair(SUBSCHOOL_TELEPORTATION, ACE_TEXT_ALWAYS_CHAR("SUBSCHOOL_TELEPORTATION")));
    myRPG_Magic_SubSchoolToStringTable.insert(std::make_pair(SUBSCHOOL_CREATION, ACE_TEXT_ALWAYS_CHAR("SUBSCHOOL_CREATION")));
    myRPG_Magic_SubSchoolToStringTable.insert(std::make_pair(SUBSCHOOL_SCRYING, ACE_TEXT_ALWAYS_CHAR("SUBSCHOOL_SCRYING")));
    myRPG_Magic_SubSchoolToStringTable.insert(std::make_pair(SUBSCHOOL_CHARM, ACE_TEXT_ALWAYS_CHAR("SUBSCHOOL_CHARM")));
    myRPG_Magic_SubSchoolToStringTable.insert(std::make_pair(SUBSCHOOL_COMPULSION, ACE_TEXT_ALWAYS_CHAR("SUBSCHOOL_COMPULSION")));
    myRPG_Magic_SubSchoolToStringTable.insert(std::make_pair(SUBSCHOOL_FIGMENT, ACE_TEXT_ALWAYS_CHAR("SUBSCHOOL_FIGMENT")));
    myRPG_Magic_SubSchoolToStringTable.insert(std::make_pair(SUBSCHOOL_GLAMER, ACE_TEXT_ALWAYS_CHAR("SUBSCHOOL_GLAMER")));
    myRPG_Magic_SubSchoolToStringTable.insert(std::make_pair(SUBSCHOOL_PATTERN, ACE_TEXT_ALWAYS_CHAR("SUBSCHOOL_PATTERN")));
    myRPG_Magic_SubSchoolToStringTable.insert(std::make_pair(SUBSCHOOL_PHANTASM, ACE_TEXT_ALWAYS_CHAR("SUBSCHOOL_PHANTASM")));
    myRPG_Magic_SubSchoolToStringTable.insert(std::make_pair(SUBSCHOOL_SHADOW, ACE_TEXT_ALWAYS_CHAR("SUBSCHOOL_SHADOW")));
  };

  inline static std::string RPG_Magic_SubSchoolToString(const RPG_Magic_SubSchool& element_in)
  {
    std::string result;
    RPG_Magic_SubSchoolToStringTableIterator_t iterator = myRPG_Magic_SubSchoolToStringTable.find(element_in);
    if (iterator != myRPG_Magic_SubSchoolToStringTable.end())
      result = iterator->second;
    else
      result = ACE_TEXT_ALWAYS_CHAR("RPG_MAGIC_SUBSCHOOL_INVALID");

    return result;
  };

  inline static RPG_Magic_SubSchool stringToRPG_Magic_SubSchool(const std::string& string_in)
  {
    RPG_Magic_SubSchoolToStringTableIterator_t iterator = myRPG_Magic_SubSchoolToStringTable.begin();
    do
    {
      if (iterator->second == string_in)
        return iterator->first;

      iterator++;
    } while (iterator != myRPG_Magic_SubSchoolToStringTable.end());

    return RPG_MAGIC_SUBSCHOOL_INVALID;
  };

  static RPG_Magic_SubSchoolToStringTable_t myRPG_Magic_SubSchoolToStringTable;

 private:
  ACE_UNIMPLEMENTED_FUNC(RPG_Magic_SubSchoolHelper());
  ACE_UNIMPLEMENTED_FUNC(RPG_Magic_SubSchoolHelper(const RPG_Magic_SubSchoolHelper&));
  ACE_UNIMPLEMENTED_FUNC(RPG_Magic_SubSchoolHelper& operator=(const RPG_Magic_SubSchoolHelper&));
};

#endif
