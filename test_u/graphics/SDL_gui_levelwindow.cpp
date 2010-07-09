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
#include "SDL_gui_levelwindow.h"

#include <rpg_graphics_defines.h>
#include <rpg_graphics_surface.h>
#include <rpg_graphics_hotspot.h>
#include <rpg_graphics_common_tools.h>
#include <rpg_graphics_SDL_tools.h>

#include <rpg_map_common_tools.h>

#include <ace/Log_Msg.h>

SDL_GUI_LevelWindow::SDL_GUI_LevelWindow(const RPG_Graphics_SDLWindow& parent_in,
                                         const RPG_Graphics_FloorStyle& floorStyle_in,
                                         const RPG_Graphics_WallStyle& wallStyle_in,
                                         const RPG_Graphics_DoorStyle& doorStyle_in,
                                         const RPG_Map_FloorPlan_t& floorPlan_in)
 : inherited(WINDOWTYPE_MAP,
             parent_in,
             std::make_pair(0, 0)),
   myMap(floorPlan_in),
   myCurrentFloorStyle(RPG_GRAPHICS_FLOORSTYLE_INVALID),
//    myCurrentFloorSet(),
   myCurrentWallStyle(RPG_GRAPHICS_WALLSTYLE_INVALID),
//    myCurrentWallSet(),
   myCurrentCeilingTile(NULL),
   myCurrentDoorStyle(RPG_GRAPHICS_DOORSTYLE_INVALID),
//    myCurrentDoorSet(),
   myCurrentOffMapTile(NULL),
//    myWallTiles(),
   myWallBlend(NULL),
   myView(std::make_pair(floorPlan_in.size_x / 2,
                         floorPlan_in.size_y / 2)),
   myHighlightPosition(std::make_pair(floorPlan_in.size_x / 2,
                                      floorPlan_in.size_y / 2)),
   myHighlightTile(NULL)
{
  ACE_TRACE(ACE_TEXT("SDL_GUI_LevelWindow::SDL_GUI_LevelWindow"));

  ACE_OS::memset(&myCurrentWallSet,
                 0,
                 sizeof(myCurrentWallSet));
  ACE_OS::memset(&myCurrentDoorSet,
                 0,
                 sizeof(myCurrentDoorSet));

  initWallBlend();

  // init style
  RPG_Graphics_StyleUnion style;
  style.discriminator = RPG_Graphics_StyleUnion::FLOORSTYLE;
  style.floorstyle = floorStyle_in;
  setStyle(style);
  style.discriminator = RPG_Graphics_StyleUnion::WALLSTYLE;
  style.wallstyle = wallStyle_in;
  setStyle(style);
  style.discriminator = RPG_Graphics_StyleUnion::DOORSTYLE;
  style.doorstyle = doorStyle_in;
  setStyle(style);

  // init ceiling tile
  initCeiling();

  // load tile for unmapped areas
  myCurrentOffMapTile = RPG_Graphics_Common_Tools::loadGraphic(TYPE_TILE_OFF_MAP, // tile
                                                               false);            // don't cache
  if (!myCurrentOffMapTile)
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to RPG_Graphics_Common_Tools::loadGraphic(\"%s\"), continuing\n"),
               RPG_Graphics_TypeHelper::RPG_Graphics_TypeToString(TYPE_TILE_OFF_MAP).c_str()));

  // init wall tiles / position
  initWalls(floorPlan_in,
            myCurrentWallSet,
            myWallTiles);

  // init door tiles / position
  initDoors(floorPlan_in,
            myMap,
            myCurrentDoorSet,
            myDoorTiles);

  // load tile for cursor highlighting
  myHighlightTile = RPG_Graphics_Common_Tools::loadGraphic(TYPE_TILE_CURSOR_HIGHLIGHT, // tile
                                                           false);                     // don't cache
  if (!myHighlightTile)
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to RPG_Graphics_Common_Tools::loadGraphic(\"%s\"), continuing\n"),
               RPG_Graphics_TypeHelper::RPG_Graphics_TypeToString(TYPE_TILE_CURSOR_HIGHLIGHT).c_str()));
}

SDL_GUI_LevelWindow::~SDL_GUI_LevelWindow()
{
  ACE_TRACE(ACE_TEXT("SDL_GUI_LevelWindow::~SDL_GUI_LevelWindow"));

  // clean up
  for (RPG_Graphics_FloorTileSetConstIterator_t iterator = myCurrentFloorSet.begin();
       iterator != myCurrentFloorSet.end();
       iterator++)
    SDL_FreeSurface((*iterator).surface);
  myCurrentFloorSet.clear();
  myCurrentFloorStyle = RPG_GRAPHICS_FLOORSTYLE_INVALID;

  if (myCurrentWallSet.east.surface)
    SDL_FreeSurface(myCurrentWallSet.east.surface);
  if (myCurrentWallSet.west.surface)
    SDL_FreeSurface(myCurrentWallSet.west.surface);
  if (myCurrentWallSet.north.surface)
    SDL_FreeSurface(myCurrentWallSet.north.surface);
  if (myCurrentWallSet.south.surface)
    SDL_FreeSurface(myCurrentWallSet.south.surface);
  myCurrentWallStyle = RPG_GRAPHICS_WALLSTYLE_INVALID;

  if (myWallBlend)
    SDL_FreeSurface(myWallBlend);

  if (myCurrentDoorSet.horizontal_open.surface)
    SDL_FreeSurface(myCurrentDoorSet.horizontal_open.surface);
  if (myCurrentDoorSet.vertical_open.surface)
    SDL_FreeSurface(myCurrentDoorSet.vertical_open.surface);
  if (myCurrentDoorSet.horizontal_closed.surface)
    SDL_FreeSurface(myCurrentDoorSet.horizontal_closed.surface);
  if (myCurrentDoorSet.vertical_closed.surface)
    SDL_FreeSurface(myCurrentDoorSet.vertical_closed.surface);
  if (myCurrentDoorSet.broken.surface)
    SDL_FreeSurface(myCurrentDoorSet.broken.surface);
  myCurrentDoorStyle = RPG_GRAPHICS_DOORSTYLE_INVALID;

  if (myCurrentCeilingTile)
    SDL_FreeSurface(myCurrentCeilingTile);

  if (myCurrentOffMapTile)
    SDL_FreeSurface(myCurrentOffMapTile);

  if (myHighlightTile)
    SDL_FreeSurface(myHighlightTile);
}

void
SDL_GUI_LevelWindow::setView(const RPG_Graphics_Position_t& view_in)
{
  ACE_TRACE(ACE_TEXT("SDL_GUI_LevelWindow::setView"));

  myView = view_in;
}

