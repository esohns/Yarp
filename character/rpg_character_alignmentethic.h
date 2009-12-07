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

#ifndef RPG_CHARACTER_ALIGNMENTETHIC_H
#define RPG_CHARACTER_ALIGNMENTETHIC_H

enum RPG_Character_AlignmentEthic
{
  ALIGNMENTETHIC_GOOD = 0,
  ALIGNMENTETHIC_NEUTRAL,
  ALIGNMENTETHIC_EVIL,
  ALIGNMENTETHIC_ANY,
  //
  RPG_CHARACTER_ALIGNMENTETHIC_MAX,
  RPG_CHARACTER_ALIGNMENTETHIC_INVALID
};

#include <ace/Global_Macros.h>

#include <map>
#include <string>

typedef std::map<RPG_Character_AlignmentEthic, std::string> RPG_Character_AlignmentEthicToStringTable_t;
typedef RPG_Character_AlignmentEthicToStringTable_t::const_iterator RPG_Character_AlignmentEthicToStringTableIterator_t;

class RPG_Character_AlignmentEthicHelper
{
 public:
  inline static void init()
  {
    myRPG_Character_AlignmentEthicToStringTable.clear();
    myRPG_Character_AlignmentEthicToStringTable.insert(std::make_pair(ALIGNMENTETHIC_GOOD, ACE_TEXT_ALWAYS_CHAR("ALIGNMENTETHIC_GOOD")));
    myRPG_Character_AlignmentEthicToStringTable.insert(std::make_pair(ALIGNMENTETHIC_NEUTRAL, ACE_TEXT_ALWAYS_CHAR("ALIGNMENTETHIC_NEUTRAL")));
    myRPG_Character_AlignmentEthicToStringTable.insert(std::make_pair(ALIGNMENTETHIC_EVIL, ACE_TEXT_ALWAYS_CHAR("ALIGNMENTETHIC_EVIL")));
    myRPG_Character_AlignmentEthicToStringTable.insert(std::make_pair(ALIGNMENTETHIC_ANY, ACE_TEXT_ALWAYS_CHAR("ALIGNMENTETHIC_ANY")));
  };

  inline static std::string RPG_Character_AlignmentEthicToString(const RPG_Character_AlignmentEthic& element_in)
  {
    std::string result;
    RPG_Character_AlignmentEthicToStringTableIterator_t iterator = myRPG_Character_AlignmentEthicToStringTable.find(element_in);
    if (iterator != myRPG_Character_AlignmentEthicToStringTable.end())
      result = iterator->second;
    else
      result = ACE_TEXT_ALWAYS_CHAR("RPG_CHARACTER_ALIGNMENTETHIC_INVALID");

    return result;
  };

  inline static RPG_Character_AlignmentEthic stringToRPG_Character_AlignmentEthic(const std::string& string_in)
  {
    RPG_Character_AlignmentEthicToStringTableIterator_t iterator = myRPG_Character_AlignmentEthicToStringTable.begin();
    do
    {
      if (iterator->second == string_in)
        return iterator->first;

      iterator++;
    } while (iterator != myRPG_Character_AlignmentEthicToStringTable.end());

    return RPG_CHARACTER_ALIGNMENTETHIC_INVALID;
  };

  static RPG_Character_AlignmentEthicToStringTable_t myRPG_Character_AlignmentEthicToStringTable;

 private:
  ACE_UNIMPLEMENTED_FUNC(RPG_Character_AlignmentEthicHelper());
  ACE_UNIMPLEMENTED_FUNC(RPG_Character_AlignmentEthicHelper(const RPG_Character_AlignmentEthicHelper&));
  ACE_UNIMPLEMENTED_FUNC(RPG_Character_AlignmentEthicHelper& operator=(const RPG_Character_AlignmentEthicHelper&));
};

#endif