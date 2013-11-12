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
#include "stdafx.h"

#include "rpg_common_defines.h"
#include "rpg_common_timer_manager.h"

#include "rpg_common_macros.h"
#include "rpg_common_itimer.h"

RPG_Common_Timer_Manager::RPG_Common_Timer_Manager()
 : inherited(ACE_Thread_Manager::instance(), // thread manager --> use default
             NULL),                          // timer queue --> allocate (dummy) temp :(
   myTimerHandler(),
   myTimerQueue(RPG_COMMON_MAX_TIMER_SLOTS, // max timer slotes
                true,                       // preallocate timer nodes
                &myTimerHandler,            // upcall functor
                NULL)                       // freelist --> allocate
{
  RPG_TRACE(ACE_TEXT("RPG_Common_Timer_Manager::RPG_Common_Timer_Manager"));

  // set time queue
  if (inherited::timer_queue(&myTimerQueue) == -1)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to ACE_Thread_Timer_Queue_Adapter::timer_queue(): \"%m\", aborting\n")));

    return;
  } // end IF

//   ACE_DEBUG((LM_DEBUG,
//              ACE_TEXT("spawning timer dispatch thread...\n")));

  // ok: spawn the dispatching worker thread
  char thread_name[RPG_COMMON_BUFSIZE];
  ACE_OS::memset(thread_name, 0, sizeof(thread_name));
  ACE_OS::strcpy(thread_name, RPG_COMMON_DEF_TIMER_THREAD_NAME);
  const char* thread_names[1];
  thread_names[0] = thread_name;
  if (inherited::activate((THR_NEW_LWP | THR_JOINABLE),         // flags
                          1,                                    // # threads --> 1
                          0,                                    // force active ?
                          ACE_DEFAULT_THREAD_PRIORITY,          // priority
                          RPG_COMMON_DEF_TIMER_THREAD_GROUP_ID, // group id
                          NULL,                                 // task base
                          NULL,                                 // thread handle(s)
                          NULL,                                 // stack(s)
                          NULL,                                 // stack size(s)
                          NULL,                                 // thread id(s)
                          thread_names) == -1)                  // thread name(s)
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to ACE_Thread_Timer_Queue_Adapter::activate(): \"%m\", continuing\n")));
   else
     ACE_DEBUG((LM_DEBUG,
                ACE_TEXT("spawned timer dispatch thread (ID: %t, group: %d)\n"),
                inherited::thr_id(),
               RPG_COMMON_DEF_TIMER_THREAD_GROUP_ID));
}

RPG_Common_Timer_Manager::~RPG_Common_Timer_Manager()
{
  RPG_TRACE(ACE_TEXT("RPG_Common_Timer_Manager::~RPG_Common_Timer_Manager"));

  // clean up
  inherited::deactivate();

  inherited::mutex().lock();
  fini_timers();
  inherited::mutex().release();

  // make sure the dispatcher thread has joined...
  inherited::wait();

   ACE_DEBUG((LM_DEBUG,
              ACE_TEXT("joined timer dispatch thread...\n")));
}

void
RPG_Common_Timer_Manager::start()
{
  RPG_TRACE(ACE_TEXT("RPG_Common_Timer_Manager::start"));

  ACE_ASSERT(false);
  ACE_NOTREACHED(return;)
}

void
RPG_Common_Timer_Manager::stop()
{
  RPG_TRACE(ACE_TEXT("RPG_Common_Timer_Manager::stop"));

  inherited::deactivate();

  inherited::mutex().lock();
  fini_timers();
  inherited::mutex().release();

  // make sure the dispatcher thread has joined...
  inherited::wait();

   ACE_DEBUG((LM_DEBUG,
              ACE_TEXT("joined timer dispatch thread...\n")));
}

bool
RPG_Common_Timer_Manager::isRunning() const
{
  RPG_TRACE(ACE_TEXT("RPG_Common_Timer_Manager::isRunning"));

  return (inherited::thr_count() > 0);
}

void
RPG_Common_Timer_Manager::fini_timers()
{
  RPG_TRACE(ACE_TEXT("RPG_Common_Timer_Manager::fini_timers"));

  const void* act = NULL;
  RPG_Common_TimerHeapIterator_t iterator(*inherited::timer_queue());
  for (iterator.first();
       !iterator.isdone();
       iterator.next())
  {
    act = NULL;
    if (inherited::cancel(iterator.item()->get_timer_id(), &act) == -1)
      ACE_DEBUG((LM_ERROR,
                 ACE_TEXT("failed to cancel timer (ID: %d): \"%m\", continuing\n"),
                 iterator.item()->get_timer_id()));
  } // end FOR
}

void
RPG_Common_Timer_Manager::resetInterval(const long& timerID_in,
                                        const ACE_Time_Value& interval_in)
{
  RPG_TRACE(ACE_TEXT("RPG_Common_Timer_Manager::resetInterval"));

  {
    ACE_Guard<ACE_Recursive_Thread_Mutex> aGuard(mutex());

    if (inherited::timer_queue()->reset_interval(timerID_in, interval_in))
    {
      ACE_DEBUG((LM_ERROR,
                 ACE_TEXT("failed to reset_interval() for timer (ID: %u): \"%m\", aborting\n"),
                 timerID_in));

      return;
    } // end IF
  } // end lock scope

//   // debug info
//   ACE_DEBUG((LM_DEBUG,
//              ACE_TEXT("reset timer interval (ID: %u)...\n"),
//              timerID_in));
}

void
RPG_Common_Timer_Manager::dump_state() const
{
  RPG_TRACE(ACE_TEXT("RPG_Common_Timer_Manager::dump_state"));

	{
		ACE_Guard<ACE_Recursive_Thread_Mutex> aGuard(const_cast<RPG_Common_Timer_Manager*>(this)->mutex());

		// *TODO*: print some meaningful data
		ACE_ASSERT(false);
	} // end lock scope
}
