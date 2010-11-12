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

// *NOTE*: need this to import correct VERSION !
#ifdef HAVE_CONFIG_H
#include <rpg_config.h>
#endif

#include <rpg_map_common_tools.h>

#include <rpg_dice.h>
#include <rpg_dice_common_tools.h>

#include <rpg_common_macros.h>
#include <rpg_common_tools.h>

#include <ace/ACE.h>
#include <ace/Log_Msg.h>
#include <ace/Get_Opt.h>
#include <ace/High_Res_Timer.h>

#include <string>
#include <sstream>
#include <iostream>

#define MAP_GENERATOR_DEF_MIN_ROOMSIZE          0
#define MAP_GENERATOR_DEF_DOORS                 true
#define MAP_GENERATOR_DEF_CORRIDORS             true
#define MAP_GENERATOR_DEF_MAX_NUMDOORS_PER_ROOM 3
#define MAP_GENERATOR_DEF_MAXIMIZE_ROOMSIZE     true
#define MAP_GENERATOR_DEF_RANDOM_START_POSITION true
#define MAP_GENERATOR_DEF_NUM_AREAS             5
#define MAP_GENERATOR_DEF_SQUARE_ROOMS          true
#define MAP_GENERATOR_DEF_DIMENSION_X           80
#define MAP_GENERATOR_DEF_DIMENSION_Y           40

void
print_usage(const std::string& programName_in)
{
  RPG_TRACE(ACE_TEXT("::print_usage"));

  // enable verbatim boolean output
  std::cout.setf(ios::boolalpha);

  std::cout << ACE_TEXT("usage: ") << programName_in << ACE_TEXT(" [OPTIONS]") << std::endl << std::endl;
  std::cout << ACE_TEXT("currently available options:") << std::endl;
  std::cout << ACE_TEXT("-a<[VALUE]> : enforce (minimum) room-size") << ACE_TEXT(" [") << (MAP_GENERATOR_DEF_MIN_ROOMSIZE != 0);
  if (MAP_GENERATOR_DEF_MIN_ROOMSIZE != 0)
    std::cout << ACE_TEXT(":") << MAP_GENERATOR_DEF_MIN_ROOMSIZE;
  std::cout << ACE_TEXT("; 0:off]") << std::endl;
  std::cout << ACE_TEXT("-c          : corridor(s)") << ACE_TEXT(" [") << MAP_GENERATOR_DEF_CORRIDORS << ACE_TEXT("]") << std::endl;
  std::cout << ACE_TEXT("-d<[VALUE]> : enforce maximum #doors/room") << ACE_TEXT(" [") << (MAP_GENERATOR_DEF_MAX_NUMDOORS_PER_ROOM != 0);
  if (MAP_GENERATOR_DEF_MAX_NUMDOORS_PER_ROOM != 0)
    std::cout << ACE_TEXT(":") << MAP_GENERATOR_DEF_MAX_NUMDOORS_PER_ROOM;
  std::cout << ACE_TEXT("; 0:off]") << std::endl;
  std::cout << ACE_TEXT("-m          : maximize room-size(s)") << ACE_TEXT(" [") << MAP_GENERATOR_DEF_MAXIMIZE_ROOMSIZE << ACE_TEXT("]") << std::endl;
  std::cout << ACE_TEXT("-p          : (random) start position") << ACE_TEXT(" [") << MAP_GENERATOR_DEF_RANDOM_START_POSITION << ACE_TEXT("]") << std::endl;
  std::cout << ACE_TEXT("-r [VALUE]  : #areas") << ACE_TEXT(" [") << MAP_GENERATOR_DEF_NUM_AREAS << ACE_TEXT("]") << std::endl;
  std::cout << ACE_TEXT("-s          : square room(s)") << ACE_TEXT(" [") << MAP_GENERATOR_DEF_SQUARE_ROOMS << ACE_TEXT("]") << std::endl;
  std::cout << ACE_TEXT("-t          : trace information") << std::endl;
  std::cout << ACE_TEXT("-v          : print version information and exit") << std::endl;
  std::cout << ACE_TEXT("-x [VALUE]  : #columns") << ACE_TEXT(" [") << MAP_GENERATOR_DEF_DIMENSION_X << ACE_TEXT("]") << std::endl;
  std::cout << ACE_TEXT("-y [VALUE]  : #rows") << ACE_TEXT(" [") << MAP_GENERATOR_DEF_DIMENSION_Y << ACE_TEXT("]") << std::endl;
} // end print_usage

