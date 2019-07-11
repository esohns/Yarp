﻿/***************************************************************************
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

#ifndef RPG_CLIENT_ENGINE_H
#define RPG_CLIENT_ENGINE_H

#include "ace/Atomic_Op_T.h"
#include "ace/Condition_T.h"
#include "ace/Global_Macros.h"
#include "ace/Synch_Traits.h"
#include "ace/Task.h"

//#include "common_icontrol.h"
#include "common_idumpstate.h"
#include "common_ilock.h"

#include "rpg_graphics_iwindow_base.h"
#include "rpg_graphics_style.h"

#include "rpg_engine_common.h"
#include "rpg_engine_iclient.h"

#include "rpg_client_common.h"
//#include "rpg_client_exports.h"

// forward declaration(s)
class RPG_Engine;

/**
	@author Erik Sohns <erik.sohns@web.de>
*/
class RPG_Client_Engine
 : public ACE_Task<ACE_MT_SYNCH>
 , public RPG_Engine_IClient
 , public Common_ILock
 //, public Common_IControl
 , public Common_IDumpState
{
 public:
  RPG_Client_Engine();
  virtual ~RPG_Client_Engine ();

  // implement Common_IControl
  virtual void start ();
  virtual void stop (bool = true); // locked access ?
  virtual bool isRunning () const;

  // implement Common_IDumpState
  virtual void dump_state () const;

  // implement Common_ILock
  virtual bool lock (bool = true); // block ?
  virtual int unlock (bool = false); // unlock completely ?

  void redraw ();
  // *TODO* these need consideration/redesign
  void setStyle (const RPG_Graphics_Style&); // style
  RPG_Graphics_Style getStyle () const; // return value: graphics style
  // *NOTE*: this triggers a complete redraw !
  void setView (const RPG_Map_Position_t&);

  // implement RPG_Engine_IWindow
  // *NOTE*: these are to be called by the level engine ONLY
  //virtual void redraw();
  //// *NOTE*: this triggers a complete redraw !
  //virtual void setView(const RPG_Map_Position_t&);
  //virtual void toggleDoor(const RPG_Map_Position_t&);
  //virtual void addEntity(const RPG_Engine_EntityID_t&,
  //                       const SDL_Surface*);
  //virtual void removeEntity(const RPG_Engine_EntityID_t&);
  //virtual void updateEntity(const RPG_Engine_EntityID_t&);
  virtual void notify (enum RPG_Engine_Command,
                       const struct RPG_Engine_ClientNotificationParameters&);

  // *WARNING*: window handle needs to be of WINDOW_MAP type !!!
  void initialize (RPG_Engine*,               // (level) state
                   RPG_Graphics_IWindowBase*, // window handle
                   //RPG_Client_IWidgetUI_t*,   // widget UI interface handle
                   bool = false);             // debug ?
  void action (const RPG_Client_Action&); // action

  void mode (const RPG_Client_SelectionMode&); // set mode
  //void clear(const RPG_Client_SelectionMode&); // clear mode
  RPG_Client_SelectionMode mode () const; // return value: current mode
  bool hasSeen (const RPG_Engine_EntityID_t&, // entity
                const RPG_Map_Position_t&,    // position
                bool = true) const;           // locked access ?

  void centerOnActive (bool); // keep active player centered ?
  bool getCenterOnActive () const; // return value: keep active player centered ?

 private:
  typedef ACE_Task<ACE_MT_SYNCH> inherited;

  ACE_UNIMPLEMENTED_FUNC (RPG_Client_Engine (const RPG_Client_Engine&));
  ACE_UNIMPLEMENTED_FUNC (RPG_Client_Engine& operator=(const RPG_Client_Engine&));

  // override task-based members
//   virtual int open(void* = NULL);
  virtual int close (u_long = 0);
  virtual int svc (void);

  // process actions
  void handleActions ();

  // *IMPORTANT NOTE*: need this ONLY to handle control messages...
//   RPG_Engine_MessageQueue         myQueue;

  // make our API re-entrant
  mutable ACE_Thread_Mutex        myLock;
  // implement blocking wait...
  ACE_Condition<ACE_Thread_Mutex> myCondition;

  bool                            myStop;

  RPG_Engine*                     myEngine;
  RPG_Graphics_IWindowBase*       myWindow;
  //RPG_Client_IWidgetUI_t*         myWidgetInterface;

  RPG_Client_Actions_t            myActions;
  struct RPG_Client_State         myRuntimeState;

  RPG_Client_SelectionMode        mySelectionMode;
  RPG_Client_SeenPositions_t      mySeenPositions;
  bool                            myCenterOnActivePlayer;
  ACE_Thread_Mutex                myScreenLock;
  bool                            myDebug;
};

#endif