void
SDL_GUI_LevelWindow::init(const RPG_Graphics_FloorStyle& floorStyle_in,
                          const RPG_Graphics_WallStyle& wallStyle_in,
                          const RPG_Graphics_DoorStyle& doorStyle_in,
                          const RPG_Map_FloorPlan_t& floorPlan_in)
{
  ACE_TRACE(ACE_TEXT("SDL_GUI_LevelWindow::init"));

  // clean up
  myWallTiles.clear();

  myMap.init(floorPlan_in);

  // init style
  RPG_Graphics_StyleUnion style;
  style.discriminator = RPG_Graphics_StyleUnion::FLOORSTYLE;
  style.floorstyle = floorStyle_in;
  setStyle(style);
  style.discriminator = RPG_Graphics_StyleUnion::WALLSTYLE;
  style.wallstyle = wallStyle_in;
  setStyle(style);
  style.discriminator = RPG_Graphics_StyleUnion::DOORSTYLE;
  style.doorstyle = doorStyle_in;
  setStyle(style);

  // init wall tiles / position
  initWalls(floorPlan_in,
            myCurrentWallSet,
            myWallTiles);

  // init door tiles / position
  initDoors(floorPlan_in,
            myMap,
            myCurrentDoorSet,
            myDoorTiles);

  // init view
  myView = std::make_pair(floorPlan_in.size_x / 2,
                          floorPlan_in.size_y / 2);
}

void
SDL_GUI_LevelWindow::draw(SDL_Surface* targetSurface_in,
                          const RPG_Graphics_Offset_t& offset_in)
{
  ACE_TRACE(ACE_TEXT("SDL_GUI_LevelWindow::draw"));

  // sanity check(s)
  ACE_ASSERT(myCurrentOffMapTile);
  ACE_ASSERT(targetSurface_in);
  ACE_ASSERT(ACE_static_cast(int, offset_in.first) <= targetSurface_in->w);
  ACE_ASSERT(ACE_static_cast(int, offset_in.second) <= targetSurface_in->h);

  // init clipping
  SDL_Rect clipRect;
  clipRect.x = offset_in.first + myBorderLeft + myOffset.first;
  clipRect.y = offset_in.second + myBorderTop + myOffset.second;
  clipRect.w = (targetSurface_in->w - offset_in.first - (myBorderLeft + myBorderRight) - myOffset.first);
  clipRect.h = (targetSurface_in->h - offset_in.second - (myBorderTop + myBorderBottom) - myOffset.second);
  if (!SDL_SetClipRect(targetSurface_in, &clipRect))
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to SDL_SetClipRect(): %s, aborting\n"),
               SDL_GetError()));

    return;
  } // end IF

  // position of the top right corner
  RPG_Graphics_Position_t top_right = std::make_pair(0, 0);
  top_right.first = (((-RPG_GRAPHICS_TILE_HEIGHT_MOD * ((targetSurface_in->w / 2) + 50)) +
                      (RPG_GRAPHICS_TILE_WIDTH_MOD * ((targetSurface_in->h / 2) + 50)) +
                      (RPG_GRAPHICS_TILE_WIDTH_MOD * RPG_GRAPHICS_TILE_HEIGHT_MOD)) /
                     (2 * RPG_GRAPHICS_TILE_WIDTH_MOD * RPG_GRAPHICS_TILE_HEIGHT_MOD));
  top_right.second = (((RPG_GRAPHICS_TILE_HEIGHT_MOD * ((targetSurface_in->w / 2) + 50)) +
                       (RPG_GRAPHICS_TILE_WIDTH_MOD * ((targetSurface_in->h / 2) + 50)) +
                       (RPG_GRAPHICS_TILE_WIDTH_MOD * RPG_GRAPHICS_TILE_HEIGHT_MOD)) /
                      (2 * RPG_GRAPHICS_TILE_WIDTH_MOD * RPG_GRAPHICS_TILE_HEIGHT_MOD));

//   // *NOTE*: without the "+-1" small corners within the viewport are not drawn
  int diff = 0;
  int sum = 0;
