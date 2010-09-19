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

#include "rpg_stream_defines.h"
#include "rpg_stream_iallocator.h"

template <typename DataType,
          typename SessionConfigType,
          typename SessionMessageType,
          typename ProtocolMessageType>
RPG_Stream_HeadModuleTaskBase<DataType,
                          SessionConfigType,
                          SessionMessageType,
                          ProtocolMessageType>::RPG_Stream_HeadModuleTaskBase(const bool autoStart_in)
 : myAllocator(NULL),
   mySessionID(0),
   myCondition(myLock),
   myIsFinished(true),
   myQueue(RPG_STREAM_DEF_MAX_QUEUE_SLOTS),
   myAutoStart(autoStart_in)//,
   //myUserData(),
{
  ACE_TRACE(ACE_TEXT("RPG_Stream_HeadModuleTaskBase::RPG_Stream_HeadModuleTaskBase"));

//   // init user data
//   ACE_OS::memset(&myUserData,
//                  0,
//                  sizeof(DataType));

  // tell the task to use our message queue...
  inherited::msg_queue(&myQueue);

  // set group ID for worker thread(s)
  // *TODO*: pass this in from outside...
  inherited::grp_id(RPG_STREAM_DEF_GROUP_ID_TASK);
}

template <typename DataType,
          typename SessionConfigType,
          typename SessionMessageType,
          typename ProtocolMessageType>
RPG_Stream_HeadModuleTaskBase<DataType,
                          SessionConfigType,
                          SessionMessageType,
                          ProtocolMessageType>::~RPG_Stream_HeadModuleTaskBase()
{
  ACE_TRACE(ACE_TEXT("RPG_Stream_HeadModuleTaskBase::~RPG_Stream_HeadModuleTaskBase"));

  // flush/deactivate our queue (check whether it was empty...)
  int flushed_messages = 0;
  flushed_messages = myQueue.flush();

  // *IMPORTANT NOTE*: this should NEVER happen !
  // debug info
  if (flushed_messages)
  {
    ACE_DEBUG((LM_WARNING,
               ACE_TEXT("flushed %d message(s)...\n"),
               flushed_messages));
  } // end IF

//   // *TODO*: check if this sequence actually works...
//   myQueue.deactivate();
//   myQueue.wait();
}

template <typename DataType,
          typename SessionConfigType,
          typename SessionMessageType,
          typename ProtocolMessageType>
int
RPG_Stream_HeadModuleTaskBase<DataType,
                          SessionConfigType,
                          SessionMessageType,
                          ProtocolMessageType>::put(ACE_Message_Block* mb_in,
                                                   ACE_Time_Value* tv_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Stream_HeadModuleTaskBase::put"));

  // drop the message into our queue...
  return inherited::putq(mb_in,
                         tv_in);
}

template <typename DataType,
          typename SessionConfigType,
          typename SessionMessageType,
          typename ProtocolMessageType>
int
RPG_Stream_HeadModuleTaskBase<DataType,
                          SessionConfigType,
                          SessionMessageType,
                          ProtocolMessageType>::open(void* args_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Stream_HeadModuleTaskBase::open"));

  // sanity check
  // *WARNING*: DataType == void* --> args_in COULD be NULL...
//   ACE_ASSERT(args_in);

  // step0: init user data
  myUserData = *ACE_static_cast(DataType*, args_in);

  // step1: (re-)activate() our queue
  // *NOTE*: the first time around, our queue will have been open()ed
  // from within the default ctor; this sets it into an ACTIVATED state
  // - hopefully, this is what we want.
  // If we come here a second time (i.e. we have been stopped/started, our queue
  // will have been deactivated in the process, and getq() (see svc()) will fail
  // miserably (ESHUTDOWN) --> (re-)activate() our queue !
  // step1: (re-)activate() our queue
  if (myQueue.activate() == -1)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to ACE_Message_Queue::activate(): \"%s\", aborting\n"),
               ACE_OS::strerror(errno)));

    return -1;
  } // end IF

  // standard usecase: being implicitly invoked by ACE_Stream::push()...
  // --> don't do anything, unless we're auto-starting
  if (myAutoStart)
  {
    if (inherited::module())
    {
      ACE_DEBUG((LM_DEBUG,
                 ACE_TEXT("auto-starting \"%s\"...\n"),
                 ACE_TEXT_ALWAYS_CHAR(inherited::name())));
    } // end IF
    else
    {
      ACE_DEBUG((LM_DEBUG,
                 ACE_TEXT("auto-starting...\n")));
    } // end ELSE

    try
    {
      start();
    }
    catch (...)
    {
      ACE_DEBUG((LM_ERROR,
                 ACE_TEXT("caught exception in start() method, aborting\n")));

      // what else can we do here ?
      return -1;
    }
  } // end IF

  return 0;
}

