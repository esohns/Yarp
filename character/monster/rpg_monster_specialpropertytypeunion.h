
// -------------------------------- * * * ----------------------------------- //
// PLEASE NOTE: this file was/is generated by XML2CppCode 0.1
// -------------------------------- * * * ----------------------------------- //

#pragma once
#ifndef RPG_MONSTER_SPECIALPROPERTYTYPEUNION_H
#define RPG_MONSTER_SPECIALPROPERTYTYPEUNION_H

#include "rpg_monster_exports.h"

struct RPG_Monster_Export RPG_Monster_SpecialPropertyTypeUnion
{
  union
  {
    RPG_Character_Ability ability;
    RPG_Magic_AbilityType abilitytype;
  };

  enum Discriminator_t
  {
    ABILITY,
    ABILITYTYPE,
    INVALID
  };
  Discriminator_t discriminator;
};

#endif
