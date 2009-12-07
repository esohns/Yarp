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
#include "rpg_character_XML_parser.h"

// #include "rpg_character_common_tools.h"
// #include "rpg_character_skills_common_tools.h"
// #include "rpg_character_monster_common.h"
// #include "rpg_character_monster_common_tools.h"
#include "rpg_character_monstermetatype.h"
#include "rpg_character_monsterweapon.h"
#include "rpg_character_attackform.h"
#include "rpg_character_skill.h"
#include "rpg_character_feat.h"
#include "rpg_character_alignmentcivic.h"
#include "rpg_character_alignmentethic.h"
#include "rpg_character_alignment.h"
#include "rpg_character_size.h"
#include "rpg_character_skills.h"
#include "rpg_character_feats.h"
#include "rpg_character_environment.h"
#include "rpg_character_monsteradvancement.h"

#include <rpg_chance_dicetype.h>

#include <ace/Log_Msg.h>

RPG_Character_Dictionary_Type::RPG_Character_Dictionary_Type(RPG_Character_MonsterDictionary_t* monsterDictionary_in)
 : myMonsterDictionary(monsterDictionary_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Dictionary_Type::RPG_Character_Dictionary_Type"));

}

RPG_Character_Dictionary_Type::~RPG_Character_Dictionary_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Dictionary_Type::~RPG_Character_Dictionary_Type"));

}

// void RPG_Character_Dictionary_Parser::pre()
// {
//   ACE_TRACE(ACE_TEXT("RPG_Character_Dictionary_Parser::pre"));
//
// }

// void RPG_Character_Dictionary_Parser::RPG_Character_MonsterDictionary()
// {
//   ACE_TRACE(ACE_TEXT("RPG_Item_Dictionary_Parser::RPG_Character_MonsterDictionary"));
//
//   // TODO
//   //
// }

void RPG_Character_Dictionary_Type::post_RPG_Character_Dictionary_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Dictionary_Type::post_RPG_Character_Dictionary_Type"));

  // debug info
  ACE_DEBUG((LM_DEBUG,
             ACE_TEXT("finished parsing character dictionary, retrieved %d monster types...\n"),
             myMonsterDictionary->size()));
}

RPG_Character_MonsterDictionary_Type::RPG_Character_MonsterDictionary_Type(RPG_Character_MonsterDictionary_t* monsterDictionary_in)
 : myMonsterDictionary(monsterDictionary_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Character_MonsterDictionary_Type::RPG_Character_MonsterDictionary_Type"));

}

// void RPG_Character_MonsterDictionary_Type::pre()
// {
//   ACE_TRACE(ACE_TEXT("RPG_Character_MonsterDictionary_Type::pre"));
//
// }

void RPG_Character_MonsterDictionary_Type::monster(const RPG_Character_MonsterPropertiesXML& monster_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Character_MonsterDictionary_Type::monster"));

  RPG_Character_MonsterProperties properties;
  properties.size             = monster_in.size;
  properties.type             = monster_in.type;
  properties.hitDice          = monster_in.hitDice;
  properties.initiative       = monster_in.initiative;
  properties.speed            = monster_in.speed;
  properties.armorClass       = monster_in.armorClass;
  properties.attack           = monster_in.attack;
  properties.space            = monster_in.space;
  properties.reach            = monster_in.reach;
  properties.saves            = monster_in.saves;
  properties.attributes       = monster_in.attributes;
  for (std::vector<RPG_Character_SkillValue>::const_iterator iterator = monster_in.skills.skills.begin();
       iterator != monster_in.skills.skills.end();
       iterator++)
  {
    properties.skills.insert(std::make_pair((*iterator).skill, (*iterator).rank));
  } // end FOR
  for (std::vector<RPG_Character_Feat>::const_iterator iterator = monster_in.feats.feats.begin();
       iterator != monster_in.feats.feats.end();
       iterator++)
  {
    properties.feats.insert(*iterator);
  } // end FOR
  properties.environment      = monster_in.environment;
  for (std::vector<RPG_Character_OrganizationStep>::const_iterator iterator = monster_in.organizations.steps.begin();
       iterator != monster_in.organizations.steps.end();
       iterator++)
  {
    properties.organizations.push_back(*iterator);
  } // end FOR
  properties.challengeRating  = monster_in.challengeRating;
  properties.treasureModifier = monster_in.treasureModifier;
  properties.alignment        = monster_in.alignment;
  for (std::vector<RPG_Character_MonsterAdvancementStep>::const_iterator iterator = monster_in.advancements.steps.begin();
       iterator != monster_in.advancements.steps.end();
       iterator++)
  {
    properties.advancements.push_back(*iterator);
  } // end FOR
  properties.levelAdjustment = monster_in.levelAdjustment;

  myMonsterDictionary->insert(std::make_pair(monster_in.name, properties));
}

void RPG_Character_MonsterDictionary_Type::post_RPG_Character_MonsterDictionary_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Character_MonsterDictionary_Type::post_RPG_Character_MonsterDictionary_Type"));

