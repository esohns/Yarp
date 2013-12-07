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

#ifndef RPG_COMMON_REFERENCE_COUNTER_H
#define RPG_COMMON_REFERENCE_COUNTER_H

#include "rpg_common_exports.h"
#include "rpg_common_irefcount.h"
#include "rpg_common_idumpstate.h"

#include <ace/Global_Macros.h>
#include <ace/Condition_T.h>
#include <ace/Synch.h>

class RPG_Common_Export RPG_Common_ReferenceCounter
 : public RPG_Common_IRefCount,
   public RPG_Common_IDumpState
{
 public:
  // implement RPG_Common_IRefCount
  virtual void increase();
  virtual void decrease();
  virtual unsigned int refcount();
  virtual void waitcount();

  // implement RPG_Common_IDumpState
  virtual void dump_state() const;

 protected:
  // safety measures: meant to be subclassed
  // *TODO*: "destroy on 0" may not work predictably if there are
  // any waiters (or in ANY multithreaded context, for that matter)...
  RPG_Common_ReferenceCounter(const unsigned int& = 1, // initial reference count
                              const bool& = true);     // destroy on 0 --> delete this ?
  RPG_Common_ReferenceCounter(const RPG_Common_ReferenceCounter&);
  // *TODO*: should be 'private'
  virtual ~RPG_Common_ReferenceCounter();

 private:
  // safety measures
  ACE_UNIMPLEMENTED_FUNC(RPG_Common_ReferenceCounter());
  ACE_UNIMPLEMENTED_FUNC(RPG_Common_ReferenceCounter& operator=(const RPG_Common_ReferenceCounter&));

  unsigned int                              myCounter;
  bool                                      myDeleteOnZero;
  // make our API re-entrant
  mutable ACE_Recursive_Thread_Mutex        myLock;
  // implement blocking wait...
  ACE_Condition<ACE_Recursive_Thread_Mutex> myCondition;
};

#endif
