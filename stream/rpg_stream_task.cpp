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

#include "rpg_stream_task.h"

#include "rpg_stream_session_message.h"
#include "rpg_stream_message_base.h"

#include <ace/Reactor.h>
#include <ace/Message_Block.h>
#include <ace/Time_Value.h>

RPG_Stream_Task::RPG_Stream_Task()
 : inherited(NULL, // thread manager instance
             NULL) // queue handle
{
  ACE_TRACE(ACE_TEXT("RPG_Stream_Task::RPG_Stream_Task"));

  // use the default reactor...
  reactor(ACE_Reactor::instance());
}

RPG_Stream_Task::~RPG_Stream_Task()
{
  ACE_TRACE(ACE_TEXT("RPG_Stream_Task::~RPG_Stream_Task"));

}

// *** dummy stub methods ***
int
RPG_Stream_Task::open(void* args_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Stream_Task::open"));

  ACE_UNUSED_ARG(args_in);

  // *NOTE*: should NEVER be reached !
  ACE_ASSERT(false);

  ACE_NOTREACHED(return -1;)
}

int
RPG_Stream_Task::close(u_long arg_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Stream_Task::close"));

  ACE_UNUSED_ARG(arg_in);

  // *NOTE*: should NEVER be reached !
  ACE_ASSERT(false);

  ACE_NOTREACHED(return -1;)
}

int
RPG_Stream_Task::module_closed(void)
{
  ACE_TRACE(ACE_TEXT("RPG_Stream_Task::module_closed"));

  // *NOTE*: should NEVER be reached !
  ACE_ASSERT(false);

  ACE_NOTREACHED(return -1;)
}

int
RPG_Stream_Task::put(ACE_Message_Block* mb_in,
                 ACE_Time_Value* tv_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Stream_Task::put"));

  ACE_UNUSED_ARG(mb_in);
  ACE_UNUSED_ARG(tv_in);

  // *NOTE*: should NEVER be reached !
  ACE_ASSERT(false);

  ACE_NOTREACHED(return -1;)
}

int
RPG_Stream_Task::svc(void)
{
  ACE_TRACE(ACE_TEXT("RPG_Stream_Task::svc"));

  // *NOTE*: should NEVER be reached !
  ACE_ASSERT(false);

  ACE_NOTREACHED(return -1;)
}
// *** END dummy stub methods ***

// void
// RPG_Stream_Task::handleDataMessage(RPG_Stream_MessageBase*& message_inout,
//                                bool& passMessageDownstream_out)
// {
//   ACE_TRACE(ACE_TEXT("RPG_Stream_Task::handleDataMessage"));
//
//   // init return value(s)
//   passMessageDownstream_out = true;
//
//   // sanity check(s)
//   ACE_ASSERT(message_inout);
//
//   ACE_UNUSED_ARG(message_inout);
// }

void
RPG_Stream_Task::handleSessionMessage(RPG_Stream_SessionMessage*& message_inout,
                                  bool& passMessageDownstream_out)
{
  ACE_TRACE(ACE_TEXT("RPG_Stream_Task::handleSessionMessage"));

  // init return value(s)
  passMessageDownstream_out = true;

  // sanity check(s)
  ACE_ASSERT(message_inout);

  // *NOTE*: the default behavior is to simply dump our state at the
  // end of a session...
  switch (message_inout->getType())
  {
    case RPG_Stream_SessionMessage::MB_STREAM_SESSION_STEP:
    {
      // don't do anything...
      break;
    }
    case RPG_Stream_SessionMessage::MB_STREAM_SESSION_BEGIN:
    {
      // don't do anything...
      break;
    }
    case RPG_Stream_SessionMessage::MB_STREAM_SESSION_END:
    {
      try
      {
        // OK: dump some status info...
        dump_state();
      }
      catch (...)
      {
        // debug info
        if (module())
        {
          ACE_DEBUG((LM_ERROR,
                     ACE_TEXT("module \"%s\": caught exception in dump_state(), continuing\n"),
                     ACE_TEXT_ALWAYS_CHAR(name())));
        } // end IF
        else
        {
          ACE_DEBUG((LM_ERROR,
                     ACE_TEXT("caught exception in dump_state(), continuing\n")));
        } // end ELSE
      }

      break;
    }
    case RPG_Stream_SessionMessage::MB_STREAM_SESSION_STATISTICS:
    {
      // don't do anything...
      break;
    }
    default:
    {
      // debug info (see above)
      std::string type_string;
      RPG_Stream_SessionMessage::SessionMessageType2String(message_inout->getType(),
                                                       type_string);

      ACE_DEBUG((LM_WARNING,
                 ACE_TEXT("invalid/unknown session message (type: \"%s\")\n"),
                 type_string.c_str()));

      // don't do anything...
      break;
    }
  } // end SWITCH
}

