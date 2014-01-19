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

#ifndef RPG_CLIENT_GTK_MANAGER_H
#define RPG_CLIENT_GTK_MANAGER_H

#include "rpg_client_exports.h"

#include "rpg_common_task_base.h"
#include "rpg_common_icontrol.h"

#include <ace/Singleton.h>
#include <ace/Synch.h>

/**
  @author Erik Sohns <erik.sohns@web.de>
 */
class RPG_Client_Export RPG_Client_GTK_Manager
 : public RPG_Common_TaskBase<ACE_MT_SYNCH>,
   public RPG_Common_IControl
{
  // singleton requires access to the ctor/dtor
  friend class ACE_Singleton<RPG_Client_GTK_Manager,
                             ACE_Recursive_Thread_Mutex>;

 public:
  // implement RPG_Common_IControl
  virtual void start();
  virtual void stop();
  virtual bool isRunning() const;

 private:
  typedef RPG_Common_TaskBase<ACE_MT_SYNCH> inherited;

  // override ACE_Task_Base member(s)
  virtual int svc(void);

  virtual ~RPG_Client_GTK_Manager();
  RPG_Client_GTK_Manager();
  ACE_UNIMPLEMENTED_FUNC(RPG_Client_GTK_Manager(const RPG_Client_GTK_Manager&));
  ACE_UNIMPLEMENTED_FUNC(RPG_Client_GTK_Manager& operator=(const RPG_Client_GTK_Manager&));
};

typedef ACE_Singleton<RPG_Client_GTK_Manager,
                      ACE_Recursive_Thread_Mutex> RPG_CLIENT_GTK_MANAGER_SINGLETON;
RPG_CLIENT_SINGLETON_DECLARE(ACE_Singleton,
                             RPG_Client_GTK_Manager,
                             ACE_Recursive_Thread_Mutex);
#endif