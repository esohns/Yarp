
// -------------------------------- * * * ----------------------------------- //
// PLEASE NOTE: this file was/is generated by XML2CppCode 0.1
// -------------------------------- * * * ----------------------------------- //

#pragma once
#ifndef RPG_MONSTER_DEFENSEACTION_H
#define RPG_MONSTER_DEFENSEACTION_H

#include "rpg_monster_exports.h"

struct RPG_Monster_Export RPG_Monster_DefenseAction
{
  std::vector<RPG_Monster_SpecialDefensePreCondition> preConditions;
  RPG_Combat_Damage damage;
  RPG_Combat_RangedAttackProperties ranged;
};

#endif
