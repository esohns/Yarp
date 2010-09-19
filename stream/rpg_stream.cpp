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

#include "rpg_stream.h"

#include "rpg_stream_headmoduletask.h"
#include "rpg_stream_session_config.h"
#include "rpg_stream_session_message.h"
#include "rpg_stream_iallocator.h"

RPG_Stream::RPG_Stream()
// *TODO*: use default ctor and rely on init/fini() ?
 : inherited(NULL,    // argument to module open()
             NULL,    // no head module --> ACE_Stream_Head !
             NULL),   // no tail module --> ACE_Stream_Tail !
   myIsInitialized(false),
   myAllocator(NULL)
{
  ACE_TRACE(ACE_TEXT("RPG_Stream::RPG_Stream"));

}

RPG_Stream::~RPG_Stream()
{
  ACE_TRACE(ACE_TEXT("RPG_Stream::~RPG_Stream"));

}

const bool
RPG_Stream::reset()
{
  ACE_TRACE(ACE_TEXT("RPG_Stream::reset"));

  // sanity check: is running ?
  if (isRunning())
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("cannot reset (currently running), aborting\n")));

    return false;
  } // end IF

  // pop/close all modules
  // *NOTE*: will implicitly (blocking !) wait for any active worker threads
  if (!fini())
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to fini(), aborting\n")));

    return false;
  } // end IF

  // - reset reader/writers tasks for ALL modules
  // - reinit head/tail modules
  return init();
}

const bool
RPG_Stream::init()
{
  ACE_TRACE(ACE_TEXT("RPG_Stream::init"));

  // *NOTE*: fini() invokes close() which will reset the writer/reader tasks
  // of the enqueued modules --> reset this !
  for (MODULE_CONTAINERITERATOR_TYPE iter = myAvailableModules.begin();
       iter != myAvailableModules.end();
       iter++)
  {
    try
    {
      (*iter)->resetReaderWriter();
    }
    catch (...)
    {
      ACE_DEBUG((LM_ERROR,
                 ACE_TEXT("caught exception in RPG_Stream_Module::resetReaderWriter(), continuing\n")));
    }
  } // end FOR

  // delegate this to base class open()
  int ret = -1;
  try
  {
    ret = inherited::open(NULL,  // argument to module open()
                          NULL,  // no head module --> ACE_Stream_Head !
                          NULL); // no tail module --> ACE_Stream_Tail !
  }
  catch (...)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("caught exception in ACE_Stream::open(), aborting\n")));
  }

  // OK ?
  if (ret == -1)
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to ACE_Stream::open(): \"%m\", aborting\n")));

  return (ret == 0);
}

const bool
RPG_Stream::fini()
{
  ACE_TRACE(ACE_TEXT("RPG_Stream::fini"));

  // OK: delegate this to base class close(ACE_Module_Base::M_DELETE_NONE)
  int ret = -1;
  try
  {
    // *NOTE*: this will implicitly:
    // - unwind the stream, which pop()s all (pushed) modules
    // --> pop()ing a module will close() it
    // --> close()ing a module will module_closed() and flush() the associated tasks
    // --> flush()ing a task will close() its queue
    // --> close()ing a queue will deactivate() and flush() it
    ret = inherited::close(ACE_Module_Base::M_DELETE_NONE);
  }
  catch (...)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("caught exception in ACE_Stream::close(M_DELETE_NONE), aborting\n")));
  }

  // OK ?
  if (ret == -1)
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to ACE_Stream::close(M_DELETE_NONE): \"%m\", aborting\n")));

  return (ret == 0);
}

