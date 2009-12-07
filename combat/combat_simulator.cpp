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
// *IMPORTANT NOTE*: need this to import correct VERSION !
#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "rpg_combat_common_tools.h"

#include <rpg_character_common_tools.h>
#include <rpg_character_skills_common_tools.h>
#include <rpg_character_dictionary.h>
#include <rpg_character_player.h>
#include <rpg_character_player_common.h>
#include <rpg_character_monster.h>

#include <rpg_item_dictionary.h>
#include <rpg_item_common_tools.h>

#include <rpg_chance_dice.h>
#include <rpg_chance_dice_common_tools.h>

#include <ace/ACE.h>
#include <ace/Log_Msg.h>
#include <ace/Get_Opt.h>
#include <ace/High_Res_Timer.h>

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

void print_usage(const std::string& programName_in)
{
  ACE_TRACE(ACE_TEXT("::print_usage"));

  std::cout << ACE_TEXT("usage: ") << programName_in << ACE_TEXT(" [OPTIONS]") << std::endl << std::endl;
  std::cout << ACE_TEXT("currently available options:") << std::endl;
  std::cout << ACE_TEXT("-i [FILE] : item dictionary (*.xml)") << std::endl;
  std::cout << ACE_TEXT("-m [FILE] : monster dictionary (*.xml)") << std::endl;
  std::cout << ACE_TEXT("-t        : trace information") << std::endl;
  std::cout << ACE_TEXT("-v        : print version information and exit") << std::endl;
} // end print_usage

const bool process_arguments(const int argc_in,
                             ACE_TCHAR* argv_in[], // cannot be const...
                             std::string& itemDictionaryFilename_out,
                             std::string& monsterDictionaryFilename_out,
                             bool& traceInformation_out,
                             bool& printVersionAndExit_out)
{
  ACE_TRACE(ACE_TEXT("::process_arguments"));

  // init results
  itemDictionaryFilename_out.clear();
  monsterDictionaryFilename_out.clear();
  traceInformation_out = false;
  printVersionAndExit_out = false;

  ACE_Get_Opt argumentParser(argc_in,
                             argv_in,
                             ACE_TEXT("i:m:tv"));

  int option = 0;
  while ((option = argumentParser()) != EOF)
  {
    switch (option)
    {
      case 'i':
      {
        itemDictionaryFilename_out = argumentParser.opt_arg();

        break;
      }
      case 'm':
      {
        monsterDictionaryFilename_out = argumentParser.opt_arg();

        break;
      }
      case 't':
      {
        traceInformation_out = true;

        break;
      }
      case 'v':
      {
        printVersionAndExit_out = true;

        break;
      }
      // error handling
      case '?':
      {
        ACE_DEBUG((LM_ERROR,
                   ACE_TEXT("unrecognized option \"%s\", aborting\n"),
                   argumentParser.last_option()));

        return false;
      }
      default:
      {
        ACE_DEBUG((LM_ERROR,
                   ACE_TEXT("unrecognized option \"%c\", aborting\n"),
                   option));

        return false;
      }
    } // end SWITCH
  } // end WHILE

  return true;
}