//   diff = top_right.first - top_right.second - 1;
//   sum  = top_right.first + top_right.second + 1;
  diff = top_right.first - top_right.second;
  sum  = top_right.first + top_right.second;

  // draw tiles
  // pass 1:
  //   1. off-map & unmapped areas
  //   2. floor
  //   3. floor edges
  //   [4. cursor highlight]
  //
  // pass 2:
  //   1. north & west walls
  //   2. furniture
  //   3. traps
  //   4. objects
  //   5. monsters
  //   6. effects
  //   7. south & east walls
  //   8. ceiling

  int i, j;
  RPG_Map_Position_t current_map_position = std::make_pair(0, 0);
  RPG_Graphics_FloorTileSetConstIterator_t floor_iterator = myCurrentFloorSet.begin();
  RPG_Graphics_FloorTileSetConstIterator_t begin_row = myCurrentFloorSet.begin();
  unsigned long floor_row = 0;
  unsigned long floor_index = 0;
  unsigned long x, y;
  // pass 1
  for (i = -top_right.second;
       i <= ACE_static_cast(int, top_right.second);
       i++)
  {
    current_map_position.second = myView.second + i;

    // floor tile rotation
    if ((current_map_position.second == 0) || // init
        (floor_row == (RPG_GRAPHICS_TILE_FLOORSET_NUMTILES / RPG_GRAPHICS_TILE_FLOORSET_ROWTILES)))
      floor_row = 0;
    begin_row = myCurrentFloorSet.begin();
    std::advance(begin_row, floor_row);
    floor_iterator = begin_row;
    floor_row++;

    for (j = diff + i;
         (j + i) <= sum;
         j++)
    {
      current_map_position.first = myView.first + j;

      // floor tile rotation
      if ((current_map_position.first == 0) || // init
          (floor_index == RPG_GRAPHICS_TILE_FLOORSET_ROWTILES))
      {
        floor_index = 0;
        floor_iterator = begin_row;
      } // end IF
      floor_index++;

      // map --> screen coordinates
      x = (targetSurface_in->w / 2) + (RPG_GRAPHICS_TILE_WIDTH_MOD * (j - i));
      y = (targetSurface_in->h / 2) + (RPG_GRAPHICS_TILE_HEIGHT_MOD * (j + i));

      // step1: off-map & unmapped areas
      if (((current_map_position.second < 0) ||
           (current_map_position.second >= myMap.getDimensions().second) ||
           (current_map_position.first < 0) ||
           (current_map_position.first >= myMap.getDimensions().first)) ||
          (myMap.getElement(current_map_position) == MAPELEMENT_UNMAPPED) ||
          // *NOTE*: walls are drawn together with the floor...
          (myMap.getElement(current_map_position) == MAPELEMENT_WALL))
      {
        RPG_Graphics_Surface::put(x,
                                  y,
                                  *myCurrentOffMapTile,
                                  targetSurface_in);

//         // off the map ? --> continue
//         if ((current_map_position.second < 0) ||
//             (current_map_position.second >= myMap.getDimensions().second) ||
//             (current_map_position.first < 0) ||
//             (current_map_position.first >= myMap.getDimensions().first))

          // advance floor iterator
          std::advance(floor_iterator, RPG_GRAPHICS_TILE_FLOORSET_ROWTILES);

          continue;
      } // end IF

      // step2: floor
      if ((myMap.getElement(current_map_position) == MAPELEMENT_FLOOR) ||
          (myMap.getElement(current_map_position) == MAPELEMENT_DOOR))
      {
        RPG_Graphics_Surface::put(x,
                                  y,
                                  *(*floor_iterator).surface,
                                  targetSurface_in);
      } // end IF

      // *TODO*: step3: floor edges

      // step4: cursor highlight
      if (current_map_position == myHighlightPosition)
      {
        RPG_Graphics_Surface::put(x,
                                  y,
                                  *myHighlightTile,
                                  targetSurface_in);
      } // end IF

      // advance floor iterator
      std::advance(floor_iterator, RPG_GRAPHICS_TILE_FLOORSET_ROWTILES);
    } // end FOR
  } // end FOR

  // pass 2
  RPG_Graphics_WallTileMapConstIterator_t wall_iterator = myWallTiles.end();
  RPG_Graphics_DoorTileMapConstIterator_t door_iterator = myDoorTiles.end();
  for (i = -top_right.second;
       i <= ACE_static_cast(int, top_right.second);
       i++)
  {
    current_map_position.second = myView.second + i;
    // off the map ? --> continue
    if ((current_map_position.second < 0) ||
        (current_map_position.second >= myMap.getDimensions().second))
      continue;

    for (j = diff + i;
         (j + i) <= sum;
         j++)
    {
      current_map_position.first = myView.first + j;
      // off the map ? --> continue
      if ((current_map_position.first < 0) ||
          (current_map_position.first >= myMap.getDimensions().first))
        continue;

      // transform map coordinates into screen coordinates
      x = (targetSurface_in->w / 2) + (RPG_GRAPHICS_TILE_WIDTH_MOD * (j - i));
      y = (targetSurface_in->h / 2) + (RPG_GRAPHICS_TILE_HEIGHT_MOD * (j + i));

      wall_iterator = myWallTiles.find(current_map_position);
      door_iterator = myDoorTiles.find(current_map_position);
      // step1: walls (west & north)
      if (wall_iterator != myWallTiles.end())
      {
        if ((*wall_iterator).second.west.surface)
          RPG_Graphics_Surface::put(x,
                                    (y -
                                     (*wall_iterator).second.west.surface->h +
                                     (RPG_GRAPHICS_TILE_FLOOR_HEIGHT / 2)),
                                    *(myCurrentWallSet.west.surface),
                                    targetSurface_in);
        if ((*wall_iterator).second.north.surface)
          RPG_Graphics_Surface::put((x +
                                     (RPG_GRAPHICS_TILE_FLOOR_WIDTH / 2)),
                                    (y -
                                     (*wall_iterator).second.north.surface->h +
                                     (RPG_GRAPHICS_TILE_FLOOR_HEIGHT / 2)),
                                    *(myCurrentWallSet.north.surface),
                                    targetSurface_in);
      } // end IF

      // step2: doors
      if (door_iterator != myDoorTiles.end())
      {
        // *NOTE*: door are drawn in the "middle" of the floor tile
        RPG_Graphics_Surface::put((x +
                                   (*door_iterator).second.offset_x +
                                   (RPG_GRAPHICS_TILE_FLOOR_WIDTH / 4)),
                                  (y +
                                   (*door_iterator).second.offset_y -
                                   (*door_iterator).second.surface->h +
                                   (RPG_GRAPHICS_TILE_WALL_HEIGHT / 2) -
                                   (RPG_GRAPHICS_TILE_FLOOR_HEIGHT / 4)),
                                  *(*door_iterator).second.surface,
                                  targetSurface_in);
      } // end IF

      // step3: walls (south & east)
      if (wall_iterator != myWallTiles.end())
      {
        if ((*wall_iterator).second.south.surface)
          RPG_Graphics_Surface::put(x,
                                    (y -
                                     (*wall_iterator).second.south.surface->h +
                                     RPG_GRAPHICS_TILE_FLOOR_HEIGHT),
                                    *(*wall_iterator).second.south.surface,
                                    targetSurface_in);
        if ((*wall_iterator).second.east.surface)
          RPG_Graphics_Surface::put((x +
                                     (RPG_GRAPHICS_TILE_FLOOR_WIDTH / 2)),
                                    (y -
                                     (*wall_iterator).second.east.surface->h +
                                     RPG_GRAPHICS_TILE_FLOOR_HEIGHT),
                                    *(*wall_iterator).second.east.surface,
                                    targetSurface_in);
      } // end IF

      // step4: ceiling
      if (SDL_GUI_LevelWindow::hasCeiling(current_map_position,
                                          myMap))
      {
        RPG_Graphics_Surface::put(x,
                                  (y -
                                   RPG_GRAPHICS_TILE_WALL_HEIGHT +
                                   (RPG_GRAPHICS_TILE_FLOOR_HEIGHT / 2)),
                                  *myCurrentCeilingTile,
                                  targetSurface_in);
      } // end IF
    } // end FOR
  } // end FOR

  // whole viewport needs a refresh...
  myDirtyRegions.push_back(clipRect);

  // reset clipping area
  clipRect.x = 0;
  clipRect.y = 0;
  clipRect.w = targetSurface_in->w;
  clipRect.h = targetSurface_in->h;
  if (!SDL_SetClipRect(targetSurface_in, &clipRect))
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to SDL_SetClipRect(): %s, aborting\n"),
               SDL_GetError()));

    return;
  } // end IF

  // remember position of last realization
  myLastAbsolutePosition = offset_in;
}