const bool
process_arguments(const int argc_in,
                  ACE_TCHAR* argv_in[], // cannot be const...
                  unsigned long& minRoomSize_out,
                  bool& corridors_out,
                  unsigned long& maxNumDoorsPerRoom_out,
                  bool& maximizeRoomSize_out,
                  bool& randomStartPosition_out,
                  unsigned long& numAreas_out,
                  bool& squareRooms_out,
                  bool& traceInformation_out,
                  bool& printVersionAndExit_out,
                  unsigned long& dimensionX_out,
                  unsigned long& dimensionY_out)
{
  RPG_TRACE(ACE_TEXT("::process_arguments"));

  // init results
  minRoomSize_out = MAP_GENERATOR_DEF_MIN_ROOMSIZE;
  corridors_out = MAP_GENERATOR_DEF_CORRIDORS;
  maxNumDoorsPerRoom_out = MAP_GENERATOR_DEF_MAX_NUMDOORS_PER_ROOM;
  maximizeRoomSize_out = MAP_GENERATOR_DEF_MAXIMIZE_ROOMSIZE;
  randomStartPosition_out = MAP_GENERATOR_DEF_RANDOM_START_POSITION;
  numAreas_out = MAP_GENERATOR_DEF_NUM_AREAS;
  squareRooms_out = MAP_GENERATOR_DEF_SQUARE_ROOMS;
  traceInformation_out = false;
  printVersionAndExit_out = false;
  dimensionX_out = MAP_GENERATOR_DEF_DIMENSION_X;
  dimensionY_out = MAP_GENERATOR_DEF_DIMENSION_Y;

  ACE_Get_Opt argumentParser(argc_in,
                             argv_in,
                             ACE_TEXT("a::cd::mpr:stvx:y:"));

  int option = 0;
  std::stringstream converter;
  while ((option = argumentParser()) != EOF)
  {
    switch (option)
    {
      case 'a':
      {
        converter.clear();
        converter.str(ACE_TEXT_ALWAYS_CHAR(""));
        converter << argumentParser.opt_arg();
        converter >> minRoomSize_out;

        break;
      }
      case 'c':
      {
        corridors_out = true;

        break;
      }
      case 'd':
      {
        int temp = 0;
        converter.clear();
        converter.str(ACE_TEXT_ALWAYS_CHAR(""));
        converter << argumentParser.opt_arg();
        converter >> temp;
        if (temp == -1)
          maxNumDoorsPerRoom_out = std::numeric_limits<unsigned long>::max();

        break;
      }
      case 'm':
      {
        maximizeRoomSize_out = true;

        break;
      }
      case 'p':
      {
        randomStartPosition_out = true;

        break;
      }
      case 'r':
      {
        converter.clear();
        converter.str(ACE_TEXT_ALWAYS_CHAR(""));
        converter << argumentParser.opt_arg();
        converter >> numAreas_out;

        break;
      }
      case 's':
      {
        squareRooms_out = true;

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
      case 'x':
      {
        converter.clear();
        converter.str(ACE_TEXT_ALWAYS_CHAR(""));
        converter << argumentParser.opt_arg();
        converter >> dimensionX_out;

        break;
      }
      case 'y':
      {
        converter.clear();
        converter.str(ACE_TEXT_ALWAYS_CHAR(""));
        converter << argumentParser.opt_arg();
        converter >> dimensionY_out;

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

void
do_work(const unsigned long& minRoomSize_in,
        const bool& doors_in,
        const bool& corridors_in,
        const unsigned long& maxDoorsPerRoom_in,
        const bool& maximizeArea_in,
        const bool& randomStartPosition_in,
        const unsigned long& numAreas_in,
        const bool& wantSquareRooms_in,
        const unsigned long& dimensionX_in,
        const unsigned long& dimensionY_in)
{
  RPG_TRACE(ACE_TEXT("::do_work"));

  // step1: init: random seed, string conversion facilities, ...
  RPG_Dice::init();
  RPG_Dice_Common_Tools::initStringConversionTables();

  // step2: generate random dungeon map
  RPG_Map_Positions_t seedPoints;
  RPG_Map_FloorPlan_t floorPlan;
  RPG_Map_Common_Tools::createFloorPlan(dimensionX_in,
                                        dimensionY_in,
                                        numAreas_in,
                                        wantSquareRooms_in,
                                        maximizeArea_in,
                                        minRoomSize_in,
                                        doors_in,
                                        corridors_in,
                                        true, // doors fill a position
                                        maxDoorsPerRoom_in,
                                        seedPoints,
                                        floorPlan);

  // step3: generate (pseudo-random) start position ?
  RPG_Map_Position_t startingPosition = std::make_pair(0, 0);
  if (randomStartPosition_in)
  {
    RPG_Dice_RollResult_t result_x, result_y;
    do
    {
      result_x.clear(); result_y.clear();
      RPG_Dice::generateRandomNumbers(dimensionX_in,
                                      1,
                                      result_x);
      RPG_Dice::generateRandomNumbers(dimensionY_in,
                                      1,
                                      result_y);
      startingPosition = std::make_pair(result_x[0] - 1,
                                        result_y[0] - 1);

      // sanity check: is a "floor" square ?
      if (RPG_Map_Common_Tools::isFloor(startingPosition, floorPlan))
        break;
    } while (true); // try again
  } // end IF

  // step4: display the result
  RPG_Map_Position_t current_position;
  RPG_Map_Door_t current_position_door;
  bool is_starting_position = false;
  bool is_seed = false;
  for (unsigned long y = 0;
       y < floorPlan.size_y;
       y++)
  {
    for (unsigned long x = 0;
         x < floorPlan.size_x;
         x++)
    {
      current_position = std::make_pair(x, y);
      current_position_door.position = current_position;
      is_starting_position = (current_position == startingPosition);
      is_seed = seedPoints.find(current_position) != seedPoints.end();

      // unmapped, floor, wall, or door ?
      // *TODO*: cannot draw seed points that are not "unmapped"/"floor" without
      // losing essential information...
      if (floorPlan.unmapped.find(current_position) != floorPlan.unmapped.end())
        std::cout << (is_seed ? ACE_TEXT("@") : ACE_TEXT(" ")); // unmapped
      else if (floorPlan.walls.find(current_position) != floorPlan.walls.end())
        std::cout << ACE_TEXT("#"); // wall
      else if (floorPlan.doors.find(current_position_door) != floorPlan.doors.end())
        std::cout << ACE_TEXT("="); // door
      else
        std::cout << (is_starting_position ? ACE_TEXT("X")
                                           : (is_seed ? ACE_TEXT("@")
                                                      : ACE_TEXT("."))); // floor
    } // end FOR
    std::cout << std::endl;
  } // end FOR

  ACE_DEBUG((LM_DEBUG,
             ACE_TEXT("finished working...\n")));
} // end do_work

void
do_printVersion(const std::string& programName_in)
{
  RPG_TRACE(ACE_TEXT("::do_printVersion"));

  std::cout << programName_in
      << ACE_TEXT(" : ")
      << RPG_VERSION
      << std::endl;

  // create version string...
  // *NOTE*: cannot use ACE_VERSION, as it doesn't contain the (potential) beta version
  // number... We need this, as the library soname is compared to this string.
  std::ostringstream version_number;
  if (version_number << ACE::major_version())
  {
    version_number << ACE_TEXT(".");
  } // end IF
  else
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to convert: \"%m\", aborting\n")));

    return;
  } // end ELSE
  if (version_number << ACE::minor_version())
  {
    version_number << ACE_TEXT(".");
    if (version_number << ACE::beta_version())
    {

    } // end IF
    else
    {
      ACE_DEBUG((LM_ERROR,
                 ACE_TEXT("failed to convert: \"%m\", aborting\n")));

      return;
    } // end ELSE
  } // end IF
  else
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to convert: \"%m\", aborting\n")));

    return;
  } // end ELSE
  std::cout << ACE_TEXT("ACE: ") << version_number.str() << std::endl;
