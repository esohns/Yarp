
// -------------------------------- * * * ----------------------------------- //
// PLEASE NOTE: this file was/is generated by XML2CppCode 0.1
// -------------------------------- * * * ----------------------------------- //

#pragma once
#ifndef RPG_MONSTER_SPECIALABILITYPROPERTIES_H
#define RPG_MONSTER_SPECIALABILITYPROPERTIES_H

#include "rpg_monster_exports.h"

struct RPG_Monster_Export RPG_Monster_SpecialAbilityProperties
 : public RPG_Monster_SpecialBaseProperties
{
  std::vector<RPG_Monster_SpecialAbilityPreCondition> preConditions;
  std::vector<RPG_Monster_SummonMonster> summons;
  std::vector<RPG_Magic_SpellLikeProperties> spells;
  RPG_Combat_RangedAttackProperties ranged;
};

#endif
