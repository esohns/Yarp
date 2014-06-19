
// -------------------------------- * * * ----------------------------------- //
// PLEASE NOTE: this file was/is generated by XML2CppCode 0.1
// -------------------------------- * * * ----------------------------------- //

#pragma once
#ifndef RPG_ITEM_WEAPONPROPERTIESBASE_H
#define RPG_ITEM_WEAPONPROPERTIESBASE_H

#include "rpg_item_exports.h"

struct RPG_Item_Export RPG_Item_WeaponPropertiesBase
 : public RPG_Item_PropertiesBase
{
#include "rpg_item_exports.h"

struct RPG_Item_Export RPG_Item_WeaponPropertiesBase
{
  RPG_Item_WeaponType type;
  RPG_Item_WeaponCategory category;
  RPG_Item_WeaponClass weaponClass;
  RPG_Dice_Roll baseDamage;
  RPG_Item_CriticalHitProperties criticalHit;
  unsigned char rangeIncrement;
  std::vector<RPG_Common_PhysicalDamageType> typeOfDamages;
  bool isNonLethal;
  bool isReachWeapon;
  bool isDoubleWeapon;
};

#endif
