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

// *NOTE*: need this to import correct PACKAGE_STRING/VERSION/... !
#ifdef HAVE_CONFIG_H
#include <rpg_config.h>
#endif

#include "SDL_gui_defines.h"
#include "SDL_gui_mainwindow.h"
#include "SDL_gui_levelwindow.h"

#include <rpg_map_defines.h>
#include <rpg_map_common_tools.h>

#include <rpg_graphics_defines.h>
#include <rpg_graphics_dictionary.h>
#include <rpg_graphics_surface.h>
#include <rpg_graphics_cursor_manager.h>
#include <rpg_graphics_common_tools.h>
#include <rpg_graphics_SDL_tools.h>

#include <rpg_dice.h>
#include <rpg_dice_common_tools.h>

#include <rpg_common_macros.h>
#include <rpg_common_defines.h>
#include <rpg_common_tools.h>
#include <rpg_common_file_tools.h>

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

#include <ace/ACE.h>
#include <ace/Log_Msg.h>
#include <ace/Get_Opt.h>
#include <ace/High_Res_Timer.h>
#include <ace/Synch.h>

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

enum userMode_t
{
  MODE_RANDOM_IMAGES = 0,
  MODE_LEVEL_MAP,
  //
  MODE_INVALID,
  MODE_MAX
};

struct map_config_t
{
  unsigned long min_room_size; // 0: don't care
  bool          doors;
  bool          corridors;
  unsigned long max_num_doors_per_room;
  bool          maximize_rooms;
  unsigned long num_areas;
  bool          square_rooms;
  unsigned long map_size_x;
  unsigned long map_size_y;
};

// *NOTE* types as used by SDL
struct SDL_video_config_t
{
  int    screen_width;
  int    screen_height;
  int    screen_colordepth; // bits/pixel
//   Uint32 screen_flags;
  bool   fullScreen;
  bool   doubleBuffer;
};

static SDL_Surface*     screen     = NULL;
static ACE_Thread_Mutex hover_lock;
static unsigned long    hover_time = 0;

const bool
do_initVideo(const std::string& graphicsDirectory_in,
             const SDL_video_config_t& config_in)
{
  RPG_TRACE(ACE_TEXT("::do_initVideo"));

  // init SDL Video

  // ***** window/screen setup *****
  // set window caption
  SDL_WM_SetCaption(ACE_TEXT_ALWAYS_CHAR(RPG_PACKAGE_STRING),  // window caption
                    ACE_TEXT_ALWAYS_CHAR(RPG_PACKAGE_STRING)); // icon caption
  // set window icon
  RPG_Graphics_GraphicTypeUnion type;
  type.discriminator = RPG_Graphics_GraphicTypeUnion::IMAGE;
  type.image = IMAGE_WM_ICON;
  RPG_Graphics_t icon_graphic = RPG_GRAPHICS_DICTIONARY_SINGLETON::instance()->get(type);
  ACE_ASSERT(icon_graphic.type.image == IMAGE_WM_ICON);
  std::string path = graphicsDirectory_in;
  path += ACE_DIRECTORY_SEPARATOR_STR;
  path += RPG_GRAPHICS_TILE_DEF_IMAGES_SUB;
  path += ACE_DIRECTORY_SEPARATOR_STR;
  path += icon_graphic.file;
  SDL_Surface* icon_image = NULL;
  icon_image = RPG_Graphics_Surface::load(path,   // file
                                          false); // DON'T convert to display format (no screen yet !)
  if (!icon_image)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to RPG_Graphics_Surface::load(\"%s\"), aborting\n"),
               path.c_str()));

    return false;
  } // end IF
  SDL_WM_SetIcon(icon_image, // surface
                 NULL);      // mask (--> everything)
  // enable cursor
  SDL_ShowCursor(SDL_ENABLE);

  screen = RPG_Graphics_SDL_Tools::initScreen(config_in.screen_width,
                                              config_in.screen_height,
                                              config_in.screen_colordepth,
                                              config_in.doubleBuffer,
                                              config_in.fullScreen);

  return (screen != NULL);
}

Uint32
event_timer_SDL_cb(Uint32 interval_in,
                   void* argument_in)
{
  RPG_TRACE(ACE_TEXT("::event_timer_SDL_cb"));

  unsigned long* current_hovertime_p = static_cast<unsigned long*> (argument_in);
  ACE_ASSERT(current_hovertime_p);

  // synch access
  {
    ACE_Guard<ACE_Thread_Mutex> aGuard(hover_lock);

    *current_hovertime_p += interval_in;
    if (*current_hovertime_p > RPG_GRAPHICS_WINDOW_HOTSPOT_HOVER_DELAY)
    {
      // mouse is hovering --> trigger an event
      SDL_Event event;
      event.type = RPG_GRAPHICS_SDL_HOVEREVENT;
      event.user.code = static_cast<int> (*current_hovertime_p);

      if (SDL_PushEvent(&event))
      {
        ACE_DEBUG((LM_ERROR,
                  ACE_TEXT("failed to SDL_PushEvent(): \"%s\", continuing\n"),
                  SDL_GetError()));
      } // end IF
    } // end IF
  } // end lock scope

  // re-schedule
  return interval_in;
}

