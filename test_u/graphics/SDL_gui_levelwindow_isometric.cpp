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

#include "SDL_gui_levelwindow_isometric.h"

#include "SDL_gui_defines.h"
#include "SDL_gui_minimapwindow.h"

#include "rpg_client_defines.h"
#include "rpg_client_entity_manager.h"
#include "rpg_client_common_tools.h"

#include "rpg_engine.h"
#include "rpg_engine_common_tools.h"

#include "rpg_graphics_defines.h"
#include "rpg_graphics_surface.h"
#include "rpg_graphics_cursor_manager.h"
#include "rpg_graphics_common_tools.h"
#include "rpg_graphics_SDL_tools.h"

#include "rpg_map_common_tools.h"

#include "rpg_common_macros.h"
#include "rpg_common_defines.h"
//#include "rpg_common_file_tools.h"

#include "ace/Log_Msg.h"

#include <sstream>

SDL_GUI_LevelWindow_Isometric::SDL_GUI_LevelWindow_Isometric(const RPG_Graphics_SDLWindowBase& parent_in,
                                                             RPG_Engine* engine_in)
 : inherited(WINDOW_MAP,           // type
             parent_in,            // parent
             std::make_pair(0, 0), // offset
             std::string()),       // title
//              NULL),                // background
   myState(NULL),
   myEngine(engine_in),
//    myCurrentFloorSet(),
//    myCurrentWallSet(),
   myCurrentCeilingTile(NULL),
//    myCurrentDoorSet(),
   myCurrentOffMapTile(NULL),
//    myFloorEdgeTiles(),
//    myWallTiles(),
   myHideFloor(false),
   myHideWalls(false),
   myWallBlend(NULL),
   myView(std::make_pair(std::numeric_limits<unsigned int>::max(),
                         std::numeric_limits<unsigned int>::max())),
//   myHighlightBGPosition(std::make_pair(myEngine->getSize().first / 2,
//                                        myEngine->getSize().second / 2)),
//   myHighlightBG(NULL),
//   myHighlightTile(NULL),
   myMinimapIsOn(RPG_CLIENT_MINIMAP_DEF_ISON)
{
  RPG_TRACE(ACE_TEXT("SDL_GUI_LevelWindow_Isometric::SDL_GUI_LevelWindow"));

	myEngine->init(this);

	RPG_Map_Size_t map_size = myEngine->getSize(true);
	myView = std::make_pair(map_size.first  >> 1,
													map_size.second >> 1);

//   initWallBlend(false);

  // init ceiling tile
  initCeiling();

  // load tile for unmapped areas
  RPG_Graphics_GraphicTypeUnion type;
  type.discriminator = RPG_Graphics_GraphicTypeUnion::TILEGRAPHIC;
  type.tilegraphic = TILE_OFF_MAP;
  myCurrentOffMapTile = RPG_Graphics_Common_Tools::loadGraphic(type,   // tile
                                                               true,   // convert to display format
                                                               false); // don't cache
  if (!myCurrentOffMapTile)
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to RPG_Graphics_Common_Tools::loadGraphic(\"%s\"), continuing\n"),
               ACE_TEXT(RPG_Graphics_Common_Tools::typeToString(type).c_str())));

  // init tiles / position
  ACE_OS::memset(&myCurrentFloorEdgeSet,
                 0,
                 sizeof(myCurrentFloorEdgeSet));
  ACE_OS::memset(&myCurrentWallSet,
                 0,
                 sizeof(myCurrentWallSet));
  ACE_OS::memset(&myCurrentDoorSet,
                 0,
                 sizeof(myCurrentDoorSet));

  // init minimap
  initMiniMap(myEngine);
}

SDL_GUI_LevelWindow_Isometric::~SDL_GUI_LevelWindow_Isometric()
{
  RPG_TRACE(ACE_TEXT("SDL_GUI_LevelWindow_Isometric::~SDL_GUI_LevelWindow"));

  // clean up
  for (RPG_Graphics_FloorTilesConstIterator_t iterator = myCurrentFloorSet.tiles.begin();
       iterator != myCurrentFloorSet.tiles.end();
       iterator++)
    SDL_FreeSurface((*iterator).surface);

  if (myCurrentFloorEdgeSet.east.surface)
    SDL_FreeSurface(myCurrentFloorEdgeSet.east.surface);
  if (myCurrentFloorEdgeSet.west.surface)
    SDL_FreeSurface(myCurrentFloorEdgeSet.west.surface);
  if (myCurrentFloorEdgeSet.north.surface)
    SDL_FreeSurface(myCurrentFloorEdgeSet.north.surface);
  if (myCurrentFloorEdgeSet.south.surface)
    SDL_FreeSurface(myCurrentFloorEdgeSet.south.surface);
  if (myCurrentFloorEdgeSet.south_east.surface)
    SDL_FreeSurface(myCurrentFloorEdgeSet.south_east.surface);
  if (myCurrentFloorEdgeSet.south_west.surface)
    SDL_FreeSurface(myCurrentFloorEdgeSet.south_west.surface);
  if (myCurrentFloorEdgeSet.north_east.surface)
    SDL_FreeSurface(myCurrentFloorEdgeSet.north_east.surface);
  if (myCurrentFloorEdgeSet.north_west.surface)
    SDL_FreeSurface(myCurrentFloorEdgeSet.north_west.surface);
  if (myCurrentFloorEdgeSet.top.surface)
    SDL_FreeSurface(myCurrentFloorEdgeSet.top.surface);
  if (myCurrentFloorEdgeSet.right.surface)
    SDL_FreeSurface(myCurrentFloorEdgeSet.right.surface);
  if (myCurrentFloorEdgeSet.left.surface)
    SDL_FreeSurface(myCurrentFloorEdgeSet.left.surface);
  if (myCurrentFloorEdgeSet.bottom.surface)
    SDL_FreeSurface(myCurrentFloorEdgeSet.bottom.surface);

  if (myCurrentWallSet.east.surface)
    SDL_FreeSurface(myCurrentWallSet.east.surface);
  if (myCurrentWallSet.west.surface)
    SDL_FreeSurface(myCurrentWallSet.west.surface);
  if (myCurrentWallSet.north.surface)
    SDL_FreeSurface(myCurrentWallSet.north.surface);
  if (myCurrentWallSet.south.surface)
    SDL_FreeSurface(myCurrentWallSet.south.surface);

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

  if (myCurrentCeilingTile)
    SDL_FreeSurface(myCurrentCeilingTile);

  if (myCurrentOffMapTile)
    SDL_FreeSurface(myCurrentOffMapTile);

//  if (myHighlightBG)
//    SDL_FreeSurface(myHighlightBG);
//  if (myHighlightTile)
//    SDL_FreeSurface(myHighlightTile);
}

void
SDL_GUI_LevelWindow_Isometric::setView(const int& offsetX_in,
                                       const int& offsetY_in)
{
  RPG_TRACE(ACE_TEXT("SDL_GUI_LevelWindow_Isometric::setView"));

  // handle over-/underruns
  if ((offsetX_in < 0) &&
      (static_cast<unsigned int>(-offsetX_in) > myView.first))
    myView.first = 0;
  else
    myView.first += offsetX_in;

  if ((offsetY_in < 0) &&
      (static_cast<unsigned int>(-offsetY_in) > myView.second))
    myView.second = 0;
  else
    myView.second += offsetY_in;

  RPG_Map_Size_t map_size = myEngine->getSize(true);
  if (myView.first >= map_size.first)
    myView.first = (map_size.first - 1);
  if (myView.second >= map_size.second)
    myView.second = (map_size.second - 1);
}

RPG_Graphics_Position_t
SDL_GUI_LevelWindow_Isometric::getView() const
{
  RPG_TRACE(ACE_TEXT("SDL_GUI_LevelWindow_Isometric::getView"));

  return myView;
}

void
SDL_GUI_LevelWindow_Isometric::init(state_t* state_in,
                                    RPG_Common_ILock* screenLock_in)
{
  RPG_TRACE(ACE_TEXT("SDL_GUI_LevelWindow_Isometric::init"));

  // sanity check(s)
  ACE_ASSERT(state_in);

  myState = state_in;
  inherited::init(screenLock_in,
                  (state_in->screen->flags & SDL_DOUBLEBUF));

  // init style
  RPG_Graphics_StyleUnion style;
  style.discriminator = RPG_Graphics_StyleUnion::FLOORSTYLE;
  style.floorstyle = myState->style.floor;
  if (!setStyle(style))
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to SDL_GUI_LevelWindow_Isometric::setStyle(FLOORSTYLE), continuing\n")));
  style.discriminator = RPG_Graphics_StyleUnion::EDGESTYLE;
  style.edgestyle = myState->style.edge;
  if (!setStyle(style))
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to SDL_GUI_LevelWindow_Isometric::setStyle(EDGESTYLE), continuing\n")));
  style.discriminator = RPG_Graphics_StyleUnion::WALLSTYLE;
  style.wallstyle = myState->style.wall;
  if (!setStyle(style))
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to SDL_GUI_LevelWindow_Isometric::setStyle(WALLSTYLE), continuing\n")));
  style.discriminator = RPG_Graphics_StyleUnion::DOORSTYLE;
  style.doorstyle = myState->style.door;
  if (!setStyle(style))
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to SDL_GUI_LevelWindow_Isometric::setStyle(DOORSTYLE), continuing\n")));

  SDL_GUI_MinimapWindow* minimap_window = NULL;
  try
  {
    minimap_window =
        dynamic_cast<SDL_GUI_MinimapWindow*>(child(WINDOW_MINIMAP));
  }
  catch (...)
  {
    minimap_window = NULL;
  }
  if (!minimap_window)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to dynamic_cast<SDL_GUI_MinimapWindow*>(%@), aborting\n"),
               child(WINDOW_MINIMAP)));

    return;
  } // end IF
  minimap_window->init(state_in, screenLock_in);
}

void
SDL_GUI_LevelWindow_Isometric::drawBorder(SDL_Surface* targetSurface_in,
                                          const unsigned int& offsetX_in,
                                          const unsigned int& offsetY_in)
{
  RPG_TRACE(ACE_TEXT("SDL_GUI_LevelWindow_Isometric::drawBorder"));

  // *NOTE*: should NEVER be reached !
  ACE_ASSERT(false);

#if defined (_MSC_VER)
  return;
#else
  ACE_NOTREACHED(return;)
#endif
}

