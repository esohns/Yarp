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

#ifndef NET_COMMON_H
#define NET_COMMON_H

#include "rpg_client_common.h"

#include "rpg_net_common.h"

#include <glade/glade.h>

#include <ace/Synch.h>

// forward declaration(s)
class Net_Client_TimeoutHandler;
class RPG_Net_Server_IListener;

struct Net_GTK_CBData_t
{
 inline Net_GTK_CBData_t()
  : lock(NULL, NULL),
    xml(NULL),
//    log_stack(),
//    subscribers(),
    timeout_handler(NULL),
    timer_id(-1),
    listener_handle(NULL)
 { };

 mutable ACE_Recursive_Thread_Mutex lock;
 GladeXML*                          xml;
 RPG_Client_MessageStack_t          log_stack;
 RPG_Net_NotifySubscribers_t        subscribers;
 Net_Client_TimeoutHandler*         timeout_handler; // *NOTE*: client only !
 long                               timer_id;        // *NOTE*: client only !
 RPG_Net_Server_IListener*          listener_handle; // *NOTE*: server only !
};

#endif