Uint32
input_timer_SDL_cb(Uint32 interval_in,
                   void* argument_in)
{
  RPG_TRACE(ACE_TEXT("::input_timer_SDL_cb"));

  // create a timer event
  SDL_Event event;
  event.type = SDL_GUI_SDL_TIMEREVENT;
  event.user.data1 = argument_in;

  // push it onto the event queue
  if (SDL_PushEvent(&event))
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
do_SDL_waitForInput(const unsigned long& timeout_in,
                    SDL_Event& event_out)
{
  RPG_TRACE(ACE_TEXT("::do_SDL_waitForInput"));

  SDL_TimerID timer = NULL;
  if (timeout_in)
    timer = SDL_AddTimer((timeout_in * 1000), // interval (ms)
                         input_timer_SDL_cb,  // timeout callback
                         NULL);               // callback argument
  ACE_ASSERT(timer);
  if (!timer)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to SDL_AddTimer(%u): \"%s\", aborting\n"),
               (timeout_in * 1000),
               SDL_GetError()));

    return;
  } // end IF

  // loop until something interesting happens
  do
  {
    if (SDL_WaitEvent(&event_out) != 1)
    {
      ACE_DEBUG((LM_ERROR,
                 ACE_TEXT("failed to SDL_WaitEvent(): \"%s\", aborting\n"),
                 SDL_GetError()));

      // what else can we do ?
      break;
    } // end IF
    if (event_out.type == SDL_KEYDOWN ||
        event_out.type == SDL_KEYUP ||
        event_out.type == SDL_MOUSEMOTION ||
        event_out.type == SDL_MOUSEBUTTONDOWN ||
        event_out.type == SDL_QUIT ||
        event_out.type == SDL_GUI_SDL_TIMEREVENT)
      break;
  } while (true);

  // clean up
  if (timeout_in &&
      (event_out.type != SDL_GUI_SDL_TIMEREVENT))
    if (!SDL_RemoveTimer(timer))
      ACE_DEBUG((LM_ERROR,
                 ACE_TEXT("failed to SDL_RemoveTimer(): \"%s\", continuing\n"),
                 SDL_GetError()));
}

void
print_usage(const std::string& programName_in)
{
  RPG_TRACE(ACE_TEXT("::print_usage"));

  std::string base_data_path;
#ifdef DATADIR
  base_data_path = DATADIR;
#else
  base_data_path = RPG_Common_File_Tools::getWorkingDirectory(); // fallback
#endif // #ifdef DATADIR

  std::cout << ACE_TEXT("usage: ") << programName_in << ACE_TEXT(" [OPTIONS]") << std::endl << std::endl;
  std::cout << ACE_TEXT("currently available options:") << std::endl;
  std::string path = base_data_path;
  path += ACE_DIRECTORY_SEPARATOR_STR;
  path += RPG_COMMON_DEF_DATA_SUB;
  path += ACE_DIRECTORY_SEPARATOR_STR;
  path += RPG_GRAPHICS_DEF_DATA_SUB;
  std::cout << ACE_TEXT("-d [DIR] : graphics directory") << ACE_TEXT(" [\"") << path.c_str() << ACE_TEXT("\"]") << std::endl;
  path = base_data_path;
  path += ACE_DIRECTORY_SEPARATOR_STR;
  path += RPG_COMMON_DEF_CONFIG_SUB;
  path += ACE_DIRECTORY_SEPARATOR_STR;
  path += RPG_GRAPHICS_DEF_DICTIONARY_FILE;
  std::cout << ACE_TEXT("-g [FILE]: graphics dictionary (*.xml)") << ACE_TEXT(" [\"") << path.c_str() << ACE_TEXT("\"]") << std::endl;
  std::cout << ACE_TEXT("-m [FILE]: level map (*.txt)") << std::endl;
  std::cout << ACE_TEXT("-s       : slideshow mode (show random graphics)") << std::endl;
  std::cout << ACE_TEXT("-t       : trace information") << std::endl;
  std::cout << ACE_TEXT("-v       : print version information and exit") << std::endl;
  std::cout << ACE_TEXT("-x       : do NOT validate XML") << std::endl;
} // end print_usage

