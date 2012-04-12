﻿/***************************************************************************
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

#ifndef RPG_MONSTER_H
#define RPG_MONSTER_H

#include "rpg_monster_exports.h"

#include <rpg_player_base.h>

#include <rpg_combat_defensesituation.h>
#include <rpg_combat_attacksituation.h>

#include <rpg_magic_common.h>

#include <rpg_character_incl.h>
#include <rpg_character_common.h>
#include <rpg_character_skills_common.h>

#include <rpg_item_instance_common.h>

#include <rpg_dice_incl.h>
#include <rpg_common_incl.h>

#include <ace/Global_Macros.h>

/**
	@author Erik Sohns <erik.sohns@web.de>
*/
class RPG_Monster_Export RPG_Monster
 : public RPG_Player_Base
{
 public:
  RPG_Monster(// base attributes
              const std::string&,                // name
              const RPG_Common_CreatureType&,    // type
              const RPG_Character_Alignment&,    // alignment
              const RPG_Character_Attributes&,   // base attributes
              const RPG_Character_Skills_t&,     // skills
              const RPG_Character_Feats_t&,      // base feats
              const RPG_Character_Abilities_t&,  // base abilities
              const RPG_Common_Size&,            // (default) size
              const unsigned short int&,         // max HP
              const RPG_Magic_SpellTypes_t&,     // set of known spells (if any)
              // current status
              const RPG_Character_Conditions_t&, // condition
              const unsigned short int&,         // HP
              const unsigned int&,               // wealth (GP)
              const RPG_Magic_Spells_t&,         // set of memorized/prepared spells (if any)
              const RPG_Item_List_t&,            // list of (carried) items
              const bool& = false);              // summoned ?
  RPG_Monster(const RPG_Monster&);
  virtual ~RPG_Monster();
//   RPG_Monster& operator=(const RPG_Monster&);

  const RPG_Common_CreatureType& getType() const;
  bool isSummoned() const;

  // access current equipment (if any)
  const RPG_Player_Equipment& getEquipment() const;

  virtual signed char getArmorClass(const RPG_Combat_DefenseSituation&) const;
  virtual unsigned char getSpeed(const RPG_Common_AmbientLighting&) const; // environment

  virtual void gainExperience(const unsigned int&); // XP

  virtual bool isPlayerCharacter() const;

  virtual void dump() const;

 private:
  typedef RPG_Player_Base inherited;

  // safety measures
  ACE_UNIMPLEMENTED_FUNC(RPG_Monster());

  // helper methods
  virtual RPG_Character_BaseAttackBonus_t getAttackBonus(const RPG_Common_Attribute&, // modifier
                                                         const RPG_Combat_AttackSituation&) const;
  virtual signed char getShieldBonus() const;

  RPG_Common_CreatureType myType;
  bool                    myIsSummoned;
};

#endif