//   // debug info
//   ACE_DEBUG((LM_DEBUG,
//              ACE_TEXT("finished parsing monster dictionary, retrieved %d types...\n"),
//              myMonsterDictionary->size()));
}

RPG_Character_Size RPG_Character_Size_Type::post_RPG_Character_Size_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Size_Type::post_RPG_Character_Size_Type"));

  return RPG_Character_SizeHelper::stringToRPG_Character_Size(post_string());
}

RPG_Character_MonsterType_Type::RPG_Character_MonsterType_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Character_MonsterType_Type::RPG_Character_MonsterType_Type"));

  myCurrentMonsterType.metaType = RPG_CHARACTER_MONSTERMETATYPE_INVALID;
  myCurrentMonsterType.subTypes.clear();
}

void RPG_Character_MonsterType_Type::metaType(const RPG_Character_MonsterMetaType& metaType_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Character_MonsterType_Type::metaType"));

  myCurrentMonsterType.metaType = metaType_in;
}

void RPG_Character_MonsterType_Type::subType(const RPG_Character_MonsterSubType& subType_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Character_MonsterType_Type::subType"));

  myCurrentMonsterType.subTypes.push_back(subType_in);
}

RPG_Character_MonsterType RPG_Character_MonsterType_Type::post_RPG_Character_MonsterType_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Character_MonsterType_Type::post_RPG_Character_MonsterType_Type"));

  RPG_Character_MonsterType result = myCurrentMonsterType;

  // clear structure
  myCurrentMonsterType.metaType = RPG_CHARACTER_MONSTERMETATYPE_INVALID;
  myCurrentMonsterType.subTypes.clear();

  return result;
}

RPG_Character_MonsterMetaType RPG_Character_MonsterMetaType_Type::post_RPG_Character_MonsterMetaType_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Character_MonsterMetaType_Type::post_RPG_Character_MonsterMetaType_Type"));

  return RPG_Character_MonsterMetaTypeHelper::stringToRPG_Character_MonsterMetaType(post_string());
}

RPG_Character_MonsterSubType RPG_Character_MonsterSubType_Type::post_RPG_Character_MonsterSubType_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Character_MonsterSubType_Type::post_RPG_Character_MonsterSubType_Type"));

  return RPG_Character_MonsterSubTypeHelper::stringToRPG_Character_MonsterSubType(post_string());
}

RPG_Character_MonsterWeapon RPG_Character_MonsterWeapon_Type::post_RPG_Character_MonsterWeapon_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Character_MonsterWeapon_Type::post_RPG_Character_MonsterWeapon_Type"));

  return RPG_Character_MonsterWeaponHelper::stringToRPG_Character_MonsterWeapon(post_string());
}

RPG_Character_AttackForm RPG_Character_AttackForm_Type::post_RPG_Character_AttackForm_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Character_AttackForm_Type::post_RPG_Character_AttackForm_Type"));

  return RPG_Character_AttackFormHelper::stringToRPG_Character_AttackForm(post_string());
}

RPG_Character_MonsterArmorClass_Type::RPG_Character_MonsterArmorClass_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Character_MonsterArmorClass_Type::RPG_Character_MonsterArmorClass_Type"));

  myCurrentArmorClass.normal = 0;
  myCurrentArmorClass.touch = 0;
  myCurrentArmorClass.flatFooted = 0;
}

void RPG_Character_MonsterArmorClass_Type::normal(signed char normal_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Character_MonsterArmorClass_Type::normal"));

  myCurrentArmorClass.normal = normal_in;
}

void RPG_Character_MonsterArmorClass_Type::touch(signed char touch_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Character_MonsterArmorClass_Type::touch"));

  myCurrentArmorClass.touch = touch_in;
}

void RPG_Character_MonsterArmorClass_Type::flatFooted(signed char flatFooted_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Character_MonsterArmorClass_Type::flatFooted"));

  myCurrentArmorClass.flatFooted = flatFooted_in;
}

RPG_Character_MonsterArmorClass RPG_Character_MonsterArmorClass_Type::post_RPG_Character_MonsterArmorClass_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Character_MonsterArmorClass_Type::post_RPG_Character_MonsterArmorClass_Type"));

  RPG_Character_MonsterArmorClass result = myCurrentArmorClass;

  // clear structure
  myCurrentArmorClass.normal = 0;
  myCurrentArmorClass.touch = 0;
  myCurrentArmorClass.flatFooted = 0;

  return result;
}

RPG_Character_MonsterAttackAction_Type::RPG_Character_MonsterAttackAction_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Character_MonsterAttackAction_Type::RPG_Character_MonsterAttackAction_Type"));

  myCurrentMonsterAttackAction.monsterWeapon = RPG_CHARACTER_MONSTERWEAPON_INVALID;
  myCurrentMonsterAttackAction.attackBonus = 0;
  myCurrentMonsterAttackAction.attackForms.clear();
  myCurrentMonsterAttackAction.damage.numDice = 0;
  myCurrentMonsterAttackAction.damage.typeDice = RPG_CHANCE_DICETYPE_INVALID;
  myCurrentMonsterAttackAction.damage.modifier = 0;
  myCurrentMonsterAttackAction.numAttacksPerRound = 0;
}

