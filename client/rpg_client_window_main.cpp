﻿/***************************************************************************
 *   Copyright (C) 2010 by Erik Sohns   *
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

#include "rpg_client_window_main.h"

#include <sstream>

#include "ace/Log_Msg.h"

#include "common_defines.h"

#include "rpg_common_defines.h"
#include "rpg_common_macros.h"

#include "rpg_engine.h"

#include "rpg_graphics_common_tools.h"
#include "rpg_graphics_cursor_manager.h"
#include "rpg_graphics_defines.h"
#include "rpg_graphics_hotspot.h"
#include "rpg_graphics_surface.h"
#include "rpg_graphics_SDL_tools.h"

#include "rpg_client_defines.h"
#include "rpg_client_engine.h"
#include "rpg_client_iwindow_level.h"
#include "rpg_client_window_level.h"

RPG_Client_Window_Main::RPG_Client_Window_Main (const RPG_Graphics_Size_t& size_in,
                                                const struct RPG_Graphics_GraphicTypeUnion& elementType_in,
                                                const std::string& title_in,
                                                enum RPG_Graphics_Font font_in)
 : inherited (size_in,        // size
              elementType_in, // element type
              title_in)       // title
 , myEngine (NULL)
 , myScreenshotIndex (1)
 , myLastHoverTime (0)
 , myAutoEdgeScroll (RPG_CLIENT_WINDOW_DEF_EDGE_AUTOSCROLL)
 , myTitleFont (font_in)
{
  RPG_TRACE (ACE_TEXT ("RPG_Client_Window_Main::RPG_Client_Window_Main"));

}

bool
RPG_Client_Window_Main::initialize (RPG_Client_Engine* clientEngine_in,
                                    bool doAutoEdgeScroll_in,
                                    RPG_Engine* engine_in,
                                    bool debug_in)
{
  RPG_TRACE (ACE_TEXT ("RPG_Client_Window_Main::initialize"));

  // sanity checks
  ACE_ASSERT (clientEngine_in);
  ACE_ASSERT (engine_in);

  myEngine = clientEngine_in;
  myAutoEdgeScroll = doAutoEdgeScroll_in;

  // initialize scroll margins
  initScrollSpots (debug_in);

  // initialize map window
  return initMap (clientEngine_in,
                  engine_in,
                  debug_in);
}

void
RPG_Client_Window_Main::draw (SDL_Surface* targetSurface_in,
                              unsigned int offsetX_in,
                              unsigned int offsetY_in)
{
  RPG_TRACE (ACE_TEXT ("RPG_Client_Window_Main::draw"));

  // sanity check(s)
  ACE_ASSERT (inherited::screen_);
#if defined (SDL_USE)
  SDL_Surface* surface_p = inherited::screen_;
#elif defined (SDL2_USE) || defined (SDL3_USE)
  SDL_Surface* surface_p = SDL_GetWindowSurface (inherited::screen_);
#endif // SDL_USE || SDL2_USE || SDL3_USE
  ACE_ASSERT (surface_p);
  SDL_Surface* target_surface =
    (targetSurface_in ? targetSurface_in : surface_p);
  ACE_ASSERT (target_surface);
  ACE_ASSERT (static_cast<int> (offsetX_in) <= target_surface->w);
  ACE_ASSERT (static_cast<int> (offsetY_in) <= target_surface->h);

  // step1: draw borders
  drawBorder (target_surface,
              offsetX_in,
              offsetY_in);

  // step2: fill central area
  struct SDL_Rect clip_rect, dirty_region;
  clip_rect.x = static_cast<int16_t> (offsetX_in + borderLeft_);
  clip_rect.y = static_cast<int16_t> (offsetY_in + borderTop_);
  clip_rect.w = static_cast<uint16_t> (target_surface->w -
                                       offsetX_in -
                                       (borderLeft_ + borderRight_));
  clip_rect.h = static_cast<uint16_t> (target_surface->h -
                                       offsetY_in -
                                       (borderTop_ + borderBottom_));
#if defined (SDL_USE) || defined (SDL2_USE)
  if (!SDL_SetClipRect (target_surface, &clip_rect))
#elif defined (SDL3_USE)
  if (!SDL_SetSurfaceClipRect (target_surface, &clip_rect))
#endif // SDL_USE || SDL2_USE || SDL3_USE
  {
    ACE_DEBUG ((LM_ERROR,
                ACE_TEXT ("failed to SDL_SetClipRect(): %s, returning\n"),
                ACE_TEXT (SDL_GetError ())));
    return;
  } // end IF
  RPG_Graphics_InterfaceElementsConstIterator_t iterator;
  iterator = myElementGraphics.find (INTERFACEELEMENT_BORDER_CENTER);
  ACE_ASSERT (iterator != myElementGraphics.end ());
  for (unsigned int i = (offsetY_in + borderTop_);
       i < (target_surface->h - borderBottom_);
       i += (*iterator).second->h)
    for (unsigned int j = (offsetX_in + borderLeft_);
         j < (target_surface->w - borderRight_);
         j += (*iterator).second->w)
      RPG_Graphics_Surface::put (std::make_pair (j,i),
                                 *(*iterator).second,
                                 target_surface,
                                 dirty_region);

#if defined (SDL_USE) || defined (SDL2_USE)
  if (!SDL_SetClipRect (target_surface, NULL))
#elif defined (SDL3_USE)
  if (!SDL_SetSurfaceClipRect (target_surface, NULL))
#endif // SDL_USE || SDL2_USE || SDL3_USE
  {
    ACE_DEBUG ((LM_ERROR,
                ACE_TEXT ("failed to SDL_SetClipRect(): %s, returning\n"),
                ACE_TEXT (SDL_GetError ())));
    return;
  } // end IF

  // step3: draw title (if any)
  if (!inherited::title_.empty ())
  {
    clip_rect.x = static_cast<int16_t> (borderLeft_);
    clip_rect.y = 0;
    clip_rect.w =
      static_cast<uint16_t> (target_surface->w - offsetX_in - (borderLeft_ + borderRight_));
    clip_rect.h = static_cast<uint16_t> (borderTop_);
#if defined (SDL_USE) || defined (SDL2_USE)
    if (!SDL_SetClipRect (target_surface, &clip_rect))
#elif defined (SDL3_USE)
    if (!SDL_SetSurfaceClipRect (target_surface, &clip_rect))
#endif // SDL_USE || SDL2_USE || SDL3_USE
    {
      ACE_DEBUG ((LM_ERROR,
                  ACE_TEXT ("failed to SDL_SetClipRect(): %s, returning\n"),
                  ACE_TEXT (SDL_GetError ())));
      return;
    } // end IF

    RPG_Graphics_TextSize_t title_size =
        RPG_Graphics_Common_Tools::textSize (myTitleFont,
                                             inherited::title_);
    RPG_Graphics_Surface::putText (myTitleFont,
                                   inherited::title_,
                                   RPG_Graphics_SDL_Tools::colorToSDLColor (RPG_Graphics_SDL_Tools::getColor (RPG_GRAPHICS_FONT_DEF_COLOR,
                                                                                                              *target_surface->format,
                                                                                                              1.0f),
                                                                            *target_surface->format),
                                   true, // add shade
                                   RPG_Graphics_SDL_Tools::colorToSDLColor (RPG_Graphics_SDL_Tools::getColor (RPG_GRAPHICS_FONT_DEF_SHADECOLOR,
                                                                                                              *target_surface->format,
                                                                                                              1.0f),
                                                                            *target_surface->format),
                                   std::make_pair (borderLeft_,                             // top left
                                                   ((borderTop_ - title_size.second) / 2)), // center of top border
                                   target_surface,
                                   dirty_region);

#if defined (SDL_USE) || defined (SDL2_USE)
    if (!SDL_SetClipRect (target_surface, NULL))
#elif defined (SDL3_USE)
    if (!SDL_SetSurfaceClipRect (target_surface, NULL))
#endif // SDL_USE || SDL2_USE || SDL3_USE
    {
      ACE_DEBUG ((LM_ERROR,
                  ACE_TEXT ("failed to SDL_SetClipRect(): %s, returning\n"),
                  ACE_TEXT (SDL_GetError ())));
      return;
    } // end IF
  } // end IF

  // step4: realize hotspots (and any other children)
  for (RPG_Graphics_WindowsIterator_t iterator = children_.begin ();
       iterator != children_.end ();
       iterator++)
  {
    try {
      (*iterator)->draw (target_surface,
                         offsetX_in,
                         offsetY_in);
    } catch (...) {
      ACE_DEBUG ((LM_ERROR,
                  ACE_TEXT ("caught exception in RPG_Graphics_IWindow::draw(), continuing\n")));
    }
  } // end FOR

  // whole window needs a refresh...
#if defined (SDL_USE) || defined (SDL2_USE)
  SDL_GetClipRect (target_surface, &dirty_region);
#elif defined (SDL3_USE)
  SDL_GetSurfaceClipRect (target_surface, &dirty_region);
#endif // SDL_USE || SDL2_USE || SDL3_USE
  inherited::invalidate (dirty_region);

  // remember position of last realization
  lastAbsolutePosition_ = std::make_pair (offsetX_in,
                                          offsetY_in);
}

void
RPG_Client_Window_Main::handleEvent (const SDL_Event& event_in,
                                     RPG_Graphics_IWindowBase* window_in,
                                     struct SDL_Rect& dirtyRegion_out)
{
  RPG_TRACE (ACE_TEXT ("RPG_Client_Window_Main::handleEvent"));

  // initialize return value(s)
  ACE_OS::memset (&dirtyRegion_out, 0, sizeof (struct SDL_Rect));

  struct RPG_Client_Action client_action;
  client_action.command = RPG_CLIENT_COMMAND_INVALID;
  client_action.position =
      std::make_pair (std::numeric_limits<unsigned int>::max (),
                      std::numeric_limits<unsigned int>::max ());
  client_action.window = this;
  client_action.cursor = RPG_GRAPHICS_CURSOR_INVALID;
  client_action.entity_id = 0;

  switch (event_in.type)
  {
    // *** visibility ***
#if defined (SDL_USE)
    case SDL_ACTIVEEVENT:
#elif defined (SDL2_USE)
    case SDL_WINDOWEVENT_SHOWN:
#endif // SDL_USE || SDL2_USE
    {
#if defined (SDL_USE)
      if (event_in.active.state & SDL_APPMOUSEFOCUS)
      {
        if (event_in.active.gain & SDL_APPMOUSEFOCUS)
        {
//           ACE_DEBUG((LM_DEBUG,
//                      ACE_TEXT("gained mouse coverage...\n")));

          //// *HACK*: prevents MOST "mouse trails" (NW borders)...
          //client_action.command = COMMAND_WINDOW_BORDER_DRAW;
          //myEngine->action(client_action);
          //client_action.command = COMMAND_WINDOW_REFRESH;
          //myEngine->action(client_action);

          //myHaveMouseFocus = true;
        } // end IF
        else
        {
//           ACE_DEBUG((LM_DEBUG,
//                      ACE_TEXT("lost mouse coverage...\n")));

          client_action.command = COMMAND_CURSOR_INVALIDATE_BG;
          client_action.window = this;
          myEngine->action (client_action);

          //// *HACK*: prevents MOST "mouse trails" (NW borders)...
          //client_action.command = COMMAND_WINDOW_BORDER_DRAW;
          //myEngine->action(client_action);
          //client_action.command = COMMAND_WINDOW_REFRESH;
          //myEngine->action(client_action);

          //myHaveMouseFocus = false;
        } // end ELSE
      } // end IF
      if (event_in.active.state & SDL_APPINPUTFOCUS)
      {
        if (event_in.active.gain & SDL_APPINPUTFOCUS)
        {
//           ACE_DEBUG((LM_DEBUG,
//                      ACE_TEXT("gained input focus...\n")));
        } // end IF
        else
        {
//           ACE_DEBUG((LM_DEBUG,
//                      ACE_TEXT("lost input focus...\n")));
        } // end ELSE
      } // end IF
      if (event_in.active.state & SDL_APPACTIVE)
      {
        if (event_in.active.gain & SDL_APPACTIVE)
        {
//           ACE_DEBUG((LM_DEBUG,
//                      ACE_TEXT("activated...\n")));
        } // end IF
        else
        {
//           ACE_DEBUG((LM_DEBUG,
//                      ACE_TEXT("iconified...\n")));
        } // end ELSE
      } // end IF
#endif // SDL_USE || SDL2_USE

      break;
    }
    // *** keyboard ***
#if defined (SDL_USE) || defined (SDL2_USE)
    case SDL_KEYDOWN:
#elif defined (SDL3_USE)
    case SDL_EVENT_KEY_DOWN:
#endif // SDL_USE || SDL2_USE || SDL3_USE
    {
//       ACE_DEBUG((LM_DEBUG,
//                  ACE_TEXT("%s key\n%s\n"),
//                  ((event_in.type == SDL_KEYDOWN) ? ACE_TEXT("pressed") : ACE_TEXT("released")),
//                  ACE_TEXT(RPG_Graphics_SDL_Tools::keyToString(event_in.key.keysym).c_str())));

      switch (event_in.key.keysym.sym)
      {
        case SDLK_ESCAPE:
        {
          struct RPG_Engine_ClientNotificationParameters parameters;
          parameters.entity_id = 0;
          parameters.condition = RPG_COMMON_CONDITION_INVALID;
          //parameters.positions.clear();
          parameters.previous_position =
            std::make_pair (std::numeric_limits<unsigned int>::max (),
                            std::numeric_limits<unsigned int>::max ());
          parameters.visible_radius = 0;
          try {
            myEngine->notify (COMMAND_E2C_QUIT,
                              parameters,
                              true); // locked access ?
          } catch (...) {
            ACE_DEBUG ((LM_ERROR,
                        ACE_TEXT ("caught exception in RPG_Engine_IWindow::notify(\"%s\"), continuing\n"),
                        ACE_TEXT (RPG_Engine_CommandHelper::RPG_Engine_CommandToString (COMMAND_E2C_QUIT).c_str ())));
          }

          break;
        }
        case SDLK_s:
        {
          // sanity check(s)
          ACE_ASSERT (inherited::screen_);
#if defined (SDL_USE)
          SDL_Surface* surface_p = inherited::screen_;
#elif defined (SDL2_USE) || defined (SDL3_USE)
          SDL_Surface* surface_p = SDL_GetWindowSurface (inherited::screen_);
#endif // SDL_USE || SDL2_USE || SDL3_USE
          ACE_ASSERT (surface_p);

          std::ostringstream converter;
          converter << myScreenshotIndex++;
          std::string dump_path =
#if defined (ACE_WIN32) || defined (ACE_WIN64)
            ACE_OS::getenv (ACE_TEXT_ALWAYS_CHAR (COMMON_LOCATION_TEMPORARY_STORAGE_VARIABLE));
#else
            ACE_TEXT_ALWAYS_CHAR (COMMON_LOCATION_TEMPORARY_STORAGE_DIRECTORY);
#endif // ACE_WIN32 || ACE_WIN64
          dump_path += ACE_DIRECTORY_SEPARATOR_CHAR_A;
          dump_path += ACE_TEXT_ALWAYS_CHAR (RPG_CLIENT_SCREENSHOT_DEF_PREFIX);
          dump_path += converter.str ();
          dump_path += ACE_TEXT_ALWAYS_CHAR (RPG_CLIENT_SCREENSHOT_DEF_EXT);

         RPG_Graphics_Surface::savePNG (*surface_p, // image
                                         dump_path, // file
                                         false);    // no alpha

          break;
        }
        default:
          break;
      } // end SWITCH

      break;
    }
#if defined (SDL_USE) || defined (SDL2_USE)
    case SDL_KEYUP:
#elif defined (SDL3_USE)
    case SDL_EVENT_KEY_UP:
#endif // SDL_USE || SDL2_USE || SDL3_USE
    {
//       ACE_DEBUG((LM_DEBUG,
//                  ACE_TEXT("key released...\n")));

      break;
    }
    // *** mouse ***
#if defined (SDL_USE) || defined (SDL2_USE)
    case SDL_MOUSEMOTION:
#elif defined (SDL3_USE)
    case SDL_EVENT_MOUSE_MOTION:
#endif // SDL_USE || SDL2_USE || SDL3_USE
    {
//       ACE_DEBUG((LM_DEBUG,
//                  ACE_TEXT("mouse motion...\n")));

      break;
    }
#if defined (SDL_USE) || defined (SDL2_USE)
    case SDL_MOUSEBUTTONDOWN:
#elif defined (SDL3_USE)
    case SDL_EVENT_MOUSE_BUTTON_DOWN:
#endif // SDL_USE || SDL2_USE || SDL3_USE
    {
//       ACE_DEBUG((LM_DEBUG,
//                  ACE_TEXT("mouse button [%u,%u] pressed\n"),
//                  static_cast<unsigned int>(event_in.button.which),
//                  static_cast<unsigned int>(event_in.button.button)));

      // (left-)clicking on a hotspot (edge) area triggers a scroll of the viewport
      if ((window_in->getType () == WINDOW_HOTSPOT) &&
          (event_in.button.button == 1))
      {
        // retrieve hotspot window handle
        RPG_Graphics_HotSpot* hotspot =
          dynamic_cast<RPG_Graphics_HotSpot*> (window_in);
        ACE_ASSERT (hotspot);

        // retrieve map window handle
        client_action.window = child (WINDOW_MAP);
        RPG_Client_IWindowLevel* level_window =
            dynamic_cast<RPG_Client_IWindowLevel*> (client_action.window);
        ACE_ASSERT (level_window);
        client_action.position = level_window->getView ();
        switch (hotspot->getCursorType ())
        {
          case CURSOR_SCROLL_UL:
          {
            client_action.position.first--;
            client_action.position.second--;
            client_action.position.first--;
            client_action.position.second++;
            break;
          }
          case CURSOR_SCROLL_U:
          {
            client_action.position.first--;
            client_action.position.second--;
            break;
          }
          case CURSOR_SCROLL_UR:
          {
            client_action.position.first--;
            client_action.position.second--;
            client_action.position.first++;
            client_action.position.second--;
            break;
          }
          case CURSOR_SCROLL_L:
          {
            client_action.position.first--;
            client_action.position.second++;
            break;
          }
          case CURSOR_SCROLL_R:
          {
            client_action.position.first++;
            client_action.position.second--;
            break;
          }
          case CURSOR_SCROLL_DL:
          {
            client_action.position.first++;
            client_action.position.second++;
            client_action.position.first--;
            client_action.position.second++;
            break;
          }
          case CURSOR_SCROLL_D:
          {
            client_action.position.first++;
            client_action.position.second++;
            break;
          }
          case CURSOR_SCROLL_DR:
          {
            client_action.position.first++;
            client_action.position.second++;
            client_action.position.first++;
            client_action.position.second--;
            break;
          }
          default:
          {
            ACE_DEBUG ((LM_DEBUG,
                        ACE_TEXT ("invalid/unknown cursor type (was: %s), returning\n"),
                        ACE_TEXT (RPG_Graphics_CursorHelper::RPG_Graphics_CursorToString (hotspot->getCursorType ()).c_str ())));
            return;
          }
        } // end SWITCH
        myEngine->setView (client_action.position,
                           true); // refresh ?
      } // end IF

      break;
    }
#if defined (SDL_USE) || defined (SDL2_USE)
    case SDL_MOUSEBUTTONUP:
#elif defined (SDL3_USE)
    case SDL_EVENT_MOUSE_BUTTON_UP:
#endif // SDL_USE || SDL2_USE || SDL3_USE
    {
//       ACE_DEBUG((LM_DEBUG,
//                  ACE_TEXT("mouse button [%u,%u] released...\n"),
//                  static_cast<unsigned int>(event_in.button.which),
//                  static_cast<unsigned int>(event_in.button.button)));

      break;
    }
    // *** joystick ***
#if defined (SDL_USE) || defined (SDL2_USE)
    case SDL_JOYAXISMOTION:
    case SDL_JOYBALLMOTION:
    case SDL_JOYHATMOTION:
    case SDL_JOYBUTTONDOWN:
    case SDL_JOYBUTTONUP:
#elif defined (SDL3_USE)
    case SDL_EVENT_JOYSTICK_AXIS_MOTION:
    case SDL_EVENT_JOYSTICK_BALL_MOTION:
    case SDL_EVENT_JOYSTICK_HAT_MOTION:
    case SDL_EVENT_JOYSTICK_BUTTON_DOWN:
    case SDL_EVENT_JOYSTICK_BUTTON_UP:
#endif // SDL_USE || SDL2_USE || SDL3_USE
    {
//       ACE_DEBUG((LM_DEBUG,
//                  ACE_TEXT("joystick activity...\n")));

      break;
    }
#if defined (SDL_USE) || defined (SDL2_USE)
    case SDL_QUIT:
#elif defined (SDL3_USE)
    case SDL_EVENT_QUIT:
#endif // SDL_USE || SDL2_USE || SDL3_USE
    {
//       ACE_DEBUG((LM_DEBUG,
//                  ACE_TEXT("SDL_QUIT event...\n")));

      break;
    }
#if defined (SDL_USE) || defined (SDL2_USE)
    case SDL_SYSWMEVENT:
    {
//       ACE_DEBUG((LM_DEBUG,
//                  ACE_TEXT("SDL_SYSWMEVENT event...\n")));

      break;
    }
#endif // SDL_USE || SDL2_USE
#if defined (SDL_USE)
    case SDL_VIDEORESIZE:
    {
//       ACE_DEBUG((LM_DEBUG,
//                  ACE_TEXT("SDL_VIDEORESIZE event...\n")));

      break;
    }
    case SDL_VIDEOEXPOSE:
    {
//       ACE_DEBUG((LM_DEBUG,
//                  ACE_TEXT("SDL_VIDEOEXPOSE event...\n")));

      break;
    }
#elif defined (SDL2_USE)
    case SDL_WINDOWEVENT_RESIZED:
    {
//       ACE_DEBUG((LM_DEBUG,
//                  ACE_TEXT("SDL_WINDOWEVENT_RESIZED event...\n")));

      break;
    }
    case SDL_WINDOWEVENT_EXPOSED:
    {
//       ACE_DEBUG((LM_DEBUG,
//                  ACE_TEXT("SDL_WINDOWEVENT_EXPOSED event...\n")));

      break;
    }
#endif // SDL_USE || SDL2_USE
    case RPG_GRAPHICS_SDL_HOVEREVENT:
    {
//       ACE_DEBUG((LM_DEBUG,
//                  ACE_TEXT("RPG_GRAPHICS_SDL_HOVEREVENT event (%d ms)...\n"),
//                  event_in.user.code));

      // hovering on a hotspot (edge) area may trigger a scroll of the viewport
      if (!myAutoEdgeScroll ||                       // function is disabled
          (window_in->getType () != WINDOW_HOTSPOT)) // not a hotspot
        break;

      if (myLastHoverTime)
      {
        // throttle scrolling
        if ((event_in.user.code - myLastHoverTime) < RPG_GRAPHICS_WINDOW_HOTSPOT_HOVER_SCROLL_DELAY)
          break; // don't scroll this time
      } // end ELSE
      myLastHoverTime = event_in.user.code;

      // retrieve map window handle
      client_action.window = child (WINDOW_MAP);
      RPG_Client_IWindowLevel* level_window =
          dynamic_cast<RPG_Client_IWindowLevel*> (client_action.window);
      ACE_ASSERT (level_window);

      // retrieve hotspot window handle
      RPG_Graphics_HotSpot* hotspot =
        dynamic_cast<RPG_Graphics_HotSpot*> (window_in);
      ACE_ASSERT (hotspot);

      client_action.position = level_window->getView ();
      switch (hotspot->getCursorType ())
      {
        case CURSOR_SCROLL_UL:
        {
          client_action.position.first--;
          client_action.position.second--;
          client_action.position.first--;
          client_action.position.second++;
          break;
        }
        case CURSOR_SCROLL_U:
        {
          client_action.position.first--;
          client_action.position.second--;
          break;
        }
        case CURSOR_SCROLL_UR:
        {
          client_action.position.first--;
          client_action.position.second--;
          client_action.position.first++;
          client_action.position.second--;
          break;
        }
        case CURSOR_SCROLL_L:
        {
          client_action.position.first--;
          client_action.position.second++;
          break;
        }
        case CURSOR_SCROLL_R:
        {
          client_action.position.first++;
          client_action.position.second--;
          break;
        }
        case CURSOR_SCROLL_DL:
        {
          client_action.position.first++;
          client_action.position.second++;
          client_action.position.first--;
          client_action.position.second++;
          break;
        }
        case CURSOR_SCROLL_D:
        {
          client_action.position.first++;
          client_action.position.second++;
          break;
        }
        case CURSOR_SCROLL_DR:
        {
          client_action.position.first++;
          client_action.position.second++;
          client_action.position.first++;
          client_action.position.second--;
          break;
        }
        default:
        {
          ACE_DEBUG ((LM_DEBUG,
                      ACE_TEXT ("invalid/unknown cursor type (was: %s), returning\n"),
                      ACE_TEXT (RPG_Graphics_CursorHelper::RPG_Graphics_CursorToString (hotspot->getCursorType ()).c_str ())));
          return;
        }
      } // end SWITCH
      myEngine->setView (client_action.position,
                         true); // refresh ?

      break;
    }
    case RPG_GRAPHICS_SDL_MOUSEMOVEOUT:
    {
//       ACE_DEBUG((LM_DEBUG,
//                  ACE_TEXT("RPG_GRAPHICS_SDL_MOUSEMOVEOUT event...\n")));

      break;
    }
    default:
    {
      ACE_DEBUG ((LM_ERROR,
                  ACE_TEXT ("received invalid/unknown event (was: %u)...\n"),
                  event_in.type));
      break;
    }
  } // end SWITCH

  // if necessary, reset last hover time
  if (event_in.type != RPG_GRAPHICS_SDL_HOVEREVENT)
    myLastHoverTime = 0;
}

void
RPG_Client_Window_Main::notify (enum RPG_Graphics_Cursor cursor_in) const
{
  RPG_TRACE (ACE_TEXT ("RPG_Client_Window_Main::notify"));

  struct RPG_Client_Action client_action;
  client_action.command = RPG_CLIENT_COMMAND_INVALID;
  client_action.position =
      std::make_pair (std::numeric_limits<unsigned int>::max (),
                      std::numeric_limits<unsigned int>::max ());
  client_action.window = const_cast<RPG_Client_Window_Main*> (this);
  client_action.cursor = cursor_in;
  client_action.entity_id = 0;
  if (cursor_in == RPG_GRAPHICS_CURSOR_INVALID)
    client_action.command = COMMAND_CURSOR_INVALIDATE_BG;
  else
    client_action.command = COMMAND_CURSOR_SET;
  myEngine->action (client_action);
}

void
RPG_Client_Window_Main::initScrollSpots (bool debug_in)
{
  RPG_TRACE(ACE_TEXT("RPG_Client_Window_Main::initScrollSpots"));

  // upper left
  RPG_Graphics_HotSpot::initialize (*this,                                                      // parent
                                    std::make_pair (RPG_GRAPHICS_WINDOW_HOTSPOT_SCROLL_MARGIN,
                                                    RPG_GRAPHICS_WINDOW_HOTSPOT_SCROLL_MARGIN), // size
                                    std::make_pair (0,
                                                    0),                                         // offset
                                    CURSOR_SCROLL_UL,                                           // (hover) cursor graphic
                                    debug_in);                                                  // debug ?
  // up
  RPG_Graphics_HotSpot::initialize (*this,
                                    std::make_pair ((inherited::clipRectangle_.w -
                                                     (2 * RPG_GRAPHICS_WINDOW_HOTSPOT_SCROLL_MARGIN)),
                                                    RPG_GRAPHICS_WINDOW_HOTSPOT_SCROLL_MARGIN),
                                    std::make_pair (RPG_GRAPHICS_WINDOW_HOTSPOT_SCROLL_MARGIN,
                                                    0),
                                    CURSOR_SCROLL_U,
                                    debug_in);

  // upper right
  RPG_Graphics_HotSpot::initialize (*this,
                                    std::make_pair (RPG_GRAPHICS_WINDOW_HOTSPOT_SCROLL_MARGIN,
                                                    RPG_GRAPHICS_WINDOW_HOTSPOT_SCROLL_MARGIN),
                                    std::make_pair (((inherited::clipRectangle_.w - 1) -
                                                     RPG_GRAPHICS_WINDOW_HOTSPOT_SCROLL_MARGIN),
                                                    0),
                                    CURSOR_SCROLL_UR,
                                    debug_in);

  // left
  RPG_Graphics_HotSpot::initialize (*this,
                                    std::make_pair (RPG_GRAPHICS_WINDOW_HOTSPOT_SCROLL_MARGIN,
                                                    (inherited::clipRectangle_.h -
                                                    (2 * RPG_GRAPHICS_WINDOW_HOTSPOT_SCROLL_MARGIN))),
                                    std::make_pair (0,
                                                    RPG_GRAPHICS_WINDOW_HOTSPOT_SCROLL_MARGIN),
                                    CURSOR_SCROLL_L,
                                    debug_in);

  // right
  RPG_Graphics_HotSpot::initialize (*this,
                                    std::make_pair (RPG_GRAPHICS_WINDOW_HOTSPOT_SCROLL_MARGIN,
                                                    (inherited::clipRectangle_.h -
                                                    (2 * RPG_GRAPHICS_WINDOW_HOTSPOT_SCROLL_MARGIN))),
                                    std::make_pair (((inherited::clipRectangle_.w - 1) -
                                                     RPG_GRAPHICS_WINDOW_HOTSPOT_SCROLL_MARGIN),
                                                    RPG_GRAPHICS_WINDOW_HOTSPOT_SCROLL_MARGIN),
                                    CURSOR_SCROLL_R,
                                    debug_in);

  // lower left
  RPG_Graphics_HotSpot::initialize (*this,
                                    std::make_pair (RPG_GRAPHICS_WINDOW_HOTSPOT_SCROLL_MARGIN,
                                                    RPG_GRAPHICS_WINDOW_HOTSPOT_SCROLL_MARGIN),
                                    std::make_pair (0,
                                                    ((inherited::clipRectangle_.h - 1) -
                                                     RPG_GRAPHICS_WINDOW_HOTSPOT_SCROLL_MARGIN)),
                                    CURSOR_SCROLL_DL,
                                    debug_in);

  // down
  RPG_Graphics_HotSpot::initialize (*this,
                                    std::make_pair ((inherited::clipRectangle_.w -
                                                     (2 * RPG_GRAPHICS_WINDOW_HOTSPOT_SCROLL_MARGIN)),
                                                    RPG_GRAPHICS_WINDOW_HOTSPOT_SCROLL_MARGIN),
                                    std::make_pair (RPG_GRAPHICS_WINDOW_HOTSPOT_SCROLL_MARGIN,
                                                    ((inherited::clipRectangle_.h - 1) -
                                                     RPG_GRAPHICS_WINDOW_HOTSPOT_SCROLL_MARGIN)),
                                    CURSOR_SCROLL_D,
                                    debug_in);

  // lower right
  RPG_Graphics_HotSpot::initialize (*this,
                                    std::make_pair (RPG_GRAPHICS_WINDOW_HOTSPOT_SCROLL_MARGIN,
                                                    RPG_GRAPHICS_WINDOW_HOTSPOT_SCROLL_MARGIN),
                                    std::make_pair (((inherited::clipRectangle_.w - 1) -
                                                     RPG_GRAPHICS_WINDOW_HOTSPOT_SCROLL_MARGIN),
                                                    ((inherited::clipRectangle_.h - 1) -
                                                     RPG_GRAPHICS_WINDOW_HOTSPOT_SCROLL_MARGIN)),
                                    CURSOR_SCROLL_DR,
                                    debug_in);
}

bool
RPG_Client_Window_Main::initMap (RPG_Client_Engine* clientEngine_in,
                                 RPG_Engine* engine_in,
                                 bool debug_in)
{
  RPG_TRACE (ACE_TEXT ("RPG_Client_Window_Main::initMap"));

  RPG_Client_IWindowLevel* i_window_level_p = NULL;
  ACE_NEW_NORETURN (i_window_level_p,
                    RPG_Client_Window_Level (*this));
  if (!i_window_level_p)
  {
    ACE_DEBUG ((LM_CRITICAL,
                ACE_TEXT ("failed to allocate memory: \"%m\", aborting\n")));
    return false;
  } // end IF

  // initialize window
  if (!i_window_level_p->initialize (clientEngine_in,
                                     engine_in,
                                     debug_in))
  {
    ACE_DEBUG ((LM_ERROR,
                ACE_TEXT ("failed to RPG_Client_IWindowLevel::initialize(): \"%m\", aborting\n")));
    return false;
  } // end IF

  RPG_Graphics_IWindowBase* i_window_base_p =
    dynamic_cast<RPG_Graphics_IWindowBase*> (i_window_level_p);
  ACE_ASSERT (i_window_base_p);
  i_window_base_p->initializeSDL (inherited::renderer_,
                                  inherited::screen_,
                                  inherited::GLContext_);

  return true;
}

void
RPG_Client_Window_Main::drawBorder (SDL_Surface* targetSurface_in,
                                    unsigned int offsetX_in,
                                    unsigned int offsetY_in)
{
  RPG_TRACE (ACE_TEXT ("RPG_Client_Window_Main::drawBorder"));

  // sanity check(s)
  ACE_ASSERT (inherited::screen_);
#if defined (SDL_USE)
  SDL_Surface* surface_p = inherited::screen_;
#elif defined (SDL2_USE) || defined (SDL3_USE)
  SDL_Surface* surface_p = SDL_GetWindowSurface (inherited::screen_);
#endif // SDL_USE || SDL2_USE || SDL3_USE
  ACE_ASSERT (surface_p);
  SDL_Surface* target_surface =
    (targetSurface_in ? targetSurface_in : surface_p);
  ACE_ASSERT (target_surface);
  ACE_ASSERT (static_cast<int> (offsetX_in) <= target_surface->w);
  ACE_ASSERT (static_cast<int> (offsetY_in) <= target_surface->h);

  RPG_Graphics_InterfaceElementsConstIterator_t iterator;
  struct SDL_Rect prev_clip_rect, clip_rect, dirty_region;
  unsigned int i = 0;

  // step0: save previous clip rectangle
#if defined (SDL_USE) || defined (SDL2_USE)
  SDL_GetClipRect (target_surface, &prev_clip_rect);
#elif defined (SDL3_USE)
  SDL_GetSurfaceClipRect (target_surface, &prev_clip_rect);
#endif // SDL_USE || SDL2_USE || SDL3_USE
  // step1: draw borders
  clip_rect.x = static_cast<int16_t> (offsetX_in + borderLeft_);
  clip_rect.y = static_cast<int16_t> (offsetY_in);
  clip_rect.w = static_cast<uint16_t> (target_surface->w - (borderLeft_ + borderRight_));
  clip_rect.h = static_cast<uint16_t> (borderTop_);
#if defined (SDL_USE) || defined (SDL2_USE)
  if (!SDL_SetClipRect (target_surface, &clip_rect))
#elif defined (SDL3_USE)
  if (!SDL_SetSurfaceClipRect (target_surface, &clip_rect))
#endif // SDL_USE || SDL2_USE || SDL3_USE
  {
    ACE_DEBUG ((LM_ERROR,
                ACE_TEXT ("failed to SDL_SetClipRect(): %s, returning\n"),
                ACE_TEXT (SDL_GetError ())));
    return;
  } // end IF
  iterator = myElementGraphics.find (INTERFACEELEMENT_BORDER_TOP);
  ACE_ASSERT (iterator != myElementGraphics.end ());
  for (i = offsetX_in + borderLeft_;
       i < (static_cast<unsigned int> (target_surface->w) - borderRight_);
       i += (*iterator).second->w)
  {
    RPG_Graphics_Surface::put (std::make_pair (i,
                                               offsetY_in),
                               *(*iterator).second,
                               target_surface,
                               dirty_region);
    inherited::invalidate (dirty_region);
  } // end FOR

  clip_rect.x = static_cast<int16_t> (offsetX_in);
  clip_rect.y = static_cast<int16_t> (offsetY_in + borderTop_);
  clip_rect.w = static_cast<uint16_t> (borderLeft_);
  clip_rect.h = static_cast<uint16_t> (target_surface->h - (borderTop_ + borderBottom_));
#if defined (SDL_USE) || defined (SDL2_USE)
  if (!SDL_SetClipRect (target_surface, &clip_rect))
#elif defined (SDL3_USE)
  if (!SDL_SetSurfaceClipRect (target_surface, &clip_rect))
#endif // SDL_USE || SDL2_USE || SDL3_USE
  {
    ACE_DEBUG ((LM_ERROR,
                ACE_TEXT ("failed to SDL_SetClipRect(): %s, returning\n"),
                ACE_TEXT (SDL_GetError ())));
    return;
  } // end IF
  iterator = myElementGraphics.find (INTERFACEELEMENT_BORDER_LEFT);
  ACE_ASSERT (iterator != myElementGraphics.end ());
  for (i = (offsetY_in + borderTop_);
       i < (static_cast<unsigned int> (target_surface->h) - borderBottom_);
       i += (*iterator).second->h)
  {
    RPG_Graphics_Surface::put (std::make_pair (offsetX_in,
                                               i),
                               *(*iterator).second,
                               target_surface,
                               dirty_region);
    inherited::invalidate (dirty_region);
  } // end FOR

  clip_rect.x = static_cast<int16_t> (target_surface->w - borderRight_);
  clip_rect.y = static_cast<int16_t> (offsetY_in + borderTop_);
  clip_rect.w = static_cast<uint16_t> (borderRight_);
  clip_rect.h = static_cast<uint16_t> (target_surface->h - (borderTop_ + borderBottom_));
#if defined (SDL_USE) || defined (SDL2_USE)
  if (!SDL_SetClipRect (target_surface, &clip_rect))
#elif defined (SDL3_USE)
  if (!SDL_SetSurfaceClipRect (target_surface, &clip_rect))
#endif // SDL_USE || SDL2_USE || SDL3_USE
  {
    ACE_DEBUG ((LM_ERROR,
                ACE_TEXT ("failed to SDL_SetClipRect(): %s, returning\n"),
                ACE_TEXT (SDL_GetError ())));
    return;
  } // end IF
  iterator = myElementGraphics.find (INTERFACEELEMENT_BORDER_RIGHT);
  ACE_ASSERT (iterator != myElementGraphics.end ());
  for (i = (offsetY_in + borderTop_);
       i < (static_cast<unsigned int> (target_surface->h) - borderBottom_);
       i += (*iterator).second->h)
  {
    RPG_Graphics_Surface::put (std::make_pair ((target_surface->w - borderRight_),
                                               i),
                               *(*iterator).second,
                               target_surface,
                               dirty_region);
    inherited::invalidate (dirty_region);
  } // end FOR

  clip_rect.x = static_cast<int16_t> (offsetX_in + borderLeft_);
  clip_rect.y = static_cast<int16_t> (target_surface->h - borderBottom_);
  clip_rect.w = static_cast<uint16_t> (target_surface->w - (borderLeft_ + borderRight_));
  clip_rect.h = static_cast<uint16_t> (borderBottom_);
#if defined (SDL_USE) || defined (SDL2_USE)
  if (!SDL_SetClipRect (target_surface, &clip_rect))
#elif defined (SDL3_USE)
  if (!SDL_SetSurfaceClipRect (target_surface, &clip_rect))
#endif // SDL_USE || SDL2_USE || SDL3_USE
  {
    ACE_DEBUG ((LM_ERROR,
                ACE_TEXT ("failed to SDL_SetClipRect(): %s, returning\n"),
                ACE_TEXT (SDL_GetError ())));
    return;
  } // end IF
  iterator = myElementGraphics.find (INTERFACEELEMENT_BORDER_BOTTOM);
  ACE_ASSERT (iterator != myElementGraphics.end ());
  for (i = (offsetX_in + borderLeft_);
       i < (target_surface->w - borderRight_);
       i += (*iterator).second->w)
  {
    RPG_Graphics_Surface::put (std::make_pair (i,
                                               (target_surface->h - borderBottom_)),
                               *(*iterator).second,
                               target_surface,
                               dirty_region);
    inherited::invalidate (dirty_region);
  } // end FOR

  // step2: draw corners

  // NW
  clip_rect.x = static_cast<int16_t> (offsetX_in);
  clip_rect.y = static_cast<int16_t> (offsetY_in);
  iterator = myElementGraphics.find (INTERFACEELEMENT_BORDER_TOP_LEFT);
  ACE_ASSERT (iterator != myElementGraphics.end ());
  clip_rect.w = static_cast<uint16_t> ((*iterator).second->w);
  clip_rect.h = static_cast<uint16_t> ((*iterator).second->h);
#if defined (SDL_USE) || defined (SDL2_USE)
  if (!SDL_SetClipRect (target_surface, &clip_rect))
#elif defined (SDL3_USE)
  if (!SDL_SetSurfaceClipRect (target_surface, &clip_rect))
#endif // SDL_USE || SDL2_USE || SDL3_USE
  {
    ACE_DEBUG ((LM_ERROR,
                ACE_TEXT ("failed to SDL_SetClipRect(): %s, returning\n"),
                ACE_TEXT (SDL_GetError ())));
    return;
  } // end IF
  RPG_Graphics_Surface::put (std::make_pair (offsetX_in,
                                             offsetY_in),
                             *(*iterator).second,
                             target_surface,
                             dirty_region);
  inherited::invalidate (dirty_region);

  // NE
  clip_rect.y = static_cast<int16_t> (offsetY_in);
  iterator = myElementGraphics.find (INTERFACEELEMENT_BORDER_TOP_RIGHT);
  ACE_ASSERT (iterator != myElementGraphics.end ());
  clip_rect.x = static_cast<int16_t> (target_surface->w - (*iterator).second->w);
  clip_rect.w = static_cast<uint16_t> ((*iterator).second->w);
  clip_rect.h = static_cast<uint16_t> ((*iterator).second->h);
#if defined (SDL_USE) || defined (SDL2_USE)
  if (!SDL_SetClipRect (target_surface, &clip_rect))
#elif defined (SDL3_USE)
  if (!SDL_SetSurfaceClipRect (target_surface, &clip_rect))
#endif // SDL_USE || SDL2_USE || SDL3_USE
  {
    ACE_DEBUG ((LM_ERROR,
                ACE_TEXT ("failed to SDL_SetClipRect(): %s, returning\n"),
                ACE_TEXT (SDL_GetError ())));
    return;
  } // end IF
  RPG_Graphics_Surface::put (std::make_pair (target_surface->w - (*iterator).second->w,
                                             offsetY_in),
                             *(*iterator).second,
                             target_surface,
                             dirty_region);
  inherited::invalidate (dirty_region);

  // SW
  clip_rect.x = static_cast<int16_t> (offsetX_in);
  iterator = myElementGraphics.find (INTERFACEELEMENT_BORDER_BOTTOM_LEFT);
  ACE_ASSERT (iterator != myElementGraphics.end ());
  clip_rect.y = static_cast<int16_t> (target_surface->h - (*iterator).second->h);
  clip_rect.w = static_cast<uint16_t> ((*iterator).second->w);
  clip_rect.h = static_cast<uint16_t> ((*iterator).second->h);
#if defined (SDL_USE) || defined (SDL2_USE)
  if (!SDL_SetClipRect (target_surface, &clip_rect))
#elif defined (SDL3_USE)
  if (!SDL_SetSurfaceClipRect (target_surface, &clip_rect))
#endif // SDL_USE || SDL2_USE || SDL3_USE
  {
    ACE_DEBUG ((LM_ERROR,
                ACE_TEXT ("failed to SDL_SetClipRect(): %s, returning\n"),
                ACE_TEXT (SDL_GetError ())));
    return;
  } // end IF
  RPG_Graphics_Surface::put (std::make_pair (offsetX_in,
                                             target_surface->h - (*iterator).second->h),
                             *(*iterator).second,
                             target_surface,
                             dirty_region);
  inherited::invalidate (dirty_region);

  // SE
  iterator = myElementGraphics.find (INTERFACEELEMENT_BORDER_BOTTOM_RIGHT);
  ACE_ASSERT (iterator != myElementGraphics.end ());
  clip_rect.x = static_cast<int16_t> (target_surface->w - (*iterator).second->w);
  clip_rect.y = static_cast<int16_t> (target_surface->h - (*iterator).second->h);
  clip_rect.w = static_cast<uint16_t> ((*iterator).second->w);
  clip_rect.h = static_cast<uint16_t> ((*iterator).second->h);
#if defined (SDL_USE) || defined (SDL2_USE)
  if (!SDL_SetClipRect (target_surface, &clip_rect))
#elif defined (SDL3_USE)
  if (!SDL_SetSurfaceClipRect (target_surface, &clip_rect))
#endif // SDL_USE || SDL2_USE || SDL3_USE
  {
    ACE_DEBUG ((LM_ERROR,
                ACE_TEXT ("failed to SDL_SetClipRect(): %s, returning\n"),
                ACE_TEXT (SDL_GetError ())));
    return;
  } // end IF
  RPG_Graphics_Surface::put (std::make_pair (target_surface->w - (*iterator).second->w,
                                             target_surface->h - (*iterator).second->h),
                             *(*iterator).second,
                             target_surface,
                             dirty_region);
  inherited::invalidate (dirty_region);

#if defined (SDL_USE) || defined (SDL2_USE)
  if (!SDL_SetClipRect (target_surface, &prev_clip_rect))
#elif defined (SDL3_USE)
  if (!SDL_SetSurfaceClipRect (target_surface, &prev_clip_rect))
#endif // SDL_USE || SDL2_USE || SDL3_USE
  {
    ACE_DEBUG ((LM_ERROR,
                ACE_TEXT ("failed to SDL_SetClipRect(): %s, returning\n"),
                ACE_TEXT (SDL_GetError ())));
    return;
  } // end IF
}
