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

#ifndef NET_CLIENT_SIGNALHANDLER_H
#define NET_CLIENT_SIGNALHANDLER_H

#include "rpg_net_client_iconnector.h"

#include <ace/Global_Macros.h>
#include <ace/Event_Handler.h>
#include <ace/INET_Addr.h>

class Net_Client_SignalHandler
 : public ACE_Event_Handler
{
 public:
  Net_Client_SignalHandler(const long&,                // interval timer handle
                           const ACE_INET_Addr&,       // peer SAP
                           RPG_Net_Client_IConnector*, // connector
                           const bool&);               // use reactor ?
  virtual ~Net_Client_SignalHandler();

  // *NOTE*: just save state and notify the reactor
  virtual int handle_signal(int,                 // signal
                            siginfo_t* = NULL,   // not needed on UNIX
                            ucontext_t* = NULL); // not used
  // implement specific behaviour
  virtual int handle_exception(ACE_HANDLE = ACE_INVALID_HANDLE); // handle

 private:
  typedef ACE_Event_Handler inherited;

  // safety measures
  ACE_UNIMPLEMENTED_FUNC(Net_Client_SignalHandler());
  ACE_UNIMPLEMENTED_FUNC(Net_Client_SignalHandler(const Net_Client_SignalHandler&));
  ACE_UNIMPLEMENTED_FUNC(Net_Client_SignalHandler& operator=(const Net_Client_SignalHandler&));

  long                       myTimerID;
  ACE_INET_Addr              myPeerAddress;
  RPG_Net_Client_IConnector* myConnector;
  bool                       myUseReactor;
  int                        mySignal;
  siginfo_t                  mySigInfo;
  ucontext_t                 myUContext;
};

#endif
