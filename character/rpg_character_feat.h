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

// -------------------------------- * * * -------------------------------- //
// PLEASE NOTE: this file was/is generated by XML2CppCode 0.1
// -------------------------------- * * * -------------------------------- //

#pragma once
#ifndef RPG_CHARACTER_FEAT_H
#define RPG_CHARACTER_FEAT_H

enum RPG_Character_Feat
{
  FEAT_BLIND_FIGHT = 0,
  FEAT_COMBAT_EXPERTISE,
  FEAT_IMPROVED_DISARM,
  FEAT_IMPROVED_FEINT,
  FEAT_IMPROVED_TRIP,
  FEAT_WHIRLWIND_ATTACK,
  FEAT_COMBAT_REFLEXES,
  FEAT_DODGE,
  FEAT_MOBILITY,
  FEAT_SPRING_ATTACK,
  FEAT_PROFICIENCY_EXOTIC_WEAPONS,
  FEAT_IMPROVED_CRITICAL,
  FEAT_IMPROVED_INITIATIVE,
  FEAT_IMPROVED_SHIELD_BASH,
  FEAT_IMPROVED_UNARMED_STRIKE,
  FEAT_DEFLECT_ARROWS,
  FEAT_IMPROVED_GRAPPLE,
  FEAT_SNATCH_ARROWS,
  FEAT_STUNNING_FIST,
  FEAT_MOUNTED_COMBAT,
  FEAT_MOUNTED_ARCHERY,
  FEAT_RIDE_BY_ATTACK,
  FEAT_SPIRITED_CHARGE,
  FEAT_TRAMPLE,
  FEAT_POINT_BLANK_SHOT,
  FEAT_FAR_SHOT,
  FEAT_PRECISE_SHOT,
  FEAT_RAPID_SHOT,
  FEAT_MANY_SHOT,
  FEAT_SHOT_ON_THE_RUN,
  FEAT_IMPROVED_PRECISE_SHOT,
  FEAT_POWER_ATTACK,
  FEAT_CLEAVE,
  FEAT_GREAT_CLEAVE,
  FEAT_IMPROVED_BULL_RUSH,
  FEAT_IMPROVED_OVERRUN,
  FEAT_IMPROVED_SUNDER,
  FEAT_QUICK_DRAW,
  FEAT_RAPID_RELOAD,
  FEAT_TWO_WEAPON_FIGHTING,
  FEAT_TWO_WEAPON_DEFENSE,
  FEAT_IMPROVED_TWO_WEAPON_FIGHTING,
  FEAT_GREATER_TWO_WEAPON_FIGHTING,
  FEAT_WEAPON_FINESSE,
  FEAT_WEAPON_FOCUS,
  FEAT_WEAPON_SPECIALIZATION,
  FEAT_GREATER_WEAPON_FOCUS,
  FEAT_GREATER_WEAPON_SPECIALIZATION,
  FEAT_BREW_POTION,
  FEAT_CRAFT_MAGIC_ARMS_AND_ARMOR,
  FEAT_CRAFT_ROD,
  FEAT_CRAFT_STAFF,
  FEAT_CRAFT_WAND,
  FEAT_CRAFT_WONDROUS_ITEM,
  FEAT_FORGE_RING,
  FEAT_SCRIBE_SCROLL,
  FEAT_EMPOWER_SPELL,
  FEAT_ENLARGE_SPELL,
  FEAT_EXTEND_SPELL,
  FEAT_HEIGHTEN_SPELL,
  FEAT_MAXIMIZE_SPELL,
  FEAT_QUICKEN_SPELL,
  FEAT_SILENT_SPELL,
  FEAT_WIDEN_SPELL,
  FEAT_ACROBATIC,
  FEAT_AGILE,
  FEAT_ALERTNESS,
  FEAT_ANIMAL_AFFINITY,
  FEAT_PROFICIENCY_ARMOR_LIGHT,
  FEAT_PROFICIENCY_ARMOR_MEDIUM,
  FEAT_PROFICIENCY_ARMOR_HEAVY,
  FEAT_ATHLETIC,
  FEAT_AUGMENT_SUMMONING,
  FEAT_COMBAT_CASTING,
  FEAT_DECEITFUL,
  FEAT_DEFT_HANDS,
  FEAT_DILIGENT,
  FEAT_ENDURANCE,
  FEAT_DIE_HARD,
  FEAT_ESCHEW_MATERIALS,
  FEAT_EXTRA_TURNING,
  FEAT_GREAT_FORTITUDE,
  FEAT_IMPROVED_COUNTERSPELL,
  FEAT_IMPROVED_FAMILIAR,
  FEAT_IMPROVED_TURNING,
  FEAT_INVESTIGATOR,
  FEAT_IRON_WILL,
  FEAT_LEADERSHIP,
  FEAT_LIGHTNING_REFLEXES,
  FEAT_MAGICAL_APTITUDE,
  FEAT_PROFICIENCY_MARTIAL_WEAPONS,
  FEAT_NATURAL_SPELL,
  FEAT_NEGOTIATOR,
  FEAT_NIMBLE_FINGERS,
  FEAT_PERSUASIVE,
  FEAT_RUN,
  FEAT_SELF_SUFFICIENT,
  FEAT_PROFICIENCY_SHIELD,
  FEAT_PROFICIENCY_TOWER_SHIELD,
  FEAT_PROFICIENCY_SIMPLE_WEAPONS,
  FEAT_SKILL_FOCUS,
  FEAT_SPELL_FOCUS,
  FEAT_GREATER_SPELL_FOCUS,
  FEAT_SPELL_MASTERY,
  FEAT_SPELL_PENETRATION,
  FEAT_GREATER_SPELL_PENETRATION,
  FEAT_STEALTHY,
  FEAT_TOUGHNESS,
  FEAT_TRACK,
  FEAT_ABILITY_FOCUS,
  FEAT_AWESOME_BLOW,
  FEAT_CRAFT_CONSTRUCT,
  FEAT_EMPOWER_SPELLLIKE_ABILITY,
  FEAT_FLYBY_ATTACK,
  FEAT_HOVER,
  FEAT_IMPROVED_NATURAL_ARMOR,
  FEAT_IMPROVED_NATURAL_ATTACK,
  FEAT_MULTI_ATTACK,
  FEAT_MULTIWEAPON_FIGHTING,
  FEAT_QUICKEN_SPELLLIKE_ABILITY,
  FEAT_SNATCH,
  FEAT_WINGOVER,
  //
  RPG_CHARACTER_FEAT_MAX,
  RPG_CHARACTER_FEAT_INVALID
};

