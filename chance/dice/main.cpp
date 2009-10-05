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

#include "rpg_chance_dice_common.h"
#include "rpg_chance_dice.h"

#include <ace/OS.h>
#include <ace/ACE.h>
#include <ace/Trace.h>
#include <ace/Get_Opt.h>
#include <ace/High_Res_Timer.h>

#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

void print_usage()
{
  ACE_TRACE(ACE_TEXT("::print_usage"));

  std::cout << ACE_TEXT("usage: dice [OPTIONS]")
            << std::endl
            << std::endl;
  std::cout << ACE_TEXT("currently available options:")
            << std::endl;
  std::cout << ACE_TEXT("-d [VALUE]    : type of dice (# sides: 4, 6, 8, 10, 12, 20 or 100); default: 6")
            << std::endl;
  std::cout << ACE_TEXT("-m [VALUE]    : modifier (e.g. +/-1, as in a roll of e.g. 2d4+1); default: 0")
            << std::endl;
  std::cout << ACE_TEXT("-n [VALUE]    : number of dice (e.g. as in a roll of 3d4); default: 1")
            << std::endl;
  std::cout << ACE_TEXT("-r [VALUE]    : number of such rolls; default: 1")
            << std::endl;
  std::cout << ACE_TEXT("-s            : include sorted result")
            << std::endl;
  std::cout << ACE_TEXT("-t            : trace information")
            << std::endl;
  std::cout << ACE_TEXT("-v            : print version information and exit")
            << std::endl;
} // end print_usage

const bool process_arguments(const int argc_in,
                             ACE_TCHAR* argv_in[], // cannot be const...
                             RPG_Chance_Roll& rollSpecs_out,
                             unsigned int& numRolls_out,
                             bool& includeSortedResult_out,
                             bool& traceInformation_out,
                             bool& printVersionAndExit_out)
{
  ACE_TRACE(ACE_TEXT("::process_arguments"));

  // init results
  rollSpecs_out.numDice = 1;
  rollSpecs_out.typeDice = D_6;
  rollSpecs_out.modifier = 0;
  numRolls_out = 1;
  includeSortedResult_out = false;
  traceInformation_out = false;
  printVersionAndExit_out = false;

  ACE_Get_Opt argumentParser(argc_in,
                             argv_in,
                             ACE_TEXT("d:m:n:r:stv"));

  int option = 0;
  while ((option = argumentParser()) != EOF)
  {
    switch (option)
    {
      case 'd':
      {
        // make sure this is a valid number...
        unsigned int temp = ::atol(argumentParser.opt_arg());
        switch (temp)
        {
          case D_4:
          case D_6:
          case D_8:
          case D_10:
          case D_12:
          case D_20:
          case D_100:
          {
            rollSpecs_out.typeDice = ACE_static_cast(RPG_Chance_Dice_Type,
                                                     temp);

            break;
          }
          default:
          {
            ACE_DEBUG((LM_ERROR,
                       ACE_TEXT("invalid input \"%s\", aborting\n"),
                       argumentParser.last_option()));

            return false;
          }
        } // end SWITCH

        break;
      }
      case 'm':
      {
        rollSpecs_out.modifier = ::atol(argumentParser.opt_arg());

        break;
      }
      case 'n':
      {
        rollSpecs_out.numDice = ::atol(argumentParser.opt_arg());

        break;
      }
      case 'r':
      {
        numRolls_out = ::atol(argumentParser.opt_arg());

        break;
      }
      case 's':
      {
        includeSortedResult_out = true;

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

void do_work(const RPG_Chance_Roll& rollSpecs_in,
             const unsigned int& numRolls_in,
             const bool& includeSortedResult_in)
{
  ACE_TRACE(ACE_TEXT("::do_work"));

  // step1: init randomization
  try
  {
    RPG_Chance_Dice::init();
  }
  catch(...)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("caught exception in RPG_Chance_Dice::init, returning\n")));

    return;
  }

  // step2: generate some randomness...
  RPG_Chance_Dice::RPG_CHANCE_DICE_RESULT_T result;
  try
  {
    RPG_Chance_Dice::simulateDiceRoll(rollSpecs_in,
                                      numRolls_in,
                                      result);
  }
  catch(...)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("caught exception in RPG_Chance_Dice::simulateDiceRoll, returning\n")));

    return;
  }

  // debug info
  std::ostringstream converter;
  for (RPG_Chance_Dice::RPG_CHANCE_DICE_RESULT_ITERATOR_T iter = result.begin();
       iter != result.end();
       iter++)
  {
    converter << (*iter);
    converter << ACE_TEXT(" ");
  } // end FOR
  std::string line_string = converter.str();
  ACE_DEBUG((LM_INFO,
             ACE_TEXT("%s\n"),
             line_string.c_str()));

  // dump sorted result too ?
  if (includeSortedResult_in)
  {
    ACE_DEBUG((LM_INFO,
               ACE_TEXT("\n--- sorted ---\n")));

    // sort array
    std::sort(result.begin(),
              result.end());

    converter.str(std::string()); // "reset" it...
    for (RPG_Chance_Dice::RPG_CHANCE_DICE_RESULT_ITERATOR_T iter = result.begin();
         iter != result.end();
         iter++)
    {
      converter << (*iter);
      converter << ACE_TEXT_ALWAYS_CHAR(" ");
    } // end FOR
    line_string = converter.str();
    ACE_DEBUG((LM_INFO,
              ACE_TEXT("%s\n"),
              line_string.c_str()));
  } // end IF

  ACE_DEBUG((LM_DEBUG,
             ACE_TEXT("finished working...\n")));
} // end do_work

void do_printVersion()
{
  ACE_TRACE(ACE_TEXT("::do_printVersion"));

  std::cout << ACE_TEXT("dice: ")
            << VERSION
            << std::endl;

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
  std::cout << ACE_TEXT("ACE: ")
            << version_number.str()
            << std::endl;
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
  RPG_Chance_Roll rollSpecs;
  rollSpecs.typeDice       = D_6;
  rollSpecs.numDice        = 1;
  rollSpecs.modifier       = 0;
  unsigned int numRolls    = 1;
  bool includeSortedResult = false;
  bool traceInformation    = false;
  bool printVersionAndExit = false;

  // step1b: parse/process/validate configuration
  if (!(process_arguments(argc,
                          argv,
                          rollSpecs,
                          numRolls,
                          includeSortedResult,
                          traceInformation,
                          printVersionAndExit)))
  {
    // make 'em learn...
    print_usage();

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
    do_printVersion();

    return EXIT_SUCCESS;
  } // end IF

  ACE_High_Res_Timer timer;
  timer.start();

  // step2: do actual work
  do_work(rollSpecs,
          numRolls,
          includeSortedResult);

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
