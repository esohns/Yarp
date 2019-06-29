
// -------------------------------- * * * ----------------------------------- //
// PLEASE NOTE: this file was/is generated by // -------------------------------- * * * ----------------------------------- //

#pragma once
#ifndef RPG_ITEM_WEAPONPROPERTIESBASE_H
#define RPG_ITEM_WEAPONPROPERTIESBASE_H

struct RPG_Item_WeaponPropertiesBase
 : public RPG_Item_PropertiesBase
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