#include <ace/Global_Macros.h>

#include <map>
#include <string>

typedef std::map<RPG_Character_Feat, std::string> RPG_Character_FeatToStringTable_t;
typedef RPG_Character_FeatToStringTable_t::const_iterator RPG_Character_FeatToStringTableIterator_t;

class RPG_Character_FeatHelper
{
 public:
  inline static void init()
  {
    myRPG_Character_FeatToStringTable.clear();
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_BLIND_FIGHT, ACE_TEXT_ALWAYS_CHAR("FEAT_BLIND_FIGHT")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_COMBAT_EXPERTISE, ACE_TEXT_ALWAYS_CHAR("FEAT_COMBAT_EXPERTISE")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_IMPROVED_DISARM, ACE_TEXT_ALWAYS_CHAR("FEAT_IMPROVED_DISARM")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_IMPROVED_FEINT, ACE_TEXT_ALWAYS_CHAR("FEAT_IMPROVED_FEINT")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_IMPROVED_TRIP, ACE_TEXT_ALWAYS_CHAR("FEAT_IMPROVED_TRIP")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_WHIRLWIND_ATTACK, ACE_TEXT_ALWAYS_CHAR("FEAT_WHIRLWIND_ATTACK")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_COMBAT_REFLEXES, ACE_TEXT_ALWAYS_CHAR("FEAT_COMBAT_REFLEXES")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_DODGE, ACE_TEXT_ALWAYS_CHAR("FEAT_DODGE")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_MOBILITY, ACE_TEXT_ALWAYS_CHAR("FEAT_MOBILITY")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_SPRING_ATTACK, ACE_TEXT_ALWAYS_CHAR("FEAT_SPRING_ATTACK")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_PROFICIENCY_EXOTIC_WEAPONS, ACE_TEXT_ALWAYS_CHAR("FEAT_PROFICIENCY_EXOTIC_WEAPONS")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_IMPROVED_CRITICAL, ACE_TEXT_ALWAYS_CHAR("FEAT_IMPROVED_CRITICAL")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_IMPROVED_INITIATIVE, ACE_TEXT_ALWAYS_CHAR("FEAT_IMPROVED_INITIATIVE")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_IMPROVED_SHIELD_BASH, ACE_TEXT_ALWAYS_CHAR("FEAT_IMPROVED_SHIELD_BASH")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_IMPROVED_UNARMED_STRIKE, ACE_TEXT_ALWAYS_CHAR("FEAT_IMPROVED_UNARMED_STRIKE")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_DEFLECT_ARROWS, ACE_TEXT_ALWAYS_CHAR("FEAT_DEFLECT_ARROWS")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_IMPROVED_GRAPPLE, ACE_TEXT_ALWAYS_CHAR("FEAT_IMPROVED_GRAPPLE")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_SNATCH_ARROWS, ACE_TEXT_ALWAYS_CHAR("FEAT_SNATCH_ARROWS")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_STUNNING_FIST, ACE_TEXT_ALWAYS_CHAR("FEAT_STUNNING_FIST")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_MOUNTED_COMBAT, ACE_TEXT_ALWAYS_CHAR("FEAT_MOUNTED_COMBAT")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_MOUNTED_ARCHERY, ACE_TEXT_ALWAYS_CHAR("FEAT_MOUNTED_ARCHERY")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_RIDE_BY_ATTACK, ACE_TEXT_ALWAYS_CHAR("FEAT_RIDE_BY_ATTACK")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_SPIRITED_CHARGE, ACE_TEXT_ALWAYS_CHAR("FEAT_SPIRITED_CHARGE")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_TRAMPLE, ACE_TEXT_ALWAYS_CHAR("FEAT_TRAMPLE")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_POINT_BLANK_SHOT, ACE_TEXT_ALWAYS_CHAR("FEAT_POINT_BLANK_SHOT")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_FAR_SHOT, ACE_TEXT_ALWAYS_CHAR("FEAT_FAR_SHOT")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_PRECISE_SHOT, ACE_TEXT_ALWAYS_CHAR("FEAT_PRECISE_SHOT")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_RAPID_SHOT, ACE_TEXT_ALWAYS_CHAR("FEAT_RAPID_SHOT")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_MANY_SHOT, ACE_TEXT_ALWAYS_CHAR("FEAT_MANY_SHOT")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_SHOT_ON_THE_RUN, ACE_TEXT_ALWAYS_CHAR("FEAT_SHOT_ON_THE_RUN")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_IMPROVED_PRECISE_SHOT, ACE_TEXT_ALWAYS_CHAR("FEAT_IMPROVED_PRECISE_SHOT")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_POWER_ATTACK, ACE_TEXT_ALWAYS_CHAR("FEAT_POWER_ATTACK")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_CLEAVE, ACE_TEXT_ALWAYS_CHAR("FEAT_CLEAVE")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_GREAT_CLEAVE, ACE_TEXT_ALWAYS_CHAR("FEAT_GREAT_CLEAVE")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_IMPROVED_BULL_RUSH, ACE_TEXT_ALWAYS_CHAR("FEAT_IMPROVED_BULL_RUSH")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_IMPROVED_OVERRUN, ACE_TEXT_ALWAYS_CHAR("FEAT_IMPROVED_OVERRUN")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_IMPROVED_SUNDER, ACE_TEXT_ALWAYS_CHAR("FEAT_IMPROVED_SUNDER")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_QUICK_DRAW, ACE_TEXT_ALWAYS_CHAR("FEAT_QUICK_DRAW")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_RAPID_RELOAD, ACE_TEXT_ALWAYS_CHAR("FEAT_RAPID_RELOAD")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_TWO_WEAPON_FIGHTING, ACE_TEXT_ALWAYS_CHAR("FEAT_TWO_WEAPON_FIGHTING")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_TWO_WEAPON_DEFENSE, ACE_TEXT_ALWAYS_CHAR("FEAT_TWO_WEAPON_DEFENSE")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_IMPROVED_TWO_WEAPON_FIGHTING, ACE_TEXT_ALWAYS_CHAR("FEAT_IMPROVED_TWO_WEAPON_FIGHTING")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_GREATER_TWO_WEAPON_FIGHTING, ACE_TEXT_ALWAYS_CHAR("FEAT_GREATER_TWO_WEAPON_FIGHTING")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_WEAPON_FINESSE, ACE_TEXT_ALWAYS_CHAR("FEAT_WEAPON_FINESSE")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_WEAPON_FOCUS, ACE_TEXT_ALWAYS_CHAR("FEAT_WEAPON_FOCUS")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_WEAPON_SPECIALIZATION, ACE_TEXT_ALWAYS_CHAR("FEAT_WEAPON_SPECIALIZATION")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_GREATER_WEAPON_FOCUS, ACE_TEXT_ALWAYS_CHAR("FEAT_GREATER_WEAPON_FOCUS")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_GREATER_WEAPON_SPECIALIZATION, ACE_TEXT_ALWAYS_CHAR("FEAT_GREATER_WEAPON_SPECIALIZATION")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_BREW_POTION, ACE_TEXT_ALWAYS_CHAR("FEAT_BREW_POTION")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_CRAFT_MAGIC_ARMS_AND_ARMOR, ACE_TEXT_ALWAYS_CHAR("FEAT_CRAFT_MAGIC_ARMS_AND_ARMOR")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_CRAFT_ROD, ACE_TEXT_ALWAYS_CHAR("FEAT_CRAFT_ROD")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_CRAFT_STAFF, ACE_TEXT_ALWAYS_CHAR("FEAT_CRAFT_STAFF")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_CRAFT_WAND, ACE_TEXT_ALWAYS_CHAR("FEAT_CRAFT_WAND")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_CRAFT_WONDROUS_ITEM, ACE_TEXT_ALWAYS_CHAR("FEAT_CRAFT_WONDROUS_ITEM")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_FORGE_RING, ACE_TEXT_ALWAYS_CHAR("FEAT_FORGE_RING")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_SCRIBE_SCROLL, ACE_TEXT_ALWAYS_CHAR("FEAT_SCRIBE_SCROLL")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_EMPOWER_SPELL, ACE_TEXT_ALWAYS_CHAR("FEAT_EMPOWER_SPELL")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_ENLARGE_SPELL, ACE_TEXT_ALWAYS_CHAR("FEAT_ENLARGE_SPELL")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_EXTEND_SPELL, ACE_TEXT_ALWAYS_CHAR("FEAT_EXTEND_SPELL")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_HEIGHTEN_SPELL, ACE_TEXT_ALWAYS_CHAR("FEAT_HEIGHTEN_SPELL")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_MAXIMIZE_SPELL, ACE_TEXT_ALWAYS_CHAR("FEAT_MAXIMIZE_SPELL")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_QUICKEN_SPELL, ACE_TEXT_ALWAYS_CHAR("FEAT_QUICKEN_SPELL")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_SILENT_SPELL, ACE_TEXT_ALWAYS_CHAR("FEAT_SILENT_SPELL")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_WIDEN_SPELL, ACE_TEXT_ALWAYS_CHAR("FEAT_WIDEN_SPELL")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_ACROBATIC, ACE_TEXT_ALWAYS_CHAR("FEAT_ACROBATIC")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_AGILE, ACE_TEXT_ALWAYS_CHAR("FEAT_AGILE")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_ALERTNESS, ACE_TEXT_ALWAYS_CHAR("FEAT_ALERTNESS")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_ANIMAL_AFFINITY, ACE_TEXT_ALWAYS_CHAR("FEAT_ANIMAL_AFFINITY")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_PROFICIENCY_ARMOR_LIGHT, ACE_TEXT_ALWAYS_CHAR("FEAT_PROFICIENCY_ARMOR_LIGHT")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_PROFICIENCY_ARMOR_MEDIUM, ACE_TEXT_ALWAYS_CHAR("FEAT_PROFICIENCY_ARMOR_MEDIUM")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_PROFICIENCY_ARMOR_HEAVY, ACE_TEXT_ALWAYS_CHAR("FEAT_PROFICIENCY_ARMOR_HEAVY")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_ATHLETIC, ACE_TEXT_ALWAYS_CHAR("FEAT_ATHLETIC")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_AUGMENT_SUMMONING, ACE_TEXT_ALWAYS_CHAR("FEAT_AUGMENT_SUMMONING")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_COMBAT_CASTING, ACE_TEXT_ALWAYS_CHAR("FEAT_COMBAT_CASTING")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_DECEITFUL, ACE_TEXT_ALWAYS_CHAR("FEAT_DECEITFUL")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_DEFT_HANDS, ACE_TEXT_ALWAYS_CHAR("FEAT_DEFT_HANDS")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_DILIGENT, ACE_TEXT_ALWAYS_CHAR("FEAT_DILIGENT")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_ENDURANCE, ACE_TEXT_ALWAYS_CHAR("FEAT_ENDURANCE")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_DIE_HARD, ACE_TEXT_ALWAYS_CHAR("FEAT_DIE_HARD")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_ESCHEW_MATERIALS, ACE_TEXT_ALWAYS_CHAR("FEAT_ESCHEW_MATERIALS")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_EXTRA_TURNING, ACE_TEXT_ALWAYS_CHAR("FEAT_EXTRA_TURNING")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_GREAT_FORTITUDE, ACE_TEXT_ALWAYS_CHAR("FEAT_GREAT_FORTITUDE")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_IMPROVED_COUNTERSPELL, ACE_TEXT_ALWAYS_CHAR("FEAT_IMPROVED_COUNTERSPELL")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_IMPROVED_FAMILIAR, ACE_TEXT_ALWAYS_CHAR("FEAT_IMPROVED_FAMILIAR")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_IMPROVED_TURNING, ACE_TEXT_ALWAYS_CHAR("FEAT_IMPROVED_TURNING")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_INVESTIGATOR, ACE_TEXT_ALWAYS_CHAR("FEAT_INVESTIGATOR")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_IRON_WILL, ACE_TEXT_ALWAYS_CHAR("FEAT_IRON_WILL")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_LEADERSHIP, ACE_TEXT_ALWAYS_CHAR("FEAT_LEADERSHIP")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_LIGHTNING_REFLEXES, ACE_TEXT_ALWAYS_CHAR("FEAT_LIGHTNING_REFLEXES")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_MAGICAL_APTITUDE, ACE_TEXT_ALWAYS_CHAR("FEAT_MAGICAL_APTITUDE")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_PROFICIENCY_MARTIAL_WEAPONS, ACE_TEXT_ALWAYS_CHAR("FEAT_PROFICIENCY_MARTIAL_WEAPONS")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_NATURAL_SPELL, ACE_TEXT_ALWAYS_CHAR("FEAT_NATURAL_SPELL")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_NEGOTIATOR, ACE_TEXT_ALWAYS_CHAR("FEAT_NEGOTIATOR")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_NIMBLE_FINGERS, ACE_TEXT_ALWAYS_CHAR("FEAT_NIMBLE_FINGERS")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_PERSUASIVE, ACE_TEXT_ALWAYS_CHAR("FEAT_PERSUASIVE")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_RUN, ACE_TEXT_ALWAYS_CHAR("FEAT_RUN")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_SELF_SUFFICIENT, ACE_TEXT_ALWAYS_CHAR("FEAT_SELF_SUFFICIENT")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_PROFICIENCY_SHIELD, ACE_TEXT_ALWAYS_CHAR("FEAT_PROFICIENCY_SHIELD")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_PROFICIENCY_TOWER_SHIELD, ACE_TEXT_ALWAYS_CHAR("FEAT_PROFICIENCY_TOWER_SHIELD")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_PROFICIENCY_SIMPLE_WEAPONS, ACE_TEXT_ALWAYS_CHAR("FEAT_PROFICIENCY_SIMPLE_WEAPONS")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_SKILL_FOCUS, ACE_TEXT_ALWAYS_CHAR("FEAT_SKILL_FOCUS")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_SPELL_FOCUS, ACE_TEXT_ALWAYS_CHAR("FEAT_SPELL_FOCUS")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_GREATER_SPELL_FOCUS, ACE_TEXT_ALWAYS_CHAR("FEAT_GREATER_SPELL_FOCUS")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_SPELL_MASTERY, ACE_TEXT_ALWAYS_CHAR("FEAT_SPELL_MASTERY")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_SPELL_PENETRATION, ACE_TEXT_ALWAYS_CHAR("FEAT_SPELL_PENETRATION")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_GREATER_SPELL_PENETRATION, ACE_TEXT_ALWAYS_CHAR("FEAT_GREATER_SPELL_PENETRATION")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_STEALTHY, ACE_TEXT_ALWAYS_CHAR("FEAT_STEALTHY")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_TOUGHNESS, ACE_TEXT_ALWAYS_CHAR("FEAT_TOUGHNESS")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_TRACK, ACE_TEXT_ALWAYS_CHAR("FEAT_TRACK")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_ABILITY_FOCUS, ACE_TEXT_ALWAYS_CHAR("FEAT_ABILITY_FOCUS")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_AWESOME_BLOW, ACE_TEXT_ALWAYS_CHAR("FEAT_AWESOME_BLOW")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_CRAFT_CONSTRUCT, ACE_TEXT_ALWAYS_CHAR("FEAT_CRAFT_CONSTRUCT")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_EMPOWER_SPELLLIKE_ABILITY, ACE_TEXT_ALWAYS_CHAR("FEAT_EMPOWER_SPELLLIKE_ABILITY")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_FLYBY_ATTACK, ACE_TEXT_ALWAYS_CHAR("FEAT_FLYBY_ATTACK")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_HOVER, ACE_TEXT_ALWAYS_CHAR("FEAT_HOVER")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_IMPROVED_NATURAL_ARMOR, ACE_TEXT_ALWAYS_CHAR("FEAT_IMPROVED_NATURAL_ARMOR")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_IMPROVED_NATURAL_ATTACK, ACE_TEXT_ALWAYS_CHAR("FEAT_IMPROVED_NATURAL_ATTACK")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_MULTI_ATTACK, ACE_TEXT_ALWAYS_CHAR("FEAT_MULTI_ATTACK")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_MULTIWEAPON_FIGHTING, ACE_TEXT_ALWAYS_CHAR("FEAT_MULTIWEAPON_FIGHTING")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_QUICKEN_SPELLLIKE_ABILITY, ACE_TEXT_ALWAYS_CHAR("FEAT_QUICKEN_SPELLLIKE_ABILITY")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_SNATCH, ACE_TEXT_ALWAYS_CHAR("FEAT_SNATCH")));
    myRPG_Character_FeatToStringTable.insert(std::make_pair(FEAT_WINGOVER, ACE_TEXT_ALWAYS_CHAR("FEAT_WINGOVER")));
  };

  inline static std::string RPG_Character_FeatToString(const RPG_Character_Feat& element_in)
  {
    std::string result;
    RPG_Character_FeatToStringTableIterator_t iterator = myRPG_Character_FeatToStringTable.find(element_in);
    if (iterator != myRPG_Character_FeatToStringTable.end())
      result = iterator->second;
    else
      result = ACE_TEXT_ALWAYS_CHAR("RPG_CHARACTER_FEAT_INVALID");

    return result;
  };

  inline static RPG_Character_Feat stringToRPG_Character_Feat(const std::string& string_in)
  {
    RPG_Character_FeatToStringTableIterator_t iterator = myRPG_Character_FeatToStringTable.begin();
    do
    {
      if (iterator->second == string_in)
        return iterator->first;

      iterator++;
    } while (iterator != myRPG_Character_FeatToStringTable.end());

    return RPG_CHARACTER_FEAT_INVALID;
  };

  static RPG_Character_FeatToStringTable_t myRPG_Character_FeatToStringTable;

 private:
  ACE_UNIMPLEMENTED_FUNC(RPG_Character_FeatHelper());
  ACE_UNIMPLEMENTED_FUNC(RPG_Character_FeatHelper(const RPG_Character_FeatHelper&));
  ACE_UNIMPLEMENTED_FUNC(RPG_Character_FeatHelper& operator=(const RPG_Character_FeatHelper&));
};

#endif