template <typename DataType,
          typename SessionConfigType,
          typename SessionMessageType,
          typename ProtocolMessageType>
int
RPG_Stream_HeadModuleTaskBase<DataType,
                          SessionConfigType,
                          SessionMessageType,
                          ProtocolMessageType>::close(u_long arg_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Stream_HeadModuleTaskBase::close"));

  // *NOTE*: this method may be invoked
  // - by an external thread closing down the active object
  //    --> should NEVER happen as a module !
  // - by the worker thread which calls this after returning from svc()
  //    --> in this case, this should be a NOP...
  switch (arg_in)
  {
    // called from ACE_Task_Base on clean-up
    case 0:
    {
//       // debug info
//       if (inherited::module())
//       {
//         ACE_DEBUG((LM_DEBUG,
//                    ACE_TEXT("\"%s\" worker thread (ID: %t) leaving...\n"),
//                    ACE_TEXT_ALWAYS_CHAR(inherited::name())));
//       } // end IF
//       else
//       {
//         ACE_DEBUG((LM_DEBUG,
//                    ACE_TEXT("worker thread (ID: %t) leaving...\n")));
//       } // end ELSE

      // don't do anything...
      break;
    }
    case 1:
    {
      // *WARNING*: SHOULD NEVER GET HERE
      // --> module_closed() hook is implemented below !!!
      ACE_ASSERT(false);

      // what else can we do ?
      return -1;
    }
    default:
    {
      ACE_DEBUG((LM_ERROR,
                 ACE_TEXT("invalid argument: %u, aborting\n"),
                 arg_in));

      // what else can we do ?
      return -1;
    }
  } // end SWITCH

  return 0;
}

template <typename DataType,
          typename SessionConfigType,
          typename SessionMessageType,
          typename ProtocolMessageType>
int
RPG_Stream_HeadModuleTaskBase<DataType,
                          SessionConfigType,
                          SessionMessageType,
                          ProtocolMessageType>::module_closed(void)
{
  ACE_TRACE(ACE_TEXT("RPG_Stream_HeadModuleTaskBase::module_closed"));

  // *NOTE*: this will be a NOP IF the stream was
  // stop()ped BEFORE it is deleted !

  // *NOTE*: this method is invoked by an external thread
  // either from the ACE_Module dtor or during explicit ACE_Module::close()

  // *NOTE*: when we get here, we SHOULD ALREADY BE in a final state...

  // sanity check
  // *WARNING*: this check CANNOT prevent a potential race condition...
  if (isRunning())
  {
    ACE_DEBUG((LM_WARNING,
               ACE_TEXT("isRunning, continuing\n")));

    try
    {
      stop();
    }
    catch (...)
    {
      ACE_DEBUG((LM_ERROR,
                 ACE_TEXT("caught exception in stop(), aborting\n")));

      // what else can we do here ?
      return -1;
    }
  } // end IF

  // just wait for OUR worker thread to die
  // *NOTE*: this works because we assume that by the time we get here,
  // we're either stop()ed (see above) or otherwise finished with processing, i.e. our
  // worker thread should be dying/dead by now...
  inherited::wait();

  return 0;
}

template <typename DataType,
          typename SessionConfigType,
          typename SessionMessageType,
          typename ProtocolMessageType>
int
RPG_Stream_HeadModuleTaskBase<DataType,
                          SessionConfigType,
                          SessionMessageType,
                          ProtocolMessageType>::svc(void)
{
  ACE_TRACE(ACE_TEXT("RPG_Stream_HeadModuleTaskBase::svc"));

  ACE_Message_Block* ace_mb          = NULL;
  bool               stop_processing = false;

  // step1: send initial session message downstream...
  if (!putSessionMessage(mySessionID,
                         RPG_Stream_SessionMessage::MB_STREAM_SESSION_BEGIN,
                         myUserData,
                         ACE_OS::gettimeofday(), // start of session
                         false))                 // N/A
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("putSessionMessage(SESSION_BEGIN) failed, aborting\n")));

    // signal the controller that we're about to die...
    finished();

    return -1;
  } // end IF

  // step2: start processing incoming data...