void RPG_Character_MonsterAttackAction_Type::monsterWeapon(const RPG_Character_MonsterWeapon& monsterWeapon_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Character_MonsterAttackAction_Type::monsterWeapon"));

  myCurrentMonsterAttackAction.monsterWeapon = monsterWeapon_in;
}

void RPG_Character_MonsterAttackAction_Type::attackBonus(signed char attackBonus_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Character_MonsterAttackAction_Type::attackBonus"));

  myCurrentMonsterAttackAction.attackBonus = attackBonus_in;
}

void RPG_Character_MonsterAttackAction_Type::attackForm(const RPG_Character_AttackForm& attackForm_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Character_MonsterAttackAction_Type::attackForm"));

  myCurrentMonsterAttackAction.attackForms.push_back(attackForm_in);
}

void RPG_Character_MonsterAttackAction_Type::damage(const RPG_Chance_DiceRoll& damage_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Character_MonsterAttackAction_Type::damage"));

  myCurrentMonsterAttackAction.damage = damage_in;
}

void RPG_Character_MonsterAttackAction_Type::numAttacksPerRound(unsigned char numAttacksPerRound_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Character_MonsterAttackAction_Type::numAttacksPerRound"));

  myCurrentMonsterAttackAction.numAttacksPerRound = numAttacksPerRound_in;
}

RPG_Character_MonsterAttackAction RPG_Character_MonsterAttackAction_Type::post_RPG_Character_MonsterAttackAction_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Character_MonsterAttackAction_Type::post_RPG_Character_MonsterAttackAction_Type"));

  RPG_Character_MonsterAttackAction result = myCurrentMonsterAttackAction;

  // clear structure
  myCurrentMonsterAttackAction.monsterWeapon = RPG_CHARACTER_MONSTERWEAPON_INVALID;
  myCurrentMonsterAttackAction.attackBonus = 0;
  myCurrentMonsterAttackAction.attackForms.clear();
  myCurrentMonsterAttackAction.damage.numDice = 0;
  myCurrentMonsterAttackAction.damage.typeDice = RPG_CHANCE_DICETYPE_INVALID;
  myCurrentMonsterAttackAction.damage.modifier = 0;
  myCurrentMonsterAttackAction.numAttacksPerRound = 0;

  return result;
}

RPG_Character_MonsterAttack_Type::RPG_Character_MonsterAttack_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Character_MonsterAttack_Type::RPG_Character_MonsterAttack_Type"));

  myCurrentMonsterAttack.baseAttackBonus = 0;
  myCurrentMonsterAttack.grappleBonus = 0;
  myCurrentMonsterAttack.attackActions.clear();
}

void RPG_Character_MonsterAttack_Type::baseAttackBonus(signed char baseAttackBonus_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Character_MonsterAttack_Type::baseAttackBonus"));

  myCurrentMonsterAttack.baseAttackBonus = baseAttackBonus_in;
}

void RPG_Character_MonsterAttack_Type::grappleBonus(signed char grappleBonus_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Character_MonsterAttack_Type::grappleBonus"));

  myCurrentMonsterAttack.grappleBonus = grappleBonus_in;
}

void RPG_Character_MonsterAttack_Type::attackAction(const RPG_Character_MonsterAttackAction& attackAction_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Character_MonsterAttack_Type::attackAction"));

  myCurrentMonsterAttack.attackActions.push_back(attackAction_in);
}

RPG_Character_MonsterAttack RPG_Character_MonsterAttack_Type::post_RPG_Character_MonsterAttack_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Character_MonsterAttack_Type::post_RPG_Character_MonsterAttack_Type"));

  RPG_Character_MonsterAttack result = myCurrentMonsterAttack;

  // clear structure
  myCurrentMonsterAttack.baseAttackBonus = 0;
  myCurrentMonsterAttack.grappleBonus = 0;
  myCurrentMonsterAttack.attackActions.clear();

  return result;
}

RPG_Character_SavingThrowModifiers_Type::RPG_Character_SavingThrowModifiers_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Character_SavingThrowModifiers_Type::RPG_Character_SavingThrowModifiers_Type"));

  myCurrentSavingThrowModifiers.fortitude = 0;
  myCurrentSavingThrowModifiers.reflex = 0;
  myCurrentSavingThrowModifiers.will = 0;
}

void RPG_Character_SavingThrowModifiers_Type::fortitude(signed char fortitude_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Character_SavingThrowModifiers_Type::fortitude"));

  myCurrentSavingThrowModifiers.fortitude = fortitude_in;
}

void RPG_Character_SavingThrowModifiers_Type::reflex(signed char reflex_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Character_SavingThrowModifiers_Type::reflex"));

  myCurrentSavingThrowModifiers.reflex = reflex_in;
}

void RPG_Character_SavingThrowModifiers_Type::will(signed char will_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Character_SavingThrowModifiers_Type::will"));

  myCurrentSavingThrowModifiers.will = will_in;
}