//   std::cout << "ACE: "
//             << ACE_VERSION
//             << std::endl;
}

int
ACE_TMAIN(int argc,
          ACE_TCHAR* argv[])
{
  RPG_TRACE(ACE_TEXT("::main"));

  // step1: init
  // step1a set defaults
  unsigned long minRoomSize        = MAP_GENERATOR_DEF_MIN_ROOMSIZE;
  bool doors                       = MAP_GENERATOR_DEF_DOORS;
  bool corridors                   = MAP_GENERATOR_DEF_CORRIDORS;
  unsigned long maxNumDoorsPerRoom = MAP_GENERATOR_DEF_MAX_NUMDOORS_PER_ROOM;
  bool maximizeRoomSize            = MAP_GENERATOR_DEF_MAXIMIZE_ROOMSIZE;
  bool randomStartPosition         = MAP_GENERATOR_DEF_RANDOM_START_POSITION;
  unsigned long numAreas           = MAP_GENERATOR_DEF_NUM_AREAS;
  bool squareRooms                 = MAP_GENERATOR_DEF_SQUARE_ROOMS;
  bool traceInformation            = false;
  bool printVersionAndExit         = false;
  unsigned long dimension_X        = MAP_GENERATOR_DEF_DIMENSION_X;
  unsigned long dimension_Y        = MAP_GENERATOR_DEF_DIMENSION_Y;

  // step1ba: parse/process/validate configuration
  if (!(process_arguments(argc,
                          argv,
                          minRoomSize,
                          corridors,
                          maxNumDoorsPerRoom,
                          maximizeRoomSize,
                          randomStartPosition,
                          numAreas,
                          squareRooms,
                          traceInformation,
                          printVersionAndExit,
                          dimension_X,
                          dimension_Y)))
  {
    // make 'em learn...
    print_usage(std::string(ACE::basename(argv[0])));

    return EXIT_FAILURE;
  } // end IF

  // step1bb: validate arguments
  if ((numAreas == 0) ||
      (dimension_X == 0) ||
      (dimension_Y == 0) ||
      (maxNumDoorsPerRoom == 1) || // cannot enforce this (just think about it !)
      (corridors && !doors)) // cannot have corridors without doors...
  {
    ACE_DEBUG((LM_DEBUG,
               ACE_TEXT("invalid argument(s), aborting\n")));

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
  do_work(minRoomSize,
          doors,
          corridors,
          maxNumDoorsPerRoom,
          maximizeRoomSize,
          randomStartPosition,
          numAreas,
          squareRooms,
          dimension_X,
          dimension_Y);

  timer.stop();

  // debug info
  std::string working_time_string;
  ACE_Time_Value working_time;
  timer.elapsed_time(working_time);
  RPG_Common_Tools::period2String(working_time,
                                  working_time_string);

  ACE_DEBUG((LM_DEBUG,
             ACE_TEXT("total working time (h:m:s.us): \"%s\"...\n"),
             working_time_string.c_str()));

  return EXIT_SUCCESS;
} // end main
