
// -------------------------------- * * * -------------------------------- //
// PLEASE NOTE: this file was/is generated by XML2CppCode 0.1
// -------------------------------- * * * -------------------------------- //

#pragma once
#ifndef RPG_ITEM_COMMODITYPROPERTIESBASE_H
#define RPG_ITEM_COMMODITYPROPERTIESBASE_H

#include "rpg_item_exports.h"

struct RPG_Item_Export RPG_Item_CommodityPropertiesBase
 : public RPG_Item_PropertiesBase
{
  RPG_Item_CommodityType type;
  RPG_Item_CommodityUnion subtype;
};

#endif