void
RPG_Stream::start()
{
  ACE_TRACE(ACE_TEXT("RPG_Stream::start"));

  // sanity check: is initialized ?
  if (!isInitialized())
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("not initialized, returning\n")));

    return;
  } // end IF

  // delegate to the head module
  RPG_Stream_Module::MODULE_TYPE* module = NULL;
  if (top(module))
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("no head module found, returning\n")));

    return;
  } // end IF

  // sanity check: head == tail ? --> no modules have been push()ed (yet) !
  if (module == tail())
  {
    ACE_DEBUG((LM_DEBUG,
               ACE_TEXT("no modules have been enqueued yet --> nothing to do !, returning\n")));

    return;
  } // end IF

  RPG_Stream_IStreamControl* control_impl = NULL;
  control_impl = ACE_dynamic_cast(RPG_Stream_IStreamControl*,
                                  module->writer());
  if (!control_impl)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("%s: ACE_dynamic_cast(RPG_Stream_IStreamControl) failed, returning\n"),
               ACE_TEXT_ALWAYS_CHAR(module->name())));

    return;
  } // end IF

  try
  {
    control_impl->start();
  }
  catch (...)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("caught exception in RPG_Stream_IStreamControl::start (module: \"%s\"), returning\n"),
               ACE_TEXT_ALWAYS_CHAR(module->name())));

    return;
  }
}

void
RPG_Stream::stop()
{
  ACE_TRACE(ACE_TEXT("RPG_Stream::stop"));

  // sanity check: is running ?
  if (!isRunning())
  {
//     ACE_DEBUG((LM_DEBUG,
//                ACE_TEXT("not running --> nothing to do, returning\n")));

    return;
  } // end IF

  // delegate to the head module
  RPG_Stream_Module::MODULE_TYPE* module = NULL;
  if (top(module))
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("no head module found, returning\n")));

    return;
  } // end IF

  // sanity check: head == tail ? --> no modules have been push()ed (yet) !
  if (module == tail())
  {
    ACE_DEBUG((LM_DEBUG,
               ACE_TEXT("no modules have been enqueued yet --> nothing to do !, returning\n")));

    return;
  } // end IF

  RPG_Stream_IStreamControl* control_impl = NULL;
  control_impl = ACE_dynamic_cast(RPG_Stream_IStreamControl*,
                                  module->writer());
  if (!control_impl)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("%s: ACE_dynamic_cast(RPG_Stream_IStreamControl) failed, returning\n"),
               ACE_TEXT_ALWAYS_CHAR(module->name())));

    return;
  } // end IF

  try
  {
    control_impl->stop();
  }
  catch (...)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("caught exception in RPG_Stream_IStreamControl::stop (module: \"%s\"), returning\n"),
               ACE_TEXT_ALWAYS_CHAR(module->name())));

    return;
  }
}

void
RPG_Stream::pause()
{
  ACE_TRACE(ACE_TEXT("RPG_Stream::pause"));

  // sanity check: is running ?
  if (!isRunning())
  {
//     ACE_DEBUG((LM_DEBUG,
//                ACE_TEXT("not running --> nothing to do, returning\n")));

    return;
  } // end IF

  // delegate to the head module
  RPG_Stream_Module::MODULE_TYPE* module = NULL;
  if (top(module))
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("no head module found, returning\n")));

    return;
  } // end IF

  // sanity check: head == tail ? --> no modules have been push()ed (yet) !
  if (module == tail())
  {
    // debug info
    ACE_DEBUG((LM_DEBUG,
               ACE_TEXT("no modules have been enqueued yet --> nothing to do !, returning\n")));

    return;
  } // end IF

  RPG_Stream_IStreamControl* control_impl = NULL;
  control_impl = ACE_dynamic_cast(RPG_Stream_IStreamControl*,
                                  module->writer());
  if (!control_impl)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("%s: ACE_dynamic_cast(RPG_Stream_IStreamControl) failed, returning\n"),
               ACE_TEXT_ALWAYS_CHAR(module->name())));

    return;
  } // end IF

  try
  {
    control_impl->pause();
  }
  catch (...)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("caught exception in RPG_Stream_IStreamControl::pause (module: \"%s\"), returning\n"),
               ACE_TEXT_ALWAYS_CHAR(module->name())));

    return;
  }
}

