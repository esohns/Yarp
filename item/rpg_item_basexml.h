
// -------------------------------- * * * ----------------------------------- //
// PLEASE NOTE: this file was/is generated by XML2CppCode 0.1
// -------------------------------- * * * ----------------------------------- //

#pragma once
#ifndef RPG_ITEM_BASEXML_H
#define RPG_ITEM_BASEXML_H

#include "rpg_item_exports.h"

struct RPG_Item_Export RPG_Item_BaseXML
{
  RPG_Item_Type type;
  RPG_Item_ArmorPropertiesXML armor;
  RPG_Item_CommodityPropertiesBase commodity;
  RPG_Item_WeaponPropertiesXML weapon;
};

#endif