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

#ifndef RPG_CHARACTER_EQUIPMENTSLOT_H
#define RPG_CHARACTER_EQUIPMENTSLOT_H

enum RPG_Character_EquipmentSlot
{
  EQUIPMENTSLOT_HEAD = 0,
  EQUIPMENTSLOT_NECK,
  EQUIPMENTSLOT_APPAREL,
  EQUIPMENTSLOT_RIGHT_HAND,
  EQUIPMENTSLOT_LEFT_HAND,
  EQUIPMENTSLOT_GAUNTLETS,
  EQUIPMENTSLOT_RING,
  EQUIPMENTSLOT_FEET,
  //
  RPG_CHARACTER_EQUIPMENTSLOT_MAX,
  RPG_CHARACTER_EQUIPMENTSLOT_INVALID
};

#include <ace/Global_Macros.h>

#include <map>
#include <string>

typedef std::map<RPG_Character_EquipmentSlot, std::string> RPG_Character_EquipmentSlotToStringTable_t;
typedef RPG_Character_EquipmentSlotToStringTable_t::const_iterator RPG_Character_EquipmentSlotToStringTableIterator_t;

class RPG_Character_EquipmentSlotHelper
{
 public:
  inline static void init()
  {
    myRPG_Character_EquipmentSlotToStringTable.clear();
    myRPG_Character_EquipmentSlotToStringTable.insert(std::make_pair(EQUIPMENTSLOT_HEAD, ACE_TEXT_ALWAYS_CHAR("EQUIPMENTSLOT_HEAD")));
    myRPG_Character_EquipmentSlotToStringTable.insert(std::make_pair(EQUIPMENTSLOT_NECK, ACE_TEXT_ALWAYS_CHAR("EQUIPMENTSLOT_NECK")));
    myRPG_Character_EquipmentSlotToStringTable.insert(std::make_pair(EQUIPMENTSLOT_APPAREL, ACE_TEXT_ALWAYS_CHAR("EQUIPMENTSLOT_APPAREL")));
    myRPG_Character_EquipmentSlotToStringTable.insert(std::make_pair(EQUIPMENTSLOT_RIGHT_HAND, ACE_TEXT_ALWAYS_CHAR("EQUIPMENTSLOT_RIGHT_HAND")));
    myRPG_Character_EquipmentSlotToStringTable.insert(std::make_pair(EQUIPMENTSLOT_LEFT_HAND, ACE_TEXT_ALWAYS_CHAR("EQUIPMENTSLOT_LEFT_HAND")));
    myRPG_Character_EquipmentSlotToStringTable.insert(std::make_pair(EQUIPMENTSLOT_GAUNTLETS, ACE_TEXT_ALWAYS_CHAR("EQUIPMENTSLOT_GAUNTLETS")));
    myRPG_Character_EquipmentSlotToStringTable.insert(std::make_pair(EQUIPMENTSLOT_RING, ACE_TEXT_ALWAYS_CHAR("EQUIPMENTSLOT_RING")));
    myRPG_Character_EquipmentSlotToStringTable.insert(std::make_pair(EQUIPMENTSLOT_FEET, ACE_TEXT_ALWAYS_CHAR("EQUIPMENTSLOT_FEET")));
  };

  inline static std::string RPG_Character_EquipmentSlotToString(const RPG_Character_EquipmentSlot& element_in)
  {
    std::string result;
    RPG_Character_EquipmentSlotToStringTableIterator_t iterator = myRPG_Character_EquipmentSlotToStringTable.find(element_in);
    if (iterator != myRPG_Character_EquipmentSlotToStringTable.end())
      result = iterator->second;
    else
      result = ACE_TEXT_ALWAYS_CHAR("RPG_CHARACTER_EQUIPMENTSLOT_INVALID");

    return result;
  };

  inline static RPG_Character_EquipmentSlot stringToRPG_Character_EquipmentSlot(const std::string& string_in)
  {
    RPG_Character_EquipmentSlotToStringTableIterator_t iterator = myRPG_Character_EquipmentSlotToStringTable.begin();
    do
    {
      if (iterator->second == string_in)
        return iterator->first;

      iterator++;
    } while (iterator != myRPG_Character_EquipmentSlotToStringTable.end());

    return RPG_CHARACTER_EQUIPMENTSLOT_INVALID;
  };

  static RPG_Character_EquipmentSlotToStringTable_t myRPG_Character_EquipmentSlotToStringTable;

 private:
  ACE_UNIMPLEMENTED_FUNC(RPG_Character_EquipmentSlotHelper());
  ACE_UNIMPLEMENTED_FUNC(RPG_Character_EquipmentSlotHelper(const RPG_Character_EquipmentSlotHelper&));
  ACE_UNIMPLEMENTED_FUNC(RPG_Character_EquipmentSlotHelper& operator=(const RPG_Character_EquipmentSlotHelper&));
};

#endif
