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

#ifndef RPG_COMBAT_DEFENSESITUATION_H
#define RPG_COMBAT_DEFENSESITUATION_H

enum RPG_Combat_DefenseSituation
{
  DEFENSE_NORMAL = 0,
  DEFENSE_TOUCH,
  DEFENSE_FLATFOOTED,
  //
  RPG_COMBAT_DEFENSESITUATION_MAX,
  RPG_COMBAT_DEFENSESITUATION_INVALID
};

#include <ace/Global_Macros.h>

#include <map>
#include <string>

typedef std::map<RPG_Combat_DefenseSituation, std::string> RPG_Combat_DefenseSituationToStringTable_t;
typedef RPG_Combat_DefenseSituationToStringTable_t::const_iterator RPG_Combat_DefenseSituationToStringTableIterator_t;

class RPG_Combat_DefenseSituationHelper
{
 public:
  inline static void init()
  {
    myRPG_Combat_DefenseSituationToStringTable.clear();
    myRPG_Combat_DefenseSituationToStringTable.insert(std::make_pair(DEFENSE_NORMAL, ACE_TEXT_ALWAYS_CHAR("DEFENSE_NORMAL")));
    myRPG_Combat_DefenseSituationToStringTable.insert(std::make_pair(DEFENSE_TOUCH, ACE_TEXT_ALWAYS_CHAR("DEFENSE_TOUCH")));
    myRPG_Combat_DefenseSituationToStringTable.insert(std::make_pair(DEFENSE_FLATFOOTED, ACE_TEXT_ALWAYS_CHAR("DEFENSE_FLATFOOTED")));
  };

  inline static std::string RPG_Combat_DefenseSituationToString(const RPG_Combat_DefenseSituation& element_in)
  {
    std::string result;
    RPG_Combat_DefenseSituationToStringTableIterator_t iterator = myRPG_Combat_DefenseSituationToStringTable.find(element_in);
    if (iterator != myRPG_Combat_DefenseSituationToStringTable.end())
      result = iterator->second;
    else
      result = ACE_TEXT_ALWAYS_CHAR("RPG_COMBAT_DEFENSESITUATION_INVALID");

    return result;
  };

  inline static RPG_Combat_DefenseSituation stringToRPG_Combat_DefenseSituation(const std::string& string_in)
  {
    RPG_Combat_DefenseSituationToStringTableIterator_t iterator = myRPG_Combat_DefenseSituationToStringTable.begin();
    do
    {
      if (iterator->second == string_in)
        return iterator->first;

      iterator++;
    } while (iterator != myRPG_Combat_DefenseSituationToStringTable.end());

    return RPG_COMBAT_DEFENSESITUATION_INVALID;
  };

  static RPG_Combat_DefenseSituationToStringTable_t myRPG_Combat_DefenseSituationToStringTable;

 private:
  ACE_UNIMPLEMENTED_FUNC(RPG_Combat_DefenseSituationHelper());
  ACE_UNIMPLEMENTED_FUNC(RPG_Combat_DefenseSituationHelper(const RPG_Combat_DefenseSituationHelper&));
  ACE_UNIMPLEMENTED_FUNC(RPG_Combat_DefenseSituationHelper& operator=(const RPG_Combat_DefenseSituationHelper&));
};

#endif