RPG_Character_SavingThrowModifiers RPG_Character_SavingThrowModifiers_Type::post_RPG_Character_SavingThrowModifiers_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Character_SavingThrowModifiers_Type::post_RPG_Character_SavingThrowModifiers_Type"));

  RPG_Character_SavingThrowModifiers result = myCurrentSavingThrowModifiers;

  // clear structure
  myCurrentSavingThrowModifiers.fortitude = 0;
  myCurrentSavingThrowModifiers.reflex = 0;
  myCurrentSavingThrowModifiers.will = 0;

  return result;
}

RPG_Character_Attributes_Type::RPG_Character_Attributes_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Attributes_Type::RPG_Character_Attributes_Type"));

  myCurrentAttributes.strength = 0;
  myCurrentAttributes.dexterity = 0;
  myCurrentAttributes.constitution = 0;
  myCurrentAttributes.intelligence = 0;
  myCurrentAttributes.wisdom = 0;
  myCurrentAttributes.charisma = 0;
}

void RPG_Character_Attributes_Type::strength(unsigned char strength_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Attributes_Type::strength"));

  myCurrentAttributes.strength = strength_in;
}

void RPG_Character_Attributes_Type::dexterity(unsigned char dexterity_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Attributes_Type::dexterity"));

  myCurrentAttributes.dexterity = dexterity_in;
}

void RPG_Character_Attributes_Type::constitution(unsigned char constitution_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Attributes_Type::constitution"));

  myCurrentAttributes.constitution = constitution_in;
}

void RPG_Character_Attributes_Type::intelligence(unsigned char intelligence_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Attributes_Type::intelligence"));

  myCurrentAttributes.intelligence = intelligence_in;
}

void RPG_Character_Attributes_Type::wisdom(unsigned char wisdom_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Attributes_Type::wisdom"));

  myCurrentAttributes.wisdom = wisdom_in;
}

void RPG_Character_Attributes_Type::charisma(unsigned char charisma_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Attributes_Type::charisma"));

  myCurrentAttributes.charisma = charisma_in;
}

RPG_Character_Attributes RPG_Character_Attributes_Type::post_RPG_Character_Attributes_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Attributes_Type::post_RPG_Character_Attributes_Type"));

  RPG_Character_Attributes result = myCurrentAttributes;

  // clear structure
  myCurrentAttributes.strength = 0;
  myCurrentAttributes.dexterity = 0;
  myCurrentAttributes.constitution = 0;
  myCurrentAttributes.intelligence = 0;
  myCurrentAttributes.wisdom = 0;
  myCurrentAttributes.charisma = 0;

  return result;
}

RPG_Character_Skill RPG_Character_Skill_Type::post_RPG_Character_Skill_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Skill_Type::post_RPG_Character_Skill_Type"));

  return RPG_Character_SkillHelper::stringToRPG_Character_Skill(post_string());
}

RPG_Character_SkillValue_Type::RPG_Character_SkillValue_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Character_SkillValue_Type::RPG_Character_SkillValue_Type"));

  myCurrentSkill.skill = RPG_CHARACTER_SKILL_INVALID;
  myCurrentSkill.rank = 0;
}

void RPG_Character_SkillValue_Type::skill(const RPG_Character_Skill& skill_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Character_SkillValue_Type::skill"));

  myCurrentSkill.skill = skill_in;
}

void RPG_Character_SkillValue_Type::rank(signed char rank_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Character_SkillValue_Type::rank"));

  myCurrentSkill.rank = rank_in;
}

RPG_Character_SkillValue RPG_Character_SkillValue_Type::post_RPG_Character_SkillValue_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Character_SkillValue_Type::post_RPG_Character_SkillValue_Type"));

  RPG_Character_SkillValue result = myCurrentSkill;

  // clear structure
  myCurrentSkill.skill = RPG_CHARACTER_SKILL_INVALID;
  myCurrentSkill.rank = 0;

  return result;
}

RPG_Character_Skills_Type::RPG_Character_Skills_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Skills_Type::RPG_Character_Skills_Type"));

  myCurrentSkills.skills.clear();
}

void RPG_Character_Skills_Type::skill(const RPG_Character_SkillValue& skill_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Skills_Type::skill"));

  myCurrentSkills.skills.push_back(skill_in);
}

RPG_Character_Skills RPG_Character_Skills_Type::post_RPG_Character_Skills_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Skills_Type::post_RPG_Character_Skills_Type"));

  RPG_Character_Skills result = myCurrentSkills;

  // clear structure
  myCurrentSkills.skills.clear();

  return result;
}

RPG_Character_Feat RPG_Character_Feat_Type::post_RPG_Character_Feat_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Feat_Type::post_RPG_Character_Feat_Type"));

  return RPG_Character_FeatHelper::stringToRPG_Character_Feat(post_string());
}

RPG_Character_Feats_Type::RPG_Character_Feats_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Feats_Type::RPG_Character_Feats_Type"));

  myCurrentFeats.feats.clear();
}

void RPG_Character_Feats_Type::feat(const RPG_Character_Feat& feat_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Feats_Type::feat"));

  myCurrentFeats.feats.push_back(feat_in);
}

