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
#include "rpg_engine_level.h"

#include "rpg_engine_common.h"

#include <rpg_map_common_tools.h>
#include <rpg_map_pathfinding_tools.h>

#include <rpg_common_macros.h>

#include <ace/Log_Msg.h>

// init statics
ACE_Atomic_Op<ACE_Thread_Mutex, RPG_Engine_EntityID_t> RPG_Engine_Level::myCurrentID = 1;

RPG_Engine_Level::RPG_Engine_Level()
 : myQueue(RPG_ENGINE_MAX_QUEUE_SLOTS),
   myCondition(myLock),
   myWindow(NULL)
{
  RPG_TRACE(ACE_TEXT("RPG_Engine_Level::RPG_Engine_Level"));

  // tell the task to use our message queue...
  msg_queue(&myQueue);

  // set group ID for worker thread(s)
  grp_id(RPG_ENGINE_DEF_TASK_GROUP_ID);

  myFloorPlan.size_x = 0;
  myFloorPlan.size_y = 0;
}

RPG_Engine_Level::RPG_Engine_Level(RPG_Engine_IWindow* window_in,
                                   const RPG_Map_FloorPlan_t& floorPlan_in)
 : myQueue(RPG_ENGINE_MAX_QUEUE_SLOTS),
   myCondition(myLock),
   myWindow(window_in),
   myFloorPlan(floorPlan_in)
{
  RPG_TRACE(ACE_TEXT("RPG_Engine_Level::RPG_Engine_Level"));

  // sanity check
  ACE_ASSERT(window_in);

  // tell the task to use our message queue...
  inherited::msg_queue(&myQueue);

  // set group ID for worker thread(s)
  inherited::grp_id(RPG_ENGINE_DEF_TASK_GROUP_ID);
}

RPG_Engine_Level::~RPG_Engine_Level()
{
  RPG_TRACE(ACE_TEXT("RPG_Engine_Level::~RPG_Engine_Level"));

}

int
RPG_Engine_Level::open(void* args_in)
{
  RPG_TRACE(ACE_TEXT("RPG_Engine_Level::open"));

  ACE_UNUSED_ARG(args_in);

  // *IMPORTANT NOTE*: the first time 'round, our queue will have been open()ed
  // from within the default ctor; this sets it into an ACTIVATED state, which
  // is what we want.
  // If we come here a second time (i.e. we have been stopped/started, our queue
  // will have been deactivated in the process, and getq() (see svc()) will fail
  // miserably (ESHUTDOWN) --> (re-)activate() our queue !
  // step1: (re-)activate() our queue
  if (myQueue.activate() == -1)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to ACE_Message_Queue::activate(): \"%m\", aborting\n")));

    return -1;
  } // end IF

  try
  {
    start();
  }
  catch (...)
  {
    ACE_DEBUG((LM_CRITICAL,
               ACE_TEXT("caught exception in start() method, aborting\n")));

    // what else can we do here ?
    return -1;
  }

  return 0;
}

int
RPG_Engine_Level::close(u_long arg_in)
{
  RPG_TRACE(ACE_TEXT("RPG_Engine_Level::close"));

  // *IMPORTANT NOTE*: this method may be invoked
  // [- by an external thread closing down the active object]
  // - by the worker thread which calls this after returning from svc()
  //    --> in this case, this should be a NOP...
  switch (arg_in)
  {
    // called from ACE_Task_Base on clean-up
    case 0:
    {
      ACE_DEBUG((LM_DEBUG,
                 ACE_TEXT("worker thread (ID: %t) leaving...\n")));

      // don't do anything...
      break;
    }
    case 1:
    {
      ACE_DEBUG((LM_CRITICAL,
                 ACE_TEXT("should never get here, returning\n")));

      ACE_ASSERT(false);

      // what else can we do ?
      break;
    }
    default:
    {
      ACE_DEBUG((LM_CRITICAL,
                 ACE_TEXT("invalid argument: %u, returning\n"),
                 arg_in));

      // what else can we do ?
      break;
    }
  } // end SWITCH

  return 0;
}

