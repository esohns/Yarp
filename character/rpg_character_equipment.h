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
#ifndef RPG_CHARACTER_EQUIPMENT_H
#define RPG_CHARACTER_EQUIPMENT_H

#include "rpg_character_equipment_common.h"

#include <ace/Global_Macros.h>

/**
	@author Erik Sohns <erik.sohns@web.de>
*/
class RPG_Character_Equipment
{
 public:
  RPG_Character_Equipment();
  ~RPG_Character_Equipment();

 private:
  // safety measures
  ACE_UNIMPLEMENTED_FUNC(RPG_Character_Equipment(const RPG_Character_Equipment&));
  ACE_UNIMPLEMENTED_FUNC(RPG_Character_Equipment& operator=(const RPG_Character_Equipment&));

  // map of equipped items (values index corresponding items in the inventory !)
  RPG_CHARACTER_EQUIPMENT_T myEquipment;
};

#endif