//   ACE_DEBUG((LM_DEBUG,
//              ACE_TEXT("entering processing loop...\n")));

  while (inherited::getq(ace_mb,
                         NULL) != -1)
  {
    inherited::handleMessage(ace_mb,
                             stop_processing);

    // finished ?
    if (stop_processing)
    {
      // *WARNING*: ace_mb has already been released() at this point !

//       ACE_DEBUG((LM_DEBUG,
//                  ACE_TEXT("leaving processing loop...\n")));

      // step3: send final session message downstream...
      if (!putSessionMessage(mySessionID,
                             RPG_Stream_SessionMessage::MB_STREAM_SESSION_END,
                             myUserData,
                             ACE_Time_Value::zero, // N/A
                             true))                // ALWAYS a user abort...
      {
        ACE_DEBUG((LM_ERROR,
                   ACE_TEXT("putSessionMessage(SESSION_END) failed, aborting\n")));

        // signal the controller that we're about to die...
        finished();

        return -1;
      } // end IF

      // signal the controller that we're about to die...
      finished();

      // leave loop and die !
      return 0;
    } // end IF

    // clean up
    ace_mb = NULL;
  } // end WHILE

  // debug info
  ACE_DEBUG((LM_ERROR,
             ACE_TEXT("worker thread (ID: %t) failed to ACE_Task::getq(): \"%s\", aborting\n"),
             ACE_OS::strerror(errno)));

  // step3: send final session message downstream...
  if (!putSessionMessage(mySessionID,
                         RPG_Stream_SessionMessage::MB_STREAM_SESSION_END,
                         myUserData,
                         ACE_Time_Value::zero, // N/A
                         false))               // N/A
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("putSessionMessage(SESSION_END) failed, aborting\n")));
  } // end IF

  // signal the controller that we're about to die...
  finished();

  return -1;
}

// template <typename DataType,
//           typename SessionConfigType,
//           typename SessionMessageType>
// void
// RPG_Stream_HeadModuleTaskBase<DataType,SessionConfigType,SessionMessageType>::handleDataMessage(RPG_Stream_MessageBase*& message_inout,
//                                                        bool& passMessageDownstream_out)
// {
//   ACE_TRACE(ACE_TEXT("RPG_Stream_HeadModuleTaskBase::handleDataMessage"));
//
//   ACE_UNUSED_ARG(message_inout);
//   ACE_UNUSED_ARG(passMessageDownstream_out);
//
//   // *NOTE*: should NEVER be reached !
//   ACE_ASSERT(false);
//
//   // what else can we do ?
//   ACE_NOTREACHED(return;)
// }

template <typename DataType,
          typename SessionConfigType,
          typename SessionMessageType,
          typename ProtocolMessageType>
void
RPG_Stream_HeadModuleTaskBase<DataType,
                          SessionConfigType,
                          SessionMessageType,
                          ProtocolMessageType>::handleControlMessage(ACE_Message_Block* controlMessage_in,
                                                                    bool& stopProcessing_out,
                                                                    bool& passMessageDownstream_out)
{
  ACE_TRACE(ACE_TEXT("RPG_Stream_HeadModuleTaskBase::handleControlMessage"));

  // init return value(s)
  stopProcessing_out = false;

  switch (controlMessage_in->msg_type())
  {
    // currently, we only handle these...
    // --> send a SESSION_END message downstream to tell the other modules...
    case ACE_Message_Block::MB_STOP:
    {
//      ACE_DEBUG((LM_DEBUG,
//                 ACE_TEXT("received MB_STOP message, shutting down...\n")));

      // clean up --> we DON'T pass these along...
      passMessageDownstream_out = false;
      controlMessage_in->release();

      // OK: tell our worker thread to stop whatever it's doing ASAP
      // *NOTE*: this triggers forwarding a SESSION_END message to notify any
      // modules downstream !
      stopProcessing_out = true;

      break;
    }
    default:
    {
      // otherwise, just behave like a regular module...
      inherited::handleControlMessage(controlMessage_in,
                                      stopProcessing_out,
                                      passMessageDownstream_out);

      break;
    }
  } // end SWITCH
}

template <typename DataType,
          typename SessionConfigType,
          typename SessionMessageType,
          typename ProtocolMessageType>