int
RPG_Engine_Level::svc(void)
{
  RPG_TRACE(ACE_TEXT("RPG_Engine_Level::svc"));

  ACE_Message_Block* ace_mb          = NULL;
  ACE_Time_Value     now;
  bool               stop_processing = false;
  bool               redrawUI        = false;

  while (!stop_processing)
  {
    redrawUI = false;

    // *IMPORTANT NOTE*: NEVER block here...
    now = ACE_OS::gettimeofday();
    if (inherited::getq(ace_mb, &now) != -1)
    {
      switch (ace_mb->msg_type())
      {
        // currently, we only use these...
        case ACE_Message_Block::MB_STOP:
        {
          ACE_DEBUG((LM_DEBUG,
                     ACE_TEXT("received MB_STOP...\n")));

          stop_processing = true;

          break;
        }
        default:
        {
          ACE_DEBUG((LM_ERROR,
                     ACE_TEXT("received an unknown control message (type: %d), continuing\n"),
                     ace_mb->msg_type()));

          break;
        }
      } // end SWITCH

      // clean up
      ace_mb->release();
      ace_mb = NULL;

      if (stop_processing)
        return 0;
    } // end IF

    // process (one round of) entity actions
    handleEntities(redrawUI);

    // redraw UI ?
    if (redrawUI)
    {
      try
      {
        myWindow->redraw();
      }
      catch (...)
      {
        ACE_DEBUG((LM_ERROR,
                   ACE_TEXT("[%@] caught exception in RPG_Engine_IWindow::redraw(), continuing\n"),
                   myWindow));
      }
    } // end IF
  } // end WHILE

  // SHOULD NEVER-EVER GET HERE !
  ACE_ASSERT(false);

  return -1;
}

void
RPG_Engine_Level::start()
{
  RPG_TRACE(ACE_TEXT("RPG_Engine_Level::start"));

  // sanity check
  if (isRunning())
    return;

  // OK: start worker thread
  ACE_thread_t thread_ids[1];
  thread_ids[0] = 0;
  ACE_hthread_t thread_handles[1];
  thread_handles[0] = 0;

  // *IMPORTANT NOTE*: MUST be THR_JOINABLE !!!
  int ret = 0;
  ret = inherited::activate((THR_NEW_LWP |
                             THR_JOINABLE |
                             THR_INHERIT_SCHED),         // flags
                            1,                           // number of threads
                            0,                           // force spawning
                            ACE_DEFAULT_THREAD_PRIORITY, // priority
                            inherited::grp_id(),         // group id --> has been set (see above)
                            NULL,                        // corresp. task --> use 'this'
                            thread_handles,              // thread handle(s)
                            NULL,                        // thread stack(s)
                            NULL,                        // thread stack size(s)
                            thread_ids);                 // thread id(s)
  if (ret == -1)
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to ACE_Task_Base::activate(): \"%m\", continuing\n")));
  else
    ACE_DEBUG((LM_DEBUG,
               ACE_TEXT("started worker thread (group: %d, id: %u)...\n"),
               inherited::grp_id(),
               thread_ids[0]));
}

void
RPG_Engine_Level::stop()
{
  RPG_TRACE(ACE_TEXT("RPG_Engine_Level::stop"));

  // drop control message into the queue...
  ACE_Message_Block* stop_mb = NULL;
  try
  {
    stop_mb = new ACE_Message_Block(0,                                  // size
                                    ACE_Message_Block::MB_STOP,         // type
                                    NULL,                               // continuation
                                    NULL,                               // data
                                    NULL,                               // buffer allocator
                                    NULL,                               // locking strategy
                                    ACE_DEFAULT_MESSAGE_BLOCK_PRIORITY, // priority
                                    ACE_Time_Value::zero,               // execution time
                                    ACE_Time_Value::max_time,           // deadline time
                                    NULL,                               // data block allocator
                                    NULL);                              // message allocator
  }
  catch (...)
  {
    ACE_DEBUG((LM_CRITICAL,
               ACE_TEXT("caught exception in new, returning\n")));

    // *TODO*: what else can we do ?
    return;
  }
  if (!stop_mb)
  {
    ACE_DEBUG((LM_CRITICAL,
               ACE_TEXT("unable to allocate memory, returning\n")));

    // *TODO*: what else can we do ?
    return;
  } // end IF

  // block, if necessary
  if (inherited::putq(stop_mb, NULL) == -1)
  {
    ACE_DEBUG((LM_CRITICAL,
               ACE_TEXT("failed to ACE_Task::putq(): \"%m\", returning\n")));

    // clean up, what else can we do ?
    stop_mb->release();

    return;
  } // end IF

  // ... and wait for the worker thread to join
  if (inherited::wait() == -1)
  {
    ACE_DEBUG((LM_CRITICAL,
               ACE_TEXT("failed to ACE_Task::wait(): \"%m\", returning\n")));

    return;
  } // end IF
}

