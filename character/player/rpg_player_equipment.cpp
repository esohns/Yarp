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

#include "rpg_player_equipment.h"

#include "rpg_player_equipment_common.h"

#include <rpg_item_base.h>
#include <rpg_item_weapon.h>
#include <rpg_item_armor.h>
#include <rpg_item_instance_manager.h>
#include <rpg_item_common_tools.h>

#include <rpg_common_macros.h>

#include <ace/Log_Msg.h>

RPG_Player_Equipment::RPG_Player_Equipment()
{
  RPG_TRACE(ACE_TEXT("RPG_Player_Equipment::RPG_Player_Equipment"));

}

RPG_Player_Equipment::~RPG_Player_Equipment()
{
  RPG_TRACE(ACE_TEXT("RPG_Player_Equipment::RPG_Player_Equipment"));

}

void
RPG_Player_Equipment::equip(const RPG_Item_ID_t& itemID_in,
                            const RPG_Character_EquipmentSlot& slot_in)
{
  RPG_TRACE(ACE_TEXT("RPG_Player_Equipment::equip"));

  // *TODO*: auto-choose appropriate slot
  ACE_ASSERT(slot_in != EQUIPMENTSLOT_ANY);

  myEquipment.insert(std::make_pair(slot_in, itemID_in));

//   // debug info
//   RPG_Item_Base* handle = NULL;
//   if (!RPG_ITEM_INSTANCE_MANAGER_SINGLETON::instance()->getItem(itemID_in, handle))
//   {
//     // debug info
//     ACE_DEBUG((LM_ERROR,
//                ACE_TEXT("invalid item ID: %d, aborting\n"),
//                itemID_in));
//
//     return;
//   } // end IF
//   ACE_ASSERT(handle);
//
//   ACE_DEBUG((LM_DEBUG,
//              ACE_TEXT("equipped item (ID: %d, type: \"%s\") @ \"%s\"\n"),
//              itemID_in,
//              RPG_Item_TypeHelper::RPG_Item_TypeToString(handle->getType()).c_str(),
//              RPG_Player_EquipmentSlotHelper::RPG_Player_EquipmentSlotToString(slot_in).c_str()));
}

void
RPG_Player_Equipment::unequip(const RPG_Character_EquipmentSlot& slot_in)
{
  RPG_TRACE(ACE_TEXT("RPG_Player_Equipment::unequip"));

  // sanity check
  if (slot_in == EQUIPMENTSLOT_ANY)
    strip();

  myEquipment.erase(slot_in);

//   ACE_DEBUG((LM_DEBUG,
//              ACE_TEXT("unequipped \"%s\"\n"),
//              RPG_Player_EquipmentSlotHelper::RPG_Player_EquipmentSlotToString(slot_in).c_str()));
}

void
RPG_Player_Equipment::strip()
{
  RPG_TRACE(ACE_TEXT("RPG_Player_Equipment::strip"));

  myEquipment.clear();

//   ACE_DEBUG((LM_DEBUG,
//              ACE_TEXT("unequipped ALL\n")));
}

const RPG_Item_WeaponType
RPG_Player_Equipment::getPrimaryWeapon(const RPG_Character_OffHand& offHand_in) const
{
  RPG_TRACE(ACE_TEXT("RPG_Player_Equipment::getPrimaryWeapon"));

  RPG_Character_EquipmentSlot slot = ((offHand_in == OFFHAND_LEFT) ? EQUIPMENTSLOT_HAND_RIGHT
                                                                   : EQUIPMENTSLOT_HAND_LEFT);

  // *TODO*; consider ambidexterity, etc...
  RPG_Player_EquipmentConstIterator_t iterator = myEquipment.find(slot);
  if (iterator == myEquipment.end())
  {
    // nothing equipped --> default is the bare fist...
    return UNARMED_WEAPON_STRIKE;
  } // end IF

  // find item type
  RPG_Item_Base* handle = NULL;
  if (!RPG_ITEM_INSTANCE_MANAGER_SINGLETON::instance()->get((*iterator).second,
                                                            handle))
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("invalid item (ID: %d), aborting\n"),
               (*iterator).second));

    return RPG_ITEM_WEAPONTYPE_INVALID;
  } // end IF

  // weapon ?
  if (handle->getType() != ITEM_WEAPON)
  {
    // equipped item is not a weapon...
    ACE_DEBUG((LM_DEBUG,
               ACE_TEXT("equipped item (ID: %d, type: \"%s\") is not a weapon: aborting\n"),
               (*iterator).second,
               RPG_Item_TypeHelper::RPG_Item_TypeToString(handle->getType()).c_str()));

    return RPG_ITEM_WEAPONTYPE_INVALID;
  } // end IF

  RPG_Item_Weapon* weapon = dynamic_cast<RPG_Item_Weapon*> (handle);
  ACE_ASSERT(weapon);

  return weapon->getWeaponType();
}

const RPG_Item_ArmorType
RPG_Player_Equipment::getBodyArmor() const
{
  RPG_TRACE(ACE_TEXT("RPG_Player_Equipment::getBodyArmor"));

  // *TODO*; consider helmets/gauntlets/boots/shields, etc...
  RPG_Player_EquipmentConstIterator_t iterator = myEquipment.find(EQUIPMENTSLOT_BODY);
  if (iterator == myEquipment.end())
  {
    // nothing equipped on body --> check torso
    iterator = myEquipment.find(EQUIPMENTSLOT_TORSO);
    if (iterator == myEquipment.end())
    {
      // nothing equipped --> default is "nakedness"...
      return ARMOR_NONE;
    } // end IF
  } // end IF

  // find item type
  RPG_Item_Base* handle = NULL;
  if (!RPG_ITEM_INSTANCE_MANAGER_SINGLETON::instance()->get((*iterator).second,
                                                            handle))
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("invalid item (ID: %d), aborting\n"),
               (*iterator).second));

    return RPG_ITEM_ARMORTYPE_INVALID;
  } // end IF

  // armor ?
  if (handle->getType() != ITEM_ARMOR)
  {
    // item is not an armor...
    return ARMOR_NONE;
  } // end IF

  RPG_Item_Armor* armor = dynamic_cast<RPG_Item_Armor*> (handle);
  ACE_ASSERT(armor);

  return armor->getArmorType();
}

