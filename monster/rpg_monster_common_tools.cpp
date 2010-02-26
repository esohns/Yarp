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
#include "rpg_monster_common_tools.h"

#include <rpg_dice_common_tools.h>

#include <rpg_combat_common_tools.h>

#include <ace/Log_Msg.h>

#include <string>
#include <sstream>

// init statics
RPG_Monster_NaturalWeaponToStringTable_t RPG_Monster_NaturalWeaponHelper::myRPG_Monster_NaturalWeaponToStringTable;
RPG_Monster_OrganizationToStringTable_t RPG_Monster_OrganizationHelper::myRPG_Monster_OrganizationToStringTable;

void RPG_Monster_Common_Tools::initStringConversionTables()
{
  ACE_TRACE(ACE_TEXT("RPG_Monster_Common_Tools::initStringConversionTables"));

  RPG_Monster_NaturalWeaponHelper::init();
  RPG_Monster_OrganizationHelper::init();

  // debug info
  ACE_DEBUG((LM_DEBUG,
             ACE_TEXT("RPG_Monster_Common_Tools: initialized string conversion tables...\n")));
}

const std::string RPG_Monster_Common_Tools::weaponTypeToString(const RPG_Monster_WeaponTypeUnion& weaponType_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Monster_Common_Tools::weaponTypeToString"));

  std::string result;

  switch (weaponType_in.discriminator)
  {
    case RPG_Monster_WeaponTypeUnion::NATURALWEAPON:
    {
      return RPG_Monster_NaturalWeaponHelper::RPG_Monster_NaturalWeaponToString(weaponType_in.naturalweapon);
    }
    case RPG_Monster_WeaponTypeUnion::ABILITY:
    {
      return RPG_Character_AbilityHelper::RPG_Character_AbilityToString(weaponType_in.ability);
    }
    case RPG_Monster_WeaponTypeUnion::WEAPONTYPE:
    {
      return RPG_Item_WeaponTypeHelper::RPG_Item_WeaponTypeToString(weaponType_in.weapontype);
    }
    case RPG_Monster_WeaponTypeUnion::SPECIALATTACK:
    {
      return RPG_Combat_SpecialAttackHelper::RPG_Combat_SpecialAttackToString(weaponType_in.specialattack);
    }
    default:
    {
      // debug info
      ACE_DEBUG((LM_ERROR,
                 ACE_TEXT("invalid weapon type: %d, aborting\n"),
                 weaponType_in.discriminator));

      break;
    }
  } // end SWITCH

  return result;
}

const std::string RPG_Combat_Common_Tools::attackFormsToString(const RPG_Combat_AttackForms_t& attackForms_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Combat_Common_Tools::attackFormsToString"));

  std::string result;

  for (RPG_Combat_AttackFormsIterator_t iterator = attackForms_in.begin();
       iterator != attackForms_in.end();
       iterator++)
  {
    result += RPG_Combat_AttackFormHelper::RPG_Combat_AttackFormToString(*iterator);
    result += ACE_TEXT_ALWAYS_CHAR("|");
  } // end FOR

  if (!result.empty())
  {
    result.erase(--(result.end()));
  } // end IF

  return result;
}

const std::string RPG_Monster_Common_Tools::attackActionToString(const RPG_Monster_AttackAction& attackAction_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Monster_Common_Tools::attackActionToString"));

  std::string result;

  result += ACE_TEXT_ALWAYS_CHAR("weapon: ");
  result += RPG_Monster_Common_Tools::weaponTypeToString(attackAction_in.weapon);
  result += ACE_TEXT_ALWAYS_CHAR("\n");
  result += ACE_TEXT_ALWAYS_CHAR("attackBonus(es): ");
  std::stringstream str;
  for (std::vector<char>::const_iterator iterator = attackAction_in.attackBonuses.begin();
       iterator != attackAction_in.attackBonuses.end();
       iterator++)
  {
    str.str(ACE_TEXT_ALWAYS_CHAR(""));
    str << ACE_static_cast(int, *iterator);
    result += str.str();
    result += ACE_TEXT_ALWAYS_CHAR("/");
  } // end FOR
  if (!attackAction_in.attackBonuses.empty())
  {
    result.erase(--(result.end()));
  } // end IF
  str.str(ACE_TEXT_ALWAYS_CHAR(""));
  result += ACE_TEXT_ALWAYS_CHAR("\n");
  result += ACE_TEXT_ALWAYS_CHAR("attackForm: ");
  result += RPG_Combat_Common_Tools::attackFormsToString(attackAction_in.attackForms);
  result += ACE_TEXT_ALWAYS_CHAR("\n");
  result += RPG_Combat_Common_Tools::damageToString(attackAction_in.damage);
  result += ACE_TEXT_ALWAYS_CHAR("numAttacksPerRound: ");
  str << ACE_static_cast(int, attackAction_in.numAttacksPerRound);
  result += str.str();
  result += ACE_TEXT_ALWAYS_CHAR("\n");

  return result;
}

