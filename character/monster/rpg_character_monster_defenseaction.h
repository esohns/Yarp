
// -------------------------------- * * * -------------------------------- //
// PLEASE NOTE: this file was/is generated by XML2CppCode 0.1
// -------------------------------- * * * -------------------------------- //

#pragma once
#ifndef RPG_CHARACTER_MONSTER_DEFENSEACTION_H
#define RPG_CHARACTER_MONSTER_DEFENSEACTION_H

#include "rpg_character_monster_exports.h"

struct RPG_Monster_Export RPG_Character_Monster_DefenseAction
{
  std::vector<RPG_Character_Monster_SpecialDefensePreCondition> preConditions;
  RPG_Combat_Damage damage;
  RPG_Combat_RangedAttackProperties ranged;
};

#endif
