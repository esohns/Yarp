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
#include "rpg_chance_dice_common_tools.h"

#include <ace/Log_Msg.h>

#include <sstream>

// init statics
RPG_Chance_Dice_Common_Tools::RPG_Chance_Dice_StringToDiceType_t RPG_Chance_Dice_Common_Tools::myStringToDiceTypeTable;

void RPG_Chance_Dice_Common_Tools::initStringConversionTables()
{
  ACE_TRACE(ACE_TEXT("RPG_Chance_Dice_Common_Tools::initStringConversionTables"));

  // clean tables
  myStringToDiceTypeTable.clear();

  // RPG_Chance_DiceType
  myStringToDiceTypeTable.insert(std::make_pair(ACE_TEXT_ALWAYS_CHAR("D_0"), D_0));
  myStringToDiceTypeTable.insert(std::make_pair(ACE_TEXT_ALWAYS_CHAR("D_2"), D_2));
  myStringToDiceTypeTable.insert(std::make_pair(ACE_TEXT_ALWAYS_CHAR("D_3"), D_3));
  myStringToDiceTypeTable.insert(std::make_pair(ACE_TEXT_ALWAYS_CHAR("D_4"), D_4));
  myStringToDiceTypeTable.insert(std::make_pair(ACE_TEXT_ALWAYS_CHAR("D_6"), D_6));
  myStringToDiceTypeTable.insert(std::make_pair(ACE_TEXT_ALWAYS_CHAR("D_8"), D_8));
  myStringToDiceTypeTable.insert(std::make_pair(ACE_TEXT_ALWAYS_CHAR("D_10"), D_10));
  myStringToDiceTypeTable.insert(std::make_pair(ACE_TEXT_ALWAYS_CHAR("D_12"), D_12));
  myStringToDiceTypeTable.insert(std::make_pair(ACE_TEXT_ALWAYS_CHAR("D_20"), D_20));
  myStringToDiceTypeTable.insert(std::make_pair(ACE_TEXT_ALWAYS_CHAR("D_100"), D_100));

  // debug info
  ACE_DEBUG((LM_DEBUG,
             ACE_TEXT("RPG_Chance_Dice_Common_Tools: initialized string conversion tables...\n")));
}

const RPG_Chance_DiceType RPG_Chance_Dice_Common_Tools::stringToDiceType(const std::string& string_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Chance_Dice_Common_Tools::stringToDiceType"));

  RPG_Chance_Dice_StringToDiceTypeIterator_t iterator = myStringToDiceTypeTable.find(string_in);
  if (iterator == myStringToDiceTypeTable.end())
  {
    // debug info
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("invalid dice type: \"%s\" --> check implementation !, returning\n"),
               string_in.c_str()));

    return D_TYPE_INVALID;
  } // end IF

  return iterator->second;
}

const std::string RPG_Chance_Dice_Common_Tools::diceTypeToString(const RPG_Chance_DiceType& diceType_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Chance_Dice_Common_Tools::diceTypeToString"));

  RPG_Chance_Dice_StringToDiceTypeIterator_t iterator = myStringToDiceTypeTable.begin();
  do
  {
    if (iterator->second == diceType_in)
    {
      // done
      return iterator->first;
    } // end IF

    iterator++;
  } while (iterator != myStringToDiceTypeTable.end());

  // debug info
  ACE_DEBUG((LM_ERROR,
             ACE_TEXT("invalid dice type: %d --> check implementation !, aborting\n"),
             diceType_in));

  return std::string(ACE_TEXT_ALWAYS_CHAR("D_TYPE_INVALID"));
}

const std::string RPG_Chance_Dice_Common_Tools::rollToString(const RPG_Chance_DiceRoll& diceRoll_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Chance_Dice_Common_Tools::rollToString"));

  std::string result;
  std::stringstream str;

  str << diceRoll_in.numDice;
  result += str.str();
  result += RPG_Chance_Dice_Common_Tools::diceTypeToString(diceRoll_in.typeDice);

  if (diceRoll_in.modifier == 0)
  {
    return result;
  } // end IF
  else if (diceRoll_in.modifier > 0)
  {
    result += ACE_TEXT_ALWAYS_CHAR("+");
  } // end IF
  str.str(ACE_TEXT_ALWAYS_CHAR(""));
  str << diceRoll_in.modifier;
  result += str.str();

  return result;
}

const std::string RPG_Chance_Dice_Common_Tools::rangeToString(const RPG_Chance_ValueRange& range_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Chance_Dice_Common_Tools::rangeToString"));

  std::string result;
  std::stringstream str;

  str << range_in.begin;
  str << ACE_TEXT_ALWAYS_CHAR("-");
  str << range_in.end;

  result = str.str();

  return result;
}
