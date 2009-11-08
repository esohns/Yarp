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

#include <ace/OS.h>
#include <ace/Log_Msg.h>

#include <string>
#include <iostream>

RPG_Character_Base::RPG_Character_Base(const RPG_Character_Gender& gender_in,
                                       const RPG_Character_Race& race_in,
                                       const RPG_Character_Class& class_in,
                                       const RPG_Character_Alignment& alignment_in,
                                       const RPG_Character_Attributes& attributes_in,
                                       const RPG_Character_Skills_t& skills_in,
                                       const RPG_Character_Feats_t& feats_in,
                                       const RPG_Character_Abilities_t& abilities_in,
                                       const unsigned int& experience_in,
                                       const unsigned short int& hitpoints_in,
                                       const unsigned int& wealth_in,
                                       const RPG_Item_List_t& inventory_in)
 : myGender(gender_in),
   myRace(race_in),
   myClass(class_in),
   myAlignment(alignment_in),
   myAttributes(attributes_in),
   mySkills(skills_in),
   myFeats(feats_in),
   myAbilities(abilities_in),
   myExperience(experience_in),
   myNumTotalHitPoints(hitpoints_in),
   myNumCurrentHitPoints(hitpoints_in), // we start out healthy, don't we ?
   myCurrentWealth(wealth_in),
   myCondition(CONDITION_NORMAL), // start normal
   myInventory(inventory_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Base::RPG_Character_Base"));

}

RPG_Character_Base::~RPG_Character_Base()
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Base::~RPG_Character_Base"));

}

const RPG_Character_Gender RPG_Character_Base::getGender() const
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Base::getGender"));

  return myGender;
}

const RPG_Character_Race RPG_Character_Base::getRace() const
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Base::getRace"));

  return myRace;
}

const RPG_Character_Class RPG_Character_Base::getClass() const
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Base::getClass"));

  return myClass;
}

const RPG_Character_Alignment RPG_Character_Base::getAlignment() const
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Base::getAlignment"));

  return myAlignment;
}

const unsigned char RPG_Character_Base::getStrength() const
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Base::getStrength"));

  return myAttributes.strength;
}

const unsigned char RPG_Character_Base::getDexterity() const
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Base::getDexterity"));

  return myAttributes.dexterity;
}

const unsigned char RPG_Character_Base::getConstitution() const
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Base::getConstitution"));

  return myAttributes.constitution;
}

const unsigned char RPG_Character_Base::getIntelligence() const
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Base::getIntelligence"));

  return myAttributes.intelligence;
}

const unsigned char RPG_Character_Base::getWisdom() const
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Base::getWisdom"));

  return myAttributes.wisdom;
}

const unsigned char RPG_Character_Base::getCharisma() const
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Base::getCharisma"));

  return myAttributes.charisma;
}

void RPG_Character_Base::getSkill(const RPG_Character_Skill& skill_in,
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

const unsigned char RPG_Character_Base::getLevel() const
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Base::getLevel"));

  // *TODO*: consider implementing class-specific tables...
  return ACE_static_cast(unsigned int,
                         ACE_OS::floor((1.0 + ::sqrt((myExperience / 125) + 1)) / 2.0));
}

const unsigned int RPG_Character_Base::getExperience() const
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Base::getExperience"));

  return myExperience;
}

const unsigned short int RPG_Character_Base::getNumTotalHitPoints() const
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Base::getNumTotalHitPoints"));

  return myNumTotalHitPoints;
}

const unsigned short int RPG_Character_Base::getNumCurrentHitPoints() const
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Base::getNumCurrentHitPoints"));

  return myNumCurrentHitPoints;
}

const unsigned int RPG_Character_Base::getCurrentWealth() const
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Base::getCurrentWealth"));

  return myCurrentWealth;
}

const RPG_Character_Condition RPG_Character_Base::getCondition() const
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Base::getCondition"));

  return myCondition;
}

