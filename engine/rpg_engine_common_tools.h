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

#ifndef RPG_ENGINE_COMMON_TOOLS_H
#define RPG_ENGINE_COMMON_TOOLS_H

#include "rpg_engine_exports.h"
#include "rpg_engine_defines.h"
#include "rpg_engine_common.h"
#include "rpg_engine_event_common.h"
#include "rpg_engine_level.h"
#include "rpg_engine_XML_tree.h"

#include "rpg_map_common.h"

#include "rpg_monster_common.h"

#include "rpg_player_common.h"
#include "rpg_player_XML_tree.h"

#include "rpg_combat_attacksituation.h"
#include "rpg_combat_defensesituation.h"

#include "rpg_character_class_common.h"

#include "rpg_item_instance_common.h"

#include "rpg_common_subclass.h"

#include "ace/Global_Macros.h"

#include <string>
#include <deque>

/**
	@author Erik Sohns <erik.sohns@web.de>
*/
class RPG_Engine_Export RPG_Engine_Common_Tools
{
 public:
  // *NOTE*: initializes (static) data from ALL individual modules
  // in particular: - randomization
  //                - string conversion facilities
  //                - static tables (skills, spells, experience, ...)
  //                - XML parsing facilities
  //                - dictionaries (spells, items, monsters, ...)
  static void init(const std::string&,  // schema directory
                   const std::string&,  // magic dictionary file
                   const std::string&,  // item dictionary file
                   const std::string&); // monster dictionary file
  static void fini();

	// ***** event-related *****
	static bool isOneShotEvent(const RPG_Engine_EventType&);

  // ***** state-related *****
  static std::string getEngineStateDirectory();

  // ***** entity-related *****
  static RPG_Engine_Entity_t createEntity();
  static RPG_Engine_Entity_t createEntity(// base attributes
                                          const std::string&,                // creature type
                                          const unsigned short int&,         // max HP
                                          // extended data
                                          const unsigned int&,               // wealth (GP)
                                          const RPG_Item_List_t&,            // list of (carried) items
                                          // current status
                                          const RPG_Character_Conditions_t&, // condition
                                          const short int&,                  // HP
                                          const RPG_Magic_Spells_t&);        // set of memorized/prepared spells (if any)

  static std::string info(const RPG_Engine_Entity_t&); // entity
  static RPG_Item_List_t generateStandardItems(const RPG_Common_SubClass&);

  // ***** combat-related *****
  static unsigned int range(const RPG_Map_Position_t&,  // A
                            const RPG_Map_Position_t&); // B
  static bool isCharacterHelpless(const RPG_Player_Base* const); // character handle
  static bool isCharacterDisabled(const RPG_Player_Base* const); // character handle
  static bool isPartyHelpless(const RPG_Player_Party_t&); // party
  static bool areMonstersHelpless(const RPG_Monster_Groups_t&); // monsters
  static void getCombatantSequence(const RPG_Player_Party_t&,        // party
                                   const RPG_Monster_Groups_t&,      // monsters
                                   RPG_Engine_CombatantSequence_t&); // battle sequence
  static void performCombatRound(const RPG_Combat_AttackSituation&,      // attack situation
                                 const RPG_Combat_DefenseSituation&,     // defense situation
                                 const RPG_Engine_CombatantSequence_t&); // battle sequence
  static bool attack(const RPG_Player_Base*,                              // attacker
                     RPG_Player_Base*,                                    // defender
                     const RPG_Combat_AttackSituation& = ATTACK_NORMAL,   // attack situation
                     const RPG_Combat_DefenseSituation& = DEFENSE_NORMAL, // defense situation
                     const bool& = true,                                  // full-round action ?
                     const unsigned short& = RPG_ENGINE_FEET_PER_SQUARE); // distance (feet)
	static unsigned int party2ACL(const RPG_Player_Party_t&);
  static unsigned int combat2XP(const std::string&,       // type
                                const unsigned int&,      // ACL (average character level)
                                const unsigned int& = 1,  // number of foes
                                const unsigned int& = 1); // number of party members

 private:
  ACE_UNIMPLEMENTED_FUNC(RPG_Engine_Common_Tools());
  ACE_UNIMPLEMENTED_FUNC(~RPG_Engine_Common_Tools());
  ACE_UNIMPLEMENTED_FUNC(RPG_Engine_Common_Tools(const RPG_Engine_Common_Tools&));
  ACE_UNIMPLEMENTED_FUNC(RPG_Engine_Common_Tools& operator=(const RPG_Engine_Common_Tools&));

  // helper types
  typedef std::deque<RPG_Engine_CombatantSequenceElement_t> RPG_Engine_CombatSequenceList_t;
  typedef RPG_Engine_CombatSequenceList_t::iterator RPG_Engine_CombatSequenceListIterator_t;

  // helper methods
  static void initCR2ExperienceMap();
  static bool isMonsterGroupHelpless(const RPG_Monster_Group_t&); // group instance
  static bool isValidFoeAvailable(const bool&,                            // monsters ? : players
                                  const RPG_Engine_CombatantSequence_t&); // battle sequence

  static unsigned int numCompatibleMonsterAttackActions(const RPG_Combat_AttackForm&,
                                                        const RPG_Monster_AttackActions_t&);
  static bool isCompatibleMonsterAttackAction(const RPG_Combat_AttackForm&,
                                              const RPG_Monster_AttackAction&);

//  // *WARNING*: result needs to be delete()d !
//  static RPG_Engine_EntityState_XMLTree_Type* playerXMLToEntityStateXML(const RPG_Player_PlayerXML_XMLTree_Type&);

  static RPG_Engine_CR2ExperienceMap_t myCR2ExperienceMap;
};

#endif