const bool
RPG_Engine_Level::isRunning()
{
  RPG_TRACE(ACE_TEXT("RPG_Engine_Level::isRunning"));

  return (inherited::thr_count() > 0);
}

void
RPG_Engine_Level::dump_state() const
{
  RPG_TRACE(ACE_TEXT("RPG_Engine_Level::dump_state"));

  ACE_Guard<ACE_Recursive_Thread_Mutex> aGuard(myLock);

  ACE_DEBUG((LM_DEBUG,
             ACE_TEXT("handling %u entities...\n"),
             myEntities.size()));

  for (RPG_Engine_EntitiesConstIterator_t iterator = myEntities.begin();
       iterator != myEntities.end();
       iterator++)
  {
    try
    {
      (*iterator).second.character->dump();
    }
    catch (...)
    {
      ACE_DEBUG((LM_ERROR,
                 ACE_TEXT("[%@] caught exception in RPG_Character_Base::dump(), continuing\n"),
                 (*iterator).second.character));
    }
  } // end FOR
}

void
RPG_Engine_Level::init(RPG_Engine_IWindow* window_in,
                       const RPG_Map_FloorPlan_t& floorPlan_in)
{
  RPG_TRACE(ACE_TEXT("RPG_Engine_Level::init"));

  // sanity check
  ACE_ASSERT(window_in);

  myWindow = window_in;
  myFloorPlan = floorPlan_in;
}

const RPG_Engine_EntityID_t
RPG_Engine_Level::add(RPG_Engine_Entity& entity_in)
{
  RPG_TRACE(ACE_TEXT("RPG_Engine_Level::add"));

  ACE_Guard<ACE_Recursive_Thread_Mutex> aGuard(myLock);

  RPG_Engine_EntityID_t id = myCurrentID++;

  myEntities.insert(std::make_pair(id, entity_in));

  return id;
}

void
RPG_Engine_Level::remove(const RPG_Engine_EntityID_t& id_in)
{
  RPG_TRACE(ACE_TEXT("RPG_Engine_Level::remove"));

  ACE_Guard<ACE_Recursive_Thread_Mutex> aGuard(myLock);

  RPG_Engine_EntitiesIterator_t iterator = myEntities.find(id_in);
  if (iterator == myEntities.end())
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("invalid entity (ID was %u), aborting\n"),
               id_in));

    return;
  } // end IF

  myEntities.erase(iterator);
}

void
RPG_Engine_Level::action(const RPG_Engine_EntityID_t& id_in,
                         const RPG_Engine_Action& action_in)
{
  RPG_TRACE(ACE_TEXT("RPG_Engine_Level::action"));

  ACE_Guard<ACE_Recursive_Thread_Mutex> aGuard(myLock);

  RPG_Engine_EntitiesIterator_t iterator = myEntities.find(id_in);
  if (iterator == myEntities.end())
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("invalid entity (ID was %u), aborting\n"),
               id_in));

    return;
  } // end IF

  switch (action_in.command)
  {
    case COMMAND_STOP:
    {
      (*iterator).second.actions.clear();

      return;
    }
    default:
    {
      (*iterator).second.actions.push_back(action_in);

      break;
    }
  } // end SWITCH
}

const RPG_Map_Dimensions_t
RPG_Engine_Level::getDimensions() const
{
  RPG_TRACE(ACE_TEXT("RPG_Engine_Level::getDimensions"));

  RPG_Map_Dimensions_t result = std::make_pair(myFloorPlan.size_x, myFloorPlan.size_y);

  return result;
}