void
RPG_Stream::rewind()
{
  ACE_TRACE(ACE_TEXT("RPG_Stream::rewind"));

  // sanity check: is running ?
  if (isRunning())
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("currently running, returning\n")));

    return;
  } // end IF

  // delegate to the head module
  RPG_Stream_Module::MODULE_TYPE* module = NULL;
  if (top(module))
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("no head module found, returning\n")));

    return;
  } // end IF

  // sanity check: head == tail ? --> no modules have been push()ed (yet) !
  if (module == tail())
  {
    ACE_DEBUG((LM_DEBUG,
               ACE_TEXT("no modules have been enqueued yet --> nothing to do !, returning\n")));

    return;
  } // end IF

  RPG_Stream_IStreamControl* control_impl = NULL;
  control_impl = ACE_dynamic_cast(RPG_Stream_IStreamControl*,
                                  module->writer());
  if (!control_impl)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("%s: ACE_dynamic_cast(RPG_Stream_IStreamControl) failed, returning\n"),
               ACE_TEXT_ALWAYS_CHAR(module->name())));

    return;
  } // end IF

  try
  {
    control_impl->rewind();
  }
  catch (...)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("caught exception in RPG_Stream_IStreamControl::rewind (module: \"%s\"), returning\n"),
               ACE_TEXT_ALWAYS_CHAR(module->name())));

    return;
  }
}

void
RPG_Stream::waitForCompletion()
{
  ACE_TRACE(ACE_TEXT("RPG_Stream::waitForCompletion"));

  // sanity check: is initialized ?
  if (!isInitialized())
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("not initialized, returning\n")));

    return;
  } // end IF

  // OK: the logic here is this...
  // step1: wait for processing to finish
  // step2: wait for the pipelined messages to flush...

  // iterate over modules...
  const RPG_Stream_Module::MODULE_TYPE* module = NULL;
  ACE_Stream_Iterator<ACE_MT_SYNCH> iter(*this);
  // skip over ACE_Stream_Head
  if (!iter.advance())
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("no head module found, returning\n")));

    return;
  } // end IF

  // get head module
  if (!iter.next(module))
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("no head module found, returning\n")));

    return;
  } // end IF

  // sanity check: head == tail ? --> no modules have been push()ed (yet) !
  if (module == tail())
  {
    ACE_DEBUG((LM_DEBUG,
               ACE_TEXT("no modules have been enqueued yet --> nothing to do !, returning\n")));

    return;
  } // end IF

  // need to downcast
  RPG_Stream_HeadModuleTask* head_task = NULL;
  head_task = ACE_dynamic_cast(RPG_Stream_HeadModuleTask*,
                               ACE_const_cast(RPG_Stream_Module::MODULE_TYPE*, module)->writer());
  if (!head_task)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("%s: ACE_dynamic_cast(RPG_Stream_HeadModuleTask) failed, returning\n"),
               ACE_TEXT_ALWAYS_CHAR(module->name())));

    return;
  } // end IF

//   ACE_DEBUG((LM_DEBUG,
//              ACE_TEXT("waiting for module (\"%s\") to finish processing...\n"),
//              ACE_TEXT_ALWAYS_CHAR(module->name())));

  // OK: now that we've got a handler... wait on it
  try
  {
    // step1: wait for state switch (xxx --> FINISHED)
    head_task->waitForCompletion();

    // step2: wait for worker thread
    head_task->wait();
  }
  catch (...)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("caught exception in RPG_Stream_IStreamControl::waitForCompletion || wait (module: \"%s\"), returning\n"),
               ACE_TEXT_ALWAYS_CHAR(module->name())));

    return;
  }

//   ACE_DEBUG((LM_DEBUG,
//              ACE_TEXT("waiting for module (\"%s\") to finish processing...DONE\n"),
//              ACE_TEXT_ALWAYS_CHAR(module->name())));
//   ACE_DEBUG((LM_DEBUG,
//              ACE_TEXT("waiting for stream to flush...\n")));

  for (iter.advance();
       iter.next(module);
       iter.advance())
  {
    // skip stream tail (last module)
    if (module == tail())
    {
      // skip last module (stream tail)
      continue;
    } // end IF

//     ACE_DEBUG((LM_DEBUG,
//                ACE_TEXT("waiting for module (\"%s\") to finish processing...\n"),
//                ACE_TEXT_ALWAYS_CHAR(module->name())));

    // OK: we've got a handle... wait
    ACE_const_cast(RPG_Stream_Module::MODULE_TYPE*, module)->writer()->wait();

//     ACE_DEBUG((LM_DEBUG,
//                ACE_TEXT("waiting for module (\"%s\") to finish processing...DONE\n"),
//                ACE_TEXT_ALWAYS_CHAR(module->name())));

    module = NULL;
  } // end FOR

  // OK: IF no new messages have been enqueued IN THE MEANTIME, the queue should be empty...
