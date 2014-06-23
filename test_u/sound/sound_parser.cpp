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
#include "stdafx.h"

// *NOTE*: need this to import correct VERSION !
#ifdef HAVE_CONFIG_H
#include "rpg_config.h"
#endif

#include "rpg_sound_defines.h"
#include "rpg_sound_common.h"
#include "rpg_sound_dictionary.h"
#include "rpg_sound_common_tools.h"

#include "rpg_dice.h"
#include "rpg_dice_common_tools.h"

#include "rpg_common_macros.h"
#include "rpg_common_defines.h"
#include "rpg_common_tools.h"
#include "rpg_common_file_tools.h"
#include "rpg_common_XML_tools.h"

#include <SDL.h>

#include <ace/ACE.h>
#include <ace/Log_Msg.h>
#include <ace/Get_Opt.h>
#include <ace/High_Res_Timer.h>

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

#define SOUNDPARSER_DEF_PLAY_RANDOM_SOUNDS false
#define SDL_TIMEREVENT                     SDL_USEREVENT

//static SDL_CD* cdrom = NULL;

Uint32
timer_SDL_cb(Uint32 interval_in,
             void* argument_in)
{
  RPG_TRACE(ACE_TEXT("::timer_SDL_cb"));

  // create an SDL timer event
  SDL_Event sdl_event;
  sdl_event.type = SDL_TIMEREVENT;
  sdl_event.user.data1 = argument_in;

  // push it onto the event queue
  if (SDL_PushEvent(&sdl_event))
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to SDL_PushEvent(): \"%s\", continuing\n"),
               SDL_GetError()));
  } // end IF

  // one-shot timer --> cancel
  return 0;
}

// wait for an input event; stop after timeout_in second(s) (0: wait forever)
void
do_SDL_waitForInput(const unsigned int& timeout_in)
{
  RPG_TRACE(ACE_TEXT("::do_SDL_waitForInput"));

  SDL_TimerID timer = NULL;
  if (timeout_in)
    timer = SDL_AddTimer((timeout_in * 1000), // interval (ms)
                          timer_SDL_cb,       // timeout callback
                          NULL);              // callback argument

  // loop until something interesting happens
  SDL_Event sdl_event;
  do
  {
    if (SDL_WaitEvent(&sdl_event) != 1)
    {
      ACE_DEBUG((LM_ERROR,
                 ACE_TEXT("failed to SDL_WaitEvent(): \"%s\", aborting\n"),
                 SDL_GetError()));

      // what else can we do ?
      break;
    } // end IF
    if (sdl_event.type == SDL_KEYDOWN ||
        sdl_event.type == SDL_MOUSEBUTTONDOWN ||
        sdl_event.type == SDL_TIMEREVENT)
      break;
  } while (true);

  if (timeout_in)
    if (!SDL_RemoveTimer(timer))
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to SDL_RemoveTimer(): \"%s\", continuing\n"),
               SDL_GetError()));
  } // end IF
}