void
SDL_GUI_LevelWindow::handleEvent(const SDL_Event& event_in,
                                 bool& redraw_out)
{
  ACE_TRACE(ACE_TEXT("SDL_GUI_LevelWindow::handleEvent"));

  // init return value(s)
  redraw_out = false;

  switch (event_in.type)
  {
    // *** visibility ***
    case SDL_ACTIVEEVENT:
    {
      if (event_in.active.state & SDL_APPACTIVE)
      {
        if (event_in.active.gain)
        {
          ACE_DEBUG((LM_DEBUG,
                     ACE_TEXT("activated...\n")));
        } // end IF
        else
        {
          ACE_DEBUG((LM_DEBUG,
                     ACE_TEXT("iconified...\n")));
        } // end ELSE
      } // end IF
      if (event_in.active.state & SDL_APPMOUSEFOCUS)
      {
        if (event_in.active.gain)
        {
          ACE_DEBUG((LM_DEBUG,
                     ACE_TEXT("mouse focus...\n")));
        } // end IF
        else
        {
          ACE_DEBUG((LM_DEBUG,
                     ACE_TEXT("lost mouse focus...\n")));
        } // end ELSE
      } // end IF

      break;
    }
    // *** keyboard ***
    case SDL_KEYDOWN:
    {
      ACE_DEBUG((LM_DEBUG,
                 ACE_TEXT("key pressed...\n")));

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

      break;
    }
    case SDL_MOUSEBUTTONDOWN:
    {
      ACE_DEBUG((LM_DEBUG,
                 ACE_TEXT("mouse button [%u,%u]\n"),
                 ACE_static_cast(unsigned long, event_in.button.which),
                 ACE_static_cast(unsigned long, event_in.button.button)));

      if (event_in.button.button == 1) // left-click
      {
        // debug info
        RPG_Graphics_Position_t map_position = screen2Map(std::make_pair(event_in.button.x,
                                                                         event_in.button.y));
        ACE_DEBUG((LM_DEBUG,
                   ACE_TEXT("mouse position [%u,%u] --> [%u,%u]\n"),
                   event_in.button.x,
                   event_in.button.y,
                   map_position.first,
                   map_position.second));
      } // end IF

      break;
    }
    case SDL_MOUSEBUTTONUP:
    {
      ACE_DEBUG((LM_DEBUG,
                 ACE_TEXT("mouse button released...\n")));

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
    case SDL_USEREVENT:
    {
      ACE_DEBUG((LM_DEBUG,
                 ACE_TEXT("SDL_USEREVENT event...\n")));

      break;
    }
    default:
    {
      ACE_DEBUG((LM_ERROR,
                 ACE_TEXT("received unknown event (was: %u)...\n"),
                 ACE_static_cast(unsigned long, event_in.type)));

      break;
    }
  } // end SWITCH
}

void
SDL_GUI_LevelWindow::setStyle(const RPG_Graphics_StyleUnion& style_in)
{
  ACE_TRACE(ACE_TEXT("SDL_GUI_LevelWindow::setStyle"));

  switch (style_in.discriminator)
  {
    case RPG_Graphics_StyleUnion::FLOORSTYLE:
    {
      // clean up
      for (RPG_Graphics_FloorTileSetConstIterator_t iterator = myCurrentFloorSet.begin();
           iterator != myCurrentFloorSet.end();
           iterator++)
        SDL_FreeSurface((*iterator).surface);
      myCurrentFloorSet.clear();

      RPG_Graphics_Common_Tools::loadFloorTileSet(style_in.floorstyle,
                                                  myCurrentFloorSet);
      // sanity check
      if (myCurrentFloorSet.empty())
      {
        ACE_DEBUG((LM_ERROR,
                   ACE_TEXT("floor-style \"%s\" has no tiles, continuing\n"),
                   RPG_Graphics_FloorStyleHelper::RPG_Graphics_FloorStyleToString(style_in.floorstyle).c_str()));
      } // end IF
      myCurrentFloorStyle = style_in.floorstyle;

      break;
    }
    case RPG_Graphics_StyleUnion::WALLSTYLE:
    {
      // clean up
      if (myCurrentWallSet.east.surface)
        SDL_FreeSurface(myCurrentWallSet.east.surface);
      if (myCurrentWallSet.west.surface)
        SDL_FreeSurface(myCurrentWallSet.west.surface);
      if (myCurrentWallSet.north.surface)
        SDL_FreeSurface(myCurrentWallSet.north.surface);
      if (myCurrentWallSet.south.surface)
        SDL_FreeSurface(myCurrentWallSet.south.surface);
      ACE_OS::memset(&myCurrentWallSet,
                     0,
                     sizeof(myCurrentWallSet));

      RPG_Graphics_Common_Tools::loadWallTileSet(style_in.wallstyle,
                                                 myCurrentWallSet);
      // sanity check
      if ((myCurrentWallSet.east.surface == NULL) ||
          (myCurrentWallSet.west.surface == NULL) ||
          (myCurrentWallSet.north.surface == NULL) ||
          (myCurrentWallSet.south.surface == NULL))
      {
        ACE_DEBUG((LM_ERROR,
                   ACE_TEXT("wall-style \"%s\" is incomplete, aborting\n"),
                   RPG_Graphics_WallStyleHelper::RPG_Graphics_WallStyleToString(style_in.wallstyle).c_str()));

        // clean up
        if (myCurrentWallSet.east.surface)
          SDL_FreeSurface(myCurrentWallSet.east.surface);
        if (myCurrentWallSet.west.surface)
          SDL_FreeSurface(myCurrentWallSet.west.surface);
        if (myCurrentWallSet.north.surface)
          SDL_FreeSurface(myCurrentWallSet.north.surface);
        if (myCurrentWallSet.south.surface)
          SDL_FreeSurface(myCurrentWallSet.south.surface);
        ACE_OS::memset(&myCurrentWallSet,
                       0,
                       sizeof(myCurrentWallSet));

        return;
      } // end IF

      // *NOTE*: west is just a "darkened" version of east...
      SDL_Surface* copy = NULL;
      copy = RPG_Graphics_SDL_Tools::copy(*myCurrentWallSet.east.surface);
      if (!copy)
      {
        ACE_DEBUG((LM_ERROR,
                   ACE_TEXT("failed to RPG_Graphics_SDL_Tools::copy(), aborting\n")));

        // clean up
        if (myCurrentWallSet.east.surface)
          SDL_FreeSurface(myCurrentWallSet.east.surface);
        if (myCurrentWallSet.west.surface)
          SDL_FreeSurface(myCurrentWallSet.west.surface);
        if (myCurrentWallSet.north.surface)
          SDL_FreeSurface(myCurrentWallSet.north.surface);
        if (myCurrentWallSet.south.surface)
          SDL_FreeSurface(myCurrentWallSet.south.surface);
        ACE_OS::memset(&myCurrentWallSet,
                       0,
                       sizeof(myCurrentWallSet));

        return;
      } // end IF
      if (SDL_BlitSurface(myWallBlend,
                          NULL,
                          copy,
                          NULL))
      {
        ACE_DEBUG((LM_ERROR,
                   ACE_TEXT("failed to SDL_BlitSurface(): %s, aborting\n"),
                   SDL_GetError()));

        // clean up
        if (myCurrentWallSet.east.surface)
          SDL_FreeSurface(myCurrentWallSet.east.surface);
        if (myCurrentWallSet.west.surface)
          SDL_FreeSurface(myCurrentWallSet.west.surface);
        if (myCurrentWallSet.north.surface)
          SDL_FreeSurface(myCurrentWallSet.north.surface);
        if (myCurrentWallSet.south.surface)
          SDL_FreeSurface(myCurrentWallSet.south.surface);
        ACE_OS::memset(&myCurrentWallSet,
                       0,
                       sizeof(myCurrentWallSet));
        SDL_FreeSurface(copy);

        return;
      } // end IF
      SDL_FreeSurface(myCurrentWallSet.west.surface);
      myCurrentWallSet.west.surface = copy;
      // *NOTE*: north is just a "darkened" version of south...
      copy = RPG_Graphics_SDL_Tools::copy(*myCurrentWallSet.south.surface);
      if (!copy)
      {
        ACE_DEBUG((LM_ERROR,
                   ACE_TEXT("failed to RPG_Graphics_SDL_Tools::copy(), aborting\n")));

        // clean up
        if (myCurrentWallSet.east.surface)
          SDL_FreeSurface(myCurrentWallSet.east.surface);
        if (myCurrentWallSet.west.surface)
          SDL_FreeSurface(myCurrentWallSet.west.surface);
        if (myCurrentWallSet.north.surface)
          SDL_FreeSurface(myCurrentWallSet.north.surface);
        if (myCurrentWallSet.south.surface)
          SDL_FreeSurface(myCurrentWallSet.south.surface);
        ACE_OS::memset(&myCurrentWallSet,
                       0,
                       sizeof(myCurrentWallSet));

        return;
      } // end IF
      if (SDL_BlitSurface(myWallBlend,
                          NULL,
                          copy,
                          NULL))
      {
        ACE_DEBUG((LM_ERROR,
                   ACE_TEXT("failed to SDL_BlitSurface(): %s, aborting\n"),
                   SDL_GetError()));

        // clean up
        if (myCurrentWallSet.east.surface)
          SDL_FreeSurface(myCurrentWallSet.east.surface);
        if (myCurrentWallSet.west.surface)
          SDL_FreeSurface(myCurrentWallSet.west.surface);
        if (myCurrentWallSet.north.surface)
          SDL_FreeSurface(myCurrentWallSet.north.surface);
        if (myCurrentWallSet.south.surface)
          SDL_FreeSurface(myCurrentWallSet.south.surface);
        ACE_OS::memset(&myCurrentWallSet,
                       0,
                       sizeof(myCurrentWallSet));
        SDL_FreeSurface(copy);

        return;
      } // end IF
      SDL_FreeSurface(myCurrentWallSet.north.surface);
      myCurrentWallSet.north.surface = copy;

      // set wall opacity
      SDL_Surface* shaded_wall = NULL;
      shaded_wall = RPG_Graphics_Surface::shade(*myCurrentWallSet.east.surface,
                                                ACE_static_cast(Uint8, (RPG_GRAPHICS_TILE_DEF_WALL_SE_OPACITY * SDL_ALPHA_OPAQUE)));
      if (!shaded_wall)
      {
        ACE_DEBUG((LM_ERROR,
                   ACE_TEXT("failed to RPG_Graphics_Surface::shade(%u), aborting\n"),
                   ACE_static_cast(Uint8, (RPG_GRAPHICS_TILE_DEF_WALL_SE_OPACITY * SDL_ALPHA_OPAQUE))));

        // clean up
        if (myCurrentWallSet.east.surface)
          SDL_FreeSurface(myCurrentWallSet.east.surface);
        if (myCurrentWallSet.west.surface)
          SDL_FreeSurface(myCurrentWallSet.west.surface);
        if (myCurrentWallSet.north.surface)
          SDL_FreeSurface(myCurrentWallSet.north.surface);
        if (myCurrentWallSet.south.surface)
          SDL_FreeSurface(myCurrentWallSet.south.surface);
        ACE_OS::memset(&myCurrentWallSet,
                       0,
                       sizeof(myCurrentWallSet));

        return;
      } // end IF
      SDL_FreeSurface(myCurrentWallSet.east.surface);
      myCurrentWallSet.east.surface = shaded_wall;

      shaded_wall = RPG_Graphics_Surface::shade(*myCurrentWallSet.west.surface,
                                                ACE_static_cast(Uint8, (RPG_GRAPHICS_TILE_DEF_WALL_NW_OPACITY * SDL_ALPHA_OPAQUE)));
      if (!shaded_wall)
      {
        ACE_DEBUG((LM_ERROR,
                   ACE_TEXT("failed to RPG_Graphics_Surface::shade(%u), aborting\n"),
                   ACE_static_cast(Uint8, (RPG_GRAPHICS_TILE_DEF_WALL_NW_OPACITY * SDL_ALPHA_OPAQUE))));

        // clean up
        if (myCurrentWallSet.east.surface)
          SDL_FreeSurface(myCurrentWallSet.east.surface);
        if (myCurrentWallSet.west.surface)
          SDL_FreeSurface(myCurrentWallSet.west.surface);
        if (myCurrentWallSet.north.surface)
          SDL_FreeSurface(myCurrentWallSet.north.surface);
        if (myCurrentWallSet.south.surface)
          SDL_FreeSurface(myCurrentWallSet.south.surface);
        ACE_OS::memset(&myCurrentWallSet,
                       0,
                       sizeof(myCurrentWallSet));

        return;
      } // end IF
      SDL_FreeSurface(myCurrentWallSet.west.surface);
      myCurrentWallSet.west.surface = shaded_wall;

      shaded_wall = RPG_Graphics_Surface::shade(*myCurrentWallSet.south.surface,
                                                ACE_static_cast(Uint8, (RPG_GRAPHICS_TILE_DEF_WALL_SE_OPACITY * SDL_ALPHA_OPAQUE)));
      if (!shaded_wall)
      {
        ACE_DEBUG((LM_ERROR,
                   ACE_TEXT("failed to RPG_Graphics_Surface::shade(%u), aborting\n"),
                   ACE_static_cast(Uint8, (RPG_GRAPHICS_TILE_DEF_WALL_SE_OPACITY * SDL_ALPHA_OPAQUE))));

        // clean up
        if (myCurrentWallSet.east.surface)
          SDL_FreeSurface(myCurrentWallSet.east.surface);
        if (myCurrentWallSet.west.surface)
          SDL_FreeSurface(myCurrentWallSet.west.surface);
        if (myCurrentWallSet.north.surface)
          SDL_FreeSurface(myCurrentWallSet.north.surface);
        if (myCurrentWallSet.south.surface)
          SDL_FreeSurface(myCurrentWallSet.south.surface);
        ACE_OS::memset(&myCurrentWallSet,
                       0,
                       sizeof(myCurrentWallSet));

        return;
      } // end IF
      SDL_FreeSurface(myCurrentWallSet.south.surface);
      myCurrentWallSet.south.surface = shaded_wall;

      shaded_wall = RPG_Graphics_Surface::shade(*myCurrentWallSet.north.surface,
                                                ACE_static_cast(Uint8, (RPG_GRAPHICS_TILE_DEF_WALL_NW_OPACITY * SDL_ALPHA_OPAQUE)));
      if (!shaded_wall)
      {
        ACE_DEBUG((LM_ERROR,
                   ACE_TEXT("failed to RPG_Graphics_Surface::shade(%u), aborting\n"),
                   ACE_static_cast(Uint8, (RPG_GRAPHICS_TILE_DEF_WALL_NW_OPACITY * SDL_ALPHA_OPAQUE))));

        // clean up
        if (myCurrentWallSet.east.surface)
          SDL_FreeSurface(myCurrentWallSet.east.surface);
        if (myCurrentWallSet.west.surface)
          SDL_FreeSurface(myCurrentWallSet.west.surface);
        if (myCurrentWallSet.north.surface)
          SDL_FreeSurface(myCurrentWallSet.north.surface);
        if (myCurrentWallSet.south.surface)
          SDL_FreeSurface(myCurrentWallSet.south.surface);
        ACE_OS::memset(&myCurrentWallSet,
                       0,
                       sizeof(myCurrentWallSet));

        return;
      } // end IF
      SDL_FreeSurface(myCurrentWallSet.north.surface);
      myCurrentWallSet.north.surface = shaded_wall;

      // debug info
      std::string dump_path_base = RPG_GRAPHICS_DUMP_DIR;
      dump_path_base += ACE_DIRECTORY_SEPARATOR_STR;

      std::string dump_path = dump_path_base;
      dump_path += ACE_TEXT("wall_n.png");
      RPG_Graphics_Surface::savePNG(*myCurrentWallSet.north.surface, // image
                                    dump_path,                       // file
                                    true);                           // WITH alpha
      dump_path = dump_path_base;
      dump_path += ACE_TEXT("wall_s.png");
      RPG_Graphics_Surface::savePNG(*myCurrentWallSet.south.surface, // image
                                    dump_path,                       // file
                                    true);                           // WITH alpha
      dump_path = dump_path_base;
      dump_path += ACE_TEXT("wall_w.png");
      RPG_Graphics_Surface::savePNG(*myCurrentWallSet.west.surface, // image
                                    dump_path,                      // file
                                    true);                          // WITH alpha
      dump_path = dump_path_base;
      dump_path += ACE_TEXT("wall_e.png");
      RPG_Graphics_Surface::savePNG(*myCurrentWallSet.east.surface, // image
                                    dump_path,                      // file
                                    true);                          // WITH alpha

      myCurrentWallStyle = style_in.wallstyle;

      break;
    }
    case RPG_Graphics_StyleUnion::DOORSTYLE:
    {
      // clean up
      if (myCurrentDoorSet.horizontal_open.surface)
        SDL_FreeSurface(myCurrentDoorSet.horizontal_open.surface);
      if (myCurrentDoorSet.vertical_open.surface)
        SDL_FreeSurface(myCurrentDoorSet.vertical_open.surface);
      if (myCurrentDoorSet.horizontal_closed.surface)
        SDL_FreeSurface(myCurrentDoorSet.horizontal_closed.surface);
      if (myCurrentDoorSet.vertical_closed.surface)
        SDL_FreeSurface(myCurrentDoorSet.vertical_closed.surface);
      if (myCurrentDoorSet.broken.surface)
        SDL_FreeSurface(myCurrentDoorSet.broken.surface);
      ACE_OS::memset(&myCurrentDoorSet,
                     0,
                     sizeof(myCurrentDoorSet));

      RPG_Graphics_Common_Tools::loadDoorTileSet(style_in.doorstyle,
                                                 myCurrentDoorSet);
      // sanity check
      if ((myCurrentDoorSet.horizontal_open.surface == NULL) ||
          (myCurrentDoorSet.vertical_open.surface == NULL) ||
          (myCurrentDoorSet.horizontal_closed.surface == NULL) ||
          (myCurrentDoorSet.vertical_closed.surface == NULL) ||
          (myCurrentDoorSet.broken.surface == NULL))
      {
        ACE_DEBUG((LM_ERROR,
                   ACE_TEXT("door-style \"%s\" is incomplete, continuing\n"),
                   RPG_Graphics_DoorStyleHelper::RPG_Graphics_DoorStyleToString(style_in.doorstyle).c_str()));
      } // end IF
      myCurrentDoorStyle = style_in.doorstyle;

      break;
    }
    default:
    {
      ACE_DEBUG((LM_ERROR,
                 ACE_TEXT("invalid style (was: %d), aborting\n"),
                 style_in.discriminator));

      return;
    }
  } // end SWITCH
}

void
SDL_GUI_LevelWindow::initCeiling()
{
  ACE_TRACE(ACE_TEXT("SDL_GUI_LevelWindow::initCeiling"));

  // sanity check
  if (myCurrentCeilingTile)
  {
    SDL_FreeSurface(myCurrentCeilingTile);
    myCurrentCeilingTile = NULL;
  } // end IF

  // load tile for ceiling
  myCurrentCeilingTile = RPG_Graphics_Common_Tools::loadGraphic(TYPE_TILE_CEILING, // tile
                                                                false);            // don't cache
  if (!myCurrentCeilingTile)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to RPG_Graphics_Common_Tools::loadGraphic(\"%s\"), aborting\n"),
               RPG_Graphics_TypeHelper::RPG_Graphics_TypeToString(TYPE_TILE_CEILING).c_str()));

    return;
  } // end IF

  SDL_Surface* shaded_ceiling = NULL;
  shaded_ceiling = RPG_Graphics_Surface::shade(*myCurrentCeilingTile,
                                               ACE_static_cast(Uint8, (RPG_GRAPHICS_TILE_DEF_WALL_NW_OPACITY * SDL_ALPHA_OPAQUE)));
  if (!shaded_ceiling)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to RPG_Graphics_Surface::shade(%u), aborting\n"),
               ACE_static_cast(Uint8, (RPG_GRAPHICS_TILE_DEF_WALL_NW_OPACITY * SDL_ALPHA_OPAQUE))));

    // clean up
    SDL_FreeSurface(myCurrentCeilingTile);
    myCurrentCeilingTile = NULL;

    return;
  } // end IF

  SDL_FreeSurface(myCurrentCeilingTile);
  myCurrentCeilingTile = shaded_ceiling;
}