const RPG_Item_ArmorType
RPG_Player_Equipment::getShield(const RPG_Character_OffHand& offHand_in) const
{
  RPG_TRACE(ACE_TEXT("RPG_Player_Equipment::getShield"));

  RPG_Character_EquipmentSlot slot = ((offHand_in == OFFHAND_LEFT) ? EQUIPMENTSLOT_HAND_LEFT
                                                                   : EQUIPMENTSLOT_HAND_RIGHT);

  // *TODO*; consider case where shield is in the primary hand, etc...
  RPG_Player_EquipmentConstIterator_t iterator = myEquipment.find(slot);
  if (iterator == myEquipment.end())
  {
    // nothing equipped...
    return ARMOR_NONE;
  } // end IF

  // find item type
  RPG_Item_Base* handle = NULL;
  if (!RPG_ITEM_INSTANCE_MANAGER_SINGLETON::instance()->get((*iterator).second,
                                                            handle))
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("invalid item (ID: %d), aborting\n"),
               (*iterator).second));

    return RPG_ITEM_ARMORTYPE_INVALID;
  } // end IF

  // armor ?
  if (handle->getType() != ITEM_ARMOR)
  {
    // item is not an armor...
    return ARMOR_NONE;
  } // end IF

  RPG_Item_Armor* armor = dynamic_cast<RPG_Item_Armor*> (handle);
  ACE_ASSERT(armor);

  // sanity check
  if (!RPG_Item_Common_Tools::isShield(armor->getArmorType()))
  {
    ACE_DEBUG((LM_DEBUG,
               ACE_TEXT("equipped armor (ID: %d, type: \"%s\") is not a shield: returning \"%s\"...\n"),
               (*iterator).second,
               RPG_Item_ArmorTypeHelper::RPG_Item_ArmorTypeToString(armor->getArmorType()).c_str(),
               RPG_Item_ArmorTypeHelper::RPG_Item_ArmorTypeToString(ARMOR_NONE).c_str()));

    // some kind of armor is equipped here, but it's not a shield...
    return ARMOR_NONE;
  } // end IF

  return armor->getArmorType();
}

const bool
RPG_Player_Equipment::isEquipped(const RPG_Item_ID_t& itemID_in) const
{
  RPG_TRACE(ACE_TEXT("RPG_Player_Equipment::isEquipped"));

  for (RPG_Player_EquipmentConstIterator_t iterator = myEquipment.begin();
       iterator != myEquipment.end();
       iterator++)
    if ((*iterator).second == itemID_in)
      return true;

  return false;
}

void
RPG_Player_Equipment::dump() const
{
  RPG_TRACE(ACE_TEXT("RPG_Player_Equipment::dump"));

  RPG_Item_Base* handle = NULL;
  for (RPG_Player_EquipmentConstIterator_t iterator = myEquipment.begin();
       iterator != myEquipment.end();
       iterator++)
  {
    // find item type
    if (!RPG_ITEM_INSTANCE_MANAGER_SINGLETON::instance()->get((*iterator).second,
                                                              handle))
    {
      ACE_DEBUG((LM_ERROR,
                 ACE_TEXT("invalid item (ID: %d), continuing\n"),
                 (*iterator).second));

      continue;
    } // end IF

    switch (handle->getType())
    {
      case ITEM_WEAPON:
      {
        RPG_Item_Weapon* weapon = dynamic_cast<RPG_Item_Weapon*>(handle);
        ACE_ASSERT(weapon);

        ACE_DEBUG((LM_DEBUG,
                   ACE_TEXT("slot \"%s\" --> weapon (ID: %d, type: %s)\n"),
                   RPG_Character_EquipmentSlotHelper::RPG_Character_EquipmentSlotToString((*iterator).first).c_str(),
                   (*iterator).second,
                   RPG_Item_WeaponTypeHelper::RPG_Item_WeaponTypeToString(weapon->getWeaponType()).c_str()));

        break;
      }
      case ITEM_ARMOR:
      {
        RPG_Item_Armor* armor = dynamic_cast<RPG_Item_Armor*>(handle);
        ACE_ASSERT(armor);

        ACE_DEBUG((LM_DEBUG,
                   ACE_TEXT("slot \"%s\" --> armor (ID: %d, type: %s)\n"),
                   RPG_Character_EquipmentSlotHelper::RPG_Character_EquipmentSlotToString((*iterator).first).c_str(),
                   (*iterator).second,
                   RPG_Item_ArmorTypeHelper::RPG_Item_ArmorTypeToString(armor->getArmorType()).c_str()));

        break;
      }
      default:
      {
        ACE_DEBUG((LM_DEBUG,
                   ACE_TEXT("slot \"%s\" --> item (ID: %d, type: %s)\n"),
                   RPG_Character_EquipmentSlotHelper::RPG_Character_EquipmentSlotToString((*iterator).first).c_str(),
                   (*iterator).second,
                   RPG_Item_TypeHelper::RPG_Item_TypeToString(handle->getType()).c_str()));

        break;
      }
    } // end SWITCH
  } // end FOR
}