void
print_usage(const std::string& programName_in)
{
  RPG_TRACE(ACE_TEXT("::print_usage"));

  // enable verbatim boolean output
  std::cout.setf(ios::boolalpha);

  std::string config_path = RPG_Common_File_Tools::getWorkingDirectory();
  std::string data_path = RPG_Common_File_Tools::getWorkingDirectory();
#ifdef BASEDIR
  config_path = RPG_Common_File_Tools::getConfigurationDataDirectory(ACE_TEXT_ALWAYS_CHAR(BASEDIR),
                                                                     true);
  data_path = RPG_Common_File_Tools::getConfigurationDataDirectory(ACE_TEXT_ALWAYS_CHAR(BASEDIR),
                                                                   false);
#endif // #ifdef BASEDIR

  std::cout << ACE_TEXT("usage: ") << programName_in << ACE_TEXT(" [OPTIONS]") << std::endl << std::endl;
  std::cout << ACE_TEXT("currently available options:") << std::endl;
  std::cout << ACE_TEXT("-d       : dump dictionary") << std::endl;
  std::string path = data_path;
  path += ACE_DIRECTORY_SEPARATOR_CHAR_A;
#if defined(_DEBUG) && !defined(DEBUG_RELEASE)
  path += ACE_TEXT_ALWAYS_CHAR("sound");
  path += ACE_DIRECTORY_SEPARATOR_CHAR_A;
  path += ACE_TEXT_ALWAYS_CHAR(RPG_COMMON_DATA_SUB);
#else
  path += ACE_TEXT_ALWAYS_CHAR(RPG_SOUND_DATA_SUB);
#endif // #if (defined _DEBUG) || (defined DEBUG_RELEASE)
  std::cout << ACE_TEXT("-f [DIR] : data directory") << ACE_TEXT(" [\"") << path.c_str() << ACE_TEXT("\"]") << std::endl;
  std::cout << ACE_TEXT("-r       : play random sounds") << ACE_TEXT(" [") << SOUNDPARSER_DEF_PLAY_RANDOM_SOUNDS << ACE_TEXT("]") << std::endl;
  path = config_path;
  path += ACE_DIRECTORY_SEPARATOR_CHAR_A;
#if defined(_DEBUG) && !defined(DEBUG_RELEASE)
  path += ACE_TEXT_ALWAYS_CHAR("sound");
  path += ACE_DIRECTORY_SEPARATOR_CHAR_A;
#endif // #if (defined _DEBUG) || (defined DEBUG_RELEASE)
  path += ACE_TEXT_ALWAYS_CHAR(RPG_SOUND_DICTIONARY_FILE);
  std::cout << ACE_TEXT("-s [FILE]: sound dictionary (*.xml)") << ACE_TEXT(" [\"") << path.c_str() << ACE_TEXT("\"]") << std::endl;
  std::cout << ACE_TEXT("-t       : trace information") << std::endl;
  std::cout << ACE_TEXT("-v       : print version information and exit") << std::endl;
  std::cout << ACE_TEXT("-x       : do NOT validate XML") << std::endl;
} // end print_usage

