
// -------------------------------- * * * ----------------------------------- //
// PLEASE NOTE: this file was/is generated by // -------------------------------- * * * ----------------------------------- //

#pragma once
#ifndef RPG_ITEM_ARMORPROPERTIESBASE_H
#define RPG_ITEM_ARMORPROPERTIESBASE_H

struct RPG_Item_ArmorPropertiesBase
 : public RPG_Item_PropertiesBase
{
  RPG_Item_ArmorType type;
  RPG_Item_ArmorCategory category;
  unsigned char baseBonus;
  unsigned char maxDexterityBonus;
  signed char checkPenalty;
  unsigned char arcaneSpellFailure;
  unsigned char baseSpeed;
};

#endif