const RPG_Map_Element
RPG_Engine_Level::getElement(const RPG_Map_Position_t& position_in) const
{
  RPG_TRACE(ACE_TEXT("RPG_Engine_Level::getElement"));

  // sanity check
  if ((position_in.first > (myFloorPlan.size_x - 1)) ||
      (position_in.second > (myFloorPlan.size_y - 1)))
    return MAPELEMENT_INVALID;

  if (myFloorPlan.unmapped.find(position_in) != myFloorPlan.unmapped.end())
    return MAPELEMENT_UNMAPPED;

  if (myFloorPlan.walls.find(position_in) != myFloorPlan.walls.end())
    return MAPELEMENT_WALL;

  RPG_Map_Door_t position_door;
  position_door.position = position_in;
  if (myFloorPlan.doors.find(position_door) != myFloorPlan.doors.end())
    return MAPELEMENT_DOOR;

  return MAPELEMENT_FLOOR;
}

const RPG_Engine_EntityGraphics_t
RPG_Engine_Level::getGraphics() const
{
  RPG_TRACE(ACE_TEXT("RPG_Engine_Level::getGraphics"));

  RPG_Engine_EntityGraphics_t graphics;

  ACE_Guard<ACE_Recursive_Thread_Mutex> aGuard(myLock);

  for (RPG_Engine_EntitiesConstIterator_t iterator = myEntities.begin();
       iterator != myEntities.end();
       iterator++)
    graphics.insert(std::make_pair((*iterator).second.position, (*iterator).second.graphic));

  return graphics;
}

const RPG_Map_Position_t
RPG_Engine_Level::getPosition(const RPG_Engine_EntityID_t& id_in) const
{
  RPG_TRACE(ACE_TEXT("RPG_Engine_Level::getPosition"));

  ACE_Guard<ACE_Recursive_Thread_Mutex> aGuard(myLock);

  RPG_Engine_EntitiesConstIterator_t iterator = myEntities.find(id_in);
  if (iterator == myEntities.end())
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("invalid entity (ID was %u), aborting\n"),
               id_in));

    return std::make_pair(0, 0);
  } // end IF

  return (*iterator).second.position;
}

const RPG_Map_Door_t
RPG_Engine_Level::getDoor(const RPG_Map_Position_t& position_in) const
{
  RPG_TRACE(ACE_TEXT("RPG_Engine_Level::getDoor"));

  RPG_Map_Door_t dummy;
  dummy.position = position_in;
  dummy.outside = DIRECTION_INVALID;
  dummy.is_open = false;
  dummy.is_locked = false;
  dummy.is_broken = false;

  // sanity check
  dummy.position = position_in;
  RPG_Map_DoorsConstIterator_t iterator = myFloorPlan.doors.find(dummy);
  if (iterator == myFloorPlan.doors.end())
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("invalid door position (was [%u,%u]), aborting\n"),
               position_in.first,
               position_in.second));

    // what else can we do ?
    dummy.position = std::make_pair(0, 0);

    return dummy;
  } // end IF

  return *iterator;
}

void
RPG_Engine_Level::handleDoor(const RPG_Map_Position_t& position_in,
                             const bool& open_in)
{
  RPG_TRACE(ACE_TEXT("RPG_Engine_Level::handleDoor"));

  RPG_Map_Door_t position_door;
  position_door.position = position_in;

  RPG_Map_DoorsIterator_t iterator = myFloorPlan.doors.find(position_door);
  if (iterator == myFloorPlan.doors.end())
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("invalid door position (was [%u,%u]), aborting\n"),
               position_in.first,
               position_in.second));

    return;
  } // end IF

  if (open_in)
  {
    // sanity check
    if ((*iterator).is_open)
    {
//       ACE_DEBUG((LM_DEBUG,
//                  ACE_TEXT("door [%u,%u] already open...\n"),
//                  position_in.first,
//                  position_in.second));

      return;
    } // end IF

    // cannot simply open locked doors...
    if ((*iterator).is_locked)
    {
      ACE_DEBUG((LM_DEBUG,
                 ACE_TEXT("door [%u,%u] is locked...\n"),
                 position_in.first,
                 position_in.second));

      return;
    } // end IF
  } // end IF
  else
  {
    // sanity check
    if (!(*iterator).is_open)
    {
//       ACE_DEBUG((LM_DEBUG,
//                  ACE_TEXT("door [%u,%u] already closed...\n"),
//                  position_in.first,
//                  position_in.second));

      return;
    } // end IF
  } // end ELSE

  // *WARNING*: set iterators are CONST for a good reason !
  // --> (but we know what we're doing)...
  (const_cast<RPG_Map_Door_t&>(*iterator)).is_open = open_in;
}

