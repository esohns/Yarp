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

#ifndef RPG_MAP_DEFINES_H
#define RPG_MAP_DEFINES_H

// min distance between any 2 doors of a single room
#define RPG_MAP_DOOR_SEPARATION    1

// output more debugging information
#define RPG_MAP_DEF_TRACE_SCANNING false
#define RPG_MAP_DEF_TRACE_PARSING  false

#define RPG_MAP_SCANNER_BUFSIZE    16384 // == to YY_BUF_SIZE

#define RPG_MAP_EXT                ".txt"

#define RPG_MAP_DEF_MAP            "default_map"

#define RPG_MAP_NAME_MAX_LENGTH    30
#define RPG_MAP_DEF_NAME           "default map"

#if !defined (ACE_WIN32) && !defined (ACE_WIN64)
#define RPG_MAP_DEF_REPOSITORY     "/var/tmp"
#else
#define RPG_MAP_DEF_REPOSITORY     "TEMP" // environment
#endif

#endif
