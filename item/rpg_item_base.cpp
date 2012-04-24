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

#include "rpg_item_base.h"

#include "rpg_item_type.h"
#include "rpg_item_instance_manager.h"

#include <rpg_common_macros.h>

#include <ace/Log_Msg.h>

RPG_Item_Base::RPG_Item_Base(const RPG_Item_Type& itemType_in,
                             const RPG_Item_ID_t& itemID_in)
 : myType(itemType_in)
{
  RPG_TRACE(ACE_TEXT("RPG_Item_Base::RPG_Item_Base"));

  // register with instance manager
  // *NOTE*: the manager stores references to RPG_Item_Base (instead of RPG_Item_Instance_Base)
  // --> allows easier/consistent upcasts !
  RPG_ITEM_INSTANCE_MANAGER_SINGLETON::instance()->registerItem(itemID_in, this);
}

RPG_Item_Base::~RPG_Item_Base()
{
  RPG_TRACE(ACE_TEXT("RPG_Item_Base::~RPG_Item_Base"));

  // deregister with instance manager
  RPG_ITEM_INSTANCE_MANAGER_SINGLETON::instance()->deregisterItem(this);
}

const RPG_Item_Type
RPG_Item_Base::getType() const
{
  RPG_TRACE(ACE_TEXT("RPG_Item_Base::getType"));

  return myType;
}

void
RPG_Item_Base::dump() const
{
  RPG_TRACE(ACE_TEXT("RPG_Item_Base::dump"));

  std::string itemType = RPG_Item_TypeHelper::RPG_Item_TypeToString(myType);

  ACE_DEBUG((LM_DEBUG,
             ACE_TEXT("Item Type: %s\n"),
             itemType.c_str()));
}
