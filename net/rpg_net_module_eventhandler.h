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

#ifndef RPG_Net_Module_EventHandler_H
#define RPG_Net_Module_EventHandler_H

#include "ace/Global_Macros.h"
#include "ace/Synch.h"

#include "common.h"
#include "common_isubscribe.h"
#include "common_iclone.h"

#include "stream_common.h"
#include "stream_task_base_synch.h"
#include "stream_streammodule_base.h"

#include "net_common.h"
#include "net_message.h"
#include "net_sessionmessage.h"
#include "net_module_messagehandler.h"

#include "rpg_net_exports.h"

// forward declaration(s)
class Net_SessionMessage;
class Net_Message;

class RPG_Net_Export RPG_Net_Module_EventHandler
 : public Net_Module_MessageHandler_T<Stream_ModuleConfiguration_t,
                                      Net_SessionMessage,
                                      Net_Message>
{
 public:
  RPG_Net_Module_EventHandler ();
  virtual ~RPG_Net_Module_EventHandler ();

  // implement Common_IClone_T
  virtual Common_Module_t* clone ();

 private:
  typedef Net_Module_MessageHandler_T<Stream_ModuleConfiguration_t,
                                      Net_SessionMessage,
                                      Net_Message> inherited;

  ACE_UNIMPLEMENTED_FUNC (RPG_Net_Module_EventHandler (const RPG_Net_Module_EventHandler&));
  ACE_UNIMPLEMENTED_FUNC (RPG_Net_Module_EventHandler& operator= (const RPG_Net_Module_EventHandler&));

  //// *NOTE*: recursive so that users may unsubscribe from within the
  //// notification callbacks...
  //ACE_Recursive_Thread_Mutex lock_;
  //Net_Subscribers_t          subscribers_;
};

// declare module
DATASTREAM_MODULE_INPUT_ONLY (ACE_MT_SYNCH,                 // task synch type
                              Common_TimePolicy_t,          // time policy
                              Stream_ModuleConfiguration_t, // configuration type
                              RPG_Net_Module_EventHandler); // writer type

#endif
