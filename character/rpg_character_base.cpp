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
#include "rpg_character_base.h"

#include "rpg_character_common_tools.h"
#include "rpg_character_skills_common_tools.h"

#include <rpg_item_common.h>
#include <rpg_item_dictionary.h>

#include <rpg_dice_dietype.h>
#include <rpg_dice_roll.h>
#include <rpg_dice_common.h>
#include <rpg_dice.h>

#include <ace/Log_Msg.h>

#include <string>

RPG_Character_Base::RPG_Character_Base(const std::string& name_in,
                                       const RPG_Character_Alignment& alignment_in,
                                       const RPG_Character_Attributes& attributes_in,
                                       const RPG_Character_Skills_t& skills_in,
                                       const RPG_Character_Feats_t& feats_in,
                                       const RPG_Character_Abilities_t& abilities_in,
                                       const RPG_Common_Size& defaultSize_in,
                                       const unsigned short int& hitpoints_in,
                                       const unsigned int& wealth_in,
                                       const RPG_Item_List_t& inventory_in)
 : myCurrentWealth(wealth_in),
   mySize(defaultSize_in),
   myInventory(inventory_in),
//    myEquipment(), // start naked
   myNumCurrentHitPoints(hitpoints_in), // we start out healthy, don't we ?
//    myConditions(), // start normal
   myName(name_in),
   myAlignment(alignment_in),
   myAttributes(attributes_in),
   mySkills(skills_in),
   myFeats(feats_in),
   myAbilities(abilities_in),
   myNumTotalHitPoints(hitpoints_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Base::RPG_Character_Base"));

  myConditions.insert(CONDITION_NORMAL);
}

RPG_Character_Base::RPG_Character_Base(const RPG_Character_Base& playerBase_in)
  : myCurrentWealth(playerBase_in.myCurrentWealth),
    mySize(playerBase_in.mySize),
    myInventory(playerBase_in.myInventory),
    myEquipment(playerBase_in.myEquipment),
    myNumCurrentHitPoints(playerBase_in.myNumCurrentHitPoints),
    myConditions(playerBase_in.myConditions),
    myName(playerBase_in.myName),
    myAlignment(playerBase_in.myAlignment),
    myAttributes(playerBase_in.myAttributes),
    mySkills(playerBase_in.mySkills),
    myFeats(playerBase_in.myFeats),
    myAbilities(playerBase_in.myAbilities),
    myNumTotalHitPoints(playerBase_in.myNumTotalHitPoints)
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Base::RPG_Character_Base"));

}

RPG_Character_Base& RPG_Character_Base::operator=(const RPG_Character_Base& playerBase_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Base::operator="));

  myCurrentWealth = playerBase_in.myCurrentWealth;
  mySize = playerBase_in.mySize;
  myInventory = playerBase_in.myInventory;
  myEquipment = playerBase_in.myEquipment;
  myNumCurrentHitPoints = playerBase_in.myNumCurrentHitPoints;
  myConditions = playerBase_in.myConditions;
  myName = playerBase_in.myName;
  myAlignment = playerBase_in.myAlignment;
  myAttributes = playerBase_in.myAttributes;
  mySkills = playerBase_in.mySkills;
  myFeats = playerBase_in.myFeats;
  myAbilities = playerBase_in.myAbilities;
  myNumTotalHitPoints = playerBase_in.myNumTotalHitPoints;

  return *this;
}

RPG_Character_Base::~RPG_Character_Base()
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Base::~RPG_Character_Base"));

}

const std::string RPG_Character_Base::getName() const
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Base::getName"));

  return myName;
}

const RPG_Character_Alignment RPG_Character_Base::getAlignment() const
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Base::getAlignment"));

  return myAlignment;
}

const unsigned char RPG_Character_Base::getAttribute(const RPG_Common_Attribute& attribute_in) const
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Base::getAttribute"));

  switch (attribute_in)
  {
    case ATTRIBUTE_STRENGTH:
    {
      return myAttributes.strength;
    }
    case ATTRIBUTE_DEXTERITY:
    {
      return myAttributes.dexterity;
    }
    case ATTRIBUTE_CONSTITUTION:
    {
      return myAttributes.constitution;
    }
    case ATTRIBUTE_INTELLIGENCE:
    {
      return myAttributes.intelligence;
    }
    case ATTRIBUTE_WISDOM:
    {
      return myAttributes.wisdom;
    }
    case ATTRIBUTE_CHARISMA:
    {
      return myAttributes.charisma;
    }
    default:
    {
      // debug info
      ACE_DEBUG((LM_ERROR,
                 ACE_TEXT("invalid attribute: \"%s\", aborting\n"),
                 RPG_Common_AttributeHelper::RPG_Common_AttributeToString(attribute_in).c_str()));

      break;
    }
  } // end SWITCH

  return 0;
}

