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

#ifndef RPG_MAP_LEVEL_H
#define RPG_MAP_LEVEL_H

#include <string>

#include "ace/Global_Macros.h"

#include "common_idumpstate.h"

#include "rpg_map_defines.h"
#include "rpg_map_common.h"

class RPG_Map_Level
 : public Common_IDumpState
{
 public:
  RPG_Map_Level (const struct RPG_Map&); // map
  inline virtual ~RPG_Map_Level () {}

  // static functionality
  static void create (const struct RPG_Map_FloorPlan_Configuration&, // floor plan config
                      struct RPG_Map&);                              // return value: map
  static bool load (const std::string&,                // FQ filename
                    struct RPG_Map&,                   // return value: map
                    bool = RPG_MAP_DEF_TRACE_SCANNING, // trace scanning ?
                    bool = RPG_MAP_DEF_TRACE_PARSING); // trace parsing ?
  static void random (const struct RPG_Map_FloorPlan_Configuration&, // floor plan config
                      struct RPG_Map&);                              // return value: map  
  static void print (const struct RPG_Map&); // map
  static std::string string (const struct RPG_Map&); // map
  static std::string info (const struct RPG_Map&); // map

  void init (const struct RPG_Map&); // map
  void save (const std::string&) const; // FQ filename
  // implement RPG_Common_IDumpState
  virtual void dump_state () const;

  inline RPG_Map_Position_t getStartPosition () const { return myMap.start; }
  inline RPG_Map_Positions_t getSeedPoints () const { return myMap.seeds; }
  inline struct RPG_Map_FloorPlan getFloorPlan () const { return myMap.plan; }
  inline RPG_Map_Size_t getSize () const { return std::make_pair (myMap.plan.size_x, myMap.plan.size_y); }
  enum RPG_Map_DoorState state (const RPG_Map_Position_t&) const;
  inline struct RPG_Map getMap () const { return myMap; }

  // either floor or an open/broken (!) door ?
  bool isValid (const RPG_Map_Position_t&) const;
  bool isCorner (const RPG_Map_Position_t&) const;
  enum RPG_Map_Element getElement (const RPG_Map_Position_t&) const;
  RPG_Map_Positions_t getObstacles () const;

  bool findPath (const RPG_Map_Position_t&, // start position
                 const RPG_Map_Position_t&, // end position
                 RPG_Map_Path_t&) const;    // return value: (partial) path A --> B
  void findValid (const RPG_Map_Position_t&,   // center
                  unsigned int,                // max (square !) radius
                  RPG_Map_Positions_t&) const; // return value: area

 protected:
  RPG_Map_Level ();

  struct RPG_Map myMap;

 private:
  ACE_UNIMPLEMENTED_FUNC (RPG_Map_Level (const RPG_Map_Level&))
  ACE_UNIMPLEMENTED_FUNC (RPG_Map_Level& operator= (const RPG_Map_Level&))
};

#endif
