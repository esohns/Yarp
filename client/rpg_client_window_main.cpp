/***************************************************************************
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
#include "rpg_client_window_main.h"

#include "rpg_client_defines.h"
#include "rpg_client_window_level.h"

#include <rpg_graphics_defines.h>
#include <rpg_graphics_surface.h>
#include <rpg_graphics_cursor_manager.h>
#include <rpg_graphics_hotspot.h>
#include <rpg_graphics_common_tools.h>
#include <rpg_graphics_SDL_tools.h>

#include <rpg_common_macros.h>

#include <ace/Log_Msg.h>

#include <sstream>

RPG_Client_WindowMain::RPG_Client_WindowMain(const RPG_Graphics_WindowSize_t& size_in,
                                             const RPG_Graphics_GraphicTypeUnion& elementType_in,
                                             const std::string& title_in,
                                             const RPG_Graphics_Font& font_in)
 : inherited(size_in,        // size
             elementType_in, // element type
             title_in,       // title
             NULL),          // background
   myScreenshotIndex(1),
   myLastHoverTime(0),
   myHaveMouseFocus(true), // *NOTE*: enforced with SDL_WarpMouse()
   myTitleFont(font_in)
{
  RPG_TRACE(ACE_TEXT("RPG_Client_WindowMain::RPG_Client_WindowMain"));

}

RPG_Client_WindowMain::~RPG_Client_WindowMain()
{
  RPG_TRACE(ACE_TEXT("RPG_Client_WindowMain::~RPG_Client_WindowMain"));

}

void
RPG_Client_WindowMain::init()
{
  RPG_TRACE(ACE_TEXT("RPG_Client_WindowMain::init"));

  // init scroll margins
  initScrollSpots();
}

void
RPG_Client_WindowMain::draw(SDL_Surface* targetSurface_in,
                         const unsigned long& offsetX_in,
                         const unsigned long& offsetY_in)
{
  RPG_TRACE(ACE_TEXT("RPG_Client_WindowMain::draw"));

  // set target surface
  SDL_Surface* targetSurface = (targetSurface_in ? targetSurface_in : myScreen);

  // sanity check(s)
  ACE_ASSERT(targetSurface);
  ACE_ASSERT(static_cast<int> (offsetX_in) <= targetSurface->w);
  ACE_ASSERT(static_cast<int> (offsetY_in) <= targetSurface->h);

  // step1: draw borders
  drawBorder(targetSurface,
             offsetX_in,
             offsetY_in);

  // step2: fill central area
  SDL_Rect clipRect;
  clipRect.x = offsetX_in + myBorderLeft;
  clipRect.y = offsetY_in + myBorderTop;
  clipRect.w = (targetSurface->w - offsetX_in - (myBorderLeft + myBorderRight));
  clipRect.h = (targetSurface->h - offsetY_in - (myBorderTop + myBorderBottom));
  if (!SDL_SetClipRect(targetSurface, &clipRect))
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to SDL_SetClipRect(): %s, aborting\n"),
               SDL_GetError()));

    return;
  } // end IF
  RPG_Graphics_InterfaceElementsConstIterator_t iterator;
  iterator = myElementGraphics.find(INTERFACEELEMENT_BORDER_CENTER);
  ACE_ASSERT(iterator != myElementGraphics.end());
  for (unsigned long i = (offsetY_in + myBorderTop);
       i < (targetSurface->h - myBorderBottom);
       i += (*iterator).second->h)
    for (unsigned long j = (offsetX_in + myBorderLeft);
         j < (targetSurface->w - myBorderRight);
         j += (*iterator).second->w)
      RPG_Graphics_Surface::put(j,
                                i,
                                *(*iterator).second,
                                targetSurface);
  invalidate(clipRect);
  if (!SDL_SetClipRect(targetSurface, NULL))
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to SDL_SetClipRect(): %s, aborting\n"),
               SDL_GetError()));

    return;
  } // end IF

  // step3: draw title (if any)
  if (!myTitle.empty())
  {
    clipRect.x = myBorderLeft;
    clipRect.y = 0;
    clipRect.w = targetSurface->w - offsetX_in - (myBorderLeft + myBorderRight);
    clipRect.h = myBorderTop;
    if (!SDL_SetClipRect(targetSurface, &clipRect))
    {
      ACE_DEBUG((LM_ERROR,
                 ACE_TEXT("failed to SDL_SetClipRect(): %s, aborting\n"),
                 SDL_GetError()));

      return;
    } // end IF

    RPG_Graphics_TextSize_t title_size = RPG_Graphics_Common_Tools::textSize(myTitleFont,
                                                                             myTitle);
    RPG_Graphics_Surface::putText(myTitleFont,
                                  myTitle,
                                  RPG_Graphics_SDL_Tools::colorToSDLColor(RPG_GRAPHICS_FONT_DEF_COLOR,
                                                                          *targetSurface),
                                  true, // add shade
                                  RPG_Graphics_SDL_Tools::colorToSDLColor(RPG_GRAPHICS_FONT_DEF_SHADECOLOR,
                                                                          *targetSurface),
                                  myBorderLeft, // top left
                                  ((myBorderTop - title_size.second) / 2), // center of top border
                                  targetSurface);
    invalidate(clipRect);
    if (!SDL_SetClipRect(targetSurface, NULL))
    {
      ACE_DEBUG((LM_ERROR,
                 ACE_TEXT("failed to SDL_SetClipRect(): %s, aborting\n"),
                 SDL_GetError()));

      return;
    } // end IF
  } // end IF

  // init clipping
  clip(targetSurface,
       offsetX_in,
       offsetY_in);

  // step4: realize hotspots (and any other children)
  for (RPG_Graphics_WindowsIterator_t iterator = myChildren.begin();
       iterator != myChildren.end();
       iterator++)
  {
    try
    {
      (*iterator)->draw(targetSurface,
                        offsetX_in,
                        offsetY_in);
    }
    catch (...)
    {
      ACE_DEBUG((LM_ERROR,
                 ACE_TEXT("caught exception in RPG_Graphics_IWindow::draw(), continuing\n")));
    }
  } // end FOR

  // restore previous clipping area
  unclip(targetSurface);

//   // whole window needs a refresh...
//   SDL_Rect dirtyRegion;
//   dirtyRegion.x = offsetX_in + myBorderLeft + myOffset.first;
//   dirtyRegion.y = offsetY_in + myBorderTop + myOffset.second;
//   dirtyRegion.w = (targetSurface->w - offsetX_in - (myBorderLeft + myBorderRight) - myOffset.first);
//   dirtyRegion.h = (targetSurface->h - offsetY_in - (myBorderTop + myBorderBottom) - myOffset.second);
//   invalidate(dirtyRegion);

  // remember position of last realization
  myLastAbsolutePosition = std::make_pair(offsetX_in,
                                          offsetY_in);
}

void
RPG_Client_WindowMain::handleEvent(const SDL_Event& event_in,
                                RPG_Graphics_IWindow* window_in,
                                bool& redraw_out)
{
  RPG_TRACE(ACE_TEXT("RPG_Client_WindowMain::handleEvent"));

  // init return value(s)
  redraw_out = false;

//   ACE_DEBUG((LM_DEBUG,
//              ACE_TEXT("RPG_Client_WindowMain::handleEvent\n")));

  switch (event_in.type)
  {
    // *** visibility ***
    case SDL_ACTIVEEVENT:
    {
      if (event_in.active.state & SDL_APPMOUSEFOCUS)
      {
        if (event_in.active.gain & SDL_APPMOUSEFOCUS)
        {
//           ACE_DEBUG((LM_DEBUG,
//                      ACE_TEXT("gained mouse coverage...\n")));

          // --> restore background
          SDL_Rect dirtyRegion;
          RPG_GRAPHICS_CURSOR_MANAGER_SINGLETON::instance()->restoreBG(myScreen,
                                                                       dirtyRegion);
          //             invalidate(dirtyRegion);
          // *NOTE*: updating straight away reduces ugly smears...
          RPG_Graphics_Surface::update(dirtyRegion,
                                       myScreen);

          // *HACK*: prevents MOST "mouse trails" (NW borders)...
          drawBorder(myScreen,
                     0,
                     0);
          refresh();

          myHaveMouseFocus = true;
        } // end IF
        else
        {
//           ACE_DEBUG((LM_DEBUG,
//                      ACE_TEXT("lost mouse coverage...\n")));

          // *HACK*: prevents MOST "mouse trails" (NW borders)...
          drawBorder(myScreen,
                     0,
                     0);
          refresh();

          myHaveMouseFocus = false;
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

      break;
    }
    // *** keyboard ***
    case SDL_KEYDOWN:
    {
//       ACE_DEBUG((LM_DEBUG,
//                  ACE_TEXT("%s key\n%s\n"),
//                  ((event_in.type == SDL_KEYDOWN) ? ACE_TEXT("pressed") : ACE_TEXT("released")),
//                  RPG_Graphics_SDL_Tools::keyToString(event_in.key.keysym).c_str()));

      switch (event_in.key.keysym.sym)
      {
        case SDLK_s:
        {
          std::ostringstream converter;
          converter << myScreenshotIndex++;
          std::string dump_path = RPG_GRAPHICS_DEF_DUMP_DIR;
          dump_path += ACE_DIRECTORY_SEPARATOR_STR;
          dump_path += ACE_TEXT("screenshot_");
          dump_path += converter.str();
          dump_path += ACE_TEXT(".png");
          RPG_Graphics_Surface::savePNG(*SDL_GetVideoSurface(), // image
                                        dump_path,              // file
                                        false);                 // no alpha

          break;
        }
        default:
        {

          break;
        }
      } // end SWITCH

      break;
    }
    case SDL_KEYUP:
    {
      ACE_DEBUG((LM_DEBUG,
                 ACE_TEXT("key released...\n")));

      break;
    }
    // *** mouse ***
    case SDL_MOUSEMOTION:
    {
//       ACE_DEBUG((LM_DEBUG,
//                  ACE_TEXT("mouse motion...\n")));

//       // (re-)draw the cursor
//       SDL_Rect dirtyRegion;
//       RPG_GRAPHICS_CURSOR_SINGLETON::instance()->put(event_in.motion.x,
//                                                      event_in.motion.y,
//                                                      myScreen,
//                                                      dirtyRegion);
//       myDirtyRegions.push_back(dirtyRegion);
//
//       // show changes
//       refresh();

      break;
    }
    case SDL_MOUSEBUTTONDOWN:
    {
//       ACE_DEBUG((LM_DEBUG,
//                  ACE_TEXT("mouse button [%u,%u] pressed\n"),
//                  static_cast<unsigned long> (event_in.button.which),
//                  static_cast<unsigned long> (event_in.button.button)));

      // (left-)clicking on a hotspot (edge) area triggers a scroll of the viewport
      if ((window_in->getType() == WINDOWTYPE_HOTSPOT) &&
          (event_in.button.button == 1))
      {
        // retrieve hotspot window handle
        RPG_Graphics_HotSpot* hotspot = NULL;
        hotspot = dynamic_cast<RPG_Graphics_HotSpot*> (window_in);
        if (!hotspot)
        {
          ACE_DEBUG((LM_ERROR,
                    ACE_TEXT("dynamic downcast failed, aborting\n")));

          break;
        } // end IF

        // retrieve map window handle
        RPG_Graphics_WindowsConstIterator_t iterator = myChildren.begin();
        for (;
             iterator != myChildren.end();
             iterator++)
        {
          if ((*iterator)->getType() == WINDOWTYPE_MAP)
            break;
        } // end FOR
        ACE_ASSERT((*iterator)->getType() == WINDOWTYPE_MAP);
        RPG_Client_WindowLevel* levelWindow = NULL;
        levelWindow = dynamic_cast<RPG_Client_WindowLevel*> (*iterator);
        if (!levelWindow)
        {
          ACE_DEBUG((LM_ERROR,
                    ACE_TEXT("dynamic downcast failed, aborting\n")));

          break;
        } // end IF

        switch (hotspot->getCursorType())
        {
          case CURSOR_SCROLL_UL:
          {
            levelWindow->setView(-RPG_GRAPHICS_WINDOW_SCROLL_OFFSET,
                                 -RPG_GRAPHICS_WINDOW_SCROLL_OFFSET);
            levelWindow->setView(-RPG_GRAPHICS_WINDOW_SCROLL_OFFSET,
                                 RPG_GRAPHICS_WINDOW_SCROLL_OFFSET);

            break;
          }
          case CURSOR_SCROLL_U:
          {
            levelWindow->setView(-RPG_GRAPHICS_WINDOW_SCROLL_OFFSET,
                                 -RPG_GRAPHICS_WINDOW_SCROLL_OFFSET);

            break;
          }
          case CURSOR_SCROLL_UR:
          {
            levelWindow->setView(-RPG_GRAPHICS_WINDOW_SCROLL_OFFSET,
                                 -RPG_GRAPHICS_WINDOW_SCROLL_OFFSET);
            levelWindow->setView(RPG_GRAPHICS_WINDOW_SCROLL_OFFSET,
                                 -RPG_GRAPHICS_WINDOW_SCROLL_OFFSET);

            break;
          }
          case CURSOR_SCROLL_L:
          {
            levelWindow->setView(-RPG_GRAPHICS_WINDOW_SCROLL_OFFSET,
                                 RPG_GRAPHICS_WINDOW_SCROLL_OFFSET);

            break;
          }
          case CURSOR_SCROLL_R:
          {
            levelWindow->setView(RPG_GRAPHICS_WINDOW_SCROLL_OFFSET,
                                 -RPG_GRAPHICS_WINDOW_SCROLL_OFFSET);

            break;
          }
          case CURSOR_SCROLL_DL:
          {
            levelWindow->setView(RPG_GRAPHICS_WINDOW_SCROLL_OFFSET,
                                 RPG_GRAPHICS_WINDOW_SCROLL_OFFSET);
            levelWindow->setView(-RPG_GRAPHICS_WINDOW_SCROLL_OFFSET,
                                 RPG_GRAPHICS_WINDOW_SCROLL_OFFSET);

            break;
          }
          case CURSOR_SCROLL_D:
          {
            levelWindow->setView(RPG_GRAPHICS_WINDOW_SCROLL_OFFSET,
                                 RPG_GRAPHICS_WINDOW_SCROLL_OFFSET);

            break;
          }
          case CURSOR_SCROLL_DR:
          {
            levelWindow->setView(RPG_GRAPHICS_WINDOW_SCROLL_OFFSET,
                                 RPG_GRAPHICS_WINDOW_SCROLL_OFFSET);
            levelWindow->setView(RPG_GRAPHICS_WINDOW_SCROLL_OFFSET,
                                 -RPG_GRAPHICS_WINDOW_SCROLL_OFFSET);

            break;
          }
          default:
          {
            ACE_DEBUG((LM_DEBUG,
                       ACE_TEXT("invalid/unknown cursor type (was: %s), aborting\n"),
                       RPG_Graphics_CursorHelper::RPG_Graphics_CursorToString(hotspot->getCursorType()).c_str()));

            return;
          }
        } // end SWITCH

//         // *NOTE*: fiddling with the view invalidates the cursor BG !
//         RPG_GRAPHICS_CURSOR_SINGLETON::instance()->invalidateBG();

        // need a redraw
        redraw_out = true;

  //       ACE_DEBUG((LM_DEBUG,
  //                  ACE_TEXT("scrolled map (%s)...\n"),
  //                  RPG_Graphics_TypeHelper::RPG_Graphics_TypeToString(hotspot->getHotSpotType()).c_str()));
      } // end IF

      break;
    }
    case SDL_MOUSEBUTTONUP:
    {
      ACE_DEBUG((LM_DEBUG,
                 ACE_TEXT("mouse button [%u,%u] released...\n"),
                 static_cast<unsigned long> (event_in.button.which),
                 static_cast<unsigned long> (event_in.button.button)));

      break;
    }
    // *** joystick ***
    case SDL_JOYAXISMOTION:
    case SDL_JOYBALLMOTION:
    case SDL_JOYHATMOTION:
    case SDL_JOYBUTTONDOWN:
    case SDL_JOYBUTTONUP:
    {
      ACE_DEBUG((LM_DEBUG,
                 ACE_TEXT("joystick activity...\n")));

      break;
    }
    case SDL_QUIT:
    {
      ACE_DEBUG((LM_DEBUG,
                 ACE_TEXT("SDL_QUIT event...\n")));

      break;
    }
    case SDL_SYSWMEVENT:
    {
      ACE_DEBUG((LM_DEBUG,
                 ACE_TEXT("SDL_SYSWMEVENT event...\n")));

      break;
    }
    case SDL_VIDEORESIZE:
    {
      ACE_DEBUG((LM_DEBUG,
                 ACE_TEXT("SDL_VIDEORESIZE event...\n")));

      break;
    }
    case SDL_VIDEOEXPOSE:
    {
      ACE_DEBUG((LM_DEBUG,
                 ACE_TEXT("SDL_VIDEOEXPOSE event...\n")));

      break;
    }
    case RPG_GRAPHICS_SDL_HOVEREVENT:
    {
//       ACE_DEBUG((LM_DEBUG,
//                  ACE_TEXT("RPG_GRAPHICS_SDL_HOVEREVENT event (%d ms)...\n"),
//                  event_in.user.code));

      // don't hover if we've lost the mouse in the meantime...
      if (!myHaveMouseFocus)
        break;

      // hovering on a hotspot (edge) area triggers a scroll of the viewport
      if (window_in == this)
        break; // not a hotspot

      // sanity check
      ACE_ASSERT(window_in->getType() == WINDOWTYPE_HOTSPOT);

      // retrieve hotspot window handle
      RPG_Graphics_HotSpot* hotspot = NULL;
      hotspot = dynamic_cast<RPG_Graphics_HotSpot*> (window_in);
      if (!hotspot)
      {
        ACE_DEBUG((LM_ERROR,
                   ACE_TEXT("dynamic downcast failed, aborting\n")));

        break;
      } // end IF

      // retrieve map window handle
      RPG_Graphics_WindowsConstIterator_t iterator = myChildren.begin();
      for (;
           iterator != myChildren.end();
           iterator++)
      {
        if ((*iterator)->getType() == WINDOWTYPE_MAP)
          break;
      } // end FOR
      ACE_ASSERT((*iterator)->getType() == WINDOWTYPE_MAP);
      RPG_Client_WindowLevel* levelWindow = NULL;
      levelWindow = dynamic_cast<RPG_Client_WindowLevel*> (*iterator);
      if (!levelWindow)
      {
        ACE_DEBUG((LM_ERROR,
                   ACE_TEXT("dynamic downcast failed, aborting\n")));

        break;
      } // end IF

      if (myLastHoverTime)
      {
        // throttle scrolling
        if ((event_in.user.code - myLastHoverTime) < RPG_GRAPHICS_WINDOW_HOTSPOT_HOVER_SCROLL_DELAY)
          break; // don't scroll this time
      } // end ELSE
      myLastHoverTime = event_in.user.code;

      switch (hotspot->getCursorType())
      {
        case CURSOR_SCROLL_UL:
        {
          levelWindow->setView(-RPG_GRAPHICS_WINDOW_SCROLL_OFFSET,
                               -RPG_GRAPHICS_WINDOW_SCROLL_OFFSET);
          levelWindow->setView(-RPG_GRAPHICS_WINDOW_SCROLL_OFFSET,
                               RPG_GRAPHICS_WINDOW_SCROLL_OFFSET);

          break;
        }
        case CURSOR_SCROLL_U:
        {
          levelWindow->setView(-RPG_GRAPHICS_WINDOW_SCROLL_OFFSET,
                               -RPG_GRAPHICS_WINDOW_SCROLL_OFFSET);

          break;
        }
        case CURSOR_SCROLL_UR:
        {
          levelWindow->setView(-RPG_GRAPHICS_WINDOW_SCROLL_OFFSET,
                               -RPG_GRAPHICS_WINDOW_SCROLL_OFFSET);
          levelWindow->setView(RPG_GRAPHICS_WINDOW_SCROLL_OFFSET,
                               -RPG_GRAPHICS_WINDOW_SCROLL_OFFSET);

          break;
        }
        case CURSOR_SCROLL_L:
        {
          levelWindow->setView(-RPG_GRAPHICS_WINDOW_SCROLL_OFFSET,
                               RPG_GRAPHICS_WINDOW_SCROLL_OFFSET);

          break;
        }
        case CURSOR_SCROLL_R:
        {
          levelWindow->setView(RPG_GRAPHICS_WINDOW_SCROLL_OFFSET,
                               -RPG_GRAPHICS_WINDOW_SCROLL_OFFSET);

          break;
        }
        case CURSOR_SCROLL_DL:
        {
          levelWindow->setView(RPG_GRAPHICS_WINDOW_SCROLL_OFFSET,
                               RPG_GRAPHICS_WINDOW_SCROLL_OFFSET);
          levelWindow->setView(-RPG_GRAPHICS_WINDOW_SCROLL_OFFSET,
                               RPG_GRAPHICS_WINDOW_SCROLL_OFFSET);

          break;
        }
        case CURSOR_SCROLL_D:
        {
          levelWindow->setView(RPG_GRAPHICS_WINDOW_SCROLL_OFFSET,
                               RPG_GRAPHICS_WINDOW_SCROLL_OFFSET);

          break;
        }
        case CURSOR_SCROLL_DR:
        {
          levelWindow->setView(RPG_GRAPHICS_WINDOW_SCROLL_OFFSET,
                               RPG_GRAPHICS_WINDOW_SCROLL_OFFSET);
          levelWindow->setView(RPG_GRAPHICS_WINDOW_SCROLL_OFFSET,
                               -RPG_GRAPHICS_WINDOW_SCROLL_OFFSET);

          break;
        }
        default:
        {
          ACE_DEBUG((LM_DEBUG,
                     ACE_TEXT("invalid/unknown cursor type (was: %s), aborting\n"),
                     RPG_Graphics_CursorHelper::RPG_Graphics_CursorToString(hotspot->getCursorType()).c_str()));

          return;
        }
      } // end SWITCH

//       // *NOTE*: fiddling with the view invalidates the cursor BG !
//       RPG_GRAPHICS_CURSOR_MANAGER_SINGLETON::instance()->invalidateBG();

      // need a redraw
      redraw_out = true;

//       ACE_DEBUG((LM_DEBUG,
//                  ACE_TEXT("scrolled map (%s)...\n"),
//                  RPG_Graphics_TypeHelper::RPG_Graphics_TypeToString(hotspot->getHotSpotType()).c_str()));

      break;
    }
    case RPG_GRAPHICS_SDL_MOUSEMOVEOUT:
    {
//       ACE_DEBUG((LM_DEBUG,
//                  ACE_TEXT("RPG_GRAPHICS_SDL_MOUSEMOVEOUT event...\n")));

//       // --> restore background
//       SDL_Rect dirtyRegion;
//       RPG_GRAPHICS_CURSOR_SINGLETON::instance()->restore(myScreen,
//                                               dirtyRegion);
// //           RPG_Graphics_Surface::update(dirtyRegion,
// //                                        myScreen);

      break;
    }
    default:
    {
      ACE_DEBUG((LM_ERROR,
                 ACE_TEXT("received unknown event (was: %u)...\n"),
                 static_cast<unsigned long> (event_in.type)));

      break;
    }
  } // end SWITCH

  // if necessary, reset last hover time
  if (event_in.type != RPG_GRAPHICS_SDL_HOVEREVENT)
    myLastHoverTime = 0;
}

void
RPG_Client_WindowMain::initScrollSpots()
{
  RPG_TRACE(ACE_TEXT("RPG_Client_WindowMain::initScrollSpots"));

  // upper left
  RPG_Graphics_HotSpot::init(*this,                  // parent
                             std::make_pair(RPG_GRAPHICS_WINDOW_HOTSPOT_SCROLL_MARGIN,
                                            RPG_GRAPHICS_WINDOW_HOTSPOT_SCROLL_MARGIN), // size
                             std::make_pair(0,
                                            0),      // offset
                             CURSOR_SCROLL_UL); // (hover) cursor graphic
  // up
  RPG_Graphics_HotSpot::init(*this,                 // parent
                             std::make_pair(mySize.first - (2 * RPG_GRAPHICS_WINDOW_HOTSPOT_SCROLL_MARGIN),
                                            RPG_GRAPHICS_WINDOW_HOTSPOT_SCROLL_MARGIN), // size
                             std::make_pair(RPG_GRAPHICS_WINDOW_HOTSPOT_SCROLL_MARGIN,
                                            0),     // offset
                             CURSOR_SCROLL_U); // (hover) cursor graphic
  // upper right
  RPG_Graphics_HotSpot::init(*this,                  // parent
                             std::make_pair(RPG_GRAPHICS_WINDOW_HOTSPOT_SCROLL_MARGIN,
                                            RPG_GRAPHICS_WINDOW_HOTSPOT_SCROLL_MARGIN), // size
                             std::make_pair(mySize.first - RPG_GRAPHICS_WINDOW_HOTSPOT_SCROLL_MARGIN,
                                            0),      // offset
                             CURSOR_SCROLL_UR); // (hover) cursor graphic
  // left
  RPG_Graphics_HotSpot::init(*this,                 // parent
                             std::make_pair(RPG_GRAPHICS_WINDOW_HOTSPOT_SCROLL_MARGIN,
                                            mySize.second - (2 * RPG_GRAPHICS_WINDOW_HOTSPOT_SCROLL_MARGIN)), // size
                             std::make_pair(0,
                                            RPG_GRAPHICS_WINDOW_HOTSPOT_SCROLL_MARGIN), // offset
                             CURSOR_SCROLL_L); // (hover) cursor graphic
  // right
  RPG_Graphics_HotSpot::init(*this,                 // parent
                             std::make_pair(RPG_GRAPHICS_WINDOW_HOTSPOT_SCROLL_MARGIN,
                                            mySize.second - (2 * RPG_GRAPHICS_WINDOW_HOTSPOT_SCROLL_MARGIN)), // size
                             std::make_pair(mySize.first - RPG_GRAPHICS_WINDOW_HOTSPOT_SCROLL_MARGIN,
                                            RPG_GRAPHICS_WINDOW_HOTSPOT_SCROLL_MARGIN), // offset
                             CURSOR_SCROLL_R); // (hover) cursor graphic
  // lower left
  RPG_Graphics_HotSpot::init(*this,                  // parent
                             std::make_pair(RPG_GRAPHICS_WINDOW_HOTSPOT_SCROLL_MARGIN,
                                            RPG_GRAPHICS_WINDOW_HOTSPOT_SCROLL_MARGIN), // size
                             std::make_pair(0,
                                            mySize.second - RPG_GRAPHICS_WINDOW_HOTSPOT_SCROLL_MARGIN), // offset
                             CURSOR_SCROLL_DL); // (hover) cursor graphic
  // down
  RPG_Graphics_HotSpot::init(*this,                 // parent
                             std::make_pair(mySize.first - (2 * RPG_GRAPHICS_WINDOW_HOTSPOT_SCROLL_MARGIN),
                                            RPG_GRAPHICS_WINDOW_HOTSPOT_SCROLL_MARGIN), // size
                             std::make_pair(RPG_GRAPHICS_WINDOW_HOTSPOT_SCROLL_MARGIN,
                                            mySize.second - RPG_GRAPHICS_WINDOW_HOTSPOT_SCROLL_MARGIN), // offset
                             CURSOR_SCROLL_D); // (hover) cursor graphic
  // lower right
  RPG_Graphics_HotSpot::init(*this,                  // parent
                             std::make_pair(RPG_GRAPHICS_WINDOW_HOTSPOT_SCROLL_MARGIN,
                                            RPG_GRAPHICS_WINDOW_HOTSPOT_SCROLL_MARGIN), // size
                             std::make_pair(mySize.first - RPG_GRAPHICS_WINDOW_HOTSPOT_SCROLL_MARGIN,
                                            mySize.second - RPG_GRAPHICS_WINDOW_HOTSPOT_SCROLL_MARGIN), // offset
                             CURSOR_SCROLL_DR); // (hover) cursor graphic
}

void
RPG_Client_WindowMain::drawBorder(SDL_Surface* targetSurface_in,
                               const unsigned long& offsetX_in,
                               const unsigned long& offsetY_in)
{
  RPG_TRACE(ACE_TEXT("RPG_Client_WindowMain::drawBorder"));

  // set target surface
  SDL_Surface* targetSurface = (targetSurface_in ? targetSurface_in : myScreen);

  // sanity check(s)
  ACE_ASSERT(targetSurface);
  ACE_ASSERT(static_cast<int> (offsetX_in) <= targetSurface->w);
  ACE_ASSERT(static_cast<int> (offsetY_in) <= targetSurface->h);

  RPG_Graphics_InterfaceElementsConstIterator_t iterator;
  SDL_Rect prev_clipRect, clipRect;
  unsigned long i = 0;

  // step0: save previous clipRect
  SDL_GetClipRect(targetSurface, &prev_clipRect);

  // step1: draw borders
  clipRect.x = offsetX_in + myBorderLeft;
  clipRect.y = offsetY_in;
  clipRect.w = (targetSurface->w - (myBorderLeft + myBorderRight));
  clipRect.h = myBorderTop;
  if (!SDL_SetClipRect(targetSurface, &clipRect))
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to SDL_SetClipRect(): %s, aborting\n"),
               SDL_GetError()));

    return;
  } // end IF
  iterator = myElementGraphics.find(INTERFACEELEMENT_BORDER_TOP);
  ACE_ASSERT(iterator != myElementGraphics.end());
  for (i = offsetX_in + myBorderLeft;
       i < (static_cast<unsigned long> (targetSurface->w) - myBorderRight);
       i += (*iterator).second->w)
    RPG_Graphics_Surface::put(i,
                              offsetY_in,
                              *(*iterator).second,
                              targetSurface);
  invalidate(clipRect);

  clipRect.x = offsetX_in;
  clipRect.y = (offsetY_in + myBorderTop);
  clipRect.w = myBorderLeft;
  clipRect.h = (targetSurface->h - (myBorderTop + myBorderBottom));
  if (!SDL_SetClipRect(targetSurface, &clipRect))
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to SDL_SetClipRect(): %s, aborting\n"),
               SDL_GetError()));

    return;
  } // end IF
  iterator = myElementGraphics.find(INTERFACEELEMENT_BORDER_LEFT);
  ACE_ASSERT(iterator != myElementGraphics.end());
  for (i = (offsetY_in + myBorderTop);
       i < (static_cast<unsigned long> (targetSurface->h) - myBorderBottom);
       i += (*iterator).second->h)
    RPG_Graphics_Surface::put(offsetX_in,
                              i,
                              *(*iterator).second,
                              targetSurface);
  invalidate(clipRect);

  clipRect.x = (targetSurface->w - myBorderRight);
  clipRect.y = offsetY_in + myBorderTop;
  clipRect.w = myBorderRight;
  clipRect.h = (targetSurface->h - (myBorderTop + myBorderBottom));
  if (!SDL_SetClipRect(targetSurface, &clipRect))
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to SDL_SetClipRect(): %s, aborting\n"),
               SDL_GetError()));

    return;
  } // end IF
  iterator = myElementGraphics.find(INTERFACEELEMENT_BORDER_RIGHT);
  ACE_ASSERT(iterator != myElementGraphics.end());
  for (i = (offsetY_in + myBorderTop);
       i < (static_cast<unsigned long> (targetSurface->h) - myBorderBottom);
       i += (*iterator).second->h)
    RPG_Graphics_Surface::put((targetSurface->w - myBorderRight),
                               i,
                               *(*iterator).second,
                               targetSurface);
  invalidate(clipRect);

  clipRect.x = offsetX_in + myBorderLeft;
  clipRect.y = (targetSurface->h - myBorderBottom);
  clipRect.w = (targetSurface->w - (myBorderLeft + myBorderRight));
  clipRect.h = myBorderBottom;
  if (!SDL_SetClipRect(targetSurface, &clipRect))
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to SDL_SetClipRect(): %s, aborting\n"),
               SDL_GetError()));

    return;
  } // end IF
  iterator = myElementGraphics.find(INTERFACEELEMENT_BORDER_BOTTOM);
  ACE_ASSERT(iterator != myElementGraphics.end());
  for (i = (offsetX_in + myBorderLeft);
       i < (targetSurface->w - myBorderRight);
       i += (*iterator).second->w)
    RPG_Graphics_Surface::put(i,
                              (targetSurface->h - myBorderBottom),
                              *(*iterator).second,
                              targetSurface);
  invalidate(clipRect);

  // step2: draw corners

  // NW
  clipRect.x = offsetX_in;
  clipRect.y = offsetY_in;
  iterator = myElementGraphics.find(INTERFACEELEMENT_BORDER_TOP_LEFT);
  ACE_ASSERT(iterator != myElementGraphics.end());
  clipRect.w = (*iterator).second->w;
  clipRect.h = (*iterator).second->h;
  if (!SDL_SetClipRect(targetSurface, &clipRect))
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to SDL_SetClipRect(): %s, aborting\n"),
               SDL_GetError()));

    return;
  } // end IF
  RPG_Graphics_Surface::put(offsetX_in,
                            offsetY_in,
                            *(*iterator).second,
                            targetSurface);
  invalidate(clipRect);

  // NE
  clipRect.y = offsetY_in;
  iterator = myElementGraphics.find(INTERFACEELEMENT_BORDER_TOP_RIGHT);
  ACE_ASSERT(iterator != myElementGraphics.end());
  clipRect.x = (targetSurface->w - (*iterator).second->w);
  clipRect.w = (*iterator).second->w;
  clipRect.h = (*iterator).second->h;
  if (!SDL_SetClipRect(targetSurface, &clipRect))
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to SDL_SetClipRect(): %s, aborting\n"),
               SDL_GetError()));

    return;
  } // end IF
  RPG_Graphics_Surface::put((targetSurface->w - (*iterator).second->w),
                            offsetY_in,
                            *(*iterator).second,
                            targetSurface);
  invalidate(clipRect);

  // SW
  clipRect.x = offsetX_in;
  iterator = myElementGraphics.find(INTERFACEELEMENT_BORDER_BOTTOM_LEFT);
  ACE_ASSERT(iterator != myElementGraphics.end());
  clipRect.y = (targetSurface->h - (*iterator).second->h);
  clipRect.w = (*iterator).second->w;
  clipRect.h = (*iterator).second->h;
  if (!SDL_SetClipRect(targetSurface, &clipRect))
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to SDL_SetClipRect(): %s, aborting\n"),
               SDL_GetError()));

    return;
  } // end IF
  RPG_Graphics_Surface::put(offsetX_in,
                            (targetSurface->h - (*iterator).second->h),
                            *(*iterator).second,
                            targetSurface);
  invalidate(clipRect);

  // SE
  iterator = myElementGraphics.find(INTERFACEELEMENT_BORDER_BOTTOM_RIGHT);
  ACE_ASSERT(iterator != myElementGraphics.end());
  clipRect.x = (targetSurface->w - (*iterator).second->w);
  clipRect.y = (targetSurface->h - (*iterator).second->h);
  clipRect.w = (*iterator).second->w;
  clipRect.h = (*iterator).second->h;
  if (!SDL_SetClipRect(targetSurface, &clipRect))
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to SDL_SetClipRect(): %s, aborting\n"),
               SDL_GetError()));

    return;
  } // end IF
  RPG_Graphics_Surface::put((targetSurface->w - (*iterator).second->w),
                            (targetSurface->h - (*iterator).second->h),
                            *(*iterator).second,
                            targetSurface);
  invalidate(clipRect);

  // restore previous clipping area
  if (!SDL_SetClipRect(targetSurface, &prev_clipRect))
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to SDL_SetClipRect(): %s, aborting\n"),
               SDL_GetError()));

    return;
  } // end IF
}