void
RPG_Stream_HeadModuleTaskBase<DataType,
                          SessionConfigType,
                          SessionMessageType,
                          ProtocolMessageType>::start()
{
  ACE_TRACE(ACE_TEXT("RPG_Stream_HeadModuleTaskBase::start"));

  // (try to) change state
  // --> start a worker thread
  changeState(inherited2::RUNNING);
}

template <typename DataType,
          typename SessionConfigType,
          typename SessionMessageType,
          typename ProtocolMessageType>
void
RPG_Stream_HeadModuleTaskBase<DataType,
                          SessionConfigType,
                          SessionMessageType,
                          ProtocolMessageType>::stop()
{
  ACE_TRACE(ACE_TEXT("RPG_Stream_HeadModuleTaskBase::stop"));

  // (try to) change state
  // --> tell the worker thread to die
  changeState(inherited2::STOPPED);

  // ...and wait for it to happen
  //wait();
}

template <typename DataType,
          typename SessionConfigType,
          typename SessionMessageType,
          typename ProtocolMessageType>
void
RPG_Stream_HeadModuleTaskBase<DataType,
                          SessionConfigType,
                          SessionMessageType,
                          ProtocolMessageType>::pause()
{
  ACE_TRACE(ACE_TEXT("RPG_Stream_HeadModuleTaskBase::pause"));

  // (try to) change state
  changeState(inherited2::PAUSED);
}

template <typename DataType,
          typename SessionConfigType,
          typename SessionMessageType,
          typename ProtocolMessageType>
void
RPG_Stream_HeadModuleTaskBase<DataType,
                          SessionConfigType,
                          SessionMessageType,
                          ProtocolMessageType>::rewind()
{
  ACE_TRACE(ACE_TEXT("RPG_Stream_HeadModuleTaskBase::rewind"));

  // *TODO*: implement this !
  ACE_ASSERT(false);
}

template <typename DataType,
          typename SessionConfigType,
          typename SessionMessageType,
          typename ProtocolMessageType>
void
RPG_Stream_HeadModuleTaskBase<DataType,
                          SessionConfigType,
                          SessionMessageType,
                          ProtocolMessageType>::waitForCompletion()
{
  ACE_TRACE(ACE_TEXT("RPG_Stream_HeadModuleTaskBase::waitForCompletion"));

  {
    ACE_Guard<ACE_Recursive_Thread_Mutex> aGuard(myLock);

    while (!myIsFinished)
    {
      myCondition.wait();
    }
  } // end lock scope

//   ACE_DEBUG((LM_DEBUG,
//              ACE_TEXT("leaving...\n")));
}

template <typename DataType,
          typename SessionConfigType,
          typename SessionMessageType,
          typename ProtocolMessageType>
const bool
RPG_Stream_HeadModuleTaskBase<DataType,
                          SessionConfigType,
                          SessionMessageType,
                          ProtocolMessageType>::isRunning()
{
  ACE_TRACE(ACE_TEXT("RPG_Stream_HeadModuleTaskBase::isRunning"));

  return (getState() == inherited2::RUNNING);
}

template <typename DataType,
          typename SessionConfigType,
          typename SessionMessageType,
          typename ProtocolMessageType>
void
RPG_Stream_HeadModuleTaskBase<DataType,
                          SessionConfigType,
                          SessionMessageType,
                          ProtocolMessageType>::finished()
{
  ACE_TRACE(ACE_TEXT("RPG_Stream_HeadModuleTaskBase::finished"));

  // (try to) set new state
  changeState(inherited2::FINISHED);

//  ACE_DEBUG((LM_DEBUG,
//             ACE_TEXT("leaving finished()...\n")));
}

template <typename DataType,
          typename SessionConfigType,
          typename SessionMessageType,
          typename ProtocolMessageType>