void
SDL_GUI_LevelWindow_Isometric::draw(SDL_Surface* targetSurface_in,
                                    const unsigned int& offsetX_in,
                                    const unsigned int& offsetY_in)
{
  RPG_TRACE(ACE_TEXT("SDL_GUI_LevelWindow_Isometric::draw"));

  // sanity check(s)
  SDL_Surface* target_surface = (targetSurface_in ? targetSurface_in
                                                  : myScreen);
  ACE_ASSERT(target_surface);
  ACE_ASSERT(myCurrentOffMapTile);
//   ACE_ASSERT(myCurrentCeilingTile);
  ACE_ASSERT(static_cast<int>(offsetX_in) <= target_surface->w);
  ACE_ASSERT(static_cast<int>(offsetY_in) <= target_surface->h);

  // init clipping
  clip(target_surface,
       offsetX_in,
       offsetY_in);

  // position of the top right corner
  RPG_Graphics_Position_t top_right = std::make_pair(0, 0);
//   top_right.first = (((-RPG_GRAPHICS_TILE_HEIGHT_MOD * ((targetSurface->w / 2) + 50)) +
//                       (RPG_GRAPHICS_TILE_WIDTH_MOD * ((targetSurface->h / 2) + 50)) +
//                       (RPG_GRAPHICS_TILE_WIDTH_MOD * RPG_GRAPHICS_TILE_HEIGHT_MOD)) /
//                      (2 * RPG_GRAPHICS_TILE_WIDTH_MOD * RPG_GRAPHICS_TILE_HEIGHT_MOD));
//   top_right.second = (((RPG_GRAPHICS_TILE_HEIGHT_MOD * ((targetSurface->w / 2) + 50)) +
//                        (RPG_GRAPHICS_TILE_WIDTH_MOD * ((targetSurface->h / 2) + 50)) +
//                        (RPG_GRAPHICS_TILE_WIDTH_MOD * RPG_GRAPHICS_TILE_HEIGHT_MOD)) /
//                       (2 * RPG_GRAPHICS_TILE_WIDTH_MOD * RPG_GRAPHICS_TILE_HEIGHT_MOD));
  top_right.first =
      (((-RPG_GRAPHICS_TILE_HEIGHT_MOD * ((target_surface->w / 2))) +
        (RPG_GRAPHICS_TILE_WIDTH_MOD   * ((target_surface->h / 2))) +
        (RPG_GRAPHICS_TILE_WIDTH_MOD * RPG_GRAPHICS_TILE_HEIGHT_MOD)) /
       (2 * RPG_GRAPHICS_TILE_WIDTH_MOD * RPG_GRAPHICS_TILE_HEIGHT_MOD));
  top_right.second =
      (((RPG_GRAPHICS_TILE_HEIGHT_MOD * ((target_surface->w / 2))) +
        (RPG_GRAPHICS_TILE_WIDTH_MOD  * ((target_surface->h / 2))) +
        (RPG_GRAPHICS_TILE_WIDTH_MOD * RPG_GRAPHICS_TILE_HEIGHT_MOD)) /
       (2 * RPG_GRAPHICS_TILE_WIDTH_MOD * RPG_GRAPHICS_TILE_HEIGHT_MOD));

  // *NOTE*: without the "+-1" small corners within the viewport are not drawn
  int diff = top_right.first - top_right.second - 1;
  int sum  = top_right.first + top_right.second + 1;

	inherited::clear(COLOR_BLACK, // color
		               false);      // don't clip

  // draw tiles
  // pass 1:
  //   1. off-map & unmapped areas
  //   2. floor
  //   3. floor edges
  //   [4. cursor highlight]
  //
  // pass 2:
  //   1. north & west walls
  //   2. doors & furniture
  //   3. traps
  //   4. objects
  //   5. creatures
  //   6. effects
  //   7. south & east walls
  //   8. ceiling

	SDL_Rect dirty_region = {0, 0, 0, 0};
	SDL_Rect window_area;
	getArea(window_area, true);

  int i, j = 0;
  RPG_Position_t current_map_position = std::make_pair(0, 0);
  RPG_Graphics_FloorTilesConstIterator_t floor_iterator =
      myCurrentFloorSet.tiles.begin();
  RPG_Graphics_FloorTilesConstIterator_t begin_row =
      myCurrentFloorSet.tiles.begin();
  unsigned int floor_row = 0;
  unsigned int floor_index = 0;
  RPG_Position_t screen_position = std::make_pair(0, 0);
  SDL_Rect rect;
  std::ostringstream converter;
  std::string tile_text;
  RPG_Graphics_TextSize_t tile_text_size;
  RPG_Graphics_FloorEdgeTileMapIterator_t floor_edge_iterator =
      myFloorEdgeTiles.end();
  RPG_Engine_EntityID_t entity_id = 0;

  if (inherited::myScreenLock)
    inherited::myScreenLock->lock();
  myEngine->lock();

  // pass 1
  RPG_Map_Size_t map_size = myEngine->getSize(false);
  for (i = -static_cast<int>(top_right.second);
       i <= static_cast<int>(top_right.second);
       i++)
  {
    current_map_position.second = myView.second + i;

    // floor tile rotation
    floor_row = (current_map_position.second %
                 (myCurrentFloorSet.tiles.size() / myCurrentFloorSet.columns));
    begin_row = myCurrentFloorSet.tiles.begin();
    std::advance(begin_row, floor_row);

    for (j = diff + i;
         (j + i) <= sum;
         j++)
    {
      current_map_position.first = myView.first + j;

      // off-map ?
      if ((current_map_position.second < 0)                                  ||
          (current_map_position.second >= static_cast<int>(map_size.second)) ||
          (current_map_position.first < 0)                                   ||
          (current_map_position.first >= static_cast<int>(map_size.first)))
        continue;

      // floor tile rotation
      floor_index = (current_map_position.first % myCurrentFloorSet.columns);
      floor_iterator = begin_row;
      std::advance(floor_iterator, (myCurrentFloorSet.rows * floor_index));

      // map --> screen coordinates
//       x = (targetSurface->w / 2) + (RPG_GRAPHICS_TILE_WIDTH_MOD * (j - i));
//       y = (targetSurface->h / 2) + (RPG_GRAPHICS_TILE_HEIGHT_MOD * (j + i));
      screen_position =
          RPG_Graphics_Common_Tools::map2Screen(current_map_position,
																								std::make_pair(window_area.w,
																															 window_area.h),
                                                myView);

      // step1: unmapped areas
      RPG_Map_Element current_map_element =
          myEngine->getElement(current_map_position, false);
      if ((current_map_element == MAPELEMENT_UNMAPPED) ||
          // *NOTE*: walls are drawn together with the floor...
          (current_map_element == MAPELEMENT_WALL))
      {
        RPG_Graphics_Surface::put(screen_position,
                                  *myCurrentOffMapTile,
                                  target_surface,
                                  dirty_region);

//         // off the map ? --> continue
//         if ((current_map_position.second < 0) ||
//             (current_map_position.second >= myEngine->getDimensions().second) ||
//             (current_map_position.first < 0) ||
//             (current_map_position.first >= myEngine->getDimensions().first))

//         // advance floor iterator
//         std::advance(floor_iterator, myCurrentFloorSet.rows);

        continue;
      } // end IF

      // step2: floor
      if ((current_map_element == MAPELEMENT_FLOOR) ||
          (current_map_element == MAPELEMENT_DOOR))
      {
        if (!myHideFloor)
          RPG_Graphics_Surface::put(screen_position,
                                    *(*floor_iterator).surface,
                                    target_surface,
                                    dirty_region);

        if (myState->debug)
        {
          // highlight floor tile indexes
          rect.x = screen_position.first;
          rect.y = screen_position.second;
          rect.w = (*floor_iterator).surface->w;
          rect.h = (*floor_iterator).surface->h;
          RPG_Graphics_Surface::putRect(rect,                         // rectangle
                                        SDL_GUI_DEF_TILE_FRAME_COLOR, // color
                                        target_surface);              // target surface
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
          tile_text_size = RPG_Graphics_Common_Tools::textSize(FONT_MAIN_NORMAL,
                                                               tile_text);
          RPG_Graphics_Surface::putText(FONT_MAIN_NORMAL,
                                        tile_text,
                                        RPG_Graphics_SDL_Tools::colorToSDLColor(RPG_Graphics_SDL_Tools::getColor(SDL_GUI_DEF_TILE_INDEX_COLOR,
                                                                                                                 *target_surface),
                                                                                *target_surface),
                                        true, // add shade
                                        RPG_Graphics_SDL_Tools::colorToSDLColor(RPG_Graphics_SDL_Tools::getColor(RPG_GRAPHICS_FONT_DEF_SHADECOLOR,
                                                                                                                 *target_surface),
                                                                                *target_surface),
                                        std::make_pair((rect.x + ((rect.w - tile_text_size.first) / 2)),
                                                       (rect.y + ((rect.h - tile_text_size.second) / 2))),
                                        target_surface,
                                        dirty_region);
        } // end IF

        // step3: floor edges
        floor_edge_iterator = myFloorEdgeTiles.find(current_map_position);
        if ((floor_edge_iterator != myFloorEdgeTiles.end()) &&
            !myHideFloor)
        {
          // straight edges
          if ((*floor_edge_iterator).second.west.surface)
            RPG_Graphics_Surface::put(std::make_pair((screen_position.first +
                                                      (*floor_edge_iterator).second.west.offset_x),
                                                      (screen_position.second -
                                                       (*floor_edge_iterator).second.west.surface->h +
                                                       (RPG_GRAPHICS_TILE_FLOOR_HEIGHT / 2) +
                                                       (*floor_edge_iterator).second.west.offset_y)),
                                      *(myCurrentFloorEdgeSet.west.surface),
                                      target_surface,
                                      dirty_region);
          if ((*floor_edge_iterator).second.north.surface)
            RPG_Graphics_Surface::put(std::make_pair((screen_position.first +
                                                      (RPG_GRAPHICS_TILE_FLOOR_WIDTH / 2) +
                                                      (*floor_edge_iterator).second.north.offset_x),
                                                     (screen_position.second -
                                                      (*floor_edge_iterator).second.north.surface->h +
                                                      (RPG_GRAPHICS_TILE_FLOOR_HEIGHT / 2) +
                                                      (*floor_edge_iterator).second.north.offset_y)),
                                      *(myCurrentFloorEdgeSet.north.surface),
                                      target_surface,
                                      dirty_region);
          if ((*floor_edge_iterator).second.east.surface)
            RPG_Graphics_Surface::put(std::make_pair((screen_position.first +
                                                      (RPG_GRAPHICS_TILE_FLOOR_WIDTH / 2) +
                                                      (*floor_edge_iterator).second.east.offset_x),
                                                     (screen_position.second -
                                                      (*floor_edge_iterator).second.east.surface->h +
                                                      (RPG_GRAPHICS_TILE_FLOOR_HEIGHT / 2) +
                                                      (*floor_edge_iterator).second.east.offset_y)),
                                      *(myCurrentFloorEdgeSet.east.surface),
                                      target_surface,
                                      dirty_region);
          if ((*floor_edge_iterator).second.south.surface)
            RPG_Graphics_Surface::put(std::make_pair((screen_position.first +
                                                      (*floor_edge_iterator).second.south.offset_x),
                                                     (screen_position.second -
                                                      (*floor_edge_iterator).second.south.surface->h +
                                                      (RPG_GRAPHICS_TILE_FLOOR_HEIGHT / 2) +
                                                      (*floor_edge_iterator).second.south.offset_y)),
                                      *(myCurrentFloorEdgeSet.south.surface),
                                      target_surface,
                                      dirty_region);
          // corners
          if ((*floor_edge_iterator).second.south_west.surface)
            RPG_Graphics_Surface::put(std::make_pair((screen_position.first +
                                                      (*floor_edge_iterator).second.south_west.offset_x),
                                                     (screen_position.second -
                                                      (*floor_edge_iterator).second.south_west.surface->h +
                                                      (RPG_GRAPHICS_TILE_FLOOR_HEIGHT / 2) +
                                                      (*floor_edge_iterator).second.south_west.offset_y)),
                                      *(myCurrentFloorEdgeSet.south_west.surface),
                                      target_surface,
                                      dirty_region);
          if ((*floor_edge_iterator).second.north_west.surface)
            RPG_Graphics_Surface::put(std::make_pair((screen_position.first +
                                                      (RPG_GRAPHICS_TILE_FLOOR_WIDTH / 2) +
                                                      (*floor_edge_iterator).second.north_west.offset_x),
                                                     (screen_position.second -
                                                      (*floor_edge_iterator).second.north_west.surface->h +
                                                      (RPG_GRAPHICS_TILE_FLOOR_HEIGHT / 2) +
                                                      (*floor_edge_iterator).second.north_west.offset_y)),
                                      *(myCurrentFloorEdgeSet.north_west.surface),
                                      target_surface,
                                      dirty_region);
          if ((*floor_edge_iterator).second.south_east.surface)
            RPG_Graphics_Surface::put(std::make_pair((screen_position.first +
                                                      (RPG_GRAPHICS_TILE_FLOOR_WIDTH / 2) +
                                                      (*floor_edge_iterator).second.south_east.offset_x),
                                                     (screen_position.second -
                                                      (*floor_edge_iterator).second.south_east.surface->h +
                                                      (RPG_GRAPHICS_TILE_FLOOR_HEIGHT / 2) +
                                                      (*floor_edge_iterator).second.south_east.offset_y)),
                                      *(myCurrentFloorEdgeSet.south_east.surface),
                                      target_surface,
                                      dirty_region);
          if ((*floor_edge_iterator).second.north_east.surface)
            RPG_Graphics_Surface::put(std::make_pair((screen_position.first +
                                                      (RPG_GRAPHICS_TILE_FLOOR_WIDTH / 2) +
                                                      (*floor_edge_iterator).second.north_east.offset_x),
                                                     (screen_position.second -
                                                      (*floor_edge_iterator).second.north_east.surface->h +
                                                      (RPG_GRAPHICS_TILE_FLOOR_HEIGHT / 2) +
                                                      (*floor_edge_iterator).second.north_east.offset_y)),
                                      *(myCurrentFloorEdgeSet.north_east.surface),
                                      target_surface,
                                      dirty_region);
          // (square) corners
          if ((*floor_edge_iterator).second.top.surface)
            RPG_Graphics_Surface::put(std::make_pair((screen_position.first +
                                                      (*floor_edge_iterator).second.top.offset_x),
                                                     (screen_position.second -
                                                      (*floor_edge_iterator).second.top.surface->h +
                                                      (RPG_GRAPHICS_TILE_FLOOR_HEIGHT / 2) +
                                                      (*floor_edge_iterator).second.top.offset_y)),
                                      *(myCurrentFloorEdgeSet.top.surface),
                                      target_surface,
                                      dirty_region);
          if ((*floor_edge_iterator).second.right.surface)
            RPG_Graphics_Surface::put(std::make_pair((screen_position.first +
                                                      (RPG_GRAPHICS_TILE_FLOOR_WIDTH / 2) +
                                                      (*floor_edge_iterator).second.right.offset_x),
                                                     (screen_position.second -
                                                      (*floor_edge_iterator).second.right.surface->h +
                                                      (RPG_GRAPHICS_TILE_FLOOR_HEIGHT / 2) +
                                                      (*floor_edge_iterator).second.right.offset_y)),
                                      *(myCurrentFloorEdgeSet.right.surface),
                                      target_surface,
                                      dirty_region);
          if ((*floor_edge_iterator).second.left.surface)
            RPG_Graphics_Surface::put(std::make_pair((screen_position.first +
                                                      (*floor_edge_iterator).second.left.offset_x),
                                                     (screen_position.second -
                                                      (*floor_edge_iterator).second.left.surface->h +
                                                      (RPG_GRAPHICS_TILE_FLOOR_HEIGHT / 2) +
                                                      (*floor_edge_iterator).second.left.offset_y)),
                                      *(myCurrentFloorEdgeSet.left.surface),
                                      target_surface,
                                      dirty_region);
          if ((*floor_edge_iterator).second.bottom.surface)
            RPG_Graphics_Surface::put(std::make_pair((screen_position.first +
                                                      (RPG_GRAPHICS_TILE_FLOOR_WIDTH / 2) +
                                                      (*floor_edge_iterator).second.bottom.offset_x),
                                                     (screen_position.second -
                                                      (*floor_edge_iterator).second.bottom.surface->h +
                                                      (RPG_GRAPHICS_TILE_FLOOR_HEIGHT / 2) +
                                                      (*floor_edge_iterator).second.bottom.offset_y)),
                                      *(myCurrentFloorEdgeSet.bottom.surface),
                                      target_surface,
                                      dirty_region);
        } // end IF
      } // end IF

//       // advance floor iterator
//       std::advance(floor_iterator, myCurrentFloorSet.rows);
    } // end FOR
  } // end FOR

  // pass 2
  RPG_Graphics_WallTileMapIterator_t wall_iterator = myWallTiles.end();
  RPG_Graphics_DoorTileMapIterator_t door_iterator = myDoorTiles.end();
  RPG_Engine_LevelMetaData_t level_metadata = myEngine->getMetaData(false);
  //RPG_Engine_EntityGraphicsConstIterator_t creature_iterator;
  for (i = -static_cast<int>(top_right.second);
       i <= static_cast<int>(top_right.second);
       i++)
  {
    current_map_position.second = myView.second + i;
    // off the map ? --> continue
    if ((current_map_position.second < 0) ||
        (current_map_position.second >= static_cast<int>(map_size.second)))
      continue;

    for (j = diff + i;
         (j + i) <= sum;
         j++)
    {
      current_map_position.first = myView.first + j;
      // off the map ? --> continue
      if ((current_map_position.first < 0) ||
          (current_map_position.first >= static_cast<int>(map_size.first)))
        continue;

      // transform map coordinates into screen coordinates
//       x = (target_surface->w / 2) + (RPG_GRAPHICS_TILE_WIDTH_MOD * (j - i));
//       y = (target_surface->h / 2) + (RPG_GRAPHICS_TILE_HEIGHT_MOD * (j + i));
      screen_position =
        RPG_Graphics_Common_Tools::map2Screen(current_map_position,
																							std::make_pair(window_area.w,
																														 window_area.h),
                                              myView);

      wall_iterator = myWallTiles.find(current_map_position);
      door_iterator = myDoorTiles.find(current_map_position);
      // step1: walls (west & north)
      if ((wall_iterator != myWallTiles.end()) &&
          !myHideWalls)
      {
        if ((*wall_iterator).second.west.surface)
          RPG_Graphics_Surface::put(std::make_pair(screen_position.first,
                                                   (screen_position.second -
                                                    (*wall_iterator).second.west.surface->h +
                                                    (RPG_GRAPHICS_TILE_FLOOR_HEIGHT / 2))),
                                    *(myCurrentWallSet.west.surface),
                                    target_surface,
                                    dirty_region);
        if ((*wall_iterator).second.north.surface)
          RPG_Graphics_Surface::put(std::make_pair((screen_position.first +
                                                    (RPG_GRAPHICS_TILE_FLOOR_WIDTH / 2)),
                                                   (screen_position.second -
                                                    (*wall_iterator).second.north.surface->h +
                                                    (RPG_GRAPHICS_TILE_FLOOR_HEIGHT / 2))),
                                    *(myCurrentWallSet.north.surface),
                                    target_surface,
                                    dirty_region);
      } // end IF

      // step2: doors & furniture
      if (door_iterator != myDoorTiles.end())
      {
        // *NOTE*: door are drawn in the "middle" of the floor tile
        RPG_Graphics_Surface::put(std::make_pair((screen_position.first +
                                                  (*door_iterator).second.offset_x +
                                                  (RPG_GRAPHICS_TILE_FLOOR_WIDTH / 4)),
                                                 (screen_position.second +
                                                  (*door_iterator).second.offset_y -
                                                  (*door_iterator).second.surface->h +
                                                  (RPG_GRAPHICS_TILE_WALL_HEIGHT / 2) -
                                                  (RPG_GRAPHICS_TILE_FLOOR_HEIGHT / 4))),
                                  *(*door_iterator).second.surface,
                                  target_surface,
                                  dirty_region);
      } // end IF

      // step3: traps

      // step4: objects

      // step5: creatures
      entity_id = myEngine->hasEntity(current_map_position, false);
      if (entity_id)
      {
        // invalidate bg
        RPG_CLIENT_ENTITY_MANAGER_SINGLETON::instance()->invalidateBG(entity_id);

        // draw creature
        RPG_CLIENT_ENTITY_MANAGER_SINGLETON::instance()->put(entity_id,
                                                             screen_position,
                                                             dirty_region,
																														 false,
																														 false);
      } // end IF

      //creature_iterator = entity_graphics.find(current_map_position);
      //if (creature_iterator != entity_graphics.end())
      //{
      //  // sanity check
      //  ACE_ASSERT((*creature_iterator).second);

      //  // *NOTE*: creatures are drawn in the "middle" of the floor tile
      //  RPG_Graphics_Surface::put((screen_position.first +
      //                             ((RPG_GRAPHICS_TILE_FLOOR_WIDTH - (*creature_iterator).second->w) / 2)),
      //                            (screen_position.second +
      //                             (RPG_GRAPHICS_TILE_FLOOR_HEIGHT / 2) -
      //                             (*creature_iterator).second->h),
      //                            *((*creature_iterator).second),
      //                            target_surface);
      //} // end IF

      // step6: effects

      // step7: walls (south & east)
      if ((wall_iterator != myWallTiles.end()) &&
          !myHideWalls)
      {
        if ((*wall_iterator).second.south.surface)
          RPG_Graphics_Surface::put(std::make_pair(screen_position.first,
                                                   (screen_position.second -
                                                    (*wall_iterator).second.south.surface->h +
                                                    RPG_GRAPHICS_TILE_FLOOR_HEIGHT)),
                                    *(*wall_iterator).second.south.surface,
                                    target_surface,
                                    dirty_region);
        if ((*wall_iterator).second.east.surface)
          RPG_Graphics_Surface::put(std::make_pair((screen_position.first +
                                                    (RPG_GRAPHICS_TILE_FLOOR_WIDTH / 2)),
                                                   (screen_position.second -
                                                    (*wall_iterator).second.east.surface->h +
                                                    RPG_GRAPHICS_TILE_FLOOR_HEIGHT)),
                                    *(*wall_iterator).second.east.surface,
                                    target_surface,
                                    dirty_region);
      } // end IF

      // step8: ceiling
      if (RPG_Client_Common_Tools::hasCeiling(current_map_position,
                                              *myEngine,
                                              false) &&
          !myHideWalls)
        RPG_Graphics_Surface::put(std::make_pair(screen_position.first,
                                                 (screen_position.second -
                                                  (myState->style.half_height_walls ? (RPG_GRAPHICS_TILE_WALL_HEIGHT / 2)
                                                                                    : RPG_GRAPHICS_TILE_WALL_HEIGHT) +
                                                  (RPG_GRAPHICS_TILE_FLOOR_HEIGHT / (myState->style.half_height_walls ? 8
                                                                                                                      : 2)))),
                                  *myCurrentCeilingTile,
                                  target_surface,
                                  dirty_region);
    } // end FOR
  } // end FOR
  myEngine->unlock();
  if (inherited::myScreenLock)
    inherited::myScreenLock->unlock();

	// refresh (i.e. update bg cache) any sub-windows
	inherited::refresh();

  // realize any sub-windows
  for (RPG_Graphics_WindowsIterator_t iterator = inherited::myChildren.begin();
       iterator != inherited::myChildren.end();
       iterator++)
  {
		switch ((*iterator)->getType())
		{
			case WINDOW_MINIMAP:
			{
				// draw minimap ?
				if (!myMinimapIsOn)
					continue;

				break;
			}
			default:
			{
				ACE_DEBUG((LM_ERROR,
					         ACE_TEXT("unknown/invalid window type (was: %d), continuing\n"),
									 (*iterator)->getType()));

				break;
			}
		} // end SWITCH

    try
    {
      (*iterator)->draw(target_surface,
                        offsetX_in,
                        offsetY_in);
    }
    catch (...)
    {
      ACE_DEBUG((LM_ERROR,
                 ACE_TEXT("caught exception in RPG_Graphics_IWindow::draw(), continuing\n")));
    }
  } // end FOR

  // reset clipping area
  unclip(target_surface);

  // whole viewport needs a refresh...
  invalidate(myClipRect);

  // remember position of last realization
  myLastAbsolutePosition = std::make_pair(myClipRect.x,
                                          myClipRect.y);
}