bool
process_arguments(const int argc_in,
                  ACE_TCHAR* argv_in[], // cannot be const...
                  bool& dumpDictionary_out,
                  std::string& directory_out,
                  bool& playRandomSounds_out,
                  std::string& filename_out,
                  bool& traceInformation_out,
                  bool& printVersionAndExit_out,
                  bool& validateXML_out)
{
  RPG_TRACE(ACE_TEXT("::process_arguments"));

  // init results
  std::string config_path = RPG_Common_File_Tools::getWorkingDirectory();
  std::string data_path = RPG_Common_File_Tools::getWorkingDirectory();
#ifdef BASEDIR
  config_path = RPG_Common_File_Tools::getConfigurationDataDirectory(ACE_TEXT_ALWAYS_CHAR(BASEDIR),
                                                                     true);
  data_path = RPG_Common_File_Tools::getConfigurationDataDirectory(ACE_TEXT_ALWAYS_CHAR(BASEDIR),
                                                                   false);
#endif // #ifdef BASEDIR

  dumpDictionary_out = false;

  directory_out = data_path;
  directory_out += ACE_DIRECTORY_SEPARATOR_CHAR_A;
#if defined(_DEBUG) && !defined(DEBUG_RELEASE)
  directory_out += ACE_TEXT_ALWAYS_CHAR("sound");
  directory_out += ACE_DIRECTORY_SEPARATOR_CHAR_A;
  directory_out += ACE_TEXT_ALWAYS_CHAR(RPG_COMMON_DATA_SUB);
#else
  directory_out += ACE_TEXT_ALWAYS_CHAR(RPG_SOUND_DATA_SUB);
#endif // #if (defined _DEBUG) || (defined DEBUG_RELEASE)

  playRandomSounds_out = SOUNDPARSER_DEF_PLAY_RANDOM_SOUNDS;

  filename_out = config_path;
  filename_out += ACE_DIRECTORY_SEPARATOR_CHAR_A;
#if defined(_DEBUG) && !defined(DEBUG_RELEASE)
  filename_out += ACE_TEXT_ALWAYS_CHAR("sound");
  filename_out += ACE_DIRECTORY_SEPARATOR_CHAR_A;
#endif // #if (defined _DEBUG) || (defined DEBUG_RELEASE)
  filename_out += ACE_TEXT_ALWAYS_CHAR(RPG_SOUND_DICTIONARY_FILE);

  traceInformation_out = false;
  printVersionAndExit_out = false;
  validateXML_out = true;

  ACE_Get_Opt argumentParser(argc_in,
                             argv_in,
                             ACE_TEXT("df:rs:tvx"));

  int option = 0;
  while ((option = argumentParser()) != EOF)
  {
    switch (option)
    {
      case 'd':
      {
        dumpDictionary_out = true;

        break;
      }
      case 'f':
      {
        directory_out = argumentParser.opt_arg();

        break;
      }
      case 'r':
      {
        playRandomSounds_out = true;

        break;
      }
      case 's':
      {
        filename_out = argumentParser.opt_arg();

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
        validateXML_out = false;

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
do_work(const bool& dumpDictionary_in,
        const std::string& path_in,
        const bool& playRandomSounds_in,
				const std::string& schemaRepository_in,
        const std::string& dictionary_in,
        const bool& validateXML_in)
{
  RPG_TRACE(ACE_TEXT("::do_work"));

  // step0: init: random seed, string conversion facilities, ...
  RPG_Dice::init();
  RPG_Dice_Common_Tools::initStringConversionTables();

  // step1: init: sound directory, cache, ...
  RPG_Sound_SDLConfiguration_t sound_config;
  sound_config.frequency = RPG_SOUND_AUDIO_DEF_FREQUENCY;
  sound_config.format = RPG_SOUND_AUDIO_DEF_FORMAT;
  sound_config.channels = RPG_SOUND_AUDIO_DEF_CHANNELS;
  sound_config.chunksize = RPG_SOUND_AUDIO_DEF_CHUNKSIZE;
  if (!RPG_Sound_Common_Tools::init(sound_config,
                                    path_in,
                                    RPG_SOUND_AMBIENT_DEF_USE_CD,
                                    RPG_SOUND_DEF_CACHESIZE,
                                    false))
	{
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to RPG_Sound_Common_Tools::init(), returning\n")));

    return;
	} // end IF

  // step2: init sound dictionary
	RPG_Common_XML_Tools::init(schemaRepository_in);
  try
  {
    RPG_SOUND_DICTIONARY_SINGLETON::instance()->init(dictionary_in,
                                                     validateXML_in);
  }
  catch (...)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("caught exception in RPG_Sound_Dictionary::init(), returning\n")));

    return;
  }

  // step3: dump sound descriptions
  if (dumpDictionary_in)
    RPG_SOUND_DICTIONARY_SINGLETON::instance()->dump();

  if (!playRandomSounds_in)
	{
		// clean up
		RPG_Common_XML_Tools::fini();

    return;
	} // end IF

  // step4: play (random) sounds...
  RPG_Sound_Event sound_event = RPG_SOUND_EVENT_INVALID;
  RPG_Dice_RollResult_t result;
  int current_channel = -1;
	ACE_Time_Value duration = ACE_Time_Value::zero;
  do
  {
    result.clear();
    RPG_Dice::generateRandomNumbers(RPG_SOUND_EVENT_MAX,
                                    1,
                                    result);
    sound_event = static_cast<RPG_Sound_Event>((result.front() - 1));
    ACE_DEBUG((LM_DEBUG,
               ACE_TEXT("playing event sound \"%s\"...\n"),
               RPG_Sound_EventHelper::RPG_Sound_EventToString(sound_event).c_str()));

    current_channel = RPG_Sound_Common_Tools::play(sound_event, duration);
    if (current_channel == -1)
    {
      ACE_DEBUG((LM_ERROR,
                 ACE_TEXT("failed to play event sound \"%s\", aborting\n"),
                 RPG_Sound_EventHelper::RPG_Sound_EventToString(sound_event).c_str()));

      break;
    } // end IF

    // stop after some time (5 seconds)
    ACE_OS::sleep(ACE_Time_Value(5, 0));
    if (RPG_Sound_Common_Tools::isPlaying(current_channel))
      RPG_Sound_Common_Tools::stop(current_channel);
  } while (true);

  // *NOTE*: it seems you cannot SDL_WaitEvent() if there is no window... :-(
//   do_SDL_waitForInput(10);

  // clean up
	RPG_Common_XML_Tools::fini();

  ACE_DEBUG((LM_DEBUG,
             ACE_TEXT("finished working...\n")));
} // end do_work

void
do_printVersion(const std::string& programName_in)
{
  RPG_TRACE(ACE_TEXT("::do_printVersion"));

  std::cout << programName_in
#ifdef HAVE_CONFIG_H
            << ACE_TEXT(" : ")
            << RPG_VERSION
#endif
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
               ACE_TEXT("failed to convert: \"%m\", returning\n")));

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
                 ACE_TEXT("failed to convert: \"%m\", returning\n")));

      return;
    } // end ELSE
  } // end IF
  else
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to convert: \"%m\", returning\n")));

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