RPG_Character_Feats RPG_Character_Feats_Type::post_RPG_Character_Feats_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Feats_Type::post_RPG_Character_Feats_Type"));

  RPG_Character_Feats result = myCurrentFeats;

  // clear structure
  myCurrentFeats.feats.clear();

  return result;
}

RPG_Character_Terrain RPG_Character_Terrain_Type::post_RPG_Character_Terrain_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Terrain_Type::post_RPG_Character_Terrain_Type"));

  return RPG_Character_TerrainHelper::stringToRPG_Character_Terrain(post_string());
}

RPG_Character_Climate RPG_Character_Climate_Type::post_RPG_Character_Climate_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Climate_Type::post_RPG_Character_Climate_Type"));

  return RPG_Character_ClimateHelper::stringToRPG_Character_Climate(post_string());
}

RPG_Character_Environment_Type::RPG_Character_Environment_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Environment_Type::RPG_Character_Environment_Type"));

  myCurrentEnvironment.terrain = RPG_CHARACTER_TERRAIN_INVALID;
  myCurrentEnvironment.climate = RPG_CHARACTER_CLIMATE_INVALID;
}

void RPG_Character_Environment_Type::terrain(const RPG_Character_Terrain& terrain_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Environment_Type::terrain"));

  myCurrentEnvironment.terrain = terrain_in;
}

void RPG_Character_Environment_Type::climate(const RPG_Character_Climate& climate_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Environment_Type::climate"));

  myCurrentEnvironment.climate = climate_in;
}

RPG_Character_Environment RPG_Character_Environment_Type::post_RPG_Character_Environment_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Environment_Type::post_RPG_Character_Environment_Type"));

  RPG_Character_Environment result = myCurrentEnvironment;

  // clear structure
  myCurrentEnvironment.terrain = RPG_CHARACTER_TERRAIN_INVALID;
  myCurrentEnvironment.climate = RPG_CHARACTER_CLIMATE_INVALID;

  return result;
}

RPG_Character_Organization RPG_Character_Organization_Type::post_RPG_Character_Organization_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Organization_Type::post_RPG_Character_Organization_Type"));

  return RPG_Character_OrganizationHelper::stringToRPG_Character_Organization(post_string());
}

RPG_Character_OrganizationSlaverStep_Type::RPG_Character_OrganizationSlaverStep_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Character_OrganizationSlaverStep_Type::RPG_Character_OrganizationSlaverStep_Type"));

  myCurrentOrganizationSlaverStep.name.clear();
  myCurrentOrganizationSlaverStep.range.begin = 0;
  myCurrentOrganizationSlaverStep.range.end = 0;
}

void RPG_Character_OrganizationSlaverStep_Type::name(const std::string& name_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Character_OrganizationSlaverStep_Type::name"));

  myCurrentOrganizationSlaverStep.name = name_in;
}

void RPG_Character_OrganizationSlaverStep_Type::range(const RPG_Chance_ValueRange& range_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Character_OrganizationSlaverStep_Type::range"));

  myCurrentOrganizationSlaverStep.range = range_in;
}

RPG_Character_OrganizationSlaverStep RPG_Character_OrganizationSlaverStep_Type::post_RPG_Character_OrganizationSlaverStep_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Character_OrganizationSlaverStep_Type::post_RPG_Character_OrganizationSlaverStep_Type"));

  RPG_Character_OrganizationSlaverStep result = myCurrentOrganizationSlaverStep;

  // clear structure
  myCurrentOrganizationSlaverStep.name.clear();
  myCurrentOrganizationSlaverStep.range.begin = 0;
  myCurrentOrganizationSlaverStep.range.end = 0;

  return result;
}

RPG_Character_OrganizationStep_Type::RPG_Character_OrganizationStep_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Character_OrganizationStep_Type::RPG_Character_OrganizationStep_Type"));

  myCurrentOrganizationStep.type = RPG_CHARACTER_ORGANIZATION_INVALID;
  myCurrentOrganizationStep.range.begin = 0;
  myCurrentOrganizationStep.range.end = 0;
  myCurrentOrganizationStep.slaves.clear();
}

void RPG_Character_OrganizationStep_Type::type(const RPG_Character_Organization& organization_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Character_OrganizationStep_Type::type"));

  myCurrentOrganizationStep.type = organization_in;
}

void RPG_Character_OrganizationStep_Type::range(const RPG_Chance_ValueRange& range_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Character_OrganizationStep_Type::range"));

  myCurrentOrganizationStep.range = range_in;
}

void RPG_Character_OrganizationStep_Type::slaves(const RPG_Character_OrganizationSlaverStep& organizationSlaverStep_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Character_OrganizationStep_Type::slaves"));

  myCurrentOrganizationStep.slaves.push_back(organizationSlaverStep_in);
}

RPG_Character_OrganizationStep RPG_Character_OrganizationStep_Type::post_RPG_Character_OrganizationStep_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Character_OrganizationStep_Type::post_RPG_Character_OrganizationStep_Type"));

  RPG_Character_OrganizationStep result = myCurrentOrganizationStep;

  // clear structure
  myCurrentOrganizationStep.type = RPG_CHARACTER_ORGANIZATION_INVALID;
  myCurrentOrganizationStep.range.begin = 0;
  myCurrentOrganizationStep.range.end = 0;
  myCurrentOrganizationStep.slaves.clear();

  return result;
}

