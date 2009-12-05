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
#ifndef RPG_COMBAT_COMMON_TOOLS_H
#define RPG_COMBAT_COMMON_TOOLS_H

#include <rpg_character_common.h>
#include <rpg_character_player.h>
#include <rpg_character_player_common.h>

#include <ace/Global_Macros.h>

/**
	@author Erik Sohns <erik.sohns@web.de>
*/
class RPG_Combat_Common_Tools
{
 public:
  static const bool isPartyDead(const RPG_Character_Party_t&); // party
  static const bool areMonstersDead(const RPG_Character_Monsters_t&); // monsters

 private:
  // safety measures
  ACE_UNIMPLEMENTED_FUNC(RPG_Combat_Common_Tools());
  ACE_UNIMPLEMENTED_FUNC(~RPG_Combat_Common_Tools());
  ACE_UNIMPLEMENTED_FUNC(RPG_Combat_Common_Tools(const RPG_Combat_Common_Tools&));
  ACE_UNIMPLEMENTED_FUNC(RPG_Combat_Common_Tools& operator=(const RPG_Combat_Common_Tools&));

  static const bool isMonsterGroupDead(const RPG_Character_MonsterGroupInstance_t&); // group instance
};

#endif