//  // step0: init ACE
//  // *PORTABILITY*: on Windows, we need to init ACE...
//#if defined (ACE_WIN32) || defined (ACE_WIN64)
//  if (ACE::init() == -1)
//  {
//    ACE_DEBUG((LM_ERROR,
//               ACE_TEXT("failed to ACE::init(): \"%m\", aborting\n")));
//
//    return EXIT_FAILURE;
//  } // end IF
//#endif

  // step1: init
  // step1a set defaults
  std::string config_path = RPG_Common_File_Tools::getWorkingDirectory();
  std::string data_path = RPG_Common_File_Tools::getWorkingDirectory();
#ifdef BASEDIR
  config_path = RPG_Common_File_Tools::getConfigurationDataDirectory(ACE_TEXT_ALWAYS_CHAR(BASEDIR),
                                                              true);
  data_path = RPG_Common_File_Tools::getConfigurationDataDirectory(ACE_TEXT_ALWAYS_CHAR(BASEDIR),
                                                            false);
#endif // #ifdef BASEDIR

  bool dumpDictionary = false;

  std::string soundDirectory = data_path;
  soundDirectory += ACE_DIRECTORY_SEPARATOR_CHAR_A;
#if defined(_DEBUG) && !defined(DEBUG_RELEASE)
  soundDirectory += ACE_TEXT_ALWAYS_CHAR("sound");
  soundDirectory += ACE_DIRECTORY_SEPARATOR_CHAR_A;
  soundDirectory += ACE_TEXT_ALWAYS_CHAR(RPG_COMMON_DATA_SUB);
#else
  soundDirectory += ACE_TEXT_ALWAYS_CHAR(RPG_SOUND_DATA_SUB);
#endif // #if (defined _DEBUG) || (defined DEBUG_RELEASE)

  bool playRandomSounds = SOUNDPARSER_DEF_PLAY_RANDOM_SOUNDS;

  std::string schemaRepository = config_path;
#if defined(_DEBUG) && !defined(DEBUG_RELEASE)
  schemaRepository += ACE_DIRECTORY_SEPARATOR_CHAR_A;
  schemaRepository += ACE_TEXT_ALWAYS_CHAR("engine");
#endif

  std::string filename = config_path;
  filename += ACE_DIRECTORY_SEPARATOR_CHAR_A;
#if defined(_DEBUG) && !defined(DEBUG_RELEASE)
  filename += ACE_TEXT_ALWAYS_CHAR("sound");
  filename += ACE_DIRECTORY_SEPARATOR_CHAR_A;
#endif // #if (defined _DEBUG) || (defined DEBUG_RELEASE)
  filename += ACE_TEXT_ALWAYS_CHAR(RPG_SOUND_DICTIONARY_FILE);

  bool traceInformation = false;
  bool printVersionAndExit = false;
  bool validateXML = true;

