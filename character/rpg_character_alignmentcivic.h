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

#ifndef RPG_CHARACTER_ALIGNMENTCIVIC_H
#define RPG_CHARACTER_ALIGNMENTCIVIC_H

enum RPG_Character_AlignmentCivic
{
  ALIGNMENTCIVIC_LAWFUL = 0,
  ALIGNMENTCIVIC_NEUTRAL,
  ALIGNMENTCIVIC_CHAOTIC,
  ALIGNMENTCIVIC_ANY,
  //
  RPG_CHARACTER_ALIGNMENTCIVIC_MAX,
  RPG_CHARACTER_ALIGNMENTCIVIC_INVALID
};

#include <ace/Global_Macros.h>

#include <map>
#include <string>

typedef std::map<RPG_Character_AlignmentCivic, std::string> RPG_Character_AlignmentCivicToStringTable_t;
typedef RPG_Character_AlignmentCivicToStringTable_t::const_iterator RPG_Character_AlignmentCivicToStringTableIterator_t;

class RPG_Character_AlignmentCivicHelper
{
 public:
  inline static void init()
  {
    myRPG_Character_AlignmentCivicToStringTable.clear();
    myRPG_Character_AlignmentCivicToStringTable.insert(std::make_pair(ALIGNMENTCIVIC_LAWFUL, ACE_TEXT_ALWAYS_CHAR("ALIGNMENTCIVIC_LAWFUL")));
    myRPG_Character_AlignmentCivicToStringTable.insert(std::make_pair(ALIGNMENTCIVIC_NEUTRAL, ACE_TEXT_ALWAYS_CHAR("ALIGNMENTCIVIC_NEUTRAL")));
    myRPG_Character_AlignmentCivicToStringTable.insert(std::make_pair(ALIGNMENTCIVIC_CHAOTIC, ACE_TEXT_ALWAYS_CHAR("ALIGNMENTCIVIC_CHAOTIC")));
    myRPG_Character_AlignmentCivicToStringTable.insert(std::make_pair(ALIGNMENTCIVIC_ANY, ACE_TEXT_ALWAYS_CHAR("ALIGNMENTCIVIC_ANY")));
  };

  inline static std::string RPG_Character_AlignmentCivicToString(const RPG_Character_AlignmentCivic& element_in)
  {
    std::string result;
    RPG_Character_AlignmentCivicToStringTableIterator_t iterator = myRPG_Character_AlignmentCivicToStringTable.find(element_in);
    if (iterator != myRPG_Character_AlignmentCivicToStringTable.end())
      result = iterator->second;
    else
      result = ACE_TEXT_ALWAYS_CHAR("RPG_CHARACTER_ALIGNMENTCIVIC_INVALID");

    return result;
  };

  inline static RPG_Character_AlignmentCivic stringToRPG_Character_AlignmentCivic(const std::string& string_in)
  {
    RPG_Character_AlignmentCivicToStringTableIterator_t iterator = myRPG_Character_AlignmentCivicToStringTable.begin();
    do
    {
      if (iterator->second == string_in)
        return iterator->first;

      iterator++;
    } while (iterator != myRPG_Character_AlignmentCivicToStringTable.end());

    return RPG_CHARACTER_ALIGNMENTCIVIC_INVALID;
  };

  static RPG_Character_AlignmentCivicToStringTable_t myRPG_Character_AlignmentCivicToStringTable;

 private:
  ACE_UNIMPLEMENTED_FUNC(RPG_Character_AlignmentCivicHelper());
  ACE_UNIMPLEMENTED_FUNC(RPG_Character_AlignmentCivicHelper(const RPG_Character_AlignmentCivicHelper&));
  ACE_UNIMPLEMENTED_FUNC(RPG_Character_AlignmentCivicHelper& operator=(const RPG_Character_AlignmentCivicHelper&));
};

#endif