void do_battle(const RPG_Character_Party_t& party_in,
               const RPG_Character_Encounter_t& encounter_in)
{
  ACE_TRACE(ACE_TEXT("::do_battle"));

  // step1: instantiate monster(s)
  RPG_Character_Monsters_t monsters;
  for (RPG_Character_EncounterIterator_t iterator = encounter_in.begin();
       iterator != encounter_in.end();
       iterator++)
  {
    RPG_Character_MonsterGroupInstance_t groupInstance;
    RPG_Character_MonsterProperties properties = RPG_CHARACTER_DICTIONARY_SINGLETON::instance()->getMonsterProperties(iterator->first);
  // *TODO*: define monster abilities !
    RPG_Character_Abilities_t abilities;

    // compute individual hitpoints
    RPG_Chance_DiceRollResult_t results;
    RPG_Chance_Dice::simulateDiceRoll(properties.hitDice,
                                      iterator->second,
                                      results);
    for (RPG_Chance_DiceRollResultIterator_t iterator2 = results.begin();
         iterator2 != results.end();
         iterator2++)
    {
      // *TODO*: define default monster inventory...
      unsigned int wealth = 0;
      RPG_Item_List_t items;
      RPG_Character_Monster monster((iterator->first).c_str(),
                                    properties.type,
                                    properties.alignment,
                                    properties.attributes,
                                    properties.skills,
                                    properties.feats,
                                    abilities,
                                    (*iterator2),
                                    wealth,
                                    items);

      // debug info
//       monster.dump();

      groupInstance.push_back(monster);
    } // end FOR

    monsters.push_back(groupInstance);
  } // end FOR

  // step2: compute initiative and battle sequence
  RPG_Combat_CombatantSequence_t battleSequence;
  RPG_Combat_Common_Tools::getCombatantSequence(party_in,
                                                monsters,
                                                battleSequence);
  // perform a combat round
  while (!RPG_Combat_Common_Tools::isPartyDeadOrHelpless(party_in) &&
         !RPG_Combat_Common_Tools::areMonstersDeadOrHelpless(monsters))
  {

  } // end WHILE

  // sanity check
  if (RPG_Combat_Common_Tools::isPartyDeadOrHelpless(party_in) &&
      RPG_Combat_Common_Tools::areMonstersDeadOrHelpless(monsters))
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("everybody is DEAD --> check implementation !\n")));
  } // end IF

  if (!RPG_Combat_Common_Tools::isPartyDeadOrHelpless(party_in))
  {
    ACE_DEBUG((LM_DEBUG,
               ACE_TEXT("party has WON !\n")));

    // *TODO*: award treasure and experience...

  } // end IF
  else
  {
    ACE_DEBUG((LM_DEBUG,
               ACE_TEXT("monsters have WON !\n")));
  } // end ELSE
}

void do_work(const std::string& itemDictionaryFilename_in,
             const std::string& monsterDictionaryFilename_in)
{
  ACE_TRACE(ACE_TEXT("::do_work"));

  // step1: init: random seed, string conversion facilities, ...
  RPG_Chance_Dice::init();
  RPG_Chance_Dice_Common_Tools::initStringConversionTables();
  RPG_Item_Common_Tools::initStringConversionTables();
  RPG_Character_Common_Tools::initStringConversionTables();
  RPG_Character_Skills_Common_Tools::init();

  // step2a: init item dictionary
  try
  {
    RPG_ITEM_DICTIONARY_SINGLETON::instance()->initItemDictionary(itemDictionaryFilename_in);
  }
  catch(...)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("caught exception in RPG_Item_Dictionary::initItemDictionary, returning\n")));

    return;
  }

  // step2b: init monster dictionary
  try
  {
    RPG_CHARACTER_DICTIONARY_SINGLETON::instance()->initCharacterDictionary(monsterDictionaryFilename_in);
  }
  catch(...)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("caught exception in RPG_Character_Dictionary::initCharacterDictionary, returning\n")));

    return;
  }

  // step3: generate a (random) player character
  RPG_Character_Player player = RPG_Character_Common_Tools::generatePlayerCharacter();

  // debug info
//   player.dump();

  RPG_Character_Party_t party;
  party.push_back(player);

  // step4: generate (random) encounter
  unsigned int numMonsterTypes = 1;
  RPG_Character_Alignment alignment;
  alignment.civic = ALIGNMENTCIVIC_ANY;
  alignment.ethic = ALIGNMENTETHIC_ANY;
  RPG_Character_Environment environment;
  environment.climate = CLIMATE_ANY;
  environment.terrain = TERRAIN_ANY;
  RPG_Character_OrganizationList_t organizations;
  organizations.insert(ORGANIZATION_ANY);
  RPG_Character_Encounter_t encounter;
  RPG_CHARACTER_DICTIONARY_SINGLETON::instance()->generateRandomEncounter(numMonsterTypes,
                                                                          alignment,
                                                                          environment,
                                                                          organizations,
                                                                          encounter);

  // step6: FIGHT !
  do_battle(party,
            encounter);

  ACE_DEBUG((LM_DEBUG,
             ACE_TEXT("finished working...\n")));
} // end do_work

