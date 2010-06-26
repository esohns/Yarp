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

#ifndef RPG_GRAPHICS_DEFINES_H
#define RPG_GRAPHICS_DEFINES_H

// #signature bytes to check for PNG graphics
#define RPG_GRAPHICS_PNG_SIGNATURE_BYTES  8

// min #screen refreshes / second of fading
#define RPG_GRAPHICS_FADE_REFRESH_RATE    10

// default font pointsize
#define RPG_GRAPHICS_FONT_DEF_POINTSIZE   10

// default text colors
#define RPG_GRAPHICS_FONT_DEF_COLOR       RPG_Graphics_Common_Tools::CLR32_WHITE
#define RPG_GRAPHICS_FONT_DEF_SHADECOLOR  RPG_Graphics_Common_Tools::CLR32_BLACK

// default (tiles) data directory tree organization
#define RPG_GRAPHICS_TILES_DEF_FLOORS_SUB ACE_TEXT("floors")

// tile drawing: pixel coordinate difference from a square to the one next to
// it in the map. Because of isometry, this is not the same as the width/height
// of a tile !
#define RPG_GRAPHICS_V_MAP_XMOD           56
#define RPG_GRAPHICS_V_MAP_YMOD           22

#endif