void
RPG_Stream_HeadModuleTaskBase<DataType,
                          SessionConfigType,
                          SessionMessageType,
                          ProtocolMessageType>::onStateChange(const Control_StateType& newState_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Stream_HeadModuleTaskBase::onStateChange"));

  switch (newState_in)
  {
    case inherited2::INIT:
    {
      // OK: (re-)initialized
      ACE_DEBUG((LM_DEBUG,
                 ACE_TEXT("(re-)initialized...\n")));

      break;
    }
    case inherited2::RUNNING:
    {
      // *NOTE*: we want to implement tape-recorder logic:
      // PAUSED --> PAUSED is mapped to PAUSED --> RUNNING
      // --> check for this condition before we do anything else...
      if (getState() == inherited2::PAUSED)
      {
        // resume our worker thread
        if (inherited::resume() == -1)
        {
          ACE_DEBUG((LM_ERROR,
                     ACE_TEXT("failed to resume(): \"%s\", continuing\n"),
                     ACE_OS::strerror(errno)));
        } // end IF

        // finished !
        break;
      } // end IF

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
                                inherited::grp_id(),         // group id --> should have been set by now !
                                NULL,                        // corresp. task --> use 'this'
                                thread_handles,              // thread handle(s)
                                NULL,                        // thread stack(s)
                                NULL,                        // thread stack size(s)
                                thread_ids);                 // thread id(s)
      if (ret == -1)
      {
        ACE_DEBUG((LM_ERROR,
                   ACE_TEXT("failed to activate(): \"%s\", aborting\n"),
                   ACE_OS::strerror(errno)));

        // finished !
        break;
      } // end IF

      {
        // synchronize access to myIsFinished
        // *TODO*: synchronize access to state logic to make the API re-entrant...
        ACE_Guard<ACE_Recursive_Thread_Mutex> aGuard(myLock);

        myIsFinished = false;
      } // end lock scope

//       // debug info
//       if (inherited::module())
//       {
//         ACE_DEBUG((LM_DEBUG,
//                    ACE_TEXT("module \"%s\" started worker thread (group: %d, id: %u)...\n"),
//                    ACE_TEXT_ALWAYS_CHAR(inherited::name()),
//                    inherited::grp_id(),
//                    thread_ids[0]));
//       } // end IF
//       else
//       {
//         ACE_DEBUG((LM_DEBUG,
//                    ACE_TEXT("started worker thread (group: %d, id: %u)...\n"),
//                    inherited::grp_id(),
//                    thread_ids[0]));
//       } // end ELSE

      break;
    }
    case inherited2::STOPPED:
    {
      // OK: drop control message into stream...
      // *TODO*: use ACE_Stream::control() instead ?
      ACE_Message_Block* stop_mb = NULL;
      ACE_NEW_NORETURN(stop_mb,
                       ACE_Message_Block(0,                                  // size
                                         ACE_Message_Block::MB_STOP,         // type
                                         NULL,                               // continuation
                                         NULL,                               // data
                                         NULL,                               // buffer allocator
                                         NULL,                               // locking strategy
                                         ACE_DEFAULT_MESSAGE_BLOCK_PRIORITY, // priority
                                         ACE_Time_Value::zero,               // execution time
                                         ACE_Time_Value::max_time,           // deadline time
                                         NULL,                               // data block allocator
                                         NULL));                             // message allocator
      if (!stop_mb)
      {
        ACE_DEBUG((LM_ERROR,
                   ACE_TEXT("failed to allocate ACE_Message_Block: \"%s\", aborting\n"),
                   ACE_OS::strerror(errno)));

        // what else can we do ?
        break;
      } // end IF

      if (inherited::putq(stop_mb, NULL) == -1)
      {
        ACE_DEBUG((LM_ERROR,
                   ACE_TEXT("failed to putq(): \"%s\", continuing\n"),
                   ACE_OS::strerror(errno)));

        // clean up
        stop_mb->release();

        // what else can we do ?
      } // end IF

      break;
    }
    case inherited2::FINISHED:
    {
      // signal waiting thread(s)
      {
        // grab condition lock...
        ACE_Guard<ACE_Recursive_Thread_Mutex> aGuard(myLock);

        myIsFinished = true;

        myCondition.broadcast();
      } // end lock scope

      // OK: (re-)initialized
//       ACE_DEBUG((LM_DEBUG,
//                  ACE_TEXT("finished successfully !\n")));

      break;
    }
    case inherited2::PAUSED:
    {
      // suspend our worker thread
      if (inherited::suspend() == -1)
      {
        ACE_DEBUG((LM_ERROR,
                   ACE_TEXT("failed to suspend(): \"%s\", continuing\n"),
                   ACE_OS::strerror(errno)));
      } // end IF

      break;
    }
    default:
    {
      // *NOTE*: if we get here, an invalid/unknown state change happened...

      // debug info
      std::string currentStateString;
      std::string newStateString;
      ControlState2String(getState(),
                          currentStateString);
      ControlState2String(newState_in,
                          newStateString);
      ACE_DEBUG((LM_ERROR,
                 ACE_TEXT("invalid state switch: \"%s\" --> \"%s\", continuing\n"),
                 currentStateString.c_str(),
                 newStateString.c_str()));

      break;
    }
  } // end SWITCH
}

