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
#include "rpg_character_player.h"

#include "rpg_character_defines.h"
#include "rpg_character_player_XML_tree.h"

#include "rpg_XMLSchema_XML_tree.h"

#include <rpg_item_instance_common.h>
#include <rpg_item_instance_manager.h>
#include <rpg_item_base.h>
#include <rpg_item_armor_base.h>
#include <rpg_item_weapon_base.h>
#include <rpg_item_common_tools.h>

#include <rpg_common_file_tools.h>

#include <ace/Log_Msg.h>

#include <fstream>

// init statics
RPG_Character_Player::XSD_Error_Handler RPG_Character_Player::myXSDErrorHandler;

RPG_Character_Player::RPG_Character_Player(const std::string& name_in,
                                           const RPG_Character_Gender& gender_in,
                                           const RPG_Character_Race& race_in,
                                           const RPG_Character_Class& class_in,
                                           const RPG_Character_Alignment& alignment_in,
                                           const RPG_Character_Attributes& attributes_in,
                                           const RPG_Character_Skills_t& skills_in,
                                           const RPG_Character_Feats_t& feats_in,
                                           const RPG_Character_Abilities_t& abilities_in,
                                           const RPG_Character_OffHand& offhand_in,
                                           const unsigned int& experience_in,
                                           const unsigned short int& hitpoints_in,
                                           const unsigned int& wealth_in,
                                           const RPG_Magic_Spells_t& knownSpells_in,
                                           const RPG_Magic_SpellList_t& spells_in,
                                           const RPG_Item_List_t& inventory_in)
 : inherited(name_in,
             gender_in,
             race_in,
             class_in,
             alignment_in,
             attributes_in,
             skills_in,
             feats_in,
             abilities_in,
             offhand_in,
             experience_in,
             hitpoints_in,
             wealth_in,
             knownSpells_in,
             spells_in,
             inventory_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Player::RPG_Character_Player"));

  // wear default items...
  defaultEquip();
//   myEquipment.dump();
}

RPG_Character_Player::RPG_Character_Player(const RPG_Character_Player& player_in)
 : inherited(player_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Player::RPG_Character_Player"));

}

RPG_Character_Player::RPG_Character_Player()
 : inherited()
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Player::RPG_Character_Player"));

}

RPG_Character_Player::~RPG_Character_Player()
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Player::~RPG_Character_Player"));

}

RPG_Character_Player&
RPG_Character_Player::operator=(const RPG_Character_Player& player_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Player::operator="));

  inherited::operator=(player_in);

  return *this;
}

const RPG_Character_Player
RPG_Character_Player::load(const std::string& filename_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Player::load"));

  // init result
  RPG_Character_Player result;

  // sanity check(s)
  if (!RPG_Common_File_Tools::isReadable(filename_in))
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to RPG_Common_File_Tools::isReadable(\"%s\"), aborting\n"),
               filename_in.c_str()));

    // *TODO*: returning an unininitialized result !
    return result;
  } // end IF

  std::ifstream ifs;
  ifs.exceptions(std::ifstream::badbit | std::ifstream::failbit);
//   ::xml_schema::flags = ::xml_schema::flags::dont_validate;
  ::xml_schema::flags flags = 0;
  ::xml_schema::properties props;
  props.no_namespace_schema_location(RPG_CHARACTER_PLAYER_SCHEMA_FILE);
//   props.schema_location("http://www.w3.org/XML/1998/namespace", "xml.xsd");
  try
  {
    ifs.open(filename_in.c_str(),
             std::ios_base::in);

    ::std::auto_ptr< ::RPG_Character_PlayerXML_XMLTree_Type > player_p = player(ifs,
                                                                                RPG_Character_Player::myXSDErrorHandler,
                                                                                flags,
                                                                                props);
  }
  catch (const std::ifstream::failure&)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("\"%s\": unable to open or read error, aborting\n"),
               filename_in.c_str()));

    // *TODO*: returning an unininitialized result !
    return result;
  }
  catch (const ::xml_schema::parsing& exception)
  {
    std::ostringstream converter;
    converter << exception;
    std::string text = converter.str();
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("RPG_Character_Player::load(\"%s\"): exception occurred: \"%s\", aborting\n"),
               filename_in.c_str(),
               text.c_str()));

    throw exception;
  }
  catch (...)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("RPG_Character_Player::load(\"%s\"): exception occurred, aborting\n"),
               filename_in.c_str()));

    throw;
  }

  return result;
}

