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

#ifndef RPG_CLIENT_COMMON_H
#define RPG_CLIENT_COMMON_H

#include "rpg_client_window_main.h"
#include "rpg_client_window_level.h"

#include <rpg_graphics_common.h>
#include <rpg_graphics_iwindow.h>

#include <rpg_map_common.h>

#include <rpg_character_player.h>

#include <glade/glade.h>
#include <SDL/SDL.h>

#include <string>

struct GTK_cb_data_t
{
  GladeXML*               xml;
  SDL_TimerID             event_timer;
  RPG_Graphics_IWindow*   previous_window;
  RPG_Client_WindowMain*  main_window;
  RPG_Client_WindowLevel* map_window;
  RPG_Map_FloorPlan_t     plan;
  RPG_Map_Positions_t     seedPoints;
  RPG_Character_Player    player;
};

// *NOTE* types as used by SDL
struct SDL_audio_config_t
{
  int    frequency;
  Uint16 format;
//   Uint8  channels;
  int    channels;
  Uint16 samples;
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

struct RPG_Client_Config
{
  // *** reactor ***
  unsigned long      num_threadpool_threads; // 0: don't use threadpool
  // *** UI ***
  std::string        glade_file;
//   GTK_cb_data_t      gtk_cb_data;
  // *** sound ***
  SDL_audio_config_t audio_config;
  std::string        sound_directory;
  unsigned long      sound_cache_size;
  std::string        sound_dictionary;
  // *** graphics ***
  SDL_video_config_t video_config;
  std::string        graphics_directory;
  unsigned long      graphics_cache_size;
  std::string        graphics_dictionary;
  // *** magic ***
  std::string        magic_dictionary;
  // *** item ***
  std::string        item_dictionary;
  // *** monster ***
  std::string        monster_dictionary;
  // *** map ***
  map_config_t       map_config;
  std::string        map_file;
};

#endif
