
// -------------------------------- * * * -------------------------------- //
// PLEASE NOTE: this file was/is generated by XML2CppCode 0.1
// -------------------------------- * * * -------------------------------- //

#pragma once
#ifndef RPG_CHARACTER_MONSTER_SPECIALPROPERTYTYPEUNION_H
#define RPG_CHARACTER_MONSTER_SPECIALPROPERTYTYPEUNION_H

struct RPG_Character_Monster_SpecialPropertyTypeUnion
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
