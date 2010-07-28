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

#include "SDL_gui_defines.h"

#include <rpg_graphics_defines.h>
#include <rpg_graphics_surface.h>
#include <rpg_graphics_cursor.h>
#include <rpg_graphics_common_tools.h>
#include <rpg_graphics_SDL_tools.h>

#include <rpg_map_common_tools.h>

#include <ace/Log_Msg.h>

#include <sstream>

SDL_GUI_LevelWindow::SDL_GUI_LevelWindow(const RPG_Graphics_SDLWindowBase& parent_in,
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
   myCursor(TYPE_CURSOR_NORMAL),
   myHighlightBGPosition(std::make_pair(floorPlan_in.size_x / 2,
                                        floorPlan_in.size_y / 2)),
   myHighlightBG(NULL),
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

  // init cursor highlighting
  myHighlightBG = RPG_Graphics_Surface::create(RPG_GRAPHICS_TILE_FLOOR_WIDTH,
                                               RPG_GRAPHICS_TILE_FLOOR_HEIGHT);
  if (!myHighlightBG)
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to RPG_Graphics_Surface::create(%u,%u), continuing\n"),
               RPG_GRAPHICS_TILE_FLOOR_WIDTH,
               RPG_GRAPHICS_TILE_FLOOR_HEIGHT));
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

  if (myHighlightBG)
    SDL_FreeSurface(myHighlightBG);
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
SDL_GUI_LevelWindow::setView(const int& offsetX_in,
                             const int& offsetY_in)
{
  ACE_TRACE(ACE_TEXT("SDL_GUI_LevelWindow::setView"));

  RPG_Map_Dimensions_t dimensions = myMap.getDimensions();

  // handle over-/underruns
  if ((offsetX_in < 0) &&
      (ACE_static_cast(unsigned long, -offsetX_in) > myView.first))
    myView.first = 0;
  else
    myView.first += offsetX_in;

  if ((offsetY_in < 0) &&
      (ACE_static_cast(unsigned long, -offsetY_in) > myView.second))
    myView.second = 0;
  else
    myView.second += offsetY_in;

  if (myView.first >= dimensions.first)
    myView.first = (dimensions.first - 1);
  if (myView.second >= dimensions.second)
    myView.second = (dimensions.second - 1);
}

void
SDL_GUI_LevelWindow::centerView()
{
  ACE_TRACE(ACE_TEXT("SDL_GUI_LevelWindow::centerView"));

  RPG_Map_Dimensions_t dimensions = myMap.getDimensions();
  myView = std::make_pair(dimensions.first / 2,
                          dimensions.second / 2);
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
  centerView();

  // *NOTE*: fiddling with the view invalidates the cursor !
  RPG_GRAPHICS_CURSOR_SINGLETON::instance()->invalidate();

  // init cursor highlighting
  myHighlightBGPosition = std::make_pair(floorPlan_in.size_x / 2,
                                         floorPlan_in.size_y / 2);
}

void
SDL_GUI_LevelWindow::draw(SDL_Surface* targetSurface_in,
                          const unsigned long& offsetX_in,
                          const unsigned long& offsetY_in)
{
  ACE_TRACE(ACE_TEXT("SDL_GUI_LevelWindow::draw"));

  // set target surface
  SDL_Surface* targetSurface = (targetSurface_in ? targetSurface_in : myScreen);

  // sanity check(s)
  ACE_ASSERT(myCurrentOffMapTile);
//   ACE_ASSERT(myCurrentCeilingTile);
  ACE_ASSERT(targetSurface);
  ACE_ASSERT(ACE_static_cast(int, offsetX_in) <= targetSurface->w);
  ACE_ASSERT(ACE_static_cast(int, offsetY_in) <= targetSurface->h);

  // init clipping
  SDL_Rect clipRect;
  clipRect.x = offsetX_in + myBorderLeft + myOffset.first;
  clipRect.y = offsetY_in + myBorderTop + myOffset.second;
  clipRect.w = (targetSurface->w - offsetX_in - (myBorderLeft + myBorderRight) - myOffset.first);
  clipRect.h = (targetSurface->h - offsetY_in - (myBorderTop + myBorderBottom) - myOffset.second);
  if (!SDL_SetClipRect(targetSurface, &clipRect))
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to SDL_SetClipRect(): %s, aborting\n"),
               SDL_GetError()));

    return;
  } // end IF

  // position of the top right corner
  RPG_Graphics_Position_t top_right = std::make_pair(0, 0);
  top_right.first = (((-RPG_GRAPHICS_TILE_HEIGHT_MOD * ((targetSurface->w / 2) + 50)) +
                      (RPG_GRAPHICS_TILE_WIDTH_MOD * ((targetSurface->h / 2) + 50)) +
                      (RPG_GRAPHICS_TILE_WIDTH_MOD * RPG_GRAPHICS_TILE_HEIGHT_MOD)) /
                     (2 * RPG_GRAPHICS_TILE_WIDTH_MOD * RPG_GRAPHICS_TILE_HEIGHT_MOD));
  top_right.second = (((RPG_GRAPHICS_TILE_HEIGHT_MOD * ((targetSurface->w / 2) + 50)) +
                       (RPG_GRAPHICS_TILE_WIDTH_MOD * ((targetSurface->h / 2) + 50)) +
                       (RPG_GRAPHICS_TILE_WIDTH_MOD * RPG_GRAPHICS_TILE_HEIGHT_MOD)) /
                      (2 * RPG_GRAPHICS_TILE_WIDTH_MOD * RPG_GRAPHICS_TILE_HEIGHT_MOD));

  // *NOTE*: without the "+-1" small corners within the viewport are not drawn
  int diff = top_right.first - top_right.second - 1;
  int sum = top_right.first + top_right.second + 1;
