/***************************************************************************
 *   Copyright (C) 2009 by Erik Sohns                                      *
 *   erik.sohns@web.de                                                     *
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

#ifndef RPG_ITEM_COMMODITY_H
#define RPG_ITEM_COMMODITY_H

#include "rpg_item_exports.h"
#include "rpg_item_instance_base.h"
#include "rpg_item_base.h"
#include "rpg_item_commoditytype.h"
#include "rpg_item_commoditybeverage.h"
#include "rpg_item_commoditylight.h"
#include "rpg_item_commodityunion.h"

#include <ace/Global_Macros.h>

/**
	@author Erik Sohns <erik.sohns@web.de>
*/
class RPG_Item_Export RPG_Item_Commodity
 : public RPG_Item_Instance_Base,
   public RPG_Item_Base
{
  // grant access to ctor
  friend class RPG_Item_Instance_Manager;

 public:
  // what am I ?
  const RPG_Item_CommodityType& getCommodityType() const;
  const RPG_Item_CommodityUnion& getCommoditySubType() const;

  virtual void dump() const;

 private:
  typedef RPG_Item_Instance_Base inherited;
  typedef RPG_Item_Base inherited2;

  // safety measures
  ACE_UNIMPLEMENTED_FUNC(RPG_Item_Commodity());
  RPG_Item_Commodity(const RPG_Item_CommodityType&,
                     const RPG_Item_CommodityUnion&);
  virtual ~RPG_Item_Commodity();
  ACE_UNIMPLEMENTED_FUNC(RPG_Item_Commodity(const RPG_Item_Commodity&));
  ACE_UNIMPLEMENTED_FUNC(RPG_Item_Commodity& operator=(const RPG_Item_Commodity&));

  RPG_Item_CommodityType  myCommodityType;
  RPG_Item_CommodityUnion myCommoditySubType;
};

#endif