void RPG_Character_Base::getSkill(const RPG_Common_Skill& skill_in,
                                  unsigned char& result_out) const
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Base::getSkill"));

  // init return value
  result_out = 0;

  RPG_Character_SkillsConstIterator_t iter = mySkills.find(skill_in);
  if (iter != mySkills.end())
  {
    result_out = iter->second;
  } // end IF
}

const bool RPG_Character_Base::hasFeat(const RPG_Character_Feat& feat_in) const
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Base::hasFeat"));

  return (myFeats.find(feat_in) != myFeats.end());
}

const bool RPG_Character_Base::hasAbility(const RPG_Character_Ability& ability_in) const
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Base::hasAbility"));

  return (myAbilities.find(ability_in) != myAbilities.end());
}

const RPG_Common_Size RPG_Character_Base::getSize() const
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Base::getSize"));

  return mySize;
}

const unsigned short int RPG_Character_Base::getNumTotalHitPoints() const
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Base::getNumTotalHitPoints"));

  return myNumTotalHitPoints;
}

const short int RPG_Character_Base::getNumCurrentHitPoints() const
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Base::getNumCurrentHitPoints"));

  return myNumCurrentHitPoints;
}

const unsigned int RPG_Character_Base::getCurrentWealth() const
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Base::getCurrentWealth"));

  return myCurrentWealth;
}

const bool RPG_Character_Base::hasCondition(const RPG_Common_Condition& condition_in) const
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Base::hasCondition"));

  return (myConditions.find(condition_in) != myConditions.end());
}

void RPG_Character_Base::sustainDamage(const RPG_Combat_Damage& damage_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Base::sustainDamage"));

  signed short damage_value = 0;
  signed short total_damage_value = 0;
  RPG_Dice_RollResult_t result;
  for (std::vector<RPG_Combat_DamageElement>::const_iterator iterator = damage_in.elements.begin();
       iterator != damage_in.elements.end();
       iterator++)
  {
    // compute damage
    damage_value = 0;
    result.clear();

    RPG_Dice::simulateRoll((*iterator).amount,
                           1,
                           result);
    damage_value = result.front();

    // *TODO*: consider defenses, resistances, (partial) immunities...

    // minimum damage is 1 HP
    if (damage_value <= 0)
      damage_value = 1;

    myNumCurrentHitPoints -= damage_value;

    total_damage_value += damage_value;
  } // end FOR

  if (myNumCurrentHitPoints < -10)
    myNumCurrentHitPoints = -10;

  // adjust condition
  if (myNumCurrentHitPoints <= 0)
  {
    myConditions.erase(CONDITION_NORMAL);

    if (myNumCurrentHitPoints == -10)
      myConditions.insert(CONDITION_DEAD);
    else if (myNumCurrentHitPoints < 0)
      myConditions.insert(CONDITION_DYING);
    else
      myConditions.insert(CONDITION_DISABLED);

    if (myNumCurrentHitPoints < 0)
      myConditions.insert(CONDITION_UNCONSCIOUS);
  } // end IF

  // debug info
  ACE_DEBUG((LM_DEBUG,
             ACE_TEXT("character \"%s\" (HP: %d/%d) suffers damage of %d HP%s...\n"),
             getName().c_str(),
             myNumCurrentHitPoints,
             myNumTotalHitPoints,
             total_damage_value,
             (!hasCondition(CONDITION_NORMAL) ? ACE_TEXT_ALWAYS_CHAR(" --> DOWN") : ACE_TEXT_ALWAYS_CHAR(""))));
}

void RPG_Character_Base::status() const
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Base::status"));

  ACE_DEBUG((LM_DEBUG,
             ACE_TEXT("condition: %s\nHP: %d/%d\nwealth: %d GP\n"),
             RPG_Character_Common_Tools::conditionToString(myConditions).c_str(),
             myNumCurrentHitPoints,
             myNumTotalHitPoints,
             myCurrentWealth));
}

void RPG_Character_Base::dump() const
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Base::dump"));

  ACE_DEBUG((LM_DEBUG,
             ACE_TEXT("Name: \"%s\"\nAlignment: \"%s\"\nAttributes:\n===========\n%sSkills:\n=======\n%sFeats:\n======\n%sAbilities:\n==========\n%sItems:\n======\n"),
             myName.c_str(),
             RPG_Character_Common_Tools::alignmentToString(myAlignment).c_str(),
             RPG_Character_Common_Tools::attributesToString(myAttributes).c_str(),
             RPG_Character_Skills_Common_Tools::skillsToString(mySkills).c_str(),
             RPG_Character_Skills_Common_Tools::featsToString(myFeats).c_str(),
             RPG_Character_Skills_Common_Tools::abilitiesToString(myAbilities).c_str()));

  // dump items
  myInventory.dump();
}