void do_printVersion(const std::string& programName_in)
{
  ACE_TRACE(ACE_TEXT("::do_printVersion"));

  std::cout << programName_in << ACE_TEXT(" : ") << VERSION << std::endl;

  // create version string...
  // *IMPORTANT NOTE*: cannot use ACE_VERSION, as it doesn't contain the (potential) beta version
  // number... We need this, as the library soname is compared to this string.
  std::ostringstream version_number;
  if (version_number << ACE::major_version())
  {
    version_number << ACE_TEXT(".");
  } // end IF
  else
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to convert: \"%s\", returning\n"),
               ACE_OS::strerror(errno)));

    return;
  } // end ELSE
  if (version_number << ACE::minor_version())
  {
    version_number << ".";

    if (version_number << ACE::beta_version())
    {

    } // end IF
    else
    {
      ACE_DEBUG((LM_ERROR,
                 ACE_TEXT("failed to convert: \"%s\", returning\n"),
                 ACE_OS::strerror(errno)));

      return;
    } // end ELSE
  } // end IF
  else
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to convert: \"%s\", returning\n"),
               ACE_OS::strerror(errno)));

    return;
  } // end ELSE
  std::cout << ACE_TEXT("ACE: ") << version_number.str() << std::endl;
//   std::cout << "ACE: "
//             << ACE_VERSION
//             << std::endl;
}

int ACE_TMAIN(int argc,
              ACE_TCHAR* argv[])
{
  ACE_TRACE(ACE_TEXT("::main"));

  // step1: init
  // step1a set defaults
  bool dumpDictionary      = false;
  std::string itemDictionaryFilename;
  std::string monsterDictionaryFilename;
  bool traceInformation    = false;
  bool printVersionAndExit = false;

  // step1b: parse/process/validate configuration
  if (!(process_arguments(argc,
                          argv,
                          itemDictionaryFilename,
                          monsterDictionaryFilename,
                          traceInformation,
                          printVersionAndExit)))
  {
    // make 'em learn...
    print_usage(std::string(ACE::basename(argv[0])));

    return EXIT_FAILURE;
  } // end IF

  // step1b: validate arguments
  if (itemDictionaryFilename.empty() ||
      monsterDictionaryFilename.empty())
  {
    ACE_DEBUG((LM_DEBUG,
               ACE_TEXT("invalid (XML) filename, aborting\n")));

    // make 'em learn...
    print_usage(std::string(ACE::basename(argv[0])));

    return EXIT_FAILURE;
  } // end IF

  // step1c: set correct trace level
  //ACE_Trace::start_tracing();
  if (!traceInformation)
  {
    u_long process_priority_mask = (LM_SHUTDOWN |
                                    //LM_INFO |  // <-- DISABLE trace messages !
                                    //LM_DEBUG |
                                    LM_INFO |
                                    LM_NOTICE |
                                    LM_WARNING |
                                    LM_STARTUP |
                                    LM_ERROR |
                                    LM_CRITICAL |
                                    LM_ALERT |
                                    LM_EMERGENCY);

    // set new mask...
    ACE_LOG_MSG->priority_mask(process_priority_mask,
                               ACE_Log_Msg::PROCESS);

    //ACE_LOG_MSG->stop_tracing();

    // don't go VERBOSE...
    //ACE_LOG_MSG->clr_flags(ACE_Log_Msg::VERBOSE_LITE);
  } // end IF

  // step1d: handle specific program modes
  if (printVersionAndExit)
  {
    do_printVersion(std::string(ACE::basename(argv[0])));

    return EXIT_SUCCESS;
  } // end IF

  ACE_High_Res_Timer timer;
  timer.start();

  // step2: do actual work
  do_work(itemDictionaryFilename,
          monsterDictionaryFilename);

  timer.stop();

//   // debug info
//   std::string working_time_string;
//   ACE_Time_Value working_time;
//   timer.elapsed_time(working_time);
//   RPS_FLB_Common_Tools::Period2String(working_time,
//                                       working_time_string);
  //
//   ACE_DEBUG((LM_DEBUG,
//              ACE_TEXT("total working time (h:m:s.us): \"%s\"...\n"),
//              working_time_string.c_str()));

  return EXIT_SUCCESS;
} // end main