//   int diff = top_right.first - top_right.second;
//   int sum  = top_right.first + top_right.second;

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
  // debug info
  SDL_Rect rect;
  std::ostringstream converter;
  std::string tile_text;
  RPG_Graphics_TextSize_t tile_text_size;
  clear();
  // pass 1
  for (i = -top_right.second;
       i <= ACE_static_cast(int, top_right.second);
       i++)
  {
    current_map_position.second = myView.second + i;

    // floor tile rotation
    floor_row = (current_map_position.second % (RPG_GRAPHICS_TILE_FLOORSET_NUMTILES / RPG_GRAPHICS_TILE_FLOORSET_ROWTILES));
    begin_row = myCurrentFloorSet.begin();
    std::advance(begin_row, floor_row);

    for (j = diff + i;
         (j + i) <= sum;
         j++)
    {
      current_map_position.first = myView.first + j;

      // floor tile rotation
      floor_index = (current_map_position.first % RPG_GRAPHICS_TILE_FLOORSET_ROWTILES);
      floor_iterator = begin_row;
      std::advance(floor_iterator, (RPG_GRAPHICS_TILE_FLOORSET_ROWTILES * floor_index));

      // map --> screen coordinates
      x = (targetSurface->w / 2) + (RPG_GRAPHICS_TILE_WIDTH_MOD * (j - i));
      y = (targetSurface->h / 2) + (RPG_GRAPHICS_TILE_HEIGHT_MOD * (j + i));

      // step1: off-map & unmapped areas
      if (((current_map_position.second < 0) ||
           (current_map_position.second >= myMap.getDimensions().second) ||
           (current_map_position.first < 0) ||
           (current_map_position.first >= myMap.getDimensions().first)) ||
          (myMap.getElement(current_map_position) == MAPELEMENT_UNMAPPED) ||
          // *NOTE*: walls are drawn together with the floor...
          (myMap.getElement(current_map_position) == MAPELEMENT_WALL))
      {
//         RPG_Graphics_Surface::put(x,
//                                   y,
//                                   *myCurrentOffMapTile,
//                                   targetSurface);

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
//         RPG_Graphics_Surface::put(x,
//                                   y,
//                                   *(*floor_iterator).surface,
//                                   targetSurface);

        // debug info
        rect.x = x;
        rect.y = y;
        rect.w = (*floor_iterator).surface->w;
        rect.h = (*floor_iterator).surface->h;
        RPG_Graphics_Surface::putRect(rect,                              // rectangle
                                      RPG_GRAPHICS_WINDOW_HOTSPOT_COLOR, // color
                                      targetSurface);                    // target surface
        converter.str(ACE_TEXT(""));
        converter.clear();
        tile_text = ACE_TEXT("[");
        converter << current_map_position.first;
        tile_text += converter.str();
        tile_text += ACE_TEXT(",");
        converter.str(ACE_TEXT(""));
        converter.clear();
        converter << current_map_position.second;
        tile_text += converter.str();
        tile_text += ACE_TEXT("]");
        tile_text_size = RPG_Graphics_Common_Tools::textSize(TYPE_FONT_MAIN_SMALL,
                                                             tile_text);
        RPG_Graphics_Surface::putText(TYPE_FONT_MAIN_SMALL,
                                      tile_text,
                                      RPG_Graphics_SDL_Tools::colorToSDLColor(RPG_GRAPHICS_FONT_DEF_COLOR,
                                                                              *targetSurface),
                                      true, // add shade
                                      RPG_Graphics_SDL_Tools::colorToSDLColor(RPG_GRAPHICS_FONT_DEF_SHADECOLOR,
                                                                              *targetSurface),
                                      (rect.x + ((rect.w - tile_text_size.first) / 2)),
                                      (rect.y + ((rect.h - tile_text_size.second) / 2)),
                                      targetSurface);
      } // end IF

      // *TODO*: step3: floor edges

//       // step4: cursor highlight
//       if (current_map_position == myHighlightBGPosition)
//       {
//         RPG_Graphics_Surface::put(x,
//                                   y,
//                                   *myHighlightTile,
//                                   targetSurface);
//       } // end IF

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
      x = (targetSurface->w / 2) + (RPG_GRAPHICS_TILE_WIDTH_MOD * (j - i));
      y = (targetSurface->h / 2) + (RPG_GRAPHICS_TILE_HEIGHT_MOD * (j + i));

      wall_iterator = myWallTiles.find(current_map_position);
      door_iterator = myDoorTiles.find(current_map_position);
      // step1: walls (west & north)
      if (wall_iterator != myWallTiles.end())
      {
//         if ((*wall_iterator).second.west.surface)
//           RPG_Graphics_Surface::put(x,
//                                     (y -
//                                      (*wall_iterator).second.west.surface->h +
//                                      (RPG_GRAPHICS_TILE_FLOOR_HEIGHT / 2)),
//                                     *(myCurrentWallSet.west.surface),
//                                     targetSurface);
//         if ((*wall_iterator).second.north.surface)
//           RPG_Graphics_Surface::put((x +
//                                      (RPG_GRAPHICS_TILE_FLOOR_WIDTH / 2)),
//                                     (y -
//                                      (*wall_iterator).second.north.surface->h +
//                                      (RPG_GRAPHICS_TILE_FLOOR_HEIGHT / 2)),
//                                     *(myCurrentWallSet.north.surface),
//                                     targetSurface);
      } // end IF

      // step2: doors
      if (door_iterator != myDoorTiles.end())
      {
//         // *NOTE*: door are drawn in the "middle" of the floor tile
//         RPG_Graphics_Surface::put((x +
//                                    (*door_iterator).second.offset_x +
//                                    (RPG_GRAPHICS_TILE_FLOOR_WIDTH / 4)),
//                                   (y +
//                                    (*door_iterator).second.offset_y -
//                                    (*door_iterator).second.surface->h +
//                                    (RPG_GRAPHICS_TILE_WALL_HEIGHT / 2) -
//                                    (RPG_GRAPHICS_TILE_FLOOR_HEIGHT / 4)),
//                                   *(*door_iterator).second.surface,
//                                   targetSurface);
      } // end IF

      // step3: walls (south & east)
      if (wall_iterator != myWallTiles.end())
      {
//         if ((*wall_iterator).second.south.surface)
//           RPG_Graphics_Surface::put(x,
//                                     (y -
//                                      (*wall_iterator).second.south.surface->h +
//                                      RPG_GRAPHICS_TILE_FLOOR_HEIGHT),
//                                     *(*wall_iterator).second.south.surface,
//                                     targetSurface);
//         if ((*wall_iterator).second.east.surface)
//           RPG_Graphics_Surface::put((x +
//                                      (RPG_GRAPHICS_TILE_FLOOR_WIDTH / 2)),
//                                     (y -
//                                      (*wall_iterator).second.east.surface->h +
//                                      RPG_GRAPHICS_TILE_FLOOR_HEIGHT),
//                                     *(*wall_iterator).second.east.surface,
//                                     targetSurface);
      } // end IF

      // step4: ceiling
//       if (SDL_GUI_LevelWindow::hasCeiling(current_map_position,
//                                           myMap))
//       {
//         RPG_Graphics_Surface::put(x,
//                                   (y -
//                                    RPG_GRAPHICS_TILE_WALL_HEIGHT +
//                                    (RPG_GRAPHICS_TILE_FLOOR_HEIGHT / 2)),
//                                   *myCurrentCeilingTile,
//                                   targetSurface);
//       } // end IF
    } // end FOR
  } // end FOR

  // whole viewport needs a refresh...
  clipRect.x = 0;
  clipRect.y = 0;
  clipRect.w = targetSurface->w;
  clipRect.h = targetSurface->h;
  myDirtyRegions.push_back(clipRect);

  // reset clipping area
  if (!SDL_SetClipRect(targetSurface, NULL))
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to SDL_SetClipRect(): %s, aborting\n"),
               SDL_GetError()));

    return;
  } // end IF

  // remember position of last realization
  myLastAbsolutePosition = std::make_pair(offsetX_in + myBorderLeft + myOffset.first,
                                          offsetY_in + myBorderTop + myOffset.second);
}