void
SDL_GUI_LevelWindow::initWalls(const RPG_Map_FloorPlan_t& levelMap_in,
                               const RPG_Graphics_WallTileSet_t& tileSet_in,
                               RPG_Graphics_WallTileMap_t& wallTiles_out)
{
  ACE_TRACE(ACE_TEXT("SDL_GUI_LevelWindow::initWalls"));

  // init return value(s)
  wallTiles_out.clear();

  RPG_Map_Position_t current_position;
  RPG_Map_Position_t east, north, west, south;
  RPG_Graphics_WallTileSet_t current_walls;
  for (unsigned long y = 0;
       y < levelMap_in.size_y;
       y++)
    for (unsigned long x = 0;
         x < levelMap_in.size_x;
         x++)
    {
      current_position = std::make_pair(x, y);
      ACE_OS::memset(&current_walls,
                     0,
                     sizeof(current_walls));

      if ((myMap.getElement(current_position) == MAPELEMENT_FLOOR) ||
          (myMap.getElement(current_position) == MAPELEMENT_DOOR))
      {
        // step1: find neighboring walls
        east = current_position;
        east.first++;
        north = current_position;
        north.second--;
        west = current_position;
        west.first--;
        south = current_position;
        south.second++;

        if (myMap.getElement(east) == MAPELEMENT_WALL)
          current_walls.east = myCurrentWallSet.east;
        if (myMap.getElement(west) == MAPELEMENT_WALL)
          current_walls.west = myCurrentWallSet.west;
        if (myMap.getElement(north) == MAPELEMENT_WALL)
          current_walls.north = myCurrentWallSet.north;
        if (myMap.getElement(south) == MAPELEMENT_WALL)
          current_walls.south = myCurrentWallSet.south;

        if (current_walls.east.surface ||
            current_walls.north.surface ||
            current_walls.west.surface ||
            current_walls.south.surface)
          myWallTiles.insert(std::make_pair(current_position, current_walls));
      } // end IF
    } // end FOR
}

