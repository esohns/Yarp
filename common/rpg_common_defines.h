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

#ifndef RPG_COMMON_DEFINES_H
#define RPG_COMMON_DEFINES_H

// *** trace log ***
// *PORTABILITY*: pathnames are not portable, so we (try to) use %TEMP% for Windows...
#if defined (ACE_WIN32) || defined (ACE_WIN64)
#define RPG_COMMON_DEF_LOG_DIRECTORY              "TEMP"
#else
#define RPG_COMMON_DEF_LOG_DIRECTORY              "/var/tmp"
#endif
#define RPG_COMMON_LOG_FILENAME_SUFFIX            ".log"

#define RPG_COMMON_MAX_SPELL_LEVEL                9
#define RPG_COMMON_MAX_CLASS_LEVEL                20

// general stuff
// *WARNING*: make sure group IDs are consistent !!!
#define RPG_COMMON_TIMER_THREAD_GROUP_ID          100
#define RPG_COMMON_TIMER_THREAD_NAME              "RPG timer dispatch"
#define RPG_COMMON_EVENT_DISPATCH_THREAD_GROUP_ID 101
#define RPG_COMMON_EVENT_DISPATCH_THREAD_NAME     "RPG event dispatch"
// *NOTE*: use ACE_DEFAULT_TIMERS instead ?
#define RPG_COMMON_MAX_TIMER_SLOTS                1024
// *IMPORTANT NOTE*: used for libc calls (i.e. char buffers, mostly)
#define RPG_COMMON_BUFSIZE                        512 // bytes

// XML-specific
// *NOTE*: refer to the XSD C++/Tree manual for details
#define RPG_COMMON_XML_SCHEMA_CHARSET             "UTF-8"
#define RPG_COMMON_XML_TARGET_NAMESPACE           "urn:rpg"
#define RPG_COMMON_XML_SCHEMA_FILE_EXT            ".xsd"

// BASEDIR-specific
#define RPG_COMMON_DATA_SUB                       "data"
#define RPG_COMMON_CONFIG_SUB                     "config"

#if !defined(ACE_WIN32) && !defined(ACE_WIN64)
#define RPG_COMMON_DEF_DUMP_DIR                   "/var/tmp"
#else
#define RPG_COMMON_DEF_DUMP_DIR                   "TEMP" // environment
#endif

#if !defined(ACE_WIN32) && !defined(ACE_WIN64)
#define RPG_COMMON_DEF_USER_LOGIN_BASE            "LOGNAME" // environment
#else
#define RPG_COMMON_DEF_USER_LOGIN_BASE            "USERNAME" // environment
#endif

#endif
