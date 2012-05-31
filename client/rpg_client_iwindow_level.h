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

#ifndef RPG_CLIENT_IWINDOW_LEVEL_H
#define RPG_CLIENT_IWINDOW_LEVEL_H

#include "rpg_client_iwindow.h"

#include <rpg_map_common.h>

class RPG_Client_IWindowLevel
 : public RPG_Client_IWindow
{
 public:
  // *NOTE*: to shut up the compiler (gcc4) complaining about missing virtual dtors, set
  // -Wno-non-virtual-dtor in the project settings...

  // exposed interface
  virtual void init() = 0;
  virtual void setView(const RPG_Map_Position_t&) = 0; // view (map coordinates !)
  virtual RPG_Map_Position_t getView() const = 0; // return value: view (map coordinates !)

  virtual void toggleDoor(const RPG_Map_Position_t&) = 0; // door position
  virtual void setBlendRadius(const unsigned char&) = 0; // radius
  virtual void updateMinimap() = 0;
};

#endif
