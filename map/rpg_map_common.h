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

#ifndef RPG_MAP_COMMON_H
#define RPG_MAP_COMMON_H

#include <string>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <functional>

enum RPG_Map_Element
{
  // *** basic ***
  MAPELEMENT_UNMAPPED = 0,
  MAPELEMENT_FLOOR,
  MAPELEMENT_STAIRS,
  MAPELEMENT_WALL,
  MAPELEMENT_DOOR,
//   // *** composite ***
//   MAPELEMENT_VAULT,
//   MAPELEMENT_ROOM,
//   MAPELEMENT_SUBROOM,
//   MAPELEMENT_CORRIDOR,
  //
  MAPELEMENT_MAX,
  MAPELEMENT_INVALID
};

struct RPG_Map_FloorPlan_Config_t
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

typedef std::pair<unsigned int, unsigned int> RPG_Map_Size_t;

typedef std::pair<unsigned int, unsigned int> RPG_Map_Position_t;
typedef std::set<RPG_Map_Position_t> RPG_Map_Positions_t;
typedef RPG_Map_Positions_t::const_iterator RPG_Map_PositionsConstIterator_t;
typedef RPG_Map_Positions_t::iterator RPG_Map_PositionsIterator_t;
typedef std::list<RPG_Map_Position_t> RPG_Map_PositionList_t;
typedef RPG_Map_PositionList_t::const_iterator RPG_Map_PositionListConstIterator_t;
typedef RPG_Map_PositionList_t::iterator RPG_Map_PositionListIterator_t;

enum RPG_Map_Direction
{
  DIRECTION_UP = 0,
  DIRECTION_RIGHT,
  DIRECTION_DOWN,
  DIRECTION_LEFT,
  //
  DIRECTION_MAX,
  DIRECTION_INVALID
};
typedef std::set<RPG_Map_Direction> RPG_Map_Directions_t;
typedef RPG_Map_Directions_t::const_iterator RPG_Map_DirectionsConstIterator_t;

struct RPG_Map_Door_t
{
  inline bool operator==(const RPG_Map_Door_t& rhs_in) const
  {
    return (position == rhs_in.position);
  }
  inline bool operator!=(const RPG_Map_Door_t& rhs_in) const
  {
    return !(position == rhs_in.position);
  }

  RPG_Map_Position_t position;
  RPG_Map_Direction outside;
  bool is_open;
  bool is_locked;
  bool is_broken;
};
struct door_compare
 : public std::binary_function<RPG_Map_Door_t, RPG_Map_Door_t, bool>
{
  inline bool operator()(const RPG_Map_Door_t& __x,
                         const RPG_Map_Door_t& __y) const
  {
    return (__x.position < __y.position);
  }
};
typedef std::set<RPG_Map_Door_t, door_compare> RPG_Map_Doors_t;
typedef RPG_Map_Doors_t::const_iterator RPG_Map_DoorsConstIterator_t;
typedef RPG_Map_Doors_t::iterator RPG_Map_DoorsIterator_t;

struct RPG_Map_FloorPlan_t
{
  unsigned int size_x;
  unsigned int size_y;
  RPG_Map_Positions_t unmapped; // (!floor)
  RPG_Map_Positions_t walls;
  RPG_Map_Doors_t doors;
};

struct RPG_Map_t
{
  std::string name;          // name
  RPG_Map_Position_t start;  // starting position
  RPG_Map_Positions_t seeds; // seed points
  RPG_Map_FloorPlan_t plan;  // floor plan
};

typedef std::pair<RPG_Map_Position_t, RPG_Map_Direction> RPG_Map_PathStep_t;
typedef std::list<RPG_Map_PathStep_t> RPG_Map_Path_t;
typedef RPG_Map_Path_t::const_iterator RPG_Map_PathConstIterator_t;
typedef std::list<RPG_Map_Path_t> RPG_Map_PathList_t;
typedef RPG_Map_PathList_t::const_iterator RPG_Map_PathListConstIterator_t;

enum RPG_Map_Orientation
{
  MAP_ORIENTATION_HORIZONTAL = 0,
  MAP_ORIENTATION_VERTICAL,
  //
  MAP_ORIENTATION_INVALID,
  MAP_ORIENTATION_MAX
};

#endif