const bool
process_arguments(const int argc_in,
                  ACE_TCHAR* argv_in[], // cannot be const...
                  std::string& directory_out,
                  std::string& dictionary_out,
                  std::string& filename_out,
                  bool& slideShowMode_out,
                  bool& traceInformation_out,
                  bool& printVersionAndExit_out,
                  bool& validateXML_out)
{
  RPG_TRACE(ACE_TEXT("::process_arguments"));

  // init results
  std::string base_data_path;
#ifdef DATADIR
  base_data_path = DATADIR;
#else
  base_data_path = RPG_Common_File_Tools::getWorkingDirectory(); // fallback
#endif // #ifdef DATADIR

  directory_out = base_data_path;
  directory_out += ACE_DIRECTORY_SEPARATOR_STR;
  directory_out += RPG_COMMON_DEF_DATA_SUB;
  directory_out += ACE_DIRECTORY_SEPARATOR_STR;
  directory_out += RPG_GRAPHICS_DEF_DATA_SUB;
  dictionary_out = base_data_path;
  dictionary_out += ACE_DIRECTORY_SEPARATOR_STR;
  dictionary_out += RPG_COMMON_DEF_CONFIG_SUB;
  dictionary_out += ACE_DIRECTORY_SEPARATOR_STR;
  dictionary_out += RPG_GRAPHICS_DEF_DICTIONARY_FILE;
  filename_out.clear();
  slideShowMode_out = (SDL_GUI_DEF_MODE == MODE_RANDOM_IMAGES);
  traceInformation_out = false;
  printVersionAndExit_out = false;
  validateXML_out = true;

  ACE_Get_Opt argumentParser(argc_in,
                             argv_in,
                             ACE_TEXT("d:g:m:stvx"));

  int option = 0;
  while ((option = argumentParser()) != EOF)
  {
    switch (option)
    {
      case 'd':
      {
        directory_out = argumentParser.opt_arg();

        break;
      }
      case 'g':
      {
        dictionary_out = argumentParser.opt_arg();

        break;
      }
      case 'm':
      {
        filename_out = argumentParser.opt_arg();

        break;
      }
      case 's':
      {
        slideShowMode_out = true;

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
do_work(const mode_t& mode_in,
        const std::string& map_in,
        const map_config_t& mapConfig_in,
        const SDL_video_config_t& videoConfig_in,
        const std::string& dictionary_in,
        const std::string& graphicsDirectory_in,
        const unsigned long& cacheSize_in,
        const bool& validateXML_in)
{
  RPG_TRACE(ACE_TEXT("::do_work"));

  // step0: init: random seed, string conversion facilities, ...
  RPG_Dice::init();
  RPG_Dice_Common_Tools::initStringConversionTables();
  RPG_Graphics_Common_Tools::initStringConversionTables();

  // step1a: init graphics dictionary
  try
  {
    RPG_GRAPHICS_DICTIONARY_SINGLETON::instance()->init(dictionary_in,
                                                        validateXML_in);
  }
  catch (...)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("caught exception in RPG_Graphics_Dictionary::init(), aborting\n")));

    return;
  }

  // step1b: init Video
  if (!do_initVideo(graphicsDirectory_in,
                    videoConfig_in))
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to initialize video, aborting\n")));

    return;
  } // end IF
  // step1c: init graphics directory, cache, fonts, ...
  RPG_Graphics_Common_Tools::init(graphicsDirectory_in,
                                  cacheSize_in);

  // step2: setup main "window"
  RPG_Graphics_GraphicTypeUnion type;
  type.discriminator = RPG_Graphics_GraphicTypeUnion::IMAGE;
  type.image = SDL_GUI_DEF_GRAPHICS_WINDOWSTYLE_TYPE;
  std::string title = SDL_GUI_DEF_GRAPHICS_MAINWINDOW_TITLE;
  SDL_GUI_MainWindow mainWindow(RPG_Graphics_WindowSize_t(screen->w,
                                                          screen->h), // size
                                type,                                 // interface elements
                                title,                                // title (== caption)
                                FONT_MAIN_LARGE);                     // title font
  mainWindow.setScreen(screen);
  mainWindow.init();
  mainWindow.draw();
  mainWindow.refresh();

  // ***** mouse setup *****
  SDL_WarpMouse((screen->w / 2),
                (screen->h / 2));

  SDL_Event event;
  bool done = false;
  RPG_Graphics_IWindow* window = NULL;
  RPG_Graphics_IWindow* previous_window = NULL;
  bool need_redraw = false;
  switch (mode_in)
  {
    case MODE_RANDOM_IMAGES:
    {
      // step3: show (random) images inside main "window"
      RPG_Graphics_GraphicTypeUnion type;
      type.discriminator = RPG_Graphics_GraphicTypeUnion::INVALID;
      type.image = RPG_GRAPHICS_IMAGE_INVALID;
      RPG_Graphics_t graphic;
      graphic.category = RPG_GRAPHICS_CATEGORY_INVALID;
      graphic.type.discriminator = RPG_Graphics_GraphicTypeUnion::INVALID;
      RPG_Dice_RollResult_t result;
      SDL_Surface* image = NULL;
      bool release_image = false;
      do
      {
        window = NULL;
        need_redraw = false;
        image = NULL;
        release_image = false;

        // reset screen
        mainWindow.draw();
        mainWindow.refresh();

        // choose category
        do
        {
          result.clear();
          RPG_Dice::generateRandomNumbers(RPG_GRAPHICS_CATEGORY_MAX,
                                          1,
                                          result);
          graphic.category = static_cast<RPG_Graphics_Category> ((result.front() - 1));
        } while (graphic.category == CATEGORY_FONT); // cannot display fonts at the moment

        // choose type within category
        result.clear();
        switch (graphic.category)
        {
          case CATEGORY_CURSOR:
          {
            RPG_Dice::generateRandomNumbers(RPG_GRAPHICS_CURSOR_MAX,
                                            1,
                                            result);
            type.cursor = static_cast<RPG_Graphics_Cursor> ((result.front() - 1));
            type.discriminator = RPG_Graphics_GraphicTypeUnion::CURSOR;

            break;
          }
          case CATEGORY_INTERFACE:
          case CATEGORY_IMAGE:
          {
            RPG_Dice::generateRandomNumbers(RPG_GRAPHICS_IMAGE_MAX,
                                            1,
                                            result);
            type.image = static_cast<RPG_Graphics_Image> ((result.front() - 1));
            type.discriminator = RPG_Graphics_GraphicTypeUnion::IMAGE;

            break;
          }
          case CATEGORY_TILE:
          {
            RPG_Dice::generateRandomNumbers(RPG_GRAPHICS_TILEGRAPHIC_MAX,
                                            1,
                                            result);
            type.tilegraphic = static_cast<RPG_Graphics_TileGraphic> ((result.front() - 1));
            type.discriminator = RPG_Graphics_GraphicTypeUnion::TILEGRAPHIC;

            break;
          }
          case CATEGORY_TILESET:
          {
            RPG_Dice::generateRandomNumbers(RPG_GRAPHICS_TILESETGRAPHIC_MAX,
                                            1,
                                            result);
            type.tilesetgraphic = static_cast<RPG_Graphics_TileSetGraphic> ((result.front() - 1));
            type.discriminator = RPG_Graphics_GraphicTypeUnion::TILESETGRAPHIC;

            break;
          }
          default:
          {
            ACE_DEBUG((LM_ERROR,
                       ACE_TEXT("invalid category (was: \"%s\"), continuing\n"),
                       RPG_Graphics_CategoryHelper::RPG_Graphics_CategoryToString(graphic.category).c_str()));

            continue;
          }
        } // end SWITCH

        if (graphic.category != CATEGORY_TILESET)
        {
          image = RPG_Graphics_Common_Tools::loadGraphic(type);
          if (!image)
          {
            ACE_DEBUG((LM_ERROR,
                       ACE_TEXT("failed to RPG_Graphics_Common_Tools::loadGraphic(\"%s\"), continuing\n"),
                       RPG_Graphics_Common_Tools::typeToString(type).c_str()));

            continue;
          } // end IF
        } // end IF
        else
        {
          // need to load this manually --> retrieve filename(s)
          graphic.category = RPG_GRAPHICS_CATEGORY_INVALID;
          graphic.type.discriminator = RPG_Graphics_GraphicTypeUnion::INVALID;
          graphic = RPG_GRAPHICS_DICTIONARY_SINGLETON::instance()->get(type);
          ACE_ASSERT((graphic.type.discriminator == type.discriminator) &&
                     (graphic.type.tilesetgraphic == type.tilesetgraphic));
          ACE_ASSERT(!graphic.tileset.tiles.empty());

          // choose random tile
          std::vector<RPG_Graphics_Tile>::const_iterator iterator = graphic.tileset.tiles.begin();
          result.clear();
          RPG_Dice::generateRandomNumbers(graphic.tileset.tiles.size(),
                                          1,
                                          result);
          std::advance(iterator, (result.front() - 1));

          // assemble filename
          std::string filename = graphicsDirectory_in;
          filename += ACE_DIRECTORY_SEPARATOR_STR;
          switch (graphic.tileset.type)
          {
            case TILESETTYPE_DOOR:
              filename += RPG_GRAPHICS_TILE_DEF_DOORS_SUB; break;
            case TILESETTYPE_FLOOR:
              filename += RPG_GRAPHICS_TILE_DEF_FLOORS_SUB; break;
            case TILESETTYPE_WALL:
              filename += RPG_GRAPHICS_TILE_DEF_WALLS_SUB; break;
            default:
            {
              ACE_DEBUG((LM_ERROR,
                         ACE_TEXT("invalid tileset type (was: \"%s\"), continuing\n"),
                         RPG_Graphics_TileSetTypeHelper::RPG_Graphics_TileSetTypeToString(graphic.tileset.type).c_str()));

              continue;
            }
          } // end SWITCH
          filename += ACE_DIRECTORY_SEPARATOR_STR;
          filename += (*iterator).file;

          image = RPG_Graphics_Surface::load(filename, // file
                                             true);    // convert to display format
          if (!image)
          {
            ACE_DEBUG((LM_ERROR,
                       ACE_TEXT("failed to RPG_Graphics_Surface::load(\"%s\"), continuing\n"),
                       filename.c_str()));

            continue;
          } // end IF
          release_image = true;
        } // end ELSE
        ACE_ASSERT(image);

        ACE_DEBUG((LM_DEBUG,
                   ACE_TEXT("showing graphics type \"%s\"...\n"),
                   RPG_Graphics_Common_Tools::typeToString(type).c_str()));

        RPG_Graphics_Surface::put((screen->w - image->w) / 2, // location x
                                  (screen->h - image->h) / 2, // location y
                                  *image,                     // image
                                  screen);                    // screen
        if (SDL_Flip(screen))
        {
          ACE_DEBUG((LM_ERROR,
                     ACE_TEXT("failed to SDL_Flip(): \"%s\", aborting\n"),
                     SDL_GetError()));

          return;
        } // end IF

        // step4: wait a little while (max: 3 seconds)
        do
        {
          do_SDL_waitForInput(3,      // second(s)
                              event); // return value: event
          switch (event.type)
          {
            case SDL_KEYDOWN:
            {
              switch (event.key.keysym.sym)
              {
                case SDLK_q:
                {
                  // finished event processing
                  done = true;

                  break;
                } // end IF
                default:
                  break;
              } // end SWITCH

              if (done)
                break;
              // *WARNING*: falls through !
            }
            case SDL_ACTIVEEVENT:
//             case SDL_MOUSEMOTION:
            case SDL_MOUSEBUTTONDOWN:
//             case SDL_GUI_SDL_HOVEREVENT: // hovering...
            {
              // find window
              RPG_Graphics_Position_t mouse_position(0, 0);
              switch (event.type)
              {
                case SDL_MOUSEMOTION:
                  mouse_position = std::make_pair(event.motion.x,
                                                  event.motion.y); break;
                case SDL_MOUSEBUTTONDOWN:
                  mouse_position = std::make_pair(event.button.x,
                                                  event.button.y); break;
                default:
                {
                  int x,y;
                  SDL_GetMouseState(&x, &y);
                  mouse_position = std::make_pair(x,
                                                  y);

                  break;
                }
              } // end SWITCH
              window = mainWindow.getWindow(mouse_position);
              ACE_ASSERT(window);
              try
              {
                window->handleEvent(event,
                                    window,
                                    need_redraw);
              }
              catch (...)
              {
                ACE_DEBUG((LM_ERROR,
                           ACE_TEXT("caught exception in RPG_Graphics_IWindow::handleEvent(), continuing\n")));
              }

              break;
            }
            case SDL_QUIT:
            {
              // finished event processing
              done = true;

              break;
            }
            case SDL_KEYUP:
            case SDL_MOUSEBUTTONUP:
            case SDL_JOYAXISMOTION:
            case SDL_JOYBALLMOTION:
            case SDL_JOYHATMOTION:
            case SDL_JOYBUTTONDOWN:
            case SDL_JOYBUTTONUP:
            case SDL_SYSWMEVENT:
            case SDL_VIDEORESIZE:
            case SDL_VIDEOEXPOSE:
            case SDL_GUI_SDL_TIMEREVENT:
            default:
            {

              break;
            }
          } // end SWITCH
        } while (event.type == SDL_MOUSEMOTION);

        // clean up
        if (release_image)
          SDL_FreeSurface(image);
      } while (!done);

      break;
    }
    case MODE_LEVEL_MAP:
    {
      bool force_redraw = false;

      // step3a: setup level
      RPG_Map_Position_t  startingPosition;
      RPG_Map_Positions_t seedPoints;
      RPG_Map_FloorPlan_t plan;
      if (map_in.empty())
        RPG_Map_Common_Tools::createFloorPlan(mapConfig_in.map_size_x,
                                              mapConfig_in.map_size_y,
                                              mapConfig_in.num_areas,
                                              mapConfig_in.square_rooms,
                                              mapConfig_in.maximize_rooms,
                                              mapConfig_in.min_room_size,
                                              mapConfig_in.doors,
                                              mapConfig_in.corridors,
                                              true, // *NOTE*: currently, doors fill one position
                                              mapConfig_in.max_num_doors_per_room,
                                              seedPoints,
                                              plan);
      else
      {
        if (!RPG_Map_Common_Tools::load(map_in,
                                        startingPosition,
                                        seedPoints,
                                        plan,
                                        false,
                                        false))
        {
          ACE_DEBUG((LM_ERROR,
                     ACE_TEXT("failed to RPG_Map_Common_Tools::load(\"%s\"), aborting\n"),
                     map_in.c_str()));

          return;
        } // end IF

        ACE_DEBUG((LM_DEBUG,
                   ACE_TEXT("loaded map (\"%s\": size [%u,%u], %u seed point(s))...\n"),
                   map_in.c_str(),
                   plan.size_x,
                   plan.size_y,
                   seedPoints.size()));
      } // end ELSE

//       RPG_Map_Common_Tools::displayFloorPlan(seedPoints,
//                                              plan);

      // step3b: setup style
      RPG_Graphics_MapStyle_t mapStyle;
      mapStyle.floor_style = SDL_GUI_DEF_GRAPHICS_FLOORSTYLE;
      mapStyle.edge_style = SDL_GUI_DEF_GRAPHICS_EDGESTYLE;
      mapStyle.wall_style = SDL_GUI_DEF_GRAPHICS_WALLSTYLE;
      mapStyle.half_height_walls = SDL_GUI_DEF_GRAPHICS_WALLSTYLE_HALF;
      mapStyle.door_style = SDL_GUI_DEF_GRAPHICS_DOORSTYLE;

      // step4: set default cursor
      RPG_GRAPHICS_CURSOR_MANAGER_SINGLETON::instance()->set(CURSOR_NORMAL);

      // step5: setup level "window"
      // *NOTE*: need to allocate this dynamically so parent window can
      // assume ownership...
      SDL_GUI_LevelWindow* mapWindow = NULL;
      try
      {
        mapWindow = new SDL_GUI_LevelWindow(mainWindow, // parent
                                            mapStyle,   // map style
                                            plan);      // map
      }
      catch (...)
      {
        ACE_DEBUG((LM_ERROR,
                   ACE_TEXT("failed to allocate memory(%u): %m, aborting\n"),
                   sizeof(SDL_GUI_LevelWindow)));

        return;
      }
      if (!mapWindow)
      {
        ACE_DEBUG((LM_ERROR,
                   ACE_TEXT("failed to allocate memory(%u): %m, aborting\n"),
                   sizeof(SDL_GUI_LevelWindow)));

        return;
      } // end IF
      mapWindow->setScreen(screen);

      // refresh screen
      try
      {
        mapWindow->draw();
        mapWindow->refresh();
      }
      catch (...)
      {
        ACE_DEBUG((LM_ERROR,
                   ACE_TEXT("caught exception in RPG_Graphics_IWindow::draw()/refresh(), continuing\n")));
      }

      // step6: start timer (triggers hover events)
      SDL_TimerID timer = NULL;
      timer = SDL_AddTimer(SDL_GUI_SDL_EVENT_TIMEOUT, // interval (ms)
                           event_timer_SDL_cb,        // event timer callback
                           &hover_time);              // callback argument
      if (!timer)
      {
        ACE_DEBUG((LM_ERROR,
                   ACE_TEXT("failed to SDL_AddTimer(%u): \"%s\", aborting\n"),
                   SDL_GUI_SDL_EVENT_TIMEOUT,
                   SDL_GetError()));

        return;
      } // end IF

      RPG_Graphics_Position_t mouse_position;
      bool hide_walls = false;
      do
      {
        window = NULL;
        need_redraw = false;
        mouse_position = std::make_pair(0, 0);
        force_redraw = false;

        // step7: process events
        if (SDL_WaitEvent(&event) != 1)
        {
          ACE_DEBUG((LM_ERROR,
                     ACE_TEXT("failed to SDL_WaitEvent(): \"%s\", aborting\n"),
                     SDL_GetError()));

          return;
        } // end IF

        // if necessary, reset hover_time
        if (event.type != RPG_GRAPHICS_SDL_HOVEREVENT)
        {
          // synch access
          ACE_Guard<ACE_Thread_Mutex> aGuard(hover_lock);

          hover_time = 0;
        } // end IF

        switch (event.type)
        {
          case SDL_KEYDOWN:
          {
            switch (event.key.keysym.sym)
            {
              case SDLK_f:
              {
                mapStyle.floor_style = static_cast<RPG_Graphics_FloorStyle> (mapStyle.floor_style + 1);
                if (mapStyle.floor_style == RPG_GRAPHICS_FLOORSTYLE_MAX)
                  mapStyle.floor_style = static_cast<RPG_Graphics_FloorStyle> (0);
                RPG_Graphics_StyleUnion style;
                style.discriminator = RPG_Graphics_StyleUnion::FLOORSTYLE;
                style.floorstyle = mapStyle.floor_style;
                mapWindow->setStyle(style);

                force_redraw = true;

                break;
              }
              case SDLK_h:
              {
                // toggle setting
                if (hide_walls)
                  hide_walls = false;
                else
                  hide_walls = true;

                mapWindow->hideWalls(hide_walls);

                force_redraw = true;

                break;
              }
              case SDLK_m:
              {
                std::string dump_path = RPG_MAP_DUMP_DIR;
                dump_path += ACE_DIRECTORY_SEPARATOR_STR;
                dump_path += ACE_TEXT("map.txt");
                if (!RPG_Map_Common_Tools::save(dump_path,
                                                startingPosition,
                                                seedPoints,
                                                plan))
                {
                  ACE_DEBUG((LM_ERROR,
                             ACE_TEXT("failed to RPG_Map_Common_Tools::save(\"%s\"), aborting\n"),
                             dump_path.c_str()));

                  return;
                } // end IF

                break;
              }
              case SDLK_q:
              {
                // finished event processing
                done = true;

                break;
              }
              case SDLK_w:
              {
                mapStyle.wall_style = static_cast<RPG_Graphics_WallStyle> (mapStyle.wall_style + 1);;
                if (mapStyle.wall_style == RPG_GRAPHICS_WALLSTYLE_MAX)
                  mapStyle.wall_style = static_cast<RPG_Graphics_WallStyle> (0);
                RPG_Graphics_StyleUnion style;
                style.discriminator = RPG_Graphics_StyleUnion::WALLSTYLE;
                style.wallstyle = mapStyle.wall_style;
                mapWindow->setStyle(style);

                force_redraw = true;

                break;
              }
              default:
              {
                break;
              }
            } // end SWITCH

            if (done)
              break; // leave
            // *WARNING*: falls through !
          }
          case SDL_ACTIVEEVENT:
          case SDL_MOUSEMOTION:
          case SDL_MOUSEBUTTONDOWN:
          case RPG_GRAPHICS_SDL_HOVEREVENT: // hovering...
          {
            // find window
            switch (event.type)
            {
              case SDL_MOUSEMOTION:
                mouse_position = std::make_pair(event.motion.x,
                                                event.motion.y); break;
              case SDL_MOUSEBUTTONDOWN:
                mouse_position = std::make_pair(event.button.x,
                                                event.button.y); break;
              default:
              {
                int x,y;
                SDL_GetMouseState(&x, &y);
                mouse_position = std::make_pair(x,
                                                y);

                break;
              }
            } // end SWITCH
            window = mainWindow.getWindow(mouse_position);
            ACE_ASSERT(window);

            // notify previously "active" window upon losing "focus"
            if (event.type == SDL_MOUSEMOTION)
            {
              if (previous_window &&
  //                 (previous_window != mainWindow)
                  (previous_window != window))
              {
                event.type = RPG_GRAPHICS_SDL_MOUSEMOVEOUT;
                try
                {
                  previous_window->handleEvent(event,
                                               previous_window,
                                               need_redraw);
                }
                catch (...)
                {
                  ACE_DEBUG((LM_ERROR,
                             ACE_TEXT("caught exception in RPG_Graphics_IWindow::handleEvent(), continuing\n")));
                }
                event.type = SDL_MOUSEMOTION;
              } // end IF
            } // end IF
            // remember last "active" window
            previous_window = window;

            // notify "active" window
            try
            {
              window->handleEvent(event,
                                  window,
                                  need_redraw);
            }
            catch (...)
            {
              ACE_DEBUG((LM_ERROR,
                         ACE_TEXT("caught exception in RPG_Graphics_IWindow::handleEvent(), continuing\n")));
            }

            break;
          }
          case SDL_QUIT:
          {
            // finished event processing
            done = true;

            break;
          }
          case SDL_KEYUP:
          case SDL_MOUSEBUTTONUP:
          case SDL_JOYAXISMOTION:
          case SDL_JOYBALLMOTION:
          case SDL_JOYHATMOTION:
          case SDL_JOYBUTTONDOWN:
          case SDL_JOYBUTTONUP:
          case SDL_SYSWMEVENT:
          case SDL_VIDEORESIZE:
          case SDL_VIDEOEXPOSE:
          case SDL_GUI_SDL_TIMEREVENT:
          default:
          {

            break;
          }
        } // end SWITCH

        // redraw map ?
        if (force_redraw || need_redraw)
        {
          try
          {
            mapWindow->draw();
            mapWindow->refresh();
          }
          catch (...)
          {
            ACE_DEBUG((LM_ERROR,
                       ACE_TEXT("caught exception in RPG_Graphics_IWindow::draw()/refresh(), continuing\n")));
          }
        } // end IF

        // redraw cursor ?
        switch (event.type)
        {
          case SDL_KEYDOWN:
          case SDL_MOUSEBUTTONDOWN:
          {
            // map hasn't changed --> no need to redraw
            if (!need_redraw)
              break;

            // *WARNING*: falls through !
          }
          case SDL_MOUSEMOTION:
          case RPG_GRAPHICS_SDL_HOVEREVENT:
          {
            // map has changed, cursor MAY have been drawn over...
            // --> redraw cursor
            SDL_Rect dirtyRegion;
            RPG_GRAPHICS_CURSOR_MANAGER_SINGLETON::instance()->put(mouse_position.first,
                                                                   mouse_position.second,
                                                                   screen,
                                                                   dirtyRegion);
            RPG_Graphics_Surface::update(dirtyRegion,
                                         screen);

            break;
          }
          default:
          {
            break;
          }
        } // end SWITCH
      } while (!done);

      // step8: clean up
      if (!SDL_RemoveTimer(timer))
      {
        ACE_DEBUG((LM_ERROR,
                   ACE_TEXT("failed to SDL_RemoveTimer(): \"%s\", continuing\n"),
                   SDL_GetError()));
      } // end IF

      break;
    }
    default:
    {
      ACE_DEBUG((LM_ERROR,
                 ACE_TEXT("invalid mode (was: %d), aborting\n"),
                 mode_in));

      break;
    }
  } // end SWITCH

  ACE_DEBUG((LM_DEBUG,
             ACE_TEXT("finished working...\n")));
} // end do_work