RPG_Character_Organizations_Type::RPG_Character_Organizations_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Organizations_Type::RPG_Character_Organizations_Type"));

  myCurrentOrganizations.steps.clear();
}

void RPG_Character_Organizations_Type::step(const RPG_Character_OrganizationStep& organizationStep_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Organizations_Type::step"));

  myCurrentOrganizations.steps.push_back(organizationStep_in);
}

RPG_Character_Organizations RPG_Character_Organizations_Type::post_RPG_Character_Organizations_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Organizations_Type::post_RPG_Character_Organizations_Type"));

  RPG_Character_Organizations result = myCurrentOrganizations;

  // clear structure
  myCurrentOrganizations.steps.clear();

  return result;
}

RPG_Character_AlignmentCivic RPG_Character_AlignmentCivic_Type::post_RPG_Character_AlignmentCivic_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Character_AlignmentCivic_Type::post_RPG_Character_AlignmentCivic_Type"));

  return RPG_Character_AlignmentCivicHelper::stringToRPG_Character_AlignmentCivic(post_string());
}

RPG_Character_AlignmentEthic RPG_Character_AlignmentEthic_Type::post_RPG_Character_AlignmentEthic_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Character_AlignmentEthic_Type::post_RPG_Character_AlignmentEthic_Type"));

  return RPG_Character_AlignmentEthicHelper::stringToRPG_Character_AlignmentEthic(post_string());
}

RPG_Character_Alignment_Type::RPG_Character_Alignment_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Alignment_Type::RPG_Character_Alignment_Type"));

  myCurrentAlignment.civic = RPG_CHARACTER_ALIGNMENTCIVIC_INVALID;
  myCurrentAlignment.ethic = RPG_CHARACTER_ALIGNMENTETHIC_INVALID;
}

void RPG_Character_Alignment_Type::civic(const RPG_Character_AlignmentCivic& alignmentCivic_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Alignment_Type::civic"));

  myCurrentAlignment.civic = alignmentCivic_in;
}

void RPG_Character_Alignment_Type::ethic(const RPG_Character_AlignmentEthic& alignmentEthic_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Alignment_Type::ethic"));

  myCurrentAlignment.ethic = alignmentEthic_in;
}

RPG_Character_Alignment RPG_Character_Alignment_Type::post_RPG_Character_Alignment_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Character_Alignment_Type::post_RPG_Character_Alignment_Type"));

  RPG_Character_Alignment result = myCurrentAlignment;

  // clear structure
  myCurrentAlignment.civic = RPG_CHARACTER_ALIGNMENTCIVIC_INVALID;
  myCurrentAlignment.ethic = RPG_CHARACTER_ALIGNMENTETHIC_INVALID;

  return result;
}

RPG_Character_MonsterAdvancementStep_Type::RPG_Character_MonsterAdvancementStep_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Character_MonsterAdvancementStep_Type::RPG_Character_MonsterAdvancementStep_Type"));

  myCurrentAdvancementStep.size = RPG_CHARACTER_SIZE_INVALID;
  myCurrentAdvancementStep.range.begin = 0;
  myCurrentAdvancementStep.range.end = 0;
}

void RPG_Character_MonsterAdvancementStep_Type::size(const RPG_Character_Size& size_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Character_MonsterAdvancementStep_Type::size"));

  myCurrentAdvancementStep.size = size_in;
}

void RPG_Character_MonsterAdvancementStep_Type::range(const RPG_Chance_ValueRange& range_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Character_MonsterAdvancementStep_Type::range"));

  myCurrentAdvancementStep.range = range_in;
}

RPG_Character_MonsterAdvancementStep RPG_Character_MonsterAdvancementStep_Type::post_RPG_Character_MonsterAdvancementStep_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Character_MonsterAdvancementStep_Type::post_RPG_Character_MonsterAdvancementStep_Type"));

  RPG_Character_MonsterAdvancementStep result = myCurrentAdvancementStep;

  // clear structure
  myCurrentAdvancementStep.size = RPG_CHARACTER_SIZE_INVALID;
  myCurrentAdvancementStep.range.begin = 0;
  myCurrentAdvancementStep.range.end = 0;

  return result;
}

RPG_Character_MonsterAdvancement_Type::RPG_Character_MonsterAdvancement_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Character_MonsterAdvancement_Type::RPG_Character_MonsterAdvancement_Type"));

  myCurrentMonsterAdvancement.steps.clear();
}

void RPG_Character_MonsterAdvancement_Type::step(const RPG_Character_MonsterAdvancementStep& advancementStep_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Character_MonsterAdvancement_Type::step"));

  myCurrentMonsterAdvancement.steps.push_back(advancementStep_in);
}

RPG_Character_MonsterAdvancement RPG_Character_MonsterAdvancement_Type::post_RPG_Character_MonsterAdvancement_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Character_MonsterAdvancement_Type::post_RPG_Character_MonsterAdvancement_Type"));

  RPG_Character_MonsterAdvancement result = myCurrentMonsterAdvancement;

  // clear container
  myCurrentMonsterAdvancement.steps.clear();

  return result;
}