void
SDL_GUI_LevelWindow_Isometric::handleEvent(const SDL_Event& event_in,
                                           RPG_Graphics_IWindowBase* window_in,
                                           SDL_Rect& dirtyRegion_out)
{
  RPG_TRACE(ACE_TEXT("SDL_GUI_LevelWindow_Isometric::handleEvent"));

  // init return value(s)
  ACE_OS::memset(&dirtyRegion_out, 0, sizeof(dirtyRegion_out));

  RPG_Engine_EntityID_t entity_id = 0;
  SDL_Rect dirty_region;
	bool redraw_cursor = false;
	bool restore_cursor_bg = false;
  switch (event_in.type)
  {
    // *** keyboard ***
    case SDL_KEYDOWN:
    {
      switch (event_in.key.keysym.sym)
      {
        // implement keypad navigation
        case SDLK_c:
        case SDLK_UP:
        case SDLK_DOWN:
        case SDLK_LEFT:
        case SDLK_RIGHT:
        {
          bool redraw = false;
          RPG_Map_Direction direction = RPG_MAP_DIRECTION_INVALID;
          entity_id = myEngine->getActive(true);
          switch (event_in.key.keysym.sym)
          {
            case SDLK_c:
            {
							myEngine->lock();
							if (entity_id)
                setView(myEngine->getPosition(entity_id, false));
              else
              {
                RPG_Map_Size_t size = myEngine->getSize(false);
                setView((size.first  / 2),
                        (size.second / 2));
              } // end ELSE
							myEngine->unlock();
              redraw = true;

              break;
            }
            case SDLK_UP:
            {
              if (event_in.key.keysym.mod & KMOD_SHIFT)
                setView(-RPG_GRAPHICS_WINDOW_SCROLL_OFFSET,
                        -RPG_GRAPHICS_WINDOW_SCROLL_OFFSET);
              else
                direction = DIRECTION_UP;

              break;
            }
            case SDLK_DOWN:
            {
              if (event_in.key.keysym.mod & KMOD_SHIFT)
                setView(RPG_GRAPHICS_WINDOW_SCROLL_OFFSET,
                        RPG_GRAPHICS_WINDOW_SCROLL_OFFSET);
              else
                direction = DIRECTION_DOWN;

              break;
            }
            case SDLK_LEFT:
            {
              if (event_in.key.keysym.mod & KMOD_SHIFT)
                setView(-RPG_GRAPHICS_WINDOW_SCROLL_OFFSET,
                        RPG_GRAPHICS_WINDOW_SCROLL_OFFSET);
              else
                direction = DIRECTION_LEFT;

              break;
            }
            case SDLK_RIGHT:
            {
              if (event_in.key.keysym.mod & KMOD_SHIFT)
                setView(RPG_GRAPHICS_WINDOW_SCROLL_OFFSET,
                        -RPG_GRAPHICS_WINDOW_SCROLL_OFFSET);
              else
                direction = DIRECTION_RIGHT;

              break;
            }
            default:
              break;
          } // end SWITCH

          if (!(event_in.key.keysym.mod & KMOD_SHIFT))
          {
            if (entity_id == 0)
              break; // nothing to do...

            RPG_Engine_Action_t player_action;
            player_action.command = COMMAND_TRAVEL;
            // compute target position
            player_action.position = myEngine->getPosition(entity_id, true);
            switch (direction)
            {
              case DIRECTION_UP:
                player_action.position.second--; break;
              case DIRECTION_DOWN:
                player_action.position.second++; break;
              case DIRECTION_LEFT:
                player_action.position.first--; break;
              case DIRECTION_RIGHT:
                player_action.position.first++; break;
              case RPG_MAP_DIRECTION_INVALID: // fell-through case
                break;
              default:
              {
                ACE_DEBUG((LM_ERROR,
                           ACE_TEXT("invalid direction (was: \"%s\"), aborting\n"),
                           ACE_TEXT(RPG_Map_DirectionHelper::RPG_Map_DirectionToString(direction).c_str())));

                break;
              }
            } // end SWITCH
            // position valid ?
            RPG_Map_Element element =
                myEngine->getElement(player_action.position, true);
            if ((element == MAPELEMENT_FLOOR) ||
                (element == MAPELEMENT_DOOR))
            {
              if (element == MAPELEMENT_DOOR)
              {
                RPG_Map_DoorState door_state =
                    myEngine->state(player_action.position, true);
                if ((door_state == DOORSTATE_CLOSED) ||
                    (door_state == DOORSTATE_LOCKED))
                  break;
              } // end IF

              myEngine->action(entity_id,
															 player_action,
															 true);

//              setView(myEngine->getPosition(entity_id));
            } // end IF
          } // end IF
          else
            redraw = true;

          if (redraw)
          {
            draw();
            getArea(dirtyRegion_out);
						redraw_cursor = true;
					} // end IF

          break;
        }
        case SDLK_d:
        {
          myState->debug = !myState->debug;

          // redraw
          draw();
          getArea(dirtyRegion_out);
					redraw_cursor = true;

          break;
        }
        case SDLK_f:
        {
          if (event_in.key.keysym.mod & KMOD_SHIFT)
          {
            // toggle setting
            myHideFloor = !myHideFloor;

            // redraw
            draw();
            getArea(dirtyRegion_out);
						redraw_cursor = true;

            break;
          } // end IF

          myState->style.floor =
              static_cast<RPG_Graphics_FloorStyle>(myState->style.floor + 1);
          if (myState->style.floor == RPG_GRAPHICS_FLOORSTYLE_MAX)
            myState->style.floor = static_cast<RPG_Graphics_FloorStyle>(0);
          RPG_Graphics_StyleUnion style;
          style.discriminator = RPG_Graphics_StyleUnion::FLOORSTYLE;
          style.floorstyle = myState->style.floor;
          setStyle(style);

          // redraw
          draw();
          getArea(dirtyRegion_out);
					redraw_cursor = true;

          break;
        }
        case SDLK_h:
        {
          // toggle setting
          myState->style.half_height_walls =
              !myState->style.half_height_walls;

          RPG_Graphics_StyleUnion new_style;
          new_style.discriminator = RPG_Graphics_StyleUnion::WALLSTYLE;
          new_style.wallstyle = myState->style.wall;
          setStyle(new_style);

          // redraw
          draw();
          getArea(dirtyRegion_out);
					redraw_cursor = true;

          break;
        }
        case SDLK_m:
        {
          myMinimapIsOn = !myMinimapIsOn;

          RPG_Graphics_IWindowBase* window_base = child(WINDOW_MINIMAP);
          if (!window_base)
          {
            ACE_DEBUG((LM_ERROR,
                       ACE_TEXT("%@: failed to RPG_Graphics_IWindow::child(WINDOW_MINIMAP), aborting\n"),
                       this));

            break;
          } // end IF
          RPG_Graphics_IWindow* window = NULL;
          try
          {
            window = dynamic_cast<RPG_Graphics_IWindow*>(window_base);
          }
          catch (...)
          {
            window = NULL;
          }
          if (!window)
          {
            ACE_DEBUG((LM_ERROR,
                       ACE_TEXT("failed to dynamic_cast<RPG_Graphics_IWindow*>(%@), aborting\n"),
                       window_base));

            break;
          } // end IF

          // draw
          try
          {
            if (myMinimapIsOn)
              window->show(dirtyRegion_out);
            else
              window->hide(dirtyRegion_out);
          }
          catch (...)
          {
            ACE_DEBUG((LM_ERROR,
                       ACE_TEXT("%@ caught exception in RPG_Graphics_IWindow::show/hide, aborting\n"),
                       window));

            break;
          }

          SDL_Rect cursor_area =
              RPG_GRAPHICS_CURSOR_MANAGER_SINGLETON::instance()->area(myView);
          SDL_Rect intersection = RPG_Graphics_SDL_Tools::intersect(cursor_area,
                                                                    dirtyRegion_out);
          redraw_cursor = (intersection.w && intersection.h);
          restore_cursor_bg = true;

          break;
        }
				case SDLK_t:
				case SDLK_x:
				{
					// find pointed-to map square
					RPG_Graphics_Position_t cursor_position =
						RPG_GRAPHICS_CURSOR_MANAGER_SINGLETON::instance()->position(false);
					SDL_Rect window_area;
					getArea(window_area, true);
					myEngine->lock();
					RPG_Map_Position_t map_position =
						RPG_Graphics_Common_Tools::screen2Map(cursor_position,
																									myEngine->getSize(false),
																									std::make_pair(window_area.w,
																									               window_area.h),
																									myView);
					RPG_GRAPHICS_CURSOR_MANAGER_SINGLETON::instance()->resetHighlightBG(map_position);
					bool push_mousemove_event = myEngine->isValid(map_position,
																												false);

					// toggle path selection mode
					switch (myState->selection_mode)
					{
						case SELECTIONMODE_AIM_CIRCLE:
						case SELECTIONMODE_AIM_SQUARE:
						{
							// --> switch off aim selection

							// clear cached positions
							myState->source =
								std::make_pair(std::numeric_limits<unsigned int>::max(),
															 std::numeric_limits<unsigned int>::max());
							myState->positions.clear();

							myState->selection_mode = SELECTIONMODE_NORMAL;
							push_mousemove_event = false;

							if (event_in.key.keysym.sym != SDLK_t)
								break;

							// *WARNING*: falls through !
						}
						case SELECTIONMODE_PATH:
						{
							// clear any cached positions
							myState->path.clear();

							// *WARNING*: falls through !
						}
						case SELECTIONMODE_NORMAL:
						{
							if (myEngine->getActive(false) == 0)
								push_mousemove_event = false;

							if (event_in.key.keysym.sym == SDLK_t)
								myState->selection_mode = SELECTIONMODE_PATH;	// --> switch on path selection
							else
							{
								// --> switch on aim selection

								// retain source position
								myState->source = map_position;

								// initial radius == 0
								myState->positions.push_back(map_position);

								myState->selection_mode = ((event_in.key.keysym.mod & KMOD_SHIFT) ? SELECTIONMODE_AIM_SQUARE
									                                                                : SELECTIONMODE_AIM_CIRCLE);
							} // end ELSE

							break;
						}
						default:
						{
							ACE_DEBUG((LM_ERROR,
												 ACE_TEXT("invalid selection mode (was: %u), continuing\n"),
												 myState->selection_mode));

							break;
						}
					} // end SWITCH

					// on the map ?
					if (push_mousemove_event)
					{
						// redraw highlight / cursor --> push fake mouse-move event
						SDL_Event sdl_event;
						sdl_event.type = SDL_MOUSEMOTION;
						sdl_event.motion.x = cursor_position.first;
						sdl_event.motion.y = cursor_position.second;
						if (SDL_PushEvent(&sdl_event))
							ACE_DEBUG((LM_ERROR,
												 ACE_TEXT("failed to SDL_PushEvent(): \"%s\", continuing\n"),
												 ACE_TEXT(SDL_GetError())));

						//            // step2: draw tile highlight
						//            myClientAction.command = COMMAND_TILE_HIGHLIGHT_DRAW;
						//            myClient->action(myClientAction);
						//            // *NOTE*: this MAY also invalidate the current cursor bg...
						//            myClientAction.command = COMMAND_CURSOR_INVALIDATE_BG;
						//            myClient->action(myClientAction);
					} // end IF
					//          // step3: set/draw an appropriate cursor
					//          RPG_Graphics_Cursor cursor_type =
					//              RPG_Client_Common_Tools::getCursor(myClientAction.position,
					//                                                 myClientAction.entity_id,
					//                                                 myClient->hasSeen(myClientAction.entity_id,
					//                                                                   myClientAction.position,
					//                                                                   true),
					//                                                 myClient->mode(),
					//                                                 *myEngine,
					//                                                 false);
					myEngine->unlock();
					//          if (cursor_type !=
					//              RPG_GRAPHICS_CURSOR_MANAGER_SINGLETON::instance()->type())
					//          {
					//            myClientAction.command = COMMAND_CURSOR_SET;
					//            myClientAction.cursor = cursor_type;
					//            myClient->action(myClientAction);
					//          } // end IF
					//          myClientAction.command = COMMAND_CURSOR_DRAW;
					//          myClientAction.position = cursor_position;
					//          myClient->action(myClientAction);

					break;
				}
        case SDLK_w:
        {
          if (event_in.key.keysym.mod & KMOD_SHIFT)
          {
            // toggle setting
            myHideWalls = !myHideWalls;

            // redraw
            draw();
            getArea(dirtyRegion_out);
						redraw_cursor = true;

            break;
          } // end IF

          myState->style.wall =
              static_cast<RPG_Graphics_WallStyle>(myState->style.wall + 1);
          if (myState->style.wall == RPG_GRAPHICS_WALLSTYLE_MAX)
            myState->style.wall = static_cast<RPG_Graphics_WallStyle>(0);
          RPG_Graphics_StyleUnion style;
          style.discriminator = RPG_Graphics_StyleUnion::WALLSTYLE;
          style.wallstyle = myState->style.wall;
          setStyle(style);

          // redraw
          draw();
          getArea(dirtyRegion_out);
					redraw_cursor = true;

          break;
        }
        default:
          break;
      } // end SWITCH

      break;
    }
    // *** mouse ***
    case SDL_MOUSEMOTION:
    {
      // find map square
			SDL_Rect window_area;
			getArea(window_area, true);
      RPG_Graphics_Position_t map_position =
          RPG_Graphics_Common_Tools::screen2Map(std::make_pair(event_in.motion.x,
                                                               event_in.motion.y),
                                                myEngine->getSize(true),
																								std::make_pair(window_area.w,
																								               window_area.h),
                                                myView);
      // inside map ?
      if (map_position ==
          std::make_pair(std::numeric_limits<unsigned int>::max(),
                         std::numeric_limits<unsigned int>::max()))
        break; // off-map

//       ACE_DEBUG((LM_DEBUG,
//                  ACE_TEXT("mouse position [%u,%u] --> [%u,%u]\n"),
//                  event_in.button.x,
//                  event_in.button.y,
//                  map_position.first,
//                  map_position.second));

      // (re-)draw "active" tile highlight ?
      SDL_Rect dirty_region;
      ACE_OS::memset(&dirty_region, 0, sizeof(dirty_region));
      if (map_position !=
          RPG_GRAPHICS_CURSOR_MANAGER_SINGLETON::instance()->getHighlightBGPosition())
      {
        // unmapped area ?
        RPG_Map_Element map_element = myEngine->getElement(map_position, true);
  //      ACE_DEBUG((LM_DEBUG,
  //                 ACE_TEXT("map element [%u,%u]: \"%s\"\n"),
  //                 map_position.first, map_position.second,
  //                 ACE_TEXT(RPG_Map_Common_Tools::mapElement2String(map_element).c_str())));
        if ((map_element == MAPELEMENT_UNMAPPED) ||
            (map_element == MAPELEMENT_WALL))
        {
          RPG_GRAPHICS_CURSOR_MANAGER_SINGLETON::instance()->restoreHighlightBG(myView,
                                                                                dirtyRegion_out);
          invalidate(dirtyRegion_out);
        } // end IF
        else
        {
          RPG_Graphics_Offset_t highlight_position =
            RPG_Graphics_Common_Tools::map2Screen(map_position,
						                                      std::make_pair(window_area.w,
																									               window_area.h),
                                                  myView);
          if (highlight_position !=
						  std::make_pair(std::numeric_limits<int>::max(),
							               std::numeric_limits<int>::max()))
          {
						// *NOTE*: essentially, this means:
						// - the cursor bg is dirty, needs an update
						// - the highlight needs to be redrawn
						// - the cursor needs to be redrawn
						
						// step1: update cursor bg
						myScreenLock->lock();
//						RPG_GRAPHICS_CURSOR_MANAGER_SINGLETON::instance()->restoreBG(dirty_region,
//																																				 NULL,
//																																				 false);
//						dirtyRegion_out =
//							RPG_Graphics_SDL_Tools::boundingBox(dirty_region,
//                                    							dirtyRegion_out);
						//std::string dump_path = RPG_Common_File_Tools::getDumpDirectory();
						//dump_path += ACE_DIRECTORY_SEPARATOR_CHAR_A;
						//dump_path += ACE_TEXT_ALWAYS_CHAR("before");
						//dump_path += ACE_TEXT_ALWAYS_CHAR(RPG_CLIENT_SCREENSHOT_DEF_EXT);
						//RPG_Graphics_Surface::savePNG(*SDL_GetVideoSurface(), // image
						//															dump_path,              // file
						//															false);                 // no alpha

//						RPG_GRAPHICS_CURSOR_MANAGER_SINGLETON::instance()->restoreHighlightBG(myView,
//																																									dirty_region,
//																																									false);
//						dirtyRegion_out =
//							RPG_Graphics_SDL_Tools::boundingBox(dirty_region,
//							                                    dirtyRegion_out);
//						// *NOTE*: putHighlight() will restoreBG() (again) during highlight bg storing
//						// --> update it first
//						RPG_GRAPHICS_CURSOR_MANAGER_SINGLETON::instance()->updateBG(NULL);

						// step2: draw highlight(s)
						bool multiple_highlights = false;
						RPG_Map_Positions_t positions;
						RPG_Graphics_Offsets_t screen_positions;
						switch (myState->selection_mode)
						{
							case SELECTIONMODE_AIM_CIRCLE:
							{
								unsigned int selection_radius =
									RPG_Map_Common_Tools::distanceMax(myState->source,
									                                  map_position);
								if (selection_radius > RPG_MAP_CIRCLE_MAX_RADIUS)
									selection_radius = RPG_MAP_CIRCLE_MAX_RADIUS;

								RPG_Map_Common_Tools::buildCircle(myState->source,
																									myEngine->getSize(false),
																									selection_radius,
																									false, // don't fill
																									positions);

								// *WARNING*: falls through !
							}
							case SELECTIONMODE_AIM_SQUARE:
							{
								if (myState->selection_mode == SELECTIONMODE_AIM_SQUARE)
								{
									unsigned int selection_radius =
										RPG_Map_Common_Tools::distanceMax(myState->source,
										                                  map_position);
									RPG_Map_Common_Tools::buildSquare(myState->source,
																										myEngine->getSize(false),
																										selection_radius,
																										false, // don't fill
																										positions);
								} // end IF

								// step2: remove invalid positions
								RPG_Map_Positions_t obstacles = myEngine->getObstacles(false,
																																			 false);
								// *WARNING*: this works for associative containers ONLY
								for (RPG_Map_PositionsIterator_t iterator = positions.begin();
										 iterator != positions.end();
										)
									if (RPG_Map_Common_Tools::hasLineOfSight(myState->source,
																													 *iterator,
																													 obstacles,
																													 false))
										iterator++;
									else
										positions.erase(iterator++);
								for (RPG_Map_PositionsConstIterator_t iterator = positions.begin();
										 iterator != positions.end();
										 iterator++)
									myState->positions.push_back(*iterator);

								// step3: compute screen positions
								for (RPG_Map_PositionListIterator_t iterator = myState->positions.begin();
											iterator != myState->positions.end();
											iterator++)
								  screen_positions.push_back(RPG_Graphics_Common_Tools::map2Screen(*iterator,
																																									 std::make_pair(window_area.w,
																																										              window_area.h),
																																									 myView));

  							multiple_highlights = true;

								break;
							}
							case SELECTIONMODE_NORMAL:
								break;
							case SELECTIONMODE_PATH:
							{
								RPG_Engine_EntityID_t entity_id = myEngine->getActive(false);
								if (entity_id                              &&
										myEngine->isValid(map_position, false) &&
										hasSeen(entity_id,
										        map_position))
								{
									RPG_Map_Position_t current_position =
										myEngine->getPosition(entity_id, false);
									if (current_position != map_position)
									{
										if (!myEngine->findPath(current_position,
											                      map_position,
											                      myState->path,
											                      false))
										{
											//ACE_DEBUG((LM_DEBUG,
											//           ACE_TEXT("could not find a path [%u,%u] --> [%u,%u], aborting\n"),
											//           current_position.first,
											//           current_position.second,
											//           myClientAction.position.first,
											//           myClientAction.position.second));

											// pointing at an invalid (==unreachable) position (still on the map)
											// --> erase cached path (and tile highlights)
											myState->path.clear();
										} // end IF
									} // end IF

									multiple_highlights = true;
								} // end IF
								else
								{
									// pointing at an invalid (==unreachable) position (still on the map)
									// --> erase cached path (and tile highlights)
									myState->path.clear();
								} // end ELSE

								break;
							}
							default:
							{
								ACE_DEBUG((LM_ERROR,
													 ACE_TEXT("invalid selection mode (was: %d), aborting\n"),
													 myState->selection_mode));

								// clean up
								myEngine->unlock();

								return;
							}
						} // end SWITCH

						if (multiple_highlights)
							RPG_GRAPHICS_CURSOR_MANAGER_SINGLETON::instance()->putHighlights(myState->positions,
																																							 screen_positions,
																																							 myView,
																																							 dirty_region,
																																							 false);
						else
							RPG_GRAPHICS_CURSOR_MANAGER_SINGLETON::instance()->putHighlight(map_position,
		                                                                          highlight_position,
			                                                                        myView,
																																							dirty_region,
																																							false,
						                                                                  myState->debug);
						dirtyRegion_out =
							RPG_Graphics_SDL_Tools::boundingBox(dirty_region,
							                                    dirtyRegion_out);
						//dump_path = RPG_Common_File_Tools::getDumpDirectory();
						//dump_path += ACE_DIRECTORY_SEPARATOR_CHAR_A;
						//dump_path += ACE_TEXT_ALWAYS_CHAR("before_2");
						//dump_path += ACE_TEXT_ALWAYS_CHAR(RPG_CLIENT_SCREENSHOT_DEF_EXT);
						//RPG_Graphics_Surface::savePNG(*SDL_GetVideoSurface(), // image
						//															dump_path,              // file
						//															false);                 // no alpha

//						// step3: this happens automatically (see SDL_gui.cpp::do_work()),
//						// update the cursor BG first
//						RPG_GRAPHICS_CURSOR_MANAGER_SINGLETON::instance()->updateBG(dirty_region,
//																																				NULL,
//																																				false,
//																																				myState->debug);
						myScreenLock->unlock();
						dirtyRegion_out =
							RPG_Graphics_SDL_Tools::boundingBox(dirty_region,
																									dirtyRegion_out);

						invalidate(dirtyRegion_out);
          } // end IF
        } // end IF
      } // end IF

      // set an appropriate cursor
      RPG_Engine_EntityID_t entity_id = myEngine->getActive(true);
      RPG_Graphics_Cursor cursor_type =
          RPG_Client_Common_Tools::getCursor(map_position,
                                             entity_id,
                                             true,
                                             SELECTIONMODE_NORMAL,
                                             *myEngine,
                                             true);
      if (cursor_type !=
          RPG_GRAPHICS_CURSOR_MANAGER_SINGLETON::instance()->type())
      {
        ACE_OS::memset(&dirty_region, 0, sizeof(dirty_region));
        RPG_GRAPHICS_CURSOR_MANAGER_SINGLETON::instance()->setCursor(cursor_type,
                                                                     dirty_region);
        if ((dirty_region.w > 0) ||
            (dirty_region.h > 0))
        {
          dirtyRegion_out =
						RPG_Graphics_SDL_Tools::boundingBox(dirty_region,
						                                    dirtyRegion_out);
          invalidate(dirty_region);
        } // end IF
      } // end IF

      break;
    }
    case SDL_MOUSEBUTTONDOWN:
    {
//       ACE_DEBUG((LM_DEBUG,
//                  ACE_TEXT("mouse button [%u,%u] pressed\n"),
//                  static_cast<unsigned int>(event_in.button.which),
//                  static_cast<unsigned int>(event_in.button.button)));

      if (event_in.button.button == 1) // left-click
      {
				SDL_Rect window_area;
				getArea(window_area, true);
				myEngine->lock();
        RPG_Graphics_Position_t map_position =
					RPG_Graphics_Common_Tools::screen2Map(std::make_pair(event_in.button.x,
                                                               event_in.button.y),
                                                myEngine->getSize(false),
																								std::make_pair(window_area.w,
																								               window_area.h),
                                                myView);
        //ACE_DEBUG((LM_DEBUG,
        //           ACE_TEXT("mouse position [%u,%u] --> [%u,%u]\n"),
        //           event_in.button.x, event_in.button.y,
        //           map_position.first, map_position.second));

				RPG_Engine_EntityID_t entity_id = myEngine->getActive(false);
				myEngine->unlock();
				if ((entity_id == 0) ||
						!hasSeen(entity_id,
						         map_position))
					break; // --> no player/vision, no action...

				myEngine->lock();
				RPG_Map_Position_t current_position =
					myEngine->getPosition(entity_id, false);

				RPG_Engine_Action_t player_action;
				player_action.command = RPG_ENGINE_COMMAND_INVALID;
				player_action.position = map_position;
				//player_action.path.clear();
				player_action.target = myEngine->hasEntity(map_position, false);
				// self ?
				if (player_action.target == entity_id)
				{
					// clean up
					myEngine->unlock();

					break;
				} // end IF

				// clicked on monster ?
				if (player_action.target                    &&
						myEngine->canSee(entity_id,
						                 map_position,
						                 false)                 &&
						myEngine->isMonster(player_action.target,
						                    false))
				{
					// attack/pursue selected monster
					player_action.command = COMMAND_ATTACK;

					// reuse existing path ?
					if (!myEngine->canReach(entity_id,
																	map_position,
																	false) &&
						  (myState->selection_mode == SELECTIONMODE_PATH) &&
						  !myState->path.empty())
					{
						// sanity checks
						ACE_ASSERT(myState->path.front().first == map_position);
						ACE_ASSERT(myState->path.back().first == player_action.position);

						// path exists --> reuse it
						player_action.path = myState->path;
						player_action.path.pop_front();
						//player_action.path.pop_back();

						myState->selection_mode = SELECTIONMODE_NORMAL;
						myState->path.clear();
						// restore/clear old tile highlight background
						RPG_GRAPHICS_CURSOR_MANAGER_SINGLETON::instance()->restoreHighlightBG(myView,
																																									dirty_region,
																																									true);
						RPG_GRAPHICS_CURSOR_MANAGER_SINGLETON::instance()->putHighlight(map_position,
																																						RPG_Graphics_Common_Tools::map2Screen(map_position,
																																																									std::make_pair(window_area.w,
																																																									         			 window_area.h),
																																																				          myView),
																																						myView,
																																						dirty_region,
																																						true,
																																						myState->debug);
					} // end IF
					myEngine->action(entity_id,
													 player_action,
													 false);

					// clean up
					myEngine->unlock();

					break;
				} // end IF
				player_action.target = 0;

				// player standing next to door ?
				RPG_Map_Element map_element = myEngine->getElement(map_position, false);
				switch (map_element)
				{
					case MAPELEMENT_DOOR:
					{
						RPG_Map_DoorState door_state = myEngine->state(map_position, false);

						// (try to) handle door ?
						if (RPG_Map_Common_Tools::isAdjacent(current_position,
																	  						 map_position))
						{
							bool ignore_door = false;
							switch (door_state)
							{
								case DOORSTATE_OPEN:
									player_action.command = COMMAND_DOOR_CLOSE; break;
								case DOORSTATE_CLOSED:
								case DOORSTATE_LOCKED:
									player_action.command = COMMAND_DOOR_OPEN; break;
								case DOORSTATE_BROKEN:
									ignore_door = true; break;
								default:
								{
									ACE_DEBUG((LM_ERROR,
														 ACE_TEXT("[%u,%u]: invalid door state (was: \"%s\"), aborting\n"),
														 map_position.first, map_position.second,
														 ACE_TEXT(RPG_Map_DoorStateHelper::RPG_Map_DoorStateToString(door_state).c_str())));

									// clean up
									myEngine->unlock();

									return;
								}
							} // end SWITCH
							player_action.position = map_position;

							if (!ignore_door)
								myEngine->action(entity_id,
																 player_action,
																 false);
						} // end IF
						else if ((door_state == DOORSTATE_CLOSED) ||
											(door_state == DOORSTATE_LOCKED))
						{
							// cannot travel there --> done

							// clean up
							myEngine->unlock();

							break;
						} // end ELSEIF

						// done ?
						if (player_action.command == COMMAND_DOOR_CLOSE)
						{
							// clean up
							myEngine->unlock();

							break;
						} // end IF

						// *WARNING*: falls through !
					}
					case MAPELEMENT_FLOOR:
					{
						// floor / (open/broken) door --> (try to) travel to this position

						player_action.command = COMMAND_TRAVEL;

						// reuse existing path ?
						if ((myState->selection_mode == SELECTIONMODE_PATH) &&
								!myState->path.empty())
						{
							// sanity checks
							ACE_ASSERT(myState->path.front().first == map_position);
							ACE_ASSERT(myState->path.back().first == player_action.position);

							// path exists --> reuse it
							player_action.path = myState->path;
							player_action.path.pop_front();

							myState->selection_mode = SELECTIONMODE_NORMAL;
							myState->path.clear();
							// restore/clear old tile highlight background
							RPG_GRAPHICS_CURSOR_MANAGER_SINGLETON::instance()->restoreHighlightBG(myView,
																																										dirty_region,
																																										true);
							RPG_GRAPHICS_CURSOR_MANAGER_SINGLETON::instance()->putHighlight(map_position,
																																							RPG_Graphics_Common_Tools::map2Screen(map_position,
																																							std::make_pair(window_area.w,
																																							window_area.h),
																																							myView),
																																							myView,
																																							dirty_region,
																																							true,
																																							myState->debug);
						} // end IF

						myEngine->action(entity_id,
														 player_action,
														 false);

						break;
					}
					default:
						break;
				} // end SWITCH

        // closed door ? --> (try to) open it ?
        if (myEngine->getElement(map_position, true) == MAPELEMENT_DOOR)
        {
          RPG_Map_DoorState door_state = myEngine->state(map_position, true);

          RPG_Engine_Action_t action;
          action.command = ((door_state == DOORSTATE_OPEN) ? COMMAND_DOOR_CLOSE
                                                           : COMMAND_DOOR_OPEN);
          action.position = map_position;
					myEngine->lock();
					RPG_Engine_EntityID_t entity_id = myEngine->getActive(false);
					if (entity_id)
						myEngine->action(entity_id,
														 action,
														 false);
					myEngine->unlock();
        } // end IF
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

      // restore/clear (highlight) BG
			//RPG_GRAPHICS_CURSOR_MANAGER_SINGLETON::instance()->restoreBG(dirtyRegion_out);
      //RPG_GRAPHICS_CURSOR_MANAGER_SINGLETON::instance()->restoreHighlightBG(myView,
      //                                                                      dirtyRegion_out);
      //RPG_GRAPHICS_CURSOR_MANAGER_SINGLETON::instance()->resetHighlightBG(std::make_pair(std::numeric_limits<unsigned int>::max(),
      //                                                                                   std::numeric_limits<unsigned int>::max()));
      //invalidate(dirtyRegion_out);

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
      break;
  } // end SWITCH

	if (redraw_cursor)
	{
		if (inherited::myScreenLock)
			inherited::myScreenLock->lock();
		redrawCursor(RPG_GRAPHICS_CURSOR_MANAGER_SINGLETON::instance()->position(false),
								 restore_cursor_bg,
								 false);
		if (inherited::myScreenLock)
			inherited::myScreenLock->unlock();
	} // end IF

  // pass events to any children ?
	// --> not if this was already an upcall...
	if (window_in == this)
	{
		ACE_OS::memset(&dirty_region, 0, sizeof(dirty_region));
		inherited::handleEvent(event_in,
													 window_in,
													 dirty_region);
		dirtyRegion_out = RPG_Graphics_SDL_Tools::boundingBox(dirty_region,
																													dirtyRegion_out);
	} // end IF
}

void
SDL_GUI_LevelWindow_Isometric::initTiles()
{
	RPG_TRACE(ACE_TEXT("SDL_GUI_LevelWindow_Isometric::initTiles"));

	ACE_ASSERT(myEngine);

  // clean up
  myFloorEdgeTiles.clear();
  myWallTiles.clear();
  myDoorTiles.clear();

  // init tiles / position
  RPG_Client_Common_Tools::initFloorEdges(*myEngine,
                                          myCurrentFloorEdgeSet,
                                          myFloorEdgeTiles);
  RPG_Client_Common_Tools::initWalls(*myEngine,
                                     myCurrentWallSet,
                                     myWallTiles);
  RPG_Client_Common_Tools::initDoors(*myEngine,
                                     myCurrentDoorSet,
                                     myDoorTiles);
}

void
SDL_GUI_LevelWindow_Isometric::setView(const RPG_Map_Position_t& position_in)
{
  RPG_TRACE(ACE_TEXT("SDL_GUI_LevelWindow_Isometric::setView"));

  myView = position_in;
}

void
SDL_GUI_LevelWindow_Isometric::center()
{
	RPG_TRACE(ACE_TEXT("SDL_GUI_LevelWindow_Isometric::center"));

	ACE_ASSERT(myEngine);

  // init view
  RPG_Map_Size_t size = myEngine->getSize(true);
  setView((size.first  / 2),
          (size.second / 2));
}

void
SDL_GUI_LevelWindow_Isometric::init(const RPG_Graphics_Style& style_in)
{
  RPG_TRACE(ACE_TEXT("SDL_GUI_LevelWindow_Isometric::init"));

  // init style
  RPG_Graphics_StyleUnion style;
  style.discriminator = RPG_Graphics_StyleUnion::FLOORSTYLE;
  style.floorstyle = style_in.floor;
  if (!setStyle(style))
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to SDL_GUI_LevelWindow_Isometric::setStyle(FLOORSTYLE), continuing\n")));
  style.discriminator = RPG_Graphics_StyleUnion::EDGESTYLE;
  style.edgestyle = style_in.edge;
  if (!setStyle(style))
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to SDL_GUI_LevelWindow_Isometric::setStyle(EDGESTYLE), continuing\n")));
  style.discriminator = RPG_Graphics_StyleUnion::WALLSTYLE;
  style.wallstyle = style_in.wall;
  if (!setStyle(style))
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to SDL_GUI_LevelWindow_Isometric::setStyle(WALLSTYLE), continuing\n")));
  style.discriminator = RPG_Graphics_StyleUnion::DOORSTYLE;
  style.doorstyle = style_in.door;
  if (!setStyle(style))
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to SDL_GUI_LevelWindow_Isometric::setStyle(DOORSTYLE), continuing\n")));

  // init tiles / position
  RPG_Client_Common_Tools::initFloorEdges(*myEngine,
                                          myCurrentFloorEdgeSet,
                                          myFloorEdgeTiles);
  RPG_Client_Common_Tools::initWalls(*myEngine,
                                     myCurrentWallSet,
                                     myWallTiles);
  RPG_Client_Common_Tools::initDoors(*myEngine,
                                     myCurrentDoorSet,
                                     myDoorTiles);
}

void
SDL_GUI_LevelWindow_Isometric::notify(const RPG_Engine_Command& command_in,
                                      const RPG_Engine_ClientNotificationParameters_t& parameters_in)
{
  RPG_TRACE(ACE_TEXT("SDL_GUI_LevelWindow_Isometric::notify"));

  // sanity check(s)
  ACE_ASSERT(myEngine);

	bool update_minimap = false;
  switch (command_in)
  {
    case COMMAND_ATTACK:
      return;
    case COMMAND_DOOR_CLOSE:
    case COMMAND_DOOR_OPEN:
    {
      myEngine->lock();
      RPG_Map_DoorState door_state =
        myEngine->state(parameters_in.position, false);

      // change tile accordingly
      RPG_Graphics_Orientation orientation =
				RPG_Client_Common_Tools::getDoorOrientation(parameters_in.position,
                                                    *myEngine,
                                                    false);
      myEngine->unlock();
      switch (orientation)
      {
        case ORIENTATION_HORIZONTAL:
        {
          myDoorTiles[parameters_in.position] =
						((door_state == DOORSTATE_OPEN) ? myCurrentDoorSet.horizontal_open
                                            : myCurrentDoorSet.horizontal_closed);
          break;
        }
        case ORIENTATION_VERTICAL:
        {
          myDoorTiles[parameters_in.position] =
            ((door_state == DOORSTATE_OPEN) ? myCurrentDoorSet.vertical_open
                                            : myCurrentDoorSet.vertical_closed);
          break;
        }
        default:
        {
          ACE_DEBUG((LM_ERROR,
                     ACE_TEXT("invalid door orientation \"%s\", aborting\n"),
                     ACE_TEXT(RPG_Graphics_OrientationHelper::RPG_Graphics_OrientationToString(orientation).c_str())));

          return;
        }
      } // end SWITCH

			// redraw
			draw();
			redrawCursor(RPG_GRAPHICS_CURSOR_MANAGER_SINGLETON::instance()->position(false),
									 false);

      break;
    }
    case COMMAND_SEARCH:
    case COMMAND_STOP:
    case COMMAND_TRAVEL:
      return;
		case COMMAND_E2C_INIT:
		{
			initTiles();

			break;
		}
    case COMMAND_E2C_ENTITY_ADD:
    {
      SDL_Surface* sprite_graphic = NULL;
      RPG_Graphics_GraphicTypeUnion type;
      type.discriminator = RPG_Graphics_GraphicTypeUnion::SPRITE;
      myEngine->lock();
      type.sprite =
				(myEngine->isMonster(parameters_in.entity_id, false) ? RPG_Client_Common_Tools::monster2Sprite(myEngine->getName(parameters_in.entity_id,
				                                                                                                                 false))
                                                     				 : RPG_Client_Common_Tools::class2Sprite(myEngine->getClass(parameters_in.entity_id,
                                                                                                                        false)));
      myEngine->unlock();
      sprite_graphic =
          RPG_Graphics_Common_Tools::loadGraphic(type,   // sprite
                                                 true,   // convert to display format
                                                 false); // don't cache
      ACE_ASSERT(sprite_graphic);
      RPG_CLIENT_ENTITY_MANAGER_SINGLETON::instance()->add(parameters_in.entity_id,
                                                           sprite_graphic);

			SDL_Rect window_area, map_area;
			ACE_OS::memset(&window_area, 0, sizeof(window_area));
			ACE_OS::memset(&map_area, 0, sizeof(map_area));
			getArea(window_area, true);
			getArea(map_area, false);
			if (RPG_Client_Common_Tools::isVisible(parameters_in.position,
																						 std::make_pair(window_area.w,
																						                window_area.h),
				                                     myView,
																						 map_area))
			{
				SDL_Rect dirty_region;
				ACE_OS::memset(&dirty_region, 0, sizeof(dirty_region));
				RPG_CLIENT_ENTITY_MANAGER_SINGLETON::instance()->put(parameters_in.entity_id,
																														 RPG_Graphics_Common_Tools::map2Screen(parameters_in.position,
																																																	 std::make_pair(window_area.w,
																																																									window_area.h),
																																																	 myView),
																														 dirty_region);
				RPG_Graphics_Surface::update(dirty_region,
																		 getScreen());

				redrawCursor(RPG_GRAPHICS_CURSOR_MANAGER_SINGLETON::instance()->position(false),
										 false);
			} // end IF

			update_minimap = true;

			break;
    }
		case COMMAND_E2C_ENTITY_CONDITION:
		case COMMAND_E2C_ENTITY_HIT:
    case COMMAND_E2C_ENTITY_MISS:
      return;
    case COMMAND_E2C_ENTITY_POSITION:
    {
			SDL_Rect window_area, map_area;
			ACE_OS::memset(&window_area, 0, sizeof(window_area));
			ACE_OS::memset(&map_area, 0, sizeof(map_area));
			getArea(window_area, true);
			getArea(map_area, false);
			if (RPG_Client_Common_Tools::isVisible(parameters_in.position,
																						 std::make_pair(window_area.w,
																						                window_area.h),
																						 myView,
																						 map_area))
			{
				SDL_Rect dirty_region;
				ACE_OS::memset(&dirty_region, 0, sizeof(dirty_region));
				RPG_CLIENT_ENTITY_MANAGER_SINGLETON::instance()->put(parameters_in.entity_id,
																														 RPG_Graphics_Common_Tools::map2Screen(parameters_in.position,
																																																	 std::make_pair(window_area.w,
																																																		              window_area.h),
																																																	 myView),
																														 dirty_region);
				RPG_Graphics_Surface::update(dirty_region,
																			getScreen());

				redrawCursor(RPG_GRAPHICS_CURSOR_MANAGER_SINGLETON::instance()->position(false),
											false);
			} // end IF

			update_minimap = true;

      break;
    }
    case COMMAND_E2C_ENTITY_REMOVE:
    {
			SDL_Rect window_area, map_area;
			ACE_OS::memset(&window_area, 0, sizeof(window_area));
			ACE_OS::memset(&map_area, 0, sizeof(map_area));
			getArea(window_area, true);
			getArea(map_area, false);
			if (RPG_Client_Common_Tools::isVisible(parameters_in.position,
																						 std::make_pair(window_area.w,
																													  window_area.h),
																						 myView,
																						 map_area))
			{
				SDL_Rect dirty_region;
				ACE_OS::memset(&dirty_region, 0, sizeof(dirty_region));
				RPG_CLIENT_ENTITY_MANAGER_SINGLETON::instance()->remove(parameters_in.entity_id,
					                                                      dirty_region);
				RPG_Graphics_Surface::update(dirty_region,
																			getScreen());

				redrawCursor(RPG_GRAPHICS_CURSOR_MANAGER_SINGLETON::instance()->position(false),
											false);
			} // end IF

			update_minimap = true;

      break;
    }
		case COMMAND_E2C_ENTITY_VISION:
		{
			update_minimap = true;

			break;
		}
    case COMMAND_E2C_QUIT:
    {
      return;
    }
    default:
    {
      ACE_DEBUG((LM_ERROR,
                 ACE_TEXT("invalid command (was: \"%s\", aborting\n"),
                 ACE_TEXT(RPG_Engine_CommandHelper::RPG_Engine_CommandToString(command_in).c_str())));

      return;
    }
  } // end SWITCH

	if (update_minimap)
		updateMinimap();
}

void
SDL_GUI_LevelWindow_Isometric::toggleDoor(const RPG_Map_Position_t& position_in)
{
  RPG_TRACE(ACE_TEXT("SDL_GUI_LevelWindow_Isometric::toggleDoor"));

  // sanity check(s)
  ACE_ASSERT(myEngine);

  myEngine->lock();
  bool is_open = (myEngine->state(position_in,
                                  false) == DOORSTATE_OPEN);

  // change tile accordingly
  RPG_Graphics_Orientation orientation = RPG_GRAPHICS_ORIENTATION_INVALID;
  orientation = RPG_Client_Common_Tools::getDoorOrientation(position_in,
                                                            *myEngine,
                                                            false);
  myEngine->unlock();
  switch (orientation)
  {
    case ORIENTATION_HORIZONTAL:
    {
      myDoorTiles[position_in] =
          (is_open ? myCurrentDoorSet.horizontal_open
                   : myCurrentDoorSet.horizontal_closed);

      break;
    }
    case ORIENTATION_VERTICAL:
    {
      myDoorTiles[position_in] =
          (is_open ? myCurrentDoorSet.vertical_open
                   : myCurrentDoorSet.vertical_closed);

      break;
    }
    default:
    {
      ACE_DEBUG((LM_ERROR,
                 ACE_TEXT("invalid door orientation \"%s\", aborting\n"),
                 ACE_TEXT(RPG_Graphics_OrientationHelper::RPG_Graphics_OrientationToString(orientation).c_str())));

      return;
    }
  } // end SWITCH
}

void
SDL_GUI_LevelWindow_Isometric::setBlendRadius(const unsigned char& radius_in)
{
  RPG_TRACE(ACE_TEXT("SDL_GUI_LevelWindow_Isometric::setBlendRadius"));

  // *NOTE*: should NEVER be reached !
  ACE_ASSERT(false);

#if defined (_MSC_VER)
  return;
#else
  ACE_NOTREACHED(return;)
#endif
}

void
SDL_GUI_LevelWindow_Isometric::updateMinimap()
{
  RPG_TRACE(ACE_TEXT("SDL_GUI_LevelWindow_Isometric::updateMinimap"));

	// sanity check(s)
	if (!myMinimapIsOn)
		return; // nothing to do...

	RPG_Graphics_IWindowBase* minimap_window = child(WINDOW_MINIMAP);
	if (!minimap_window)
	{
		ACE_DEBUG((LM_ERROR,
							 ACE_TEXT("%@: failed to RPG_Graphics_SDLWindowBase::child(WINDOW_MINIMAP), aborting\n"),
							 this));

		return;
	} // end IF

	try
	{
		minimap_window->draw();
	}
	catch (...)
	{
		ACE_DEBUG((LM_ERROR,
			         ACE_TEXT("%@: caught exception in RPG_Graphics_IWindow::draw(), aborting\n"),
							 minimap_window));

		return;
	}
}

void
SDL_GUI_LevelWindow_Isometric::updateMessageWindow(const std::string& message_in)
{
  RPG_TRACE(ACE_TEXT("SDL_GUI_LevelWindow_Isometric::updateMessageWindow"));

  // *NOTE*: should NEVER be reached !
  ACE_ASSERT(false);

#if defined (_MSC_VER)
  return;
#else
  ACE_NOTREACHED(return;)
#endif
}

void
SDL_GUI_LevelWindow_Isometric::redrawCursor(const RPG_Graphics_Position_t& position_in,
                                            const bool& restoreBG_in,
                                            const bool& lockedAccess_in)
{
	RPG_TRACE(ACE_TEXT("SDL_GUI_LevelWindow_Isometric::redrawCursor"));

	// sanity check(s)
	ACE_ASSERT(myEngine);

	if (!restoreBG_in)
		RPG_GRAPHICS_CURSOR_MANAGER_SINGLETON::instance()->reset(false,
																														 lockedAccess_in,
																														 myState->debug);

	SDL_Rect dirty_region = {0, 0, 0, 0};
	myEngine->lock();
	RPG_Map_Size_t map_size = myEngine->getSize(false);
	SDL_Rect window_area = {0, 0, 0, 0};
	getArea(window_area, true);
	RPG_Map_Position_t map_position =
		RPG_Graphics_Common_Tools::screen2Map(position_in,
																					map_size,
																					std::make_pair(window_area.w,
																					               window_area.h),
																					myView);
	bool draw_highlight = RPG_Client_Common_Tools::hasHighlight(map_position,
																															*myEngine,
																															false);
	myEngine->unlock();
	RPG_GRAPHICS_CURSOR_MANAGER_SINGLETON::instance()->put(position_in,
																												 myView,
																												 map_size,
																												 dirty_region,
																												 draw_highlight,
																												 lockedAccess_in,
																												 myState->debug);
	RPG_Graphics_IWindowBase* parent = getParent();
	if (!parent)
	{
		ACE_DEBUG((LM_ERROR,
         			 ACE_TEXT("failed to RPG_Graphics_SDLWindowBase::getParent(), aborting\n")));

		return;
	} // end IF
	try
	{
		parent->invalidate(dirty_region);
		parent->update(NULL);
	}
	catch (...)
	{
		ACE_DEBUG((LM_ERROR,
			         ACE_TEXT("caught exception in RPG_Graphics_IWindowBase::invalidate/update(), aborting\n")));

		return;
	} // end IF
}

bool
SDL_GUI_LevelWindow_Isometric::setStyle(const RPG_Graphics_StyleUnion& style_in)
{
  RPG_TRACE(ACE_TEXT("SDL_GUI_LevelWindow_Isometric::setStyle"));

  switch (style_in.discriminator)
  {
    case RPG_Graphics_StyleUnion::EDGESTYLE:
    {
      RPG_Graphics_Common_Tools::loadFloorEdgeTileSet(style_in.edgestyle,
                                                      myCurrentFloorEdgeSet);
      // sanity check
      if ((myCurrentFloorEdgeSet.west.surface == NULL)       &&
          (myCurrentFloorEdgeSet.north.surface == NULL)      &&
          (myCurrentFloorEdgeSet.east.surface == NULL)       &&
          (myCurrentFloorEdgeSet.south.surface == NULL)      &&
          (myCurrentFloorEdgeSet.south_west.surface == NULL) &&
          (myCurrentFloorEdgeSet.south_east.surface == NULL) &&
          (myCurrentFloorEdgeSet.north_west.surface == NULL) &&
          (myCurrentFloorEdgeSet.north_east.surface == NULL) &&
          (myCurrentFloorEdgeSet.top.surface == NULL)        &&
          (myCurrentFloorEdgeSet.right.surface == NULL)      &&
          (myCurrentFloorEdgeSet.left.surface == NULL)       &&
          (myCurrentFloorEdgeSet.bottom.surface == NULL))
      {
        ACE_DEBUG((LM_ERROR,
                   ACE_TEXT("edge-style \"%s\" has no tiles, aborting\n"),
                   ACE_TEXT(RPG_Graphics_EdgeStyleHelper::RPG_Graphics_EdgeStyleToString(style_in.edgestyle).c_str())));

        return false;
      } // end IF
      myState->style.edge = style_in.edgestyle;

      // update floor edge tiles / position
      RPG_Client_Common_Tools::updateFloorEdges(myCurrentFloorEdgeSet,
                                                myFloorEdgeTiles);

      break;
    }
    case RPG_Graphics_StyleUnion::FLOORSTYLE:
    {
      RPG_Graphics_Common_Tools::loadFloorTileSet(style_in.floorstyle,
                                                  myCurrentFloorSet);
      // sanity check
      if (myCurrentFloorSet.tiles.empty())
      {
        ACE_DEBUG((LM_ERROR,
                   ACE_TEXT("floor-style \"%s\" has no tiles, aborting\n"),
                   ACE_TEXT(RPG_Graphics_FloorStyleHelper::RPG_Graphics_FloorStyleToString(style_in.floorstyle).c_str())));

        return false;
      } // end IF
      myState->style.floor = style_in.floorstyle;

      break;
    }
    case RPG_Graphics_StyleUnion::WALLSTYLE:
    {
      RPG_Graphics_Common_Tools::loadWallTileSet(style_in.wallstyle,
                                                 myState->style.half_height_walls,
                                                 myCurrentWallSet);
      // sanity check
      if ((myCurrentWallSet.east.surface == NULL)  ||
          (myCurrentWallSet.west.surface == NULL)  ||
          (myCurrentWallSet.north.surface == NULL) ||
          (myCurrentWallSet.south.surface == NULL))
      {
        ACE_DEBUG((LM_ERROR,
                   ACE_TEXT("wall-style \"%s\" is incomplete, aborting\n"),
                   ACE_TEXT(RPG_Graphics_WallStyleHelper::RPG_Graphics_WallStyleToString(style_in.wallstyle).c_str())));

        return false;
      } // end IF

      initWallBlend(myState->style.half_height_walls);

//#if !defined (ACE_WIN32) && !defined (ACE_WIN64)
//      std::string dump_path_base = ACE_TEXT_ALWAYS_CHAR(RPG_COMMON_DEF_DUMP_DIR);
//#else
//      std::string dump_path_base = ACE_OS::getenv(ACE_TEXT_ALWAYS_CHAR(RPG_COMMON_DEF_DUMP_DIR));
//#endif
//      dump_path_base += ACE_DIRECTORY_SEPARATOR_CHAR_A;
//      std::string dump_path;
//       dump_path = dump_path_base;
//       dump_path += ACE_TEXT("wall_n.png");
//       RPG_Graphics_Surface::savePNG(*myCurrentWallSet.north.surface, // image
//                                     dump_path,                       // file
//                                     true);                           // WITH alpha
//       dump_path = dump_path_base;
//       dump_path += ACE_TEXT("wall_s.png");
//       RPG_Graphics_Surface::savePNG(*myCurrentWallSet.south.surface, // image
//                                     dump_path,                       // file
//                                     true);                           // WITH alpha
//       dump_path = dump_path_base;
//       dump_path += ACE_TEXT("wall_w.png");
//       RPG_Graphics_Surface::savePNG(*myCurrentWallSet.west.surface, // image
//                                     dump_path,                      // file
//                                     true);                          // WITH alpha
//       dump_path = dump_path_base;
//       dump_path += ACE_TEXT("wall_e.png");
//       RPG_Graphics_Surface::savePNG(*myCurrentWallSet.east.surface, // image
//                                     dump_path,                      // file
//                                     true);                          // WITH alpha

      // *NOTE*: WEST is just a "darkened" version of EAST...
      SDL_Surface* copy = NULL;
      copy = RPG_Graphics_Surface::copy(*myCurrentWallSet.east.surface);
      if (!copy)
      {
        ACE_DEBUG((LM_ERROR,
                   ACE_TEXT("failed to RPG_Graphics_Surface::copy(), aborting\n")));

        return false;
      } // end IF
      if (SDL_BlitSurface(myWallBlend,
                          NULL,
                          copy,
                          NULL))
      {
        ACE_DEBUG((LM_ERROR,
                   ACE_TEXT("failed to SDL_BlitSurface(): \"%s\", aborting\n"),
                   ACE_TEXT(SDL_GetError())));

        // clean up
        SDL_FreeSurface(copy);

        return false;
      } // end IF
      SDL_FreeSurface(myCurrentWallSet.west.surface);
      myCurrentWallSet.west.surface = copy;

      // *NOTE*: NORTH is just a "darkened" version of SOUTH...
      copy = RPG_Graphics_Surface::copy(*myCurrentWallSet.south.surface);
      if (!copy)
      {
        ACE_DEBUG((LM_ERROR,
                   ACE_TEXT("failed to RPG_Graphics_Surface::copy(), aborting\n")));

        return false;
      } // end IF
      if (SDL_BlitSurface(myWallBlend,
                          NULL,
                          copy,
                          NULL))
      {
        ACE_DEBUG((LM_ERROR,
                   ACE_TEXT("failed to SDL_BlitSurface(): \"%s\", aborting\n"),
                   ACE_TEXT(SDL_GetError())));

        // clean up
        SDL_FreeSurface(copy);

        return false;
      } // end IF
      SDL_FreeSurface(myCurrentWallSet.north.surface);
      myCurrentWallSet.north.surface = copy;

//       dump_path = dump_path_base;
//       dump_path += ACE_TEXT("wall_n_blended.png");
//       RPG_Graphics_Surface::savePNG(*myCurrentWallSet.north.surface, // image
//                                     dump_path,                       // file
//                                     true);                           // WITH alpha
//       dump_path = dump_path_base;
//       dump_path += ACE_TEXT("wall_s_blended.png");
//       RPG_Graphics_Surface::savePNG(*myCurrentWallSet.south.surface, // image
//                                     dump_path,                       // file
//                                     true);                           // WITH alpha
//       dump_path = dump_path_base;
//       dump_path += ACE_TEXT("wall_w_blended.png");
//       RPG_Graphics_Surface::savePNG(*myCurrentWallSet.west.surface, // image
//                                     dump_path,                      // file
//                                     true);                          // WITH alpha
//       dump_path = dump_path_base;
//       dump_path += ACE_TEXT("wall_e_blended.png");
//       RPG_Graphics_Surface::savePNG(*myCurrentWallSet.east.surface, // image
//                                     dump_path,                      // file
//                                     true);                          // WITH alpha

      // adjust EAST wall opacity
      SDL_Surface* shaded_wall = NULL;
      shaded_wall =
          RPG_Graphics_Surface::alpha(*myCurrentWallSet.east.surface,
                                      static_cast<Uint8>((RPG_GRAPHICS_TILE_WALL_DEF_SE_OPACITY * SDL_ALPHA_OPAQUE)));
      if (!shaded_wall)
      {
        ACE_DEBUG((LM_ERROR,
                   ACE_TEXT("failed to RPG_Graphics_Surface::alpha(%u), aborting\n"),
                   static_cast<Uint8>((RPG_GRAPHICS_TILE_WALL_DEF_SE_OPACITY * SDL_ALPHA_OPAQUE))));

        return false;
      } // end IF
      SDL_FreeSurface(myCurrentWallSet.east.surface);
      myCurrentWallSet.east.surface = shaded_wall;

      // adjust WEST wall opacity
      shaded_wall =
          RPG_Graphics_Surface::alpha(*myCurrentWallSet.west.surface,
                                      static_cast<Uint8>((RPG_GRAPHICS_TILE_WALL_DEF_NW_OPACITY * SDL_ALPHA_OPAQUE)));
      if (!shaded_wall)
      {
        ACE_DEBUG((LM_ERROR,
                   ACE_TEXT("failed to RPG_Graphics_Surface::alpha(%u), aborting\n"),
                   static_cast<Uint8>((RPG_GRAPHICS_TILE_WALL_DEF_NW_OPACITY * SDL_ALPHA_OPAQUE))));

        return false;
      } // end IF
      SDL_FreeSurface(myCurrentWallSet.west.surface);
      myCurrentWallSet.west.surface = shaded_wall;

      // adjust SOUTH wall opacity
      shaded_wall =
          RPG_Graphics_Surface::alpha(*myCurrentWallSet.south.surface,
                                      static_cast<Uint8>((RPG_GRAPHICS_TILE_WALL_DEF_SE_OPACITY * SDL_ALPHA_OPAQUE)));
      if (!shaded_wall)
      {
        ACE_DEBUG((LM_ERROR,
                   ACE_TEXT("failed to RPG_Graphics_Surface::alpha(%u), aborting\n"),
                   static_cast<Uint8>((RPG_GRAPHICS_TILE_WALL_DEF_SE_OPACITY * SDL_ALPHA_OPAQUE))));

        return false;
      } // end IF
      SDL_FreeSurface(myCurrentWallSet.south.surface);
      myCurrentWallSet.south.surface = shaded_wall;

      // adjust NORTH wall opacity
      shaded_wall =
          RPG_Graphics_Surface::alpha(*myCurrentWallSet.north.surface,
                                      static_cast<Uint8>((RPG_GRAPHICS_TILE_WALL_DEF_NW_OPACITY * SDL_ALPHA_OPAQUE)));
      if (!shaded_wall)
      {
        ACE_DEBUG((LM_ERROR,
                   ACE_TEXT("failed to RPG_Graphics_Surface::alpha(%u), aborting\n"),
                   static_cast<Uint8>((RPG_GRAPHICS_TILE_WALL_DEF_NW_OPACITY * SDL_ALPHA_OPAQUE))));

        return false;
      } // end IF
      SDL_FreeSurface(myCurrentWallSet.north.surface);
      myCurrentWallSet.north.surface = shaded_wall;

//       dump_path = dump_path_base;
//       dump_path += ACE_TEXT("wall_n_shaded.png");
//       RPG_Graphics_Surface::savePNG(*myCurrentWallSet.north.surface, // image
//                                     dump_path,                       // file
//                                     true);                           // WITH alpha
//       dump_path = dump_path_base;
//       dump_path += ACE_TEXT("wall_s_shaded.png");
//       RPG_Graphics_Surface::savePNG(*myCurrentWallSet.south.surface, // image
//                                     dump_path,                       // file
//                                     true);                           // WITH alpha
//       dump_path = dump_path_base;
//       dump_path += ACE_TEXT("wall_w_shaded.png");
//       RPG_Graphics_Surface::savePNG(*myCurrentWallSet.west.surface, // image
//                                     dump_path,                      // file
//                                     true);                          // WITH alpha
//       dump_path = dump_path_base;
//       dump_path += ACE_TEXT("wall_e_shaded.png");
//       RPG_Graphics_Surface::savePNG(*myCurrentWallSet.east.surface, // image
//                                     dump_path,                      // file
//                                     true);                          // WITH alpha

      // update wall tiles / position
      RPG_Client_Common_Tools::updateWalls(myCurrentWallSet,
                                           myWallTiles);

      myState->style.wall = style_in.wallstyle;

      break;
    }
    case RPG_Graphics_StyleUnion::DOORSTYLE:
    {
      RPG_Graphics_Common_Tools::loadDoorTileSet(style_in.doorstyle,
                                                 myCurrentDoorSet);
      // sanity check
      if ((myCurrentDoorSet.horizontal_open.surface == NULL)   ||
          (myCurrentDoorSet.vertical_open.surface == NULL)     ||
          (myCurrentDoorSet.horizontal_closed.surface == NULL) ||
          (myCurrentDoorSet.vertical_closed.surface == NULL)   ||
          (myCurrentDoorSet.broken.surface == NULL))
      {
        ACE_DEBUG((LM_ERROR,
                   ACE_TEXT("door-style \"%s\" is incomplete, continuing\n"),
                   ACE_TEXT(RPG_Graphics_DoorStyleHelper::RPG_Graphics_DoorStyleToString(style_in.doorstyle).c_str())));

        return false;
      } // end IF

      // update door tiles / position
      RPG_Client_Common_Tools::updateDoors(myCurrentDoorSet,
                                           *myEngine,
                                           myDoorTiles);

      myState->style.door = style_in.doorstyle;

      break;
    }
    default:
    {
      ACE_DEBUG((LM_ERROR,
                 ACE_TEXT("invalid style (was: %d), aborting\n"),
                 style_in.discriminator));

      return false;
    }
  } // end SWITCH

  return true;
}

void
SDL_GUI_LevelWindow_Isometric::initCeiling()
{
  RPG_TRACE(ACE_TEXT("SDL_GUI_LevelWindow_Isometric::initCeiling"));

  // sanity check
  if (myCurrentCeilingTile)
  {
    SDL_FreeSurface(myCurrentCeilingTile);
    myCurrentCeilingTile = NULL;
  } // end IF

  // load tile for ceiling
  RPG_Graphics_GraphicTypeUnion type;
  type.discriminator = RPG_Graphics_GraphicTypeUnion::TILEGRAPHIC;
  type.tilegraphic = TILE_CEILING;
  myCurrentCeilingTile = RPG_Graphics_Common_Tools::loadGraphic(type,   // tile
                                                                true,   // convert to display format
                                                                false); // don't cache
  if (!myCurrentCeilingTile)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to RPG_Graphics_Common_Tools::loadGraphic(\"%s\"), aborting\n"),
               ACE_TEXT(RPG_Graphics_Common_Tools::typeToString(type).c_str())));

    return;
  } // end IF

  SDL_Surface* shaded_ceiling = NULL;
  Uint8 opacity = static_cast<Uint8>(RPG_GRAPHICS_TILE_WALL_DEF_NW_OPACITY *
                                     SDL_ALPHA_OPAQUE);
  shaded_ceiling = RPG_Graphics_Surface::alpha(*myCurrentCeilingTile,
                                               opacity);
  if (!shaded_ceiling)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to RPG_Graphics_Surface::alpha(%u), aborting\n"),
               opacity));

    // clean up
    SDL_FreeSurface(myCurrentCeilingTile);
    myCurrentCeilingTile = NULL;

    return;
  } // end IF

  SDL_FreeSurface(myCurrentCeilingTile);
  myCurrentCeilingTile = shaded_ceiling;
}