void
do_printVersion(const std::string& programName_in)
{
  RPG_TRACE(ACE_TEXT("::do_printVersion"));

//   std::cout << programName_in << ACE_TEXT(" : ") << VERSION << std::endl;
  std::cout << programName_in << ACE_TEXT(" : ") << RPG_VERSION << std::endl;

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

  // step0: init ACE
  // *PORTABILITY*: on Windows, we need to init ACE...
#if defined (ACE_WIN32) || defined (ACE_WIN64)
  if (ACE::init() == -1)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to ACE::init(): \"%m\", aborting\n")));

    return EXIT_FAILURE;
  } // end IF
#endif

  // step1: init
  // step1a set defaults
  std::string base_data_path;
#ifdef DATADIR
  base_data_path = DATADIR;
#else
  base_data_path = RPG_Common_File_Tools::getWorkingDirectory(); // fallback
#endif // #ifdef DATADIR

  std::string graphicsDirectory = base_data_path;
  graphicsDirectory += ACE_DIRECTORY_SEPARATOR_STR;
  graphicsDirectory += RPG_COMMON_DEF_DATA_SUB;
  graphicsDirectory += ACE_DIRECTORY_SEPARATOR_STR;
  graphicsDirectory += RPG_GRAPHICS_DEF_DATA_SUB;
  unsigned long cacheSize        = SDL_GUI_DEF_GRAPHICS_CACHESIZE;
  std::string dictionary = base_data_path;
  dictionary += ACE_DIRECTORY_SEPARATOR_STR;
  dictionary += RPG_COMMON_DEF_CONFIG_SUB;
  dictionary += ACE_DIRECTORY_SEPARATOR_STR;
  dictionary += RPG_GRAPHICS_DEF_DICTIONARY_FILE;
  mode_t mode                    = SDL_GUI_DEF_MODE;
  std::string mapFilename;
  bool slideShowMode             = (SDL_GUI_DEF_MODE == MODE_RANDOM_IMAGES);
  bool traceInformation          = false;
  bool printVersionAndExit       = false;
  bool validateXML               = true;

  // *** map ***
  map_config_t map_config;
  map_config.min_room_size          = SDL_GUI_DEF_MAP_MIN_ROOM_SIZE;
  map_config.doors                  = SDL_GUI_DEF_MAP_DOORS;
  map_config.corridors              = SDL_GUI_DEF_MAP_CORRIDORS;
  map_config.max_num_doors_per_room = SDL_GUI_DEF_MAP_MAX_NUM_DOORS_PER_ROOM;
  map_config.maximize_rooms         = SDL_GUI_DEF_MAP_MAXIMIZE_ROOMS;
  map_config.num_areas              = SDL_GUI_DEF_MAP_NUM_AREAS;
  map_config.square_rooms           = SDL_GUI_DEF_MAP_SQUARE_ROOMS;
  map_config.map_size_x             = SDL_GUI_DEF_MAP_SIZE_X;
  map_config.map_size_y             = SDL_GUI_DEF_MAP_SIZE_Y;

  // *** video ***
  SDL_video_config_t video_config;
  video_config.screen_width      = SDL_GUI_DEF_VIDEO_W;
  video_config.screen_height     = SDL_GUI_DEF_VIDEO_H;
  video_config.screen_colordepth = SDL_GUI_DEF_VIDEO_BPP;