const bool
RPG_Character_Player::save(const std::string& filename_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Player::save"));

  // sanity check(s)
  if (RPG_Common_File_Tools::isReadable(filename_in))
  {
    // *TODO*: warn user ?
//     if (!RPG_Common_File_Tools::deleteFile(filename_in))
//     {
//       ACE_DEBUG((LM_ERROR,
//                  ACE_TEXT("failed to RPG_Common_File_Tools::deleteFile(\"%s\"), aborting\n"),
//                  filename_in.c_str()));
//
//       return false;
//     } // end IF
  } // end IF

  std::ofstream ofs;
  ofs.exceptions(std::ofstream::badbit | std::ofstream::failbit);
  ::xml_schema::namespace_infomap map;
  map[""].schema = RPG_CHARACTER_PLAYER_SCHEMA_FILE;
  std::string character_set(RPG_CHARACTER_PLAYER_SCHEMA_CHARSET);
  //   ::xml_schema::flags = ::xml_schema::flags::dont_validate;
  ::xml_schema::flags flags = 0;

  try
  {
    ofs.open(filename_in.c_str(),
             (std::ios_base::out | std::ios_base::trunc));

    RPG_Character_Alignment_XMLTree_Type alignment(RPG_Character_AlignmentCivicHelper::RPG_Character_AlignmentCivicToString(getAlignment().civic),
              RPG_Character_AlignmentEthicHelper::RPG_Character_AlignmentEthicToString(getAlignment().ethic));
    RPG_Character_Attributes_XMLTree_Type attributes(getAttribute(ATTRIBUTE_STRENGTH),
                                                     getAttribute(ATTRIBUTE_DEXTERITY),
                                                     getAttribute(ATTRIBUTE_CONSTITUTION),
                                                     getAttribute(ATTRIBUTE_INTELLIGENCE),
                                                     getAttribute(ATTRIBUTE_WISDOM),
                                                     getAttribute(ATTRIBUTE_CHARISMA));
    RPG_Character_Skills_XMLTree_Type skills;
    RPG_Character_Feats_XMLTree_Type feats;
    RPG_Character_Abilities_XMLTree_Type abilities;
    RPG_Character_ClassXML_XMLTree_Type classXML(RPG_Character_MetaClassHelper::RPG_Character_MetaClassToString(getClass().metaClass));
    for (RPG_Character_SubClassesIterator_t iterator = getClass().subClasses.begin();
         iterator != getClass().subClasses.end();
         iterator++)
      classXML.subClass().push_back(RPG_Common_SubClassHelper::RPG_Common_SubClassToString(*iterator));
    RPG_Character_PlayerXML_XMLTree_Type player_model(RPG_Character_GenderHelper::RPG_Character_GenderToString(getGender()),
                                                      alignment,
                                                      attributes,
                                                      skills,
                                                      feats,
                                                      abilities,
                                                      getExperience(),
                                                      getNumHitPoints(),
                                                      getNumTotalHitPoints(),
                                                      getWealth(),
                                                      getName(),
                                                      classXML,
                                                      RPG_Character_OffHandHelper::RPG_Character_OffHandToString(getOffHand()));
    player(ofs,
           player_model,
           map,
           character_set,
           flags);
  }
  catch (const std::ofstream::failure&)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("\"%s\": unable to open or write error, aborting\n"),
               filename_in.c_str()));

    return false;
  }
  catch (const ::xml_schema::serialization& exception)
  {
    std::ostringstream converter;
    converter << exception;
    std::string text = converter.str();
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("RPG_Character_Player::save(\"%s\"): exception occurred: \"%s\", aborting\n"),
               filename_in.c_str(),
               text.c_str()));

    throw exception;
  }
  catch (...)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("RPG_Character_Player::save(\"%s\"): exception occurred, aborting\n"),
               filename_in.c_str()));

    throw;
  }

  return true;
}

