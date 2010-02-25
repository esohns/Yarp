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

#ifndef RPG_COMMON_COUNTERMEASURE_H
#define RPG_COMMON_COUNTERMEASURE_H

enum RPG_Common_CounterMeasure
{
  COUNTERMEASURE_CHECK = 0,
  COUNTERMEASURE_SPELL,
  //
  RPG_COMMON_COUNTERMEASURE_MAX,
  RPG_COMMON_COUNTERMEASURE_INVALID
};

#include <ace/Global_Macros.h>

#include <map>
#include <string>

typedef std::map<RPG_Common_CounterMeasure, std::string> RPG_Common_CounterMeasureToStringTable_t;
typedef RPG_Common_CounterMeasureToStringTable_t::const_iterator RPG_Common_CounterMeasureToStringTableIterator_t;

class RPG_Common_CounterMeasureHelper
{
 public:
  inline static void init()
  {
    myRPG_Common_CounterMeasureToStringTable.clear();
    myRPG_Common_CounterMeasureToStringTable.insert(std::make_pair(COUNTERMEASURE_CHECK, ACE_TEXT_ALWAYS_CHAR("COUNTERMEASURE_CHECK")));
    myRPG_Common_CounterMeasureToStringTable.insert(std::make_pair(COUNTERMEASURE_SPELL, ACE_TEXT_ALWAYS_CHAR("COUNTERMEASURE_SPELL")));
  };

  inline static std::string RPG_Common_CounterMeasureToString(const RPG_Common_CounterMeasure& element_in)
  {
    std::string result;
    RPG_Common_CounterMeasureToStringTableIterator_t iterator = myRPG_Common_CounterMeasureToStringTable.find(element_in);
    if (iterator != myRPG_Common_CounterMeasureToStringTable.end())
      result = iterator->second;
    else
      result = ACE_TEXT_ALWAYS_CHAR("RPG_COMMON_COUNTERMEASURE_INVALID");

    return result;
  };

  inline static RPG_Common_CounterMeasure stringToRPG_Common_CounterMeasure(const std::string& string_in)
  {
    RPG_Common_CounterMeasureToStringTableIterator_t iterator = myRPG_Common_CounterMeasureToStringTable.begin();
    do
    {
      if (iterator->second == string_in)
        return iterator->first;

      iterator++;
    } while (iterator != myRPG_Common_CounterMeasureToStringTable.end());

    return RPG_COMMON_COUNTERMEASURE_INVALID;
  };

  static RPG_Common_CounterMeasureToStringTable_t myRPG_Common_CounterMeasureToStringTable;

 private:
  ACE_UNIMPLEMENTED_FUNC(RPG_Common_CounterMeasureHelper());
  ACE_UNIMPLEMENTED_FUNC(RPG_Common_CounterMeasureHelper(const RPG_Common_CounterMeasureHelper&));
  ACE_UNIMPLEMENTED_FUNC(RPG_Common_CounterMeasureHelper& operator=(const RPG_Common_CounterMeasureHelper&));
};

#endif
