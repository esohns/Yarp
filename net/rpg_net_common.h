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

#ifndef RPG_NET_COMMON_H
#define RPG_NET_COMMON_H

#include "rpg_net_exports.h"
//#include "rpg_net_remote_comm.h"
#include "rpg_net_connection_manager.h"

#include <ace/Time_Value.h>
#include <ace/Singleton.h>
#include <ace/Synch.h>

// forward declaration(s)
class RPG_Stream_IAllocator;
class RPG_Stream_Module;

struct RPG_Net_RuntimeStatistic
{
  unsigned long numDataMessages; // (protocol) messages
  double        numBytes;        // amount of processed data

  // convenience
  inline RPG_Net_RuntimeStatistic operator+=(const RPG_Net_RuntimeStatistic& rhs)
  {
    numDataMessages += rhs.numDataMessages;
    numBytes += rhs.numBytes;

    return *this;
  };
};

struct RPG_Net_ConfigPOD
{
  // ************ connection config data ************
  unsigned long            clientPingInterval; // used by the server...
  int                      socketBufferSize;
  RPG_Stream_IAllocator*   messageAllocator;
  unsigned long            defaultBufferSize;
  // ************ stream config data ************
  RPG_Stream_Module*       module;
  unsigned long            sessionID; // (== socket handle !)
  unsigned long            statisticsReportingInterval;
  // ************ runtime data ************
  RPG_Net_RuntimeStatistic currentStatistics;
  ACE_Time_Value           lastCollectionTimestamp;
};

template <typename ConfigType,
          typename StatisticsContainerType> class RPG_Net_Connection_Manager;
typedef RPG_Net_Connection_Manager<RPG_Net_ConfigPOD,
                                   RPG_Net_RuntimeStatistic> RPG_Net_Connection_Manager_t;
typedef ACE_Singleton<RPG_Net_Connection_Manager_t,
                      ACE_Recursive_Thread_Mutex> RPG_NET_CONNECTIONMANAGER_SINGLETON;
RPG_NET_SINGLETON_DECLARE(ACE_Singleton,
			                    RPG_Net_Connection_Manager_t,
													ACE_Recursive_Thread_Mutex);

#endif
