
// -------------------------------- * * * ----------------------------------- //
// PLEASE NOTE: this file was/is generated by XML2CppCode 0.1
// -------------------------------- * * * ----------------------------------- //

#pragma once
#ifndef RPG_ITEM_ARMORPROPERTIESBASE_H
#define RPG_ITEM_ARMORPROPERTIESBASE_H

#include "rpg_item_exports.h"

struct RPG_Item_Export RPG_Item_ArmorPropertiesBase
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