const RPG_Map_Positions_t
RPG_Engine_Level::getWalls() const
{
  RPG_TRACE(ACE_TEXT("RPG_Engine_Level::getWalls"));

  return myFloorPlan.walls;
}

void
RPG_Engine_Level::handleEntities(bool& redrawUI_out)
{
  RPG_TRACE(ACE_TEXT("RPG_Engine_Level::handleEntities"));

  // init return value(s)
  redrawUI_out = false;

  bool action_complete = true;

  ACE_Guard<ACE_Recursive_Thread_Mutex> aGuard(myLock);

  for (RPG_Engine_EntitiesIterator_t iterator = myEntities.begin();
       iterator != myEntities.end();
       iterator++)
  {
    if ((*iterator).second.actions.empty())
      continue;

    action_complete = true;
    switch ((*iterator).second.actions.front().command)
    {
      case COMMAND_ATTACK:
      {
        ACE_DEBUG((LM_DEBUG,
                   ACE_TEXT("[%u] attacking...\n"),
                   (*iterator).first));

        action_complete = false;

        break;
      }
      case COMMAND_STEP:
      {
        // compute target position
        RPG_Map_Position_t targetPosition = (*iterator).second.position;
        switch ((*iterator).second.actions.front().direction)
        {
          case DIRECTION_UP:
            targetPosition.second--; break;
          case DIRECTION_DOWN:
            targetPosition.second++; break;
          case DIRECTION_LEFT:
            targetPosition.first--; break;
          case DIRECTION_RIGHT:
            targetPosition.first++; break;
          default:
          {
            ACE_DEBUG((LM_ERROR,
                       ACE_TEXT("invalid direction (was: \"%s\"), aborting\n"),
                       RPG_Map_Common_Tools::direction2String((*iterator).second.actions.front().direction).c_str()));

            break;
          }
        } // end SWITCH

        // position valid ?
        RPG_Map_Element element = getElement(targetPosition);
        if ((element == MAPELEMENT_FLOOR) ||
            (element == MAPELEMENT_DOOR))
        {
          if (element == MAPELEMENT_DOOR)
          {
            RPG_Map_Door_t door = getDoor(targetPosition);
            if (!door.is_open)
              return;
          } // end IF

          (*iterator).second.position = targetPosition;

          redrawUI_out = true;
        } // end IF

        break;
      }
      case COMMAND_TRAVEL:
      {
        ACE_DEBUG((LM_DEBUG,
                   ACE_TEXT("[%u] travelling...\n"),
                   (*iterator).first));

        // compute path
        RPG_Map_Path_t path;
        if (!RPG_Map_Pathfinding_Tools::findPath(myFloorPlan.size_x,
                                                 myFloorPlan.size_y,
                                                 myFloorPlan.walls,
                                                 (*iterator).second.position,
                                                 RPG_Map_Pathfinding_Tools::getDirection((*iterator).second.position,
                                                                                         (*iterator).second.actions.front().position),
                                                 (*iterator).second.actions.front().position,
                                                 path))
        {
          ACE_DEBUG((LM_DEBUG,
                     ACE_TEXT("could not find a path [%u,%u] --> [%u,%u], continuing\n"),
                     (*iterator).second.position.first,
                     (*iterator).second.position.second,
                     (*iterator).second.actions.front().position.first,
                     (*iterator).second.actions.front().position.second));
        } // end IF

        if (path.empty())
          break;

        // sanity check
        ACE_ASSERT(path.front().first == (*iterator).second.position);
        path.pop_front();

        if (!path.empty())
        {
          (*iterator).second.position = path.front().first;

          redrawUI_out = true;

          // reached destination ?
          if ((*iterator).second.position != (*iterator).second.actions.front().position)
            action_complete = false;
        } // end IF

        break;
      }
      default:
      {
        ACE_DEBUG((LM_ERROR,
                   ACE_TEXT("invalid action (ID: %u, was: \"%s\"), continuing\n"),
                   (*iterator).first,
                   RPG_Engine_CommandHelper::RPG_Engine_CommandToString((*iterator).second.actions.front().command).c_str()));

        break;
      }
    } // end SWITCH

    if (action_complete)
      (*iterator).second.actions.pop_front();
  } // end FOR
}