RPG_Character_MonsterPropertiesXML_Type::RPG_Character_MonsterPropertiesXML_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Character_MonsterPropertiesXML_Type::RPG_Character_MonsterPropertiesXML_Type"));

  myCurrentProperties.name.resize(0);
  myCurrentProperties.size = RPG_CHARACTER_SIZE_INVALID;
  myCurrentProperties.type.metaType = RPG_CHARACTER_MONSTERMETATYPE_INVALID;
  myCurrentProperties.type.subTypes.clear();
  myCurrentProperties.hitDice.numDice = 0;
  myCurrentProperties.hitDice.typeDice = RPG_CHANCE_DICETYPE_INVALID;
  myCurrentProperties.hitDice.modifier = 0;
  myCurrentProperties.initiative = 0;
  myCurrentProperties.speed = 0;
  myCurrentProperties.armorClass.normal = 0;
  myCurrentProperties.armorClass.touch = 0;
  myCurrentProperties.armorClass.flatFooted = 0;
  myCurrentProperties.attack.baseAttackBonus = 0;
  myCurrentProperties.attack.grappleBonus = 0;
  myCurrentProperties.attack.attackActions.clear();
  myCurrentProperties.space = 0;
  myCurrentProperties.reach = 0;
  myCurrentProperties.saves.fortitude = 0;
  myCurrentProperties.saves.reflex = 0;
  myCurrentProperties.saves.will = 0;
  myCurrentProperties.attributes.strength = 0;
  myCurrentProperties.attributes.dexterity = 0;
  myCurrentProperties.attributes.constitution = 0;
  myCurrentProperties.attributes.intelligence = 0;
  myCurrentProperties.attributes.wisdom = 0;
  myCurrentProperties.attributes.charisma = 0;
  myCurrentProperties.skills.skills.clear();
  myCurrentProperties.feats.feats.clear();
  myCurrentProperties.environment.climate = RPG_CHARACTER_CLIMATE_INVALID;
  myCurrentProperties.environment.terrain = RPG_CHARACTER_TERRAIN_INVALID;
  myCurrentProperties.organizations.steps.clear();
  myCurrentProperties.challengeRating = 0;
  myCurrentProperties.treasureModifier = 0;
  myCurrentProperties.alignment.civic = RPG_CHARACTER_ALIGNMENTCIVIC_INVALID;
  myCurrentProperties.alignment.ethic = RPG_CHARACTER_ALIGNMENTETHIC_INVALID;
  myCurrentProperties.advancements.steps.clear();
  myCurrentProperties.levelAdjustment = 0;
}

void RPG_Character_MonsterPropertiesXML_Type::name(const ::std::string& name_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Character_MonsterPropertiesXML_Type::name"));

  myCurrentProperties.name = name_in;
}

void RPG_Character_MonsterPropertiesXML_Type::size(const RPG_Character_Size& size_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Character_MonsterPropertiesXML_Type::size"));

  myCurrentProperties.size = size_in;
}

void RPG_Character_MonsterPropertiesXML_Type::type(const RPG_Character_MonsterType& type_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Character_MonsterPropertiesXML_Type::type"));

  myCurrentProperties.type = type_in;
}

void RPG_Character_MonsterPropertiesXML_Type::hitDice(const RPG_Chance_DiceRoll& hitDice_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Character_MonsterPropertiesXML_Type::hitDice"));

  myCurrentProperties.hitDice = hitDice_in;
}

void RPG_Character_MonsterPropertiesXML_Type::initiative(signed char initiative_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Character_MonsterPropertiesXML_Type::initiative"));

  myCurrentProperties.initiative = initiative_in;
}

void RPG_Character_MonsterPropertiesXML_Type::speed(unsigned char speed_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Character_MonsterPropertiesXML_Type::speed"));

  myCurrentProperties.speed = speed_in;
}

void RPG_Character_MonsterPropertiesXML_Type::armorClass(const RPG_Character_MonsterArmorClass& armorClass_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Character_MonsterPropertiesXML_Type::armorClass"));

  myCurrentProperties.armorClass = armorClass_in;
}

void RPG_Character_MonsterPropertiesXML_Type::attack(const RPG_Character_MonsterAttack& attack_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Character_MonsterPropertiesXML_Type::attack"));

  myCurrentProperties.attack = attack_in;
}

void RPG_Character_MonsterPropertiesXML_Type::space(unsigned char space_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Character_MonsterPropertiesXML_Type::space"));

  myCurrentProperties.space = space_in;
}

void RPG_Character_MonsterPropertiesXML_Type::reach(unsigned char reach_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Character_MonsterPropertiesXML_Type::reach"));

  myCurrentProperties.reach = reach_in;
}

void RPG_Character_MonsterPropertiesXML_Type::saves(const RPG_Character_SavingThrowModifiers& saves_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Character_MonsterPropertiesXML_Type::saves"));

  myCurrentProperties.saves = saves_in;
}