void RPG_Character_Base::dump() const
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Base::dump"));

  std::string gender = RPG_Character_Common_Tools::genderToString(myGender);
  std::string race = RPG_Character_Common_Tools::raceToString(myRace);
  std::string class_string = RPG_Character_Common_Tools::subClassToString(myClass.subClass);
  std::string alignment = RPG_Character_Common_Tools::alignmentToString(myAlignment);
  std::string attributes = RPG_Character_Common_Tools::attributeToString(ATTRIBUTE_STRENGTH);
  attributes += ACE_TEXT_ALWAYS_CHAR(": ");
  attributes += myAttributes.strength;
  attributes += ACE_TEXT_ALWAYS_CHAR("\n");
  attributes += RPG_Character_Common_Tools::attributeToString(ATTRIBUTE_DEXTERITY);
  attributes += ACE_TEXT_ALWAYS_CHAR(": ");
  attributes += myAttributes.dexterity;
  attributes += ACE_TEXT_ALWAYS_CHAR("\n");
  attributes += RPG_Character_Common_Tools::attributeToString(ATTRIBUTE_CONSTITUTION);
  attributes += ACE_TEXT_ALWAYS_CHAR(": ");
  attributes += myAttributes.constitution;
  attributes += ACE_TEXT_ALWAYS_CHAR("\n");
  attributes += RPG_Character_Common_Tools::attributeToString(ATTRIBUTE_INTELLIGENCE);
  attributes += ACE_TEXT_ALWAYS_CHAR(": ");
  attributes += myAttributes.intelligence;
  attributes += ACE_TEXT_ALWAYS_CHAR("\n");
  attributes += RPG_Character_Common_Tools::attributeToString(ATTRIBUTE_WISDOM);
  attributes += ACE_TEXT_ALWAYS_CHAR(": ");
  attributes += myAttributes.wisdom;
  attributes += ACE_TEXT_ALWAYS_CHAR("\n");
  attributes += RPG_Character_Common_Tools::attributeToString(ATTRIBUTE_CHARISMA);
  attributes += ACE_TEXT_ALWAYS_CHAR(": ");
  attributes += myAttributes.charisma;
  attributes += ACE_TEXT_ALWAYS_CHAR("\n");
  std::string skills;
  RPG_Character_Skills_Common_Tools::RPG_Character_Skill2StringTableIterator_t iterator;
  for (RPG_Character_SkillsConstIterator_t iterator2 = mySkills.begin();
       iterator2 != mySkills.end();
       iterator2++)
  {
    iterator = RPG_Character_Skills_Common_Tools::mySkill2StringTable.find(iterator2->first);
    // sanity check
    if (iterator == RPG_Character_Skills_Common_Tools::mySkill2StringTable.end())
    {
      ACE_DEBUG((LM_ERROR,
                 ACE_TEXT("invalid skill %d --> check implementation !, continuing\n"),
                 iterator2->first));
    } // end IF

    skills += iterator->second;
    skills += ACE_TEXT_ALWAYS_CHAR(": ");
    skills += iterator2->second;
    skills += ACE_TEXT_ALWAYS_CHAR("\n");
  }; // end FOR
  std::string feats;
  RPG_Character_Skills_Common_Tools::RPG_Character_Feat2StringTableIterator_t iterator3;
  for (RPG_Character_FeatsConstIterator_t iterator4 = myFeats.begin();
       iterator4 != myFeats.end();
       iterator4++)
  {
    iterator3 = RPG_Character_Skills_Common_Tools::myFeat2StringTable.find(*iterator4);
    // sanity check
    if (iterator3 == RPG_Character_Skills_Common_Tools::myFeat2StringTable.end())
    {
      ACE_DEBUG((LM_ERROR,
                 ACE_TEXT("invalid feat %d --> check implementation !, continuing\n"),
                 *iterator4));
    } // end IF

    feats += iterator3->second;
    feats += ACE_TEXT_ALWAYS_CHAR("\n");
  }; // end FOR
  std::string abilities;
  RPG_Character_Skills_Common_Tools::RPG_Character_Ability2StringTableIterator_t iterator5;
  for (RPG_Character_AbilitiesConstIterator_t iterator6 = myAbilities.begin();
       iterator6 != myAbilities.end();
       iterator6++)
  {
    iterator5 = RPG_Character_Skills_Common_Tools::myAbility2StringTable.find(*iterator6);
    // sanity check
    if (iterator5 == RPG_Character_Skills_Common_Tools::myAbility2StringTable.end())
    {
      ACE_DEBUG((LM_ERROR,
                 ACE_TEXT("invalid ability %d --> check implementation !, continuing\n"),
                 *iterator6));
    } // end IF

    abilities += iterator5->second;
    abilities += ACE_TEXT_ALWAYS_CHAR("\n");
  }; // end FOR

  ACE_DEBUG((LM_DEBUG,
             ACE_TEXT("Player: \nGender: %s\nRace: %s\nClass: %s\nAlignment: %s\nAttributes:\n%s\nSkills:\n%s\nFeats:\n%s\nAbilities: %s\nItems:\n"),
             gender.c_str(),
             race.c_str(),
             class_string.c_str(),
             alignment.c_str(),
             attributes.c_str(),
             skills.c_str(),
             feats.c_str(),
             abilities.c_str()));

  // dump items
  myInventory.dump();
}