void
RPG_Stream_Task::handleProcessingError(const ACE_Message_Block* const message_in)
{
  ACE_TRACE(ACE_TEXT("RPG_Stream_Task::handleProcessingError"));

  ACE_UNUSED_ARG(message_in);

  if (module())
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("module: \"%s\": failed to process message, continuing\n"),
               ACE_TEXT_ALWAYS_CHAR(name())));
  } // end IF
  else
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to process message, continuing\n")));
  } // end ELSE
}

void
RPG_Stream_Task::dump_state() const
{
  ACE_TRACE(ACE_TEXT("RPG_Stream_Task::dump_state"));

//   // debug info
//   if (module())
//   {
//     ACE_DEBUG((LM_DEBUG,
//                ACE_TEXT(" ***** MODULE: \"%s\" has not implemented the dump_state() API *****\n"),
//                ACE_TEXT_ALWAYS_CHAR(name())));
//   } // end IF
//   else
//   {
//     ACE_DEBUG((LM_WARNING,
//                ACE_TEXT("dump_state() API not implemented\n")));
//   } // end ELSE
}

void
RPG_Stream_Task::handleMessage(ACE_Message_Block* mb_in,
                           bool& stopProcessing_out)
{
  ACE_TRACE(ACE_TEXT("RPG_Stream_Task::handleMessage"));

  // sanity check
  ACE_ASSERT(mb_in);

  // init return value(s)
  stopProcessing_out = false;

  // default behavior is to pass EVERYTHING downstream...
  bool passMessageDownstream = true;
  switch (mb_in->msg_type())
  {
    // DATA handling
    case RPG_Stream_MessageBase::MB_STREAM_DATA:
    case RPG_Stream_MessageBase::MB_STREAM_OBJ:
    {
      RPG_Stream_MessageBase* message = NULL;
      // downcast message
      message = ACE_dynamic_cast(RPG_Stream_MessageBase*,
                                 mb_in);
//       // *OPTIMIZATION*: not as safe, but (arguably) a lot faster !...
//       message = ACE_static_cast(RPG_Stream_MessageBase*,
//                                 mb_in);
      if (!message)
      {
        std::string type;
        RPG_Stream_MessageBase::MessageType2String(mb_in->msg_type(),
                                               type);

        if (module())
        {
          ACE_DEBUG((LM_ERROR,
                     ACE_TEXT("module \"%s\": ACE_dynamic_cast(RPG_Stream_MessageBase*), type: \"%s\" failed, aborting\n"),
                     ACE_TEXT_ALWAYS_CHAR(module()->name()),
                     type.c_str()));
        } // end IF
        else
        {
          ACE_DEBUG((LM_ERROR,
                     ACE_TEXT("ACE_dynamic_cast(RPG_Stream_MessageBase*), type: \"%s\" failed, aborting\n"),
                     type.c_str()));
        } // end ELSE

        // clean up
        mb_in->release();

        return;
      } // end IF

      // OK: process data...
      try
      {
        // invoke specific implementation...
        handleDataMessage(message,
                          passMessageDownstream);
      }
      catch (...)
      {
        if (module())
        {
          ACE_DEBUG((LM_ERROR,
                     ACE_TEXT("module \"%s\": caught an exception in handleDataMessage() (message ID: %u), continuing\n"),
                     ACE_TEXT_ALWAYS_CHAR(name()),
                     message->getID()));
        } // end IF
        else
        {
          ACE_DEBUG((LM_ERROR,
                     ACE_TEXT("caught an exception in handleDataMessage() (message ID: %u), continuing\n"),
                     message->getID()));
        } // end ELSE
      }

      break;
    }
    // *NOTE*: anything that is NOT data is defined as a control message...
    default:
    {
      // OK: process control message...
      try
      {
        // invoke specific implementation...
        handleControlMessage(mb_in,
                             stopProcessing_out,
                             passMessageDownstream);
      }
      catch (...)
      {
        std::string type;
        RPG_Stream_MessageBase::MessageType2String(mb_in->msg_type(),
                                               type);

        if (module())
        {
          ACE_DEBUG((LM_ERROR,
                     ACE_TEXT("module \"%s\": caught an exception in handleControlMessage() (type: \"%s\"), continuing\n"),
                     ACE_TEXT_ALWAYS_CHAR(name()),
                     type.c_str()));
        } // end IF
        else
        {
          ACE_DEBUG((LM_ERROR,
                     ACE_TEXT("caught an exception in handleControlMessage() (type: \"%s\"), continuing\n"),
                     type.c_str()));
        } // end ELSE
      }

      break;
    }
  } // end SWITCH

  // pass message downstream (if there IS a stream)...
  if (passMessageDownstream)
  {
    // *NOTE*: tasks that are not part of a stream have no notion of
    // this concept, so we decide for them...
    if (!module())
    {
//       ACE_DEBUG((LM_DEBUG,
//                  ACE_TEXT("cannot put_next(): not a module, continuing\n"),
//                  ACE_OS::strerror(errno)));

      // clean up
      mb_in->release();
    } // end IF
    else if (put_next(mb_in, NULL) == -1)
    {
      ACE_DEBUG((LM_ERROR,
                 ACE_TEXT("failed to put_next(): \"%m\", continuing\n")));

      // clean up
      mb_in->release();
    } // end IF
  } // end IF
}

