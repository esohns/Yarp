/***************************************************************************
 *   Copyright (C) 2009 by Erik Sohns   *
 *   erik.sohns@web.de   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/
#include "stdafx.h"

#include "rpg_item_commodity.h"

#include "rpg_item_common_tools.h"
#include "rpg_item_dictionary.h"

#include <rpg_common_macros.h>

#include <ace/Log_Msg.h>

RPG_Item_Commodity::RPG_Item_Commodity(const RPG_Item_CommodityType& commodityType_in,
                                       const RPG_Item_CommodityUnion& commoditySubType_in)
 : inherited(), // *NOTE*: this generates a new item ID
   inherited2(ITEM_COMMODITY,
              getID()), // <-- retrieve generated item ID
   myCommodityType(commodityType_in),
   myCommoditySubType(commoditySubType_in)
{
  RPG_TRACE(ACE_TEXT("RPG_Item_Commodity::RPG_Item_Commodity"));

}

RPG_Item_Commodity::~RPG_Item_Commodity()
{
  RPG_TRACE(ACE_TEXT("RPG_Item_Commodity::RPG_Item_Commodity"));

}

const RPG_Item_CommodityType&
RPG_Item_Commodity::getCommodityType() const
{
  RPG_TRACE(ACE_TEXT("RPG_Item_Commodity::getCommodityType"));

  return myCommodityType;
}

const RPG_Item_CommodityUnion&
RPG_Item_Commodity::getCommoditySubType() const
{
  RPG_TRACE(ACE_TEXT("RPG_Item_Commodity::getCommoditySubType"));

  return myCommoditySubType;
}

void
RPG_Item_Commodity::dump() const
{
  RPG_TRACE(ACE_TEXT("RPG_Item_Commodity::dump"));

  // retrieve properties
  RPG_Item_CommodityProperties properties = RPG_ITEM_DICTIONARY_SINGLETON::instance()->getCommodityProperties(myCommoditySubType);

  ACE_DEBUG((LM_DEBUG,
            ACE_TEXT("Item: Commodity\nType: %s\nPrice: %d GP, %d SP\nWeight: %d\n"),
            RPG_Item_CommodityTypeHelper::RPG_Item_CommodityTypeToString(myCommodityType).c_str(),
            properties.baseStorePrice.numGoldPieces,
            properties.baseStorePrice.numSilverPieces,
            properties.baseWeight));
}