void
RPG_Character_Player::defaultEquip()
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Player::operator="));

  RPG_Item_Base* handle = NULL;
  for (RPG_Item_ListIterator_t iterator = myInventory.myItems.begin();
       iterator != myInventory.myItems.end();
       iterator++)
  {
    handle = NULL;
    if (!RPG_ITEM_INSTANCE_MANAGER_SINGLETON::instance()->getItem(*iterator, handle))
    {
      ACE_DEBUG((LM_ERROR,
                 ACE_TEXT("invalid item ID: %d, aborting\n"),
                 *iterator));

      return;
    } // end IF
    ACE_ASSERT(handle);

    switch (handle->getType())
    {
      case ITEM_ARMOR:
      {
        RPG_Item_Armor_Base* armor_base = ACE_dynamic_cast(RPG_Item_Armor_Base*, handle);
        ACE_ASSERT(armor_base);
//         RPG_Item_ArmorProperties armor_properties = RPG_ITEM_DICTIONARY_SINGLETON::instance()->getArmorProperties(armor_base->getArmorType());
        // shield or (body) armor ?
        // *TODO*: what about other types of armor ?
        RPG_Character_EquipmentSlot slot = EQUIPMENTSLOT_BODY;
        if (RPG_Item_Common_Tools::isShield(armor_base->getArmorType()))
        {
          slot = ((getOffHand() == OFFHAND_LEFT) ? EQUIPMENTSLOT_HAND_LEFT
                                                 : EQUIPMENTSLOT_HAND_RIGHT);
        } // end IF
        myEquipment.equip(*iterator, slot);

        break;
      }
      case ITEM_WEAPON:
      {
        RPG_Item_Weapon_Base* weapon_base = ACE_dynamic_cast(RPG_Item_Weapon_Base*, handle);
        ACE_ASSERT(weapon_base);
//         RPG_Item_WeaponProperties weapon_properties = RPG_ITEM_DICTIONARY_SINGLETON::instance()->getWeaponProperties(weapon_base->getWeaponType());
        // - by default, equip melee weapons only
        // *TODO*: what about other types of weapons ?
        if (!RPG_Item_Common_Tools::isMeleeWeapon(weapon_base->getWeaponType()))
          break;

        RPG_Character_EquipmentSlot slot = ((getOffHand() == OFFHAND_LEFT) ? EQUIPMENTSLOT_HAND_RIGHT
                                                                           : EQUIPMENTSLOT_HAND_LEFT);
        myEquipment.equip(*iterator, slot);
        if (RPG_Item_Common_Tools::isTwoHandedWeapon(weapon_base->getWeaponType()))
        {
          slot = ((getOffHand() == OFFHAND_LEFT) ? EQUIPMENTSLOT_HAND_LEFT
                                                 : EQUIPMENTSLOT_HAND_RIGHT);
          myEquipment.equip(*iterator, slot);
        } // end IF

        break;
      }
      default:
      {
        ACE_DEBUG((LM_DEBUG,
                   ACE_TEXT("item ID %d: invalid type: \"%s\", continuing\n"),
                   *iterator,
                   RPG_Item_TypeHelper::RPG_Item_TypeToString(handle->getType()).c_str()));

        break;
      }
    } // end SWITCH
  } // end FOR
}

bool
RPG_Character_Player::XSD_Error_Handler::handle(const std::string& id_in,
                                                unsigned long line_in,
                                                unsigned long column_in,
                                                ::xsd::cxx::xml::error_handler<char>::severity severity_in,
                                                const std::string& message_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Player::XSD_Error_Handler::handle"));

//   ACE_DEBUG((LM_DEBUG,
//              ACE_TEXT("error occured (ID: \"%s\", location: %d, %d): \"%s\", continuing\n"),
//              id_in.c_str(),
//              line_in,
//              column_in,
//              message_in.c_str()));

  switch (severity_in)
  {
    case ::xml_schema::error_handler::severity::warning:
    {
      ACE_DEBUG((LM_WARNING,
                 ACE_TEXT("WARNING: error occured (ID: \"%s\", location: %d, %d): \"%s\", continuing\n"),
                 id_in.c_str(),
                 line_in,
                 column_in,
                 message_in.c_str()));

      break;
    }
    case ::xml_schema::error_handler::severity::error:
    {
      ACE_DEBUG((LM_ERROR,
                 ACE_TEXT("ERROR: error occured (ID: \"%s\", location: %d, %d): \"%s\", continuing\n"),
                 id_in.c_str(),
                 line_in,
                 column_in,
                 message_in.c_str()));

      break;
    }
    case ::xml_schema::error_handler::severity::fatal:
    {
      ACE_DEBUG((LM_CRITICAL,
                 ACE_TEXT("FATAL: error occured (ID: \"%s\", location: %d, %d): \"%s\", continuing\n"),
                 id_in.c_str(),
                 line_in,
                 column_in,
                 message_in.c_str()));

      break;
    }
    default:
    {
      ACE_DEBUG((LM_DEBUG,
                 ACE_TEXT("unkown error occured (ID: \"%s\", location: %d, %d): \"%s\", continuing\n"),
                 id_in.c_str(),
                 line_in,
                 column_in,
                 message_in.c_str()));

      break;
    }
  } // end SWITCH

  // try to continue anyway...
  return true;
}