void
SDL_GUI_LevelWindow::initWallBlend()
{
  ACE_TRACE(ACE_TEXT("SDL_GUI_LevelWindow::initWallBlend"));

  // sanity check
  if (myWallBlend)
  {
    SDL_FreeSurface(myWallBlend);
    myWallBlend = NULL;
  } // end IF

  myWallBlend = SDL_CreateRGBSurface((SDL_HWSURFACE | // TRY to (!) place the surface in VideoRAM
                                      SDL_ASYNCBLIT |
                                      SDL_SRCCOLORKEY |
                                      SDL_SRCALPHA),
                                     RPG_GRAPHICS_TILE_WALL_WIDTH,
                                     RPG_GRAPHICS_TILE_WALL_HEIGHT,
//                                      (bit_depth * 8),
                                     32,
                                     ((SDL_BYTEORDER == SDL_LIL_ENDIAN) ? 0x000000FF : 0xFF000000),
                                     ((SDL_BYTEORDER == SDL_LIL_ENDIAN) ? 0x0000FF00 : 0x00FF0000),
                                     ((SDL_BYTEORDER == SDL_LIL_ENDIAN) ? 0x00FF0000 : 0x0000FF00),
                                     ((SDL_BYTEORDER == SDL_LIL_ENDIAN) ? 0xFF000000 : 0x000000FF));
//                                      Rmask,
//                                      Gmask,
//                                      Bmask,
//                                      Amask);
  if (!myWallBlend)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to SDL_CreateRGBSurface(): %s, aborting\n"),
               SDL_GetError()));

    return;
  } // end IF

  if (SDL_FillRect(myWallBlend,
                   NULL,
                   RPG_Graphics_SDL_Tools::CLR32_BLACK_A10))
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to SDL_FillRect(): %s, aborting\n"),
               SDL_GetError()));

    // clean up
    SDL_FreeSurface(myWallBlend);
    myWallBlend = NULL;

    return;
  } // end IF

