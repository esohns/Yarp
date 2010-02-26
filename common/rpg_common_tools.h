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
#ifndef RPG_COMMON_TOOLS_H
#define RPG_COMMON_TOOLS_H

#include <rpg_dice_incl.h>
#include "rpg_common_incl.h"

#include <ace/Global_Macros.h>

#include <string>

/**
	@author Erik Sohns <erik.sohns@web.de>
*/
class RPG_Common_Tools
{
 public:
  static void initStringConversionTables();

  static const RPG_Common_Attribute savingThrowToAttribute(const RPG_Common_SavingThrow&); // save
  static const std::string creatureTypeToString(const RPG_Common_CreatureType&); // type
  static const std::string savingThrowToString(const RPG_Common_SavingThrowCheck&); // save

 private:
  // safety measures
  ACE_UNIMPLEMENTED_FUNC(RPG_Common_Tools());
  ACE_UNIMPLEMENTED_FUNC(~RPG_Common_Tools());
  ACE_UNIMPLEMENTED_FUNC(RPG_Common_Tools(const RPG_Common_Tools&));
  ACE_UNIMPLEMENTED_FUNC(RPG_Common_Tools& operator=(const RPG_Common_Tools&));
};

#endif