void
SDL_GUI_LevelWindow_Isometric::initWallBlend(const bool& halfHeightWalls_in)
{
  RPG_TRACE(ACE_TEXT("SDL_GUI_LevelWindow_Isometric::initWallBlend"));

  // sanity check
  if (myWallBlend)
  {
    SDL_FreeSurface(myWallBlend);
    myWallBlend = NULL;
  } // end IF

  myWallBlend =
      RPG_Graphics_Surface::create(RPG_GRAPHICS_TILE_WALL_WIDTH,
                                   (halfHeightWalls_in ? RPG_GRAPHICS_TILE_WALL_HEIGHT_HALF
                                                       : RPG_GRAPHICS_TILE_WALL_HEIGHT));
  if (!myWallBlend)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to RPG_Graphics_Surface::create(%u,%u), aborting\n"),
               RPG_GRAPHICS_TILE_WALL_WIDTH,
               (halfHeightWalls_in ? RPG_GRAPHICS_TILE_WALL_HEIGHT_HALF
                                   : RPG_GRAPHICS_TILE_WALL_HEIGHT)));

    return;
  } // end IF

  if (SDL_FillRect(myWallBlend,
                   NULL,
                   RPG_Graphics_SDL_Tools::getColor(COLOR_BLACK_A10,
                                                    *myWallBlend)))
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to SDL_FillRect(): %s, aborting\n"),
               ACE_TEXT(SDL_GetError())));

    // clean up
    SDL_FreeSurface(myWallBlend);
    myWallBlend = NULL;

    return;
  } // end IF