//   SDL_Surface* shaded_blend = NULL;
//   shaded_blend = RPG_Graphics_Surface::shade(*myWallBlend,
//                                              ACE_static_cast(Uint8, (RPG_GRAPHICS_TILE_DEF_WALL_NW_OPACITY * SDL_ALPHA_OPAQUE)));
//   if (!shaded_blend)
//   {
//     ACE_DEBUG((LM_ERROR,
//                ACE_TEXT("failed to RPG_Graphics_Surface::shade(%u), aborting\n"),
//                ACE_static_cast(Uint8, (RPG_GRAPHICS_TILE_DEF_WALL_NW_OPACITY * SDL_ALPHA_OPAQUE))));
//
//     // clean up
//     SDL_FreeSurface(myWallBlend);
//     myWallBlend = NULL;
//
//     return;
//   } // end IF
//
//   SDL_FreeSurface(myWallBlend);
//   myWallBlend = shaded_blend;
}

void
SDL_GUI_LevelWindow::initDoors(const RPG_Map_FloorPlan_t& levelMap_in,
                               const RPG_Map_Level& levelState_in,
                               const RPG_Graphics_DoorTileSet_t& tileSet_in,
                               RPG_Graphics_DoorTileMap_t& doorTiles_out)
{
  ACE_TRACE(ACE_TEXT("SDL_GUI_LevelWindow::initDoors"));

  // init return value(s)
  doorTiles_out.clear();

  RPG_Graphics_Tile_t current_tile;
  RPG_Map_Door_t current_door;
  RPG_Graphics_Orientation orientation = RPG_GRAPHICS_ORIENTATION_INVALID;
  for (RPG_Map_PositionsConstIterator_t iterator = levelMap_in.doors.begin();
       iterator != levelMap_in.doors.end();
       iterator++)
  {
    ACE_OS::memset(&current_tile,
                   0,
                   sizeof(current_tile));
    current_door = levelState_in.getDoor(*iterator);
    orientation = RPG_GRAPHICS_ORIENTATION_INVALID;
    if (current_door.is_broken)
    {
      current_tile = tileSet_in.broken;
      continue;
    } // end IF

    orientation = SDL_GUI_LevelWindow::getDoorOrientation(levelMap_in,
                                                          *iterator);
    switch (orientation)
    {
      case ORIENTATION_HORIZONTAL:
      {
        current_tile = (current_door.is_open ? tileSet_in.horizontal_open
                                             : tileSet_in.horizontal_closed);
        break;
      }
      case ORIENTATION_VERTICAL:
      {
        current_tile = (current_door.is_open ? tileSet_in.vertical_open
                                             : tileSet_in.vertical_closed);
        break;
      }
      default:
      {
        ACE_DEBUG((LM_ERROR,
                   ACE_TEXT("invalid door orientation \"%s\", aborting\n"),
                   RPG_Graphics_OrientationHelper::RPG_Graphics_OrientationToString(orientation).c_str()));

        // clean up
        myDoorTiles.clear();

        return;
      }
    } // end SWITCH

    myDoorTiles.insert(std::make_pair(*iterator, current_tile));
  } // end FOR
}

