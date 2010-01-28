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

#ifndef RPG_MONSTER_INCL_H
#define RPG_MONSTER_INCL_H

#include <vector>
#include "rpg_monster_metatype.h"
#include "rpg_monster_subtype.h"
#include "rpg_monster_type.h"
#include "rpg_monster_naturalarmorclass.h"
#include "rpg_monster_specialpropertytypeunion.h"
#include "rpg_monster_specialbaseproperties.h"
#include "rpg_monster_naturalweapon.h"
#include "rpg_monster_weapontypeunion.h"
#include "rpg_monster_specialdefenseprecondition.h"
#include "rpg_monster_defenseaction.h"
#include "rpg_monster_specialdefenseproperties.h"
#include "rpg_monster_attackaction.h"
#include "rpg_monster_attack.h"
#include "rpg_monster_actiontrigger.h"
#include "rpg_monster_specialattackprecondition.h"
#include "rpg_monster_specialattackproperties.h"
#include "rpg_monster_specialabilityprecondition.h"
#include "rpg_monster_summonmonster.h"
#include "rpg_monster_specialabilityproperties.h"
#include "rpg_monster_savingthrowmodifiers.h"
#include "rpg_monster_organization.h"
#include "rpg_monster_organizationslaverstep.h"
#include "rpg_monster_organizationstep.h"
#include "rpg_monster_organizations.h"
#include "rpg_monster_advancementstep.h"
#include "rpg_monster_advancement.h"
#include "rpg_monster_propertiesxml.h"

#endif