void
RPG_Stream_Task::handleControlMessage(ACE_Message_Block* controlMessage_in,
                                  bool& stopProcessing_out,
                                  bool& passMessageDownstream_out)
{
  ACE_TRACE(ACE_TEXT("RPG_Stream_Task::handleControlMessage"));

  // init return value(s)
  stopProcessing_out = false;
  passMessageDownstream_out = true;

  switch (controlMessage_in->msg_type())
  {
    // currently, we only use these...
    case RPG_Stream_MessageBase::MB_STREAM_SESSION:
    {
      RPG_Stream_SessionMessage* sessionMessage = NULL;
      // downcast message
      sessionMessage = ACE_dynamic_cast(RPG_Stream_SessionMessage*,
                                        controlMessage_in);
      if (!sessionMessage)
      {
        // debug info
        if (module())
        {
          ACE_DEBUG((LM_ERROR,
                     ACE_TEXT("module \"%s\": ACE_dynamic_cast (type: %d) failed, aborting\n"),
                     ACE_TEXT_ALWAYS_CHAR(name()),
                     controlMessage_in->msg_type()));
        } // end IF
        else
        {
          ACE_DEBUG((LM_ERROR,
                     ACE_TEXT("ACE_dynamic_cast (type: %d) failed, aborting\n"),
                     controlMessage_in->msg_type()));
        } // end ELSE

        // clean up
        passMessageDownstream_out = false;
        controlMessage_in->release();

        // what else can we do ?
        break;
      } // end IF

      // OK: process session message...
      try
      {
        // invoke specific implementation...
        handleSessionMessage(sessionMessage,
                             passMessageDownstream_out);
      }
      catch (...)
      {
        // debug info
        if (module())
        {
          ACE_DEBUG((LM_ERROR,
                     ACE_TEXT("module \"%s\": caught an exception in handleSessionMessage(), continuing\n"),
                     ACE_TEXT_ALWAYS_CHAR(name())));
        } // end IF
        else
        {
          ACE_DEBUG((LM_ERROR,
                     ACE_TEXT("caught an exception in handleSessionMessage(), continuing\n")));
        } // end ELSE
      }

      // *NOTE*: if this was a RPG_Stream_SessionMessage::MB_STREAM_SESSION_END, we need to
      // stop processing (see above) !
      if (sessionMessage->getType() == RPG_Stream_SessionMessage::MB_STREAM_SESSION_END)
      {
        // OK: tell our worker thread to stop whatever it's doing ASAP...
        stopProcessing_out = true;
      } // end IF

      break;
    }
    default:
    {
      // debug info
      // *NOTE*: if someone defines his own control message type and enqueues it
      // on the stream, it will land here (this is just a sanity check warning...)
      if (module())
      {
        ACE_DEBUG((LM_WARNING,
                   ACE_TEXT("module \"%s\": received an unknown control message (type: %d), continuing\n"),
                   ACE_TEXT_ALWAYS_CHAR(name()),
                   controlMessage_in->msg_type()));
      } // end IF
      else
      {
        ACE_DEBUG((LM_WARNING,
                   ACE_TEXT("received an unknown control message (type: %d), continuing\n"),
                   controlMessage_in->msg_type()));
      } // end ELSE

      break;
    }
  } // end SWITCH
}