const std::string RPG_Monster_Common_Tools::attackToString(const RPG_Monster_Attack& attack_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Monster_Common_Tools::attackToString"));

  std::string result;

  std::stringstream str;
  result += ACE_TEXT_ALWAYS_CHAR("baseAttackBonus: ");
  str << ACE_static_cast(int, attack_in.baseAttackBonus);
  result += str.str();
  str.str(ACE_TEXT_ALWAYS_CHAR(""));
  result += ACE_TEXT_ALWAYS_CHAR("\n");
  result += ACE_TEXT_ALWAYS_CHAR("grappleBonus: ");
  str << ACE_static_cast(int, attack_in.grappleBonus);
  result += str.str();
//   str.str(ACE_TEXT_ALWAYS_CHAR(""));
  result += ACE_TEXT_ALWAYS_CHAR("\n");
  result += ACE_TEXT_ALWAYS_CHAR("Standard Attack Action(s):\n-----------------------\n");
  int i = 1;
  for (std::vector<RPG_Monster_AttackAction>::const_iterator iterator = attack_in.standardAttackActions.begin();
       iterator != attack_in.standardAttackActions.end();
       iterator++, i++)
  {
    result += ACE_TEXT_ALWAYS_CHAR("action #");
    str.str(ACE_TEXT_ALWAYS_CHAR(""));
    str << i;
    result += str.str();
    result += ACE_TEXT_ALWAYS_CHAR("\n");
    result += attackActionToString(*iterator);
  } // end FOR
  result += ACE_TEXT_ALWAYS_CHAR("Full Attack Action(s):\n---------------\n");
  i = 1;
  for (std::vector<RPG_Monster_AttackAction>::const_iterator iterator = attack_in.fullAttackActions.begin();
       iterator != attack_in.fullAttackActions.end();
       iterator++, i++)
  {
    result += ACE_TEXT_ALWAYS_CHAR("action #");
    str.str(ACE_TEXT_ALWAYS_CHAR(""));
    str << i;
    result += str.str();
    result += ACE_TEXT_ALWAYS_CHAR("\n");
    result += attackActionToString(*iterator);
  } // end FOR

  return result;
}

const std::string RPG_Monster_Common_Tools::organizationsToString(const RPG_Monster_OrganizationList_t& organizations_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Monster_Common_Tools::organizationsToString"));

  std::string result;
  for (RPG_Monster_OrganizationListIterator_t iterator = organizations_in.begin();
       iterator != organizations_in.end();
       iterator++)
  {
    result += RPG_Monster_OrganizationHelper::RPG_Monster_OrganizationToString(*iterator);
    result += ACE_TEXT_ALWAYS_CHAR("|");
  } // end FOR

  if (!result.empty())
  {
    result.erase(--(result.end()));
  } // end IF

  return result;
}

const std::string RPG_Monster_Common_Tools::organizationsToString(const RPG_Monster_Organizations_t& organizations_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Monster_Common_Tools::organizationsToString"));

  std::string result;
  std::string range_string;
  for (RPG_Monster_OrganizationsIterator_t iterator = organizations_in.begin();
       iterator != organizations_in.end();
       iterator++)
  {
    result += RPG_Monster_OrganizationHelper::RPG_Monster_OrganizationToString((*iterator).type);
    range_string = RPG_Dice_Common_Tools::rangeToString((*iterator).range);
    result += ACE_TEXT_ALWAYS_CHAR(": ");
    result += range_string;
    result += ACE_TEXT_ALWAYS_CHAR("\n");
  } // end FOR

  return result;
}

const std::string RPG_Monster_Common_Tools::advancementToString(const RPG_Monster_Advancement_t& advancement_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Monster_Common_Tools::advancementToString"));

  std::string result;
  for (RPG_Monster_AdvancementIterator_t iterator = advancement_in.begin();
       iterator != advancement_in.end();
       iterator++)
  {
    result += RPG_Character_SizeHelper::RPG_Character_SizeToString((*iterator).size);
    result += ACE_TEXT_ALWAYS_CHAR(": ");
    result += RPG_Dice_Common_Tools::rangeToString((*iterator).range);
    result += ACE_TEXT_ALWAYS_CHAR(" HD\n");
  } // end FOR

  return result;
}

const RPG_Common_PhysicalDamageList_t RPG_Monster_Common_Tools::naturalWeaponToPhysicalDamageType(const RPG_Monster_NaturalWeapon& naturalWeapon_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Monster_Common_Tools::naturalWeaponToPhysicalDamageType"));

  RPG_Common_PhysicalDamageList_t result;

  switch (naturalWeapon_in)
  {
    case NATURALWEAPON_BITE:
    case NATURALWEAPON_GORE:
    case NATURALWEAPON_STING:
    {
      result.insert(PHYSICALDAMAGE_PIERCING);

      break;
    }
    case NATURALWEAPON_CLAW_TALON:
    case NATURALWEAPON_PINCER:
    {
//       result.push_back(PHYSICALDAMAGE_PIERCING);
      result.insert(PHYSICALDAMAGE_SLASHING);

      break;
    }
    case NATURALWEAPON_BLAST:
    case NATURALWEAPON_CONSTRICT:
    case NATURALWEAPON_HOOF:
    case NATURALWEAPON_ROCK_STONE:
    case NATURALWEAPON_SLAP_SLAM:
    case NATURALWEAPON_TAIL:
    case NATURALWEAPON_TENTACLE:
    {
      result.insert(PHYSICALDAMAGE_BLUDGEONING);

      break;
    }
    case NATURALWEAPON_SPIT:
    case NATURALWEAPON_WEB:
    {
      result.insert(PHYSICALDAMAGE_NONE);

      break;
    }
    default:
    {
      // debug info
      ACE_DEBUG((LM_ERROR,
                 ACE_TEXT("invalid natural weapon: \"%s\", aborting\n"),
                 RPG_Monster_NaturalWeaponHelper::RPG_Monster_NaturalWeaponToString(naturalWeapon_in).c_str()));

      break;
    }
  } // end SWITCH

  return result;
}