//  RPG_Sound_SDLConfig_t audio_config;
//  audio_config.frequency = RPG_SOUND_DEF_AUDIO_FREQUENCY;
//  audio_config.format    = RPG_SOUND_DEF_AUDIO_FORMAT;
//  audio_config.channels  = RPG_SOUND_DEF_AUDIO_CHANNELS;
//  audio_config.chunksize = RPG_SOUND_DEF_AUDIO_CHUNKSIZE;

  // step1b: parse/process/validate configuration
  if (!process_arguments(argc,
                         argv,
                         dumpDictionary,
                         soundDirectory,
                         playRandomSounds,
                         filename,
                         traceInformation,
                         printVersionAndExit,
                         validateXML))
  {
    // make 'em learn...
    print_usage(std::string(ACE::basename(argv[0])));

//    // *PORTABILITY*: on Windows, we must fini ACE...
//#if defined (ACE_WIN32) || defined (ACE_WIN64)
//    if (ACE::fini() == -1)
//      ACE_DEBUG((LM_ERROR,
//                 ACE_TEXT("failed to ACE::fini(): \"%m\", continuing\n")));
//#endif

    return EXIT_FAILURE;
  } // end IF

  // step1b: validate arguments
  if ((playRandomSounds && !RPG_Common_File_Tools::isDirectory(soundDirectory)) ||
      !RPG_Common_File_Tools::isReadable(filename))
  {
    ACE_DEBUG((LM_DEBUG,
               ACE_TEXT("invalid argument, aborting\n")));

    // make 'em learn...
    print_usage(std::string(ACE::basename(argv[0])));

//    // *PORTABILITY*: on Windows, we must fini ACE...
//#if defined (ACE_WIN32) || defined (ACE_WIN64)
//    if (ACE::fini() == -1)
//      ACE_DEBUG((LM_ERROR,
//                 ACE_TEXT("failed to ACE::fini(): \"%m\", continuing\n")));
//#endif

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

  // step2: init SDL
  if (SDL_Init(SDL_INIT_TIMER |
               SDL_INIT_AUDIO |
               SDL_INIT_CDROM |
               SDL_INIT_NOPARACHUTE) == -1) // "...Prevents SDL from catching fatal signals..."
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to SDL_Init(): \"%s\", aborting\n"),
               SDL_GetError()));

//    // *PORTABILITY*: on Windows, we must fini ACE...
//#if defined (ACE_WIN32) || defined (ACE_WIN64)
//    if (ACE::fini() == -1)
//      ACE_DEBUG((LM_ERROR,
//                 ACE_TEXT("failed to ACE::fini(): \"%m\", continuing\n")));
//#endif

    return EXIT_FAILURE;
  } // end IF
  // ***** keyboard setup *****
  // enable Unicode translation
  SDL_EnableUNICODE(1);
  // enable key repeat
  SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY,
                      SDL_DEFAULT_REPEAT_INTERVAL);
//   // ignore keyboard events
//   SDL_EventState(SDL_KEYDOWN, SDL_IGNORE);
//   SDL_EventState(SDL_KEYUP, SDL_IGNORE);

//   // SDL event filter (filter mouse motion events and the like)
//   SDL_SetEventFilter(event_filter_SDL_cb);

  // step3: do actual work
  ACE_High_Res_Timer timer;
  timer.start();
  do_work(dumpDictionary,
          soundDirectory,
          playRandomSounds,
					schemaRepository,
          filename,
          validateXML);
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

  // step4a: fini SDL
  SDL_Quit();

//  // *PORTABILITY*: on Windows, we must fini ACE...
//#if defined (ACE_WIN32) || defined (ACE_WIN64)
//  if (ACE::fini() == -1)
//  {
//    ACE_DEBUG((LM_ERROR,
//               ACE_TEXT("failed to ACE::fini(): \"%m\", aborting\n")));
//
//    return EXIT_FAILURE;
//  } // end IF
//#endif

  return EXIT_SUCCESS;
} // end main