void
SDL_GUI_LevelWindow::initHotSpots()
{
  ACE_TRACE(ACE_TEXT("SDL_GUI_LevelWindow::initHotSpots"));

  // upper left
  RPG_Graphics_HotSpot::init(*this,                  // parent
                             std::make_pair(RPG_GRAPHICS_WINDOW_HOTSPOT_SCROLL_MARGIN,
                                            RPG_GRAPHICS_WINDOW_HOTSPOT_SCROLL_MARGIN), // size
                             std::make_pair(0,
                                            0),   // offset
                             TYPE_CURSOR_SCROLL_UL); // (hover) cursor graphic
  // up
  RPG_Graphics_HotSpot::init(*this,                 // parent
                             std::make_pair(mySize.first - (2 * RPG_GRAPHICS_WINDOW_HOTSPOT_SCROLL_MARGIN),
                                            RPG_GRAPHICS_WINDOW_HOTSPOT_SCROLL_MARGIN), // size
                             std::make_pair(RPG_GRAPHICS_WINDOW_HOTSPOT_SCROLL_MARGIN,
                                            0),     // offset
                             TYPE_CURSOR_SCROLL_U); // (hover) cursor graphic
  // upper right
  RPG_Graphics_HotSpot::init(*this,                  // parent
                             std::make_pair(RPG_GRAPHICS_WINDOW_HOTSPOT_SCROLL_MARGIN,
                                            RPG_GRAPHICS_WINDOW_HOTSPOT_SCROLL_MARGIN), // size
                             std::make_pair(mySize.first - RPG_GRAPHICS_WINDOW_HOTSPOT_SCROLL_MARGIN,
                                            0),      // offset
                             TYPE_CURSOR_SCROLL_UR); // (hover) cursor graphic
  // left
  RPG_Graphics_HotSpot::init(*this,                 // parent
                             std::make_pair(RPG_GRAPHICS_WINDOW_HOTSPOT_SCROLL_MARGIN,
                                            mySize.second - (2 * RPG_GRAPHICS_WINDOW_HOTSPOT_SCROLL_MARGIN)), // size
                             std::make_pair(0,
                                            RPG_GRAPHICS_WINDOW_HOTSPOT_SCROLL_MARGIN), // offset
                             TYPE_CURSOR_SCROLL_L); // (hover) cursor graphic
  // right
  RPG_Graphics_HotSpot::init(*this,                 // parent
                             std::make_pair(RPG_GRAPHICS_WINDOW_HOTSPOT_SCROLL_MARGIN,
                                            mySize.second - (2 * RPG_GRAPHICS_WINDOW_HOTSPOT_SCROLL_MARGIN)), // size
                             std::make_pair(mySize.first - RPG_GRAPHICS_WINDOW_HOTSPOT_SCROLL_MARGIN,
                                            RPG_GRAPHICS_WINDOW_HOTSPOT_SCROLL_MARGIN), // offset
                             TYPE_CURSOR_SCROLL_R); // (hover) cursor graphic
  // lower left
  RPG_Graphics_HotSpot::init(*this,                  // parent
                             std::make_pair(RPG_GRAPHICS_WINDOW_HOTSPOT_SCROLL_MARGIN,
                                            RPG_GRAPHICS_WINDOW_HOTSPOT_SCROLL_MARGIN), // size
                             std::make_pair(0,
                                            mySize.second -RPG_GRAPHICS_WINDOW_HOTSPOT_SCROLL_MARGIN), // offset
                             TYPE_CURSOR_SCROLL_DL); // (hover) cursor graphic
  // down
  RPG_Graphics_HotSpot::init(*this,                 // parent
                             std::make_pair(mySize.first - (2 * RPG_GRAPHICS_WINDOW_HOTSPOT_SCROLL_MARGIN),
                                            RPG_GRAPHICS_WINDOW_HOTSPOT_SCROLL_MARGIN), // size
                             std::make_pair(RPG_GRAPHICS_WINDOW_HOTSPOT_SCROLL_MARGIN,
                                            mySize.second - RPG_GRAPHICS_WINDOW_HOTSPOT_SCROLL_MARGIN), // offset
                             TYPE_CURSOR_SCROLL_D); // (hover) cursor graphic
  // lower right
  RPG_Graphics_HotSpot::init(*this,                  // parent
                             std::make_pair(RPG_GRAPHICS_WINDOW_HOTSPOT_SCROLL_MARGIN,
                                            RPG_GRAPHICS_WINDOW_HOTSPOT_SCROLL_MARGIN), // size
                             std::make_pair(mySize.first - RPG_GRAPHICS_WINDOW_HOTSPOT_SCROLL_MARGIN,
                                            mySize.second - RPG_GRAPHICS_WINDOW_HOTSPOT_SCROLL_MARGIN), // offset
                             TYPE_CURSOR_SCROLL_DR); // (hover) cursor graphic
}

const RPG_Graphics_Orientation
SDL_GUI_LevelWindow::getDoorOrientation(const RPG_Map_Level& level_in,
                                        const RPG_Map_Position_t& position_in)
{
  ACE_TRACE(ACE_TEXT("SDL_GUI_LevelWindow::getDoorOrientation"));

  RPG_Map_Position_t east;//, south;
  east = position_in;
  east.first++;
//   south = position_in;
//   south.second++;

  if (level_in.getElement(east) == MAPELEMENT_WALL) // &&
//     (level_in.getElement(west) == MAPELEMENT_WALL))
  {
    return ORIENTATION_HORIZONTAL;
  } // end IF

  return ORIENTATION_VERTICAL;
}

const bool
SDL_GUI_LevelWindow::hasCeiling(const RPG_Map_Position_t& position_in,
                                const RPG_Map_Level& level_in)
{
  ACE_TRACE(ACE_TEXT("SDL_GUI_LevelWindow::hasCeiling"));

  // shortcut: floors, doors never get a ceiling
  if ((level_in.getElement(position_in) == MAPELEMENT_FLOOR) ||
      (level_in.getElement(position_in) == MAPELEMENT_DOOR))
    return false;

  RPG_Map_Position_t east, west, south, north;
  east = position_in;
  east.first++;
  west = position_in;
  west.first--;
  north = position_in;
  north.second--;
  south = position_in;
  south.second++;

  if (((level_in.getElement(east) == MAPELEMENT_FLOOR) ||
       (level_in.getElement(east) == MAPELEMENT_DOOR)) &&
      ((level_in.getElement(west) == MAPELEMENT_FLOOR) ||
       (level_in.getElement(west) == MAPELEMENT_DOOR)))
    return true;

  if (((level_in.getElement(north) == MAPELEMENT_FLOOR) ||
       (level_in.getElement(north) == MAPELEMENT_DOOR)) &&
      ((level_in.getElement(south) == MAPELEMENT_FLOOR) ||
       (level_in.getElement(south) == MAPELEMENT_DOOR)))
    return true;

  return false;
}

const RPG_Graphics_Position_t
SDL_GUI_LevelWindow::screen2Map(const RPG_Graphics_Position_t& position_in)
{
  ACE_TRACE(ACE_TEXT("SDL_GUI_LevelWindow::screen2Map"));

  RPG_Graphics_Position_t offset, map_position;

  offset.first = (position_in.first - (mySize.first / 2) + ((myView.first - myView.second) * RPG_GRAPHICS_TILE_WIDTH_MOD));
  offset.second = (position_in.second - (mySize.second / 2) + ((myView.first + myView.second) * RPG_GRAPHICS_TILE_HEIGHT_MOD));

  map_position.first = ((RPG_GRAPHICS_TILE_HEIGHT_MOD * offset.first) +
                        (RPG_GRAPHICS_TILE_WIDTH_MOD * offset.second) +
                        (RPG_GRAPHICS_TILE_WIDTH_MOD * RPG_GRAPHICS_TILE_HEIGHT_MOD)) /
                       (2 * RPG_GRAPHICS_TILE_WIDTH_MOD * RPG_GRAPHICS_TILE_HEIGHT_MOD);
  map_position.second = ((-RPG_GRAPHICS_TILE_HEIGHT_MOD * offset.first) +
                         (RPG_GRAPHICS_TILE_WIDTH_MOD * offset.second) +
                         (RPG_GRAPHICS_TILE_WIDTH_MOD * RPG_GRAPHICS_TILE_HEIGHT_MOD)) /
                        (2 * RPG_GRAPHICS_TILE_WIDTH_MOD * RPG_GRAPHICS_TILE_HEIGHT_MOD);

  return map_position;
}

const RPG_Graphics_Position_t
SDL_GUI_LevelWindow::map2Screen(const RPG_Graphics_Position_t& position_in)
{
  ACE_TRACE(ACE_TEXT("SDL_GUI_LevelWindow::map2Screen"));

  RPG_Graphics_Position_t map_center, screen_position;

  map_center.first = mySize.first / 2;
  map_center.second = mySize.second / 2;

  screen_position.first = map_center.first +
                          (RPG_GRAPHICS_TILE_WIDTH_MOD *
                           (position_in.first - position_in.second + myView.second - myView.first));
  screen_position.second = map_center.second +
                           (RPG_GRAPHICS_TILE_HEIGHT_MOD *
                            (position_in.first + position_in.second - myView.second - myView.first));

  // *TODO* fix underruns (why does this happen ?)
  return screen_position;
}