void RPG_Character_MonsterPropertiesXML_Type::attributes(const RPG_Character_Attributes& attributes_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Character_MonsterPropertiesXML_Type::attributes"));

  myCurrentProperties.attributes = attributes_in;
}

void RPG_Character_MonsterPropertiesXML_Type::skills(const RPG_Character_Skills& skills_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Character_MonsterPropertiesXML_Type::skills"));

  myCurrentProperties.skills = skills_in;
}

void RPG_Character_MonsterPropertiesXML_Type::feats(const RPG_Character_Feats& feats_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Character_MonsterPropertiesXML_Type::feats"));

  myCurrentProperties.feats = feats_in;
}

void RPG_Character_MonsterPropertiesXML_Type::environment(const RPG_Character_Environment& environment_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Character_MonsterPropertiesXML_Type::environment"));

  myCurrentProperties.environment = environment_in;
}

void RPG_Character_MonsterPropertiesXML_Type::organizations(const RPG_Character_Organizations& organizations_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Character_MonsterPropertiesXML_Type::organizations"));

  myCurrentProperties.organizations = organizations_in;
}

void RPG_Character_MonsterPropertiesXML_Type::challengeRating(unsigned char challengeRating_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Character_MonsterPropertiesXML_Type::challengeRating"));

  myCurrentProperties.challengeRating = challengeRating_in;
}

void RPG_Character_MonsterPropertiesXML_Type::treasureModifier(unsigned char treasureModifier_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Character_MonsterPropertiesXML_Type::treasureModifier"));

  myCurrentProperties.treasureModifier = treasureModifier_in;
}

void RPG_Character_MonsterPropertiesXML_Type::alignment(const RPG_Character_Alignment& alignment_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Character_MonsterPropertiesXML_Type::alignment"));

  myCurrentProperties.alignment = alignment_in;
}

void RPG_Character_MonsterPropertiesXML_Type::advancement(const RPG_Character_MonsterAdvancement& advancement_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Character_MonsterPropertiesXML_Type::advancement"));

  myCurrentProperties.advancements = advancement_in;
}

void RPG_Character_MonsterPropertiesXML_Type::levelAdjustment(unsigned char levelAdjustment_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Character_MonsterPropertiesXML_Type::levelAdjustment"));

  myCurrentProperties.levelAdjustment = levelAdjustment_in;
}

RPG_Character_MonsterPropertiesXML RPG_Character_MonsterPropertiesXML_Type::post_RPG_Character_MonsterPropertiesXML_Type()
{
  ACE_TRACE(ACE_TEXT("RPG_Character_MonsterPropertiesXML_Type::post_RPG_Character_MonsterPropertiesXML_Type"));

  RPG_Character_MonsterPropertiesXML result = myCurrentProperties;

  // clear structure
  myCurrentProperties.name.resize(0);
  myCurrentProperties.size = RPG_CHARACTER_SIZE_INVALID;
  myCurrentProperties.type.metaType = RPG_CHARACTER_MONSTERMETATYPE_INVALID;
  myCurrentProperties.type.subTypes.clear();
  myCurrentProperties.hitDice.numDice = 0;
  myCurrentProperties.hitDice.typeDice = RPG_CHANCE_DICETYPE_INVALID;
  myCurrentProperties.hitDice.modifier = 0;
  myCurrentProperties.initiative = 0;
  myCurrentProperties.speed = 0;
  myCurrentProperties.armorClass.normal = 0;
  myCurrentProperties.armorClass.touch = 0;
  myCurrentProperties.armorClass.flatFooted = 0;
  myCurrentProperties.attack.baseAttackBonus = 0;
  myCurrentProperties.attack.grappleBonus = 0;
  myCurrentProperties.attack.attackActions.clear();
  myCurrentProperties.space = 0;
  myCurrentProperties.reach = 0;
  myCurrentProperties.saves.fortitude = 0;
  myCurrentProperties.saves.reflex = 0;
  myCurrentProperties.saves.will = 0;
  myCurrentProperties.attributes.strength = 0;
  myCurrentProperties.attributes.dexterity = 0;
  myCurrentProperties.attributes.constitution = 0;
  myCurrentProperties.attributes.intelligence = 0;
  myCurrentProperties.attributes.wisdom = 0;
  myCurrentProperties.attributes.charisma = 0;
  myCurrentProperties.skills.skills.clear();
  myCurrentProperties.feats.feats.clear();
  myCurrentProperties.environment.climate = RPG_CHARACTER_CLIMATE_INVALID;
  myCurrentProperties.environment.terrain = RPG_CHARACTER_TERRAIN_INVALID;
  myCurrentProperties.organizations.steps.clear();
  myCurrentProperties.challengeRating = 0;
  myCurrentProperties.treasureModifier = 0;
  myCurrentProperties.alignment.civic = RPG_CHARACTER_ALIGNMENTCIVIC_INVALID;
  myCurrentProperties.alignment.ethic = RPG_CHARACTER_ALIGNMENTETHIC_INVALID;
  myCurrentProperties.advancements.steps.clear();
  myCurrentProperties.levelAdjustment = 0;

  return result;
}