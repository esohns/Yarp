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

#ifndef RPG_CHARACTER_COMMON_TOOLS_H
#define RPG_CHARACTER_COMMON_TOOLS_H

#include <string>

#include "ace/Global_Macros.h"

#include "rpg_dice_incl.h"

#include "rpg_common_incl.h"

#include "rpg_character_common.h"
#include "rpg_character_encumbrance.h"
#include "rpg_character_incl.h"
#include "rpg_character_class_common.h"
#include "rpg_character_race_common.h"

class RPG_Character_Common_Tools
{
 public:
  // init string conversion (and other) tables
  static void initialize ();

  static std::string toString (const RPG_Character_Race_t&); // race(es)
  static std::string toString (const RPG_Character_Class&); // class(es)
  static std::string toString (const RPG_Character_Alignment&); // alignment
  static std::string toString (const RPG_Character_Attributes&); // attributes
  static std::string toString (const RPG_Character_Conditions_t&); // condition

  static bool match (const RPG_Character_Alignment&,  // a
                     const RPG_Character_Alignment&); // b

  static signed char getAttributeAbilityModifier (unsigned char); // attribute ability score
  static bool getAttributeCheck (unsigned char); // attribute ability score
  static enum RPG_Dice_DieType getHitDie (enum RPG_Common_SubClass); // subclass
  static RPG_Character_BaseAttackBonus_t getBaseAttackBonus (enum RPG_Common_SubClass, // subClass
                                                             unsigned char);           // class level
  static RPG_Character_Encumbrance getEncumbrance (unsigned char,        // strength
                                                   enum RPG_Common_Size, // size
                                                   unsigned short,       // (carried) weight
                                                   bool = true);         // is biped ?
  static void getLoadModifiers (enum RPG_Character_Encumbrance, // encumbrance
                                unsigned char,                  // (base) speed
                                signed char&,                   // return value: max Dex modifier (AC)
                                signed char&,                   // return value: (armor) check penalty
                                unsigned char&,                 // return value: (reduced) speed
                                unsigned char&);                // return value: run modifier
  static unsigned char getReducedSpeed (unsigned char); // (base) speed

 private:
  ACE_UNIMPLEMENTED_FUNC(RPG_Character_Common_Tools ())
  ACE_UNIMPLEMENTED_FUNC(~RPG_Character_Common_Tools ())
  ACE_UNIMPLEMENTED_FUNC(RPG_Character_Common_Tools (const RPG_Character_Common_Tools&))
  ACE_UNIMPLEMENTED_FUNC(RPG_Character_Common_Tools& operator= (const RPG_Character_Common_Tools&))

  static void initializeStringConversionTables ();
  static void initializeEncumbranceTable ();

  struct RPG_Character_EncumbranceEntry_t
  {
    unsigned short light;
    unsigned short medium;
    unsigned short heavy;
  };
  typedef std::map<unsigned char, RPG_Character_EncumbranceEntry_t> RPG_Character_EncumbranceTable_t;
  typedef RPG_Character_EncumbranceTable_t::const_iterator RPG_Character_EncumbranceTableConstIterator_t;

  static RPG_Character_EncumbranceTable_t myEncumbranceTable;
};

#endif
