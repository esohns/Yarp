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

#include "rpg_graphics_SDL_window_sub.h"

#include "rpg_graphics_surface.h"

#include <rpg_common_macros.h>

#include <ace/Log_Msg.h>

RPG_Graphics_SDLWindowSub::RPG_Graphics_SDLWindowSub(const RPG_Graphics_WindowType& type_in,
                                                     const RPG_Graphics_SDLWindowBase& parent_in,
                                                     // *NOTE*: offset doesn't include any border(s) !
                                                     const RPG_Graphics_Offset_t& offset_in,
                                                     const std::string& title_in)
//                                                      SDL_Surface* backGround_in)
 : inherited(type_in,        // type
             parent_in,      // parent
             offset_in,      // offset
             title_in),      // title
//              backGround_in), // background
   myBGHasBeenSaved(false),
   myBG(NULL)
{
  RPG_TRACE(ACE_TEXT("RPG_Graphics_SDLWindowSub::RPG_Graphics_SDLWindowSub"));

}

RPG_Graphics_SDLWindowSub::~RPG_Graphics_SDLWindowSub()
{
  RPG_TRACE(ACE_TEXT("RPG_Graphics_SDLWindowSub::~RPG_Graphics_SDLWindowSub"));

  // clean up
  if (myBG)
    SDL_FreeSurface(myBG);
}

void
RPG_Graphics_SDLWindowSub::close()
{
  RPG_TRACE(ACE_TEXT("RPG_Graphics_SDLWindowSub::close"));

  // restore saved background
  if (myBG)
    restoreBG();

  delete this;
}

void
RPG_Graphics_SDLWindowSub::saveBG(const RPG_Graphics_WindowSize_t& size_in)
{
  RPG_TRACE(ACE_TEXT("RPG_Graphics_SDLWindowSub::saveBG"));

  // sanity check(s)
  ACE_ASSERT(myBG == NULL);
  ACE_ASSERT(!myBGHasBeenSaved);

  myBG = RPG_Graphics_Surface::get((myScreen->w -
                                    (myBorderLeft + myBorderRight) -
                                    myOffset.first),
                                   (myScreen->h -
                                    (myBorderTop + myBorderBottom) -
                                    myOffset.second),
                                   ((size_in.first == 0) ? inherited::mySize.first
                                                         : size_in.first),
                                   ((size_in.second == 0) ? inherited::mySize.second
                                                          : size_in.second),
                                   *myScreen);
  if (!myBG)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to RPG_Graphics_Surface::get(%u,%u,%u,%u,%@), returning\n"),
               (myScreen->w -
                (myBorderLeft + myBorderRight) -
                myOffset.first),
               (myScreen->h -
                (myBorderTop + myBorderBottom) -
                myOffset.second),
               size_in.first,
               size_in.second,
               myScreen));

    return;
  } // end IF

  myBGHasBeenSaved = true;
}

void
RPG_Graphics_SDLWindowSub::restoreBG()
{
  RPG_TRACE(ACE_TEXT("RPG_Graphics_SDLWindowSub::restoreBG"));

  // sanity check(s)
  ACE_ASSERT(myBG);

  RPG_Graphics_Surface::put((myScreen->w -
                             (myBorderLeft + myBorderRight) -
                             myOffset.first),
                            (myScreen->h -
                             (myBorderTop + myBorderBottom) -
                             myOffset.second),
                            *myBG,
                            myScreen);
  // update screen immediately
  SDL_Rect dirtyRegion;
  dirtyRegion.x = (myScreen->w -
                   (myBorderLeft + myBorderRight) -
                   myOffset.first);
  dirtyRegion.y = (myScreen->h -
                   (myBorderTop + myBorderBottom) -
                   myOffset.second);
  dirtyRegion.w = myBG->w;
  dirtyRegion.h = myBG->h;
  RPG_Graphics_Surface::update(dirtyRegion,
                               myScreen);
}