void
SDL_GUI_LevelWindow::handleEvent(const SDL_Event& event_in,
                                 RPG_Graphics_IWindow* window_in,
                                 bool& redraw_out)
{
  ACE_TRACE(ACE_TEXT("SDL_GUI_LevelWindow::handleEvent"));

  // init return value(s)
  redraw_out = false;

  switch (event_in.type)
  {
    // *** keyboard ***
    case SDL_KEYDOWN:
    {
//       ACE_DEBUG((LM_DEBUG,
//                  ACE_TEXT("%s key\n%s\n"),
//                  ((event_in.type == SDL_KEYDOWN) ? ACE_TEXT("pressed") : ACE_TEXT("released")),
//                  RPG_Graphics_SDL_Tools::keyToString(event_in.key.keysym).c_str()));

      switch (event_in.key.keysym.sym)
      {
        // implement keypad navigation
        case SDLK_c:
        case SDLK_UP:
        case SDLK_DOWN:
        case SDLK_LEFT:
        case SDLK_RIGHT:
        {
          switch (event_in.key.keysym.sym)
          {
            case SDLK_c:
              centerView(); break;
//             case SDLK_UP:
//               mapWindow->setView(0,
//                                  -RPG_GRAPHICS_WINDOW_SCROLL_OFFSET); break;
//             case SDLK_DOWN:
//               mapWindow->setView(0,
//                                  RPG_GRAPHICS_WINDOW_SCROLL_OFFSET); break;
//             case SDLK_LEFT:
//               mapWindow->setView(-RPG_GRAPHICS_WINDOW_SCROLL_OFFSET,
//                                  0); break;
//             case SDLK_RIGHT:
//               mapWindow->setView(RPG_GRAPHICS_WINDOW_SCROLL_OFFSET,
//                                  0); break;
            case SDLK_UP:
              setView(-RPG_GRAPHICS_WINDOW_SCROLL_OFFSET,
                      -RPG_GRAPHICS_WINDOW_SCROLL_OFFSET); break;
            case SDLK_DOWN:
              setView(RPG_GRAPHICS_WINDOW_SCROLL_OFFSET,
                      RPG_GRAPHICS_WINDOW_SCROLL_OFFSET); break;
            case SDLK_LEFT:
              setView(-RPG_GRAPHICS_WINDOW_SCROLL_OFFSET,
                      RPG_GRAPHICS_WINDOW_SCROLL_OFFSET); break;
            case SDLK_RIGHT:
              setView(RPG_GRAPHICS_WINDOW_SCROLL_OFFSET,
                      -RPG_GRAPHICS_WINDOW_SCROLL_OFFSET); break;
            default:
              break;
          } // end SWITCH

          // *NOTE*: fiddling with the view invalidates the cursor !
          RPG_GRAPHICS_CURSOR_SINGLETON::instance()->invalidate();

          // need a redraw
          redraw_out = true;

          // done with this event
          return;
        }
        default:
        {

          break;
        }
      } // end SWITCH

      // delegate all other keypresses to the parent...
      return getParent()->handleEvent(event_in,
                                      window_in,
                                      redraw_out);
    }
    // *** mouse ***
    case SDL_MOUSEMOTION:
    {
      // find map square
      RPG_Graphics_Position_t map_position = screen2Map(std::make_pair(event_in.motion.x,
                                                                       event_in.motion.y));
//       ACE_DEBUG((LM_DEBUG,
//                  ACE_TEXT("mouse position [%u,%u] --> [%u,%u]\n"),
//                  event_in.button.x,
//                  event_in.button.y,
//                  map_position.first,
//                  map_position.second));

      // draw highlight ?
      SDL_Rect dirtyRegion;
      if ((map_position != std::make_pair(std::numeric_limits<unsigned long>::max(),
                                          std::numeric_limits<unsigned long>::max())) &&
          (map_position != myHighlightBGPosition))
      {
        RPG_Graphics_Position_t tile_position;

        // restore old background
        if (myHighlightBG)
        {
          tile_position = map2Screen(myHighlightBGPosition);
//           // map square center --> top-left position
//           tile_position.first -= RPG_GRAPHICS_TILE_WIDTH_MOD;
//           tile_position.second -= RPG_GRAPHICS_TILE_HEIGHT_MOD;
          RPG_Graphics_Surface::put(tile_position.first,
                                    tile_position.second,
                                    *myHighlightBG,
                                    myScreen);

          dirtyRegion.x = tile_position.first;
          dirtyRegion.y = tile_position.second;
          dirtyRegion.w = myHighlightBG->w;
          dirtyRegion.h = myHighlightBG->h;

          myDirtyRegions.push_back(dirtyRegion);
        } // end IF
        // store current background
        tile_position = map2Screen(map_position);
//         // map square center --> top-left position
//         tile_position.first -= RPG_GRAPHICS_TILE_WIDTH_MOD;
//         tile_position.second -= RPG_GRAPHICS_TILE_HEIGHT_MOD;
        RPG_Graphics_Surface::get(tile_position.first,
                                  tile_position.second,
                                  true, // use (fast) blitting method
                                  *myScreen,
                                  *myHighlightBG);
        myHighlightBGPosition = map_position;

        // draw highlight
//         SDL_Rect clipRect;
//         clipRect.x = tile_position.first;
//         clipRect.y = tile_position.second;
//         clipRect.w = myHighlightTile->w;
//         clipRect.h = myHighlightTile->h;
//         if (!SDL_SetClipRect(myScreen, &clipRect))
//         {
//           ACE_DEBUG((LM_ERROR,
//                      ACE_TEXT("failed to SDL_SetClipRect(): %s, aborting\n"),
//                      SDL_GetError()));
//
//           return;
//         } // end IF
//         ACE_DEBUG((LM_DEBUG,
//                    ACE_TEXT("highlight @ (%u,%u) --> (%u,%u)\n"),
//                    map_position.first,
//                    map_position.second,
//                    tile_position.first,
//                    tile_position.second));

        RPG_Graphics_Surface::put(tile_position.first,
                                  tile_position.second,
                                  *myHighlightTile,
                                  myScreen);

        dirtyRegion.x = tile_position.first;
        dirtyRegion.y = tile_position.second;
        dirtyRegion.w = myHighlightTile->w;
        dirtyRegion.h = myHighlightTile->h;

        myDirtyRegions.push_back(dirtyRegion);

        // show changes
        refresh();
      } // end IF

      // set an appropriate cursor
      RPG_Graphics_Type cursor_type = SDL_GUI_LevelWindow::getCursor(std::make_pair(event_in.motion.x,
                                                                                    event_in.motion.y),
                                                                     myMap);
      if (cursor_type != myCursor)
        RPG_GRAPHICS_CURSOR_SINGLETON::instance()->set(cursor_type);
//       RPG_GRAPHICS_CURSOR_SINGLETON::instance()->put(event_in.motion.x,
//                                                      event_in.motion.y,
//                                                      myScreen,
//                                                      dirtyRegion);
//       myDirtyRegions.push_back(dirtyRegion);

      // show changes
      refresh();

      break;
    }
    case SDL_MOUSEBUTTONDOWN:
    {
//       ACE_DEBUG((LM_DEBUG,
//                  ACE_TEXT("mouse button [%u,%u] pressed\n"),
//                  ACE_static_cast(unsigned long, event_in.button.which),
//                  ACE_static_cast(unsigned long, event_in.button.button)));

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
    case RPG_GRAPHICS_SDL_HOVEREVENT:
    {
//       ACE_DEBUG((LM_DEBUG,
//                  ACE_TEXT("RPG_GRAPHICS_SDL_HOVEREVENT event...\n")));

      break;
    }
    case RPG_GRAPHICS_SDL_MOUSEMOVEOUT:
    {
//       ACE_DEBUG((LM_DEBUG,
//                  ACE_TEXT("RPG_GRAPHICS_SDL_MOUSEMOVEOUT event...\n")));

      break;
    }
    case SDL_ACTIVEEVENT:
    case SDL_KEYUP:
    case SDL_MOUSEBUTTONUP:
    case SDL_JOYAXISMOTION:
    case SDL_JOYBALLMOTION:
    case SDL_JOYHATMOTION:
    case SDL_JOYBUTTONDOWN:
    case SDL_JOYBUTTONUP:
    case SDL_QUIT:
    case SDL_SYSWMEVENT:
    case SDL_VIDEORESIZE:
    case SDL_VIDEOEXPOSE:
    default:
    {
      // delegate these to the parent...
      return getParent()->handleEvent(event_in,
                                      window_in,
                                      redraw_out);

      break;
    }
  } // end SWITCH
}

void
SDL_GUI_LevelWindow::clear()
{
  ACE_TRACE(ACE_TEXT("SDL_GUI_LevelWindow::clear"));

  // init clipping
  SDL_Rect clipRect;
  clipRect.x = myBorderLeft + myOffset.first;
  clipRect.y = myBorderTop + myOffset.second;
  clipRect.w = (myScreen->w - (myBorderLeft + myBorderRight) - myOffset.first);
  clipRect.h = (myScreen->h - (myBorderTop + myBorderBottom) - myOffset.second);
  if (!SDL_SetClipRect(myScreen, &clipRect))
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to SDL_SetClipRect(): %s, aborting\n"),
               SDL_GetError()));

    return;
  } // end IF

  if (SDL_FillRect(myScreen,                             // target surface
                   &clipRect,                            // rectangle
                   RPG_Graphics_SDL_Tools::CLR32_BLACK)) // color
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to SDL_FillRect(): %s, aborting\n"),
               SDL_GetError()));

    return;
  } // end IF

  // reset clipping
  if (!SDL_SetClipRect(myScreen, NULL))
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to SDL_SetClipRect(): %s, aborting\n"),
               SDL_GetError()));

    return;
  } // end IF
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
      copy = RPG_Graphics_Surface::copy(*myCurrentWallSet.east.surface);
      if (!copy)
      {
        ACE_DEBUG((LM_ERROR,
                   ACE_TEXT("failed to RPG_Graphics_Surface::copy(), aborting\n")));

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
      copy = RPG_Graphics_Surface::copy(*myCurrentWallSet.south.surface);
      if (!copy)
      {
        ACE_DEBUG((LM_ERROR,
                   ACE_TEXT("failed to RPG_Graphics_Surface::copy(), aborting\n")));

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

        if ((myMap.getElement(east) == MAPELEMENT_WALL) ||
            (current_position.first == (levelMap_in.size_x - 1))) // perimeter
          current_walls.east = myCurrentWallSet.east;
        if ((myMap.getElement(west) == MAPELEMENT_WALL) ||
            (current_position.first == 0)) // perimeter
          current_walls.west = myCurrentWallSet.west;
        if ((myMap.getElement(north) == MAPELEMENT_WALL) ||
            (current_position.second == 0)) // perimeter
          current_walls.north = myCurrentWallSet.north;
        if ((myMap.getElement(south) == MAPELEMENT_WALL) ||
            (current_position.second == (levelMap_in.size_y - 1))) // perimeter
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

  myWallBlend = RPG_Graphics_Surface::create(RPG_GRAPHICS_TILE_WALL_WIDTH,
                                             RPG_GRAPHICS_TILE_WALL_HEIGHT);
  if (!myWallBlend)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to RPG_Graphics_Surface::create(%u,%u), aborting\n"),
               RPG_GRAPHICS_TILE_WALL_WIDTH,
               RPG_GRAPHICS_TILE_WALL_HEIGHT));

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

  // "corridors"
  // vertical
  if (((level_in.getElement(east) == MAPELEMENT_FLOOR) ||
       (level_in.getElement(east) == MAPELEMENT_DOOR)) &&
      ((level_in.getElement(west) == MAPELEMENT_FLOOR) ||
       (level_in.getElement(west) == MAPELEMENT_DOOR)))
    return true;
  // horizontal
  if (((level_in.getElement(north) == MAPELEMENT_FLOOR) ||
       (level_in.getElement(north) == MAPELEMENT_DOOR)) &&
      ((level_in.getElement(south) == MAPELEMENT_FLOOR) ||
       (level_in.getElement(south) == MAPELEMENT_DOOR)))
    return true;
  // "corners"
  // SW
  if (((level_in.getElement(west) == MAPELEMENT_FLOOR) ||
       (level_in.getElement(west) == MAPELEMENT_DOOR)) &&
      ((level_in.getElement(south) == MAPELEMENT_FLOOR) ||
       (level_in.getElement(south) == MAPELEMENT_DOOR)) &&
      ((level_in.getElement(north) == MAPELEMENT_UNMAPPED) ||
       (level_in.getElement(north) == MAPELEMENT_WALL)) &&
      ((level_in.getElement(east) == MAPELEMENT_UNMAPPED) ||
       (level_in.getElement(east) == MAPELEMENT_WALL)))
    return (SDL_GUI_LevelWindow::hasCeiling(north,
                                            level_in) ||
            SDL_GUI_LevelWindow::hasCeiling(east,
                                            level_in));
  // SE
  if (((level_in.getElement(east) == MAPELEMENT_FLOOR) ||
       (level_in.getElement(east) == MAPELEMENT_DOOR)) &&
      ((level_in.getElement(south) == MAPELEMENT_FLOOR) ||
       (level_in.getElement(south) == MAPELEMENT_DOOR)) &&
      ((level_in.getElement(north) == MAPELEMENT_UNMAPPED) ||
       (level_in.getElement(north) == MAPELEMENT_WALL)) &&
      ((level_in.getElement(west) == MAPELEMENT_UNMAPPED) ||
       (level_in.getElement(west) == MAPELEMENT_WALL)))
    return (SDL_GUI_LevelWindow::hasCeiling(north,
                                            level_in) ||
            SDL_GUI_LevelWindow::hasCeiling(west,
                                            level_in));
  // NW
  if (((level_in.getElement(west) == MAPELEMENT_FLOOR) ||
       (level_in.getElement(west) == MAPELEMENT_DOOR)) &&
      ((level_in.getElement(north) == MAPELEMENT_FLOOR) ||
       (level_in.getElement(north) == MAPELEMENT_DOOR)) &&
      ((level_in.getElement(south) == MAPELEMENT_UNMAPPED) ||
       (level_in.getElement(south) == MAPELEMENT_WALL)) &&
      ((level_in.getElement(east) == MAPELEMENT_UNMAPPED) ||
       (level_in.getElement(east) == MAPELEMENT_WALL)))
    return (SDL_GUI_LevelWindow::hasCeiling(south,
                                            level_in) ||
            SDL_GUI_LevelWindow::hasCeiling(east,
                                            level_in));
  // NE
  if (((level_in.getElement(east) == MAPELEMENT_FLOOR) ||
       (level_in.getElement(east) == MAPELEMENT_DOOR)) &&
      ((level_in.getElement(north) == MAPELEMENT_FLOOR) ||
       (level_in.getElement(north) == MAPELEMENT_DOOR)) &&
      ((level_in.getElement(south) == MAPELEMENT_UNMAPPED) ||
       (level_in.getElement(south) == MAPELEMENT_WALL)) &&
      ((level_in.getElement(west) == MAPELEMENT_UNMAPPED) ||
       (level_in.getElement(west) == MAPELEMENT_WALL)))
    return (SDL_GUI_LevelWindow::hasCeiling(south,
                                            level_in) ||
            SDL_GUI_LevelWindow::hasCeiling(west,
                                            level_in));;

  return false;
}

const RPG_Graphics_Type
SDL_GUI_LevelWindow::getCursor(const RPG_Map_Position_t& position_in,
                               const RPG_Map_Level& level_in)
{
  ACE_TRACE(ACE_TEXT("SDL_GUI_LevelWindow::getCursor"));

  RPG_Graphics_Type result = TYPE_CURSOR_NORMAL;

  // (closed) door ?
  if (level_in.getElement(position_in) == MAPELEMENT_DOOR)
  {
    RPG_Map_Door_t door = level_in.getDoor(position_in);
    if (!door.is_open)
      result = TYPE_CURSOR_DOOR_OPEN;
  } // end IF

  return result;
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

  // sanity check: off-map position ?
  if ((map_position.first >= myMap.getDimensions().first) ||
      (map_position.second >= myMap.getDimensions().second))
  {
    map_position.first = std::numeric_limits<unsigned long>::max();
    map_position.second = std::numeric_limits<unsigned long>::max();
  } // end IF

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