//   ACE_DEBUG((LM_DEBUG,
//              ACE_TEXT("waiting for stream to flush...DONE\n")));
}

const bool
RPG_Stream::isRunning()
{
  ACE_TRACE(ACE_TEXT("RPG_Stream::isRunning"));

  // delegate to the head module
  RPG_Stream_Module::MODULE_TYPE* module = NULL;
  if (top(module))
  {
//     ACE_DEBUG((LM_ERROR,
//                ACE_TEXT("no head module found, aborting\n")));

    return false;
  } // end IF

  // sanity check: head == tail ? --> no modules have been push()ed (yet) !
  if (module == tail())
  {
//     ACE_DEBUG((LM_DEBUG,
//                ACE_TEXT("no modules have been enqueued yet --> nothing to do !, returning\n")));

    return false;
  } // end IF

  RPG_Stream_IStreamControl* control_impl = NULL;
  control_impl = ACE_dynamic_cast(RPG_Stream_IStreamControl*, module->writer());
  if (!control_impl)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("%s: ACE_dynamic_cast(RPG_Stream_IStreamControl) failed, returning\n"),
               ACE_TEXT_ALWAYS_CHAR(module->name())));

    return false;
  } // end IF

  try
  {
    return control_impl->isRunning();
  }
  catch (...)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("caught exception in RPG_Stream_IStreamControl::isRunning (module: \"%s\"), aborting\n"),
               ACE_TEXT_ALWAYS_CHAR(module->name())));
  }

  return false;
}

void
RPG_Stream::dump_state() const
{
  ACE_TRACE(ACE_TEXT("RPG_Stream::dump_state"));

  std::string stream_layout;

  const RPG_Stream_Module::MODULE_TYPE* module = NULL;
  for (ACE_Stream_Iterator<ACE_MT_SYNCH> iter(*this);
       iter.next(module);
       iter.advance())
  {
    // silently ignore ACE head/tail modules...
    if ((module == ACE_const_cast(RPG_Stream*, this)->tail()) ||
        (module == ACE_const_cast(RPG_Stream*, this)->head()))
    {
      continue;
    } // end IF

    stream_layout.append(ACE_TEXT_ALWAYS_CHAR(module->name()));

    // avoid trailing "-->"...
    if (ACE_const_cast(RPG_Stream_Module::MODULE_TYPE*, module)->next() !=
        ACE_const_cast(RPG_Stream*, this)->tail())
    {
      stream_layout += ACE_TEXT_ALWAYS_CHAR(" --> ");
    } // end IF

    module = NULL;
  } // end FOR

  ACE_DEBUG((LM_DEBUG,
             ACE_TEXT("stream layout: \"%s\"\n"),
             stream_layout.c_str()));
}

const bool
RPG_Stream::isInitialized() const
{
  ACE_TRACE(ACE_TEXT("RPG_Stream::isInitialized"));

  return myIsInitialized;
}