template <typename DataType,
          typename SessionConfigType,
          typename SessionMessageType,
          typename ProtocolMessageType>
const bool
RPG_Stream_HeadModuleTaskBase<DataType,
                          SessionConfigType,
                          SessionMessageType,
                          ProtocolMessageType>::putSessionMessage(const unsigned long& sessionID_in,
                                                                 const RPG_Stream_SessionMessageType& messageType_in,
                                                                 SessionConfigType*& config_inout,
                                                                 RPG_Stream_IAllocator* allocator_in) const
{
  ACE_TRACE(ACE_TEXT("RPG_Stream_HeadModuleTaskBase::putSessionMessage"));

  // create session message
  SessionMessageType* message = NULL;
  if (allocator_in)
  {
    try
    {
      message = ACE_static_cast(SessionMessageType*,
                                allocator_in->malloc(0)); // we want a session message !
    }
    catch (...)
    {
      ACE_DEBUG((LM_ERROR,
                ACE_TEXT("caught exception in RPG_Stream_IAllocator::malloc(0), aborting\n")));

      // clean up
      config_inout->decrease();
      config_inout = NULL;

      return false;
    }
  } // end IF
  else
  { // *NOTE*: session message assumes responsibility for session_config !
    ACE_NEW_NORETURN(message,
                     SessionMessageType(sessionID_in,
                                        messageType_in,
                                        config_inout));
  } // end ELSE

  if (!message)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to allocate SessionMessageType: \"%s\", aborting\n"),
               ACE_OS::strerror(errno)));

    // clean up
    config_inout->decrease();
    config_inout = NULL;

    return false;
  } // end IF
  if (allocator_in)
  { // *NOTE*: session message assumes responsibility for session_config !
    message->init(sessionID_in,
                  messageType_in,
                  config_inout);
  } // end IF

  // pass message downstream...
  if (ACE_const_cast(own_type*, this)->put_next(message, NULL) == -1)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to put_next(): \"%s\", aborting\n"),
               ACE_OS::strerror(errno)));

    // clean up
    message->release();

    // what else can we do ?
    return false;
  } // end IF

  //ACE_DEBUG((LM_DEBUG,
  //           ACE_TEXT("enqueued session message...\n")));

  return true;
}

template <typename DataType,
          typename SessionConfigType,
          typename SessionMessageType,
          typename ProtocolMessageType>
const bool
RPG_Stream_HeadModuleTaskBase<DataType,
                          SessionConfigType,
                          SessionMessageType,
                          ProtocolMessageType>::putSessionMessage(const unsigned long& sessionID_in,
                                                                 const RPG_Stream_SessionMessageType& messageType_in,
                                                                 const DataType& userData_in,
                                                                 const ACE_Time_Value& startOfSession_in,
                                                                 const bool& userAbort_in) const
{
  ACE_TRACE(ACE_TEXT("RPG_Stream_HeadModuleTaskBase::putSessionMessage"));

  // create session data
  SessionConfigType* config = NULL;

  // switch
  switch (messageType_in)
  {
    case RPG_Stream_SessionMessage::MB_STREAM_SESSION_BEGIN:
    case RPG_Stream_SessionMessage::MB_STREAM_SESSION_STEP:
    case RPG_Stream_SessionMessage::MB_STREAM_SESSION_END:
    {
      ACE_NEW_NORETURN(config,
                       SessionConfigType(userData_in,
                                         startOfSession_in,
                                         userAbort_in));
      if (!config)
      {
        ACE_DEBUG((LM_ERROR,
                   ACE_TEXT("failed to allocate SessionConfigType: \"%s\", aborting\n"),
                   ACE_OS::strerror(errno)));

        // what else can we do ?
        return false;
      } // end IF

      break;
    }
    case RPG_Stream_SessionMessage::MB_STREAM_SESSION_STATISTICS:
    default:
    {
      ACE_DEBUG((LM_ERROR,
                 ACE_TEXT("invalid/unknown message type: %d, aborting\n"),
                 messageType_in));

      return false;
    }
  } // end SWITCH

  // *NOTE*: this API is a "fire-and-forget", so we don't need to
  // worry about config any longer !
  return putSessionMessage(sessionID_in,
                           messageType_in,
                           config,
                           myAllocator);
}