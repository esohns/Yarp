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
#ifndef RPG_CHARACTER_SKILLS_COMMON_H
#define RPG_CHARACTER_SKILLS_COMMON_H

#include "rpg_character_common.h"
#include "rpg_character_class_common.h"

#include <map>
#include <set>

enum RPG_Character_Skill
{
  SKILL_APPRAISE = 0,
  SKILL_BALANCE,
  SKILL_BLUFF,
  SKILL_CLIMB,
  SKILL_CONCENTRATION,
  SKILL_CRAFT_ANY,
  SKILL_CRAFT_ALL,
  SKILL_CRAFT_ALCHEMY,
  SKILL_CRAFT_FLETCHER,
  SKILL_CRAFT_BOWYER,
  SKILL_CRAFT_SMITH_ARMOR,
  SKILL_CRAFT_SMITH_BLACK,
  SKILL_CRAFT_SMITH_WEAPON,
  SKILL_CRAFT_TRAP,
  SKILL_CRAFT_OTHER,
  SKILL_DECIPHER_SCRIPT,
  SKILL_DIPLOMACY,
  SKILL_DISABLE_DEVICE,
  SKILL_DISGUISE,
  SKILL_ESCAPE_ARTIST,
  SKILL_FORGERY,
  SKILL_GATHER_INFORMATION,
  SKILL_HANDLE_ANIMAL,
  SKILL_HEAL,
  SKILL_HIDE,
  SKILL_INTIMIDATE,
  SKILL_JUMP,
  SKILL_KNOWLEDGE_ANY,
  SKILL_KNOWLEDGE_ALL,
  SKILL_KNOWLEDGE_ARCANA,
  SKILL_KNOWLEDGE_ARCH_ENG,
  SKILL_KNOWLEDGE_DUNGEONS,
  SKILL_KNOWLEDGE_GEOGRAPHY,
  SKILL_KNOWLEDGE_HISTORY,
  SKILL_KNOWLEDGE_LOCAL,
  SKILL_KNOWLEDGE_NATURE,
  SKILL_KNOWLEDGE_NOB_ROY,
  SKILL_KNOWLEDGE_RELIGION,
  SKILL_KNOWLEDGE_PLANES,
  SKILL_LISTEN,
  SKILL_MOVE_SILENTLY,
  SKILL_OPEN_LOCK,
  SKILL_PERFORM,
  SKILL_PROFESSION,
  SKILL_RIDE,
  SKILL_SEARCH,
  SKILL_SENSE_MOTIVE,
  SKILL_SLEIGHT_OF_HAND,
  SKILL_SPEAK_LANGUAGE,
  SKILL_SPELLCRAFT,
  SKILL_SPOT,
  SKILL_SURVIVAL,
  SKILL_SWIM,
  SKILL_TUMBLE,
  SKILL_USE_MAGIC_DEVICE,
  SKILL_USE_ROPE,
  //
  SKILL_MAX,
  SKILL_INVALID
};

enum RPG_Character_Feat
{
  // fighter bonus
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
  // item creation
  FEAT_BREW_POTION,
  FEAT_CRAFT_MAGIC_ARMS_AND_ARMOR,
  FEAT_CRAFT_ROD,
  FEAT_CRAFT_STAFF,
  FEAT_CRAFT_WAND,
  FEAT_CRAFT_WONDROUS_ITEM,
  FEAT_FORGE_RING,
  FEAT_SCRIBE_SCROLL,
  // meta-magic
  FEAT_EMPOWER_SPELL,
  FEAT_ENLARGE_SPELL,
  FEAT_EXTEND_SPELL,
  FEAT_HEIGHTEN_SPELL,
  FEAT_MAXIMIZE_SPELL,
  FEAT_QUICKEN_SPELL,
  FEAT_SILENT_SPELL,
  FEAT_WIDEN_SPELL,
  // general
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
  // monster
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
  FEAT_MAX,
  FEAT_INVALID
};

