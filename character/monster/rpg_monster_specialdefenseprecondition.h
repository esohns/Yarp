
// -------------------------------- * * * ----------------------------------- //
// PLEASE NOTE: this file was/is generated by // -------------------------------- * * * ----------------------------------- //

#pragma once
#ifndef RPG_MONSTER_SPECIALDEFENSEPRECONDITION_H
#define RPG_MONSTER_SPECIALDEFENSEPRECONDITION_H

struct RPG_Monster_SpecialDefensePreCondition
{
  std::vector<RPG_Monster_WeaponTypeUnion> weaponTypes;
  std::vector<RPG_Common_Condition> ownConditions;
  std::vector<RPG_Common_Condition> targetConditions;
  bool isMagicalWeapon;
};

#endif