//   video_config.screen_flags      = ;
  video_config.fullScreen        = SDL_GUI_DEF_VIDEO_FULLSCREEN;
  video_config.doubleBuffer      = SDL_GUI_DEF_VIDEO_DOUBLEBUFFER;

  // step1b: parse/process/validate configuration
  if (!(process_arguments(argc,
                          argv,
                          graphicsDirectory,
                          dictionary,
                          mapFilename,
                          slideShowMode,
                          traceInformation,
                          printVersionAndExit,
                          validateXML)))
  {
    // make 'em learn...
    print_usage(std::string(ACE::basename(argv[0])));

    // *PORTABILITY*: on Windows, we must fini ACE...
#if defined (ACE_WIN32) || defined (ACE_WIN64)
    if (ACE::fini() == -1)
      ACE_DEBUG((LM_ERROR,
                 ACE_TEXT("failed to ACE::fini(): \"%m\", continuing\n")));
#endif

    return EXIT_FAILURE;
  } // end IF

  // step1b: validate arguments
  if (!RPG_Common_File_Tools::isDirectory(graphicsDirectory) ||
      !RPG_Common_File_Tools::isReadable(dictionary) ||
      !RPG_Common_File_Tools::isReadable(mapFilename))
  {
    ACE_DEBUG((LM_DEBUG,
               ACE_TEXT("invalid argument, aborting\n")));

    // make 'em learn...
    print_usage(std::string(ACE::basename(argv[0])));

    // *PORTABILITY*: on Windows, we must fini ACE...
#if defined (ACE_WIN32) || defined (ACE_WIN64)
    if (ACE::fini() == -1)
      ACE_DEBUG((LM_ERROR,
                 ACE_TEXT("failed to ACE::fini(): \"%m\", continuing\n")));
#endif

    return EXIT_FAILURE;
  } // end IF
  if (!mapFilename.empty() &&
      !RPG_Common_File_Tools::isReadable(mapFilename))
  {
    ACE_DEBUG((LM_DEBUG,
               ACE_TEXT("invalid map filename \"%s\", aborting\n"),
               mapFilename.c_str()));

    // make 'em learn...
    print_usage(std::string(ACE::basename(argv[0])));

    // *PORTABILITY*: on Windows, we must fini ACE...
#if defined (ACE_WIN32) || defined (ACE_WIN64)
    if (ACE::fini() == -1)
      ACE_DEBUG((LM_ERROR,
                 ACE_TEXT("failed to ACE::fini(): \"%m\", continuing\n")));
#endif

    return EXIT_FAILURE;
  } // end IF
  if (!RPG_Common_File_Tools::isDirectory(graphicsDirectory))
  {
    ACE_DEBUG((LM_DEBUG,
               ACE_TEXT("invalid graphics directory \"%s\", aborting\n"),
               graphicsDirectory.c_str()));

    // *PORTABILITY*: on Windows, we must fini ACE...
#if defined (ACE_WIN32) || defined (ACE_WIN64)
    if (ACE::fini() == -1)
      ACE_DEBUG((LM_ERROR,
                 ACE_TEXT("failed to ACE::fini(): \"%m\", continuing\n")));
#endif

    return EXIT_FAILURE;
  } // end IF
  mode = (slideShowMode ? MODE_RANDOM_IMAGES : mode);

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
               SDL_INIT_VIDEO |
               SDL_INIT_NOPARACHUTE) == -1) // "...Prevents SDL from catching fatal signals..."
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to SDL_Init(): \"%s\", aborting\n"),
               SDL_GetError()));

    // *PORTABILITY*: on Windows, we must fini ACE...