//   std::string dump_path_base = ACE_TEXT_ALWAYS_CHAR(RPG_COMMON_DEF_DUMP_DIR);
//   dump_path_base += ACE_DIRECTORY_SEPARATOR_CHAR_A;
//   std::string dump_path = dump_path_base;
//   dump_path += ACE_TEXT("wall_blend.png");
//   RPG_Graphics_Surface::savePNG(*myWallBlend, // image
//                                 dump_path,    // file
//                                 true);        // WITH alpha
}

void
SDL_GUI_LevelWindow_Isometric::initMiniMap(RPG_Engine* engine_in)
{
  RPG_TRACE(ACE_TEXT("SDL_GUI_LevelWindow_Isometric::initMiniMap"));

  SDL_GUI_MinimapWindow* minimap_window = NULL;
  ACE_NEW_NORETURN(minimap_window,
                   SDL_GUI_MinimapWindow(*this,
																				 std::make_pair(std::numeric_limits<int>::max(),
																												std::numeric_limits<int>::max()),
                                         engine_in));
  if (!minimap_window)
  {
    ACE_DEBUG((LM_CRITICAL,
               ACE_TEXT("failed to allocate memory(%u): %m, aborting\n"),
               sizeof(SDL_GUI_MinimapWindow)));

    return;
  } // end IF
  // *NOTE* cannot init screen lock (has not been set), do it later...
//  minimap_window->init(inherited::myScreenLock);
}

bool
SDL_GUI_LevelWindow_Isometric::hasSeen(const RPG_Engine_EntityID_t& id_in,
																			 const RPG_Map_Position_t& position_in) const
{
	RPG_TRACE(ACE_TEXT("SDL_GUI_LevelWindow_Isometric::hasSeen"));

	RPG_Client_SeenPositionsConstIterator_t iterator =
		myState->seen_positions.find(id_in);
	if (iterator == myState->seen_positions.end())
		return false;

	RPG_Map_PositionsConstIterator_t iterator2 =
		(*iterator).second.find(position_in);
	return (iterator2 != (*iterator).second.end());
}
