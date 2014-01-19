
// -------------------------------- * * * -------------------------------- //
// PLEASE NOTE: this file was/is generated by XML2CppCode 0.1
// -------------------------------- * * * -------------------------------- //

#pragma once
#ifndef RPG_MONSTER_ATTACKACTION_H
#define RPG_MONSTER_ATTACKACTION_H

#include "rpg_monster_exports.h"

struct RPG_Monster_Export RPG_Monster_AttackAction
{
  RPG_Monster_WeaponTypeUnion weapon;
  std::vector<signed char> attackBonuses;
  std::vector<RPG_Combat_AttackForm> attackForms;
  RPG_Combat_Damage damage;
  RPG_Magic_SpellLikeProperties effect;
  unsigned char numAttacksPerRound;
  RPG_Combat_RangedAttackProperties ranged;
  std::vector<RPG_Character_Ability> triggers;
  bool allAdjacent;
  bool fullAttackIncludesNextAction;
};

#endif