#if defined (ACE_WIN32) || defined (ACE_WIN64)
    if (ACE::fini() == -1)
      ACE_DEBUG((LM_ERROR,
                 ACE_TEXT("failed to ACE::fini(): \"%m\", continuing\n")));
#endif

    return EXIT_FAILURE;
  } // end IF
  // ***** mouse setup *****
  // don't show (double) cursor
  SDL_ShowCursor(SDL_DISABLE);
  // ***** keyboard setup *****
  // enable Unicode translation
  SDL_EnableUNICODE(1);
  // enable key repeat
  SDL_EnableKeyRepeat(SDL_DEFAULT_REPEAT_DELAY,
                      SDL_DEFAULT_REPEAT_INTERVAL);
  // setup font engine
  if (TTF_Init() == -1)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to TTF_Init(): \"%s\", aborting\n"),
               SDL_GetError()));

    SDL_Quit();
    // *PORTABILITY*: on Windows, we must fini ACE...
#if defined (ACE_WIN32) || defined (ACE_WIN64)
    if (ACE::fini() == -1)
      ACE_DEBUG((LM_ERROR,
                 ACE_TEXT("failed to ACE::fini(): \"%m\", continuing\n")));
#endif

    return EXIT_FAILURE;
  } // end IF
  // enable WM events
  Uint8 event_state = 0;
  event_state = SDL_EventState(SDL_SYSWMEVENT, SDL_QUERY);
  if ((event_state == SDL_IGNORE) ||
      (event_state == SDL_DISABLE))
  {
    SDL_EventState(SDL_SYSWMEVENT, SDL_ENABLE);

    ACE_DEBUG((LM_DEBUG,
               ACE_TEXT("enabled SDL_SYSWMEVENT events...\n")));
  } // end IF
  event_state = SDL_EventState(SDL_ACTIVEEVENT, SDL_QUERY);
  if ((event_state == SDL_IGNORE) ||
      (event_state == SDL_DISABLE))
  {
    SDL_EventState(SDL_ACTIVEEVENT, SDL_ENABLE);

    ACE_DEBUG((LM_DEBUG,
               ACE_TEXT("enabled SDL_ACTIVEEVENT events...\n")));
  } // end IF

  // step3: do actual work
  ACE_High_Res_Timer timer;
  timer.start();
  do_work(mode,
          mapFilename,
          map_config,
          video_config,
          dictionary,
          graphicsDirectory,
          cacheSize,
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
  TTF_Quit();
  SDL_Quit();

  // *PORTABILITY*: on Windows, we must fini ACE...
#if defined (ACE_WIN32) || defined (ACE_WIN64)
  if (ACE::fini() == -1)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to ACE::fini(): \"%m\", aborting\n")));

    return EXIT_FAILURE;
  } // end IF
#endif

  return EXIT_SUCCESS;
} // end main