void
RPG_Stream::shutdown()
{
  ACE_TRACE(ACE_TEXT("RPG_Stream::shutdown"));

//   ACE_DEBUG((LM_DEBUG,
//              ACE_TEXT("shutting down stream...\n")));

  // if we haven't properly initialized, we need to deactivate any hitherto enqueued
  // ACTIVE modules, or we will wait forever during closure...
  // --> possible scenarios:
  // - (re-)init() failed halfway through (i.e. MAYBE some modules push()ed correctly)
  if (!myIsInitialized)
  {
    // sanity check: have we actually successfully pushed() any modules ?
    if (head()->next() != tail())
    {
      ACE_DEBUG((LM_DEBUG,
                 ACE_TEXT("not initialized - deactivating module(s)...\n")));

      deactivateModules();

//       ACE_DEBUG((LM_DEBUG,
//                  ACE_TEXT("not initialized - deactivating module(s)...WAITING\n")));

      // ...and wait for it to complete ?
      // *NOTE*: children can synchronize by calling waitForCompletion...

      ACE_DEBUG((LM_DEBUG,
                 ACE_TEXT("not initialized - deactivating module(s)...DONE\n")));
    } // end IF
  } // end IF

  // step1: retrieve a list of modules which are NOT on the stream
  // --> need to close() these manually (before they do so in their dtors...)
//   ACE_DEBUG((LM_DEBUG,
//              ACE_TEXT("deactivating offline module(s)...\n")));

  for (MODULE_CONTAINERITERATOR_TYPE iter = myAvailableModules.begin();
       iter != myAvailableModules.end();
       iter++)
  {
    if ((*iter)->next() == NULL)
    {
//       ACE_DEBUG((LM_DEBUG,
//                  ACE_TEXT("manually closing module: \"%s\"\n"),
//                  ACE_TEXT_ALWAYS_CHAR((*iter)->name())));

      try
      {
        (*iter)->close(ACE_Module_Base::M_DELETE_NONE);
      }
      catch (...)
      {
        ACE_DEBUG((LM_ERROR,
                   ACE_TEXT("caught exception in ACE_Module::close(M_DELETE_NONE), continuing\n")));
      }
    } // end IF
  } // end FOR

//   ACE_DEBUG((LM_DEBUG,
//              ACE_TEXT("deactivating offline module(s)...DONE\n")));

  // step2: shutdown stream
  // check the ACE documentation on ACE_Stream to see why this is needed !!!
  // Note: ONLY do this if stream_head != 0 !!! (warning: obsolete ?)
  // *NOTE*: this will NOT destroy all modules in the current stream
  // as this leads to exceptions in debug builds under windows (can't delete
  // objects in a different DLL where it was created...)
  // --> we need to do this ourselves !
  // all this does is call close() on each one (--> wait for the worker thread to return)
//   ACE_DEBUG((LM_DEBUG,
//              ACE_TEXT("deactivating module(s)...\n")));

  fini();

//   ACE_DEBUG((LM_DEBUG,
//              ACE_TEXT("deactivating module(s)...DONE\n")));

  // *NOTE*: every ACTIVE module will join with its worker thread in close()
  // --> ALL stream-related threads should have returned by now !

//   ACE_DEBUG((LM_DEBUG,
//              ACE_TEXT("shutting down stream...FINISHED\n")));
}

void RPG_Stream::deactivateModules()
{
  ACE_TRACE(ACE_TEXT("RPG_Stream::deactivateModules"));

  // create session data
  RPG_Stream_SessionConfig* session_config = NULL;
  ACE_NEW_NORETURN(session_config,
                   RPG_Stream_SessionConfig(NULL)); // NO user data...
  if (!session_config)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to allocate RPG_Stream_SessionConfig: \"%m\", aborting\n")));

    return;
  } // end IF

  // create MB_STREAM_SESSION_END session message
  RPG_Stream_SessionMessage* message = NULL;
  if (myAllocator)
  {
    try
    {
      message = ACE_static_cast(RPG_Stream_SessionMessage*,
                                myAllocator->malloc(0)); // we want a session message !
    }
    catch (...)
    {
      ACE_DEBUG((LM_ERROR,
                ACE_TEXT("caught exception in RPG_Stream_IAllocator::malloc(0), aborting\n")));

      // clean up
      session_config->decrease();
      session_config = NULL;

      return;
    }
  } // end IF
  else
  { // *NOTE*: session message assumes responsibility for session_config !
    ACE_NEW_NORETURN(message,
                     RPG_Stream_SessionMessage(0, // N/A
                                               RPG_Stream_SessionMessage::MB_STREAM_SESSION_END,
                                               session_config));
  } // end ELSE

  if (!message)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to allocate RPG_Stream_SessionMessage: \"%m\", aborting\n")));

    // clean up
    session_config->decrease();
    session_config = NULL;

    return;
  } // end IF
  if (myAllocator)
  { // *NOTE*: session message assumes responsibility for session_config !
    message->init(0, // N/A
                  RPG_Stream_SessionMessage::MB_STREAM_SESSION_END,
                  session_config);
  } // end IF

  // pass message downstream...
  if (put(message, NULL) == -1)
  {
    ACE_DEBUG((LM_ERROR,
               ACE_TEXT("failed to ACE_RPG_Stream::put(): \"%m\", aborting\n")));

    // clean up
    message->release();

    return;
  } // end IF
}