enum RPG_Character_Ability
{
  ABILITY_SCORE_LOSS = 0,
  ABILITY_ALTERNATE_FORM,
  ABILITY_ANTIMAGIC,
  ABILITY_BLINDSIGHT,
  ABILITY_BLINDSENSE,
  ABILITY_BREATH_WEAPON,
  ABILITY_CHANGE_SHAPE,
  ABILITY_CHARM,
  ABILITY_COMPULSION,
  ABILITY_IMMUNITY_COLD,
  ABILITY_CONSTRICT,
  ABILITY_RESISTANCE_TO_DAMAGE,
  ABILITY_DARKVISION,
  ABILITY_DEATH_ATTACK,
  ABILITY_DISEASE,
  ABILITY_ENERGY_DRAIN,
  ABILITY_ETHEREALNESS,
  ABILITY_EVASION,
  ABILITY_IMPROVED_EVASION,
  ABILITY_FAST_HEALING,
  ABILITY_FEAR,
  ABILITY_IMMUNITY_FIRE,
  ABILITY_GASEOUS_FORM,
  ABILITY_GAZE_ATTACK,
  ABILITY_IMPROVED_GRAB,
  ABILITY_INCORPOREALITY,
  ABILITY_INVISIBILITY,
  ABILITY_LEVEL_LOSS,
  ABILITY_LOWLIGHT_VISION,
  ABILITY_MANUFACTURED_WEAPONS,
  ABILITY_MOVEMENT_MODES,
  ABILITY_NATURAL_WEAPONS,
  ABILITY_NONABILITIES,
  ABILITY_PARALYZE_ATTACK,
  ABILITY_POISON_ATTACK,
  ABILITY_IMMUNITY_POISON,
  ABILITY_POLYMORPH,
  ABILITY_POUNCE,
  ABILITY_POWERFUL_CHARGE,
  ABILITY_PSIONICS,
  ABILITY_RAKE,
  ABILITY_RAY_ATTACK,
  ABILITY_REGENERATION,
  ABILITY_RESISTANCE_TO_ENERGY,
  ABILITY_SCENT,
  ABILITY_SONIC_ATTACK,
  ABILITY_IMMUNITY_SPELL,
  ABILITY_RESISTANCE_TO_SPELL,
  ABILITY_SPELLS,
  ABILITY_SUMMON,
  ABILITY_SWALLOW_WHOLE,
  ABILITY_TELEPATHY,
  ABILITY_TRAMPLE,
  ABILITY_TREMOR_SENSE,
  ABILITY_RESISTANCE_TO_TURNING,
  ABILITY_VULNERABILITY_TO_ENERGY,
  // Monk abilities
  ABILITY_IMMUNITY_DISEASE,
  // Druid/Ranger abilities
  ABILITY_ANIMAL_COMPANION,
  ABILITY_WOODLAND_STRIDE,
  // Rogue abilities
  ABILITY_SENSE_TRAPS,
  ABILITY_UNCANNY_DODGE,
  ABILITY_IMPROVED_UNCANNY_DODGE,
  ABILITY_CRIPPLING_STRIKE,
  ABILITY_DEFENSIVE_ROLL,
  ABILITY_OPPORTUNIST,
  ABILITY_SKILL_MASTERY,
  ABILITY_SLIPPERY_MIND,
  ABILITY_BONUS_FEAT,
  //
  ABILITY_MAX,
  ABILITY_INVALID
};

enum RPG_Character_Feat_Prerequisite_Type
{
  FEAT_PREREQUISITETYPE_MINATTRIBUTESCORE = 0,
  FEAT_PREREQUISITETYPE_OTHERFEAT,
  FEAT_PREREQUISITETYPE_MINBASEATTACKBONUS,
  FEAT_PREREQUISITETYPE_MINSKILLRANK,
  FEAT_PREREQUISITETYPE_MINCLASSLEVEL,
  FEAT_PREREQUISITETYPE_MINCASTERLEVEL,
  FEAT_PREREQUISITETYPE_RESTRICTEDCLASSES,
  FEAT_PREREQUISITETYPE_ABILITY,
  //
  FEAT_PREREQUISITETYPE_MAX,
  FEAT_PREREQUISITETYPE_INVALID
};

struct RPG_Character_Feat_Prerequisite
{
  RPG_Character_Feat_Prerequisite_Type prerequisiteType;
  RPG_Character_Feat requiredOtherFeat;            // if applicable
  RPG_Character_Attribute attribute;               // if applicable
  unsigned char minValue;                          // if applicable
  RPG_Character_Skill skill;                       // if applicable
  RPG_Character_SubClasses_t restrictedSubClasses; // if applicable
  RPG_Character_Ability requiredAbility;           // if applicable
};

// some useful types
typedef std::pair<RPG_Character_Skill, char> RPG_Character_SkillsItem_t;
typedef std::map<RPG_Character_Skill, char> RPG_Character_Skills_t;
// typedef RPG_Character_Skills_t::value_type RPG_Character_SkillsItem_t;
typedef RPG_Character_Skills_t::iterator RPG_Character_SkillsIterator_t;
typedef RPG_Character_Skills_t::const_iterator RPG_Character_SkillsConstIterator_t;
typedef std::multiset<RPG_Character_Feat> RPG_Character_Feats_t;
typedef RPG_Character_Feats_t::iterator RPG_Character_FeatsIterator_t;
typedef RPG_Character_Feats_t::const_iterator RPG_Character_FeatsConstIterator_t;
typedef std::set<RPG_Character_Ability> RPG_Character_Abilities_t;
typedef RPG_Character_Abilities_t::const_iterator RPG_Character_AbilitiesConstIterator_t;

#endif
